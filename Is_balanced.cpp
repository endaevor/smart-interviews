/*
Given an array of unique elements, construct a Binary Search Tree and check if its balanced. A tree is said to be balanced if for every node, the difference between the height of its child nodes is not greater than 1.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    int height=0;                 // height of node
    bool flag;                    // flag for is_balanced
    node (int x)
    {
        left=right=nullptr;
        data=x;
        height=0;
        flag=true;
    }
};

node* create(node* root,int x)
{
    if(root==nullptr)
    {
    root=new node(x);
    return root;
    }
 
    if(x < root->data)
    {
        root->left=create(root->left,x);
    }
    else
    {
        root->right=create(root->right,x);
    }
    return root;
}

int height(node* root)
{
    if(root==nullptr)
        return 0;
    int l=height(root->left);
    int h=height(root->right);
    if(abs(l-h)<=1)
        root->flag=true;
    else
        root->flag=false;
    root->height=max(l,h);
    
    return root->height+1;
}

bool isbalanced(node* root)
{
   
    if(root==nullptr)
        return true;
    
    if(root->flag)                                                                // top to bottom
    {
        return (isbalanced(root->left) && isbalanced(root->right));               // checking every node
    }
    else
    {
        return false;
    }
}

int main() {
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        int temp;
        node* root=nullptr;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            root=create(root,temp);
        }
        height(root);
        if(isbalanced(root))
            cout<<"Yes\n";
        else
            cout<<"No\n";
        
    }
    return 0;
}
