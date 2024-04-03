/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     if(root==nullptr ||(root->left==NULL && root->right==NULL)){
        return 1;
     }
     
     
     int left = 0, right = 0;
     
     if(root->left!=NULL){
         left = root->left->data;
     }
     
     if(root->right!=NULL){
         right = root->right->data;
     }
     
     if(root->data==left+right){
         return isSumProperty(root->left) && isSumProperty(root->right);
     } else {
         return 0;
     }
    }
};
