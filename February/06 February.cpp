//User function Template for C++
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
public:
bool f(Node*root,Node* &t,int target)
{
    if(root==NULL)
    return false;
    if(root->data > target)
    f(root->left,t,target);
    else if(root->data < target)
    f(root->right,t,target);
    
    else{ t = root; return true;}
}
void bakeSum(Node*root,int val ,int comp,int &ans)
{
    if(root==NULL)
    return;
    if(val==comp)
    ans+=root->data;
    bakeSum(root->left,val-1,comp,ans);
    bakeSum(root->right,val+1,comp,ans);
}
long long int verticallyDownBST(Node *root,int target){
    // Code here
    Node*t=NULL;
    int ans = 0;
    bool s =f(root,t,target);
    if(!s) return  -1;
    
    bakeSum(t,0,0,ans);
    return ans-t->data;
    
}
};
