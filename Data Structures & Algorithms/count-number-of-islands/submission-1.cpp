class Solution {
    void bfs(vector<vector<char>>& grid, int i, int j) {
        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        queue<pair<int,int>> q;
        q.push({i, j});
        grid[i][j] = '0';

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 &&
                    nx < grid.size() && ny < grid[0].size() &&
                    grid[nx][ny] == '1') {

                    grid[nx][ny] = '0';
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }

        return count;
    }
};