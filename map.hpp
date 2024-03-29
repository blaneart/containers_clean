/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:11:54 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/28 16:26:06 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
#define MAP_HPP

#include "utility.hpp"

namespace ft
{
	//Node

	template <class value_type>
	struct Node
	{
		bool _unused;
		#if __APPLE__ == 0
			int _unused_for_linux;
		#endif
		value_type			e;
		Node				*right;
		Node				*left;
		Node				*parent;
		Node() :
		e(), right(NULL), left(NULL), parent(NULL)
		{}
		template <class U>
		Node(const U& pr = U()):
		e(pr), right(NULL), left(NULL), parent(NULL)
		{}
	};


	template <class T, class Compare, bool is_const = false >
	class MapIterator
	{
		public:
			typedef typename choose<is_const, const T &, T &>::type 				reference;
			typedef typename choose<is_const, const T *, T *>::type 				pointer;
			typedef typename choose<is_const, const T, T>::type 					value_type;
			typedef MapIterator<value_type, Compare, is_const>						iterator;
			typedef typename choose<is_const, const Node<T>*, Node<T>*>::type		nodeptr;

		private:
			nodeptr current;
			nodeptr prev;

		public:
			MapIterator() :
				current(NULL), prev(NULL)
			{}

			MapIterator(nodeptr b, nodeptr prev = NULL) :
				current(b), prev(prev)
			{}

			MapIterator(MapIterator const &it) :
				current(it.current), prev(it.prev)
			{}

			MapIterator &operator=(const MapIterator &it)
			{
				this->current = it.current;
				this->prev = it.prev;
				return *this;
			}

			~MapIterator()
			{}

			operator MapIterator<value_type, Compare>()
	 		{
				return MapIterator<value_type, Compare>(current, prev);
			}

			operator MapIterator<value_type, Compare, true>() const
			{
				return MapIterator<value_type, Compare, true>(current, prev);
			}

			MapIterator &operator++()
			{
				Node<T> *p;

				if (current->right)
				{
					prev = current;
					current = current->right;
					while (current->left)
					{
						prev = current;
						current = current->left;
					}
				}
				else
				{
					p = current->parent;
					while (p != NULL && current == p->right)
					{
						prev = current;
						current = p;
						p = current->parent;
					}
					prev = current;
					current = p;
				}
				return *this;
			}

			MapIterator 	operator++(int)
			{
				MapIterator copy(*this);
				++*this;
				return copy;
			}

			MapIterator &operator--()
			{
				Node<T> *p;

				if (!current && prev)
				{
					current = prev;
					prev = prev->parent;
					return *this;
				}
				if (current->left)
				{
					prev = current;
					current = current->left;
					while (current->right)
					{
						prev = current;
						current = current->right;
					}
				}
				else
				{
					p = current->parent;
					while (p != NULL && current == p->left)
					{
						prev = current;
						current = p;
						p = current->parent;
					}
					prev = current;
					current = p;
				}
				return *this;
			}

			MapIterator operator--(int)
			{
				MapIterator copy(*this);
				--*this;
				return copy;
			}

			pointer operator->() const
			{
				return &this->operator*();
			}

			reference operator*() const
			{
				return this->current->e;
			}

			template <class U, class V, bool E>
			bool	operator==(const MapIterator<U, V, E> &rhs) const
			{
				return current == rhs.current;
			}
			template <class U, class V, bool E>
			bool	operator!=(const MapIterator<U, V, E> &rhs) const
			{
				return !(*this == rhs);
			}
			// template <class U, class V>
			// friend bool operator!=(const MapIterator<U,V>& lhs, const MapIterator<U,V>& rhs);
			// template <class U, class V>
			// friend bool operator==(const MapIterator<U,V>& lhs, const MapIterator<U,V>& rhs);
			template <class, class, class, class>
			friend class map;
			template <class, class, bool>
			friend class MapIterator;
	};
	template <class Iterator>
	class reverseMapIterator
	{
	private:
		Iterator _base;

	public:
		typedef Iterator iterator_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;

		reverseMapIterator() :
			_base()
			{ }
		reverseMapIterator(Iterator base):
			_base(base)
			{}

