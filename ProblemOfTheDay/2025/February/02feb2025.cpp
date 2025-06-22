//Check if Array Is Sorted and Rotated (EASY)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
        return true;
        int count=0;
        for(int i=1;i<n;i++)    //for(int i=1;i<=n;i++)
            if(nums[i]<nums[i-1])   //if(nums[i%n]<nums[(i-1)%n])
                count++;
        if(nums[0]<nums[n-1])   //remove this line
        count++;    //remove this line
        return count<=1;
    }
    /*
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> checkSorted(n);
        for (int rotationOffset = 0; rotationOffset < n; ++rotationOffset) {
            int currIndex = 0;
            for (int index = rotationOffset; index < n; ++index) {
                checkSorted[currIndex++] = (nums[index]);
            }
            for (int index = 0; index < rotationOffset; ++index) {
                checkSorted[currIndex++] = (nums[index]);
            }
            bool isSorted = true;
            for (int index = 0; index < n - 1; ++index) {
                if (checkSorted[index] > checkSorted[index + 1]) {
                    isSorted = false;
                    break;
                }
            }
            if (isSorted) {
                return true;
            }
        }
        return false;
    }
    */
    /*
    bool check(vector<int>& nums) {
        int size = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        for (int rotationOffset = 0; rotationOffset < size; ++rotationOffset) {
            bool isMatch = true;
            for (int index = 0; index < size; ++index) {
                if (nums[(rotationOffset + index) % size] !=
                    sortedNums[index]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                return true;
            }
        }
        return false;
    }
    */
};

int main() {
    vector<int> arr{7,9,1,1,1,3};
    Solution s;
    cout<<s.check(arr);
    return 0;
}