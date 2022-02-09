#pragma once

#include <iostream>
#include <memory>
#include <map>

namespace ft
{
	template <typename T1, typename T2>  
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;
		T1 first;
		T2 second;

		pair() : first(), second()
		{};

		pair( const T1& x, const T2& y )
		{
			first = x;
			second = y;
		};

		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) : first(p.first)
		{second = p.second;};

		pair& operator=( const pair& other )
		{
			first = other.first;
			second = other.second;
			return *this;
		};
	};

		template< class T1, class T2 >
		ft::pair<T1,T2> make_pair( T1 t, T2 u )
		{return ft::pair<T1, T2>(t, u);};

		template< class T1, class T2 >
		bool operator==(const ft::pair<T1, T2> &t, const ft::pair<T1, T2> &u)
		{return (t.first == u.first && t.second == u.second);};

		template< class T1, class T2 >
		bool operator!=(const ft::pair<T1, T2> &t, const ft::pair<T1, T2> &u)
		{return !(t == u);};

		template< class T1, class T2 >
		bool operator>(const ft::pair<T1, T2> &t, const ft::pair<T1, T2> &u)
		{return (t.first > u.first && t.second > u.second);};

		template< class T1, class T2 >
		bool operator<=(const ft::pair<T1, T2> &t, const ft::pair<T1, T2> &u)
		{return !(t > u);};

		template< class T1, class T2 >
		bool operator<(const ft::pair<T1, T2> &t, const ft::pair<T1, T2> &u)
		{return (u > t);};

		template< class T1, class T2 >
		bool operator>=(const ft::pair<T1, T2> &t, const ft::pair<T1, T2> &u)
		{return !(t < u);};

	template< class T >
	struct less
	{
		int operator()(const T &t, const T &u) const
		{
			if (t < u)
				return 1;
			else if (t == u)
				return 0;
			return 2;
		};
	};




	//Making iterator

	//iterator
	template<class Key, class T, typename node, class Compare = ft::less<Key> >
	class map_iterator
	{
		public:
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef ft::pair<Key, T>				value_type;
			typedef const ft::pair<const Key, T>	const_value_type;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef Compare							key_compare;
			typedef node*							pointer;
			typedef node&							reference;
			typedef const node*						const_pointer;
			typedef const node&						const_reference;
		private:
			pointer		_node;
			key_compare	_comp;
			pointer		_last;

			pointer	go_to_min(pointer curr)
			{
				pointer tmp = curr;
				while (tmp->left != NULL)
					tmp = tmp->left;
				return tmp;
			};
			pointer	go_to_max(pointer curr)
			{
				pointer tmp = curr;
				while (tmp->right != NULL)
					tmp = tmp->right;
				return tmp;
			};
		public:
			map_iterator(node *nod = 0, node *end = 0, const Compare &comp = Compare())
			{
				this->_node = nod;
				this->_comp = comp;
				this->_last = end;
			};
			map_iterator(const map_iterator &other)
			{
				this->_node = other._node;
				this->_comp = other._comp;
				this->_last = other._last;
			};
			~map_iterator()
			{};
			map_iterator operator=(const map_iterator &other)
			{
				this->_node = other._node;
				this->_comp = other._comp;
				this->_last = other._last;
				return (*this);
			};

			map_iterator &operator++()
			{
				map_iterator &ret(*this);
				value_type temp = this->_node->contain;
				if (this->_node->right != NULL)
				{
					this->_node = go_to_min(this->_node->right);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->right == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first <= temp.first)
					this->_node = NULL;
				return ret;
			};

			map_iterator &operator--()
			{
				map_iterator &ret(*this);
				value_type temp = this->_node->contain;
				if (this->_node->left != NULL)
				{
					this->_node = go_to_max(this->_node->left);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->left == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first >= temp.first)
					this->_node = NULL;
				return ret;
			};

			map_iterator &operator++(int)
			{
				value_type temp = this->_node->contain;
				if (this->_node->right != NULL)
				{
					this->_node = go_to_min(this->_node->right);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->right == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first <= temp.first)
					this->_node = NULL;
				return *this;
			};

			map_iterator &operator--(int)
			{
				value_type temp = this->_node->contain;
				if (this->_node->left != NULL)
				{
					this->_node = go_to_max(this->_node->left);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->left == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first >= temp.first)
					this->_node = NULL;
				return *this;
			};

			value_type &operator*() const
			{return(this->_node->contain);};

			value_type *operator->() const
			{return(&(this->_node->contain));};

			pointer base() const
			{return (this->_node);};
	};

	//могут возникнуть проблемы



	//const iterator
	template<class Key, class T, typename node, class Compare = ft::less<Key> >
	class const_map_iterator
	{
		public:
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef ft::pair<const Key, T>			value_type;
			typedef const ft::pair<const Key, T>	const_value_type;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef Compare							key_compare;
			typedef node*							pointer;
			typedef node&							reference;
			typedef const node*						const_pointer;
			typedef const node&						const_reference;
		private:
			pointer		_node;
			key_compare	_comp;
			pointer		_last;

			pointer	go_to_min(pointer curr)
			{
				pointer tmp = curr;
				while (tmp->left != NULL)
					tmp = tmp->left;
				return tmp;
			};
			pointer	go_to_max(pointer curr)
			{
				pointer tmp = curr;
				while (tmp->right != NULL)
					tmp = tmp->right;
				return tmp;
			};
		public:
			const_map_iterator(node *nod = 0, node *end = 0, const Compare &comp = Compare())
			{
				this->_node = nod;
				this->_comp = comp;
				this->_last = end;
			};
			const_map_iterator(const const_map_iterator &other)
			{
				this->_node = other._node;
				this->_comp = other._comp;
				this->_last = other._last;
			};
			~const_map_iterator()
			{};
			const_map_iterator operator=(const const_map_iterator &other)
			{
				this->_node = other._node;
				this->_comp = other._comp;
				this->_last = other._last;
				return (*this);
			};

			const_map_iterator &operator++()
			{
				const_map_iterator &ret(*this);
				value_type temp = this->_node->contain;
				if (this->_node->right != NULL)
				{
					this->_node = go_to_min(this->_node->right);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->right == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first <= temp.first)
					this->_node = NULL;
				return ret;
			};

			const_map_iterator &operator--()
			{
				const_map_iterator &ret(*this);
				value_type temp = this->_node->contain;
				if (this->_node->left != NULL)
				{
					this->_node = go_to_max(this->_node->left);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->left == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first >= temp.first)
					this->_node = NULL;
				return ret;
			};

			const_map_iterator &operator++(int)
			{
				value_type temp = this->_node->contain;
				if (this->_node->right != NULL)
				{
					this->_node = go_to_min(this->_node->right);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->right == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first <= temp.first)
					this->_node = NULL;
				return *this;
			};

			const_map_iterator &operator--(int)
			{
				value_type temp = this->_node->contain;
				if (this->_node->left != NULL)
				{
					this->_node = go_to_max(this->_node->left);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->left == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first >= temp.first)
					this->_node = NULL;
				return *this;
			};

			const_value_type &operator*() const
			{return(this->_node->contain);};

			const_value_type *operator->() const
			{return(&(this->_node->contain));};

			pointer base()
			{return (this->_node);};
	};

	//reverse iterator
	template<class Key, class T, typename node, class Compare = ft::less<Key> >
	class reverse_map_iterator
	{
		public:
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef ft::pair<const Key, T>			value_type;
			typedef const ft::pair<const Key, T>	const_value_type;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef Compare							key_compare;
			typedef node*							pointer;
			typedef node&							reference;
			typedef const node*						const_pointer;
			typedef const node&						const_reference;
		private:
			pointer		_node;
			key_compare	_comp;
			pointer		_last;

			pointer	go_to_min(pointer curr)
			{
				pointer tmp = curr;
				while (tmp->left != NULL)
					tmp = tmp->left;
				return tmp;
			};
			pointer	go_to_max(pointer curr)
			{
				pointer tmp = curr;
				while (tmp->right != NULL)
					tmp = tmp->right;
				return tmp;
			};
		public:
			reverse_map_iterator(node *nod = 0, node *end = 0, const Compare &comp = Compare())
			{
				this->_node = nod;
				this->_comp = comp;
				this->_last = end;
			};
			reverse_map_iterator(const reverse_map_iterator &other)
			{
				this->_node = other._node;
				this->_comp = other._comp;
				this->_last = other._last;
			};
			~reverse_map_iterator()
			{};
			reverse_map_iterator operator=(const reverse_map_iterator &other)
			{
				this->_node = other._node;
				this->_comp = other._comp;
				this->_last = other._last;
				return (*this);
			};

			reverse_map_iterator &operator--()
			{
				reverse_map_iterator &ret(*this);
				value_type temp = this->_node->contain;
				if (this->_node->right != NULL)
				{
					this->_node = go_to_min(this->_node->right);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->right == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first <= temp.first)
					this->_node = NULL;
				return ret;
			};

			reverse_map_iterator &operator++()
			{
				reverse_map_iterator &ret(*this);
				value_type temp = this->_node->contain;
				if (this->_node->left != NULL)
				{
					this->_node = go_to_max(this->_node->left);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->left == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first >= temp.first)
					this->_node = NULL;
				return ret;
			};

			reverse_map_iterator &operator--(int)
			{
				value_type temp = this->_node->contain;
				if (this->_node->right != NULL)
				{
					this->_node = go_to_min(this->_node->right);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->right == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first <= temp.first)
					this->_node = NULL;
				return *this;
			};

			reverse_map_iterator &operator++(int)
			{
				value_type temp = this->_node->contain;
				if (this->_node->left != NULL)
				{
					this->_node = go_to_max(this->_node->left);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->left == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first >= temp.first)
					this->_node = NULL;
				return *this;
			};

			value_type &operator*() const
			{return(this->_node->contain);};

			value_type *operator->() const
			{return(&(this->_node->contain));};

			pointer base()
			{return (this->_node);};
	};

	//const reverse iterator
	template<class Key, class T, typename node, class Compare = ft::less<Key> >
	class const_reverse_map_iterator
	{
		public:
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef ft::pair<const Key, T>			value_type;
			typedef const ft::pair<const Key, T>	const_value_type;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef Compare							key_compare;
			typedef node*							pointer;
			typedef node&							reference;
			typedef const node*						const_pointer;
			typedef const node&						const_reference;
		private:
			pointer		_node;
			key_compare	_comp;
			pointer		_last;

			pointer	go_to_min(pointer curr)
			{
				pointer tmp = curr;
				while (tmp->left != NULL)
					tmp = tmp->left;
				return tmp;
			};
			pointer	go_to_max(pointer curr)
			{
				pointer tmp = curr;
				while (tmp->right != NULL)
					tmp = tmp->right;
				return tmp;
			};
		public:
			const_reverse_map_iterator(node *nod = 0, node *end = 0, const Compare &comp = Compare())
			{
				this->_node = nod;
				this->_comp = comp;
				this->_last = end;
			};
			const_reverse_map_iterator(const const_reverse_map_iterator &other)
			{
				this->_node = other._node;
				this->_comp = other._comp;
				this->_last = other._last;
			};
			~const_reverse_map_iterator()
			{};
			const_reverse_map_iterator operator=(const const_reverse_map_iterator &other)
			{
				this->_node = other._node;
				this->_comp = other._comp;
				this->_last = other._last;
				return (*this);
			};

			const_reverse_map_iterator &operator--()
			{
				const_reverse_map_iterator &ret(*this);
				value_type temp = this->_node->contain;
				if (this->_node->right != NULL)
				{
					this->_node = go_to_min(this->_node->right);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->right == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first <= temp.first)
					this->_node = NULL;
				return ret;
			};

			const_reverse_map_iterator &operator++()
			{
				const_reverse_map_iterator &ret(*this);
				value_type temp = this->_node->contain;
				if (this->_node->left != NULL)
				{
					this->_node = go_to_max(this->_node->left);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->left == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first >= temp.first)
					this->_node = NULL;
				return ret;
			};

			const_reverse_map_iterator &operator--(int)
			{
				value_type temp = this->_node->contain;
				if (this->_node->right != NULL)
				{
					this->_node = go_to_min(this->_node->right);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->right == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first <= temp.first)
					this->_node = NULL;
				return *this;
			};

			const_reverse_map_iterator &operator++(int)
			{
				value_type temp = this->_node->contain;
				if (this->_node->left != NULL)
				{
					this->_node = go_to_max(this->_node->left);
					return *this;
				}
				pointer tmp = _node->root;
				while ((tmp != NULL) && tmp->left == _node)
				{
					this->_node = tmp;
					tmp = tmp->root;
				}
				if (tmp != NULL)
					this->_node = this->_node->root;
				if (this->_node->contain.first >= temp.first)
					this->_node = NULL;
				return *this;
			};

			const_value_type &operator*() const
			{return(this->_node->contain);};

			const_value_type *operator->() const
			{return(&(this->_node->contain));};

			pointer base()
			{return (this->_node);};
	};



	//свалка операторов сравнения

	template<class Key, class T, typename node, class Compare >
	bool operator!=(const const_reverse_map_iterator<Key, T, node, Compare>& a, const const_reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() != b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator!=(const const_reverse_map_iterator<Key, T, node, Compare>& a, const reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() != b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator==(const const_reverse_map_iterator<Key, T, node, Compare>& a, const const_reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() == b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator==(const const_reverse_map_iterator<Key, T, node, Compare>& a, const reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() == b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<(const const_reverse_map_iterator<Key, T, node, Compare>& a, const const_reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() < b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<(const const_reverse_map_iterator<Key, T, node, Compare>& a, const reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() < b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<=(const const_reverse_map_iterator<Key, T, node, Compare>& a, const const_reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() <= b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<=(const const_reverse_map_iterator<Key, T, node, Compare>& a, const reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() <= b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>(const const_reverse_map_iterator<Key, T, node, Compare>& a, const const_reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() > b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>(const const_reverse_map_iterator<Key, T, node, Compare>& a, const reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() > b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>=(const const_reverse_map_iterator<Key, T, node, Compare>& a, const const_reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() >= b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>=(const const_reverse_map_iterator<Key, T, node, Compare>& a, const reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() >= b.base());};


		template<class Key, class T, typename node, class Compare >
	bool operator!=(const map_iterator<Key, T, node, Compare>& a, const map_iterator<Key, T, node, Compare>& b)
	{return (a.base() != b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator==(const map_iterator<Key, T, node, Compare>& a, const map_iterator<Key, T, node, Compare>& b)
	{return (a.base() == b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<(const map_iterator<Key, T, node, Compare>& a, const map_iterator<Key, T, node, Compare>& b)
	{return (a.base() < b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<=(const map_iterator<Key, T, node, Compare>& a, const map_iterator<Key, T, node, Compare>& b)
	{return (a.base() <= b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>(const map_iterator<Key, T, node, Compare>& a, const map_iterator<Key, T, node, Compare>& b)
	{return (a.base() > b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>=(const map_iterator<Key, T, node, Compare>& a, const map_iterator<Key, T, node, Compare>& b)
	{return (a.base() >= b.base());};


	template<class Key, class T, typename node, class Compare >
	bool operator!=(const map_iterator<Key, T, node, Compare>& a, const const_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() != b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator==(const map_iterator<Key, T, node, Compare>& a, const const_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() == b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<(const map_iterator<Key, T, node, Compare>& a, const const_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() < b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<=(const map_iterator<Key, T, node, Compare>& a, const const_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() <= b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>(const map_iterator<Key, T, node, Compare>& a, const const_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() > b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>=(const map_iterator<Key, T, node, Compare>& a, const const_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() >= b.base());};


	template<class Key, class T, typename node, class Compare >
	bool operator!=(const reverse_map_iterator<Key, T, node, Compare>& a, const reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() != b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator!=(const reverse_map_iterator<Key, T, node, Compare>& a, const const_reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() != b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator==(const reverse_map_iterator<Key, T, node, Compare>& a, const reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() == b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator==(const reverse_map_iterator<Key, T, node, Compare>& a, const const_reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() == b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<(const reverse_map_iterator<Key, T, node, Compare>& a, const reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() < b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<(const reverse_map_iterator<Key, T, node, Compare>& a, const const_reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() < b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<=(const reverse_map_iterator<Key, T, node, Compare>& a, const reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() <= b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<=(const reverse_map_iterator<Key, T, node, Compare>& a, const const_reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() <= b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>(const reverse_map_iterator<Key, T, node, Compare>& a, const reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() > b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>(const reverse_map_iterator<Key, T, node, Compare>& a, const const_reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() > b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>=(const reverse_map_iterator<Key, T, node, Compare>& a, const reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() >= b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>=(const reverse_map_iterator<Key, T, node, Compare>& a, const const_reverse_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() >= b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator!=(const const_map_iterator<Key, T, node, Compare>& a, const const_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() != b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator!=(const const_map_iterator<Key, T, node, Compare>& a, const map_iterator<Key, T, node, Compare>& b)
	{return (a.base() != b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator==(const const_map_iterator<Key, T, node, Compare>& a, const const_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() == b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator==(const const_map_iterator<Key, T, node, Compare>& a, const map_iterator<Key, T, node, Compare>& b)
	{return (a.base() == b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<(const const_map_iterator<Key, T, node, Compare>& a, const const_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() < b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<(const const_map_iterator<Key, T, node, Compare>& a, const map_iterator<Key, T, node, Compare>& b)
	{return (a.base() < b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<=(const const_map_iterator<Key, T, node, Compare>& a, const const_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() <= b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator<=(const const_map_iterator<Key, T, node, Compare>& a, const map_iterator<Key, T, node, Compare>& b)
	{return (a.base() <= b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>(const const_map_iterator<Key, T, node, Compare>& a, const const_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() > b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>(const const_map_iterator<Key, T, node, Compare>& a, const map_iterator<Key, T, node, Compare>& b)
	{return (a.base() > b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>=(const const_map_iterator<Key, T, node, Compare>& a, const const_map_iterator<Key, T, node, Compare>& b)
	{return (a.base() >= b.base());};

	template<class Key, class T, typename node, class Compare >
	bool operator>=(const const_map_iterator<Key, T, node, Compare>& a, const map_iterator<Key, T, node, Compare>& b)
	{return (a.base() >= b.base());};
}