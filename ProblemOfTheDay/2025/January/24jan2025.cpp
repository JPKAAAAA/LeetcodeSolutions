//Find Eventual Safe States
/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/
#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(auto j:graph[i]){
                adj[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        vector<bool> safe(n);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe[node]=true;
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0)
                q.push(i);
            }
        }
        vector<int> safeNodes;
        for(int i=0;i<n;i++)
        {
            if(safe[i])
            safeNodes.push_back(i);
        }
        return safeNodes;
    }
};*/

class Solution {
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visit,
        vector<bool>& inStack) {
        if (inStack[node]) {
            return true;
        }
        if (visit[node]) {
            return false;
        }
        visit[node] = true;
        inStack[node] = true;
        for (auto neighbor : adj[node]) {
            if (dfs(neighbor, adj, visit, inStack)) {
                return true;
            }
        }
        inStack[node] = false;
        return false;
    }
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visit(n), inStack(n);

        for (int i = 0; i < n; i++) {
            dfs(i, graph, visit, inStack);
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (!inStack[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph{{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> arr=s.eventualSafeNodes(graph);
    for(auto i:arr)
    cout<<i<<"  ";
    return 0;
}