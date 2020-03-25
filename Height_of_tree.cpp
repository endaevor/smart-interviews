#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node{
    public:
    node* right;
    int data;
    node* left;
    node(int x)
    {
        data=x;
        right=left=NULL;
    }
};

node* create(node* root,int key)
{
    if(!root)
    {
        node* temp=new node(key);
        return temp;
    }
    else if(key < root->data)
    {
        root->left=create(root->left,key);
    }
    else 
    {
        root->right=create(root->right,key);
    }
    return root;
}

int height(node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    return max(height(root->right),height(root->left)) +1;
}

int main() {
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        int temp;
        node* root=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            root=create(root,temp);
        }
        int ans=height(root);
        cout<<ans<<endl;
        delete root;
    }
    return 0;
}
