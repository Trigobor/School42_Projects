#pragma once

#include "utilities.hpp"
#include <unistd.h>

#define BLACK 0;
#define RED 1;

namespace ft
{
	template<
	class Key,
	class T,
	class Compare = ft::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			struct node
			{
				pair	<Key, T> contain;
				bool	collor;
				node	*right;
				node	*left;
				node	*root;
				node(const pair<Key, T> &contain)
				{this->contain = contain;};
			};
			class value_compare
			{
				private:
					Compare base;
					value_compare(Compare sample)
					{base = sample;};
				public:
					bool operator()(const pair<Key, T>& x, const pair<Key, T>& y) const
                    {return base(x.first, y.first);}
			};
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const Key, T> value_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef	typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef ft::map_iterator<Key, T, node, Compare> iterator;
			typedef Allocator allocator_type;
			typedef typename Allocator::template rebind<node>::other allocator_spec;
			typedef ft::const_map_iterator<Key, T, node, Compare> const_iterator;
			typedef ft::reverse_map_iterator<Key, T, node, Compare> reverse_iterator;
			typedef ft::const_reverse_map_iterator<Key, T, node, Compare> const_reverse_iterator;

			//Если возникнут какие-нибудь пробелы с аллицированием памяти под ноду, 
			//попрорбуй использовать нижестоящую конструкцию вместо allocator_type
			//typedef typename  Alloc::template rebind<node>::other	specific_alloc;

		private:
			allocator_type _alloc;
			allocator_spec spetiallocator;
			key_compare _comp;
			size_type _size_struct;
			size_type _size_alloc;
			node* _node;

			iterator customAt( const Key& key )
			{
				try
				{
					if (_node == NULL)
						throw std::out_of_range("map::at:  key not found");
					else
					{
						node *one = _node;
						node *two;

						while (one != NULL)
						{
							two = one;
							switch (_comp(two->contain.first, key))
							{
							case (1):
								one = two->right;
								break;
							case (2):
								one = two->left;
								break;
							default:
							return (iterator(two, two, this->_comp));
							}
						}
						throw std::out_of_range("map::at:  key not found");
					}
				}
				catch(const std::exception& e)
				{
					throw;
				}
			};

			void untie(node *changeling)
			{
				node *prev = changeling->root;
				if (changeling->left == NULL && changeling->right == NULL)
				{
					if ((prev->left != NULL) && prev->left->contain.first == changeling->contain.first)
						prev->left = NULL;
					else
						prev->right = NULL;
					changeling->root = NULL; 
				}
				else if (changeling->left == NULL)
				{
					if ((prev->left != NULL) && prev->left->contain.first == changeling->contain.first)
						prev->left = changeling->right;
					else
						prev->right = changeling->right;
					changeling->right->root = prev;
					changeling->root = NULL;
				}
				else if (changeling->right == NULL)
				{
					if ((prev->left != NULL) && prev->left->contain.first == changeling->contain.first)
						prev->left = changeling->left;
					else
						prev->right = changeling->left;
					changeling->left->root = prev;
					changeling->root = NULL;
				}
			};

			void spetial_erase(node *item)
			{
				node *curr = item;
				if (curr->left == NULL && curr->right == NULL)
					this->spetiallocator.destroy(curr);
				else if (curr->left == NULL)
				{
					curr->right->root = NULL;
					this->spetiallocator.destroy(curr);
				}
				else if (curr->right == NULL)
				{
					curr->left->root = NULL;
					this->spetiallocator.destroy(curr);
				}	
				else
				{
					iterator tmp(curr, curr, _comp);
					tmp++;
					node *changeling = tmp.base();
					untie(changeling);
					changeling->left = curr->left;
					changeling->right = curr->right;
					changeling->root = NULL;
					curr->root = NULL;
					curr->left = NULL;
					curr->right = NULL;
					this->spetiallocator.destroy(curr);
				}
				this->_size_struct--;
			};

