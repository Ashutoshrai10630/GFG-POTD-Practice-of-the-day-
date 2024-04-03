class Solution{
public:
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        vector<long long int> ans;
        long long int g = __gcd(L,B), prod = L*B, n = prod/(g*g);
        ans.push_back(n); ans.push_back(g);
        return ans;
    }
};
