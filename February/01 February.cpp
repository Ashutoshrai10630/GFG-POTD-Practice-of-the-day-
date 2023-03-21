//Let's Solve the question Together 

class Solution{   
public:
  long long int dp[3][50005];
long long int distinctColoring(int n, int r[], int g[], int b[]){
        dp[0][0] = min(g[0],b[0]);
        dp[1][0] = min(r[0],b[0]);
        dp[2][0] = min(r[0],g[0]);
        for(int i = 1; i < n; i++){
           long long int x = r[i] + dp[0][i-1];
           long long int y = g[i] + dp[1][i-1];
           long long int z = b[i] + dp[2][i-1];
           dp[0][i] = min(y,z);
           dp[1][i] = min(x,z);
           dp[2][i] = min(x,y);
        }
        long long int ans = 1e18;
        for(int i = 0; i< 3; i++){
            ans = min(ans,dp[i][n-1]);
        }
        return ans;
    }
};

