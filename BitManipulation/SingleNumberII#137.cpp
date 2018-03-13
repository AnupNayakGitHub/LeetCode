#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int carry = 0;
        int val = 0;
        for (auto num : nums) {
            carry ^= (val & num);
            val ^= num;
            auto mask = ~(val & carry);
            val &= mask;
            carry &= mask;
        }
        return val;
    }
};

int main() {
  vector<int> data {2, 2, 3, 2};
  Solution solver;
  auto ret = solver.singleNumber(data);
  std::cout << "Single number is " << std::bitset<32>(ret) << std::endl;
  return 0;
}
