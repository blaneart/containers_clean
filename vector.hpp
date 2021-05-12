/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:00:51 by ablanar           #+#    #+#             */
/*   Updated: 2021/05/12 17:56:11 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
# include <sstream> // ostring
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

	template <class T, bool is_const = false>
	class vectorIterator
	{
	public:
		typedef typename choose<is_const, const T &, T &>::type 	reference;
		typedef typename choose<is_const, const T *, T *>::type 	pointer;
		typedef typename choose<is_const, const T, T>::type 		value_type;
		typedef vectorIterator<value_type, is_const>					iterator;
		typedef ptrdiff_t										difference_type;
	private:
			pointer _array;
	protected:
		vectorIterator(pointer ptr):
			_array(ptr)
		{}
	public:

		vectorIterator(void):
			_array(0)
		{}


		vectorIterator(iterator const &copy)
		{
			*this = copy;
		}

		~vectorIterator()
		{}

		operator vectorIterator<T, true>() const
 		{
			return vectorIterator<T,true>(_array);
		}
		iterator	&operator=(iterator const &copy)
		{
			if (this == &copy)
				return (*this);
			_array = copy._array;
			return *this;
		}

		reference operator*()
		{
			return *_array;
		}

		pointer operator->()
		{
			return _array;
		}

		reference operator[](int n)
		{
			return _array[n];
		}

		vectorIterator &operator++()
		{
			++_array;
			return *this;
		}

		vectorIterator operator++(int)
		{
			vectorIterator cpy(*this);
			++_array;
			return cpy;
		}

		vectorIterator &operator+=(difference_type n)
		{
			_array += n;
			return *this;
		}


		vectorIterator &operator--()
		{
			--_array;
			return *this;
		}

		vectorIterator operator--(int)
		{
			vectorIterator cpy(*this);
			--_array;
			return cpy;
		}

		vectorIterator &operator-=(difference_type n)
		{
			_array -= n;
			return *this;
		}




		vectorIterator operator+(difference_type n) const
		{
			vectorIterator cpy(*this);
			return 	cpy += n;
		}

		vectorIterator operator-(difference_type n) const
		{
			vectorIterator cpy(*this);

			return 	cpy -= n;
		}

		difference_type operator-(vectorIterator<T, true> const &x) const
		{
			return _array - x._array;
		}

		friend vectorIterator operator+(difference_type value, const vectorIterator &x)
		{
			vectorIterator tmp(x);
			return tmp += value;
		}

		// bool operator==(const vectorIterator &rhs)
		// {
		// 	return _array == rhs._array;
		// }
		// bool operator!=(const vectorIterator &rhs)
		// {
		// 	return _array != rhs._array;
		// }
		// bool operator<(const vectorIterator &rhs)
		// {
		// 	return _array < rhs._array;
		// }
		// bool operator<=(const vectorIterator &rhs)
		// {
		// 	return _array <= rhs._array;
		// }
		// bool operator>(const vectorIterator &rhs)
		// {
		// 	return _array > rhs._array;
		// }
		// bool operator>=(const vectorIterator &rhs)
		// {
		// 	return _array >= rhs._array;
		// }
		template <class, bool>
		friend class vectorIterator;
		template <class, class>
		friend class vector;


		friend bool operator==(const vectorIterator &lhs, const vectorIterator &rhs)
		{
			return lhs._array == rhs._array;
		}
		friend bool operator!=(const vectorIterator &lhs, const vectorIterator &rhs)
		{
			return lhs._array != rhs._array;
		}
		friend bool operator<(const vectorIterator &lhs, const vectorIterator &rhs)
		{
			return lhs._array < rhs._array;
		}
		friend bool operator<=(const vectorIterator &lhs, const vectorIterator &rhs)
		{
			return lhs._array <= rhs._array;
		}
		friend bool operator>(const vectorIterator &lhs, const vectorIterator &rhs)
		{
			return lhs._array > rhs._array;
		}
		friend bool operator>=(const vectorIterator &lhs, const vectorIterator &rhs)
		{
			return lhs._array >= rhs._array;
		}
	};

	template <class Iterator>
	class reverseVectorIterator
	{
	public:
		typedef Iterator 						iterator_type;
		typedef typename Iterator::value_type	value_type;
		typedef typename Iterator::pointer 		pointer;
		typedef typename Iterator::reference 	reference;
		typedef ptrdiff_t						difference_type;
		typedef reverseVectorIterator			reverse_iterator;
	private:
			Iterator _base;

	public:
		reverseVectorIterator():
		_base()
		{
		}
		reverseVectorIterator(Iterator base):
			_base(base)
			{}

		template <class U>
		reverseVectorIterator(const reverseVectorIterator<U> &u):
			_base(u.base())
		{
		}
		reverseVectorIterator(const reverseVectorIterator<Iterator> & other):
			_base(other.base())
		{
		}
		reverseVectorIterator<Iterator>& operator=(const reverseVectorIterator<Iterator>& other)
		{
			_base = other.base();
			return *this;
		}

		~reverseVectorIterator()
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


		reverseVectorIterator &operator++()
		{
			--_base;
			return *this;
		}

		reverseVectorIterator operator++(int)
		{
			reverse_iterator temp = *this;
		    ++(*this);
		    return temp;
		}

		reverseVectorIterator &operator+=(difference_type n)
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

		// friend reverseVectorIterator operator+(difference_type value, const reverseVectorIterator &x)
		// {
		// 	reverseVectorIterator tmp(x);
		// 	return tmp += value;
		// }

		// bool operator==(const reverseVectorIterator &rhs)
		// {
		// 	return _base == rhs._base;
		// }
		// bool operator!=(const reverseVectorIterator &rhs)
		// {
		// 	return _base != rhs._base;
		// }
		// bool operator<(const reverseVectorIterator &rhs)
		// {
		// 	return _base < rhs._base;
		// }
		// bool operator<=(const reverseVectorIterator &rhs)
		// {
		// 	return _base <= rhs._base;
		// }
		// bool operator>(const reverseVectorIterator &rhs)
		// {
		// 	return _base > rhs._base;
		// }
		// bool operator>=(const reverseVectorIterator &rhs)
		// {
		// 	return _base >= rhs._base;
		// }

		template <class>
		friend class reverseVectorIterator;
		template <class, bool>
		friend class vectorIterator;
		template <class U, class V>
		friend  ptrdiff_t operator- (const reverseVectorIterator<U>& lhs, const reverseVectorIterator<V>& rhs);

		template <class it>
		friend bool operator== (const reverse_iterator& lhs, const reverseVectorIterator<it>& rhs)
		{
			return lhs._base == rhs._base;
		}
		template <class it>
		friend bool operator!=(const reverseVectorIterator &lhs, const reverseVectorIterator<it> &rhs)
		{
			return lhs._base != rhs._base;
		}
		template <class it>
		friend bool operator<(const reverseVectorIterator &lhs, const reverseVectorIterator<it> &rhs)
		{
			return lhs._base > rhs._base;
		}
		template <class it>
		friend bool operator<=(const reverseVectorIterator &lhs, const reverseVectorIterator<it> &rhs)
		{
			return lhs._base >= rhs._base;
		}
		template <class it>
		friend bool operator>(const reverseVectorIterator &lhs, const reverseVectorIterator<it> &rhs)
		{
			return lhs._base < rhs._base;
		}
		template <class it>
		friend bool operator>=(const reverseVectorIterator &lhs, const reverseVectorIterator<it> &rhs)
		{
			return lhs._base <= rhs._base;
		}
	};

	template <class U, class V>
	ptrdiff_t operator-(
	    const reverseVectorIterator<U>& lhs,
	    const reverseVectorIterator<V>& rhs)
		{
			return rhs._base - lhs._base;
		}
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::value_type&			reference;
		typedef const typename allocator_type::value_type& 		const_reference;
		typedef typename allocator_type::value_type*			pointer;
		typedef const typename allocator_type::value_type*		const_pointer;
		typedef vectorIterator<T>								iterator;
		typedef vectorIterator<T, true>							const_iterator;
		typedef reverseVectorIterator<vectorIterator<T> >		reverse_iterator;
		typedef reverseVectorIterator<vectorIterator<T,true> >	const_reverse_iterator;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;

	private:
		pointer				_array;
		size_type			_size;
		size_type			_capacity;
		allocator_type		_alloc;
		void alloc_mem()
		{
			_capacity == (__APPLE__ ? _capacity : _size);
			pointer new_array = new T[_capacity + 1];
			for (size_type i = 0; i < _size; i++)
				new_array[i] = _array[i];
			for (size_t i = _size; i < _capacity; i++)
				new_array[i] = T();
			delete[] _array;
			_array = new_array;
		}

	public:
		explicit vector (const allocator_type& alloc = allocator_type()):
			_array(0), _size(0), _capacity(0), _alloc(alloc)
		{
		}
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) :
				 _array(0), _size(0), _capacity(0), _alloc(alloc)
		{
			insert(begin(), n, val);
		}

		template <class InputIterator>
		vector(typename enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first,  InputIterator last,
        	const allocator_type& alloc = allocator_type()):
				 _array(0), _size(0), _capacity(0), _alloc(alloc)
		{
			insert(begin(), first, last);
		}

		vector(const vector& x) :
			 _array(0), _size(0), _capacity(0), _alloc(x._alloc)
		{
			insert(begin(), x.begin(), x.end());
		}

		~vector()
		{
			clear();
			_array = NULL;
			_capacity = 0;
		}
		vector& operator=(const vector& x)
		{
			if (this == &x)
				return (*this);
			clear();
			if (_capacity >= x._size)
			{
				const_iterator first = x.begin();
				for (size_t i = 0; i < x._size; i++)
					_array[i] = (*first++);
				for (size_t i = x._size; i < _size; i++)
					_alloc.destroy(&_array[i]);
				_size = x._size;
			}
			else
			{
				delete _array;
				_array = NULL;
				_capacity = 0;
				insert(begin(), x.begin(), x.end());
			}
			return *this;
		}

		iterator	begin()
		{
			return iterator(&_array[0]);
		}

		const_iterator begin() const
		{
			return const_iterator(&_array[0]);
		}

		iterator	end()
		{
			return iterator(&_array[_size]);
		}

		const_iterator end() const
		{
			return const_iterator(&_array[_size]);
		}

		reverse_iterator	rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator	rend()
		{
			return reverse_iterator(begin());
		}

		const_iterator rend() const
		{
			return const_iterator(begin());
		}

		size_type size() const
		{
			return _size;
		}

		size_type max_size() const
		{
			return std::numeric_limits<difference_type>::max() / ((sizeof(T) / 2) < 1 ? 1 : (sizeof(T) / 2));
		}

		void resize (size_type n, value_type val = value_type())
		{
			if (n < _size)
			{
				while (n < _size)
					_alloc.destroy(&this->_array[--_size]);
			}
			else
			{
				size_type const &lambda = (__APPLE__ ? _capacity : _size);
				if (n <= _capacity)
					;
				else if (n <= lambda * 2)
					reserve(lambda * 2);
				else
					reserve(n);
				while (_size < n)
					_alloc.construct(&this->_array[_size++], val);
				if (n < _size)
					_size = n;
				else
				{
					for (size_type i = _size; i < n ;i++)
						push_back(val);
				}
			}
		}

		size_type capacity() const
		{
			return _capacity;
		}

		bool empty() const
		{
			return static_cast<bool>(!_size);
		}

		void reserve(size_t n)
		{
			if (n > max_size())
				throw std::out_of_range("Introduced number is greater than vector size");
			if (n <= _capacity)
				return ;
			if (n > _capacity)
			{
				_capacity = n;
				pointer new_array = new value_type[_capacity + 1];
				for (size_type i = 0; i < _size; i++)
					new_array[i] = _array[i];
				for(size_t i = _size; i < this->capacity(); i++)
					new_array[i] = value_type();
				delete[] _array;
				_array = new_array;
			}
		}

		reference operator[] (size_type n)
		{
			return _array[n];
		}

		const_reference operator[] (size_type n) const
		{
			return _array[n];
		}
		reference at(size_type n)
		{
			std::ostringstream ostr;
			ostr << "vector";
			if (n < _size)
				return (_array[n]);
			throw std::out_of_range(ostr.str());
		}

		const_reference at(size_type n) const
		{
			std::ostringstream ostr;
			ostr << "vector";
			if (n < _size)
				return (_array[n]);
			throw std::out_of_range(ostr.str());
		}

		reference front()
		{
			return _array[0];
		}

		const_reference front() const
		{
			return _array[0];
		}

		reference back()
		{
			return _array[_size - 1];
		}

		const_reference back() const
		{
			return _array[_size - 1];
		}

		template <class InputIterator>
		void assign(InputIterator first, typename enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type last)
		{
			size_type size;
			InputIterator buf(first);

			size = 0;
			for (; buf != last; ++buf)
				size++;

			if (size <= _capacity)
			{
				for (size_t i = 0; i < size; i++)
					_array[i] = (*first++);
				for (size_t i = size; i < _size; i++)
					_array[i] = value_type();
				_size = size;
			}
			else
			{
				clear();
				delete _array;
				_array = NULL;
				_capacity = 0;
				insert(begin(), first, last);
			}
		}

		void assign(size_type n, const value_type& val)
		{
			if (n <= _capacity)
			{
				for (size_t i = 0; i < n; i++)
					_array[i] = val;
				for (size_t i = n; i < _size; i++)
					_array[i] = value_type();
				_size = n;
			}
			else
			{
				clear();
				delete _array;
				_array = NULL;
				_capacity = 0;
				insert(begin(), n, val);
			}
		}
		void push_back(const value_type& val)
		{

			if (_size  == _capacity)
				resize(_size + 1, val);
			else
			{
				_array[_size] = val;
				_size++;
			}

		}

		void pop_back()
		{
			_alloc.destroy(&_array[--_size]);
		}

		iterator insert (iterator position, const value_type& val)
		{
			difference_type idx = position - begin();

			insert(position, 1, val);
			return (iterator(begin() + idx));
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			difference_type const	idx = position - this->begin();
			difference_type const	old_end_idx = this->end() - this->begin();
			iterator				old_end, ite;

			resize(_size + n);

			ite = end();
			position = begin() + idx;
			old_end = begin() + old_end_idx;
			while (old_end != position)
				*--ite = *--old_end;
			while (n-- > 0)
				*position++ = val;
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, typename enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type last)
		{
			difference_type const	idx = position - this->begin();
			difference_type const	old_end_idx = this->end() - this->begin();
			iterator				old_end, ite;
			size_type length;
			InputIterator buf(first);

			length = 0;

			for (; buf != last; ++buf)
				length++;
			resize(_size + length);

			ite = end();
			position = begin() + idx;
			old_end = begin() + old_end_idx;
			while (old_end != position)
				*--ite = *--old_end;
			while (first != last)
				*position++ = *first++;
		}

		iterator erase(iterator position)
		{
			return erase(position, position + 1);
		}

		iterator erase(iterator first, iterator last)
		{
			iterator tmp = first;
			iterator ite = end();
			size_type deleted;
			iterator buf(first);

			deleted = 0;
			for (; buf != last; ++buf)
				deleted++;

			while (last != ite)
			{
				*first = *last;
				++first;
				++last;
			}
			while (deleted-- > 0)
				_alloc.destroy(&_array[--_size]);
			return (tmp);
		}

		void swap(vector &x)
		{
			pointer tmp;
			size_type tmp_s;
			size_type tmp_c;

			tmp = _array;
			_array = x._array;
			x._array = tmp;

			tmp_s = _size;
			_size = x._size;
			x._size = tmp_s;

			tmp_c = _capacity;
			_capacity = x._capacity;
			x._capacity = tmp_c;
		}
		void clear()
		{
			while (_size > 0)
				_alloc.destroy(&_array[--_size]);
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
	bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return (equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool	operator< (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool	operator> (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}
}
#endif