	/*		void calculateRelatives(node *daughter, node *mother, node *grandmother, node *aunt)
			{
				aunt = NULL;
				mother = NULL;
				grandmother = NULL;
				if (daughter->root)
					mother = daughter->root;
				if (mother->root)
					grandmother = mother->root;
				if ((grandmother->left) && (grandmother->right))
				{
					if (grandmother->left->contain.first == mother->contain.first)
						aunt = grandmother->right;
					else
						aunt = grandmother->left;
				}
			}

			void turn(node *doughter, node *mother, node *grandmother)
			{
				if ()

			}

			void treeFixing(node *lastelem, node *rock_bottom)
			{
				node *daughter = lastelem;
				node *mother;
				node *grandmother;
				node *aunt;

				while (daughter->contain.first != rock_bottom->contain.first)
				{
					calculateRelatives(daughter, mother, grandmother, aunt);
					if (!mother || !grandmother || !aunt)
						break;
					else
					{
						if (daughter->collor == RED && mother->collor == RED && aunt->collor = RED)
						{
							mother->collor = BLACK;
							aunt->collor = BLACK;
							grandmother->collor = RED;
							daughter = grandmother;
						}
						else if (daughter->collor == RED && mother->collor == RED && aunt->collor = BLACK)
						{
							mother->collor = BLACK;
							grandmother->collor = RED;
						}
					}
				}
				
			};
	*/
		public:
		//Member functions
		map()
		{
			this->_size_alloc = 0;
			this->_size_struct = 0;
//			this->_alloc = alloc;
//			this->_comp = comp;
			this->_node = NULL;
		};
		explicit map( const Compare& comp, const Allocator& alloc = Allocator() )
		{
			this->_size_alloc = 0;
			this->_size_struct = 0;
			this->_alloc = alloc;
			this->_comp = comp;
			this->_node = NULL;
		};
		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
		{
			this->_alloc = alloc;
			this->_comp = comp;
			this->_size_alloc = 0;
			this->_size_struct = 0;
			this->_node = NULL;
			insert(first, last);
		};
		map( const map& other )
		{
			this->_alloc = other._alloc;
			this->_comp = other._comp;
			this->spetiallocator = other.spetiallocator;
			iterator begi = other.begin;
			iterator endi = other.end;
			insert(begi, endi);
		};
		~map()
		{
			this->clear();
			this->spetiallocator.deallocate(_node, _size_alloc);
		};
		map &operator=( const map& other )
		{
			this->_alloc = other._alloc;
			this->_comp = other._comp;
			this->spetiallocator = other.spetiallocator;
			iterator begi = other.begin;
			iterator endi = other.end;
			insert(begi, endi);
			return (*this);
		};
		allocator_type get_allocator() const
		{return (_alloc);};

		//Element access
		T& at( const Key& key )
		{
			try
			{
				if (_node == NULL)
					throw std::out_of_range("map::at:  key not found");
				else
				{
					node *one = _node;
					node *two;

					while (one != NULL)
					{
						two = one;
						switch (_comp(two->contain.first, key))
						{
						case (1):
							one = two->right;
							break;
						case (2):
							one = two->left;
							break;
						default:
							return (two->contain.second);
						}
					}
					throw std::out_of_range("map::at:  key not found");
				}
			}
			catch(const std::exception& e)
			{
				throw;
			}
		};
		const T& at( const Key& key ) const
		{
			try
			{
				if (_node == NULL)
					throw std::out_of_range("map::at:  key not found");
				else
				{
					node *one = _node;
					node *two;

					while (one != NULL)
					{
						two = one;
						switch (_comp(two->contain.first, key))
						{
						case (1):
							one = two->right;
							break;
						case (2):
							one = two->left;
							break;
						default:
							return (two->contain.second);
						}
					}
					throw std::out_of_range("map::at:  key not found");
				}
			}
			catch(const std::exception& e)
			{
				throw;
			}
		};

		T& operator[]( const Key& key )
		{
				if (_node == NULL)
					return (*((insert(ft::make_pair(key, NULL))).first)).second;
				else
				{
					node *one = _node;
					node *two;

					while (one != NULL)
					{
						two = one;
						switch (_comp(two->contain.first, key))
						{
						case (1):
							one = two->right;
							break;
						case (2):
							one = two->left;
							break;
						default:
							return (two->contain.second);
						}
					}
					return (*((insert(ft::make_pair(key, NULL))).first)).second;
				}
		};


