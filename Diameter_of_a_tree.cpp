#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int ans=0;

class node
{
    public:
    node* left;
    node* right;
    int data;
    node (int x)
    {
        left=right=NULL;
        data=x;
    }
};

node* create(node* root,int x)
{
    if(!root)
    {
        root=new node (x);
        return root;
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

int diameter(node* root)
{
    if(!root)
    {
        return 0;
    }
    int L=diameter(root->left);         
    int R=diameter(root->right);
    int dist=1+L+R;                            // distance till LCA, +1 is to add current node value
    if( dist > ans)                           // update ans if dist is greater
        ans=dist;
    return (L>=R)? L+1 : R+1 ;                // return the max(left dist+1,right dist+1) 
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
        ans=0;
        diameter(root);
        cout<<ans<<endl;
    }
    return 0;
}
