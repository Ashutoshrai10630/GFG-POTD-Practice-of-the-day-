class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> ans(n,0);
        set<int> s;
        s.insert(0);
        for(int i=1;i<n;i++){
            if(ans[i-1]-i>0 && s.count(ans[i-1]-i)==0)
                ans[i]=ans[i-1]-i;
            else
                ans[i]=ans[i-1]+i;
            s.insert(ans[i]);
        }
        return ans;
    }
};
