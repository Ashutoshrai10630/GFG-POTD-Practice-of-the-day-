long long sumSubstrings(string s){
        // long long int ans=0;
        long long int mod=1e9+7;
        long long int r=1,res=0;
        for(int i=s.size()-1;i>=0;i--){
            // long long int  
            res=(res+((s[i]-'0')*(i+1)*r)%mod)%mod;
            res%=mod;
            r=(r*10+1)%mod;
            r%=mod;
            
        }
        return(res);
    }