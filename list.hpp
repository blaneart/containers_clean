/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:35:11 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/09 13:47:13 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP
# include <iostream>

namespace ft
{

	template <bool, class IsTrue = void>
	struct enable_if;

	template <class IsTrue>
	struct enable_if<true, IsTrue> {
		typedef IsTrue type;
	};

	template <bool flag, class IsTrue, class IsFalse>
	struct choose;

	template <class IsTrue, class IsFalse>
	struct choose<true, IsTrue, IsFalse> {
	   typedef IsTrue type;
	};

	template <class IsTrue, class IsFalse>
	struct choose<false, IsTrue, IsFalse> {
	   typedef IsFalse type;
	};
	// list node
	template <typename T>
	struct listNode
	{
		listNode(const T& e = T()) :
			data(e), next(NULL), prev(NULL)
		{}
		T data;
		listNode<T> *next;
		listNode<T> *prev;
	};

	template <typename T, bool is_const = false>
	class listIterator
	{

		public:
			typedef typename choose<is_const, const T &, T &>::type 	reference;
			typedef typename choose<is_const, const T *, T *>::type 	pointer;
			typedef typename choose<is_const, const T, T>::type 		value_type;
			typedef listIterator<value_type, is_const>					iterator;
			typedef typename choose<is_const, const listNode<T>*, listNode<T>*>::type nodeptr;
		private:
			nodeptr _pos;
			nodeptr _prev;
			nodeptr _head;
			nodeptr _tail;

		public:
			listIterator(nodeptr p = 0, nodeptr  prev = 0, nodeptr head = 0, nodeptr tail = 0):
				_pos(p), _prev(prev), _head(head), _tail(tail)
			{}

			operator listIterator<T, true>() const
 			{
				return listIterator<T,true>(_pos, _prev, _head);
			}
			reference operator*() const
			{
				return _pos->data;
			}

			pointer operator->() const
			{
				return &_pos->data;
			}

			listIterator(const iterator& other):
				_pos(other._pos), _prev(other._prev), _head(other._head), _tail(other._tail)
			{}

			listIterator& operator=(const iterator & other)
			{
				_pos = other._pos;
				_prev = other._prev;
				_head = other._head;
				_tail = other._tail;
				return *this;
			}

			~listIterator()
			{}

			listIterator& operator++()
			{
				if (!_pos)
				{
					if (_prev)
					{
						_prev = _prev->next;
						_pos = _prev->next;
					}
				}
				else
				{
					_prev = _pos;
					if (_pos)
						_pos = _pos->next;
					else
						_pos = _head;
				}
				return *this;
			}

			listIterator& operator--() {
				if (!_pos)
				{
					_pos = _prev;
					_prev = _pos->prev;
				}
				else
				{
					_pos = _pos->prev;
					if (_pos)
						_prev = _pos->prev;
					else
						_prev = _tail;
				}
				return *this;
			}

			listIterator operator++(int)
			{
				listIterator cpy(*this);
				// ++_pos;
				// ++_prev;

				if (!_pos)
				{
					if (_prev)
					{
						_prev = _prev->next;
						_pos = _prev->next;
					}
				}
				else
				{
					_prev = _pos;
					if (_pos)
						_pos = _pos->next;
				}
				return cpy;
			}

			listIterator operator--(int)
			{
				listIterator cpy = *this;
				// --(*this);
				// --_pos;
				// --_prev;
				// std::cout << !_po`s << std::endl;
				if (!_pos)
				{
					_pos = _prev;
					if (_pos)
						_prev = _pos->prev;
				}
				else
				{
					_pos = _pos->prev;
					if (_pos)
						_prev = _pos->prev;
					else
						_prev = _tail;
				}
				return cpy;
			}
			template <class U, bool E>
			bool	operator==(const listIterator<U, E> &rhs) const
			{
				return _pos == rhs._pos;
			}
			template <class U, bool E>
			bool	operator!=(const listIterator<U, E> &rhs) const
			{
				return _pos != rhs._pos;
			}
			template <class, bool>
			friend class listIterator;
			template <class, class>
			friend class list;
			// template <typename E>
			// friend class list;
			// template <typename U,bool E>
			// friend bool operator==(const listIterator<U, E>& lhs, const listIterator<U, E>& rhs);
			// template <typename U,bool E>
			// friend bool operator!=(const listIterator<U, E>& lhs, const listIterator<U, E>& rhs);
	};
	// template <typename U,bool E>
	// bool operator==(const listIterator<U, E>& lhs, const listIterator<U, E>& rhs)	{
	// return lhs._pos == rhs._pos;
// }
	// template <typename U,bool E>
// 	bool operator!=(const listIterator<U, E>& lhs, const listIterator<U, E>& rhs)	{
// 	return lhs._pos != rhs._pos;
// }