		template <class U>
		reverseMapIterator(const reverseMapIterator<U> &u):
			_base(u.base())
		{
		}
		reverseMapIterator(const reverseMapIterator<Iterator> & other):
			_base(other.base())
		{
		}
		reverseMapIterator<Iterator>& operator=(const reverseMapIterator<Iterator>& other)
		{
			_base = other.base();
			return *this;
		}

		~reverseMapIterator()
		{}

		Iterator base() const
		{
			Iterator cpy(_base);
			return cpy;
		}

		reverseMapIterator<Iterator>& operator++()
		{
			--_base;
			return *this;
		}

		reverseMapIterator<Iterator>& operator--() {
			++_base;
			return *this;
		}

		reverseMapIterator<Iterator> operator++(int)
		{
			reverseMapIterator cpy(*this);
			--_base;
			return cpy;
		}

		reverseMapIterator<Iterator> operator--(int)
		{
			reverseMapIterator cpy(*this);
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
		bool	operator==(const reverseMapIterator<U> &rhs) const
		{
			return _base == rhs.base();
		}

		template <class U>
		bool	operator!=(const reverseMapIterator<U> &rhs) const
		{
			return _base != rhs.base();
		}
	};
	// template <class U, class V>
	// bool operator!=(const MapIterator<U,V>& lhs, const MapIterator<U,V>& rhs)
	// {
	// 	return lhs.current != rhs.current && lhs.prev != rhs.prev;
	// }
	// template <class U, class V>
	// bool operator==(const MapIterator<U,V>& lhs, const MapIterator<U,V>& rhs)
	// {
	// 	return lhs.current == rhs.current && lhs.prev == rhs.prev;
	// }

	// template <class Key, class T, class Compare = std::less<Key> >
	// class ReverseMapIterator
	// {
	// 	private:
	// 		Node<>	*current;
	// 		Node<Key,T>	*prev;
	// 	public:
	// 		ReverseMapIterator() :
	// 			current(NULL), prev(NULL)
	// 		{}
	// 		ReverseMapIterator(Node<Key,T> *b, Node<Key,T> *prev = NULL) :
	// 			current(b), prev(prev)
	// 		{}
	// 		ReverseMapIterator(ReverseMapIterator const &it) :
	// 			current(it.current), prev(it.prev)
	// 		{}
	//
	// 		ReverseMapIterator &operator=(const ReverseMapIterator &it)
	// 		{
	// 			this->current = it.current;
	// 			this->prev = it.prev;
	// 			return *this;
	// 		}
	// 		~ReverseMapIterator()
	// 		{}
	//
	// 		ReverseMapIterator<Key, T> &operator--()
	// 		{
	// 			Node<Key, T> *p;
	//
	// 			if (current->right)
	// 			{
	// 				prev = current;
	// 				current = current->right;
	// 				while (current->left)
	// 				{
	// 					prev = current;
	// 					current = current->left;
	// 				}
	// 			}
	// 			else
	// 			{
	// 				p = current->parent;
	// 				while (p != NULL && current == p->right)
	// 				{
	// 					prev = current;
	// 					current = p;
	// 					p = current->parent;
	// 				}
	// 				prev = current;
	// 				current = p;
	// 			}
	// 			return *this;
	// 		}
	//
	// 		ReverseMapIterator<Key, T> operator--(int)
	// 		{
	// 			ReverseMapIterator<Key, T> copy(*this);
	// 			--*this;
	// 			return copy;
	// 		}
	//
	// 		ReverseMapIterator<Key, T> &operator++()
	// 		{
	// 			Node<Key, T> *p;
	//
	// 			if (!current && prev)
	// 			{
	// 				current = prev;
	// 				prev = prev->parent;
	// 				return *this;
	// 			}
	// 			if (current->left)
	// 			{
	// 				prev = current;
	// 				current = current->left;
	// 				while (current->right)
	// 				{
	// 					prev = current;
	// 					current = current->right;
	// 				}
	// 			}
	// 			else
	// 			{
	// 				p = current->parent;
	// 				while (p != NULL && current == p->left)
	// 				{
	// 					prev = current;
	// 					current = p;
	// 					p = current->parent;
	// 				}
	// 				prev = current;
	// 				current = p;
	// 			}
	// 			return *this;
	// 		}
	//
	// 		ReverseMapIterator<Key, T> operator++(int)
	// 		{
	// 			ReverseMapIterator<Key, T> copy(*this);
	// 			++*this;
	// 			return copy;
	// 		}
	//
	// 		pair<Key,T> *operator->() const
	// 		{
	// 			return &this->current->e;
	// 		}
	//
	// 		pair<Key,T> &operator*() const
	// 		{
	// 			return this->current->e;
	// 		}
	//
	// 		template <class U, class V>
	// 		friend bool operator!=(const ReverseMapIterator<U,V>& lhs, const ReverseMapIterator<U,V>& rhs);
	// 		template <class U, class V>
	// 		friend bool operator==(const ReverseMapIterator<U,V>& lhs, const ReverseMapIterator<U,V>& rhs);
	// 		template <class U, class V, class C>
	// 		friend class map;
	// };
	// template <class U, class V>
	// bool operator!=(const ReverseMapIterator<U,V>& lhs, const ReverseMapIterator<U,V>& rhs)
	// {
	// 	return lhs.current != rhs.current && lhs.prev != rhs.prev;
	// }
	// template <class U, class V>
	// bool operator==(const ReverseMapIterator<U,V>& lhs, const ReverseMapIterator<U,V>& rhs)
	// {
	// 	return lhs.current == rhs.current && lhs.prev == rhs.prev;
	// }


	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef pair<const key_type, mapped_type>				value_type;
		typedef Compare											key_compare;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::value_type&			reference;
		typedef const typename allocator_type::value_type&		const_reference;
		typedef	typename allocator_type::value_type*			pointer;
		typedef const typename allocator_type::value_type*		const_pointer;
		typedef MapIterator<value_type, key_compare>			iterator;
		typedef MapIterator<value_type, key_compare, true>		const_iterator;
		typedef reverseMapIterator<iterator>					reverse_iterator;
		typedef reverseMapIterator<const_iterator>				const_reverse_iterator;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;

