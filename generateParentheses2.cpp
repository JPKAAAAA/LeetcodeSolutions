//15-08-23
//this solution involve DP

#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1); // cache to store all generated strings
        dp[0] = {""}; 
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                vector<string> left = dp[j];
                vector<string> right = dp[i-j-1];
                for(int k=0;k<left.size();k++){
                    for(int l=0;l<right.size();l++){
                        dp[i].push_back("(" + left[k] + ")" + right[l]);
                    }
                }
            }
        }
        return dp[n];
    }

int main()
{
    system("cls");
    int ch;
    cin>>ch;
    vector<string> ans=generateParenthesis(ch);
    cout<<ans.size()<<endl;
    for(auto i:ans)
    cout<<i<<" ";
    return 0;
}