	template <class Iterator>
	class reverseListIterator
	{
	private:
		Iterator _base;
		reverseListIterator();
	public:
		typedef Iterator iterator_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		reverseListIterator(Iterator base):
			_base(base)
			{}

		template <class U>
		reverseListIterator(const reverseListIterator<U> &u):
			_base(u.base())
		{
		}
		reverseListIterator(const reverseListIterator<Iterator> & other):
			_base(other.base())
		{
		}
		reverseListIterator<Iterator>& operator=(const reverseListIterator<Iterator>& other)
		{
			_base = other.base();
			return *this;
		}

		~reverseListIterator()
		{}

		Iterator base() const
		{
			Iterator cpy(_base);
			return cpy;
		}

		reverseListIterator<Iterator>& operator++()
		{
			--_base;
			return *this;
		}
		reverseListIterator<Iterator>& operator--() {
			++_base;
			return *this;
		}
		reverseListIterator<Iterator> operator++(int)
		{
			reverseListIterator cpy(*this);
			--_base;
			return cpy;
		}
		reverseListIterator<Iterator> operator--(int)
		{
			reverseListIterator cpy(*this);
			++_base;
			return cpy;
		}
		reference	operator*() const
		{
			return (--Iterator(_base)).operator*();
		}
		pointer operator->() const
		{
			return (--Iterator(_base)).operator->();;
		}
		template <class U>
		bool	operator==(const reverseListIterator<U> &rhs) const
		{
			return _base == rhs.base();
		}
		template <class U>
		bool	operator!=(const reverseListIterator<U> &rhs) const
		{
			return _base != rhs.base();
		}
	};

	template <class T, class Alloc = std::allocator<T> >
	class list
	{
	public:

		typedef T												value_type;
		typedef Alloc				 							allocator_type;
		typedef typename allocator_type::value_type&										reference;
		typedef const typename allocator_type::value_type&								const_reference;
		typedef typename allocator_type::value_type*										pointer;
		typedef const typename allocator_type::value_type*								const_pointer;
		typedef listIterator<T>									iterator;
		typedef listIterator<T, true>							const_iterator;
		typedef reverseListIterator<listIterator<T> >			reverse_iterator;
		typedef reverseListIterator<listIterator<T, true> >	const_reverse_iterator;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;


		explicit list():
				_head(NULL), _tail(NULL), _size(0)
		{}

		explicit list(size_type n, const value_type& val = value_type()):
			_head(NULL), _tail(NULL),_size(0)
		{

			insert(begin(), n, val);

		}

		template <class InputIterator>
		explicit list(InputIterator first, InputIterator last,
			typename std::enable_if<!std::is_integral<InputIterator>::value>::type * = 0) :
			_head(NULL), _tail(NULL), _size(0)
		{
			insert(begin(), first, last);
		}

		list(const list<T>& other):
			_head(NULL), _tail(NULL), _size(0)
		{
			insert(begin(), other.begin(), other.end());
		}

		list<T> &operator=(const list<T> & other)
		{
			clear();
			insert(begin(), other.begin(), other.end());
			return *this;
		}

		~list()
		{
			clear();
			// listNode<T> *buf;
			// listNode<T> *cur = _head;
			//
			// while (cur)
			// {
			// 	buf = cur->next;
			// 	delete cur;
			// 	cur = buf;
			// }
		}

		// Iterators

		iterator begin() {

			return iterator(_head, 0, _head, _tail);
		}

		iterator end() {
			return iterator(0, _tail, _head, _tail);
		}

		const_iterator begin() const{
			return const_iterator(_head, 0, _head, _tail);
		}

