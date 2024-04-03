class Solution {

    public int maxLevelSum(Node root) {

        // add code here.

        if(root==null)

        return 0;

        Queue<Node>q=new LinkedList<>();

        q.offer(root);

        int maximum=Integer.MIN_VALUE;

        while(!q.isEmpty())

        {

              int size=q.size();

              int sum=0;

              for(int i=0;i<size;i++)

              {

                    Node current=q.poll();

                    sum+=current.data;

                    if(current.left!=null)

                    q.offer(current.left);

                    if(current.right!=null)

                    q.offer(current.right);

              }

              maximum=Math.max(maximum,sum);

              

        }

        return maximum;

    }

}