		//Iterators
		iterator begin()
		{
			if (this->_node == NULL)
				return iterator(NULL);
			node *curr = this->_node;
			node *prev;
			while (curr != NULL)
			{
				prev = curr;
				curr = curr->left;
			}
			return iterator(prev, prev->root, _comp);
		};
		const_iterator begin() const
		{
			if (this->_node == NULL)
				return const_iterator(NULL);
			node *curr = this->_node;
			node *prev;
			while (curr != NULL)
			{
				prev = curr;
				curr = curr->left;
			}
			return const_iterator(prev, prev->root, _comp);
		};
		iterator end()
		{
			if (this->_node == NULL)
				return iterator(NULL);
			node *curr = this->_node;
			node *prev;
			while (curr != NULL)
			{
				prev = curr;
				curr = curr->right;
			}
			return iterator(NULL, prev->root, _comp);
		};
		const_iterator end() const
		{
			if (this->_node == NULL)
				return const_iterator(NULL);
			node *curr = this->_node;
			node *prev;
			while (curr != NULL)
			{
				prev = curr;
				curr = curr->right;
			}
			return const_iterator(prev, prev->root, _comp);
		};
		reverse_iterator rbegin()
		{
			if (this->_node == NULL)
				return reverse_iterator(NULL);
			node *curr = this->_node;
			node *prev;
			while (curr != NULL)
			{
				prev = curr;
				curr = curr->right;
			}
			return reverse_iterator(prev, prev->root, _comp);
		};
		const_reverse_iterator rbegin() const
		{
			if (this->_node == NULL)
				return const_reverse_iterator(NULL);
			node *curr = this->_node;
			node *prev;
			while (curr != NULL)
			{
				prev = curr;
				curr = curr->right;
			}
			return const_reverse_iterator(prev, prev->root, _comp);
		};
		reverse_iterator rend()
		{
			if (this->_node == NULL)
				return reverse_iterator(NULL);
			node *curr = this->_node;
			node *prev;
			while (curr != NULL)
			{
				prev = curr;
				curr = curr->left;
			}
			return reverse_iterator(NULL, prev->root, _comp);
		};
		const_reverse_iterator rend() const
		{
			if (this->_node == NULL)
				return const_reverse_iterator(NULL);
			node *curr = this->_node;
			node *prev;
			while (curr != NULL)
			{
				prev = curr;
				curr = curr->left;
			}
			return const_reverse_iterator(NULL, prev->root, _comp);
		};

		//Capasity
		bool empty() const
		{return (this->_size_struct == 0 ? true : false);};
		size_type size() const
		{return this->_size_struct;};
		size_type max_size() const
		{return this->spetiallocator.max_size();};

		//Modifiers
		ft::pair<iterator, bool> insert( const value_type& value )
		{
			//я хотел созадвать по умолчанию новую ноду, но так как я реализую map,
			//а не miltimap, то вызов insert не всегда будет созавать ноую ноду.
			//изз-за этого insert разрастается, но работать будет оптимально
			node* curr;
			node* prev = this->_node;
			pair<iterator, bool> rez;
			if (this->_node == NULL)
			{
				//самый базовый случай, когда map пустая, нужно:
				//аллоцировать память
				this->_node = this->spetiallocator.allocate(1 * sizeof(node*));
				//сконструировать и заполнить ноду
				this->spetiallocator.construct(this->_node, value);
				this->_node->left = NULL;
				this->_node->right = NULL;
				this->_node->root = NULL;
				this->_node->left = BLACK;
				//создаем итератор, увеличиваем capacity и size, возвращаем результат
				iterator reterator(this->_node, this->_node, this->_comp);
				rez.first = reterator;
				rez.second = true;
				_size_alloc++;
				_size_struct++;
				return rez;
			}
			else
			{
				while (prev != NULL)
				{
					curr = prev;
					switch (_comp(curr->contain.first, value.first))
					{
					case (1):
						prev = curr->right;
						break;
					case (2):
						prev = curr->left;
						break;
					default:
						iterator reterator(curr, curr, this->_comp);
						rez.first = reterator;
						rez.second = false;
						return rez;
					}
				}
			}
			// мы отмели 2 варианта, если мар была пустой и если в мар уже есть нода с добавляемым ключом
			// далее нужно вставить значение и сбалансировать дерево перекрасив его, или повернув поддеревья

			node *newnode = this->spetiallocator.allocate(1 * sizeof(node*));
			this->spetiallocator.construct(newnode, value);
			newnode->right = NULL;
			newnode->left = NULL;
			newnode->root = NULL;
			newnode->collor = RED; //пускай остается красным, в случае наруения правил, фиксить дерево будет другой метод

			if (this->_comp(curr->contain.first, newnode->contain.first) == 1)
				curr->right = newnode;
			else
				curr->left = newnode;
			newnode->root = curr;
			// перед возвратом значения
//			if (curr->collor == RED)
//				treeFixing(newnode, this->_node);
			// нужно починить дерево
			iterator reterator(newnode, newnode, this->_comp);
			rez.first = reterator;
			rez.second = true;
			_size_alloc++;
			_size_struct++;
			return rez;			
		};

