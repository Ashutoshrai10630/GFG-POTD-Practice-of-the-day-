class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    int c = 0;
    
    int printKDistantfromLeaf(Node* root, int k)
    {
        vector<bool> v;
        distantfromLeaf(root, v, k, 0);
    	return c;
    }
    
    void distantfromLeaf(Node* node, vector<bool> &v, int k, int d)
    {
        if(node == NULL)
            return;
            
        v.push_back(true);
        
        if(node->left == NULL && node->right == NULL && d >= k && v[d - k])
        {
            v[d - k] = false;
            c++;
        }
        
        distantfromLeaf(node->left, v, k, d + 1);
        distantfromLeaf(node->right, v, k, d + 1);
        
        v.pop_back();
    }
};
