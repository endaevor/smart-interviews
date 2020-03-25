#include <map>
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
        left=right=NULL;
        data=x;
    }
};

node* treecreate(node *root,int n)
{
    
    if(root==NULL)
    {
        node *temp=new node(n);
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

void vorder(node* root,map <int,vector<int>> &mp,int pos)      // passing map of (int ,vector) to store elements of specific keys
{                                                              // preorder traversal is used
    if(root==NULL)          
    {
        return;
    }
    mp[pos].push_back(root->data);
    vorder(root->left,mp,pos-1);
    vorder(root->right,mp,pos+1);
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
        
        map <int,vector<int>> mp;
        vorder(root,mp,0);
        
        for(auto itr=mp.begin();itr!=mp.end();itr++)               // printing elements of each key
        {
            sort(itr->second.begin(),itr->second.end());
            for(int j=0;j<itr->second.size();j++)
            {
                cout<<itr->second[j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        mp.clear();
    }
    return 0;
}
