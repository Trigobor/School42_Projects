#pragma once

#include "iterator.hpp"
//#include "const_iterator.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		public:
		//эти тайпдефы нужны(нет), нужны только чтобы прототипы функций выглядели аналогично библиотечному вектору
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef T&											reference;
			typedef const T&									const_reference;
			typedef T*											pointer;
			typedef const T*									const_pointer;
			typedef _iterator<T>								iterator;				//доработай
			typedef _const_iterator<T>							const_iterator;			//
			typedef _reverse_iterator<T>						reverse_iterator;		//
			typedef _reverse_const_iterator<T>					const_reverse_iterator;	//доработал
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;
		private:
			T*				arr;
			size_type		size_arr;
			size_type		capasity;
			allocator_type	t_memory;
			//...
			//Exeptions
//			class length_error : public std::exception
//			{
//				public:
//					virtual const char* what() const throw()
//					{return ("libc++abi.dylib: terminating with uncaught exception of type std::length_error: allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size\nzsh: abort      ./a.out");}
//			};
			void primitive_resize(size_type n, bool flag, bool cap)
			{
				allocator_type tmp;
				T* contain = tmp.allocate(n);
				for (size_type i = 0; i < n && i != this->size_arr; i++)
					tmp.construct(&contain[i], this->arr[i]);
				this->~vector();
				this->t_memory = tmp;
				this->arr = contain;
				if (flag)
					this->size_arr = n;
				if (cap)
					this->capasity = n;
//				std::cout << "\nsize is " << this->size_arr;
//				std::cout << "\nsize is " << this->capasity << "\n";
//				for (size_type i = 0; i < this->size_arr; i++)
//				
			};
		public:
		//Member functions
			explicit vector(const allocator_type& alloc = allocator_type() )
			{
				this->t_memory = alloc;
				this->arr = this->t_memory.allocate(0);
				this->capasity = 0;
				this->size_arr = 0;
			};
			explicit vector(size_type count, const T& value = T(), const allocator_type& alloc = allocator_type())
			{
				this->arr = alloc.allocate(count);
				this->t_memory = alloc;
				this->capasity = count;
				this->size_arr = value;
				for(size_type i = 0; i < count; i++)
					this->t_memory.construct(&(this->arr[i]), value);
			};
			template< class InputIterator >
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() ) //не понимаю что это до конца
			{
				this->t_memory = alloc;
				this->size_arr = 0;
				for (InputIterator i = first; i != last; i++)
					this->size_arr += 1;
				this->capasity = this->size_arr;
				for (int i = 0; first != last; first++, i++)
					this->arr[i] = *first;
			};
			vector(const vector& sample)
			{
				this->t_memory = sample.t_memory;
				this->capasity = sample.capasity;
				this->size_arr = sample.size_arr;
				this->arr = this->t_memory.allocate(sample.capasity);
				for(size_type i = 0; i < sample.size_arr; i++)
					this->t_memory.construct(&(this->arr[i]), sample.arr[i]);
			};
			~vector()
			{
				for (size_type i = 0; i < this->size_arr; i++)
					this->t_memory.destroy(&(this->arr[i]));
				this->t_memory.deallocate(this->arr, this->capasity); 
			};
			vector &operator= (const vector &sample)
			{
				this->t_memory = sample.t_memory;
				this->capasity = sample.capasity;
				this->size_arr = sample.size_arr;
				this->arr = this->t_memory.allocate(sample.capasity);
				for(size_type i = 0; i < sample.size_arr; i++)
					this->t_memory.construct(&(this->arr[i]), sample.arr[i]);
				return (*this);
			};
		//Iterators
			iterator begin()
			{return (iterator(arr));};
			iterator end()
			{return (iterator(arr + size_arr));};
			reverse_iterator rbegin()
			{return (reverse_iterator(arr + size_arr));};
			reverse_iterator rend()
			{return (reverse_iterator(arr));};
			const_iterator begin() const
			{return (const_iterator(arr));};
			const_iterator end() const
			{return (const_iterator(arr + size_arr));};
			const_reverse_iterator rbegin() const
			{return (const_reverse_iterator(arr + size_arr));};
			const_reverse_iterator rend() const
			{return (const_reverse_iterator(arr));};
		//Capasity
			size_type capacity() const
			{return this->capasity;};
			bool empty() const
			{return (this->size_arr == 0 ? true : false);};
			void reserve(size_type n)
			{
				try
				{
					if (n > max_size())
						throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
					if (n > this->capasity)
						this->primitive_resize(n, 0, 1);
				}
				catch(const std::exception& e)
				{
					throw;
//					std::cerr << e.what() << '\n';
//					exit(0);
				}
				
			}
			size_type size() const
			{return this->size_arr;};
			size_type max_size() const
			{return t_memory.max_size();};
