#include <iostream>
#include <bitset>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t rev {0};
      uint32_t mask = 1;
      do{
        rev <<= 1;
        rev |= (n&0x1);
        n >>= 1;
      }while(mask <<= 1);
      return rev;        
    }
};

int main() {
  uint32_t orig = 12324321;
  Solution solver;
  auto rev = solver.reverseBits(orig);
  std::cout << "Original bits are " << std::bitset<32>(orig) << std::endl;
  std::cout << "Original bits are " << std::bitset<32>(rev) << std::endl;
}
