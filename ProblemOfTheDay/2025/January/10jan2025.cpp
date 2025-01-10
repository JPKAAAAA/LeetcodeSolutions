//Word Subsets

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> count(const string& word) {
    vector<int> charCount(26, 0);
    for (char c : word) {
        charCount[c - 'a']++;
    }
    return charCount;
}
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<int> bmax(26, 0);
    for (const string& b : words2) {
        vector<int> bCount = count(b);
        for (int i = 0; i < 26; ++i) {
            bmax[i] = max(bmax[i], bCount[i]);
        }
    }
    vector<string> result;
    for (const string& a : words1) {
        vector<int> aCount = count(a);
        bool isUniversal = true;
        for (int i = 0; i < 26; ++i) {
            if (aCount[i] < bmax[i]) {
                isUniversal = false;
                break;
            }
        }
        if (isUniversal) {
            result.push_back(a);
        }
    }
    return result;
    }
};

int main(){
    Solution s;
    vector<string> str1={"amazon","apple","facebook","google","leetcode"};
    vector<string> str2={"e","o"};
    vector<string> ans=s.wordSubsets(str1,str2);
    for(auto i:ans)
    cout<<i<<"  ";
    return 0;
}