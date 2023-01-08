#ifndef MAP_HPP
#define MAP_HPP

#include "../utils/utils.h"
#include "../utils/pair.hpp"

namespace ft
{
	template < typename Key, typename T, typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, T>>>
	class map
	{
		public:
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef ft::pair<const Key, T>			value_type;
			typedef Compare							key_compare;
			typedef Allocator						allocator_type;
		
		//typedef typename std::size_t	size_type;
		//typedef typename std::ptrdiff_t	difference_type;

		private:
			typedef typename Allocator::value_type	allocator_value_type;

		public:
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map<Key, T, Compare, Allocator>;
				
				protected:
					Compare _comp;

					value_compare(Compare _c) : _comp(c){}

				public:
					bool operator()(const value_type& _x, const value_type& _y) const
					{
						return _comp(_x.first, _y.first);
					}
			};
		
		private:
			typedef typename Allocator::template rebind<value_type>::other _pair_alloc_type;
			// typedef _Rb_tree
	};
};

#endif