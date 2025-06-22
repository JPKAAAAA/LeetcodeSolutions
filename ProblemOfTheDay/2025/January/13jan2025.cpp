//Minimum Length of String After Operations

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minimumLength(string s){
        int n,count;
        n=count=s.size();
        if(n<=2)
        {
            return n;
        }
        int arr[26]={0};
        for(int i=0;i<n;i++)
        {   
            arr[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]>2 && arr[i]%2==0)
                count=count-(arr[i]-2);
            else if(arr[i]>2 && arr[i]%2==1)
                count=count-(arr[i]-1);
        }
        return count;
    }
};

int main(){
    Solution s;
    string str="abaacbcbb";
    cout<<s.minimumLength(str);
    return 0;
}