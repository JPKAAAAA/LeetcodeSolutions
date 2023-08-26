//26-08-23


#include<iostream>
using namespace std;
class Solution {
public:
    string countAndSay(int n, string prevs="1") {
         if(n==1) return prevs;
    int i=0, j, len = prevs.size();
    string currs = "";
    while(i<len) {
        j=i;
        while(i<len && prevs[i]==prevs[j]) i++;
        currs += to_string(i-j) + prevs[j];
    }
    return countAndSay(n-1, currs);
    }
};

int main()
{
    system("cls");
    Solution s;
    cout<<s.countAndSay(7);
    return 0;
}