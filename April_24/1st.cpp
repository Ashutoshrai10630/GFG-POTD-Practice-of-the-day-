// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
  void mergeArray(vector<int>&v,int low,int mid,int high,int &c)
  {
      vector<int>temp;
      int left = low;
      int right = mid+1;
      while(left<=mid and right <= high)
      {
          if(v[left] <= v[right])
          {
            
              temp.push_back(v[left++]);
          }
          else
          { c +=  mid-left+1;
              
              temp.push_back(v[right++]);
          }
          
      }
      while(left<=mid)
      {
          temp.push_back(v[left++]);
         // c++;
      }
      while(right<=high)
      {
          temp.push_back(v[right++]);
         // c++;
      }
      for(int i = low;i<=high;i++)
      {
          v[i] = temp[i-low];
      }
  }
  void mergeSort(vector<int>&v,int low,int high,int &c)
  {
      if(low >= high)
      return;
      int mid = (low+high) / 2;
      mergeSort(v,low,mid,c);
      mergeSort(v,mid+1,high,c);
      mergeArray(v,low,mid,high,c);
  }
void inorder(Node* root,vector<int>&v)
{
    if(root==NULL)
    return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        vector<int>v;
        inorder(root,v);
        int ans = 0;
        mergeSort(v,0,n-1,ans);
        return ans;
        }
};