//23-08-23
//Find First and Last Position of Element in Sorted Array
//linear Search approach


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int startingPosition = -1, endingPosition = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                startingPosition = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] == target){
                endingPosition = i;
                break;
            }
        }
        return {startingPosition, endingPosition};
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> num={1,1,2,2,3,4,4,5,6,6,7};
    vector<int> ans=s.searchRange(num,8);
    for(auto i:ans)
    cout<<i<<" ";
    return 0;
}