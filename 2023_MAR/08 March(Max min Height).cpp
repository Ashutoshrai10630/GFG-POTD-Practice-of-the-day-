class Solution{
    public: 
        bool isOK(vector<int> &arr, int days, int cs, long long int h){
            int n=arr.size();
            
            vector<long long> waterSupply(n,0);
            
            if(arr[0]<h){
                waterSupply[0]=h-arr[0];
                days-=(h-arr[0]);
            }
            
            if(days<0){
                return false;
            }
            
            for(int i=1;i<arr.size();i++){
                waterSupply[i]=waterSupply[i-1];
                
                int actualHeight=arr[i];
                if(i>=cs){
                    actualHeight+=(waterSupply[i]-waterSupply[i-cs]);
                }
                else{
                    actualHeight+=waterSupply[i];
                }
                
                if(actualHeight<h){
                    waterSupply[i]+=(h-actualHeight);
                    days-=(h-actualHeight);
                }
                if(days<0){
                    return false;
                }
            }
            return true;
        }
        
        long long int maximizeMinHeight(int n,int k,int w, vector<int> &a){
            long long int res=-1;
            long long int mnHeight=*min_element(a.begin(),a.end());
            long long int mxHeight=INT_MAX/2;
            while(mnHeight<=mxHeight){
                int guessHeight=(mxHeight+mnHeight)/2;
                if(isOK(a,k,w,guessHeight)==true){
                    res=guessHeight;
                    mnHeight=guessHeight+1;
                }
                else{
                    mxHeight=guessHeight-1;
                }
            }
            return res;
        }
};
