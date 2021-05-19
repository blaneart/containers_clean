#ifndef SET_HPP
#define SET_HPP
#include <functional>
#include <utility>

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

	template <class Key, class T>
	struct pair
	{
		Key	first;
		T	second;

		typedef	Key				first_type;
		typedef T				second_type;
		pair():
		first(), second()
		{}
		template<class U, class V>
		pair(const pair<U,V>& pr):
		first(pr.first), second(pr.second)
		{}
		pair (const first_type& a, const second_type& b):
		first(a), second(b)
		{}
		pair& operator=(const pair& pr)
		{
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		}
	};

	//Relational operators
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first==rhs.first && lhs.second==rhs.second;
	}
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs==rhs);
	}
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	}
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs<lhs);
	}
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return rhs<lhs;
	}
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs<rhs);
	}
	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
			return pair<T1,T2>(x, y);
	}

	//Nodes
	template <class T, class NodeType, bool is_const = false >
	class setIterator
	{
	public:
		typedef typename choose<is_const, const T &, T &>::type 				reference;
		typedef typename choose<is_const, const T *, T *>::type 				pointer;
		typedef typename choose<is_const, const T, T>::type 					value_type;
		typedef typename choose<is_const, const NodeType *, NodeType *>::type	nodeptr;
		typedef typename choose<is_const, const NodeType, NodeType>::type		node;
		typedef setIterator<value_type, node, is_const>							iterator;

		private:
			nodeptr		current;
			nodeptr		prev;
		public:
			setIterator():
				current(NULL), prev(NULL)
			{
			}
			setIterator(nodeptr current, nodeptr prev = NULL):
				current(current), prev(prev)
			{
			}
			setIterator(const setIterator &it):
				current(it.current), prev(it.prev)
			{
			}
			~setIterator()
			{}

			operator setIterator<value_type, node,true>() const
			{
				return setIterator<value_type, node, true>(current, prev);
			}

			operator setIterator<value_type, node>()
	 		{
				return setIterator<value_type, node>(current, prev);
			}

			setIterator &operator=(const setIterator &it)
			{
				current = it.current;
				prev = it.prev;
				return *this;
			}

			setIterator &operator++()
			{
				NodeType *p;

				if (current->rightChild)
				{
					prev = current;
					current = current->rightChild;
					while (current->leftChild)
					{
						prev = current;
						current = current->leftChild;
					}
				}
				else
				{
					p = current->parent;
					while (p != NULL && current == p->rightChild)
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

			setIterator operator++(int)
			{
				setIterator copy(*this);
				++*this;
				return copy;
			}

			setIterator &operator--()
			{
				NodeType *p;

				if (!current && prev)
				{
					current = prev;
					prev = prev->parent;
					return *this;
				}
				if (current->leftChild)
				{
					prev = current;
					current = current->leftChild;
					while (current->rightChild)
					{
						prev = current;
						current = current->rightChild;
					}
				}
				else
				{
					p = current->parent;
					while (p != NULL && current == p->leftChild)
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

			setIterator operator--(int)
			{
				setIterator copy(*this);

				--*this;
				return copy;
			}

			pointer operator->() const
			{
				return &this->current->nodeData;
			}

			reference operator*() const
			{
				return this->current->nodeData;
			}

			template <class U, class V, bool E>
			bool	operator==(const setIterator<U, V, E> &rhs) const
			{
				return this->current == rhs.current;
			}
			template <class U, class V, bool E>
			bool	operator!=(const setIterator<U, V, E> &rhs) const
			{
				return !(*this == rhs);
			}

			template <class, class, class>
			friend class set;
			template <class, class, bool>
			friend class setIterator;
			// template <class U, class V>
			// friend bool operator!= (const setIterator<U,V>& lhs, const setIterator<U,V>& rhs);
			// template <class U, class V>
			// friend bool operator!= (const setIterator<U,V>& lhs, const setIterator<U,V>& rhs);
			// template <class U, class V>
			// friend bool operator== (const setIterator<U,V>& lhs, const setIterator<U,V>& rhs);
			// template <class U, class C>
			// friend class set;
	};

	// template <class U, class V, bool B>
	// bool operator!=(const setIterator<U,V>& lhs, const setIterator<U,V>& rhs)
	// {
	// 	return lhs.current != rhs.current && lhs.prev != rhs.prev;
	// }
	//
	// template <class U, class V, bool>
	// bool operator==(const setIterator<U,V>& lhs, const setIterator<U,V>& rhs)
	// {
	// 	return lhs.current == rhs.current && lhs.prev == rhs.prev;
	// }

	template <class Iterator>
	class ReverseSetIterator
	{
		private:
			Iterator _base;
		public:
			typedef Iterator iterator_type;
			typedef typename Iterator::value_type value_type;
			typedef typename Iterator::pointer pointer;
			typedef typename Iterator::reference reference;

			ReverseSetIterator():
				_base()
			{}

			ReverseSetIterator(Iterator base):
				_base(base)
			{}

			template <class U>
			ReverseSetIterator(const ReverseSetIterator<U> &it):
				_base(it.base())
			{}

			ReverseSetIterator(const ReverseSetIterator<Iterator> &it):
					_base(it.base())
			{}

			~ReverseSetIterator()
			{}

			ReverseSetIterator<Iterator> &operator=(const  ReverseSetIterator<Iterator> &it)
			{
				_base = it.base();
				return *this;
			}

			Iterator base() const
			{
				Iterator cpy(_base);
				return cpy;
			}

			ReverseSetIterator<Iterator> &operator++()
			{
				--_base;
				return *this;
			}

			ReverseSetIterator<Iterator> &operator--()
			{
				++_base;
				return *this;
			}

			ReverseSetIterator<Iterator> operator++(int)
			{
				ReverseSetIterator<Iterator> copy(*this);

				--_base;
				return copy;
			}


			ReverseSetIterator<Iterator> operator--(int)
			{
				ReverseSetIterator<Iterator> copy(*this);
				++_base;
				return copy;
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
			friend bool operator!= (const ReverseSetIterator<U>& lhs, const ReverseSetIterator<U>& rhs);
			template <class U>
			friend bool operator== (const ReverseSetIterator<U>& lhs, const ReverseSetIterator<U>& rhs);
			template <class, class, class>
			friend class set;
	};

	template <class U>
	bool operator!=(const ReverseSetIterator<U>& lhs, const ReverseSetIterator<U>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class U>
	bool operator==(const ReverseSetIterator<U>& lhs, const ReverseSetIterator<U>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
	private:
		struct Node
		{
			T nodeData;
			Node *parent;
			Node *leftChild;
			Node *rightChild;
			Node(const T &val, Node *left = NULL, Node *right = NULL, Node *p = NULL)
			{
				nodeData = val;
				leftChild = left;
				rightChild = right;
				parent = p;
			}
		};
	public:
		typedef T												key_type;
		typedef T												value_type;
		typedef Compare 										key_compare;
		typedef Compare 										value_compare;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::value_type& 			reference;
		typedef const typename allocator_type::value_type& 		const_reference;
		typedef typename allocator_type::value_type*			pointer;
		typedef const typename allocator_type::value_type*		const_pointer;
		typedef setIterator<T, Node>							iterator;
		typedef setIterator<T, Node, true> 						const_iterator;
		typedef ReverseSetIterator<iterator> 					reverse_iterator;
		typedef ReverseSetIterator<const_iterator>	 			const_reverse_iterator;
		typedef ptrdiff_t 										difference_type;
		typedef size_t											size_type;
	private:

		bool f(const T a, const T b, Compare u = Compare())
		{
			return (u(a, b));
		}
		bool f(const T a, const T b, Compare u = Compare()) const
		{
			return (u(a, b));
		}
		Node *				_root;
		size_t 				_size;
		key_compare			_comp;
		allocator_type 		_alloc;

	public:
		// Constructors
		explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
			_root(NULL), _size(0), _comp(comp), _alloc(alloc)
		{
		}

		template <class InputIterator>
		set(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare())
		{
			_root = NULL;
			_size = 0;
			_comp = comp;
			insert(first, last);
		}

		set(const set& x)
		{
			_root = NULL;
			_size = 0;
			_comp = x._comp;
			insert(x.begin(), x.end());
		}

		~set()
		{
			if (_root)
				clear();
		}

		set& operator= (const set& x)
		{
			if (this == &x)
				return (*this);
			if (!empty())
				clear();
			_root = NULL;
			_size = 0;
			_comp = x._comp;
			insert(x.begin(), x.end());
			return *this;
		}
		// Iterators

		iterator begin()
		{
			Node *buf;

			buf = _root;
			while (buf && buf->leftChild)
				buf = buf->leftChild;
			return (iterator(buf, NULL));
		}

		const_iterator begin() const
		{
			Node *buf;
			buf = _root;
			while (buf && buf->leftChild)
				buf = buf->leftChild;
			return (const_iterator(buf, NULL));
		}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			iterator end()
			{
				Node *buf;

				buf = _root;
				while (buf && buf->rightChild)
					buf = buf->rightChild;
				return (iterator(buf->rightChild, buf));
			}

			const_iterator end() const
			{
				Node *buf;

				buf = _root;
				while (buf && buf->rightChild)
					buf = buf->rightChild;
				return (const_iterator(buf->rightChild, buf));
			}

			reverse_iterator rend()
			{
				Node *buf;

				buf = _root;
				while (buf && buf->leftChild)
					buf = buf->leftChild;
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				Node *buf;

				buf = _root;
				while (buf && buf->leftChild)
					buf = buf->leftChild;
				return (const_reverse_iterator(begin()));
			}
			// CAPACITY

			bool empty() const
			{
				return (_size == 0);
			}

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return std::numeric_limits<difference_type>::max();
			}


			// Modifiers

			ft::pair<iterator,bool> insert (const value_type& val)
			{
				Node *buf;
				Node *prev;
				bool ret;
				iterator it;

				buf = _root;
				prev = NULL;
				ret = true;
				it = begin();
				while (buf != NULL)
				{
					if (buf->nodeData == val)
					{
						ret = false;
						it = iterator(buf, prev);
						return (ft::pair<iterator, bool>(it, ret));
					}
					prev = buf;
					if (f(val, buf->nodeData, _comp))
						buf = buf->leftChild;
					else
						buf = buf->rightChild;
				}
				if (prev && ret)
				{
					Node *to_insert = new Node(val);
					if (f(val, prev->nodeData, _comp))
						prev->leftChild = to_insert;
					else
						prev->rightChild = to_insert;
					to_insert->parent = prev;
					it = iterator(to_insert, prev);
				}
				else if (ret)
				{
					_root = new Node(val);
					it = begin();
				}
				if (ret)
				{
					_size++;
				}
				return (ft::pair<iterator, bool>(it, ret));
			}
			iterator insert (iterator position, const value_type& val)
			{
				ft::pair<iterator,bool> ret;
				iterator it;
				it = position;
				if (f(*position, val, _comp) && !it.current->rightChild && *position != val)
				{
					++position;
					if (f(val, *position, _comp) && *position != val)
					{
						it.current->rightChild = new Node(val);
						it.current->rightChild->parent = it.current;
						ret.first = iterator(it.current->rightChild);
						_size++;
					}
					else
						ret = insert(val);
				}
				else if (f(val, *position, _comp) && !it.current->leftChild && *position != val)
				{
					--position;
					if (f(*position, val, _comp) && *position != val)
					{
						it.current->leftChild = new Node(val);
						it.current->leftChild->parent = it.current;
						ret.first = iterator(it.current->leftChild);
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
				ft::pair<ft::set<int>::iterator,bool> ret1;
				for (InputIterator it = first; it != last; ++it)
					ret1 = insert(*it);
			}

			void erase (iterator position)
			{
				Node *p;
				iterator it;

				it = position;
				p = position.current->parent;
				if (position.current->rightChild)
				{
					if (p && p->rightChild == position.current)
						p->rightChild = position.current->rightChild;
					else if (p && p->leftChild == position.current)
						p->leftChild = position.current->rightChild;
					position.current->rightChild->parent = p;
					if (!p)
						_root = position.current->rightChild;
					if (position.current->leftChild && position.current->rightChild->leftChild)
					{
						--it;
						it.current->rightChild = position.current->rightChild->leftChild;
					}
					if (position.current->leftChild)
						position.current->rightChild->leftChild = position.current->leftChild;
				}
				else if (position.current->leftChild)
				{
					if (!p)
						_root = position.current->rightChild;
					if (p && p->rightChild == position.current)
						p->rightChild = position.current->leftChild;
					else if (p && p->leftChild == position.current)
						p->leftChild = position.current->leftChild;
					position.current->leftChild->parent = p;
				}
				else
				{
					if (!p)
						_root = position.current->rightChild;
					if (p && p->rightChild == position.current)
						p->rightChild = NULL;
					else if (p && p->leftChild == position.current)
						p->leftChild = NULL;
				}
				delete position.current;
				position.current->parent = NULL;
				_size--;
			}

			size_type erase (const value_type& val)
			{
				iterator it;

				it = find(val);
				if (it == end())
					return 0;
				else
					erase(it);
				return 1;
			}

			void erase (iterator first, iterator last)
		 	{
				for (iterator it = first; it != last; ++it)
					erase(it);
			}

			void clear()
			{
				if (_root)
					erase(begin(), end());
			}

			iterator find (const value_type& val) const
			{

				Node *buf;

				buf = _root;
				while (buf && buf->leftChild)
					buf = buf->leftChild;
				iterator it(buf);
				for (;it != end(); ++it)
					if (*it == val)
						return it;
				buf = _root;
				while (buf && buf->rightChild)
					buf = buf->rightChild;
				return iterator(buf->rightChild, buf);
			}

			size_type count (const value_type& val) const
			{
				if (find(val) != end())
					return 1;
				else
					return 0;
			}
			void swap (set& x)
			{
				Node *buf;
				int buf_size;

				buf_size = _size;
				buf = _root;
				_root = x._root;
				_size = x._size;
				x._root = buf;
				x._size = buf_size;
			}

			key_compare key_comp() const
			{
				return key_compare();
			}

			value_compare value_comp() const
			{
				return key_compare();
			}

			iterator lower_bound (const value_type& val) const
			{

				Node *buf;

				buf = _root;
				while (buf && buf->leftChild)
					buf = buf->leftChild;
				iterator it(buf);
				for (; it != end(); ++it)
				{
					if (!f(*it, val, _comp))
						return it;
				}
				buf = _root;
				while (buf && buf->rightChild)
					buf = buf->rightChild;
				return iterator(buf->rightChild, buf);
			}


			iterator upper_bound (const value_type& val) const
			{
				Node *buf;

				buf = _root;
				while (buf && buf->leftChild)
					buf = buf->leftChild;
				iterator it(buf);
				for (; it != end(); ++it)
				{
					if (f(val, *it, _comp))
						return it;
				}
				buf = _root;
				while (buf && buf->rightChild)
					buf = buf->rightChild;
				return iterator(buf->rightChild, buf);
			}


			ft::pair<iterator,iterator> equal_range (const value_type& val)
			{
				ft::pair<iterator, iterator> ret;
				ret.first = lower_bound(val);
				ret.second = upper_bound(val);
				return ret;
			}

	};

}

#endif
