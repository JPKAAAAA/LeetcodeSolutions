//22-08-23


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
         int lo = 0, hi = int(nums.size()) - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo == hi && nums[lo] == target ? lo : -1;
    }
};

int main()
{
    system("cls");
    vector<int> nums={12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    Solution s;
    cout<<s.search(nums,17);
    return 0;
}