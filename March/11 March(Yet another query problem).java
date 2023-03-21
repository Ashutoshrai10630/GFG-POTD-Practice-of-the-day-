class Solution {

    public static ArrayList<Integer> solveQueries(int n, int num, int[] arr, int[][] qrr) {

        ArrayList<HashMap<Integer,Integer>> al=new ArrayList<>();

        for(int i=0; i<n; i++) al.add(new HashMap<>());

        for(int i=0; i<n; i++)for(int j=i; j<n; j++)al.get(i).put(arr[j],al.get(i).getOrDefault(arr[j],0)+1);

        ArrayList<Integer> ans=new ArrayList<>();

        for(int i=0; i<num; i++){

            int count=0;

            for(int j=qrr[i][0]; j<=qrr[i][1]; j++)if(al.get(j).get(arr[j])==qrr[i][2])count++;

            ans.add(count);

        }return ans;

    }

}
