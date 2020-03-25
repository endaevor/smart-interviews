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

void preorder(node *root)
{
    if(root!=NULL)
    {
        cout<< root->data <<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<(*root).data<<" ";
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
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
        preorder(root);
        cout<<endl;
        inorder(root);
        cout<<endl;
        postorder(root);
        cout<<endl<<endl;
        delete root;
    }
    return 0;
}
