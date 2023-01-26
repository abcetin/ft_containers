#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "../iterator.hpp"
#include "rotation.hpp"
#include "insert_delete.hpp"
#include "../../utils/reverse_iterator.hpp"
#include "tree_utils.hpp"
#include <limits>

namespace ft
{
	template <typename _Val, typename _Compare, typename _Allocator = std::allocator<_Val> > 
	class avl_tree
	{
		public:
			typedef typename _Allocator::template rebind<node<_Val> >::other	allocator_type;
			typedef _Val														value_type;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef size_t														size_type;
			typedef ptrdiff_t													difference_type;
			typedef ft::const_tree_iterator<value_type>							const_iterator;
			typedef ft::tree_iterator<value_type>								iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef ft::node<_Val>*												_Base_ptr;

			_Base_ptr		_tree;
			_Base_ptr		_end;
			size_type		_count;
			_Compare		_key_compare;
			allocator_type	_allocator;
		private:
			void _M_erase(_Base_ptr _x)
			{
				if (_x)
				{
					_M_erase(_x->left_node);
					_M_erase(_x->right_node);
					this->_allocator.destroy(_x);
					this->_allocator.deallocate(_x, 1);
					_x = NULL;
				}	
			}

		public:

			avl_tree(): _tree(), _end(), _count(0), _key_compare(), _allocator() 
			{ 

			}

			avl_tree(const _Compare& _comp, const allocator_type& _a = allocator_type()) : _tree(), _end(), _count(0), _key_compare(_comp), _allocator(_a)
			{

			}

			avl_tree (const avl_tree& _x) : _count(0), _key_compare(_x._key_compare), _allocator(_x._allocator)
			{
				if (_x._tree)
				{
					create_node(&this->_end, _Val(), _allocator);
					this->_tree = _copy(this->_tree, _x._tree, _end, _allocator);
					this->_end->parent_node = _tree->_maximum(_tree);
					this->_count = _x._count;
					_end->left_node = _tree;
				}
			}

			avl_tree& operator=(const avl_tree& _x)
			{
				if (this != &_x)
				{
					clear();
					_key_compare = _x._key_compare;
					_allocator = _x._allocator;
					if (_x._tree != 0)
					{
						create_node(&_end, _Val(), _allocator);
						_tree = _copy(_tree, _x._tree, _end, _allocator);
						_count = _x._count;
						_end->left_node = _tree;
						_end->parent_node = _tree->_maximum(_tree);
					}
				}
				return *this;
			}

			_Compare value_compare() const { return _key_compare; }

			_Base_ptr insert(const _Val& _value)
			{
				if(!_end)
					create_node(&_end, _Val(), _allocator);
				_Base_ptr ret = search(this->_tree, _value);
				if (!ret)
				{
					this->_tree = _add_with_balance(this->_tree, _value, this->_end, value_compare(), _allocator);
					_Base_ptr max = _tree->_maximum(_tree);
					this->_end->parent_node = max;
					this->_end->left_node = this->_tree;
					this->_count++;
					ret = search(this->_tree, _value);
				}
				return ret;
			}

			void insert(_Base_ptr pos, const _Val& _value)
			{
				if(!_end)
					create_node(&_end, _Val(), _allocator);
				this->_count++;
				if (!_tree)
					_tree = _add_with_balance(_tree, _value, _tree, value_compare(), _allocator);
				else if (value_compare()(_tree->data, pos->data) && value_compare()(_value, _tree->data))
					_tree =  _add_with_balance(_tree, _value, _end, value_compare(), _allocator);
				else if (value_compare()(pos->data , _tree->data) && value_compare()(_tree->data, _value))
					_tree = _add_with_balance(_tree, _value, _end, value_compare(), _allocator);
				else
					pos = _add_with_balance(pos, _value, pos, value_compare(), _allocator);
				this->_end->left_node = this->_tree;
				this->_end->parent_node = this->_tree->_maximum(_tree);
			}
			
			_Base_ptr search(_Base_ptr _node, _Val _value) const
			{
				if (!_node)
					return _node;
				else if (_value.first == _node->data.first)
					return _node;
				else if (value_compare()(_node->data, _value))
					_node = search(_node->right_node, _value);
				else if (value_compare()(_value, _node->data))
					_node = search(_node->left_node, _value);
				return _node;
			}

			void clear() 
			{
				_M_erase(_tree);
				_count = 0;
			}

