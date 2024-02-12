#define mod 1000000007
class Solution{
public:
    long long solve(int n){
        
        if(n==1)
        return 1;
        
        int cnt= (n*(n-1))/2;
        long long prod=1;
        cnt++;
        for(int i=0;i<n;i++){
            prod=(prod*cnt)% mod;
            cnt++;
        }
        return (solve(n-1) + prod)% mod;
    }
    long long sequence(int n){
        // code here
        return solve(n);
    }
};
