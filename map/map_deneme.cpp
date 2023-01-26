// #include "tree/avl_tree.hpp"
#include <map>
#include <iostream>
#include "map.hpp"


int main()
{		
	// std::map<char,int> mymap;
	// std::map<char,int> mymap2;
	// ft::map<char, int> tmp;
	// tmp.insert(ft::pair<char, int>('c', 100));
	// tmp.insert(ft::pair<char, int>('b', 200));
	// tmp.insert(ft::pair<char, int>('a', 300));
	// tmp.insert(ft::pair<char, int>('d', 400));
	// tmp.insert(ft::pair<char, int>('p', 500));
	// tmp.insert(ft::pair<char, int>('A', 600));
	// tmp.insert(ft::pair<char, int>('B', 700));
	// tmp.insert(ft::pair<char, int>('C', 800));
	// ft::map<char, int> tmp2;
	// tmp2 = tmp;
	// ft::map<char, int>::iterator it = tmp2.begin();
	// // it++;
	// // it++;
	// // it++;
	// // it++;
	// // it++;
	// // it++;
	// it = tmp2.insert(it, ft::pair<char, int>('z', 900));
	// std::cout << "it : " << it->first << std::endl;
	// //print_tree(tmp2._M_t._tree, "root");
	// tmp2['e'] = 10;
	// int i = 0;
	// tmp2.size();
	// for (ft::map<char, int>::iterator it = tmp2.begin(); it != tmp2.end(); it++)
	// {
	// 	i++;
	// 	std::cout << it->first << std::endl;
	// }
	//print_tree(tmp2._M_t._tree, "root");
	// std::cout << "-----------------------\n";
	// print_tree(tmp._M_t._tree, "root");
	//std::cout << "at : "<<tmp2.at('B') << std::endl;
  	// mymap['c'] = 100;
  	// mymap['b'] = 200;
  	// mymap['a'] = 300;
	// mymap['d'] = 400;
	// mymap['p'] = 500;
	// mymap['A'] = 600;
	// mymap['B'] = 700;
	// mymap['C'] = 800;
	// std::map<char,int>::iterator i1;
	// i1 = mymap.insert(mymap.begin(), std::pair<char,int>('z',900) );;
	// std::cout << "i1 : "<<i1->first << std::endl;
	// mymap['e'] = 10;
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
// 	ft::map<char, int> tmp3;
// 	tmp3['a'] = 100;
// 	//tmp3.insert(tmp2.begin(), tmp2.end());
// 	 for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
//     	std::cout << "std " << it->first << " => " << it->second << '\n';
// 	std::cout << "---------------------\n";
// 	for (ft::map<char,int>::iterator it=tmp2.begin(); it!=tmp2.end(); it++)
//     	std::cout <<"ft tmp2 " << it->first << " => " << it->second << '\n';
// std::cout << "---------------------\n";
// 	for (ft::map<char,int>::iterator it=tmp3.begin(); it!=tmp3.end(); it++)
//     	std::cout <<"ft tmp3 " << it->first << " => " << it->second << '\n';
// 	std::cout << "tmp "<< tmp2.max_size() << std::endl;
// 	std::cout << "mymap "<< mymap.max_size() << std::endl;
	//print_tree(tmp2._M_t._tree, "before clear");
	//std::cout << tmp2.erase('.') << std::endl;
	//print_tree(tmp2._M_t._tree, "after clear");
	// std::cout << "------------------\n";
	//  for (std::map<char,int>::iterator it=mymap2.begin(); it!=mymap2.end(); it++)
    // 	std::cout << it->first << " => " << it->second << '\n';
 
    // insert elements in random order
	ft::map<int, char> a;
	ft::map<int, char> b;
	ft::map<int, char> c;
	for (size_t i = 0; i < 10; i++)
	{
		a.insert(ft::make_pair(i, i + 65));
	}
	b = a;
	for (size_t i = 0; i < 10; i++)
	{
		c.insert(ft::make_pair(i, i + 65));
	}
	b = c;
	for(ft::map<int, char>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	// for(ft::map<int, char>::iterator it = a.end(); it != a.begin(); --it)
	// 	std::cout << it->first << " " << it->second << std::endl;
}