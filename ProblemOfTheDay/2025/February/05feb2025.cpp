//Check if One String Swap Can Make Strings Equal (EASY)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool areAlmostEqual(string s1,string s2)
    {
        int arr[]={0,0};
        int count=0;
        for(int i=0;i<s1.size();i++) {
            if (s1[i]!=s2[i]) {
                count++;
                if(count>2)
                    return false;
                else if (count==1) {
                    arr[0]=i;
                } else {
                    arr[1]=i;
                }
            }
        }
        return(s1[arr[0]]==s2[arr[1]] && s1[arr[1]] == s2[arr[0]]);
    }
    /*
     bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        int s1FrequencyMap[26] = {0};
        int s2FrequencyMap[26] = {0};
        int numDiffs = 0;
        for (int i = 0; i < s1.size(); i++) {
            char s1Char = s1[i];
            char s2Char = s2[i];
            if (s1Char != s2Char) {
                numDiffs++;
                if (numDiffs > 2) return false;
            }
            s1FrequencyMap[s1Char - 'a']++;
            s2FrequencyMap[s2Char - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (s1FrequencyMap[i] != s2FrequencyMap[i]) return false;
        }
        return true;
    }
    */
};

int main() {
    Solution s;
    string str1="bank";
    string str2="kanb";
    cout<<s.areAlmostEqual(str1,str2);
    return 0;
}