// User function Template for Java

class Solution {

    int parent[];

    ArrayList<String> avoidExlosion(int mix[][], int n, int danger[][], int m) {

        // Code Here

        ArrayList<String>ans=new ArrayList<>();

        parent =new int[n+1];

        for(int i=0;i<=n;i++){

            parent[i]=i;

        }

        for(int i=0;i<n;i++)

        {

            int a=find(mix[i][0]);

            int b=find(mix[i][1]);

              boolean x=true;

            for(int j=0;j<m;j++){

                int c=find(danger[j][0]);

                int d=find(danger[j][1]);

            if((a==c&&b==d)||(a==d&&b==c)){

                x=false;

                break;

            }

            }

        if(x){union(a,b);

        ans.add("Yes");}

        else ans.add("No");

      

    }

    return ans;

    }

    void union(int x,int y){

        int x_ref=find(x);

        int y_ref=find(y);

        if(x_ref==y_ref)return;

        parent[x_ref]=y_ref;

    }

    int find(int x){

        if(parent[x]==x)

        return x;

        return find(parent[x]);

    }

}
