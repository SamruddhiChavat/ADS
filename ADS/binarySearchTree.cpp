#include<iostream>
#include<queue>
using namespace std;
class treenode {
string word;
string meaning;
treenode * left;
treenode * right;
friend class tree;
};
class Queue {
int front, back;
treenode * data[30];
public:
Queue();
void enqueue(treenode * temp);
treenode * dequeue();
int isEmpty();
friend class tree;
};
Queue::Queue() {
front = -1;
back = -1;
}
void Queue::enqueue(treenode * temp) {
back++;
data[back] = temp;
}
treenode * Queue::dequeue() {
front++;
return data[front];
}
int Queue::isEmpty() {
if (front == back) {
return 1;
}
return 0;
}
class tree {
treenode * root;
Queue * q = new Queue();

public:
tree();
void create_nr();
void inorder_r();
void inorder_r(treenode * temp);
void bfs();
void search_r();
int search_r(treenode * temp, string word);
void search_nr();
void delete_nr();
void copy();
treenode * copy(treenode * temp);
void mirror_r();
void mirror_r(treenode * temp);
void mirror_nr();
};
tree::tree() {
root = NULL;
}
void tree::create_nr() {
root = new treenode();
string word;
string meaning;
cout << "Enter word of root node: \n";
cin >> word;
cout << "Enter meaning of word: \n";
cin >> meaning;
root -> word = word;
root -> meaning = meaning;
root -> left = NULL;
root -> right = NULL;
char ch = 'y';
do {
treenode * temp = root;
int flag = 0;
treenode * curr = new treenode();
curr -> left = NULL;
curr -> right = NULL;
string word;
string meaning;
cout << "Enter word of node:\n";
cin >> word;
cout << "Enter meaning of word: \n";
cin >> meaning;
curr -> word = word;
curr -> meaning = meaning;
while (flag == 0) {
if (curr -> word < temp -> word) {

if (temp -> left == NULL) {
temp -> left = curr;
flag = 1;
} else {
temp = temp -> left;
}
} else {
if (temp -> right == NULL) {
temp -> right = curr;
flag = 1;
} else {
temp = temp -> right;
}
}
}
cout << "Add more nodes? (y/n): \n";
cin >> ch;
} while (ch == 'y');
}
void tree::inorder_r() {
inorder_r(root);
}
void tree::inorder_r(treenode * temp) {
if (temp != NULL) {
inorder_r(temp -> left);
cout << temp -> word << " ";
inorder_r(temp -> right);
}
}
void tree::bfs() {
if (root == NULL) {
cout << "Tree Empty\n";
return;
}
int p = 1, r = 0;
treenode * temp = root;
q -> enqueue(temp);
cout << "\nBFS: \n";
while (q -> isEmpty() == 0) {
for (int i = 0; i < p; i++) {
temp = q -> dequeue();
cout << temp -> word << " ";
if (temp -> left != NULL) {
q -> enqueue(temp -> left);
r++;
}
if (temp -> right != NULL) {
q -> enqueue(temp -> right);

r++;
}
}
cout << endl;
p = r;
r = 0;
}
cout << "\n";
}
void tree::search_r() {
int flag = 0;
string word;
string meaning;
cout << "Enter word to search: \n";
cin >> word;
flag = search_r(root, word);
if (flag == 1) {
cout << word << " has been found.\n";
} else {
cout << word << " is not present in bst.\n";
}
}
int tree::search_r(treenode * temp, string word) {
int flag = 0;
if (temp != NULL) {
if (word == temp -> word) {
return 1;
}
if (word < temp -> word) {
flag = search_r(temp -> left, word);
}
if (word > temp -> word) {
flag = search_r(temp -> right, word);
}
}
return flag;
}
void tree::search_nr() {
int flag = 0;
treenode * temp = root;
string word;
string meaning;
cout << "Enter word to search: \n";
cin >> word;
while (temp != NULL) {
if (word == temp -> word) {
flag = 1;
break;

} else if (word < temp -> word) {
temp = temp -> left;
} else {
temp = temp -> right;
}
}
if (flag == 1) {
cout << word << " has been found\n";
} else {
cout << word << " is not present in bst\n";
}
}
void tree::delete_nr() {
int flag = 0;
treenode * parent = NULL;
treenode * curr = root;
string word;
string meaning;
cout << "Enter word to delete: \n";
cin >> word;
while (curr != NULL) {
if (word == curr -> word) {
flag = 1;
break;
} else if (word < curr -> word) {
parent = curr;
curr = curr -> left;
} else {
parent = curr;
curr = curr -> right;
}
}
if (flag != 1) {
cout << word << " is not present in bst\n";
return;
}
treenode * temp = NULL;
if (curr == root) {
if (curr -> right == NULL) {
root = root -> left;
} else if (curr -> left == NULL) {
root = root -> right;
} else if (curr -> left == NULL && curr -> right == NULL) {
temp = curr -> left;
root = curr -> right;
treenode * s = curr -> right;
while (s -> left != NULL) {
s = s -> left;

}
s -> left = temp;
}
} else {
if (curr -> left == NULL && curr -> right == NULL) {
if (parent -> left == curr) {
parent -> left = NULL;
} else {
parent -> right = NULL;
}
} else if (curr -> left == NULL) {
if (parent -> left == curr) {
parent -> left = curr -> right;
} else {
parent -> right = curr -> right;
}
} else if (curr -> right == NULL) {
if (parent -> left == curr) {
parent -> left = curr -> left;
} else {
parent -> right = curr -> left;
}
} else {
treenode * s = curr -> right;
temp = curr -> left;
while (s -> left != NULL) {
s = s -> left;
}
s -> left = temp;
if (parent -> left == curr) {
parent -> left = curr -> right;
} else {
parent -> right = curr -> left;
}
}
}
curr -> left = NULL;
curr -> right = NULL;
delete curr;
}
void tree::copy() {
tree new_bst;
new_bst.root = copy(root);
cout << "New tree is: \n";
new_bst.bfs();
}
treenode * tree::copy(treenode * root) {
treenode * temp = NULL;

if (root != NULL) {
temp = new treenode();
temp -> word = root -> word;
temp -> left = copy(root -> left);
temp -> right = copy(root -> right);
}
return temp;
}
void tree::mirror_r() {
mirror_r(root);
cout << "\nMirror tree is:\n";
bfs();
}
void tree::mirror_r(treenode * root) {
treenode * temp = root -> left;
root -> left = root -> right;
root -> right = temp;
if (root -> left != NULL) {
mirror_r(root -> left);
}
if (root -> right != NULL) {
mirror_r(root -> right);
}
}
void tree::mirror_nr() {
treenode * temp = root;
q -> enqueue(temp);
while (q -> isEmpty() == 0) {
temp = q -> dequeue();
treenode *
var = temp -> left;
temp -> left = temp -> right;
temp -> right =
var;
if (temp -> left != NULL) {
q -> enqueue(temp -> left);
}
if (temp -> right != NULL) {
q -> enqueue(temp -> right);
}
}
cout << "\nMirror tree is:\n";
bfs();
}
int main() {
tree bst;
int n;
do {

cout << "\nOptions:\n";
cout << "1 - Create dictionary\n";
cout << "2 - Display using inorder traversal\n";
cout << "3 - Display using BFS\n";
cout << "4 - Search using recursion\n";
cout << "5 - Search not using recursion\n";
cout << "6 - Delete a node\n";
cout << "7 - Copy the BST\n";
cout << "8 - Mirror BST using recursion\n";
cout << "9 - Mirror BST not using recursion\n";
cout << "10 - Exit\n";
cout << "Enter your choice: ";
cin >> n;
switch (n) {
case 1:
bst.create_nr();
break;
case 2:
bst.inorder_r();
break;
case 3:
bst.bfs();
break;
case 4:
bst.search_r();
break;
case 5:
bst.search_nr();
break;
case 6:
bst.delete_nr();
cout << "\n";
bst.inorder_r();
break;
case 7:
bst.copy();
break;
case 8:
bst.mirror_r();
break;
case 9:
bst.mirror_nr();
break;
case 10:
cout << "Exiting...\n";
break;
default:
cout << "Wrong input\n";

break;
}
} while (n != 10);
return 0;
}















