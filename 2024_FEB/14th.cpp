class Solution {
public:

    int dfs(vector<int> graph[], int i, vector<int>& rank, vector<vector<int>>& res, int prev_rank, int n) {
        // increment the current node's rank
        rank[i] = prev_rank + 1;
        int t = INT_MAX;
        // traverse the neibours
        for(const auto& nbr: graph[i]) {
            if(rank[nbr] == -1) {
                // not visited
                int k = dfs(graph, nbr, rank, res, prev_rank+1, n);
                if( k > rank[i])
                    // problem statement to store edges in order
                    res.push_back({min(i, nbr), max(i,nbr)});
                t = min(t, k);
                
            } else if(rank[nbr] == n+1)
                continue;
            else if(rank[nbr] != prev_rank)
                t = min(t, rank[nbr]);
        }
        rank[i] = n + 1;
        return t;
    }
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    // Tarzan's Algorithm
	    vector<vector<int>> res;
	    vector<int> rank(v, -1);
	    
	    int k = dfs(adj, 0, rank, res, 0, v);
	    sort(res.begin(), res.end());
	    return res;
	}
};
