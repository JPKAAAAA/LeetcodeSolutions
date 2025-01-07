//String Matching in an Array

#include<bits/stdc++.h>
using namespace std;

class Solution {
     bool isSubstringOf(string &sub, string &main) {
        for (int startIndex = 0; startIndex < main.size(); startIndex++) {
            bool subFits = true;
            for (int subIndex = 0; subIndex < sub.size(); subIndex++) {
                if (startIndex + subIndex >= main.size() ||
                    main[startIndex + subIndex] != sub[subIndex]) {
                    subFits = false; 
                    break; 
                }
            }
            if (subFits) {
                return true; 
            }
        }
        return false;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> matchingWords;
        for (int currentWordIndex = 0; currentWordIndex < words.size();
             currentWordIndex++) {
            for (int otherWordIndex = 0; otherWordIndex < words.size();
                 otherWordIndex++) {
                if (currentWordIndex == otherWordIndex)
                    continue;  
                if (isSubstringOf(words[currentWordIndex],
                                  words[otherWordIndex])) {
                    matchingWords.push_back(words[currentWordIndex]);
                    break; 
                }
            }
        }
        return matchingWords;
    }
};

int main(){
    Solution s;
    
    vector<string> str={"mass","as","hero","superhero"};
    for(auto x:str)
    cout<<x<<"  ";
    cout<<endl;
    str=s.stringMatching(str);
    for(auto x:str)
    cout<<x<<"  ";
    return 0;
}