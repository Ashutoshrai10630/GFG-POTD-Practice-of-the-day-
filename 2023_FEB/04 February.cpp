//Let's Solve the question Together 


class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    if (n == 1) return arr[0];
	    
	    int t0 = arr[0], t1 = max(arr[0], arr[1]);
	    for (int i=2; i<n; i++) {
	        int t2 = max(t1, arr[i] + t0);
	        t0 = t1, t1 = t2;
	    }
	    return t1;
	}
};
