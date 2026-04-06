class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> rows,col;
        unordered_map<int,unordered_set<int>> squares;
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.') {
                    continue;
                }
                int num = board[i][j]-'1';
                int it = (i/3)*3+(j/3);
                if(rows[i].count(num) || col[j].count(num) || squares[it].count(num)) {
                    return false;
                }
                rows[i].insert(num);
                col[j].insert(num);
                squares[it].insert(num);
            }
            
        }
        return true;
    }
};
