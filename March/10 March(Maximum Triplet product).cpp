class Solution {
  public:
    
    //naive approach O(nlogn)
    /*
    long long maxTripletProduct(long long arr[], int n)
    {
    	sort(arr,arr+n);
    	
    	long long mn1=arr[0],mn2=arr[1],mx1=arr[n-1],mx2=arr[n-2],mx3=arr[n-3];
    	
    	return max((mn1*mn2*mx1),(mx1*mx2*mx3));
    }
    */
    
    
    
    //Eureka approach O(n)
    long long maxTripletProduct(long long arr[], int n)
    {
        
        long long mn1=INT_MAX,mn2=INT_MAX,mx1=INT_MIN,mx2=INT_MIN,mx3=INT_MIN;
        
        for(int p=0;p<n;p++){
            
            //Calculate the first min and second min element
            
            if(arr[p]<mn1){
                mn2=mn1;
                mn1=arr[p];
            }
            else if(arr[p]<mn2){
                mn2=arr[p];
            }
            
            //Calculate the first max ,second max and third max elements
            
            if(arr[p]>mx1){
                mx3=mx2;
                mx2=mx1;
                mx1=arr[p];
            }else if(arr[p]>mx2){
                mx3=mx2;
                mx2=arr[p];
            }else if(arr[p]>mx3){
                mx3=arr[p];
            }
        }
        
        return max((mn1*mn2*mx1),(mx1*mx2*mx3));
    }

};
