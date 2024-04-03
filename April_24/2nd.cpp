/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

};
*/

class Solution
{
    public:
    void inorder(Node* node, Node*& prev, int& minDiff) {
        if (node == nullptr) return;
        
        inorder(node->left, prev, minDiff);
        
        if (prev != nullptr) {
            minDiff = min(minDiff, node->data - prev->data);
        }
        prev = node;
        
        inorder(node->right, prev, minDiff);
    }
    
    int absolute_diff(Node *root)
    {
        int minDiff = INT_MAX;
        Node* prev = nullptr;
        inorder(root, prev, minDiff);
        return minDiff;
    }
};