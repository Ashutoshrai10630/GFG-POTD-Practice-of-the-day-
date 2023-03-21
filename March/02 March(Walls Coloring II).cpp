class Solution{

public:

    int minCost(vector<vector<int>> &costs) {

        // write your code here

        int n=costs.size(),m=costs[0].size();

        if(n>1 and m==1) {

            return -1;

        }

        int f_min=INT_MAX, s_min=INT_MAX, f_ind=-1;

        for(int i=0; i<1; ++i) {

            for(int j=0; j<m; ++j) {

                if(costs[i][j]<f_min) {

                    f_min=costs[i][j];

                    f_ind=j;

                }

            }

            for(int j=0; j<m; ++j) {

                if(costs[i][j]<s_min and j!=f_ind) {

                    s_min=costs[i][j];

                }

            }

        }

        for(int i=1; i<n; ++i) {

            for(int j=0; j<m; ++j) {

                if(j!=f_ind) {

                    costs[i][j]=f_min+costs[i][j];

                }

                else {

                    costs[i][j]=s_min+costs[i][j];

                }

            }

            f_min=INT_MAX, s_min=INT_MAX, f_ind=-1;

            for(int j=0; j<m; ++j) {

                if(costs[i][j]<f_min) {

                    f_min=costs[i][j];

                    f_ind=j;

                }

            }

            for(int j=0; j<m; ++j) {

                if(costs[i][j]<s_min and j!=f_ind) {

                    s_min=costs[i][j];

                }

            }

        }

        return f_min;

    }

};
