#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
class BST
{   
    struct node *root;
    public:
    BST()
    {
        root = NULL;
    }
    int NoofLeafNodes(struct node *root)
    {   
        if(root->left==NULL && root->right==NULL)
            return 1;
        return (NoofLeafNodes(root->right)+NoofLeafNodes(root->left));
    }
    int NoofNonLeafNodes_main(struct node *root)
    {
        if(root==NULL)
            return 0;
        return 1+((NoofNonLeafNodes(root->left))+(NoofLeafNodes(root->right)));
    }
    int NoofNonLeafNodes(struct node *root)
    {
        return NoofNonLeafNodes_main(root) - NoofLeafNodes(root);
    }
    int FindMin(struct node *root)
    {
        if(root!=NULL)
        {
            while(root->left!=NULL)
                root=root->left;
            return root->data;
        }
        else
        {
            cout<<"Empty Tree"<<endl;
            return -999;
        }
        
    }
    int FindMax(struct node *root)
    {
        if(root!=NULL)
        {
            while(root->right!=NULL)
                root=root->right;
            return root->data;
        }
        else
        {
            cout<<"Empty Tree"<<endl;
            return -99;
        }   
    }
    int height(struct node *root)
    {
        if(root == NULL)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void PreOrder(struct node *root)
    {
        if(root!=NULL)
        {
            cout<<root->data<<" ";
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }
    void PostOrder(struct node *root)
    {
        if(root!=NULL)
        {
            PostOrder(root->left);
            PostOrder(root->right);
            cout<<root->data<<" ";
        }
    }
    void Inorder(struct node *root)
    {
        if(root!=NULL)
        {
            Inorder(root->left);
            cout<<root->data<<" ";
            Inorder(root->right);
        }
    }
    struct node * Insert(int ele,node *root)
    {
        if(root==NULL)
        {
            struct node *temp;
            temp = new node;
            temp->data = ele; 
            temp->left = NULL;
            temp->right = NULL;
        }
        else
        {
            if(root->data>ele)
            {
                root->right = Insert(ele,root->right);
            }
            else
            {
                root->left = Insert(ele,root->left);
            } 
        }
    }
    struct node* Delete(int ele,struct node *root)
    {
        if(root!=NULL)
        {
            if(ele>root->data)
            {
                root->right = Delete(ele,root->right);
            }
            else if(ele<root->data)
            {
                root->left = Delete(ele,root->left);
            }
            else
            {
                if(root->left!=NULL && root->right!=NULL)
                {
                    root->data = FindMax(root->left);
                    root->left = Delete(root->data,root->left);
                }
                else
                {
                    struct node *temp;
                    temp = root;
                    if(root->left == NULL)
                        root = root->right;   
                    else
                    {
                        root = root->right;
                    }
                    delete temp;
                }
            }
        }
    }
};
int main()
{
    
}