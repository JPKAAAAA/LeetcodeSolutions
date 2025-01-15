//Minimize XOR

#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isSet(int x,int bit){
        return x&(1<<bit);
    }
    void setBit(int &x,int bit)
    {
        x|=(1<<bit);
    }
    void unsetBit(int &x,int bit){
        x&=~(1<<bit);
    }
public:
    int minimizeXor(int num1, int num2) {
        int ans=num1;
        int count=__builtin_popcount(num2);
        int scount=__builtin_popcount(ans);
        int cur=0;
        while(scount<count){
            if(!isSet(ans,cur)){
                setBit(ans,cur);
                scount++;
            }
            cur++;
        }
        while(scount>count){
            if(isSet(ans,cur)){
                unsetBit(ans,cur);
                scount--;
            }
            cur++;
        }
        return ans;
    }
};