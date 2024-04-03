//Let's Solve the question Together ....................................................................................................................

class Solution

{

  public:

   long long largestSumCycle(int n, vector<int> edge) {

        // code here//Let's Solve the question Together 
        vector<int> indegree(n, 0);

        for(auto it: edge) {

            if(it == -1) continue;

            indegree[it]++;

        }

        

        queue<int> q;

        vector<int> vis(n, false);

        for(int i = 0; i < n; i++) {

            if(indegree[i] == 0) {

                vis[i] = true;

                q.push(i);

            }

        }

        

        while(q.empty() == false) {

            int curr = q.front(); q.pop();

            int par = edge[curr];

            if(par == -1) continue;

            

            if(--indegree[par] == 0) {

                q.push(par);

                vis[par] = true;

            }

        }

        

        int res = -1;

        for(int i = 0; i < n; i++) {

            if(vis[i]) continue;

            int val = 0;

            for(int st = i; vis[st] == false; st = edge[st]) {

                val += st;

                vis[st] = true;

            }

            res = max(res, val);

        }

        return res;

  } 

};

