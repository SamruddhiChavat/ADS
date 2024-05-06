#include <iostream>
using namespace std;
class node 
{
    int data;
    node* left;
    node* right;
    friend class AVL;
};
class AVL 
{
    node* root;
public:
    AVL() 
    {
        root = nullptr;
    }
    void create_avl();
    node* insert(node* root, int key);
    node* balance(node* temp);
    int balance_factor(node* temp);
    int height(node* temp);
    node* LL_rotation(node* parent);
    node* RR_rotation(node* parent);
    node* LR_rotation(node* parent);
    node* RL_rotation(node* parent);
    void inorder(node* temp);
    void inorder();
};

void AVL::create_avl() 
{
    char choice;
    int key;
    do 
    {
        cout << "Enter key to insert: ";
        cin >> key;
        root = insert(root, key);
        cout << "Do you want to insert another key? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

node* AVL::insert(node* root, int key) 
{
    if (root == nullptr) 
    {
        root = new node;
        root->data = key;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return balance(root);
}

node* AVL::balance(node* temp) 
{
    int bal_factor = balance_factor(temp);
    if (bal_factor > 1) 
    {
        if (balance_factor(temp->left) > 0) 
        {
            cout << "LL Rotation Applied" << endl;
            return LL_rotation(temp);
        } 
        else 
        {
            cout << "LR Rotation Applied" << endl;
            return LR_rotation(temp);
        }
    } 
    else if (bal_factor < -1) 
    {
        if (balance_factor(temp->right) > 0) 
        {
            cout << "RL Rotation Applied" << endl;
            return RL_rotation(temp);
        } 
        else 
        {
            cout << "RR Rotation Applied" << endl;
            return RR_rotation(temp);
        }
    }
    return temp;
}
int AVL::balance_factor(node* temp) 
{
    if (temp == nullptr)
        return 0;
    return height(temp->left) - height(temp->right);
}
int AVL::height(node* temp) 
{
    if (temp == nullptr)
        return 0;
    return 1 + max(height(temp->left), height(temp->right));
}
node* AVL::LL_rotation(node* parent) 
{
    node* temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
node* AVL::RR_rotation(node* parent) 
{
    node* temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
node* AVL::LR_rotation(node* parent) 
{
    parent->left = RR_rotation(parent->left);
    return LL_rotation(parent);
}
node* AVL::RL_rotation(node* parent) 
{
    parent->right = LL_rotation(parent->right);
    return RR_rotation(parent);
}
void AVL::inorder(node* temp) 
{
    if (temp != nullptr) 
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}
void AVL::inorder() 
{
    inorder(root);
}
int main() 
{
    AVL tree;
    cout << "Creation of AVL Tree\n";
    tree.create_avl();
    cout << "\nInorder Traversal of AVL tree: ";
    tree.inorder();
    cout << endl;
    return 0;
}
