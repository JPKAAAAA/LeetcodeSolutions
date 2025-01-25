//Make Lexicographically Smallest Array by Swapping Elements

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> ans(nums);
        sort(ans.begin(),ans.end());
        int c=0;
        unordered_map<int,int> mp1;
        unordered_map<int,list<int>> mp2;
        mp1.insert({ans[0],c});
        mp2.insert({c,list<int>(1,ans[0])});
        for(int i=1;i<nums.size();i++)
        {
            if(abs(ans[i]-ans[i-1])>limit)
            c++;
            mp1.insert({ans[i],c});
            if(mp2.find(c)==mp2.end())
            mp2[c]=list<int>();
            mp2[c].push_back(ans[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            int y=mp1[x];
            nums[i]=*mp2[y].begin();
            mp2[y].pop_front();
        }
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,7,6,18,2,1};
    vector<int> ans=s.lexicographicallySmallestArray(nums,3);
    for(auto i:ans)
    cout<<i<<"  ";
    return 0;
}