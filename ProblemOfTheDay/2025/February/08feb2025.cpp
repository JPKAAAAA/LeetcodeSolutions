//Design a Number Container System (MEDIUM)

#include<bits/stdc++.h>
using namespace std;

class NumberContainers {
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>>numberToIndices;
    unordered_map<int, int> indexToNumbers;
public:
    NumberContainers() {
    }
    
    void change(int index, int number) {
        indexToNumbers[index] = number;
        numberToIndices[number].push(index);
    }
    
    int find(int number) {
        if (numberToIndices.find(number) == numberToIndices.end()) 
            return -1;
        auto& minHeap = numberToIndices[number];
        while (!minHeap.empty()) {
            int index = minHeap.top();
            if (indexToNumbers[index] == number) 
                return index;
            minHeap.pop();
        }
        return -1;
    }
};
/*
class NumberContainers {
public:
    NumberContainers() {}
    void change(int index, int number) {
        if (indexToNumbers.find(index) != indexToNumbers.end()) {
            int previousNumber = indexToNumbers[index];
            numberToIndices[previousNumber].erase(index);
            if (numberToIndices[previousNumber].empty()) {
                numberToIndices.erase(previousNumber);
            }
        }
        indexToNumbers[index] = number;
        numberToIndices[number].insert(index);
    }
    int find(int number) {
        if (numberToIndices.find(number) != numberToIndices.end()) {
            return *numberToIndices[number].begin();
        }
        return -1;
    }

private:
    unordered_map<int, set<int>> numberToIndices;
    unordered_map<int, int> indexToNumbers;
};
*/

int main() {
    NumberContainers n;
    vector<string> arr1={"find","change","change","change","change","find","change","find"};
    vector<vector<int>> arr2={{10},{2,10},{1,10},{3,10},{5,10},{10},{1,20},{10}};
    for(int i=0;i<arr1.size();i++)
    {
        if(arr1[i]=="find")
        {
            cout<<n.find(arr2[i][0])<<endl;
        }
        else if(arr1[i]=="change")
        {
            n.change(arr2[i][0],arr2[i][1]);
        }
    }
    return 0;
}