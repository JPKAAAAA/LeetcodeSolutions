//Construct K Palindrome String

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k)
        return false;
        if(s.length()==k)
        return true;
        vector<int> fq(26);
        int oddCount=0;
        for(auto ch:s)
        fq[ch-'a']++;
        for(int i=0;i<26;i++){
            if(fq[i]%2==1)
            oddCount++;
        }
        return oddCount<=k;
    }
};

int main(){
    Solution s;
    string str="annabelle";
    cout<<s.canConstruct(str,2);
    return 0;
}