		const_iterator end() const{
			return  const_iterator(0, _tail, _head, _tail);
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(end()));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(begin()));
		}
		bool empty() const
		{
			return static_cast<bool>(!_size);
		}

		size_type size() const
		{
			return _size;
		}

		size_type max_size() const
		{
			return std::numeric_limits<difference_type>::max() / (sizeof(Node) / 2);
		}

		//Element access
		reference front() {
			return (_head->data);
		}
		const_reference front() const {
			return (_head->data);
		}
		reference back() {
			return (_tail->data);
		}
		const_reference back() const {
			return (_tail->data);
		}

		//Modifiers
		void push_front(const value_type& val) {
			insert(begin(), val);
		}

		void pop_front() {
			erase(begin());
		}

		void push_back(const value_type& val) {

			insert(end(), val);
		}

		void pop_back() {
			iterator it = end();
			it--;
			erase(it);
		}

		iterator insert(iterator position, const value_type& val)
		{
			listNode<T> *n = new listNode<T>(val);

			if (position._pos)
			{
				position._pos->prev = n;
				n->next = position._pos;
				if (!position._prev)
					_head = n;
				else
				{
					position._prev->next = n;
					n->prev = position._prev;
				}
			}
			else
			{
				_tail = n;
				if (position._prev)
				{
					position._prev->next = n;
					n->prev = position._prev;
				}
				else
					_head = n;
			}
			_size++;
			position._prev = n;
			return iterator(n, n->prev);
		}

		template <class InputIterator>
		void insert (iterator position, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
		{
			;
			iterator buf;
			for (InputIterator it = first; it != last; ++it)
			{
				buf = insert(position, *it);
				position._prev = buf._pos;
			}
		}

		void insert(iterator position, size_type n, const value_type& val)
		{
			iterator buf;
			;
			for (size_type i = 0; i < n; i++)
			{
				;
				buf = insert(position, val);
				;
				position._prev = buf._pos;
			}
			;
		}

		iterator erase(iterator position)
		{
		// return (this->erase(position++, position));
			listNode<T> *next;

			next = position._pos->next;
			if (next)
				next->prev = position._prev;
			else
				_tail = position._prev;
			if (!position._prev)
				_head = next;
			else
				position._prev->next = next;
			delete position._pos;
			position._pos = next;
			 _size--;
			return position;
		}

		iterator erase(iterator first, iterator last)
		{
			// listNode<T> *last_del = last._pos;
			// listNode<T> *before_del = first._pos->prev;
			//
			// std::cout << *first << std::endl;
			// std::cout << *last << std::endl;
			// before_del->next = last_del;
			// last_del->prev = before_del;
			// while (first != last)
			// {
			// 	std::cout << "jere" << std::endl;
			// 	--_size;
			// 	delete (first++)._pos;
			// }
			// return last;
			iterator it = first;
			while(it != last)
				it = erase(it);
			return last;
		}

		void assign(size_type n, const value_type &val)
		{
			listNode<T> *current;
			listNode<T> *prev;

			clear();
			for (size_type i = 0; i < n; i++)
			{
				listNode<T> *n = new listNode<T>(val);
				if (i == 0)
					_head = n;
				else
				{
					n->prev = prev;
					prev->next = n;
				}
				current = n;
				prev = current;
				current = current->next;
			}
			if (!current)
				_tail = prev;
			_size = n;
		}

		template <class InputIterator>
		void assign (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
		{
			listNode<T> *current;
			listNode<T> *prev;
			clear();
			_size = 0;

			for (InputIterator it = first; it != last; it++)
			{
				listNode<T> *n = new listNode<T>(*it);
				if (it == first)
					_head = n;
				else
				{
					n->prev = prev;
					prev->next = n;
				}
				current = n;
				prev = current;
				current = current->next;
				_size++;
			}
			if (!current)
				_tail = prev;

		}

		void swap (list<T>& x)
		{
			listNode<T> *buf_head = _head;
			listNode<T> *buf_tail = _tail;
			size_type buf_size = _size;
			_head = x._head;
			_tail = x._tail;
			_size = x._size;
			x._head = buf_head;
			x._tail = buf_tail;
			x._size = buf_size;
		}

		void resize (size_type n, value_type val = value_type())
		{
			if (n > _size)
				insert(end(), n - _size, val);
			else
			{
				iterator it;
				it = end();
				for (size_type i = 0; i < _size - n; i++)
					it--;
				erase(it, end());
			}
		}

		void clear()
		{
			erase(begin(), end());
			_head = NULL;
		}

		//Operations

		void splice (iterator position, list<T>& x)
		{
			if (this == &x)
				return ; // Undefined behavior
			this->splice(position, x, x.begin(), x.end());
		}

		void splice (iterator position, list<T>& x, iterator i)
		{
			x.unlink(i._pos);
			i._prev = NULL;
			if (empty())
			{
				_head = _tail = i._pos;
			}
			else if (position._pos == _head)
			{
				_head->prev = i._pos;
				i._pos->next = _head;
				_head = i._pos;

			}
			else if (position._pos == 0)
			{
				_tail->next = i._pos;
				i._pos->prev = _tail;
				i._prev = _tail;
				_tail= i._pos;
			}
			else
			{
				i._pos->next = position._pos;
				i._pos->prev = position._pos->prev;
				i._prev  = position._prev;
				i._pos->prev->next = i._pos;
				i._pos->next->prev = i._pos;
			}
			_size++;
		}

		void splice (iterator position, list<T>& x, iterator first, iterator last)
		{
			if (!x._head || first == last)
				return ;

			listNode<T> *last_node = (last._pos);
			listNode<T> *last_attach = (last._pos) ? last._pos : last._prev;

			_size += x.unlink(first._pos, last_node);



			if (empty())
			{
				_head = first._pos;
				_tail = last_attach;
			}

			else if (position._pos == _head)
			{
				if (_head != NULL)
					_head->prev = last_attach;
				if (last_attach != NULL)
					last_attach->next = _head;
				_head = first._pos;
			}
			else if (position._pos == NULL)
			{
				_tail->next = first._pos;
				first._pos->prev = _tail;
				_tail = last_attach;
			}
			else
			{
				position._pos->prev->next = first._pos;
				first._prev =  position._pos->prev;
				first._pos->prev = position._pos->prev;
				position._pos->prev = last_attach;
				position._prev = last_attach;
				last_attach->next = position._pos;
			}
		}


		void remove (const value_type& val)
		{
			{
				iterator it = begin();
				while (it != end())
				{
					if (*it == val)
					{
						erase(it);
						it = begin();
					}
					else
						++it;
				}
			}
		}

		template <class Predicate>
		void remove_if (Predicate pred)
		{
			iterator it = begin();
			while (it != end())
			{
				if (pred(*it))
				{
					erase(it);
					it = begin();
				}
				else
					++it;
			}
		}

		void unique()
		{
			iterator it2;
			for (iterator it = begin(); it != end(); it++)
			{
				it2 = it;
				it2++;
				for (; it2 != end(); it2++)
				{
					if (*it2 == *it)
					{
						erase(it2);
						it2 = it;
						if (it2 != end())
							it2++;
					}
				}
			}
		}
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred)
		{
			iterator first = begin();
			iterator last = end();
			iterator tmp;
			tmp = first++;

			while (first != last)
			{
				if (binary_pred(*first, *tmp))
					erase(first--);
				tmp = first++;
			}
			// for (iterator it = begin(); it != end(); it++)
			// {
			// 	it2 = it;
			// 	if (it2 != end())
			// 		it2++;
			// 	for (; it2 != end(); it2++)
			// 	{
			// 		if (binary_pred(*it, *it2))
			// 		{
			// 			erase(it2);
			// 			it2 = it;
			// 			if (it2._pos->next)
			// 				it2++;
			// 		}
			// 	}
			// }
		}

		void merge (list<T>& x)
		{
			if (this == &x)
				return ;
			_tail->next = x._head;
			x._head->prev = _tail;
			_tail = x._tail;
			_size += x._size;
			sort();
			x._head = NULL;
			x._tail = NULL;
			x._size = 0;
		}

		template <class Compare>
		void merge (list<T>& x, Compare comp)
		{
			if (this == &x)
				return ;
			iterator this_it = this->begin(), x_it = x.begin();

			while (x_it != x.end() && this_it != this->end())
			{
				if (comp(*x_it, *this_it))
					this->splice(this_it, x, x_it++);
				else
					++this_it;
			}
			if (!x.empty())
				this->splice(this->end(), x);


			// if (this == &x)
			// 	return ;
			// _tail->next = x._head;
			// x._head->prev = _tail;
			// _tail = x._tail;
			// _size += x._size;
			// sort(comp);
			// x._head = NULL;
			// x._tail = NULL;
			// x._size = 0;
		}

		void sort()
		{
			sort_helper_(_head, _tail);
		}

		template <class Compare>
		void sort(Compare comp)
		{
			sort_helper_(_head, _tail, comp);
		}

		void reverse()
		{
			listNode<T> *temp = NULL;
			listNode<T> *current = _head;
			_tail = _head;
		    while (current != NULL)
		    {
		        temp = current->prev;
		        current->prev = current->next;
		        current->next = temp;
		        current = current->prev;
		    }

		    /* Before changing the head, check for the cases like empty
		        list and list with only one node */
		    if(temp != NULL )
		        _head = temp->prev;
		}
	private:

		listNode<T> *partition(listNode<T> *first, listNode<T> *last)
		{
			T x = last->data;
			listNode<T> *i = first->prev;
			for (listNode<T> *j = first; j != last; j = j->next)
			{
				if (j->data <= last->data)
				{
					i = i == NULL ? first : i->next;
					swap_T((i->data), (j->data));
				}
			}
			i = i == NULL ? first : i->next;
			swap_T((i->data), (last->data));
			return i;
		}

		void sort_helper_(listNode<T> *first, listNode<T> *last)
		{
			if (last != NULL && first != last && first != last->next)
			{
				listNode<T> *p = partition(first, last);
				sort_helper_(first, p->prev);
				sort_helper_(p->next, last);
			}
		}
		template <class Compare>
		listNode<T> *partition(listNode<T> *first, listNode<T> *last, Compare comp)
		{
			T x = last->data;
			listNode<T> *i = first->prev;
			for (listNode<T> *j = first; j != last; j = j->next)
			{
				if (comp(j->data, x))
				{

					i = i == NULL ? first : i->next;
					swap_T((i->data), (j->data));
				}
			}
			i = i == NULL ? first : i->next;
			swap_T((i->data), (last->data));
			return i;
		}

		template <class Compare>
		void sort_helper_(listNode<T> *first, listNode<T> *last, Compare comp)
		{
			if (last != NULL && first != last && first != last->next)
			{
				listNode<T> *p = partition(first, last, comp);
				sort_helper_(first, p->prev, comp);
				sort_helper_(p->next, last, comp);
			}
		}

		void swap_T(T &first, T &second)
		{
			T buf = first;
			first = second;
			second = buf;
		}

		typedef listNode<T> Node;
		Node		*_head;
		Node		*_tail;
		size_type		_size;

		size_t unlink(listNode<T> *first, listNode<T> *last)
		{
			size_t range_size = 0;
			for (Node *trav = first; trav != last; trav = trav->next)
			{
				range_size++;
			}

			if (range_size == _size || (first == _head && last == 0))
			{
				_head = _tail = 0;
			}
			else if (first == _head)
			{
				_head = last;
				if (last != NULL)
					last->prev->next = 0;
				_head->prev = 0;
			}
			else if (last == 0)
			{
				_tail = first->prev;
				_tail->next = 0;
			}
			else
			{
				first->prev->next = last;
				if (last->prev != NULL)
					last->prev->next = 0;
				last->prev = first->prev;
			}
			first->prev = 0;
			_size -= range_size;

			return range_size;
		}
		void unlink(listNode<T> *position)
		{
			if (!position)
				return;
			_size--;
			if (_size < 1)
			{
				_head = _tail = 0;
			}
			else if (position == _head)
			{
				_head = _head->next;
				_head->prev = 0;
			}
			else if (position == _tail)
			{
				_tail = _tail->prev;
				_tail->next = 0;
			}
			else
			{
				position->prev->next = position->next;
				position->next->prev = position->prev;
			}
			position->prev = position->next = 0;
		}
	};
	template <class Ite1, class Ite2>
	bool equal (Ite1 first, Ite1 last, Ite2 first2)
	{
		while (first != last)
		{
			if (*first != *first2)
				return false;
			++first;
			++first2;
		}
		return true;
	}

	template <class Ite1, class Ite2>
	bool lexicographical_compare(Ite1 first1, Ite1 last1, Ite2 first2, Ite2 last2)
	{
		while (first1 != last1 && first2 != last2 && *first1 == *first2)
		{
			++first1; ++first2;
		}
		if (first1 == last1)
			return (first2 != last2);
		else if (first2 == last2)
			return (false);
		return (*first1 < *first2);
	}
	template <class T, class Alloc>
	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
		  	return false;
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return !(lhs==rhs);
	}
	template <class T, class Alloc>
	bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	  template <class T, class Alloc>
		void	swap(list<T, Alloc> &x, list<T, Alloc> &y) { x.swap(y); }
}

#endif
