//Maximum Number of Fish in a Grid (MEDIUM)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int helper(vector<vector<int>> &grid,vector<vector<bool>> &v,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || v[i][j])
        return 0;
        v[i][j]=true;
        return grid[i][j]+helper(grid,v,i,j+1)+helper(grid,v,i,j-1)+helper(grid,v,i+1,j)+helper(grid,v,i-1,j);
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int count=0;
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]>0 && !vis[i][j])
                count=max(count,helper(grid,vis,i,j));
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<vector<int>> arr{{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    cout<<s.findMaxFish(arr);
    return 0;
}