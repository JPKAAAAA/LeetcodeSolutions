//First Completely Painted Row or Column

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < arr.size(); i++) {
            numToIndex[arr[i]] = i;
        }
        int result = INT_MAX;
        int numRows = mat.size();
        int numCols = mat[0].size();
        for (int row = 0; row < numRows; row++) {
            int lastElementIndex = INT_MIN;
            for (int col = 0; col < numCols; col++) {
                int indexVal = numToIndex[mat[row][col]];
                lastElementIndex = max(lastElementIndex, indexVal);
            }
            result = min(result, lastElementIndex);
        }
        for (int col = 0; col < numCols; col++) {
            int lastElementIndex = INT_MIN;
            for (int row = 0; row < numRows; row++) {
                int indexVal = numToIndex[mat[row][col]];
                lastElementIndex = max(lastElementIndex, indexVal);
            }
            result = min(result, lastElementIndex);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> arr{2,8,7,4,1,3,5,6,9};
    vector<vector<int>> mat{{3,2,5},{1,4,6},{8,7,9}};
    cout<<s.firstCompleteIndex(arr,mat);
    return 0;
}