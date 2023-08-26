//26-08-23


#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
         if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;    
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
    }
};

int main()
{
    system("cls");
    Solution s;
    cout<<s.countAndSay(10);
    return 0;
}