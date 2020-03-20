/* passing range of root.data to left and right changing min and max vlaues accordingly */

#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node{
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

node* create(node* root,int idx,int *arr,int n)
{
    if(idx<n)
    {
        if(root==NULL)
        {
            root = new node(arr[idx]);
        }
        root->left=create(root->left,idx*2+1,arr,n);
        root->right=create(root->right,idx*2+2,arr,n);
    }
    else
        return NULL;
    return root;
}

bool isbst(node* root,int min,int max)
{
    if(root==NULL)
    {
        return true;
    }
    
    if(root->data > min && root->data < max)
    {
        return (isbst(root->left,min,root->data) && isbst(root->right,root->data,max));
    }
    else
        return false;
}

int main() {
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        node* root=NULL;
        root=create(root,0,arr,n);
        if(isbst(root,INT_MIN,INT_MAX))
        {
            cout<<"True\n";
        }
        else
        {
            cout<<"False\n";
        }
    }
    return 0;
}
