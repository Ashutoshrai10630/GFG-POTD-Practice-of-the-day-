class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, int>> v;
        for(int i=0; i<n; i++)
        {
            v.push_back({double(arr[i].value) / double(arr[i].weight), i});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        double wt = double(W);
        double ans = 0.000000;
        for(auto it : v)
        {
            double costPerUnit = it.first;
            int i = it.second;
            if(arr[i].weight <=  wt)
            {
                wt -= double(arr[i].weight);
                ans += double(arr[i].value);
            }
            else
            {
                ans += wt * costPerUnit;
                wt = 0;
            }
        }
        return ans;
    }
        
};
