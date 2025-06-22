//07-08-23


#include<iostream>
#include<string>
using namespace std;
string convert(string s, int nRows) {
        if(nRows <= 1) return s;
        string result = "";
        //the size of a cycle(period)
        int cycle = 2 * nRows - 2;
        for(int i = 0; i < nRows; ++i)
        {
            for(int j = i; j < s.length(); j = j + cycle){
               result = result + s[j];
               int secondJ = (j - i) + cycle - i;
               if(i != 0 && i != nRows-1 && secondJ < s.length())
                   result = result + s[secondJ];
            }
        }
        return result;
    }


int main()
{
    system("cls");
    cout<<convert("mynameissurajjha",5);
    return 0;
}
