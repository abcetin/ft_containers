// #include "tree/avl_tree.hpp"
#include <map>
#include <iostream>
#include "map.hpp"


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
	std::map<char,int> mymap2;
	ft::map<char, int> tmp;
	typedef ft::pair<char,int> pr;
	tmp.insert(ft::pair<char, int>('c', 100));
	tmp.insert(ft::pair<char, int>('b', 200));
	tmp.insert(ft::pair<char, int>('a', 300));
	tmp.insert(ft::pair<char, int>('d', 400));
	tmp.insert(ft::pair<char, int>('p', 500));
	tmp.insert(ft::pair<char, int>('A', 600));
	tmp.insert(ft::pair<char, int>('B', 700));
	tmp.insert(ft::pair<char, int>('C', 800));
	ft::map<char, int> tmp2;
	tmp2 = tmp;
	ft::map<char, int>::iterator it = tmp2.begin();
	// it++;
	// it++;
	// it++;
	// it++;
	// it++;
	// it++;
	it = tmp2.insert(it, ft::pair<char, int>('z', 900));
	std::cout << "it : " << it._M_node->data.first << std::endl;
	//print_tree(tmp2._M_t._tree, "root");
	tmp2['e'];
	for (ft::map<char, int>::iterator it = tmp2.begin(); it != tmp2.end(); it++)
	{
		std::cout << it._M_node->data.first << std::endl;
	}
	print_tree(tmp2._M_t._tree, "root");
	// std::cout << "-----------------------\n";
	// print_tree(tmp._M_t._tree, "root");
	//std::cout << "at : "<<tmp2.at('B') << std::endl;
  	mymap['c'] = 100;
  	mymap['b'] = 200;
  	mymap['a'] = 300;
	mymap['d'] = 400;
	mymap['p'] = 500;
	mymap['A'] = 600;
	mymap['B'] = 700;
	mymap['C'] = 800;
	std::map<char,int>::iterator i1;
	i1 = mymap.insert(mymap.begin(), std::pair<char,int>('z',900) );
	std::cout << "i1 : "<<i1->first << std::endl;
	mymap['e'] = 10;
  	// // mymap['e'] = 500;
  	// // mymap['f'] = 600;
	// // mymap['g'] = 700;
  	// // mymap['h'] = 800;
  	// // mymap2['z'] = 100;
	// // mymap2['y'] = 200;
	// // mymap2['x'] = 300;
	// // mymap2['w'] = 400;
	// // mymap2['l'] = 500;
	// std::map<char,int>::iterator it1 = mymap.begin();
	// mymap2.insert(it1, mymap.end());

	// // for (std::map<char,int>::iterator it=mymap.end(); it!=mymap.begin(); --it)
   	// // 	std::cout << it->first << " => " << it->second << '\n';
	 for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
    	std::cout << it->first << " => " << it->second << '\n';

	tmp2.clear();
	// std::cout << "------------------\n";
	//  for (std::map<char,int>::iterator it=mymap2.begin(); it!=mymap2.end(); it++)
    // 	std::cout << it->first << " => " << it->second << '\n';
}