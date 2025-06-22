/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *ptr;
        ptr=head;
        int *a=new int;
        int *b=new int;
        int i=0,j=0,count=0;
        while(ptr!=NULL)
        {
            *(a+i)=ptr->val;
            ptr=ptr->next;
            i++;
        }
        for(i=i-1;i>=0;i--,j++)
        {
            *(b+j)=*(a+i);
        }
        for(j=j-1;j>=0;j--)
        if(*(a+i)!=*(b+i))
        {
            count++;
            break;
        }
        if(count==0)
        return true;
        else 
        return false;
        
    }
};