//Count Number of Bad Pairs (MEDIUM)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    long long countBadPairs(vector<int>& nums) {
        long long badPairs = 0;
        unordered_map<int, int> diffCount;
        for (int pos = 0; pos < nums.size(); pos++) {
            int diff = pos - nums[pos];
            int goodPairsCount = diffCount[diff];
            badPairs += pos - goodPairsCount;
            diffCount[diff] = goodPairsCount + 1;
        }
        return badPairs;
    }
};

int main() {
    Solution s;
    vector<int> arr={4,1,3,3};
    cout<<s.countBadPairs(arr);
    return 0;
}