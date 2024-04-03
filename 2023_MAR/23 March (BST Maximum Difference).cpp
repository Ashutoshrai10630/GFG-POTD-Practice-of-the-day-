class Solution{
public:
 int solve(Node* root){
        if(!root) return 0;
        if(!root->left && !root->right){
            return root->data;
        }
        int leftData=solve(root->left);
        int rightData=solve(root->right);
        if(!leftData) return root->data+rightData;
        if(!rightData) return root->data+leftData;
        return root->data+min(leftData,rightData);
    }
    int maxDifferenceBST(Node *root,int target){
        Node* temp=root;
        bool find=false;
        int sum=0;
        while(temp){
            if(temp->data!=target){
                sum+=temp->data;
            }
            else{
                find=true;
                break;
            }
            if(temp->data>target){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        if(!find) return -1;
        int sum1;
        if(!solve(temp->right)) sum1=solve(temp->left);
        else if(!solve(temp->left)) sum1=solve(temp->right);
        else sum1=min(solve(temp->left),solve(temp->right));
        return sum-sum1;
    }


};
