//Counting Words With a Given Prefix

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(string& str:words){
            if(str.find(pref)==0){
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<string> words={"pay","attention","practice","attend"};
    cout<<s.prefixCount(words,"at");
    return 0;
}
/*
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}
*/