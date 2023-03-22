class Solution {
    public static int minimumTime(int N, int cur, int[] pos, int[] time) {
        ArrayList<Integer> l=new ArrayList<>();
        int ans=0;
        for(int i=0;i<N;i++){
        ans=(Math.max(cur,pos[i])-Math.min(cur,pos[i]))*time[i];
        l.add(ans);
        }
        Collections.sort(l);
        return l.get(0);
    }
}