		private:
			Node<value_type>	*_head;
			size_type			_size;
			key_compare			_comp;
			allocator_type		_alloc;

			bool f(const Key a, const Key b, Compare u = Compare())
			{
				return (u(a, b));
			}

			bool f(const Key a, const Key b, Compare u = Compare()) const
			{
				return (u(a, b));
			}

			class value_compare
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					typedef pair<const Key, T>		value_type;
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

			void delete_helper(Node<value_type> *cur)
			{
				if (cur->left)
					delete_helper(cur->left);
				if (cur->right)
					delete_helper(cur->right);
				delete cur;
				cur = NULL;
			}
		public:
			explicit map(const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()) :
				_size(0), _comp(comp), _alloc(alloc)
			{
				_head = NULL;
			}

			template <class InputIterator>
 			map(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first,
				InputIterator last,
       			const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type()) :
				_size(0), _comp(comp), _alloc(alloc)
			{
				_head = NULL;
				insert(first, last);
			}

			map (const map& x) :
			_size(0), _comp(x._comp), _alloc(x._alloc)
			{
				_head = NULL;
				if (!x.empty())
					insert(x.begin(), x.end());
			}

			map<Key, T, Compare, Alloc>&	operator=(map const &x)
			{
				if (this == &x)
					return (*this);
				clear();
				_head = NULL;
				_size = 0;
				_comp = x._comp;
				if (!x.empty())
					insert(x.begin(), x.end());
				return *this;
			}

			~map()
			{
				Node<value_type> *start;

				start = _head;
				if (start)
					delete_helper(start);
			}

			iterator begin()
			{
				Node<value_type> *buf;
				buf = _head;

				if (buf != NULL)
				{
					while(buf->left)
				 		buf = buf->left;
				}
				return (iterator(buf));
			}

			const_iterator begin() const
			{
				Node<value_type> *buf;
				buf = _head;
				if (buf)
				{
					while(buf->left)
				 		buf = buf->left;
				}
				return (const_iterator(buf));
			}

