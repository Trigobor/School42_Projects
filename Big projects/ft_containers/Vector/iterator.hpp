#pragma once

#include <memory>
#include <iostream>
#include <string>
//#include "const_iterator.hpp"

namespace ft
{
	template <typename T>
	class _const_iterator;
	template <typename T>
	class _reverse_iterator;
	template <typename T>
	class _reverse_const_iterator;
	// iterator
	template <typename T>
	class _iterator
	{
		public:
			typedef std::random_access_iterator_tag				iterator_category;
			typedef long int									difference_type;
			typedef T											value_type;
			typedef T&											reference;	
			typedef T*											pointer;
		protected:
			T* content;

			void yaywalking(T*& content, int step, int direction)
			{
				if (step < 0)
				{
					step *= -1;
					direction *= -1;
				}
				while(step--)
					content += direction;
			}
		public:

			_iterator() : content() {};

			_iterator(T* content) : content(content) {};

			_iterator(const _iterator &sample)
			{this->content = sample.base();};

			_iterator(const _const_iterator<T> &sample)
			{this->content = sample.base();};

//			_iterator(const _reverse_iterator<T> &sample)
//			{this->content = sample.base();};

//			_iterator(const _reverse_const_iterator<T> &sample)
//			{this->content = sample.base();};

			template <class some>
				_iterator(const _iterator<some> &sample) : content(sample.base()) {};

			template <class some>
				_iterator &operator=(const _iterator<some> &sample)
					{content = sample.base(); return *this;};

/*			_iterator &operator=(const _iterator &sample)
			{this->content = sample.base(); return *this;};

			_iterator &operator=(const _const_iterator<T> &sample)
			{this->content = sample.base(); return *this;};

			_iterator &operator=(const _reverse_iterator<T> &sample)
			{this->content = sample.base(); return *this;};

			_iterator &operator=(const _reverse_const_iterator<T> &sample)
			{this->content = sample.base(); return *this;};
*/
			~_iterator() {};
		
			T* base() const
			{return this->content;};

			reference operator*() const
			{return *(content);};

			pointer operator->() const
			{return (content);};

			_iterator &operator+=(difference_type i)
			{yaywalking(this->content, i, 1);return *this;};

			_iterator &operator-=(difference_type i)
			{yaywalking(this->content, i, -1);return *this;};

			_iterator operator++(int)
			{_iterator ret(*this);++content;return (ret);};//(*this) += sizeof(T);

			_iterator operator--(int)
			{_iterator ret(*this);--content;return (ret);};

			_iterator &operator++()
			{content++; return (*this);};

			_iterator &operator--()
			{content--; return (*this);};

			_iterator operator+(difference_type step) const
			{
				_iterator temp(*this);
				for(difference_type i = 0; i < step; i++)
					temp++;
				return (temp);
			};

			_iterator operator-(difference_type step) const
			{
				_iterator temp(*this);
				for(difference_type i = 0; i < step; i++)
					temp--;
				return (temp);
			};

			reference operator[](difference_type index)
			{pointer tmp = this->content; yaywalking(tmp, index, 1); return (*tmp);};

			difference_type operator-(_iterator subtrahend)
			{return (this->content - subtrahend.content);};
/*
			bool operator!=(const _iterator &sample)
			{return (this->content != sample->content ? true : false);};

			bool operator==(const _iterator &sample)
			{return (this->content == sample->content ? true : false);};

			bool operator<(const _iterator &sample)
			{return (this->content < sample->content ? true : false);};

			bool operator>(const _iterator &sample)
			{return (this->content > sample->content ? true : false);};

			bool operator<=(const _iterator &sample)
			{return (this->content <= sample->content ? true : false);};

			bool operator>=(const _iterator &sample)
			{return (this->content >= sample->content ? true : false);};
*/	};

//	template <class f_Iterator, class s_Iterator>
//	long int operator-(_iterator<f_Iterator>& a, _iterator<s_Iterator>& b)
//	{return (a.content - b.content);};

