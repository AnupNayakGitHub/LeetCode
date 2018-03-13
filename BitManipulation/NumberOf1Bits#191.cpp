#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
    }
};

int main() {
  uint32_t orig = 12324321;
  Solution solver;
  auto setbits = solver.hammingWeight(orig);
  std::cout << "Original bits are " << std::bitset<32>(orig) << std::endl;
  std::cout << "Hamming weight is " << setbits << std::endl;
}
