#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//Node structure changed little bit to easily create test data
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode *l = nullptr, TreeNode *r = nullptr) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vov{};
        if(root == nullptr) return vov;
        queue<TreeNode*> nodeq;
        nodeq.push(root);
        while(!nodeq.empty()){
          vector<int> lvl{};
          for(int remaining = nodeq.size(); remaining > 0; remaining--) {
            lvl.push_back(nodeq.front()->val);
            if(nodeq.front()->left)nodeq.push(nodeq.front()->left);
            if(nodeq.front()->right)nodeq.push(nodeq.front()->right);
            nodeq.pop();
          }
          //used move syntax
          vov.push_back(move(lvl));
        }
        return vov;
    }
};

void print_vov(vector<vector<int>>& vov) {
  cout << "[";
  for (auto& inner : vov) {
    cout << "\n [";
    for(auto& elem : inner){
      cout << elem << " ";
    }
    cout << "]";
  }
  cout << "\n]\n";
}
int main(){
  TreeNode* data = new TreeNode(3,new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  Solution solver;
  auto&& result = solver.levelOrder(data);
  print_vov(result);
  return 0;
}
