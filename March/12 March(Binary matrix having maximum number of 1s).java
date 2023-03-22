class Solution {
   public int[] findMaxRow(int mat[][], int N) {
    //code here
    for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(mat[j][i]==1){
                    return new int[]{j,N-i};
                }
            }
        }
        return new int[]{0,0};
    }
};
