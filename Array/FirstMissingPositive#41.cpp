#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ){
          int val = nums[i];
          if((val > 0) & (val <= nums.size()) & (nums[val-1] != val)) {
            int temp = nums[val-1];
            nums[val-1] = val;
            nums[i] = temp;
          }
          else i++;
        }
        int match = 1;
        for (auto num: nums) {
          if (num > 0) {
            if (num != match)
              return match;
            match++;
          }
        }
        return match;
    }
};

int main() {
  vector<int> data {-1,4,2,1,9,10};

  Solution solver;
  auto ret = solver.firstMissingPositive(data);
  std::cout << "First missing positive  number is " << ret << std::endl;
  return 0;
}