			int get_balance() { return _get_balance(this->_tree); }

			void delete_node(const _Val& _value)
			{  
				this->_tree = _delete_node(this->_tree, _value, value_compare(), _allocator);
				this->_end->parent_node = _tree->_maximum(_tree);
				this->_end->left_node = this->_tree;
				//this->_end->left_node = _tree;
				this->_count--;
			}

			allocator_type get_allocator() const { return this->_allocator; }

			iterator begin() { return iterator(this->_tree->_minimum(_tree)); }
			
			const_iterator begin() const { return const_iterator(this->_tree->_minimum(_tree)); }
			
			iterator end() { return iterator(this->_end); }
			
			const_iterator end() const { return const_iterator(this->_end); }

			reverse_iterator rbegin() { return reverse_iterator(end()); }

			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

			reverse_iterator rend() { return reverse_iterator(begin()); }

			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

			bool empty() const { return (this->_count == 0); }

			size_type size() const { return this->_count; }

			size_type max_size() const { return get_allocator().max_size(); }

			_Base_ptr lower_bound(const value_type& _value)
			{
				_Base_ptr ret = _end;
				_Base_ptr _node = _tree;
				while (_node)
				{
					if (!value_compare()(_node->data, _value))
					{
						ret = _node;
						_node = _node->left_node;
					}
					else
						_node = _node->right_node;
				}
				return ret;
			}

			_Base_ptr lower_bound(const value_type& _value) const
			{
				_Base_ptr ret = _end;
				_Base_ptr _node = _tree;
				while (_node)
				{
					if (!value_compare()(_node->data, _value))
					{
						ret = _node;
						_node = _node->left_node;
					}
					else
						_node = _node->right_node;
				}
				return ret;
			}

			_Base_ptr upper_bound(const value_type& _value)
			{
				_Base_ptr ret = _end;
				_Base_ptr _node = _tree;
				while (_node)
				{
					if (value_compare()(_value, _node->data))
					{
						ret = _node;
						_node = _node->left_node;
					}
					else
						_node = _node->right_node;
				}
				return ret;
			}

			_Base_ptr upper_bound(const value_type& _value) const
			{
				_Base_ptr ret = _end;
				_Base_ptr _node = _tree;
				while (_node)
				{
					if (value_compare()(_value, _node->data))
					{
						ret = _node;
						_node = _node->left_node;
					}
					else
						_node = _node->right_node;
				}
				return ret;
			}

			~avl_tree()
			{
				_M_erase(_tree);
			}
	};

	template<typename _Val, typename _Compare, typename _Alloc>
    bool operator==(const ft::avl_tree<_Val, _Compare, _Alloc>& __x,
	const ft::avl_tree<_Val, _Compare, _Alloc>& __y)
    {
    	 return __x.size() == __y.size()
	     && ft::equal(__x.begin(), __x.end(), __y.begin());
    }

	template<typename _Val, typename _Compare, typename _Alloc>
    bool operator<(const ft::avl_tree<_Val, _Compare, _Alloc>& __x,
	const ft::avl_tree<_Val, _Compare, _Alloc>& __y)
    {
	 	return ft::lexicographical_compare(__x.begin(), __x.end(), 
					  __y.begin(), __y.end());
    }

	template<typename _Val, typename _Compare, typename _Alloc>
    bool operator!=(const ft::avl_tree<_Val, _Compare, _Alloc>& __x,
	const ft::avl_tree<_Val, _Compare, _Alloc>& __y)
    {
    	return !(__x == __y);
    }

	template<typename _Val, typename _Compare, typename _Alloc>
    bool operator>(const ft::avl_tree<_Val, _Compare, _Alloc>& __x,
	const ft::avl_tree<_Val, _Compare, _Alloc>& __y)
    {
		 return __y < __x;
    }

	template<typename _Val, typename _Compare, typename _Alloc>
    bool operator<=(const ft::avl_tree<_Val, _Compare, _Alloc>& __x,
	const ft::avl_tree<_Val, _Compare, _Alloc>& __y)
    {
    	 return !(__y < __x);
    }

	template<typename _Val, typename _Compare, typename _Alloc>
	bool operator>=(const ft::avl_tree<_Val, _Compare, _Alloc>& __x,
	const ft::avl_tree<_Val, _Compare, _Alloc>& __y)
    {
    	return !(__x < __y);
    }
};

#endif