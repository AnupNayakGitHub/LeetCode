#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Note that the logic is not O(n) complexity as expected in the problem
// statement. The Result actually beat the 99.92% of submissions.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       if(nums.empty()) return 0;

       sort(nums.begin(), nums.end()); 
       nums.erase( unique( nums.begin(), nums.end() ), nums.end() );

       int max = 1;
       for (int i = 1; i < nums.size(); i++){
         if ((nums[i] - nums[i-max]) == max)
           max++;
       }
       return max;
    }
};
int main() {
  vector<int> data {-1, 100, 4, 4, 200, 1, 3, 2};

  Solution solver;
  auto ret = solver.longestConsecutive(data);
  cout << "Longest Consecutive Sequence is " << ret << endl;
  return 0;
}
