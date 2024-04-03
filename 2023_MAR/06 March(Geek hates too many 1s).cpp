class Solution {
int binaryToDecimal(string str){
    int dec_num = 0;
      int power = 0 ;
    int n = str.length() ;
   
      for(int i = n-1 ; i>=0 ; i--){
      if(str[i] == '1'){
        dec_num += (1<<power) ;
      }
      power++ ;
    }
   
    return dec_num;
}
string decToBinary(int n){
    string s = "";
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            s += "1";
        else
            s += "0";
    }
    return s;
}
  public:
    int noConseBits(int n) {
        // code here
        string s = decToBinary(n);
        
        for(int i = 2; i < s.size(); i++) {
            if(s[i] == '1' and s[i-1] == '1' and s[i-2] == '1')s[i] = '0';
        }
        
        return binaryToDecimal(s);
        
        
    }
};
