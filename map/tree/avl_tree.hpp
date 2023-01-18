#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "../iterator.hpp"
#include "rotation.hpp"
#include "insert_delete.hpp"
#include "../../utils/reverse_iterator.hpp"
#include "tree_utils.hpp"

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
			typedef ft::reverse_iterator<iterator>								const_reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						reverse_iterator;
			typedef ft::node<_Val>*												_Base_ptr;
			typedef const ft::node<_Val>*										_Const_Base_ptr;

			_Base_ptr		_tree;
			_Base_ptr		_end;
			size_type		_count;
			_Compare		_key_compare;
			allocator_type	_allocator;

		public:

			avl_tree(): _tree(), _count(0), _key_compare(), _allocator() { std::cout << _tree << std::endl; create_node(&this->_end, _Val(), _allocator);}

			avl_tree(const _Compare& _comp, const allocator_type& _a = allocator_type()) : _tree(), _end(0), _count(0), _key_compare(_comp), _allocator(_a)
			{
				create_node(&this->_end, _Val(), _allocator);
				//_tree = _end;
				//std::cout << _tree->data.first << std::endl;
			}

			avl_tree (const avl_tree& _x) : _key_compare(_x._key_compare), _allocator(_x._allocator), _count(_x._count)
			{
				if (_x._tree)
				{
					this->_tree = _copy(this->_tree, _x._tree, this->_end, _allocator);
					this->_count = _x.size();
				}
			}

			_Base_ptr insert(const _Val& _value)
			{
				_Base_ptr ret = search(this->_tree, _value);
				if (!ret)
				{
					this->_tree = _add_with_balance(this->_tree, _value, this->_tree, _allocator);
					_Base_ptr max = _tree->_maximum(_tree);
					this->_tree->parent_node = this->_end;
					this->_end->parent_node = max;
					this->_count++;
					ret = search(this->_tree, _value);
				}
				return ret;
			}

			_Base_ptr insert(_Base_ptr pos, const _Val& _value)
			{
				this->_count++;
				if (pos->data.first > _tree->data.first && _value.first < _tree->data.first)
					return _add_with_balance(_tree, _value, _tree, _allocator);
				if (pos->data.first < _tree->data.first && _value.first > _tree->data.first)
					return _add_with_balance(_tree, _value, _tree, _allocator);
				return _add_with_balance(pos, _value, pos, _allocator);
			}
			
			_Base_ptr search(_Base_ptr _node, _Val _value)
			{
				if (!_node)
					return _node;
				else if (_value.first == _node->data.first)
					return _node;
				else if (_value.first > _node->data.first)
					_node = search(_node->right_node, _value);
				else if (_value.first < _node->data.first)
					_node = search(_node->left_node, _value);
				return _node;
			}

			void clear() 
			{
				iterator first = this->begin();
				iterator temp;
				while(first != end())
				{
					temp = first;
					first++;
					_allocator.destroy(temp._M_node);
					_allocator.deallocate(temp._M_node, 1);
				}
				_tree->left_node = _end;
				_tree->right_node = _end;
				_tree = NULL;
				_count = 0;
			}

			int get_balance() { return _get_balance(this->_tree); }

			void delete_node(const _Val& _value) { this->_tree = _delete_node(this->_tree, _value, _allocator); this->_count--; }

			allocator_type get_allocator() { return this->_allocator; }

			const_iterator begin() const { return const_iterator(this->_tree->_minimum(_tree)); }
			
			iterator begin() { return iterator(this->_tree->_minimum(_tree)); }
			
			const_iterator end() const { return const_iterator(this->_end); }
			
			iterator end() { return iterator(this->_end); }

			reverse_iterator rbegin() { return reverse_iterator(end() - 1); }

			const_reverse_iterator rbegin() const { return const_reverse_iterator(end() - 1); }

			reverse_iterator rend() { return reverse_iterator(begin()); }

			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

			bool empty() { return this->_count == 0; }

			size_type size() const { return this->_count; }

			size_type max_size() const { return this->_allocator.max_size(); }

			_Base_ptr lower_bound(const value_type& _value)
			{
				return _lower_bound(_tree, _value.first);
			}

			_Base_ptr lower_bound(const value_type& _value) const
			{
				return _lower_bound(_tree, _value.first);
			}

			_Base_ptr upper_bound(const value_type& _value)
			{
				return _upper_bound(_tree, _value.first);
			}

			_Base_ptr upper_bound(const value_type& _value) const
			{
				return _upper_bound(_tree, _value.first);
			}
			
			// void swap(avl_tree& other)
			// {

			// }

			~avl_tree()
			{
				//clear();
			}
	};
};

#endif