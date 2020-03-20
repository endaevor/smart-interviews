#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node{                                                   // tree class O(n)
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

void LCA(node* root,int n1,int n2)                                 /* if n1<n2 ,LCA is "n1< root.data <n2 "
                                                                       else n1 && n2 < root.data move left, else if                                                                                right*/
{
    if(root==NULL)
    {
        return ;
    }
                                                                          //cout<<root->data<<"* 
    if(root->data > n1 && root->data > n2)
    {
        LCA(root->left,n1,n2);
    }
    else if(root->data < n1 && root->data < n2)
    {
        LCA(root->right,n1,n2);
    }
    else
    {
        cout<<root->data<<" ";
        return ;
    }
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
            node* m=root;
            int n1,n2;
            cin>>n1>>n2;
            if(n1<n2)                  // making sure n1<n2
            {
                LCA(m,n1,n2);
            }
            else
            {
                LCA(m,n2,n1);
            }
        }
        cout<<endl;
    }
    return 0;
}
