class Solution{
  public:
    bool check(Node *root)
    {
        int level = -1;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(q.empty()==false){
            Node* curr = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(!curr->left && !curr->right){
                if(level == -1){
                    level = lvl;
                }
                else if(level != lvl){
                    return false;
                }
            }
            if(curr->left)  q.push({curr->left, lvl+1});
            if(curr->right) q.push({curr->right, lvl+1});
        }
        return true;
    }
};
