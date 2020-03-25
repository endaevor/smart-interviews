/*
Given an array of unique elements, construct a Binary Search Tree and check if its a complete tree. In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.
*/

#include <queue>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int x)
    {
        right=left=NULL;
        data=x;
    }
};

node* create(node* root,int data)
{
    if(root==NULL)
    {
        node *temp=new node(data);
        return temp;
    }
    
    if(data < root->data)
    {
        root->left=create(root->left,data);
    }
    else
    {
        root->right=create(root->right,data);
    }
    return root;
}

int n_nodes(node* root)
{
    if(root==NULL)
        return 0;
    
    return (1+n_nodes(root->left)+n_nodes(root->right));     // number of nodes , i dont know why i calucated it because
}                                                            // number of nodes in tree is already given

bool isbalanced(node* root,int idx,int count)
{
    if(root==NULL)                                 //given a node n, if idx value for that node is greater than number of nodes present
        return true;                               // then it is not a balanced tree, left=2*idx+1 ,right=2*idx+2, try with a example.
    else if(idx>=count)
        return false;
    
    return (isbalanced(root->left,2*idx+1,count) && isbalanced(root->right,2*idx+2,count));
}

int main() {
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        node *root=NULL;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            root=create(root,temp);
        }
        int count=n_nodes(root);
        
        if(isbalanced(root,0,count))
        cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
