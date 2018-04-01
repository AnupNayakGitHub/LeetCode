#include "MyTemplate.h"
#include <iostream>

extern template class MyTemplate<int>;

int main() {
  MyTemplate<int> v;
  v.push_back(1);
  std::cout << v[0] << std::endl;
  return 0;
}
