class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) {
            if(board[i][0]=='O') {
                q.push({i,0});
                board[i][0]='s';
            }
            if(board[i][n-1]=='O') {
                q.push({i,n-1});
                board[i][n-1]='s';
            }
        }
        for(int j=0;j<n;j++) {
            if(board[0][j]=='O') {
                q.push({0,j});
                board[0][j]='s';
            }
            if(board[m-1][j]=='O') {
                q.push({m-1,j});
                board[m-1][j]='s';
            }
        }
        vector<pair<int,int>> dir= {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            auto [i,j] = q.front();
            q.pop();

            for(auto [di,dj]: dir) {
                int x = i+di;
                int y= j+dj;
                if(x>=0 && y>=0 && x<m && y<n && board[x][y]=='O') {
                    board[x][y]='s';
                    q.push({x,y});
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]=='O') {
                    board[i][j]='X';
                }else if(board[i][j]=='s') {
                    board[i][j]='O';
                }
            }
        }

    }
};
