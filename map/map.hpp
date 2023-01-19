#ifndef MAP_HPP
#define MAP_HPP

#include "../utils/utils.h"
#include "../utils/pair.hpp"
#include "tree/avl_tree.hpp"

namespace ft
{
	template < typename Key, typename T, typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef ft::pair<const Key, T>			value_type;
			typedef Compare							key_compare;
			typedef Allocator						allocator_type;

		private:
			typedef typename Allocator::value_type							allocator_value_type;
			typedef avl_tree<value_type, key_compare, allocator_type>		_Rep_type;

			_Rep_type _M_t;

		public:
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map<Key, T, Compare, Allocator>;
				
				protected:
					Compare _comp;

					value_compare(Compare _c) : _comp(_c){}

				public:
					bool operator()(const value_type& _x, const value_type& _y) const
					{
						return _comp(_x.first, _y.first);
					}
			};

			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename _Rep_type::_Base_ptr				_Base_ptr;
			typedef typename _Rep_type::_Const_Base_ptr			_Const_Base_ptr;
			typedef typename _Rep_type::iterator				iterator;
			typedef typename _Rep_type::const_iterator			const_iterator;
			typedef typename _Rep_type::size_type				size_type;
			typedef typename _Rep_type::difference_type			difference_type;
			typedef typename _Rep_type::reverse_iterator		reverse_iterator;
			typedef typename _Rep_type::const_reverse_iterator	const_reverse_iterator;

			map() : _M_t() {}

			map( const map& other) : _M_t(other._M_t) {}

			explicit map(const Compare& comp, const Allocator& alloc=Allocator()) : _M_t(comp, alloc) {}

			template <typename _InputIterator>
			explicit map(_InputIterator first, _InputIterator last, const Compare _comp = Compare(), const allocator_type& _a = allocator_type() ) : _M_t(_comp, _a)
			{
				while(first != last)
				{
					_M_t.insert(*first);
					first++;
				}
			}

			map& operator=( const map& other )
			{
				this->_M_t = other._M_t;
				return *this;
			}

			ft::pair<iterator, bool>
			insert( const value_type& value )
			{
				_Base_ptr ret = _M_t.search(this->_M_t._tree, value);
				if (ret)
					return  ft::pair<iterator, bool>(iterator(ret), false);
				return ft::pair<iterator, bool>(iterator(_M_t.insert(value)), true);
			}

			iterator insert( iterator pos, const value_type& value )
			{
				if (pos == end())
					insert(value);
				else
					_M_t.insert(pos._M_node, value);
				return iterator(_M_t.search(_M_t._tree, value));
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last )
			{
				while(first != last)
				{
					_M_t.insert(*first);
					first++;
				}
			}

			allocator_type get_allocator() const { return _M_t.get_allocator(); }

			mapped_type& at( const key_type& key ) 
			{ 
				iterator i = iterator(_M_t.lower_bound(ft::make_pair(key, mapped_type())));
				if (i == end() || key_compare()(key, (*i).first))
					throw std::out_of_range(("map::at:	key not found"));
				return (*i).second;
			}

			const mapped_type& at( const key_type& key ) const
			{ 
				const_iterator i = const_iterator(_M_t.lower_bound(ft::make_pair(key, mapped_type())));
				if (i == end() || key_compare()(key, (*i).first))
					throw std::out_of_range(("map::at:	key not found"));
				return (*i).second;
			}

			mapped_type& operator[]( const key_type& key )
			{
				iterator i = iterator(lower_bound(key));
				if (i == end() || key_compare()(key, (*i).first))
					i = insert(i, ft::make_pair(key, mapped_type()));
				return (*i).second;
			}

			iterator begin() { return _M_t.begin(); }

			const_iterator begin() const { return _M_t.begin(); }

			iterator end() { return _M_t.end(); }

			const_iterator end() const { return _M_t.end(); }

			reverse_iterator rbegin() { return _M_t.rbegin(); }

			const_reverse_iterator rbegin() const { return _M_t.rbegin(); }

			reverse_iterator rend() { return _M_t.rend(); }

			const_reverse_iterator rend() const { return _M_t.rend(); }

			bool empty() const { return _M_t.empty(); }

			size_type size() const { return _M_t.size(); }

			size_type max_size() const { return _M_t.max_size(); }

			void clear() { _M_t.clear(); }

			void erase( iterator pos ) { _M_t.delete_node(pos._M_node->data); }

			void erase( iterator first, iterator last )
			{
				iterator temp;
				while(first != last)
				{
					temp = first;
					first++;
					_M_t.delete_node(temp._M_node->data);
				}
			}

			size_type erase( const Key& key )
			{
				_Base_ptr _search = _M_t.search(_M_t._tree, ft::make_pair(key, mapped_type())); 
				if (_search)
				{
					_M_t.delete_node(_search->data);
					return 1;
				}
				return 0;
			}

			void swap( map& other ) // buraya bak
			{
				std::swap(this, other);
			}

			iterator lower_bound( const Key& key )
			{
				return iterator(_M_t.lower_bound(ft::make_pair(key, mapped_type())));
			}

			const_iterator lower_bound( const Key& key ) const
			{
				return const_iterator(_M_t.lower_bound(ft::make_pair(key, mapped_type())));
			}

			iterator upper_bound( const Key& key )
			{
				return iterator(_M_t.upper_bound(ft::make_pair(key, mapped_type())));
			}

			const_iterator upper_bound( const Key& key ) const
			{
				return const_iterator(_M_t.upper_bound(ft::make_pair(key, mapped_type())));
			}

			size_type count( const Key& key ) const
			{
				_Base_ptr _search = _M_t.search(_M_t._tree, ft::make_pair(key, mapped_type())); 
				if (_search)
					return 1;
				return 0;
			}

			iterator find( const Key& key )
			{
				iterator find = iterator(_M_t.lower_bound(ft::make_pair(key, mapped_type())));
				return (find == end() || key_compare()(key, find->first) ? end() : find);
			}

			const_iterator find( const Key& key ) const
			{
				const_iterator find = iterator(_M_t.lower_bound(ft::make_pair(key, mapped_type())));
				return (find == end() || key_compare()(key, _M_t._tree->data.first) ? end() : find);
			}

			ft::pair<iterator,iterator> equal_range( const Key& key )
			{
				return (ft::make_pair(iterator(lower_bound(key)), iterator(upper_bound(key))));
			}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
			{
				return (ft::make_pair(const_iterator(lower_bound(key)), const_iterator(upper_bound(key))));
			}

			key_compare key_comp() const { return key_compare(); }

			value_compare value_comp() const { return value_compare(key_compare()); }

			template<typename _K1, typename _T1, typename _C1, typename _A1>
        	friend bool operator==(const map<_K1, _T1, _C1, _A1>&, const map<_K1, _T1, _C1, _A1>&);

			template<typename _K1, typename _T1, typename _C1, typename _A1>
	        friend bool operator<(const map<_K1, _T1, _C1, _A1>&, const map<_K1, _T1, _C1, _A1>&);
	};

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	bool operator==(const map<_Key, _Tp, _Compare, _Alloc>& __x, const map<_Key, _Tp, _Compare, _Alloc>& __y)
	{ return __x._M_t == __y._M_t; }

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	bool operator<(const map<_Key, _Tp, _Compare, _Alloc>& __x, const map<_Key, _Tp, _Compare, _Alloc>& __y)
    { return __x._M_t < __y._M_t; }

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator!=(const map<_Key, _Tp, _Compare, _Alloc>& __x, const map<_Key, _Tp, _Compare, _Alloc>& __y)
    { return !(__x == __y); }

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator>(const map<_Key, _Tp, _Compare, _Alloc>& __x, const map<_Key, _Tp, _Compare, _Alloc>& __y)
    { return __y < __x; }

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator<=(const map<_Key, _Tp, _Compare, _Alloc>& __x, const map<_Key, _Tp, _Compare, _Alloc>& __y)
    { return !(__y < __x); }

	template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator>=(const map<_Key, _Tp, _Compare, _Alloc>& __x, const map<_Key, _Tp, _Compare, _Alloc>& __y)
    { return !(__x < __y); }

};

#endif