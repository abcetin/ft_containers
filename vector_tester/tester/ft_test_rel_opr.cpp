#include <iostream>
#include "../../vector/vector.hpp"

int main ()
{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "1 foo and bar are equal\n";
  if (foo!=bar) std::cout << "2 foo and bar are not equal\n";
  if (foo< bar) std::cout << "3 foo is less than bar\n";
  if (foo> bar) std::cout << "4 foo is greater than bar\n";
  if (foo<=bar) std::cout << "5 foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "6 foo is greater than or equal to bar\n";

  return 0;
}
