#ifndef STACK_HPP
#define STACK_HPP

// #include "../deque/Deque.hpp"
#include <iostream>

#include "utility.hpp"
#include "deque.hpp"
 
namespace ft
{
	template <class T, class Container = deque<T> >
	class stack
	{
		private:
			Container container;
		public:
			typedef T				value_type;
			typedef Container		container_type;
			typedef size_t			size_type;

			explicit stack (const container_type& ctnr = container_type())
			: container(ctnr)
			{

			}
			bool empty() const
			{
				return (container.empty());
			}
			size_type size() const
			{
				return (container.size());
			}
			value_type& top()
			{
				return (container.back());
			}

			const value_type& top() const
			{
				return (container.back());
			}

			void push (const value_type& val)
			{
				container.push_back(val);
			}

			void pop()
			{
				container.pop_back();
			}
			template <class U, class V>
			friend bool operator== (const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator!= (const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator<  (const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator<= (const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator>  (const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator>= (const stack<U,V>& lhs, const stack<U,V>& rhs);
	};

	template <class U, class V>
  	bool operator== (const stack<U,V>& lhs, const stack<U,V>& rhs)
	{
		return (lhs.container == rhs.container);
	}
	template <class U, class V>
  	bool operator!= (const stack<U,V>& lhs, const stack<U,V>& rhs)
	{
		return (lhs.container != rhs.container);
	}
	template <class U, class V>
	bool operator<  (const stack<U,V>& lhs, const stack<U,V>& rhs)
	{
		return (lhs.container < rhs.container);
	}
	template <class U, class V>
	bool operator<= (const stack<U,V>& lhs, const stack<U,V>& rhs)
	{
		return (lhs.container <= rhs.container);
	}
	template <class U, class V>
	bool operator>  (const stack<U,V>& lhs, const stack<U,V>& rhs)
	{
		return (lhs.container > rhs.container);
	}
	template <class U, class V>
	bool operator>= (const stack<U,V>& lhs, const stack<U,V>& rhs)
	{
		return (lhs.container >= rhs.container);
	}
}

#endif
