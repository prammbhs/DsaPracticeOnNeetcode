class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m,vector<bool> (n,false));
        vector<vector<bool>> alt(m,vector<bool> (n,false));

        queue<pair<int,int>> qp, qa;
        for(int i=0;i<m;i++) {
            pac[i][0] = true;
            qp.push({i,0});
            alt[i][n-1]=true;
            qa.push({i,n-1});
        }
        for(int i=0;i<n;i++) {
            pac[0][i]=true;
            qp.push({0,i});
            alt[m-1][i] = true;
            qa.push({m-1,i}); 
        }
        vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        auto bfs = [&] (queue<pair<int,int>>& q,vector<vector<bool>>& vis) {
            while(!q.empty()) {
                auto [i,j] = q.front();
                q.pop();
                for(auto [di,dy]: dir) {
                    int x = i+di;
                    int y = j+dy;
                    if(x>=0 && y>=0 && x<m && y<n && !vis[x][y] && heights[x][y]>=heights[i][j]) {
                        vis[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
        };
        bfs(qp,pac);
        bfs(qa,alt);
        vector<vector<int>> ans;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pac[i][j]&&alt[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
