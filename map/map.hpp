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
			typedef typename Allocator::value_type				allocator_value_type;
			typedef avl_tree<value_type, key_compare, allocator_type>		_Rep_type;
		public:
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
					_M_t.insert(first._M_node->data);
					first++;
				}
			}

			std::pair<iterator, bool>
			insert( const value_type& value )
			{
				_Base_ptr ret = _M_t.search(this->_M_t._tree, value);
				if (ret)
					return  std::pair<iterator, bool>(iterator(ret), false);
				return std::pair<iterator, bool>(iterator(_M_t.insert(value)), true);
			}

			iterator insert( iterator pos, const value_type& value )
			{
				_M_t.insert(pos._M_node, value);
				return iterator(_M_t.search(_M_t._tree, value));
			}

			map& operator=( const map& other )
			{
				_M_t = other._M_t;
				return *this;
			}
			allocator_type get_allocator() const { return _M_t.get_allocator(); }

			mapped_type& at( const key_type& key ) 
			{ 
				iterator i = iterator(lower_bound(_M_t._tree, key));
				if (i == end() || key_compare()(key, (*i).first))
					throw std::out_of_range(("map::at:	key not found"));
				return (*i).second;
			}

			const mapped_type& at( const key_type& key ) const
			{ 
				const_iterator i = const_iterator(lower_bound(_M_t._tree, key));
				if (i == end() || key_compare()(key, (*i).first))
					throw std::out_of_range(("map::at:	key not found"));
				return (*i).second;
			}

			// mapped_type& operator[]( const key_type& key )
			// {
			// 	iterator i = iterator(lower_bound(_M_t._tree, key));
			// 	if (i == end() || key_compare()(key, (*i).first))
			// 		insert(i._M_node, value_type(key, mapped_type()));
			// 	return (*i)->second;
			// }


			iterator begin() { return _M_t.begin(); }

			iterator end() { return _M_t.end(); }			
	};
};

#endif