/*#include <iostream>
#include <queue>
using namespace std;

class node {
    string word;
    string mean;
    node *left;
    node *right;
    friend class BST;
};

class BST {
    node *root;

public:
    BST() {
        root = nullptr;
    }
    
    void BST_non_rec();
    void create_BST(node *root);
    void preorder(node *root);
    void inorder(node *root);
    void postorder(node *root);
    void preorder();
    void inorder();
    void postorder();
    node* copy_rec(node *root);
    void copy_rec();
    void mirror_rec(node *root);
    void mirror_rec();
    void BFS_traversal(node *root);
    void BFS_traversal();
};

void BST::BST_non_rec() {
    root = new node();
    cout << "Enter the word for Root node: ";
    cin >> root->word;
    cout << endl;
    cout << "Enter the meaning of the word you entered: ";
    cin >> root->mean;
    cout << endl;
    root->left = root->right = nullptr;
    create_BST(root);
}

void BST::create_BST(node *root) {
    char choice;    
    do {
        int flag = 0;
        node *temp = root;
        node *curr = new node();
        cout << "Enter the word for next node: ";
        cin >> curr->word;
        cout << endl;
        cout << "Enter the meaning of the word you entered: ";
        cin >> curr->mean;
        cout << endl;
        curr->left = curr->right = nullptr;
        while (flag == 0) {
            if (curr->word <= temp->word) {
                if (temp->left == nullptr) {
                    temp->left = curr;
                    flag = 1;
                    break;
                } else {
                    temp = temp->left;
                    flag = 0;
                }
            } else {
                if (temp->right == nullptr) {
                    temp->right = curr;
                    flag = 1;
                    break;
                } else {
                    temp = temp->right;
                    flag = 0;
                }
            }
        }
        cout << "Do you want to add data to the tree? (Yes(Y) or No(N)): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void BST::preorder(node *root) {
    if (root != nullptr) {
        cout << root->word << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BST::preorder() {
    preorder(root);
}

void BST::inorder(node *root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->word << " ";
        inorder(root->right);
    }
}

void BST::inorder() {
    inorder(root);
}

void BST::postorder(node *root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->word << " ";
    }
}

void BST::postorder() {
    postorder(root);
}

node* BST::copy_rec(node *root) {
    node *temp = nullptr;
    if (root != nullptr) {
        temp = new node();
        temp->word = root->word;
        temp->mean = root->mean;
        temp->left = copy_rec(root->left);
        temp->right = copy_rec(root->right);
    }
    return temp;
}

void BST::copy_rec() {
    node *t1 = copy_rec(root);
    inorder(t1);
}

void BST::mirror_rec(node *root) {
    if (root != nullptr) {
        node *t2 = root->right;
        root->right = root->left;
        root->left = t2;    
        if (root->left != nullptr) {
            mirror_rec(root->left);
        }
        if (root->right != nullptr) {
            mirror_rec(root->right);
        }
    }
}

void BST::mirror_rec() {
    mirror_rec(root);
}

void BST::BFS_traversal(node *root) {
    if (root == nullptr)
        return;
    
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();
        cout << temp->word << " ";
        
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

void BST::BFS_traversal() {
    BFS_traversal(root);
}

int main() {
    BST b1;
    int choice;
    do {
        cout << "\n1. Create BST (Non-recursive)\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Copy of BST (Recursive)\n";
        cout << "6. Mirror Image of BST (Recursive)\n";
        cout << "7. BFS Traversal\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Creation of Binary Search Tree\n";
                b1.BST_non_rec();
                break;
            case 2:
                cout << "Preorder Traversal of Binary Search Tree\n";
                b1.preorder();
                cout << endl;
                break;
            case 3:
                cout << "Inorder Traversal of Binary Search Tree\n";
                b1.inorder();
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal of Binary Search Tree\n";
                b1.postorder();
                cout << endl;
                break;
            case 5:
                cout << "Copy of Binary Search Tree\n";
                b1.copy_rec();
                cout << endl;
                break;
            case 6:
                cout << "Mirror image of Binary Search Tree\n";
                b1.mirror_rec();
                b1.inorder();
                cout << endl;
                break;
            case 7:
                cout << "Level-wise Traversal of Binary Search Tree\n";
                b1.BFS_traversal();
                cout << endl;
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
                break;
        }
    } while (choice != 8);

    return 0;
}
*/