// #include "tree/avl_tree.hpp"
#include <map>
#include <iostream>
#include "map.hpp"

// void print_tree(ft::node<int> *avl, std::string str)
// {
// 	if (avl == NULL)
// 		return;
// 	std::cout << str << " " << avl->data << " ";
// 	if (avl->parent_node)
// 		std::cout << "parent :"<<avl->parent_node->data;
// 	std::cout << std::endl;
// 	print_tree(avl->left_node, str + " left");
// 	print_tree(avl->right_node, str + " right");
// }

int main()
{
	// ft::avl_tree<int, > tree;
	// ft::node<int> *temp;
	// tree.insert(11);
	// tree.insert(10);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// // std::cout << "node : " << tree._tree->data << std::endl;
	// // temp  = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// // tree.insert(20);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// // std::cout << "node : " << tree._tree->data << std::endl;
	// // temp = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// // tree.insert(30);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// // std::cout << "node : " << tree._tree->data << std::endl;
	// // temp = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// // tree.insert(25);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// // std::cout << "node : " << tree._tree->data << std::endl;
	// // temp = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// // tree.insert(30);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// // std::cout << "node : " << tree._tree->data << std::endl;
	// // temp = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// // tree.insert(22);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// // std::cout << "node : " << tree._tree->data << std::endl;
	// // temp = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// // tree.insert(50);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// // std::cout << "node : " << tree._tree->data << std::endl;
	// // temp = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// // tree.insert(60);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// // std::cout << "node : " << tree._tree->data << std::endl;
	// // temp = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// // tree.insert(70);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// // std::cout << "node : " << tree._tree->data << std::endl;
	// // temp = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// // tree.insert(80);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// // std::cout << "node : " << tree._tree->data << std::endl;
	// // temp = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// // tree.insert(90);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// // std::cout << "node : " << tree._tree->data << std::endl;
	// // temp = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// // tree.insert(100);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// // std::cout << "node : " << tree._tree->data << std::endl;
	// // temp = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// // std::cout << "delete" << std::endl;
	// // tree._delete_node(80);
	// // std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	 
	// // temp = tree._tree;
	// // print_tree(temp->left_node, "left");
	// // print_tree(temp->right_node, "right");
	// // std::cout << "----------------------------\n";
	// tree.insert(13);
	// tree.insert(14);
	// tree.insert(9);
	// tree.insert(8);
	// tree.insert(7);
	// tree.insert(6);
	// tree.insert(5);
	// std::cout << "node : " << tree._tree->data << " node parent " << tree._tree->parent_node->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// tree.delete_node(5);
	// ft::avl_tree<int>::iterator iter = tree.begin();
	// while (iter != tree.end())
	// {
	// 	std::cout << "iter "<< *iter << std::endl;
	// 	iter++;
	// }
	// std::cout << "----------------------------\n";
	// ft::avl_tree<int>::iterator iter1 = tree.begin();
	// // std::cout<< *iter << std::endl;
	// // iter--;
	// while (iter != iter1)
	// {
	// 	std::cout<< *iter << std::endl;
	// 	iter--;
	// }
	
	
	std::map<char,int> mymap;
	ft::map<char, int> tmp;
	tmp.insert({'a', 1});
  	mymap['a'] = 100;
  	mymap['b'] = 200;
  	// mymap['c'] = 300;
	// mymap['d'] = 400;
  	// mymap['e'] = 500;
  	// mymap['f'] = 600;
	// mymap['g'] = 700;
  	// mymap['h'] = 800;
  	// mymap['i'] = 900;
	std::map<char,int>::iterator it1 = mymap.end();
	it1 = mymap.insert(it1, std::pair<char, int>('c', 100));
	std::cout << it1->first << std::endl;

	// for (std::map<char,int>::iterator it=mymap.end(); it!=mymap.begin(); --it)
   	// 	std::cout << it->first << " => " << it->second << '\n';
	 for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
    std::cout << it->first << " => " << it->second << '\n';
}