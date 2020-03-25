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
    node* right;
    node* left;
    node(int x)
    {
        data=x;
        left=right=NULL;
    }
};

node* create(node* root,int x,int num)         // printing depth of each node while creating tree
{
    if(!root)
    {
        cout<<num+1<<" ";
        node* temp=new node(x);
        return temp;
    }
    else if(x< root->data)
    {
        root->left= create (root->left,x,num+1);
    }
    else
    {
        root->right= create(root->right,x,num+1);
    }
    return root;
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
        int num=-1;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            root=create(root,temp,num);
        }
        
        cout<<endl;
    }
    return 0;
}