//			{return (static_cast<size_type>(std::numeric_limits<T>::max()));};
			void resize(size_type n, const T& value = T())
			{
				if (n <= this->capasity && n <= this->size_arr)
				{
					size_type i = size_arr;
					size_arr = n;
					for (;n < i; n++)
						this->t_memory.destroy(&(this->arr[n]));
					return ; 
				}
				if (n > capasity)
				{
					if (n <= capasity * 2)
						capasity *= 2;
					else
						capasity = n;
					primitive_resize(capasity, false, true);
				}
				if (n > this->size_arr)
				{
					for (size_type l = n; l < size_arr; l++)
						this->t_memory.destroy(&(this->arr[l]));
					for (size_type l = size_arr; l < n; l++)
						this->t_memory.construct(&(this->arr[l]), value);
					size_arr = n;					
				}
/*				if (n <= this->capasity && n > this->size_arr)
				{
					std::cout << "aaa\n";
					size_type i = size_arr;
					for (size_type l = n; l < i; l++)
						this->t_memory.destroy(&(this->arr[l]));
					for (size_type l = size_arr; l < n; l++)
						this->t_memory.construct(&(this->arr[l]), value);
					size_arr = n;
				}
				else if (n > capasity && n > this->size_arr)
				{
					std::cout << "bbb\n";
					if (n > capasity && n <= capasity * 2)
						capasity *= 2;
					else
						capasity = n;
					primitive_resize(capasity, false, true);
					size_type l = size_arr;
					size_arr = n;
					for (; l < this->size_arr; l++)
						this->t_memory.construct(&(this->arr[l]), value);
				}
*/			};
		//Element access
			reference &operator[] (size_type n)
			{return (this->arr[n]);};
			const_reference &operator[] (size_type n) const
			{return (this->arr[n]);};
			reference at(size_type n)
			{
				try
				{
					if (n > this->size_arr || n < 0)
						throw std::out_of_range("ft::vector: argument is out of range");
					else
						return (this->operator[](n));
				}
				catch (std::out_of_range &e)
				{
					throw;
				}
			};
			const_reference at(size_type n) const
			{
				try
				{
					if (n > this->size_arr || n < 0)
						throw std::out_of_range("ft::vector: argument is out of range");
					else
						return (this->arr[n]);
				}
				catch (std::out_of_range &e)
				{
					throw;
				}
			};
			reference front()
			{return *arr;};
			const_reference front() const
			{return *arr;};
			reference back()
			{return arr[this->size_arr - 1];};
			const_reference back() const
			{return arr[this->size_arr - 1];};
		//Modifies
		//
			template< class InputIt >
			void assign( InputIt first, InputIt last )
			{
				this->clear();
				for(;first != last; first++)
					push_back(*first);
			};
			void assign(size_type count, const T& value)
			{
				this->clear();
				if (this->capasity < count)
					primitive_resize(count, true, 1);
				for (size_type i = 0; i < count; i++)
					this->t_memory.construct(&arr[i], value);

			};
		//
			void push_back(const T& value)
			{
				if (capasity == 0)
					capasity = 1;
				if (size_arr + 1 > this->capasity)
				{
					capasity *= 2;
					primitive_resize(capasity, false, true);
				}
				size_arr += 1;
				this->t_memory.construct(&arr[size_arr - 1], value);
			};
			void pop_back()
			{
				if (this->size_arr != 0)
					t_memory.destroy(arr + size_arr-- - 1);
			};

			void		insert(iterator pos, iterator first, iterator last)
			{
				size_type count = last - first;
				size_type i = pos - this->begin();
				iterator curr = first;
				T* contain;
				if (size_arr + count > capasity)
					contain = t_memory.allocate(size_arr + count);
				else
					contain = t_memory.allocate(capasity);
				for (size_type j = 0; j < i; j++)
					t_memory.construct(&contain[j], this->arr[j]);
				for (size_type j = i; j < (i + count); j++, curr++)
					t_memory.construct(&contain[j], curr);
				for (size_type j = i + count; j < size_arr + count; j++, i++)
				t_memory.construct(&contain[j], this->arr[i]);
				this->~vector();
				this->arr = contain;
				size_arr += count;
				if (size_arr > capasity)
						capasity = size_arr;
			};

			void		insert(iterator pos, size_type count, const T& value)
			{
				try
				{
					if (this->size_arr == max_size())
						throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
					if ((size_arr + count) > capasity)
					{
						size_type i = pos - this->begin();
						size_type oldsiz = size_arr;
						size_type oldcap = capasity;
						if (oldcap != capasity)
						{
							if (oldsiz != size_arr)
								std::cout << "";
						}
						if (capasity * 2 < size_arr + count)
							capasity = size_arr + count;
						else
							capasity *= 2;
						T* contain = t_memory.allocate(capasity);
						for (size_type j = 0; j < i; j++)
							t_memory.construct(&contain[j], this->arr[j]);
						for (size_type j = i; j < (i + count); j++)
							t_memory.construct(&contain[j], value);
						for (size_type j = i + count; j < size_arr + count; j++, i++)
							t_memory.construct(&contain[j], this->arr[i]);
						this->~vector();
						this->arr = contain;
						size_arr += count;
						if (size_arr > capasity)
							capasity = size_arr;
					}
					else
					{
						size_type i = pos - this->begin();
						for(size_type j = 1; j <= count; j++)
							t_memory.construct(&arr[size_arr + count - j], this->arr[size_arr - j]);
						for(size_type j = size_arr; j > i + count; j--)
						{
							t_memory.destroy(&arr[j - 1]);
							t_memory.construct(&arr[j - 1], this->arr[j - 1 - count]);
						}
						for(size_type j = 0; (j < count) && ((j + i) < size_arr); j++)
						{
							t_memory.destroy(&arr[j + i]);
							t_memory.construct(&arr[j + i], value);
						}
						if ((i + count) > size_arr)
						{
							for (size_type j = 0; j < (i + count - size_arr); j++)
								t_memory.construct(&arr[size_arr + j], value);
						}
						size_arr += count;
					}
				}
				catch(const std::exception& e)
				{
					throw;
				}
			};
			iterator	insert(iterator pos, const T& value)
			{
				try
				{
					size_type i = pos - this->begin();
					insert(pos, 1, value);
					iterator ret = this->begin();
					return ret += i;
				}
				catch (std::exception &e)
				{
					throw;
				}
			};
			iterator	erase(iterator pos)
			{return erase(pos, pos + 1);};
			iterator	erase(iterator first, iterator last)
			{
				size_type i = first - begin();
				size_type count = last - first; //поменять
				size_type size_arr_new = size_arr - count;
				for (size_type j = 0; i + j < size_arr_new; j++)
				{
					t_memory.destroy(&arr[i + j]);
					t_memory.construct(&arr[i + j], arr[i + j + count]);
				}
				for(size_type j = size_arr_new - 1; j < size_arr; j++)
					t_memory.destroy(&arr[j]);
				size_arr -= count;
//				for (size_type j = 0; j < count; i++)
//					t_memory.destroy(&arr[j]);
//				for (size_type j = i; j < size_arr; j++)
//				{
//					t_memory.construct(&arr[j], arr[j + count]);
//					t_memory.destroy(&arr[j + count]);
//				}
				return iterator(&arr[i]);
			};
			//
			void swap(vector &x)
			{
				std::swap(this->t_memory, x.t_memory);
				std::swap(this->arr, x.arr);
				std::swap(this->size_arr, x.size_arr);
				std::swap(this->capasity, x.capasity);
			};
			void clear()
			{
				this->~vector();
				this->size_arr = 0;
				this->arr = t_memory.allocate(this->capasity);
			};
		//Allocator
			allocator_type get_allocator() const
			{return this->t_memory;};
		//Non-member functions overloads после настройки итератора можно вынести за пределы класса
			friend bool operator == (const vector<T,Alloc>& l, const vector<T,Alloc>& r)
			{
				if (l.size_arr != r.size_arr)
					return false;
				for (size_type i = 0; i < l.size_arr; i++)
					if (l.arr[i] == r.arr[i])
						return false;
				return true;
			};
			friend bool operator != (const vector<T,Alloc>& l, const vector<T,Alloc>& r)
			{return !(l == r);};
			friend bool operator <= (const vector<T,Alloc>& l, const vector<T,Alloc>& r)
			{return !(l > r);};
			friend bool operator >= (const vector<T,Alloc>& l, const vector<T,Alloc>& r)
			{return !(l < r);};
			friend bool operator < (const vector<T,Alloc>& l, const vector<T,Alloc>& r)
			{
				if (l != r)
				{
					size_type i = 0;
					size_type s = l.size_arr;
					if (r.size_arr < s)
						s = r.size_arr;
					for(; i < s; i++)
						if (l.arr[i] != r.arr[i])
							break ;
					if (l.arr[i] < r.arr[i])
						return true;
					if (l.arr[i] == r.arr[i])
						return (l.size_arr < r.size_arr ? true : false);
				}
				return false;
			};
			friend bool operator > (const vector<T,Alloc>& l, const vector<T,Alloc>& r)
			{
				if (l < r || l == r)
					return false;
				return true;
			};
//			friend void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);		
//			{};
	};
}