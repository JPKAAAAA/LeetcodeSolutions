//17-08-23
//remove duplicate from sorted Array


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        int k = 1;  
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                ++k;
            }
        }
        
        return k;
    }
};

int main()
{
    system("cls");
    vector<int> num={5,0,0,0,0,0,4,4,1,1,1,1,3,3,3};
    Solution s;
    cout<<"No. of distinct Elements: "<<s.removeDuplicates(num);
    return 0;

}