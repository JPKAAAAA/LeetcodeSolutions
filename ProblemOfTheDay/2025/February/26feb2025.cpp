//Maximum Absolute Sum of Any Subarray (MEDIUM)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int minPrefixSum = INT_MAX, maxPrefixSum = INT_MIN;
            int prefixSum = 0, maxAbsSum = 0;
            for (int i = 0; i < nums.size(); i++) {
                prefixSum += nums[i];
                minPrefixSum = min(minPrefixSum, prefixSum);
                maxPrefixSum = max(maxPrefixSum, prefixSum);
                if (prefixSum >= 0) {
                    maxAbsSum = max(maxAbsSum, max(prefixSum, prefixSum - minPrefixSum));
                } else if (prefixSum <= 0) {
                    maxAbsSum = max(maxAbsSum, max(abs(prefixSum), abs(prefixSum - maxPrefixSum)));
                }
            }
            return maxAbsSum;
        }
};
/*
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPrefixSum = 0, maxPrefixSum = 0;
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);
        }
        return maxPrefixSum - minPrefixSum;
    }
};
*/
int main() {
    Solution s;
    vector<int> arr{2,-5,1,-4,3,-2};
    cout<<s.maxAbsoluteSum(arr);
    return 0;
}