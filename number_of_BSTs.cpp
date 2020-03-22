#include <climits>       //      O(n)
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct range          //range structure
{
    int min;
    int max;
    bool flag;
    int bst=0;
};

class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int x)
    {
        left=right=NULL;
        data=x;
    }
};

node* create(node* root,int *arr,int idx,int n)        //create tree
{
    if(idx<=n)
    {
        if(!root)
        {
            root=new node(arr[idx]);
        }
        root->left=create(root->left,arr,2*idx,n);
        root->right=create(root->right,arr,2*idx+1,n);
    }
    else
        return NULL;
    return root;
}

range n_bst(node* root)            // fn to count number of BSTs , return type structure
{
    if(root==NULL)                         // if root is equal to null
    {
        return {INT_MAX,INT_MIN,true,0};       // check base condition (int max & int min)  #tricky
    }
    if(root->left==NULL && root->right==NULL)        // if leaf node - it is bst
    {
        return {root->data,root->data,true,1};
    }

    range L=n_bst(root->left);                      //left
    range R=n_bst(root->right);                     // right
    
    range temp;                                     //check bst (left.maximum < root.data < right.minimum  && flags)
    
    if( ((root->data < R.min && root->data > L.max)) && L.flag && R.flag ) 
    {
        temp.bst=  1  + L.bst + R.bst ;                      // if bst increase count by 1
        temp.flag=true;
    }
    else
    {
        temp.bst=L.bst+R.bst;
        temp.flag=false;
    }
    
    temp.min=min(root->data,min(L.min,R.min));               // changing range of tree left side
    temp.max=max(root->data,max(L.max,R.max));               // changing range of tree right side
    
    return temp;
}

int main() {                                                  // take an example and revise
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        int arr[n+1];
        node* root=NULL;
        int count=0;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        root=create(root,arr,1,n);
        
        range ans=n_bst(root);
        cout<<ans.bst<<endl;
    }
    return 0;
}

