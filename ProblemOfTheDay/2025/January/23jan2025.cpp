//Count Servers that Communicate

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rowCounts(grid[0].size(), 0), colCounts(grid.size(), 0);
        for (int row = 0; row < grid.size(); ++row)
            for (int col = 0; col < grid[0].size(); ++col)
                if (grid[row][col]) {
                    rowCounts[col]++;
                    colCounts[row]++;
                }
        int communicableServersCount = 0;
        for (int row = 0; row < grid.size(); ++row)
            for (int col = 0; col < grid.size(); ++col)
                if (grid[row][col])
                    communicableServersCount += rowCounts[col] > 1 || colCounts[row] > 1;
        return communicableServersCount;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid{{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    cout<<s.countServers(grid);
    return 0;
}