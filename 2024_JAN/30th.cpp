

class Solution
{
    public:

        // Function to find the length of the longest common subsequence of three strings
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // Create a 3D dynamic programming table
            int dp[n1+1][n2+1][n3+1];

            // Initialize the table with zeros
            memset(dp, 0, sizeof(dp));

            // Iterate over the first string
            for(int i=1; i<=n1; i++)
            {
                // Iterate over the second string
                for(int j=1; j<=n2; j++)
                {
                    // Iterate over the third string
                    for(int k=1; k<=n3; k++)
                    {
                        // If the current characters of all three strings are equal
                        if (A[i-1] == B[j-1] && B[j-1] == C[k-1])
                        {
                            // Increment the length of the common subsequence
                            dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                        }
                        else
                        {
                            // If the current characters are not equal, take the maximum length of the subsequence found so far
                            dp[i][j][k]=max(max(dp[i-1][j][k], dp[i][j-1][k]),dp[i][j][k-1]);
                        }
                    }
                }
            }

            // Return the length of the longest common subsequence
            return dp[n1][n2][n3];
        }
};
