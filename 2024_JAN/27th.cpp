class Solution{
public:
    string matrixChainOrder(int p[], int n){
        
        pair<int , string> dp[n][n] ;
        
        for(int gap = 1 ; gap<n ; gap++){
            for(int i = 0 ; i<n - gap; i++){
                int j = i + gap ;
                if(gap == 1){
                    string res = "0" ;
                    res[0] = 'A' + i;
                    dp[i][j] = {0 , res} ; 
                }
                else{
                    dp[i][j] = {INT_MAX, "-1"} ;
                    for(int k = i+1 ; k<=j-1 ; k++){
                        int cost = p[i] * p[k] * p[j] + dp[i][k].first + dp[k][j].first ;
                        if(dp[i][j].first > cost){
                           dp[i][j].first = cost ; 
                           dp[i][j].second = "(" + dp[i][k].second + dp[k][j].second + ")" ;
                        } 
                    }
                }
            }
        }
        
        return dp[0][n-1].second ;
    }
};
