
class Solution{
private:
    int n;
    vector <int> nums;
    map <pair<int,int>,int> dp;
public:
    int dfs(int i, int p){
        if(i == n)
            return 0;
        int a = INT_MAX, b = INT_MAX;
        if(dp.find({i, p}) != dp.end())
            return dp[{i, p}];
        if(nums[i] > p)
            a = dfs(i+1, nums[i]);
        b = 1+dfs(i+1, p+1);
        return dp[{i, p}] = min(a, b);
    }
    int min_operations(vector<int>nums){
        n = nums.size();
        this->nums = nums;
        return dfs(0, -10000000);
	}
};