			reverse_iterator rbegin()
			{
				Node<value_type> *buf;
				buf = _head;
				if (buf)
				{
					while(buf->right)
				 		buf = buf->right;
				}
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				Node<value_type> *buf;
				buf = _head;
				if (buf)
				{
					while(buf->right)
						buf = buf->right;
				}
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend()
			{
				Node<value_type> *buf;
				buf = _head;
				if (buf)
				{
					while(buf->left)
						buf = buf->left;
				}
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				Node<value_type> *buf;
				buf = _head;
				if (buf)
				{
					while(buf->left)
						buf = buf->left;
				}
				return (const_reverse_iterator(begin()));
			}

			iterator end()
			{
				Node<value_type> *buf;
				buf = _head;
				if (buf)
				{
					while(buf->right)
						buf = buf->right;
				}
				return (iterator(NULL, buf));
			}

			const_iterator end() const
			{
				Node<value_type> *buf;
				buf = _head;
				if (buf)
				{
					while(buf->right)
						buf = buf->right;
				}
				return (const_iterator(NULL, buf));
			}
			// Capacity

			bool empty() const
			{
				return !_size;
			}

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return std::numeric_limits<difference_type>::max() / (sizeof(Node<value_type>) / 2 ?: 1);
			}
			// Element Access

			mapped_type& operator[] (const key_type& k)
			{
				return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
			}

			// Modifiers

			pair<iterator, bool> insert (const value_type& val)
			{
				Node<value_type>	*buf;
				Node<value_type>	*prev;
				bool				ret;
				iterator			it;

				buf = _head;
				prev = NULL;
				ret = true;
				it = begin();
				while (buf != NULL)
				{
					if (buf->e.first == val.first)
					{
						ret = false;
						it = iterator(buf, NULL);
						break ;
					}
					prev = buf;
					if (f(val.first, buf->e.first, _comp))
						buf = buf->left;
					else
						buf = buf->right;
				}
				if (prev && ret)
				{
					Node<value_type> *to_insert = new Node<value_type>(val);
					if (f(val.first, prev->e.first, _comp))
						prev->left = to_insert;
					else
						prev->right = to_insert;
					to_insert->parent = prev;
					it = iterator(to_insert);
				}
				else if (ret)
				{
					_head = new Node<value_type>(val);
					// _head->left = NULL;
					it = begin();
				}
				if (ret)
					_size++;

				return pair<iterator,bool>(it,ret);
			}

			iterator insert(iterator position, const value_type& val)
			{
				pair<iterator,bool> ret;
				iterator it;

				it = position;
				if (!empty() && f(position->first, val.first, _comp) && !it.current->right && position->first != val.first)
				{
					++position;
					if (f(val.first, position->first, _comp) && position->first != val.first)
					{
						it.current->right = new Node<value_type>(val);
						it.current->right->parent = it.current;
						ret.first = iterator(it.current->right);
						_size++;
					}
					else
						ret = insert(val);
				}
				else if (!empty() && f(val.first, position->first, _comp) && !it.current->left && position->first != val.first)
				{
					--position;
					if (f(position->first, val.first, _comp) && position->first != val.first)
					{
						it.current->left = new Node<value_type>(val);
						it.current->left->parent = it.current;
						ret.first = iterator(it.current->left);
						_size++;
					}
					else
						ret = insert(val);
				}
				else
					ret = insert(val);
				return ret.first;
			}

