//Remove All Occurrences of a Substring (MEDIUM)

#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {
            size_t part_start_index = s.find(part);
            s = s.substr(0, part_start_index) +
                s.substr(part_start_index + part.length());
        }
        return s;
    }
};
*/
class Solution {
    bool helper(stack<char> &st,string &pat, int len)
    {
        stack<char> temp=st;
        for(int i=len-1;i>=0;i--)
        {
            if(temp.top()!=pat[i])
                return false;
            temp.pop();
        }
        return true;
    }
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int slen=s.length();
        int plen=part.length();
        for(int i=0;i<slen;i++)
        {
            st.push(s[i]);
            if(st.size()>=plen && helper(st,part,plen))
            {
                for(int j=0;j<plen;j++)
                    st.pop();
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
/*
class Solution {
public:
    string removeOccurrences(string s, string part) {
        vector<int> kmpLPS = computeLongestPrefixSuffix(part);
        stack<char> charStack;
        vector<int> patternIndexes(s.length() + 1, 0);
        for (int strIndex = 0, patternIndex = 0; strIndex < s.length();
             strIndex++) {
            char currentChar = s[strIndex];
            charStack.push(currentChar);
            if (currentChar == part[patternIndex]) {
                patternIndexes[charStack.size()] = ++patternIndex;
                if (patternIndex == part.length()) {
                    int remainingLength = part.length();
                    while (remainingLength != 0) {
                        charStack.pop();
                        remainingLength--;
                    }
                    patternIndex = charStack.empty()? 0 : patternIndexes[charStack.size()];
                }
            } else {
                if (patternIndex != 0) {
                    strIndex--;
                    patternIndex = kmpLPS[patternIndex - 1];
                    charStack.pop();
                } else {
                    patternIndexes[charStack.size()] = 0;
                }
            }
        }
        string result = "";
        while (!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }
        return result;
    }

private:
    vector<int> computeLongestPrefixSuffix(string pattern) {
        vector<int> lps(pattern.length(), 0);
        for (int current = 1, prefixLength = 0; current < pattern.length();) {
            if (pattern[current] == pattern[prefixLength]) {
                lps[current] = ++prefixLength;
                current++;
            }
            else if (prefixLength != 0) {
                prefixLength = lps[prefixLength - 1];
            }
            else {
                lps[current] = 0;
                current++;
            }
        }
        return lps;
    }
};
*/
int main() {
    Solution s;
    string str="daabcbaabcbc",part="abc";
    cout<<s.removeOccurrences(str,part);
    return 0;
}