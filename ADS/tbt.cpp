//THREADED BINARY TREE CREATION, PREORDER INODER

#include <iostream>
using namespace std;
class node
{
    int data;
    int lbit;
    int rbit;    
    node *left;
    node *right;
    friend class TBT;
};
class TBT
{
    node *root;
    node *head;
    public:
        void create();
        void preorder(node *root);
        void preorder();
        node* inorder_successor(node *temp);
        void inorder();
};
void TBT :: create()
{
    head = new node();
    root = new node();
    int flag = 1;
    char ch;
    cout<<"Enter Root data\n";
    cin>>root->data;
    head->left=root;
    head->right=head;
    root->left=root->right=head;
    head->lbit=head->rbit= 1;
    root->lbit=root->rbit= 0;
    do
    {
        node *temp = root;
        node *curr = new node();
        cout<<"Enter data for next node\n";
        cin>>curr->data;
        int flag = 1;
        while(flag == 1)
        {
            cout<<"Enter where you want to join the Node: Right(R)/Left(L)\n";
            cin>>ch;
            if(ch == 'L')
            {
                if(temp->lbit == 0)
                {
                    curr->left = temp->left;
                    temp->left = curr;
                    curr->right = temp;
                    temp->left = curr;
                    curr->lbit = curr->rbit = 0;
                    temp->lbit = 1;
                    flag = 1;
                    break;
                }
                else
                {
                    temp = temp->left;
                    flag = 1;
                }
            }
            else
            {
                if(temp->rbit == 0)
                {
                    curr->right = temp->right;
                    temp->right = curr;
                    curr->left = temp;
                    temp->left = curr;
                    curr->lbit = curr->rbit = 0;
                    temp->rbit = 1;
                    flag = 0;
                    break;
                }
                else
                {
                    temp = temp->right;
                }    
            }    
        }
        cout<<"Do you want to add data to the tree? : Yes(Y) or No(N)\n";
        cin>>ch;
    }while(ch == 'Y');
}
void TBT :: preorder(node *root)
{
    node *temp = head->left;
    while(temp != head)
    {
        cout<<temp->data<<" ";
        while(temp->lbit != 0)
        {
            temp = temp->left;
            cout<<temp->data<<" ";
        }
        while(temp->rbit == 0)
        {
            temp = temp->right;
        }
        if(temp->rbit == 1)
        {
            temp = temp->right;
        }
    }
}
void TBT :: preorder()
{
    preorder(root);
}
node* TBT :: inorder_successor(node *temp)
{
    node *x = temp->right;
    if(temp->rbit == 1)
    {
    	while(x->lbit != 0)
    	{
    		x = x->left;
    	}
    }
    return (x);
}
void TBT :: inorder()
{
    node *temp = head;
    while(1)
    {
        temp = inorder_successor(temp);
        if(temp == head)
        {
        	break;
        }
        else
        {
        	cout<<temp->data<<" ";
        }
    }
}
int main()
{
    TBT b1;
    cout<<"Creation of Threaded Binary Tree \n";
    b1.create();
    cout<<endl;
    cout<<"Preorder Traversal of Threaded Binary Tree\n";
    b1.preorder();
    cout<<endl;
    cout<<"Inorder Traversal of Threaded Binary Tree\n";
    b1.inorder();
    cout<<endl;
}


