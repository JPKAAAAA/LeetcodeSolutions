//Merge Two 2D Arrays by Summing Values (EASY)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int N1 = nums1.size(), N2 = nums2.size();
            int ptr1 = 0, ptr2 = 0;
            vector<vector<int>> mergedArray;
            while (ptr1 < N1 && ptr2 < N2) {
                if (nums1[ptr1][0] == nums2[ptr2][0]) {
                    mergedArray.push_back({nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]});
                    ptr1++;
                    ptr2++;
                } else if (nums1[ptr1][0] < nums2[ptr2][0]) {
                    mergedArray.push_back(nums1[ptr1]);
                    ptr1++;
                } else {
                    mergedArray.push_back(nums2[ptr2]);
                    ptr2++;
                }
            }
            while (ptr1 < N1) {
                mergedArray.push_back(nums1[ptr1]);
                ptr1++;
            }
            while (ptr2 < N2) {
                mergedArray.push_back(nums2[ptr2]);
                ptr2++;
            }
            return mergedArray;
        }
};

int main() {
    Solution s;
    vector<vector<int>> arr1{{2,4},{3,6},{5,5}},arr2{{1,3},{4,3}};
    vector<vector<int>> ans=s.mergeArrays(arr1,arr2);
    for(auto i:arr1) {
        for(auto j:i)
            cout<<j<<"  ";
    cout<<endl;
    }
    cout<<endl;
    for(auto i:arr2) {
        for(auto j:i)
            cout<<j<<"  ";
    cout<<endl;
    }
    cout<<endl;
    for(auto i:ans) {
        for(auto j:i)
            cout<<j<<"  ";
    cout<<endl;
    }
    return 0;
}