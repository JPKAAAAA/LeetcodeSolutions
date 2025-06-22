//14-08-23


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)
        return list2;
        else if(list2==nullptr)
        return list1;
        ListNode *head=nullptr,*temp,*temp1,*temp2;
        temp1=list1;
        temp2=list2;
        while(temp1!=nullptr&&temp2!=nullptr)
        {
            ListNode *newNode=new ListNode;
             if(head==nullptr)
            {
            head=newNode;
            temp=newNode;
            }
            else
            {
            temp->next=newNode;
            temp=newNode;
            }
            if(temp1->val<temp2->val)
            {
                newNode->val=temp1->val;
                temp1=temp1->next;
            }
            else
            {
                newNode->val=temp2->val;
                temp2=temp2->next;
            }
            
        }
        while(temp1!=nullptr)
        {
            ListNode *newNode=new ListNode;
            newNode->val=temp1->val;
            temp1=temp1->next;
             temp->next=newNode;
            temp=newNode;
        }
        while(temp2!=nullptr)
        {
            ListNode *newNode=new ListNode;
            newNode->val=temp2->val;
             temp->next=newNode;
            temp=newNode;
        }
        return head;
    }
};