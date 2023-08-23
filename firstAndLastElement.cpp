//23-08-23
//Find First and Last Position of Element in Sorted Array


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = lower_bound(nums, target);
    int idx2 = lower_bound(nums, target+1)-1;
    if (idx1 < nums.size() && nums[idx1] == target)
        return {idx1, idx2};
    else
        return {-1, -1};
}

int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
        int mid = (r-l)/2+l;
        if (nums[mid] < target)
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}
};

int main()
{
    system("cls");
    Solution s;
    vector<int> num={1,1,2,2,3,4,4,5,6,6,7};
    vector<int> ans=s.searchRange(num,6);
    for(auto i:ans)
    cout<<i<<" ";
    return 0;
}