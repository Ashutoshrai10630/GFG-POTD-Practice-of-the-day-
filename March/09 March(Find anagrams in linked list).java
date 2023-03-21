class Solution {
    public static Node createList(Node low, Node high){
        Node newList=new Node(' ');
        Node newListHead=newList;
        
        Node temp=low;
        while(temp!=high){
            char curr=temp.data;
            
            newList.next=new Node(curr);
            newList=newList.next;
            
            temp=temp.next;
        }
        
        return newListHead.next;
    }
    public static ArrayList<Node> findAnagrams(Node head, String s) {
        int savedTime=0;
        int time=1;
        int n=s.length();
        Map<Character, Integer> map=new HashMap<>();
        
        //store original string freq
        for(int i=0; i<n; i++){
            char curr=s.charAt(i);
            map.put(curr, map.getOrDefault(curr, 0) + 1);
        }
        
        Node low=head;
        Node high=head;
        Map<Character, Integer> currMap=new HashMap<>();
        ArrayList<Node> res=new ArrayList<>();
        
        //store initial freq
        int i=0;
        while(high!=null && i<n){
            char curr=high.data;
            
            //store into map
            currMap.put(curr, currMap.getOrDefault(curr, 0) + 1);
            
            high=high.next;
            i++;
            time++;
        }
        
        //check
        if(map.equals(currMap) && ((time-savedTime)>=n)){
            savedTime=time;
            //save
            Node list=createList(low, high);
            res.add(list);
        }
        
        //logic
        while(high!=null){
            char prev=low.data;
            char curr=high.data;
            
            //acquire
            currMap.put(curr, currMap.getOrDefault(curr, 0) + 1);
            
            //release
            if(currMap.get(prev)==1 ){
                currMap.remove(prev);
            }
            else{
                currMap.put(prev, currMap.get(prev) - 1);
            }
            
            //inc ptrs
            low=low.next;
            high=high.next;
            time++;
            
            //check
            if(map.equals(currMap) && ((time-savedTime)>=n)){
                savedTime=time;
                //save
                Node list=createList(low, high);
                res.add(list);
            }
            
        }
        
        return res;
    }
}
