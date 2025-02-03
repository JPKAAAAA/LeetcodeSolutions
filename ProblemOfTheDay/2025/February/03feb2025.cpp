//Longest Strictly Increasing or Strictly Decreasing Subarray (EASY)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=0,j=1;
        int small=0,big=0;
        int temp=nums[i];
        while(j<=nums.size()){
            if(j<nums.size() && temp<nums[j])
            {
                temp=nums[j];
                j++;
            }
            else
            {
                small=max(small,j-i);
                i=j;
                temp=nums[i];
                j++;
            }
        }
        i=0,j=1;
        temp=nums[i];
        while(j<=nums.size())
        {
            if(j<nums.size() && temp>nums[j])
            {
                temp=nums[j];
                j++;
            }
            else
            {
                big=max(big,j-i);
                i=j;
                temp=nums[i];
                j++;
            }
        }
        return max(small,big);
    }
};

/*
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,dec=1,ans=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                inc++;
                dec=1;
            }
            else if(nums[i]<nums[i-1])
            {
                dec++;
                inc=1;
            }
            else
            {
                inc=dec=1;
            }
            ans=max(ans,max(inc,dec));
        }
        return ans;
    }
};
*/

int main() {
    vector<int> arr{1,4,3,3,2};
    Solution s;
    cout<<s.longestMonotonicSubarray(arr);
    return 0;
}