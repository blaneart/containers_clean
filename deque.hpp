#ifndef DEQUE_HPP
#define DEQUE_HPP

#ifndef DEQUE_SIZE
#define DEQUE_SIZE 1024
#endif
#include <iostream>
#include <functional>
#include <exception>
#include <stdexcept>

// #include "../Map.hpp"
//array of arrays https://stackoverflow.com/questions/6292332/what-really-is-a-deque-in-stl
// https://stackoverflow.com/questions/43221070/is-it-possible-to-set-the-size-of-the-inner-array-of-a-stldeque buf size

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

	template <class T, bool is_const = false >
	class DequeIterator
	{
	public:
		typedef typename choose<is_const, const T &, T &>::type 	reference;
		typedef typename choose<is_const, const T *, T *>::type 	pointer;
		typedef typename choose<is_const, const T, T>::type 		value_type;
		typedef DequeIterator<value_type, is_const>					iterator;
		typedef ptrdiff_t											difference_type;
	private:
		pointer array;
		int		first;
		int		current;
		int		last;
		size_t	size_;
		int	reserved_size_;
		public:

			DequeIterator():
				array(NULL), first(-1), current(0), last(0), size_(0), reserved_size_(DEQUE_SIZE)
			{}
			DequeIterator(pointer array, int first, int current, int last, size_t size_, int reserved_size_):
				array(array), first(first), current(current), last(last), size_(size_), reserved_size_(reserved_size_)
			{}

			DequeIterator(const DequeIterator &it):
				array(it.array), first(it.first), current(it.current), last(it.last), size_(it.size_), reserved_size_(it.reserved_size_)
			{}

			operator DequeIterator<T, true>() const
		 	{
				return DequeIterator<T,true>(array, first, current, last, size_, reserved_size_);
			}
			DequeIterator &operator=(const DequeIterator &it)
			{
				this->array = it.array;
				this->first = it.first;
				this->current = it.current;
				this->last = it.last;
				this->size_ = it.size_;
				this->reserved_size_ = it.reserved_size_;
				return *this;
			}
			~DequeIterator()
			{}

			DequeIterator &operator++()
			{
				if (current == reserved_size_ - 1 && first != 0)
					current = 0;
				else
					current++;
				return *this;
			}

			DequeIterator &operator--()
			{
				if (current == 0 && first != 0)
					current = reserved_size_ - 1;
				else
					current--;
				return *this;
			}

			DequeIterator operator++(int)
			{
				DequeIterator copy(*this);
				if (current == reserved_size_ - 1 && first != 0)
					current = 0;
				else
					current++;
				return copy;
			}

			DequeIterator operator--(int)
			{
				DequeIterator copy(*this);

				if (current == 0 && first != 0)
					current = reserved_size_ - 1;
				else
					current--;
				return copy;
			}

			void operator+=(int n)
			{
				if (current + n >= reserved_size_ - 1 && first != 0)
					current = current + n - reserved_size_;
				else
					current = current + n;

			}

			void operator-=(int n)
			{
				if (current - n < 0 && first != 0)
					current = reserved_size_ + (current - n);
				else
					current = current - n;

			}

			DequeIterator &operator+ (difference_type n)
			{
				// std::cout << "here23" << std::endl;
				// std::cout << "current:" << current << "n:" << n << std::endl;

				if (current + n > reserved_size_ - 1 && first != 0)
					current = current + n - reserved_size_;
				else
					current = current + n;
				// std::cout << "current:" << current << "n:" << n << std::endl;
				return *this;
			}

			DequeIterator &operator- (difference_type n)
			{
				if (current - n < 0 && first != 0)
					current = reserved_size_ + (current - n);
				else
					current = current - n;
				return *this;
			}

			reference operator*() const
			{
				return this->array[current];
			}

			reference operator[](int n)
			{
				n = n + first + current > reserved_size_ - 1 ? (first + n + current) - (reserved_size_) :  first + n + current;
				return (array[n]);
			}
			friend DequeIterator operator+(difference_type value, const DequeIterator &x)
			{
				DequeIterator tmp(x);
				// std::cout << "here2" << std::endl;
				return tmp += value;
			}

			template <class, bool>
			friend class DequeIterator;
			template <class, class>
			friend class deque;

			friend bool operator==(const DequeIterator &lhs, const DequeIterator &rhs)
			{
				// std::cout << lhs.current << "|" << rhs.current <<std::endl;
				return ((lhs.current == rhs.current));
			}
			friend bool operator!=(const DequeIterator &lhs, const DequeIterator &rhs)
			{
				return (!(lhs == rhs));
			}
			friend bool operator<(const DequeIterator &lhs, const DequeIterator &rhs)
			{
				if (lhs.array == rhs.array)
					return (lhs.current < rhs.current);
				else
				  return (&lhs.array[lhs.current] < &rhs.array[rhs.current]);
			}
			friend bool operator<=(const DequeIterator &lhs, const DequeIterator &rhs)
			{
				if (lhs.array == rhs.array)
					return (lhs.current <= rhs.current);
				else
					return (&lhs.array[lhs.current] <= &rhs.array[rhs.current]);
			}
			friend bool operator>(const DequeIterator &lhs, const DequeIterator &rhs)
			{
				return !(lhs <= rhs);
			}
			friend bool operator>=(const DequeIterator &lhs, const DequeIterator &rhs)
			{
				return !(lhs < rhs);
			}
			// template <class U>
			// friend bool operator!=(const DequeIterator<U>& lhs, const DequeIterator<U> &rhs);
			// template <class U>
			// friend bool operator==(const DequeIterator<U>& lhs, const DequeIterator<U>& rhs);
			template <class U>
			friend ptrdiff_t operator-(const DequeIterator<U>& lhs, const DequeIterator<U>& rhs);
			template <class U>
			friend ptrdiff_t operator+(const DequeIterator<U>& lhs, const DequeIterator<U>& rhs);
			template <class U>
			friend DequeIterator<U> &operator- (int n,DequeIterator<U>& lhs);
			template <class U>
			friend DequeIterator<U> &operator+ (int n, DequeIterator<U>& lhs);
			// template <class U>
			// friend bool operator<  (const DequeIterator<U>& lhs, const DequeIterator<U>& rhs);
			// template <class U>
			// friend bool operator<= (const DequeIterator<U>& lhs, const DequeIterator<U>& rhs);
			// template <class U>
			// friend bool operator>  (const DequeIterator<U>&lhs, const DequeIterator<U>& rhs);
			// template <class U>
			// friend bool operator>= (const DequeIterator<U>& lhs, const DequeIterator<U>& rhs);
	};

	// template <class U>
	// bool operator!=(const DequeIterator<U>& lhs, const DequeIterator<U>& rhs)
	// {
	// 	return (!(lhs.current == rhs.current && lhs.array == rhs.array));
	// }
	//
	//
	// template <class U>
	// bool operator==(const DequeIterator<U>& lhs, const DequeIterator<U>& rhs)
	// {
	// 	return ((lhs.current == rhs.current && lhs.array == rhs.array));
	// }

	template <class U>
	ptrdiff_t operator-(const DequeIterator<U>& lhs, const DequeIterator<U>& rhs)
	{
		return (&lhs.array[lhs.current] - &rhs.array[rhs.current]);
	}

	template <class U>
	ptrdiff_t operator+(const DequeIterator<U>& lhs, const DequeIterator<U>& rhs)
	{
		return (&lhs.array[lhs.current] + &rhs.array[rhs.current]);
	}

	template <class U>
	DequeIterator<U> &operator+ (int n, DequeIterator<U>& lhs)
	{
		if (lhs.current + n >= lhs.reserved_size_ - 1 && lhs.first != 0)
			lhs.current = lhs.current + n - lhs.reserved_size_;
		else
			lhs.current = lhs.current + n;
		return lhs;
	}

	template <class U>
	DequeIterator<U> &operator- (int n, DequeIterator<U>& lhs)
	{
		if (lhs.current - n < 0 && lhs.first != 0)
			lhs.current = lhs.reserved_size_ + (lhs.current - n);
		else
			lhs.current = lhs.current - n;
		return lhs;
	}
	//
	// template <class U>
	// bool operator<  (const DequeIterator<U>& lhs, const DequeIterator<U>& rhs)
	// {
	// 	if (lhs.array == rhs.array)
	// 		return (lhs.current < rhs.current);
	// 	else
	// 	  return (&lhs.array[lhs.current] < &rhs.array[rhs.current]);
	// }
	//
	// template <class U>
	// bool operator<= (const DequeIterator<U>& lhs, const DequeIterator<U>& rhs)
	// {
	// 	if (lhs.array == rhs.array)
	// 		return (lhs.current <= rhs.current);
	// 	else
	// 		return (&lhs.array[lhs.current] <= &rhs.array[rhs.current]);
	// }
	//
	// template <class U>
	// bool operator>  (const DequeIterator<U>&lhs, const DequeIterator<U>& rhs)
	// {
	// 	return !(lhs <= rhs);
	// }

	template <class U>
	bool operator>= (const DequeIterator<U>& lhs, const DequeIterator<U>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class Iterator>
	class ReverseDequeIterator
	{
	public:
		typedef Iterator 						iterator_type;
		typedef typename Iterator::value_type	value_type;
		typedef typename Iterator::pointer 		pointer;
		typedef typename Iterator::reference 	reference;
		typedef ptrdiff_t						difference_type;
		typedef ReverseDequeIterator			reverse_iterator;
	private:
		Iterator _base;
	public:
		ReverseDequeIterator():
		_base()
		{
		}
		ReverseDequeIterator(Iterator base):
			_base(base)
			{}

		template <class U>
		ReverseDequeIterator(const ReverseDequeIterator<U> &u):
			_base(u.base())
		{
		}
		ReverseDequeIterator(const ReverseDequeIterator<Iterator> & other):
			_base(other.base())
		{
		}
		ReverseDequeIterator<Iterator>& operator=(const ReverseDequeIterator<Iterator>& other)
		{
			_base = other.base();
			return *this;
		}

		~ReverseDequeIterator()
		{}

		Iterator base() const
		{
			return _base;
		}

		reference operator*() const
		{
			return (--Iterator(_base)).operator*();
		}

		pointer operator->() const {
		  return &(operator*());
		}

		reference operator[] (difference_type n) const
		{
			return base()[-n-1];
		}


		reverse_iterator operator+ (difference_type n) const
		{
			return 	reverse_iterator(_base.operator-(n));
		}


		ReverseDequeIterator &operator++()
		{
			--_base;
			return *this;
		}

		ReverseDequeIterator operator++(int)
		{
			reverse_iterator temp = *this;
		    ++(*this);
		    return temp;
		}

		ReverseDequeIterator &operator+=(difference_type n)
		{
			_base.operator-=(n);
			return *this;
		}

		reverse_iterator operator- (difference_type n) const
		{
			return 	reverse_iterator(_base.operator+(n));
		}

		reverse_iterator& operator--()
		{
			++_base;
			return *this;
		}

		reverse_iterator  operator--(int)
		{
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		}

		reverse_iterator& operator-= (difference_type n)
		{
			_base.operator+=(n);
			return *this;
		}

		friend reverse_iterator operator+(difference_type n, const reverse_iterator& rev_it)
		{
			return rev_it + n;
		}

		template <class>
		friend class ReverseDequeIterator;
		template <class, bool>
		friend class vectorIterator;
		template <class U, class V>
		friend  ptrdiff_t operator- (const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<V>& rhs);

		template <class it>
		friend bool operator== (const reverse_iterator& lhs, const ReverseDequeIterator<it>& rhs)
		{
			return lhs._base == rhs._base;
		}
		template <class it>
		friend bool operator!=(const ReverseDequeIterator &lhs, const ReverseDequeIterator<it> &rhs)
		{
			return lhs._base != rhs._base;
		}
		template <class it>
		friend bool operator<(const ReverseDequeIterator &lhs, const ReverseDequeIterator<it> &rhs)
		{
			return lhs._base > rhs._base;
		}
		template <class it>
		friend bool operator<=(const ReverseDequeIterator &lhs, const ReverseDequeIterator<it> &rhs)
		{
			return lhs._base >= rhs._base;
		}
		template <class it>
		friend bool operator>(const ReverseDequeIterator &lhs, const ReverseDequeIterator<it> &rhs)
		{
			return lhs._base < rhs._base;
		}
		template <class it>
		friend bool operator>=(const ReverseDequeIterator &lhs, const ReverseDequeIterator<it> &rhs)
		{
			return lhs._base <= rhs._base;
		}

		// ReverseDequeIterator():
		// 	iterator()
		// {}
		// ReverseDequeIterator(const DequeIterator<T> &it):
		// 	iterator(it)
		// {}
		// ReverseDequeIterator(const ReverseDequeIterator<T> &it):
		// 	iterator(it.iterator)
		// {}
		// ~ReverseDequeIterator()
		// {}
		//
		// ReverseDequeIterator &operator=(const ReverseDequeIterator &it)
		// {
		// 	iterator = it.iterator;
		// 	return *this;
		// }
		//
		// ReverseDequeIterator<T> &operator++()
		// {
		// 	--iterator;
		// 	return *this;
		// }
		//
		// ReverseDequeIterator<T> operator++(int)
		// {
		// 	ReverseDequeIterator<T> copy(*this);
		// 	--iterator;
		// 	return copy;
		// }
		//
		// 	ReverseDequeIterator<T> &operator+ (int n)
		// 	{
		// 		iterator = iterator - n;
		// 		return *this;
		// 	}
		// 	ReverseDequeIterator<T> &operator--()
		// 	{
		// 		++iterator;
		// 		return *this;
		// 	}
		//
		// 	ReverseDequeIterator<T> operator--(int)
		// 	{
		// 		ReverseDequeIterator<T> copy(*this);
		//
		// 		++iterator;
		// 		return copy;
		// 	}
		// 	ReverseDequeIterator<T> &operator- (int n)
		// 	{
		// 		iterator = iterator + n;
		// 		return *this;
		// 	}
		//
		// 	void operator+=(int n)
		// 	{
		// 		iterator -= n;
		// 	}
		//
		// 	void operator-=(int n)
		// 	{
		// 		iterator += n;
		// 	}
		//
		// 	T &operator*() const
		// 	{
		// 		return *iterator;
		// 	}
		//
		// 	T operator[](int n)
		// 	{
		// 		return (iterator[n]);
		// 	}
		//
		// 	template <class U>
		// 	friend bool operator!=(const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U> &rhs);
		// 	template <class U>
		// 	friend ptrdiff_t operator-(const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs);
		// 	template <class U>
		// 	friend bool operator==(const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs);
		// 	template <class U>
		// 	friend ptrdiff_t operator+(const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs);
		// 	template <class U>
		// 	friend ReverseDequeIterator<U> &operator+ (int n, ReverseDequeIterator<U>& lhs);
		// 	template <class U>
		// 	friend ReverseDequeIterator<U> &operator- (int n, ReverseDequeIterator<U>& lhs);
		// 	template <class U>
		// 	friend bool operator<  (const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs);
		// 	template <class U>
		// 	friend bool operator<= (const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs);
		// 	template <class U>
		// 	friend bool operator>  (const ReverseDequeIterator<U>&lhs, const ReverseDequeIterator<U>& rhs);
		// 	template <class U>
		// 	friend bool operator>= (const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs);
	};

	// template <class U>
	// bool operator!=(const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs)
	// {
	// 	return (lhs.iterator != rhs.iterator);
	// }
	//
	// template <class U>
	// ptrdiff_t operator-(const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs)
	// {
	// 	return (lhs.iterator - rhs.iterator);
	// }
	//
	//
	// template <class U>
	// bool operator==(const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs)
	// {
	// 	return ((lhs.iterator == rhs.iterator));
	// }
	//
	// template <class U>
	// ptrdiff_t operator+(const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs)
	// {
	// 	return (&lhs.iterator + &rhs.iterator);
	// }
	//
	// template <class U>
	// ReverseDequeIterator<U> &operator+ (int n, ReverseDequeIterator<U>& lhs)
	// {
	// 	-n + lhs.iterator;
	// 	return lhs;
	// }
	//
	// template <class U>
	// ReverseDequeIterator<U> &operator- (int n, ReverseDequeIterator<U>& lhs)
	// {
	// 	n + lhs.iterator;
	// 	return lhs;
	// }
	//
	// template <class U>
	// bool operator<  (const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs)
	// {
	// 	return (lhs.iterator > rhs.iterator);
	// }
	//
	// template <class U>
	// bool operator<= (const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs)
	// {
	// 	return (lhs.iterator >= rhs.iterator);
	// }
	//
	// template <class U>
	// bool operator>  (const ReverseDequeIterator<U>&lhs, const ReverseDequeIterator<U>& rhs)
	// {
	// 	return !(lhs <= rhs);
	// }
	//
	// template <class U>
	// bool operator>= (const ReverseDequeIterator<U>& lhs, const ReverseDequeIterator<U>& rhs)
	// {
	// 	return !(lhs < rhs);
	// }

	template <class T, class Alloc = std::allocator<T> >
	class deque
	{
		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::value_type&					reference;
			typedef const typename allocator_type::value_type&		const_reference;
			typedef typename allocator_type::value_type*			pointer;
			typedef const typename allocator_type::value_type*		const_pointer;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;
			typedef DequeIterator<T>								iterator;
			typedef DequeIterator<T, true>							const_iterator;
			typedef ReverseDequeIterator<iterator>					reverse_iterator;
			typedef ReverseDequeIterator<const_iterator>			const_reverse_iterator;

		private:
			T		*array;
			int		first;
			int		last;
			size_t	reserved_size_;
			size_t	size_;

			template <class InputIterator>
			size_t distance(InputIterator first, InputIterator last)
			{
				size_t dist;

				dist = 0;
				for (InputIterator it = first; it != last; ++it)
					dist++;
				return dist;
			}

			void modify_reserved_size(size_type reserved)
			{
				pointer new_array;
				int i = 0;
				if (reserved == 0)
					reserved = 512;
				reserved_size_ = reserved;
				new_array = new T[reserved];
				if (array != NULL)
				{
					for (iterator it = begin(); it != end(); ++it)
					{
						new_array[i] = *it;
						i++;
					}
				}
				first = 0;
				last = size_ - 1;
				if (array != NULL)
					delete array;
				array = new_array;
			}

			void create_new(void)
			{
				array = new T[reserved_size_];
				for (int i = 0; i < reserved_size_; i++)
					array[i] = value_type();
				first = 0;
				last = 0;
			}

		public:

			explicit deque (const allocator_type& alloc = allocator_type()):
				array(NULL), first(0), last(0), reserved_size_(0), size_(0)
			{}

			explicit deque(size_type n, const value_type& val = value_type(),
				                const allocator_type& alloc = allocator_type())
			{
				reserved_size_ = DEQUE_SIZE;
				while (n > reserved_size_ )
					reserved_size_ = reserved_size_ * 2;
				T *arr = new T[reserved_size_];
				for (int i = 0; i < n; i++)
					arr[i] = val;
				for (int i = n; i < reserved_size_; i++)
					arr[i] = value_type();
				array = arr;
				first = 0;
				last = n - 1;
				size_ = n;
			}

			deque(const deque& x):
				array(NULL), first(0), last(0), reserved_size_(DEQUE_SIZE), size_(0)
			{

				if (!x.empty())
				{
					for (const_iterator it = x.begin(); it != x.end(); ++it)
					{
						push_back(*it);
					}
				}
				else
					array = NULL;
			}

			template <class InputIterator>
			deque(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last):
							array(NULL), first(0), last(0), reserved_size_(DEQUE_SIZE), size_(0)
			{
				for (InputIterator it = first; it != last; ++it)
				{
					// std::cout << *it << std::endl;
					push_back(*it);
				}
			}

			~deque()
			{
				if (size_ != 0)
					delete array;
				array = NULL;
			}

			// deque(size_type n, const value_type& val = value_type())
			// {
			// 	reserved_size_ = DEQUE_SIZE;
			// 	while (n > reserved_size_ )
			// 		reserved_size_ = reserved_size_ * 2;
			// 	T *arr = new T[reserved_size_];
			// 	for (int i = 0; i < n; i++)
			// 		arr[i] = val;
			// 	for (int i = n; i < reserved_size_; i++)
			// 		arr[i] = value_type();
			// 	array = arr;
			// 	first = 0;
			// 	last = n - 1;
			// 	size_ = n;
			// }


			deque& operator=(const deque& x)
			{
				if (this == &x)
					return *this;
				if (array)
					delete array;
				first = x.first;
				last = x.last;
				reserved_size_ = x.reserved_size_;
				size_ = x.size_;
				array = new T[reserved_size_];
				if (!x.empty())
				{
					iterator _it = begin();
					for (const_iterator it = x.begin(); it != x.end(); ++it)
					{
						*_it = *it;
						++_it;
					}
				}
				else
					array = NULL;
				return *this;
			}

			// ITERATORS
			iterator begin()
			{
				return (iterator(array, first, first, last, size_, reserved_size_));
			}

			const_iterator begin() const
			{
				return (iterator(array, first, first, last + 1, size_, reserved_size_));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (reverse_iterator(end()));
			}

     		iterator end()
			{
				if (size_ == 0)
					return (begin());
				return (iterator(array, first, last + 1, last + 1, size_, reserved_size_));
			}
			const_iterator end() const
			{
				if (size_ == 0)
					return (begin());
				return (iterator(array, first, last + 1, last + 1, size_, reserved_size_));
			}

			reverse_iterator rend()
			{
				if (size_ == 0)
					return (rbegin());
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				if (size_ == 0)
					return (rbegin());
				return (reverse_iterator(begin()));
			}

			//CAPACITY
			size_type size() const
			{
				return (size_);
			}

			size_type max_size() const
			{
				return std::numeric_limits<difference_type>::max() / ((sizeof(T) / 2) < 1 ? 1 : (sizeof(T) / 2));
			}

			void resize (size_type n, value_type val = value_type())
			{
				int j;

				if (n > size_)
				{
					while (n > reserved_size_)
					{
						std::cout << n << std::endl;
						modify_reserved_size(reserved_size_);
					}
					for (size_t i = size_; i < n; i++)
					{
						j = i + first > reserved_size_ - 1 ? (first + i) - (reserved_size_) :  first + i;
						std::cout << j << std::endl;
						array[j] = val;
					}
				}
				last = n - 1;
				size_ = n;
			}

			bool empty() const
			{
				return (size_ == 0 ? 1 : 0);
			}

			// Element access
			reference operator[] (size_type n)
			{
				n = n + first > reserved_size_ - 1 ? (first + n) - (reserved_size_) :  first + n;
				return (array[n]);
			}

			const_reference operator[] (size_type n) const
			{
				n = n + first > reserved_size_ - 1 ? (first + n) - (reserved_size_) :  first + n;
				return (array[n]);
			}

			reference at(size_type n)
			{
				if (n > size_ - 1)
					throw std::out_of_range("deque");
				n = n + first > reserved_size_ - 1 ? (first + n) - (reserved_size_) :  first + n;
				return (array[n]);
			}
			const_reference at (size_type n) const
			{
				if (n > size_ - 1)
					throw std::out_of_range("deque");
				n = n + first > reserved_size_ - 1 ? (first + n) - (reserved_size_) :  first + n;
				return (array[n]);
			}

		   	reference front()
			{
				return (array[first]);
			}

			const_reference front() const
			{
				return (array[first]);
			}

			reference back()
			{
				return (array[last]);
			}

			const_reference back() const
			{
				return (array[last]);
			}

			//Modifiers



			void assign (size_type n, const value_type& val)
			{
				if (!array)
					create_new();
				while (n > reserved_size_)
					modify_reserved_size(reserved_size_ * 2);
				for (int i = 0; i < n; i++)
					array[i] = val;
				first = 0;
				last = n - 1;
				size_ = n;
			}

			template <class InputIterator>
			void assign (InputIterator first, typename enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type last)
			{
				int i = 0;
				size_t dist;

				dist = distance(first, last);
				if (!array)
					create_new();
				while (dist > reserved_size_)
					modify_reserved_size(reserved_size_ * 2);
				for (InputIterator it = first; it < last; it++)
				{
					array[i] = *it;
					i++;
				}
				this->first = 0;
				this->last = i - 1;
				size_ = i;
			}

			void push_back (const value_type& val)
			{

				if (!array)
				{
					create_new();
					array[last] = val;
				}
				else if (size_ != reserved_size_)
				{
					array[last + 1] = val;
					last++;
				}
				else
				{
					modify_reserved_size(reserved_size_ * 2);
					last++;
					array[last] = val;
				}
				size_++;
			}

			void push_front (const value_type& val)
			{
				if (!array)
				{
					create_new();
					array[first] = val;
				}
				else if (size_ != reserved_size_)
				{
					if (first == 0)
						first = reserved_size_ - 1;
					else
						first--;
					array[first] = val;
				}
				else
				{
					modify_reserved_size(reserved_size_ * 2);
					first = reserved_size_ - 1;
					array[first] = val;
				}
				size_++;
			}

			void pop_back()
			{
				size_--;
				last = last - 1;
			}
			void pop_front()
			{
				size_--;
				first++;
				if (first > reserved_size_ - 1)
					first = 0;
			}

			iterator insert (iterator position, const value_type& val)
			{
				iterator change;

				if (reserved_size_ < size_ + 1)
				{
					modify_reserved_size(reserved_size_ * 2);
				}
				if (!array && size_ == 0)
				{
					create_new();
					change = begin();
				}
				else if (position - begin() < end() - position)
				{

					iterator it = begin();
					if (first == 0)
						first = reserved_size_ - 1;
					else
						first--;
					change = begin();
					for (; it != position; ++it)
					{
						std::cout << *it << std::endl;
						*(change) = *(it);
						change++;
					}
				}
				else
				{
					iterator pos = position;
					pos--;
					last++;
					for (iterator it = end() - 2; it != (pos); it--)
					{
						change = it;
						change++;
						*(change) = *it;
					}
					change = position;
				}
				*change = val;
				size_++;
				return (change);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				for (int i = 0; i < n; i++)
				{
				    insert(position, val);
				}
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, typename enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type last)
			{
				for (InputIterator it = first; it != last; ++it)
				{
					std::cout << "here " << std::endl;
					insert(position, *it);
				}
			}

			iterator erase (iterator position)
			{
				iterator change;
				iterator pos;

				size_--;
				if (position - begin() < end() - position)
				{
					first++;
					pos = begin();
					for (iterator it = position; it != begin() - 1; --it)
					{
						pos++;
						change = it;
						change--;
						*it = *change;
					}
				}
				else
				{
					last--;
					pos = end();
					for (iterator it = position; it != end() + 1; ++it)
					{
						pos--;
						change = it;
						change++;
						*it = *change;
					}
					pos++;
				}

				return (pos);
			}

			iterator erase (iterator first, iterator last)
			{
				iterator pos;
				for (iterator it = first; it != last; ++it)
					pos = erase(it);
				return (pos);
			}
			void swap (deque& x)
			{
				deque buf;
				T *ar;

				ar = x.array;
				buf.first = x.first;
				buf.last = x.last;
				buf.reserved_size_ = x.reserved_size_;
				buf.size_ = x.size_;
				x.array = array;
				x.first = first;
				x.last = last;
				x.reserved_size_ = reserved_size_;
				x.size_ = size_;
				array = ar;
				first = buf.first;
				last = buf.last;
				reserved_size_ = buf.reserved_size_;
				size_ = buf.size_;
			}
			void clear()
			{
				erase(begin(), end());
			}
	};

	template <class U>
	bool operator== (const deque<U>& lhs, const deque<U>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			DequeIterator<U, true> it1 = lhs.begin();
			DequeIterator<U, true> it2 = rhs.begin();
			while (it1 != lhs.end() && it2 != rhs.end())
			{
				if (*it1 != *it2)
					return (0);
				++it1;
				++it2;
			}
			return (1);
		  }
		  return (0);
	}

	template <class U>
	bool operator!= (const deque<U>& lhs, const deque<U>& rhs)
	{
		return !(lhs == rhs);
	}
	template <class U>
	bool operator<  (const deque<U>& lhs, const deque<U>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			DequeIterator<U, true> it1 = lhs.begin();
			DequeIterator<U, true> it2 = rhs.begin();
			while (it1 != lhs.end() && it2 != rhs.end())
			{
				if (*it1 != *it2)
					return (*it1 - *it2 < 0 ? 1 : 0);
				++it1;
				++it2;
			}
			return (0);
		  }
		  return (lhs.size() - rhs.size());
	}

	template <class U>
	bool operator<= (const deque<U>& lhs, const deque<U>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			DequeIterator<U, true> it1 = lhs.begin();
			DequeIterator<U, true> it2 = rhs.begin();
			while (it1 != lhs.end() && it2 != rhs.end())
			{
				if (*it1 != *it2)
					return (*it1 - *it2 < 0 ? 1 : 0);
				++it1;
				++it2;
			}
			return (1);
		  }
		  return (lhs.size() - rhs.size());
	}
	template <class U>
	bool operator>  (const deque<U>& lhs, const deque<U>& rhs)
	{
		return !(lhs <= rhs);
	}
	template <class U>
	bool operator>= (const deque<U>& lhs, const deque<U>& rhs)
	{
		return !(lhs < rhs);
	}
	template <class T>
  	void swap (deque<T>& x, deque<T>& y)
	{
		deque<T> buf;
		buf = x;
		x = y;
		y = buf;
	}
}

#endif
