//Most Profitable Path in a Tree (MEDIUM)  

#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, int> bobPath;
    vector<bool> visited;
    vector<vector<int>> tree;
    bool findBobPath(int sourceNode, int time) {
        bobPath[sourceNode] = time;
        visited[sourceNode] = true;
        if (sourceNode == 0) {
            return true;
        }
        for (auto adjacentNode : tree[sourceNode]) {
            if (!visited[adjacentNode]) {
                if (findBobPath(adjacentNode, time + 1)) {
                    return true;
                }
            }
        }
        bobPath.erase(sourceNode);
        return false;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
               int n = amount.size(), maxIncome = INT_MIN;
        tree.resize(n);
        visited.assign(n, false);
        queue<vector<int>> nodeQueue;
        nodeQueue.push({0, 0, 0});
        for (vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        findBobPath(bob, 0);
        visited.assign(n, false);
        while (!nodeQueue.empty()) {
            int sourceNode = nodeQueue.front()[0], time = nodeQueue.front()[1],
                income = nodeQueue.front()[2];
            if (bobPath.find(sourceNode) == bobPath.end() ||
                time < bobPath[sourceNode]) {
                income += amount[sourceNode];
            }
            else if (time == bobPath[sourceNode]) {
                income += (amount[sourceNode] / 2);
            }
            if (tree[sourceNode].size() == 1 && sourceNode != 0) {
                maxIncome = max(maxIncome, income);
            }
            for (int adjacentNode : tree[sourceNode]) {
                if (!visited[adjacentNode]) {
                    nodeQueue.push({adjacentNode, time + 1, income});
                }
            }
            visited[sourceNode] = true;
            nodeQueue.pop();
        }
        return maxIncome;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    int bob = 3;
    vector<int> amount = {-2,4,2,-4,6};
    cout << obj.mostProfitablePath(edges, bob, amount) << endl;
    return 0;
}