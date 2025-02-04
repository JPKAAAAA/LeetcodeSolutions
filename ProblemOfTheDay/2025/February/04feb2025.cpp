//Maximum Ascending Subarray Sum (EASY)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        int sum=nums[0];
        int ans=sum;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                sum=sum+nums[i];
            }
            else
            {
                ans=max(ans,sum);
                sum=nums[i];
            }
        }
        ans=max(ans,sum);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr{12,17,15,13,10,11,12};
    cout<<s.maxAscendingSum(arr);
    return 0;
}