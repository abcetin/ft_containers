#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "../iterator.hpp"
#include "rotation.hpp"
#include "insert_delete.hpp"

namespace ft
{
	//new leri allocator olarak güncelle!!!!!!!!!!!!!  
	template <typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Allocator = std::allocator<_Val> > 
	class avl_tree
	{	
		typedef typename _Allocator::template rebind<node<_Val> >::other _Node_allocator;

		protected:
			typedef ft::node<_Val>* _Base_ptr;
			typedef const ft::node<_Val>* _Const_base_ptr;
		
		public:
			typedef _Key								key_type;
			typedef _Val								value_type;
			typedef value_type*							pointer;
			typedef const value_type*					const_pointer;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef node<_Val>*							_Link_type;
			typedef const node<_Val>*					_Const_link_type;
			typedef size_t								size_type;
			typedef ptrdiff_t							difference_type;
			typedef _Allocator							allocator_type;
			typedef const ft::tree_iterator<_Val>		const_iterator;
			typedef ft::tree_iterator<_Val>				iterator; // const_iterator yap sonra
			typedef iterator							const_reverse_iterator; //hepsinin const olmasının sebebi ağaçta verilerin yeniden atanmasını istemiyoruz.
			typedef const_iterator						reverse_iterator;		//avl_ağaç yapısını bozabileceği için eğer atama iterator ile yapılırsa hatalı çalışmalara sebep olabilir.
			
			_Base_ptr _tree;
			_Base_ptr _start;
			_Base_ptr _end;

		public:

			avl_tree(): _tree(), _start(){ this->_end = new node<_Key>(0); /*allocator ile değiştir*/}
			
			void insert(const _Key& _value)
			{	
				_Base_ptr max = _tree->_maxmimum(_tree);
				this->_tree = add_with_balance(this->_tree, _value, this->_tree);
				this->_tree->parent_node = this->_end;
				this->_end->parent_node = max;
			}
			
			_Base_ptr search(_Base_ptr _node, const _Key& _value)
			{
				if (!_node)
					return _node;
				if (_value == _node->data)
					return _node;
				if (_value >= _node->data)
					_node = search(_node->right_node, _value);
				else if (_value < _node->data)
					_node = search(_node->left_node, _value);
				return _node;
			}

			int get_balance()
			{
				return _get_balance(this->_tree);
			}

			void delete_node(const _Key& _value)
			{
				this->_tree = _delete_node(this->_tree, _value);
			}
		
			const_iterator begin() const
			{
				return const_iterator(this->_tree->_minimum(_tree));
			}
			
			iterator begin()
			{
				return iterator(this->_tree->_minimum(_tree));
			}
			
			const_iterator end() const //end nullptr döndürür
			{
				
				return const_iterator(this->_end);
			}
			
			iterator end() //end nullptr döndürür
			{
				return iterator(this->_end);
			}
			
			~avl_tree()
			{
				// while(_tree)
				// {
				// 	_delete_node(_tree->data);
				// }
			}
	};
};

#endif