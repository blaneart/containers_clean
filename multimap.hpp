/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multimap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:38:53 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/28 16:21:41 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MULTIMAP_HPP
#define MULTIMAP_HPP

#include <iostream>

// There are no guarantees on the relative order of equivalent elements.
// https://www.cplusplus.com/reference/map/multimap/insert/

namespace ft
{


	template <class T, class Compare, bool is_const = false >
	class multiMapIterator
	{
		public:
			typedef typename choose<is_const, const T &, T &>::type 				reference;
			typedef typename choose<is_const, const T *, T *>::type 				pointer;
			typedef typename choose<is_const, const T, T>::type 					value_type;
			typedef multiMapIterator<value_type, Compare, is_const>						iterator;
			typedef typename choose<is_const, const Node<T>*, Node<T>*>::type		nodeptr;

		private:
			nodeptr current;
			nodeptr prev;

		public:
			multiMapIterator() :
				current(NULL), prev(NULL)
			{}

			multiMapIterator(nodeptr b, nodeptr prev = NULL) :
				current(b), prev(prev)
			{}

			multiMapIterator(multiMapIterator const &it) :
				current(it.current), prev(it.prev)
			{}

			multiMapIterator &operator=(const multiMapIterator &it)
			{
				this->current = it.current;
				this->prev = it.prev;
				return *this;
			}

			~multiMapIterator()
			{}

			operator multiMapIterator<value_type, Compare>()
	 		{
				return multiMapIterator<value_type, Compare>(current, prev);
			}

			operator multiMapIterator<value_type, Compare, true>() const
			{
				return multiMapIterator<value_type, Compare, true>(current, prev);
			}

			multiMapIterator &operator++()
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

			multiMapIterator 	operator++(int)
			{
				multiMapIterator copy(*this);
				++*this;
				return copy;
			}

			multiMapIterator &operator--()
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

			multiMapIterator operator--(int)
			{
				multiMapIterator copy(*this);
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
			bool	operator==(const multiMapIterator<U, V, E> &rhs) const
			{
				return current == rhs.current;
			}
			template <class U, class V, bool E>
			bool	operator!=(const multiMapIterator<U, V, E> &rhs) const
			{
				return !(*this == rhs);
			}
			template <class, class, class, class>
			friend class multimap;
			template <class, class, bool>
			friend class multiMapIterator;
	};
	template <class Iterator>
	class reverseMultiMapIterator
	{
	private:
		Iterator _base;

	public:
		typedef Iterator iterator_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;

		reverseMultiMapIterator() :
			_base()
			{ }
		reverseMultiMapIterator(Iterator base):
			_base(base)
			{}

		template <class U>
		reverseMultiMapIterator(const reverseMultiMapIterator<U> &u):
			_base(u.base())
		{
		}
		reverseMultiMapIterator(const reverseMultiMapIterator<Iterator> & other):
			_base(other.base())
		{
		}
		reverseMultiMapIterator<Iterator>& operator=(const reverseMultiMapIterator<Iterator>& other)
		{
			_base = other.base();
			return *this;
		}

		~reverseMultiMapIterator()
		{}

		Iterator base() const
		{
			Iterator cpy(_base);
			return cpy;
		}

		reverseMultiMapIterator<Iterator>& operator++()
		{
			--_base;
			return *this;
		}

		reverseMultiMapIterator<Iterator>& operator--() {
			++_base;
			return *this;
		}

		reverseMultiMapIterator<Iterator> operator++(int)
		{
			reverseMultiMapIterator cpy(*this);
			--_base;
			return cpy;
		}

		reverseMultiMapIterator<Iterator> operator--(int)
		{
			reverseMultiMapIterator cpy(*this);
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
		bool	operator==(const reverseMultiMapIterator<U> &rhs) const
		{
			return _base == rhs.base();
		}

		template <class U>
		bool	operator!=(const reverseMultiMapIterator<U> &rhs) const
		{
			return _base != rhs.base();
		}
	};

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class multimap
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
		typedef multiMapIterator<value_type, key_compare>			iterator;
		typedef multiMapIterator<value_type, key_compare, true>		const_iterator;
		typedef reverseMultiMapIterator<iterator>					reverse_iterator;
		typedef reverseMultiMapIterator<const_iterator>				const_reverse_iterator;
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
				friend class multimap;
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
			explicit multimap(const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()) :
				_size(0), _comp(comp), _alloc(alloc)
			{
				_head = NULL;
			}

			template <class InputIterator>
 			multimap(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first,
				InputIterator last,
       			const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type()) :
				_size(0), _comp(comp), _alloc(alloc)
			{
				_head = NULL;
				insert(first, last);
			}

			multimap (const multimap& x) :
			_size(0), _comp(x._comp), _alloc(x._alloc)
			{
				_head = NULL;
				if (!x.empty())
					insert(x.begin(), x.end());
			}

			multimap<Key, T, Compare, Alloc>&	operator=(multimap const &x)
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

			~multimap()
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

			iterator insert (const value_type& val)
			{
				Node<value_type>	*buf;
				Node<value_type>	*prev;
				iterator			it;

				buf = _head;
				prev = NULL;

				it = begin();
				while (buf != NULL)
				{
					prev = buf;
					if (f(val.first, buf->e.first, _comp))
						buf = buf->left;
					else
						buf = buf->right;
				}
				if (prev)
				{
					Node<value_type> *to_insert = new Node<value_type>(val);
					if (f(val.first, prev->e.first, _comp))
						prev->left = to_insert;
					else
						prev->right = to_insert;
					to_insert->parent = prev;
					it = iterator(to_insert);
				}
				else
				{
					_head = new Node<value_type>(val);
					// _head->left = NULL;
					it = begin();
				}
				_size++;

				return iterator(it);
			}

			iterator insert(iterator position, const value_type& val)
			{
				iterator ret;
				iterator it;

				it = position;
				if (!empty() && f(position->first, val.first, _comp) && !it.current->right && position->first != val.first)
				{
					++position;
					if (f(val.first, position->first, _comp) && position->first != val.first)
					{
						it.current->right = new Node<value_type>(val);
						it.current->right->parent = it.current;
						ret = iterator(it.current->right);
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
						ret = iterator(it.current->left);
						_size++;
					}
					else
						ret = insert(val);
				}
				else
					ret = insert(val);
				return ret;
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
				int c;

				c = 0;
				it = find(k);
				while (it != end())
				{
					erase(it);
					it = find(k);
					c++;
				}
				return c;
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
				int c;

				c = 0;
				for (const_iterator it = this->begin(); it != this->end(); ++it)
					if (!f(k, it->first, _comp) && !f(it->first, k, _comp))
						c++;
				return c;
			}

			void swap (multimap& x)
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


	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const multimap<Key, T, Compare, Alloc> &lhs,
						const multimap<Key, T, Compare, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const multimap<Key, T, Compare, Alloc> &lhs,
						const multimap<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator< (const multimap<Key, T, Compare, Alloc> &lhs,
						const multimap<Key, T, Compare, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const multimap<Key, T, Compare, Alloc> &lhs,
						const multimap<Key, T, Compare, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator> (const multimap<Key, T, Compare, Alloc> &lhs,
						const multimap<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const multimap<Key, T, Compare, Alloc> &lhs,
						const multimap<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}
}

#endif