		iterator insert( iterator hint, const value_type& value )
		{
			//придумай проверку на NULL значения получе
			if (hint.base() == NULL)
				return insert(value).first;
			node* curr;
			node* prev = hint.base();
			while (prev != NULL)
			{
				curr = prev;
				switch (_comp(curr->contain.first, value.first))
				{
				case (1):
					prev = curr->right;
					break;
				case (2):
					prev = curr->left;
					break;
				default:
					return iterator(curr, curr, this->_comp);
				}
			}
			node *newnode = this->spetiallocator.allocate(1 * sizeof(node*));
			this->spetiallocator.construct(newnode, value);
			newnode->right = NULL;
			newnode->left = NULL;
			newnode->root = NULL;
			newnode->collor = RED;
			if (this->_comp(curr->contain.first, newnode->contain.first) == 1)
				curr->right = newnode;
			else
				curr->left = newnode;
			newnode->root = curr;
			// перед возвратом значения
//			if (curr->collor == RED)
//				treeFixing(newnode, this->_node);
			// нужно починить дерево
			_size_alloc++;
			_size_struct++;
			return iterator(newnode, newnode, this->_comp);
		};

		template< class InputIt >
			void insert( InputIt first, InputIt last )
		{
			insert(*last);
			while (first != last)
			{
				insert(*first);
				first++;
			}
		};

		void erase( iterator pos )
		{
			node *curr = pos.base();
			node *prev = curr->root;
			if (prev == NULL)
			{
				spetial_erase(curr);
				return ;
			}
			if (curr->left == NULL && curr->right == NULL)
			{
				if (prev->left->contain.first == curr->contain.first)
					prev->left = NULL;
				else
					prev->right = NULL;
				curr->root = NULL;
				this->spetiallocator.destroy(curr);
			}
			else if (curr->left == NULL)
			{
				if ((prev->left != NULL) && prev->left->contain.first == curr->contain.first)
					prev->left = curr->right;
				else
					prev->right = curr->right;
				curr->right->root = prev;
				curr->root = NULL;
				this->spetiallocator.destroy(curr);
			}
			else if (curr->right == NULL)
			{
				if ((prev->left != NULL) && prev->left->contain.first == curr->contain.first)
					prev->left = curr->left;
				else
					prev->right = curr->left;
				curr->left->root = prev;
				curr->root = NULL;
				this->spetiallocator.destroy(curr);
			}
			else
			{
				iterator tmp(curr, curr, _comp);
				tmp++;
				node *changeling = tmp.base();
				untie(changeling);
				prev = curr->root;
				if ((prev->left != NULL) && prev->left->contain.first == curr->contain.first)
					prev->left = changeling;
				else
					prev->right = changeling;
				changeling->left = curr->left;
				changeling->right = curr->right;
				changeling->root = prev;
				curr->root = NULL;
				curr->left = NULL;
				curr->right = NULL;
				this->spetiallocator.destroy(curr);
			}
			this->_size_struct--;
		};

		void erase( iterator first, iterator last )
		{
//			std::cout << (*first).second << "\n";
//			std::cout << (*last).second << "\n";
			iterator current = first;
			while (first != last)
			{
				current = first;
				++first;
				erase(current);
//				usleep(1000);
			}
		};

		size_type erase( const Key& key )
		{
			try
			{
				iterator iter = customAt(key);
				erase(iter);
				return 1;
			}
			catch(const std::exception& e)
			{
				return 0;
			}
		};
		void swap( map& other )
		{
			swap(this->_node, other._node);
			swap(this->_size_struct, other._size_struct);
			swap(this->_size_alloc, other._size_alloc);
			swap(this->_comp, other._comp);
			swap(this->spetiallocator, other.spetiallocator);
			swap(this->_alloc, other._alloc);
		};