	template <class f_Iterator, class s_Iterator>
	bool operator!=(const _iterator<f_Iterator>& a, const _iterator<s_Iterator>& b)
	{return (a.base() != b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator!=(const _iterator<f_Iterator>& a, const _const_iterator<s_Iterator>& b)
	{return (a.base() != b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator==(const _iterator<f_Iterator>& a, const _iterator<s_Iterator>& b)
	{return (a.base() == b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator==(const _iterator<f_Iterator>& a, const _const_iterator<s_Iterator>& b)
	{return (a.base() == b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<(const _iterator<f_Iterator>& a, const _iterator<s_Iterator>& b)
	{return (a.base() < b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<(const _iterator<f_Iterator>& a, const _const_iterator<s_Iterator>& b)
	{return (a.base() < b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<=(const _iterator<f_Iterator>& a, const _iterator<s_Iterator>& b)
	{return (a.base() <= b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<=(const _iterator<f_Iterator>& a, const _const_iterator<s_Iterator>& b)
	{return (a.base() <= b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>(const _iterator<f_Iterator>& a, const _iterator<s_Iterator>& b)
	{return (a.base() > b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>(const _iterator<f_Iterator>& a, const _const_iterator<s_Iterator>& b)
	{return (a.base() > b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>=(const _iterator<f_Iterator>& a, const _iterator<s_Iterator>& b)
	{return (a.base() >= b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>=(const _iterator<f_Iterator>& a, const _const_iterator<s_Iterator>& b)
	{return (a.base() >= b.base());};

	// reverse iterator
	template <typename T>
	class _reverse_iterator
	{
		public:
			typedef std::random_access_iterator_tag				iterator_category;
			typedef long int									difference_type;
			typedef T											value_type;
			typedef T&											reference;	
			typedef T*											pointer;
		protected:
			T* content;

			void yaywalking(T*& content, int step, int direction)
			{
				if (step < 0)
				{
					step *= -1;
					direction *= -1;
				}
				while(step--)
					content += direction;
			}
		public:

			_reverse_iterator() : content() {};

			_reverse_iterator(T* content) : content(content) {};

			_reverse_iterator(const _reverse_iterator &sample)
			{this->content = sample.base();};

//			_reverse_iterator(const _iterator<T> &sample)
//			{this->content = sample.base();};

//			_reverse_iterator(const _const_iterator<T> &sample)
//			{this->content = sample.base();};

			_reverse_iterator(const _reverse_const_iterator<T> &sample)
			{this->content = sample.base();};

			template <class some>
				_reverse_iterator(const _reverse_iterator<some> &sample) : content(sample.base()) {};

			template <class some>
				_reverse_iterator &operator=(const _reverse_iterator<some> &sample)
					{content = sample.base(); return *this;};

/*			_reverse_iterator &operator=(const _iterator<T> &sample)
			{this->content = sample.base(); return *this;};

			_reverse_iterator &operator=(const _const_iterator<T> &sample)
			{this->content = sample.base(); return *this;};

			_reverse_iterator &operator=(const _reverse_iterator &sample)
			{this->content = sample.base(); return *this;};

			_reverse_iterator &operator=(const _reverse_const_iterator<T> &sample)
			{this->content = sample.base(); return *this;};
*/
			~_reverse_iterator() {};
		
			T* base() const
			{return this->content;};

			reference operator*() const
			{return *(content - 1);};

			pointer operator->() const
			{return (content - 1);};

			_reverse_iterator &operator+=(difference_type i)
			{yaywalking(this->content, i, -1);return *this;};

			_reverse_iterator &operator-=(difference_type i)
			{yaywalking(this->content, i, 1);return *this;};

			_reverse_iterator operator++(int)
			{_reverse_iterator ret(*this);--content;return (ret);};//(*this) += sizeof(T);

			_reverse_iterator operator--(int)
			{_reverse_iterator ret(*this);++content;return (ret);};

			_reverse_iterator &operator++()
			{content--; return (*this);};

			_reverse_iterator &operator--()
			{content++; return (*this);};

			_reverse_iterator operator+(difference_type step) const
			{
				_reverse_iterator temp(*this);
				for(difference_type i = 0; i < step; i++)
					temp--;
				return (temp);
			};

			_reverse_iterator operator-(difference_type step) const
			{
				_reverse_iterator temp(*this);
				for(difference_type i = 0; i < step; i++)
					temp++;
				return (temp);
			};

			reference operator[](difference_type index)
			{pointer tmp = this->content; yaywalking(tmp, index + 1, -1); return (*tmp);};
/*
			bool operator!=(const _reverse_iterator &sample)
			{return (this->content != sample->content ? true : false);};

			bool operator==(const _reverse_iterator &sample)
			{return (this->content == sample->content ? true : false);};

			bool operator<(const _reverse_iterator &sample)
			{return (this->content < sample->content ? true : false);};

			bool operator>(const _reverse_iterator &sample)
			{return (this->content > sample->content ? true : false);};

			bool operator<=(const _reverse_iterator &sample)
			{return (this->content <= sample->content ? true : false);};

			bool operator>=(const _reverse_iterator &sample)
			{return (this->content >= sample->content ? true : false);};
*/	};

	template <class f_Iterator, class s_Iterator>
	bool operator!=(const _reverse_iterator<f_Iterator>& a, const _reverse_iterator<s_Iterator>& b)
	{return (a.base() != b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator!=(const _reverse_iterator<f_Iterator>& a, const _reverse_const_iterator<s_Iterator>& b)
	{return (a.base() != b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator==(const _reverse_iterator<f_Iterator>& a, const _reverse_iterator<s_Iterator>& b)
	{return (a.base() == b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator==(const _reverse_iterator<f_Iterator>& a, const _reverse_const_iterator<s_Iterator>& b)
	{return (a.base() == b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<(const _reverse_iterator<f_Iterator>& a, const _reverse_iterator<s_Iterator>& b)
	{return (a.base() < b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<(const _reverse_iterator<f_Iterator>& a, const _reverse_const_iterator<s_Iterator>& b)
	{return (a.base() < b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<=(const _reverse_iterator<f_Iterator>& a, const _reverse_iterator<s_Iterator>& b)
	{return (a.base() <= b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<=(const _reverse_iterator<f_Iterator>& a, const _reverse_const_iterator<s_Iterator>& b)
	{return (a.base() <= b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>(const _reverse_iterator<f_Iterator>& a, const _reverse_iterator<s_Iterator>& b)
	{return (a.base() > b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>(const _reverse_iterator<f_Iterator>& a, const _reverse_const_iterator<s_Iterator>& b)
	{return (a.base() > b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>=(const _reverse_iterator<f_Iterator>& a, const _reverse_iterator<s_Iterator>& b)
	{return (a.base() >= b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>=(const _reverse_iterator<f_Iterator>& a, const _reverse_const_iterator<s_Iterator>& b)
	{return (a.base() >= b.base());};

	// const iterator
	template <typename T>
	class _const_iterator
	{
		public:
			typedef std::random_access_iterator_tag				iterator_category;
			typedef long int									difference_type;
			typedef T											value_type;
			typedef T&											reference;	
			typedef T*											pointer;
			typedef const T&									const_reference;	
			typedef const T*									const_pointer;
		protected:
			T* content;

			void yaywalking(T*& content, int step, int direction)
			{
				if (step < 0)
				{
					step *= -1;
					direction *= -1;
				}
				while(step--)
					content += direction;
			}
		public:

			_const_iterator() : content() {};

			_const_iterator(T* content) : content(content) {};

			_const_iterator(const _const_iterator &sample)
			{this->content = sample.base();};

//			_const_iterator(const _reverse_const_iterator<T> &sample)
//			{this->content = sample.base();};

			_const_iterator(const _iterator<T> &sample)
			{this->content = sample.base();};

//			_const_iterator(const _reverse_iterator<T> &sample)
//			{this->content = sample.base();};

			template <class some>
				_const_iterator(const _const_iterator<some> &sample) : content(sample.base()) {};

			template <class some>
				_const_iterator &operator=(const _const_iterator<some> &sample)
					{content = sample.base(); return *this;};


/*			_const_iterator &operator=(const _iterator<T> &sample)
			{this->content = sample.base(); return *this;};

			_const_iterator &operator=(const _const_iterator &sample)
			{this->content = sample.base(); return *this;};

			_const_iterator &operator=(const _reverse_iterator<T> &sample)
			{this->content = sample.base(); return *this;};

			_const_iterator &operator=(const _reverse_const_iterator<T> &sample)
			{this->content = sample.base(); return *this;};
*/
			~_const_iterator() {};
		
			T* base() const
			{return this->content;};

			const_reference operator*() const
			{return *(content);};

			pointer operator->() const
			{return (content);};

			_const_iterator &operator+=(difference_type i)
			{yaywalking(this->content, i, 1);return *this;};

			_const_iterator &operator-=(difference_type i)
			{yaywalking(this->content, i, -1);return *this;};

			_const_iterator operator++(int)
			{_const_iterator ret(*this);++content;return (ret);};//(*this) += sizeof(T);

			_const_iterator operator--(int)
			{_const_iterator ret(*this);--content;return (ret);};

			_const_iterator &operator++()
			{content++; return (*this);};

			_const_iterator &operator--()
			{content--; return (*this);};

			_const_iterator operator+(difference_type step) const
			{
				_const_iterator temp(*this);
				for(difference_type i = 0; i < step; i++)
					temp++;
				return (temp);
			};

			_const_iterator operator-(difference_type step) const
			{
				_const_iterator temp(*this);
				for(difference_type i = 0; i < step; i++)
					temp--;
				return (temp);
			};

			const_reference operator[](difference_type index)
			{pointer tmp = this->content; yaywalking(tmp, index, 1); return *tmp;};
/*
			bool operator!=(const _const_iterator &sample)
			{return (this->content != sample->content ? true : false);};

			bool operator==(const _const_iterator &sample)
			{return (this->content == sample->content ? true : false);};

			bool operator<(const _const_iterator &sample)
			{return (this->content < sample->content ? true : false);};

			bool operator>(const _const_iterator &sample)
			{return (this->content > sample->content ? true : false);};

			bool operator<=(const _const_iterator &sample)
			{return (this->content <= sample->content ? true : false);};

			bool operator>=(const _const_iterator &sample)
			{return (this->content >= sample->content ? true : false);};
*/	};

	template <class f_Iterator, class s_Iterator>
	bool operator!=(const _const_iterator<f_Iterator>& a, const _const_iterator<s_Iterator>& b)
	{return (a.base() != b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator!=(const _const_iterator<f_Iterator>& a, const _iterator<s_Iterator>& b)
	{return (a.base() != b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator==(const _const_iterator<f_Iterator>& a, const _const_iterator<s_Iterator>& b)
	{return (a.base() == b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator==(const _const_iterator<f_Iterator>& a, const _iterator<s_Iterator>& b)
	{return (a.base() == b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<(const _const_iterator<f_Iterator>& a, const _const_iterator<s_Iterator>& b)
	{return (a.base() < b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<(const _const_iterator<f_Iterator>& a, const _iterator<s_Iterator>& b)
	{return (a.base() < b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<=(const _const_iterator<f_Iterator>& a, const _const_iterator<s_Iterator>& b)
	{return (a.base() <= b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<=(const _const_iterator<f_Iterator>& a, const _iterator<s_Iterator>& b)
	{return (a.base() <= b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>(const _const_iterator<f_Iterator>& a, const _const_iterator<s_Iterator>& b)
	{return (a.base() > b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>(const _const_iterator<f_Iterator>& a, const _iterator<s_Iterator>& b)
	{return (a.base() > b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>=(const _const_iterator<f_Iterator>& a, const _const_iterator<s_Iterator>& b)
	{return (a.base() >= b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>=(const _const_iterator<f_Iterator>& a, const _iterator<s_Iterator>& b)
	{return (a.base() >= b.base());};

	// const reverse iterator
	template <typename T>
	class _reverse_const_iterator
	{
		public:
			typedef std::random_access_iterator_tag				iterator_category;
			typedef long int									difference_type;
			typedef T											value_type;
			typedef T&											reference;	
			typedef T*											pointer;
			typedef const T&									const_reference;	
			typedef const T*									const_pointer;
		protected:
			T* content;

			void yaywalking(T*& content, int step, int direction)
			{
				if (step < 0)
				{
					step *= -1;
					direction *= -1;
				}
				while(step--)
					content += direction;
			}
		public:

			_reverse_const_iterator() : content() {};

			_reverse_const_iterator(T* content) : content(content) {};

			_reverse_const_iterator(const _reverse_const_iterator &sample)
			{this->content = sample.base();};

//			_reverse_const_iterator(const _iterator<T> &sample)
//			{this->content = sample.base();};

			_reverse_const_iterator(const _reverse_iterator<T> &sample)
			{this->content = sample.base();};

//			_reverse_const_iterator(const _const_iterator<T> &sample)
//			{this->content = sample.base();};

			template <class some>
				_reverse_const_iterator(const _reverse_const_iterator<some> &sample) : content(sample.base()) {};

			template <class some>
				_reverse_const_iterator &operator=(const _reverse_const_iterator<some> &sample)
					{content = sample.base(); return *this;};

/*			_reverse_const_iterator &operator=(const _iterator<T> &sample)
			{this->content = sample.base(); return *this;};

			_reverse_const_iterator &operator=(const _const_iterator<T> &sample)
			{this->content = sample.base(); return *this;};

			_reverse_const_iterator &operator=(const _reverse_iterator<T> &sample)
			{this->content = sample.base(); return *this;};

			_reverse_const_iterator &operator=(const _reverse_const_iterator &sample)
			{this->content = sample.base(); return *this;};
*/
			~_reverse_const_iterator() {};
		
			T* base() const
			{return this->content;};

			const_reference operator*() const
			{return *(content - 1);};

			pointer operator->() const
			{return (content - 1);};

			_reverse_const_iterator &operator+=(difference_type i)
			{yaywalking(this->content, i, -1);return *this;};

			_reverse_const_iterator &operator-=(difference_type i)
			{yaywalking(this->content, i, 1);return *this;};

			_reverse_const_iterator operator++(int)
			{_reverse_const_iterator ret(*this);--content;return (ret);};//(*this) += sizeof(T);

			_reverse_const_iterator operator--(int)
			{_reverse_const_iterator ret(*this);++content;return (ret);};

			_reverse_const_iterator &operator++()
			{content--; return (*this);};

			_reverse_const_iterator &operator--()
			{content++; return (*this);};

			_reverse_const_iterator operator+(difference_type step) const
			{
				_reverse_const_iterator temp(*this);
				for(difference_type i = 0; i < step; i++)
					temp++;
				return (temp);
			};

			_reverse_const_iterator operator-(difference_type step) const
			{
				_reverse_const_iterator temp(*this);
				for(difference_type i = 0; i < step; i++)
					temp--;
				return (temp);
			};

			const_reference operator[](difference_type index)
			{pointer tmp = this->content; yaywalking(tmp, index + 1, -1); return (*tmp);};
	/*
				bool operator!=(const _reverse_const_iterator &sample)
				{return (this->content != sample->content ? true : false);};

				bool operator==(const _reverse_const_iterator &sample)
				{return (this->content == sample->content ? true : false);};

				bool operator<(const _reverse_const_iterator &sample)
				{return (this->content < sample->content ? true : false);};

				bool operator>(const _reverse_const_iterator &sample)
				{return (this->content > sample->content ? true : false);};

				bool operator<=(const _reverse_const_iterator &sample)
				{return (this->content <= sample->content ? true : false);};

				bool operator>=(const _reverse_const_iterator &sample)
				{return (this->content >= sample->content ? true : false);};
	*/	};

	template <class f_Iterator, class s_Iterator>
	bool operator!=(const _reverse_const_iterator<f_Iterator>& a, const _reverse_const_iterator<s_Iterator>& b)
	{return (a.base() != b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator!=(const _reverse_const_iterator<f_Iterator>& a, const _reverse_iterator<s_Iterator>& b)
	{return (a.base() != b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator==(const _reverse_const_iterator<f_Iterator>& a, const _reverse_const_iterator<s_Iterator>& b)
	{return (a.base() == b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator==(const _reverse_const_iterator<f_Iterator>& a, const _reverse_iterator<s_Iterator>& b)
	{return (a.base() == b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<(const _reverse_const_iterator<f_Iterator>& a, const _reverse_const_iterator<s_Iterator>& b)
	{return (a.base() < b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<(const _reverse_const_iterator<f_Iterator>& a, const _reverse_iterator<s_Iterator>& b)
	{return (a.base() < b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<=(const _reverse_const_iterator<f_Iterator>& a, const _reverse_const_iterator<s_Iterator>& b)
	{return (a.base() <= b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator<=(const _reverse_const_iterator<f_Iterator>& a, const _reverse_iterator<s_Iterator>& b)
	{return (a.base() <= b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>(const _reverse_const_iterator<f_Iterator>& a, const _reverse_const_iterator<s_Iterator>& b)
	{return (a.base() > b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>(const _reverse_const_iterator<f_Iterator>& a, const _reverse_iterator<s_Iterator>& b)
	{return (a.base() > b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>=(const _reverse_const_iterator<f_Iterator>& a, const _reverse_const_iterator<s_Iterator>& b)
	{return (a.base() >= b.base());};

	template <class f_Iterator, class s_Iterator>
	bool operator>=(const _reverse_const_iterator<f_Iterator>& a, const _reverse_iterator<s_Iterator>& b)
	{return (a.base() >= b.base());};
}
