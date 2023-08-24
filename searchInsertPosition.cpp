//24-08-23


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int mid;
        while(end>=start)
        {
            mid=start+(end-start)/2;
            if(nums[mid]==target)
            return mid;
            else if(target>nums[mid])
            start=mid+1;
            else if(target<nums[mid])
            end=mid-1;
        }
        return (target>nums[mid])?mid+1:mid;
        
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> num={1,3,5,6};
    cout<<s.searchInsert(num,7);
    return 0;
}