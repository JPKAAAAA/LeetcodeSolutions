//06-08-23



#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=0;
        int i=0;
        int j=height.size()-1;
        while(i<j)
        {
            int minheight=min(height[i],height[j]);
            maxwater=max(maxwater,minheight*(j-i));
            if(height[i]<height[j])
            i++;
            else
            j--;
        }
        return maxwater;
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(height);
    return 0;
}