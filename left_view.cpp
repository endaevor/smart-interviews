/*
The problem can also be solved using simple recursive traversal. We can keep track of the level of a node by passing a parameter to all recursive calls. The idea is to keep track of the maximum level also. Whenever we see a node whose level is more than maximum level so far, we print the node because this is the first node in its level (Note that we traverse the left subtree before right subtree).
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
 node (int x)
 {
 left=right=nullptr;
 data=x;
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

void leftview(node* root,int *maxlevel,int level)
{
 if(root==nullptr)
 return ;
 
 if(level>*maxlevel)
 {
cout<<root->data<<" ";
 *maxlevel=level;
}
leftview(root->left,maxlevel,level+1);
leftview(root->right,maxlevel,level+1);     // for right view we go right first and then left
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
        int maxlevel;
        maxlevel=-1;
 leftview(root,&maxlevel,0);
 cout<<endl;
}
 return 0;
}
