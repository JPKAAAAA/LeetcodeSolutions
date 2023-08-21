//21-08-23


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         next_permutation(nums.begin(), nums.end());
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    s.nextPermutation(nums);
    return 0;
}