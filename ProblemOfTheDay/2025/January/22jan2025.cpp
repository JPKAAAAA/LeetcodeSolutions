//Map of Highest Peak

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool valid(pair<int,int> cell,int r,int c){
        return cell.first>=0 && cell.second>=0 && cell.first<r && cell.second<c;
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int x[]={0,0,1,-1};
        int y[]={1,-1,0,0};
        int r=isWater.size();
        int c=isWater[0].size();
        vector<vector<int>> ans(r,vector<int>(c,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(isWater[i][j]){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        int height=1;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int> cur=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    pair<int,int> n={cur.first+x[d],cur.second+y[d]};
                    if(valid(n,r,c) && ans[n.first][n.second]==-1)
                    {
                        ans[n.first][n.second]=height;
                        q.push(n);
                    }
                }
            }
            height++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> arr{{0,0,1},{1,0,0},{0,0,0}};
    arr=s.highestPeak(arr);
    for(auto i:arr)
    {
        for(auto j:i)
        cout<<j<<"  ";
        cout<<endl;
    }
    return 0;
}