//16-08-23


#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
         if(head == NULL || head -> next == NULL) 
        {
            return head;
        }
            
        ListNode* temp; 
        temp = head->next; 
        
        head->next = swapPairs(head->next->next); 
        temp->next = head;
        return temp; 
    }
};


int main()
{
    system("cls");
    ListNode l[5];
    Solution s;
    for(int i=0;i<5;i++)
    {   
        if(i==4)
        l[i]=ListNode(10*i+10,nullptr);
        l[i]=ListNode(10*i+10,&l[i+1]);
    }
    // s.swapPairs(l[0]);
}