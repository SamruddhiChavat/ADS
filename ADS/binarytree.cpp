#include<iostream>
#include<stack>
using namespace std;

class node
{
public:
    char data;
    node *left, *right;
    friend class bintree;

    node() : left(nullptr), right(nullptr) {}
};

class bintree
{
public:
    node *root;

    bintree() : root(nullptr) {}
    void create_bintree();
    void inorder_traversal();
    void preorder_traversal();
    void postorder_traversal();
    void preorder_nonrec();
    void inorder_nonrec();
    void postorder_nonrec();
    
private:
    void inorder_traversal_recursive(node* root);
    void preorder_traversal_recursive(node* root);
    void postorder_traversal_recursive(node* root);
};

void bintree::create_bintree()
{
    root = new node();
    cout << "Enter root data: ";
    cin >> root->data;
    root->left = root->right = nullptr;
    stack<node*> s; 
    s.push(root);

    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();

        char choice;
        cout << "Do you want to add left child for " << temp->data << " (y/n)? ";
        cin >> choice;

        if (choice == 'y')
        {
            node *leftChild = new node();
            cout << "Enter left child data for " << temp->data << ": ";
            cin >> leftChild->data;
            leftChild->left = leftChild->right = nullptr;
            temp->left = leftChild;
            s.push(leftChild);
        }

        cout << "Do you want to add right child for " << temp->data << " (y/n)? ";
        cin >> choice;

        if (choice == 'y')
        {
            node *rightChild = new node();
            cout << "Enter right child data for " << temp->data << ": ";
            cin >> rightChild->data;
            rightChild->left = rightChild->right = nullptr;
            temp->right = rightChild;
            s.push(rightChild);
        }
    }
}

void bintree::inorder_traversal()
{
    inorder_traversal_recursive(root);
    cout << endl;
}

void bintree::preorder_traversal()
{
    preorder_traversal_recursive(root);
    cout << endl;
}

void bintree::postorder_traversal()
{
    postorder_traversal_recursive(root);
    cout << endl;
}

void bintree::inorder_nonrec()
{
    std::stack<node*> s;
    node *temp = root;

    while (temp != nullptr || !s.empty())
    {
        while (temp != nullptr)
        {
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();

        cout << temp->data << " ";

        temp = temp->right;
    }
}

void bintree::preorder_nonrec()
{
    std::stack<node*> s;
    node *temp = root;

    while (temp != nullptr || !s.empty())
    {
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            s.push(temp);
            temp = temp->left;
        }

        if (!s.empty())
        {
            temp = s.top();
            s.pop();
            temp = temp->right;
        }
    }
}

void bintree::postorder_nonrec() {
    std::stack<node*> s;
    node *temp = root;
    node *lastVisited = nullptr;

    while (temp != nullptr || !s.empty()) {
        while (temp != nullptr) {
            s.push(temp);
            temp = temp->left;
        }

        node *topNode = s.top();

        if (topNode->right == nullptr || topNode->right == lastVisited) {
            cout << topNode->data << " ";
            lastVisited = topNode;
            s.pop();
        } else {
            temp = topNode->right;
        }
    }
}

void bintree::inorder_traversal_recursive(node* root)
{
    if (root == nullptr)
        return;

    inorder_traversal_recursive(root->left);
    cout << root->data << " ";
    inorder_traversal_recursive(root->right);
}

void bintree::preorder_traversal_recursive(node* root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder_traversal_recursive(root->left);
    preorder_traversal_recursive(root->right);
}

void bintree::postorder_traversal_recursive(node* root)
{
    if (root == nullptr)
        return;

    postorder_traversal_recursive(root->left);
    postorder_traversal_recursive(root->right);
    cout << root->data << " ";
}

int main()
{
    char choice;
    bintree t;
    bool treeCreated = false;

    do {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Create binary tree" << endl;
        cout << "2. In-order traversal" << endl;
        cout << "3. Pre-order traversal" << endl;
        cout << "4. Post-order traversal" << endl;
        cout << "5. In-order (Non rec) traversal" << endl;
        cout << "6. Pre-order (Non rec) traversal" << endl;
        cout << "7. Post order (Non rec) traversal" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case '1':
                t.create_bintree();
                treeCreated = true;
                break;
            case '2':
                if (treeCreated) {
                    cout << "In-order traversal: ";
                    t.inorder_traversal();
                    cout << endl;
                } else {
                    cout << "Binary tree has not been created yet. Please create a tree first." << endl;
                }
                break;
            case '3':
                if (treeCreated) {
                    cout << "Pre-order traversal: ";
                    t.preorder_traversal();
                    cout << endl;
                } else {
                    cout << "Binary tree has not been created yet. Please create a tree first." << endl;
                }
                break;
            case '4':
                if (treeCreated) {
                    cout << "Post-order traversal: ";
                    t.postorder_traversal();
                    cout << endl;
                } else {
                    cout << "Binary tree has not been created yet. Please create a tree first." << endl;
                }
                break;
            case '5':
                if (treeCreated) {
                    cout << "In-order (Non rec) traversal: ";
                    t.inorder_nonrec();
                    cout << endl;
                } else {
                    cout << "Binary tree has not been created yet. Please create a tree first." << endl;
                }
                break;
            case '6':
                if (treeCreated) {
                    cout << "Pre-order (Non rec) traversal: ";
                    t.preorder_nonrec();
                    cout << endl;
                } else {
                    cout << "Binary tree has not been created yet. Please create a tree first." << endl;
                }
                break;
            case '7':
                if (treeCreated) {
                    cout << "Post order (Non rec) traversal: ";
                    t.postorder_nonrec();
                    cout << endl;
                } else {
                    cout << "Binary tree has not been created yet. Please create a tree first." << endl;
                }
                break;
            case '8':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != '8');

    return 0;
}
