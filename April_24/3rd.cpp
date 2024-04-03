//User function Template for C++

/*// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};*/


class Solution
{
    public:
    
 int kthCommonAncestor(Node *root, int k,int x, int y)
{
    vector<int> arr;
    Node* t = root;
    int mn = min(x,y);
    int mx = max(x,y);
    while(t!=NULL)
    {
        if(t->data < mn) 
        {
            arr.push_back(t->data);
            t=t->right;
        }
        else if(t->data > mx) 
        {
            arr.push_back(t->data);
            t=t->left;
        }
        else
        {
            arr.push_back(t->data);
            if(k>arr.size()) return -1;
            return arr[arr.size()-k];
        }
    }
    return -1;
}
};
