//Redundant Connection (MEDIUM)

#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    int n;
    vector<int> size;
    vector<int> arr;
    public:
    disjointSet(int n){
        this->n=n;
        for(int i=0;i<n;i++)
        {
            size.push_back(1);
            arr.push_back(i);
        }
    }
    int find(int node){
        if(arr[node]==node)
        return node;
        return arr[node]=find(arr[node]);
    }
    bool Union(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y)
        return 0;
        else
        {
            if(size[x]>size[y])
            {
                arr[y]=x;
                size[x]=size[x]+size[y];
            }
            else
            {
                arr[x]=y;
                size[y]=size[y]+size[x];
            }
            return 1;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        disjointSet ds(n);
        for(auto i:edges){
            if(!ds.Union(i[0]-1,i[1]-1))
                return i;
        }
        return {};
    }
};

int main(){
    Solution s;
    vector<vector<int>> arr{{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<int> ans=s.findRedundantConnection(arr);
    for(auto i:ans)
    cout<<i<<" ";
    return 0;
}