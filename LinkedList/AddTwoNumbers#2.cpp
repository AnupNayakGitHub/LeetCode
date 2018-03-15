/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void print(ListNode* l) {
  ListNode* curr = l;
  cout << "(";
  while(curr != nullptr) {
    cout << curr->val;
    curr = curr->next;
    if(curr) cout << "->";
  }
  cout << ")\n";
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy{0};
        auto next = &dummy;
        int carry{0};
        while(l1 || l2){
            carry += ((l1)?l1->val:0) + ((l2)?l2->val:0); 
            next = next->next = new ListNode(carry%10);
            carry /= 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry)
            next->next = new ListNode(carry);
        return dummy.next;
    }
};

int main(){
  ListNode* l1 = new ListNode(2);
  ListNode* curr = l1;
  curr->next = new ListNode(4);
  curr = curr->next;
  curr->next = new ListNode(3);


  ListNode* l2 = new ListNode(5);
  curr = l2;
  curr->next = new ListNode(6);
  curr = curr->next;
  curr->next = new ListNode(4);

  print(l1);
  print(l2);
  Solution solver;
  ListNode* res = solver.addTwoNumbers(l1, l2);
  print(res);
  
  return 0;
}
