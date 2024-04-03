//                                                       Let's Solve the question Together 




class Solution{
    public:
    bool check(int x,int y,int n,int m){
        if(x>=n||y>=m||x<0||y<0)return true;
        return false;
    }
    pair<int,int> endPoints(vector<vector<int>>&a){
        int n=a.size();
        int m=a[0].size();
        pair<int,int>ans{-1,-1};
        int x=0,y=0;
        map<pair<int,int>,pair<int,int>>mp;
        mp[{-1,0}]={0,1};// up ---> right
        mp[{0,1}]={1,0};// right ->> down
        mp[{1,0}]={0,-1};  // down ---> left
        mp[{0,-1}]={-1,0};// left ----> up
        int dx=0,dy=1;
        while(true){
            int nxtx,nxty;
             nxtx=x+dx;
             nxty=y+dy;
             if(a[x][y]==0){
            if(check(nxtx,nxty,n,m)){
                ans={x,y};
                break;}
            x=nxtx;
            y=nxty;
            }
           if(a[x][y]){
            a[x][y]=0;
            pair<int,int>p=mp[{dx,dy}];
            dx=p.first;
            dy=p.second;
            }
        }
        return ans;
    }
};
