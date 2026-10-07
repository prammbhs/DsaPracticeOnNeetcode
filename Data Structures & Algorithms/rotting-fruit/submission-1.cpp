class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> rotten;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==2) {
                    rotten.push({i,j});
                }else if(grid[i][j]==1) {
                    fresh++;
                }
            }
        }
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int time = 0;
        while(!rotten.empty()) {
            if(fresh==0) {
                break;
            }
            int freshbf = fresh;
            int size = rotten.size();
            for(int i=0;i<size;i++) {
                auto [x,y] = rotten.front();
                rotten.pop();
                for(auto [di,dj]: dir) {
                    int nx=di+x;
                    int ny=dj+y;
                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1) {
                        grid[nx][ny]=2;
                        fresh--;
                        rotten.push({nx,ny});
                    }
                }
            }
            if(fresh==freshbf) {
                break;
            }
            time++;
        }
        return fresh!=0? -1:time;
    }
};
