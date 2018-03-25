// Given an array of n integers where n > 1, nums, return an array output such that
// output[i] is equal to the product of all the elements of nums except nums[i].
// Solve it without division and in O(n).
// For example, given [1,2,3,4], return [24,12,8,6].

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int accum = 1;
        for (auto& val : nums){
            res.push_back(accum);
            accum *= val;
        }
        accum = 1;
        std::vector<int>::reverse_iterator rit = nums.rbegin();
        std::vector<int>::reverse_iterator rit_res = res.rbegin();
        while(rit != nums.rend()){
            (*rit_res) *= accum;
            accum *= (*rit);
            ++rit;
            ++rit_res;
        }
        return res;
    }
};
void print_vec(vector<int>& nums){
  cout<<"[";
  for(auto& elem : nums) {
    cout<<elem <<" ";
  }
  cout<<"]\n";
}

int main(){
  vector<int> data = {1, 2, 3, 4};
  cout<<"Data : ";
  print_vec(data);
  Solution solver;
  auto res = solver.productExceptSelf(data);
  cout<<"Result : ";
  print_vec(res);
  return 0;
}
