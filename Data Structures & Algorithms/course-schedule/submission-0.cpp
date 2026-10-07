class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(auto edge: prerequisites) {
            indeg[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(indeg[i]==0) {
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            for(auto nei: adj[course]) {
                indeg[nei]--;
                if(indeg[nei]==0) {
                    q.push(nei);
                }
            }
        }
        return n==count;
    }
};
