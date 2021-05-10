#ifndef QUEUE_HPP
#define QUEUE_HPP

// #include "../deque/Deque.hpp"

#include "list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class queue
	{
		private:
			Container container;
		public:
			typedef T value_type;
			typedef Container container_type;
			typedef int size_type;
			explicit queue (const container_type& ctnr = container_type()):
				container(ctnr)
			{
			}

			size_type size() const
			{
				return container.size();
			}

			bool empty() const
			{
				return container.empty();
			}
			value_type& front()
			{
				return container.front();
			}

			const value_type& front() const
			{
				return container.front();
			}

			value_type& back()
			{
				return container.back();
			}

			const value_type& back() const
			{
				return container.back();
			}

			void push (const value_type& val)
			{
				container.push_back(val);
			}

			void pop()
			{
				container.pop_front();
			}
	};
}

#endif