			template <class InputIterator>
			void insert (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
			{
				for (InputIterator it = first; it != last; ++it)
					insert(*it);
			}


			void erase (iterator position)
			{
				Node<value_type> *p;
				iterator it;

				it = position;
				p = position.current->parent;
				if (position.current->right)
				{
					if (p && p->right == position.current)
						p->right = position.current->right;
					else if (p && p->left == position.current)
						p->left = position.current->right;
					position.current->right->parent = p;
					if (!p)
						_head = position.current->right;
					if (position.current->left && position.current->right->left)
					{
						--it;
						it.current->right = position.current->right->left;
					}
					if (position.current->left)
					{
						position.current->right->left = position.current->left;
						position.current->left->parent = position.current->right;
					}
				}
				else if (position.current->left)
				{
					if (!p)
						_head = position.current->left;
					if (p && p->right == position.current)
						p->right = position.current->left;
					else if (p && p->left == position.current)
						p->left = position.current->left;
					position.current->left->parent = p;
				}
				else
				{
					if (!p)
						_head = position.current->right;
					if (p && p->right == position.current)
						p->right = NULL;
					else if (p && p->left == position.current)
						p->left = NULL;
				}
				delete position.current;
				position.current->parent = NULL;
				_size--;
			}

			size_type erase (const key_type& k)
			{
				iterator it;

				it = find(k);
				if (it != end())
					erase(it);
				else
					return 0;
				return 1;
			}

			void erase (iterator first, iterator last)
			{
				for (iterator it = first; it != last; ++it)
					erase(it);
			}

			void clear()
			{
				iterator it = begin();
				iterator ite = end();
				while (it != ite)
					erase(it++);
				_head = NULL;
			}

			// Operations
			iterator find (const key_type& k)
			{
				iterator it;

				it = begin();
				while (it != end())
				{
					if (!f(k, it->first, _comp) && !f(it->first, k, _comp))
						return it;
					++it;
				}
				return it;
			}

			const_iterator find (const key_type& k) const
			{
				const_iterator it;

				it = begin();
				while (it != end())
				{
					if (!f(k, it->first, _comp) && !f(it->first, k, _comp))
						return it;
					++it;
				}
				return it;
			}

			size_type count (const key_type& k) const
			{
				const_iterator it = begin();
				const_iterator ite = end();
				for (; it != ite; ++it)
					if (!f(k, it->first, _comp) && !f(it->first, k, _comp))
						return 1;
				return 0;
			}

			void swap (map& x)
			{
				Node<value_type> *buf;
				int saved_size;

				saved_size = _size;
				buf = _head;
				_head = x._head;
				_size = x._size;
				x._head = buf;
				x._size = saved_size;
			}

			key_compare key_comp() const
			{
				return key_compare();
			}

			iterator lower_bound (const key_type& k)
			{
				for (iterator it = begin(); it != end(); ++it)
				{
					if (!f(it->first, k, _comp))
						return it;
				}
				return end();
			}

			const_iterator lower_bound (const key_type& k) const
			{
				for (const_iterator it = begin(); it != end(); ++it)
				{
					if (!f(it->first, k, _comp))
						return it;
				}
				return end();
			}

			iterator upper_bound (const key_type& k)
			{
				for (iterator it = begin(); it != end(); ++it)
				{
					if (f(k, it->first, _comp))
						return it;
				}
				return end();
			}

			const_iterator upper_bound (const key_type& k) const
			{
				for (const_iterator it = begin(); it != end(); ++it)
				{
					if (f(k, it->first, _comp))
						return it;
				}
				return end();
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				pair<const_iterator, const_iterator> ret;
				ret.first = lower_bound(k);
				ret.second = upper_bound(k);
				return ret;
			}

			pair<iterator,iterator>             equal_range (const key_type& k)
			{
				pair<iterator, iterator> ret;
				ret.first = lower_bound(k);
				ret.second = upper_bound(k);
				return ret;
			}

			value_compare value_comp() const
			{
				return value_compare(key_comp());
			}
	};

	// template <class Ite1, class Ite2>
	// bool equal (Ite1 first, Ite1 last, Ite2 first2)
	// {
	// 	while (first != last)
	// 	{
	// 		if (*first != *first2)
	// 			return false;
	// 		++first;
	// 		++first2;
	// 	}
	// 	return true;
	// }
	//
	// template <class Ite1, class Ite2>
	// bool lexicographical_compare(Ite1 first1, Ite1 last1, Ite2 first2, Ite2 last2)
	// {
	// 	while (first1 != last1 && first2 != last2 && *first1 == *first2)
	// 	{
	// 		++first1; ++first2;
	// 	}
	// 	if (first1 == last1)
	// 		return (first2 != last2);
	// 	else if (first2 == last2)
	// 		return (false);
	// 	return (*first1 < *first2);
	// }

	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc> &lhs,
						const map<Key, T, Compare, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc> &lhs,
						const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator< (const map<Key, T, Compare, Alloc> &lhs,
						const map<Key, T, Compare, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc> &lhs,
						const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator> (const map<Key, T, Compare, Alloc> &lhs,
						const map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc> &lhs,
						const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}
}

#endif
