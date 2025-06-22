//18-08-23


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         int index = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<int> vec={1,2,3,4,1,2,3,4,5};
    int i=vec[8];
    cout<<"Number of distinct elements other than "<<i<<": "<<s.removeElement(vec,5);
    return 0;

}