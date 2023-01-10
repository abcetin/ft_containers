#include "avl_tree.hpp"

void print_tree(ft::node<int> *avl, std::string str)
{
	if (avl == NULL)
	{
		return;
	}
	std::cout << str << " " << avl->data << std::endl;
	print_tree(avl->left_node, str + " left");
	print_tree(avl->right_node, str + " right");
}

int main()
{
	ft::avl_tree<int> tree;
	ft::node<int> *temp;
	tree.insert(10);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp  = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// tree.insert(20);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// tree.insert(30);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// tree.insert(25);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// tree.insert(30);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// tree.insert(22);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// tree.insert(50);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// tree.insert(60);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// tree.insert(70);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// tree.insert(80);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// tree.insert(90);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// tree.insert(100);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	// std::cout << "delete" << std::endl;
	// tree._delete_node(80);
	// std::cout << "balance " << tree.get_balance(tree._tree) << std::endl;
	// std::cout << "node : " << tree._tree->data << std::endl;
	// temp = tree._tree;
	// print_tree(temp->left_node, "left");
	// print_tree(temp->right_node, "right");
	// std::cout << "----------------------------\n";
	tree.insert(13);
	tree.insert(14);
	tree.insert(1);
	tree.insert(0);
	tree.insert(-1);
	tree.insert(-1);
	tree.insert(-1);

	ft::avl_tree<int>::iterator iter = tree.begin();

	std::cout << *iter << std::endl;
}