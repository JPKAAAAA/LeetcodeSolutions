//07-08-23
//beats 98.36% runtime, beats 99.71% memory


#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
    int i,j,num,x,S,k=0;
    num=s.size();
    char *ans=new char[num];
    if(numRows==1)
    {
        return s;
    }
    x=(numRows-1)+(numRows-2);
    S=(num/x)+2;
    int *index=new int[S];
    for(i=0;i<S;i++)
        index[i]=i*(x+1);
    for(i=0;i<numRows;i++)
        for(j=0;j<S;j++)
        {
            if(i==0&&index[j]<num){
                ans[k++]=s[index[j]];
            }
            else
            {
                if(index[j]-i>0&&i<=numRows-2&&index[j]-i<num){
                ans[k++]=s[index[j]-i];
                }
                if(index[j]+i<num){
                ans[k++]=s[index[j]+i];
                }
            }
        }
        for(i=0;i<num;i++)
        s[i]=ans[i];
    return s;
    }
};

int main()
{
    system("cls");
    Solution s;
    cout<<s.convert("hoofremgfkrbcvkzvgbofthgojhdnaywpnbitora",13);
    return 0;
}