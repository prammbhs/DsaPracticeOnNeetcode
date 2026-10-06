class Solution {
    void dfs(vector<vector<char>>& grid,int i,int j) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0') {
            return;
        }
        grid[i][j]='0';
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto [x,y]: dir) {
            int nx = x+i;
            int ny = y+j;
            dfs(grid,nx,ny); 
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]=='1') {
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};
