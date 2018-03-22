#include <iostream>
#include <vector>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x,  TreeNode *lp = nullptr, TreeNode *rp = nullptr) : val(x), left(lp), right(rp) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;

        auto* curr = root;
        while(curr != nullptr) {
          //cout << "Current " << curr->val << "\n";
          if(curr->left != nullptr) {
            //go to the right most on the left branch and set he pointer
            // or break the pointer move to the right branch
            auto* rightmost = curr->left;
            while((rightmost->right != nullptr)&&(rightmost->right != curr)) {
              rightmost = rightmost->right;
            }
            if(rightmost->right == curr) {//break the link
              //cout << "Breaking Link " << "\n";
              res.push_back(curr->val);
              curr = curr->right;
            }
            else {// it is null; make the link
              //cout << "Making Link " << "\n";
              rightmost->right = curr;
              curr = curr->left;
            }
          }
          else { // this the left most in the branch
            res.push_back(curr->val);
            curr = curr->right;
          }
        }
        return res;
    }
};
int main () {

  auto root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(30);
  root->left->left = new TreeNode(-2);
  root->left->right = new TreeNode(6);
  root->right->right = new TreeNode(40);
  root->left->left->right = new TreeNode(2);
  root->left->right->right = new TreeNode(8);
  root->left->left->right->left = new TreeNode(-1);

  Solution solver;
  auto&& ordered_vec = solver.inorderTraversal(root);
  cout << "Output: ";
  for (auto& elem : ordered_vec) {
    cout << elem << " ";
  }
  cout << "\n";

  root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  ordered_vec = solver.inorderTraversal(root);
  cout << "Output: ";
  for (auto& elem : ordered_vec) {
    cout << elem << " ";
  }
  cout << "\n";

  return 0;
}
