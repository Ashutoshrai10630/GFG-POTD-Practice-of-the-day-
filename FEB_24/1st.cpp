class Solution
{
  public:
    bool checkPangram (string s) 
    {
        int chk=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a'&&s[i]<='z') chk|=(1<<(s[i]-'a'));
            else if(s[i]>='A'&&s[i]<='Z') chk|=(1<<(s[i]-'A'));
            if(chk+1==(1<<26)) return true;
        }
        return false;
    }
};
