#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "../iterator.hpp"
#include "rotation.hpp"
#include "insert_delete.hpp"
#include "../../utils/reverse_iterator.hpp"

namespace ft
{
	template <typename _Val, typename _Compare, typename _Allocator = std::allocator<_Val> > 
	class avl_tree
	{
		public:
			typedef typename _Allocator::template rebind<node<_Val> >::other	allocator_type;
			typedef _Val														value_type;
			typedef value_type*													pointer;
			typedef const value_type*											const_pointer;
			typedef value_type&													reference;
			typedef const value_type&											const_reference;
			typedef size_t														size_type;
			typedef ptrdiff_t													difference_type;
			typedef const ft::tree_iterator<_Val>								const_iterator;
			typedef ft::tree_iterator<_Val>										iterator;
			typedef ft::reverse_iterator<iterator>								const_reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						reverse_iterator;
			typedef ft::node<_Val>*												_Base_ptr;
			
			_Base_ptr		_tree;
			_Base_ptr		_end;
			size_type		_count;
			_Compare		_key_compare;
			allocator_type	_allocator;
		
		protected:

		_Base_ptr create_node(value_type _value)
		{
			_Base_ptr ret = this->_allocator.allocate(1);
			this->_allocator.construct(ret, _value);
			return ret;
		}

		public:

			avl_tree(): _tree(), _count(0) { this->_end = create_node(_Val());}

			avl_tree(const _Compare& _comp, const allocator_type& _a = allocator_type()) : _key_compare(_comp), _allocator(_a)
			{
				this->_end = create_node(0);
				this->_tree = this->_end;
			}

			avl_tree (const avl_tree& _x) : _key_compare(_x._key_compare), _allocator(_x._get_allocator())
			{
				if (_x._tree)
				{
					this->_tree = _copy(_x._tree, _x.begin(), _x.end());
					this->_end = _x._end;
					this->_count = _x.size();
				}
			}

			node<_Val> *insert(const _Val& _value)
			{
				node<_Val> *ret = create_node(_value);
				this->_tree = add_with_balance(this->_tree, _value, this->_tree);
				_Base_ptr max = _tree->_maxmimum(_tree);
				this->_tree->parent_node = this->_end;
				this->_end->parent_node = max;
				this->_count++;
				return ret;
			}
			
			_Base_ptr search(_Base_ptr _node, const _Val& _value)
			{
				if (!_node)
					return _node;
				if (_value.first == _node->data.first)
					return _node;
				if (_value.first >= _node->data.first)
					_node = search(_node->right_node, _value);
				else if (_value.first < _node->data.first)
					_node = search(_node->left_node, _value);
				return _node;
			}

			int get_balance()
			{
				return _get_balance(this->_tree);
			}

			void delete_node(const _Val& _value)
			{
				this->_tree = _delete_node(this->_tree, _value);
			}

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

			size_type size() { return this->_count; }

			size_type max_size() const { return this->_allocator.max_size(); }
			
			~avl_tree()
			{
				// while(_tree)
				// {
				// 	_delete_node(_tree->data);
				// }
			}

			private:
				_Base_ptr add_with_balance(_Base_ptr _node, const  value_type&_value, _Base_ptr parent)
				{
					if (_node && !_key_compare(_node->data.first, _value.first))
						return _node;
					else if (!_node)
						return create_node(_value);
					else if (_value < _node->data)
						_node->left_node = add_with_balance(_node->left_node, _value, _node);
					else if (_value >= _node->data)
						_node->right_node = add_with_balance(_node->right_node, _value, _node);
					else
						return _node;
					_node->height = 1 + std::max(height(_node->left_node), height(_node->right_node));
					_node = balance(_node);
					return _node;
				}
	};
};

#endif