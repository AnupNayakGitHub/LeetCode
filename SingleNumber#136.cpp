#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0, std::bit_xor<int>());
    }
};

int main() {
  vector<int> data {0, 0, 0, 0, 1};
  Solution solver;
  auto ret = solver.singleNumber(data);
  std::cout << "Single number is " << ret << std::endl;
  return 0;
}
