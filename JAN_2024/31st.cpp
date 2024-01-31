class Solution

{

    public:

        //Function to insert string into TRIE.

        void insert(struct TrieNode *root, string key)

        {

            // code here

            for (int i=0;i<key.size();i++)

            {

                if (root->children[key[i]-'a']==NULL)

                {root->children[key[i]-'a']=new TrieNode();}

                root=root->children[key[i]-'a'];

            }

            root->isLeaf=true;

        }

        

        //Function to use TRIE data structure and search the given string.

        bool search(struct TrieNode *root, string key) 

        {

            // code here

            for (int i=0;i<key.size();i++)

            {

                if (root->children[key[i]-'a']==NULL) return false;

                root=root->children[key[i]-'a'];

            }

            if (root->isLeaf==true) return true;

            return false;

        }

};

