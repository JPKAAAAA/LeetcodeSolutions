// 3. Longest Substring Without Repeating Characters


#include<iostream>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> visited;
        unordered_map<char,int> index;
        int max=0;
        int start=0,count;
        while(s[start]!='\0')
        {
            count=0;
            for(int i=start;s[i]!='\0';i++)
            {
                if(!visited[s[i]])
                {
                    visited[s[i]]=true;
                    index[s[i]]=i;
                    start++;
                    count++;
                }
                else
                {   start=index[s[i]]+1;
                    break;
                }
            }
            if(count>max)
                    max=count;
                    visited.clear();
        }
        return max;
    }
};

int main()
{
    Solution s;
    string st="surajsbcdefgh";
    int ans=s.lengthOfLongestSubstring(st);
    cout<<ans;
    return 0;
}