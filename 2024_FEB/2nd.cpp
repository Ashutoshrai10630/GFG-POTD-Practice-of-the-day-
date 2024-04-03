int atoi(string str) {
        for(int i=0;i<str.size();i++){
            if((str[i] >='a' && str[i]<='z'))
                return -1;
            if(i>0 && str[i] =='-')
                return -1;
        }
        int ans=0; 
        bool flag=false;
        for(int i=0;i<str.size();i++){
            if(i==0 && str[i]=='-')
                flag=true;
            else{
                ans=ans*10 + (str[i]-'0');
            }    
        }
        if(flag==true)
            return -1*ans;
        return ans;    
    }
