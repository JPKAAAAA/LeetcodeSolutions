//26-08-23


#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
         if(n == 1)
          return "1";
        if(n == 2)
          return "11";
          
        string str = "11";
        
        for(int i = 3; i <= n; i++)
         {
             str += '$';
             int len = str.length();
             
             int cnt = 1;
             string tmp = "";
             
             for(int j = 1; j < len; j++)
              {
                  if(str[j] != str[j - 1])
                    {
                        tmp += cnt + '0';
                        tmp += str[j - 1];
                        cnt = 1;
                    }
                   else
                     cnt++;
              }
            str = tmp;  
         }
         
        return str;
    }
};

int main()
{
    system("cls");
    Solution s;
    cout<<s.countAndSay(13);
    return 0;
}