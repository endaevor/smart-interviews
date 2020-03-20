/* The idea is to traverse the tree starting from root. If any of the given keys (n1 and n2) matches with root, 
then root is LCA (assuming that both keys are present). If root doesn’t match with any of the keys, 
we recur for left and right subtree. The node which has one key present in its left subtree and 
the other key present in right subtree is the LCA. If both keys lie in left subtree, then left subtree has LCA also, 
otherwise LCA lies in right subtree. Got TLE in HACKERRANK */

/* another method is to add node data to a vector for n1 and for n2 in another vector
   compare vectors and common element in vectors is LCA */
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node{                                                   // tree class
    public:
    int data;
    node* left;
    node* right;
    node (int x)
    {
        left=right=NULL;
        data=x;
    }
};

node* create(node* root,int x)                            // creating tree
{
    if(root==NULL)
    {
            node *temp = new node(x);
            return temp;
     }
    if(root->data > x)
    {
        root->left=create(root->left,x);
    }
    else
    {
        root->right=create(root->right,x);
    }
    return root;
}

node* LCA(node* root,int n1,int n2)                           //  O(N)      
{
    if(root==NULL)
    {
        return NULL ;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    
    node* Lca_left=LCA(root->left,n1,n2);
    node* Lca_right=LCA(root->right,n1,n2);
    
    if(Lca_left && Lca_right) return root;
    
    return (Lca_left !=NULL)? Lca_left : Lca_right;
}

int main() {
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int q,n;
        cin>>n>>q;
        int temp;
        node* root=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            root=create(root,temp);
        }
        for(int j=0;j<q;j++)
        {
            node* m;
            int n1,n2;
            cin>>n1>>n2;
            if(n1<n2)                  // making sure n1<n2
            {
                m=LCA(root,n1,n2);
                cout<<m->data<<" ";
            }
            else
            {
                m=LCA(root,n2,n1);
                cout<<m->data<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
