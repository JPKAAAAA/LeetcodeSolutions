//25-08-23


#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         set<pair<int,char>> row,col,grid;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                int count=(i/3)*3 +j/3;
                
                if(row.find({i,board[i][j]})==row.end())
                    row.insert({{i,board[i][j]}});
                 else return false;

                if(col.find({j,board[i][j]})==col.end())
                    col.insert({{j,board[i][j]}});
                 else return false;

                if(grid.find({count,board[i][j]})==grid.end())
                    grid.insert({{count,board[i][j]}});
                 else  return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    system("cls");
    Solution s;
    vector<vector<char>> num={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout<<s.isValidSudoku(num);
    return 0;
}