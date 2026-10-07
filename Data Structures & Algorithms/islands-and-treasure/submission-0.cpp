class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()) {
            auto [i,j] = q.front();
            q.pop();
            for(auto [x,y]: dir) {
                int nx = i+x;
                int ny = j+y;
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]!=-1 && grid[nx][ny]>grid[i][j]+1) {
                    grid[nx][ny] = grid[i][j]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
};
