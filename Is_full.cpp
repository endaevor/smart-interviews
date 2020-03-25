/*
Given an array of unique elements, construct a Binary Search Tree and check if its a Full Binary Tree [FBT]. A FBT is one in which each node is either a leaf or possesses exactly 2 child nodes.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *right,*left;
};

node* newnode(int d)
{
    node* root= (node*)malloc(sizeof(node));
    root->data=d;
    root->left=root->right=NULL;
    return root;
}

node* treecreate(node *root,int n)
{
    
    if(root==NULL)
    {
        node *temp=newnode(n);
        return temp;
    }
    if(n< root->data)
    {
        root->left=treecreate(root->left,n);
    }
    else
    {
        root->right=treecreate(root->right,n);
    }
    return root;
}

bool preorder(node *root)                 // traverse each node and check left and right
{
    if(root!=NULL)
    {
        if((root->left!=NULL && root->right!=NULL) || (root->left==NULL && root->right==NULL))
        {
            return preorder(root->left) && preorder(root->right);
        }
        else
            return false;
    }
    else
        return true;
}

int main() {
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        node *root=NULL;
        for(int i=0;i<n;i++)
        {
            root=treecreate(root,arr[i]);
        }
        if(preorder(root))
        {
            cout<<"True\n";
        }
        else{
            cout<<"False\n";
        }
        delete root;
    }
    return 0;
}
