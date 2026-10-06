class Solution {
    int bfs(vector<vector<int>>& grid,int i,int j) {
        queue<pair<int,int>> q;
        int res=1;
        q.push({i,j});
        grid[i][j]=0;
        vector<pair<int,int>> dir= {{1,0},{-1,0},{0,1},{0,-1}};
        while(q.size()) {
            auto [x,y] = q.front();
            q.pop();
            for(auto [l,r]: dir) {
                int nx= l+x;
                int ny = r+y;
                if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==1) {
                    res++;
                    grid[nx][ny]=0;
                    q.push({nx,ny});
                }
            }
        }
        return res;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1) {
                    area = max(area,bfs(grid,i,j));
                }
            }
        }
        return area;
    }
};
