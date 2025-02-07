// Find the Number of Distinct Colors Among the Balls (MEDIUM)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colorMap, ballMap;
        for (int i = 0; i < n; i++) {
            int ball = queries[i][0], color = queries[i][1];
            if (ballMap.find(ball) != ballMap.end()) {
                int prevColor = ballMap[ball];
                colorMap[prevColor]--;
                if (colorMap[prevColor] == 0) colorMap.erase(prevColor);
            }
            ballMap[ball] = color;
            colorMap[color]++;
            result[i] = colorMap.size();
        }
        return result;
    }
    /*
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colorMap;
        vector<int> ballArray(limit + 1);
        for (int i = 0; i < n; i++) {
            int ball = queries[i][0], color = queries[i][1];
            if (ballArray[ball] != 0) {
                int prevColor = ballArray[ball];
                colorMap[prevColor]--;
                if (colorMap[prevColor] == 0) colorMap.erase(prevColor);
            }
            ballArray[ball] = color;
            colorMap[color]++;
            result[i] = colorMap.size();
        }
        return result;
    }
    */
};

int main() {
    Solution s;
    vector<vector<int>> arr{{0,1},{1,2},{2,2},{3,4},{4,5}};
    vector<int> ans=s.queryResults(4,arr);
    for(auto i:ans)
        cout<<i<<"  ";
    cout<<endl;
    return 0;
}