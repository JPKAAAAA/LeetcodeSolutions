//EASY 27-09-2024

/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num(m+n,10);
        int i=0;
        int j=0;
        int k=0;
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                num[k++]=nums1[i++];
            }
            else
            {
                num[k++]=nums2[j++];
            }
        }
        while(i<m)
        {
            num[k++]=nums1[i++];
        }
        while(j<n)
        {
            num[k++]=nums2[j++];
        }
        for(int i=0;i<m+n;i++)
        nums1[i]=num[i];
    }
};