		size_type count( const Key& key ) const
		{
			try
			{
				T val = this->at(key);
				return 1;
			}
			catch(const std::exception& e)
			{
				return 0;
			}
		};

		const_iterator find( const Key& key ) const
		{
			if (_node == NULL)
				return this->cend();
			else
			{
				node *one = _node;
				node *two;
					while (one != NULL)
				{
					two = one;
					switch (_comp(two->contain.first, key))
					{
					case (1):
						one = two->right;
						break;
					case (2):
						one = two->left;
						break;
					default:
						return (const_iterator(two, two, this->_comp));
					}
				}
				return this->cend();
			}
		};
		iterator find( const Key& key )
		{
			if (_node == NULL)
				return this->end();
			else
			{
				node *one = _node;
				node *two;
					while (one != NULL)
				{
					two = one;
					switch (_comp(two->contain.first, key))
					{
					case (1):
						one = two->right;
						break;
					case (2):
						one = two->left;
						break;
					default:
						return (iterator(two, two, this->_comp));
					}
				}
				return this->end();
			}
		};


		ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
		{
			ft::pair<const_iterator,const_iterator> rez;
			rez->first = lower_bound(key);
			rez->second = upper_bound(key);
			return rez;
		};
		ft::pair<iterator,iterator> equal_range( const Key& key )
		{
			ft::pair<iterator,iterator> rez;
			rez->first = lower_bound(key);
			rez->second = upper_bound(key);
			return rez;
		};
		iterator lower_bound( const Key& key )
		{
			iterator rez = begin();
			size_type i = 0;
			while (true)
			{
				if (i >= this->_size_struct)
					return NULL;
				if ((*rez).first < key)
				{
					rez++;
					i++;
				}
				else
					return rez;
			}
		};
		const_iterator lower_bound( const Key& key ) const
		{
			const_iterator rez = begin();
			size_type i = 0;
			while (true)
			{
				if (i >= this->_size_struct)
					return NULL;
				if ((*rez).first < key)
				{
					rez++;
					i++;
				}
				else
					return rez;
			}
		};
		iterator upper_bound( const Key& key )
		{
			iterator rez = begin();
			size_type i = 0;
			while (true)
			{
				if (i >= this->_size_struct)
					return NULL;
				if ((*rez).first <= key)
				{
					rez++;
					i++;
				}
				else
					return rez;
			}
		};
		const_iterator upper_bound( const Key& key ) const
		{
			const_iterator rez = begin();
			size_type i = 0;
			while (true)
			{
				if (i >= this->_size_struct)
					return NULL;
				if ((*rez).first <= key)
				{
					rez++;
					i++;
				}
				else
					return rez;
			}
		};

		void clear()
		{
			iterator begi = begin();
			iterator endi = end();
			if (this->_size_struct == 0)
				return;
			else if (begi == endi)
				erase(begi);
			else
				erase(begi, endi);
		};
		//Observers
		key_compare key_comp() const
		{return (this->_size_struct);};
		value_compare value_comp() const
		{return (value_compare(this->_comp));};
	
		friend bool operator==( const map& lhs, const map& rhs )
		{
			if (!(lhs < rhs) && !(lhs > rhs))
				return true;
			return false;
		};

		friend bool operator!=( const map& lhs, const map& rhs )
		{return !(lhs == rhs);};

		friend bool operator<=( const map& lhs, const map& rhs )
		{return !(lhs > rhs);};

		friend bool operator>=( const map& lhs, const map& rhs )
		{return !(lhs < rhs);};

		friend bool operator<( const map& lhs, const map& rhs )
		{
			const_iterator liter = lhs.begin();
			const_iterator riter = rhs.begin();
			size_t i = 0;

			if ((lhs.size() > rhs.size()) || (lhs.size() == 0 && rhs.size() == 0))
				return false;
			while (i < lhs.size())
			{
				if ((liter.base()->contain.first >= riter.base()->contain.first) || (liter.base()->contain.second >= riter.base()->contain.second))
					return false;
				else
				{
					liter++;
					riter++;
					i++;
				};
			}
			return true;
		};

		friend bool operator>( const map& lhs, const map& rhs )
		{return (rhs < lhs);};

	};
}