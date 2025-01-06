//Minimum Number of Operations to Move All Balls to Each Box


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.size(),0);
        int left=0,mleft=0,right=0,mright=0;
        for(int i=0;i<boxes.size();i++){
            res[i]=res[i]+mleft;
            left=left+boxes[i]-'0';
            mleft=mleft+left;
            int j=boxes.size()-i-1;
            res[j]=res[j]+mright;
            right=right+boxes[j]-'0';
            mright=mright+right;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> ans=s.minOperations("001011");
    for(int x:ans)
    cout<<x<<" ";
    return 0;
}