#pragma once

#include <memory>
#include <iostream>
#include <string>
#include "../Vector/Vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T> > // поменять std на ft когда будет готов вектор
	class stack
	{
		public:
			typedef Container	container_type;
			typedef	T			value_type;
			typedef size_t		size_type;
		private:
			container_type		contain;
		public:
			explicit stack(const container_type &sample = container_type())
			{this->contain = sample;};
			~stack()
			{};
			bool empty() const
			{return (this->contain.empty());};
			size_t size() const
			{return (this->contain.size());};
			T& top()
			{return (this->contain.back());};
			const T& top() const
			{return (this->contain.back());};
			void push(const T& item)
			{this->contain.push_back(item);};
	
			friend bool operator == (const stack<T,Container>& l, const stack<T,Container>& r)
			{return (l.contain == r.contain);};
			friend bool operator != (const stack<T,Container>& l, const stack<T,Container>& r)
			{return (l.contain != r.contain);};
			friend bool operator <= (const stack<T,Container>& l, const stack<T,Container>& r)
			{return (l.contain <= r.contain);};
			friend bool operator >= (const stack<T,Container>& l, const stack<T,Container>& r)
			{return (l.contain >= r.contain);};
			friend bool operator < (const stack<T,Container>& l, const stack<T,Container>& r)
			{return (l.contain < r.contain);};
			friend bool operator > (const stack<T,Container>& l, const stack<T,Container>& r)
			{return (l.contain > r.contain);};
			//попробуй сделать реализацию с выносом дружественных функций за пределы класса
	};
	/*
	template <class T, class Container>
	bool operator == (const stack<T,Container>& l, const stack<T,Container>& r)
	{return (l.contain == r.contain);};

	template <class T, class Container>
	bool operator != (const stack<T,Container>& l, const stack<T,Container>& r)
	{return (l.contain != r.contain);};

	template <class T, class Container>
	bool operator <= (const stack<T,Container>& l, const stack<T,Container>& r)
	{return (l.contain >= r.contain);};

	template <class T, class Container>
	bool operator >= (const stack<T,Container>& l, const stack<T,Container>& r)
	{return (l.contain >= r.contain);};

	template <class T, class Container>
	bool operator < (const stack<T,Container>& l, const stack<T,Container>& r)
	{return (l.contain < r.contain);};

	template <class T, class Container>
	bool operator > (const stack<T,Container>& l, const stack<T,Container>& r)
	{return (l.contain > r.contain);};
*/
}
