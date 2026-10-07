class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(auto edge: prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            indeg[edge[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(indeg[i]==0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto nei: adj[node]) {
                indeg[nei]--;
                if(indeg[nei]==0) {
                    q.push(nei);
                }
            }
        }
        if(ans.size()!=n) {
            return {};
        }
        return ans;
    }
};
