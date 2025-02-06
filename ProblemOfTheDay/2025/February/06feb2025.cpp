//Tuple with Same Product (MEDIUM)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int total=0;
        for( int i=0;i<n;i++)
        {
            for(int j=n-1;j>=i+1;j--)
            {
                int product=nums[i]*nums[j];
                unordered_set<int> values;
                for(int k=i+1;k<j;k++)
                {
                    if(product%nums[k]==0){
                        int dvalue=product/nums[k];
                        if(values.find(dvalue)!=values.end())
                            total=total+8;
                        values.insert(nums[k]);
                    }
                }
            }
        }
        return total;
    }
    /*
    int tupleSameProduct(vector<int>& nums) {
        int numsLength = nums.size();
        vector<int> pairProducts;
        int totalNumberOfTuples = 0;
        for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < numsLength;
                 secondIndex++) {
                pairProducts.push_back(nums[firstIndex] * nums[secondIndex]);
            }
        }
        sort(pairProducts.begin(), pairProducts.end());
        int lastProductSeen = -1;
        int sameProductCount = 0;
        for (int productIndex = 0; productIndex < pairProducts.size();
             productIndex++) {
            if (pairProducts[productIndex] == lastProductSeen) {
                sameProductCount++;
            } else {
                int pairsOfEqualProduct =
                    (sameProductCount - 1) * sameProductCount / 2;
                totalNumberOfTuples += 8 * pairsOfEqualProduct;
                lastProductSeen = pairProducts[productIndex];
                sameProductCount = 1;
            }
        }
        int pairsOfEqualProduct = (sameProductCount - 1) * sameProductCount / 2;
        totalNumberOfTuples += 8 * pairsOfEqualProduct;
        return totalNumberOfTuples;
    }    
    */
   /*
   int tupleSameProduct(vector<int>& nums) {
        int numsLength = nums.size();
        unordered_map<int, int> pairProductsFrequency;
        int totalNumberOfTuples = 0;
        for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < numsLength;
                secondIndex++) {
                pairProductsFrequency[nums[firstIndex] * nums[secondIndex]]++;
            }
        }
        for (auto i : pairProductsFrequency) {
            int pairsOfEqualProduct =
                (i.second - 1) * i.second / 2;
            totalNumberOfTuples += 8 * pairsOfEqualProduct;
        }
        return totalNumberOfTuples;
    }
    */
};

int main() {
    Solution s;
    vector<int> nums{1,2,4,5,10};
    cout<<s.tupleSameProduct(nums);
    return 0;
}