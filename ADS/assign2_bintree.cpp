/*#include<iostream>
#include<stack>
using namespace std;

class node
{
public:
    char data;
    node *left, *right;
    friend class bintree;
    friend class stack;

    node() : left(nullptr), right(nullptr) {}
};

class Stack
{
    friend class bintree;
    node *st[20];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(node *);
    node *pop();
    int empty();
};

void Stack::push(node *t)
{
    top++;
    st[top] = t;
}

node *Stack::pop()
{
    node *t;
    t = st[top];
    top--;
    return (t);
}

int Stack::empty()
{
    if (top == -1)
        return (1);
    else
        return (0);
}

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
};

void bintree::create_bintree()
{
    root = new node();
    cout << "Enter root data(character): ";
    cin >> root->data;
    root->left = root->right = nullptr;
    Stack s;
    s.push(root);

    while (!s.empty())
    {
        node *temp = s.pop();

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
    if (root == nullptr)
        return;

    Stack s;
    node *current = root;

    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }

        current = s.pop();

        cout << current->data << " ";

        current = current->right;
    }
}

void bintree::preorder_traversal()
{
    if (root == nullptr)
        return;

    Stack s;
    s.push(root);

    while (!s.empty())
    {
        node *current = s.pop();

        cout << current->data << " ";

        if (current->right != nullptr)
            s.push(current->right);

        if (current->left != nullptr)
            s.push(current->left);
    }
}

void bintree::postorder_traversal()
{
    if (root == nullptr)
        return;

    Stack s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        node *current = s1.pop();
        s2.push(current);

        if (current->left != nullptr)
            s1.push(current->left);

        if (current->right != nullptr)
            s1.push(current->right);
    }

    while (!s2.empty())
    {
        node *current = s2.pop();
        cout << current->data << " ";
    }
}

void bintree::inorder_nonrec()
{
    Stack s;
    node *temp = root;

    while (temp != nullptr || !s.empty())
    {
        while (temp != nullptr)
        {
            s.push(temp);
            temp = temp->left;
        }

        if (!s.empty())
        {
            temp = s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}

void bintree::preorder_nonrec()
{
    Stack s;
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
            temp = s.pop();
            temp = temp->right;
        }
    }
}

void bintree::postorder_nonrec() {
    Stack s;
    node *temp = root;
    node *lastVisited = nullptr;

    while (temp != nullptr || !s.empty()) {
        while (temp != nullptr) {
            s.push(temp);
            temp = temp->left;
        }

        node *topNode = s.st[s.top];

        if (topNode->right == nullptr || topNode->right == lastVisited) {
            temp = s.pop();
            cout << temp->data << " ";
            lastVisited = temp;
            temp = nullptr; 
        } else {
            temp = topNode->right;
        }
    }
}

int main()
{
    bintree t;
    t.create_bintree();

    char choice;
    do {
        cout << "\nChoose Traversal: " << endl;
        cout << "1. In-order Traversal" << endl;
        cout << "2. Pre-order Traversal" << endl;
        cout << "3. Post-order Traversal" << endl;
        cout << "4. In-order (Non Recursive) Traversal" << endl;
        cout << "5. Pre-order (Non Recursive) Traversal" << endl;
        cout << "6. Post-order (Non Recursive) Traversal" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "In-order traversal: ";
                t.inorder_traversal();
                break;
            case '2':
                cout << "Pre-order traversal: ";
                t.preorder_traversal();
                break;
            case '3':
                cout << "Post-order traversal: ";
                t.postorder_traversal();
                break;
            case '4':
                cout << "In-order (Non rec) traversal: ";
                t.inorder_nonrec();
                break;
            case '5':
                cout << "Pre-order (Non rec) traversal: ";
                t.preorder_nonrec();
                break;
            case '6':
                cout << "Post-order (Non rec) traversal: ";
                t.postorder_nonrec();
                break;
            case '7':
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice! Please enter a valid choice." << endl;
        }
        cout << endl;
      } while (choice != '7');

    return 0;
}
*/


#include <iostream>
using namespace std;
class treenode
{
	int data;
	treenode *left;
	treenode *right;
	friend class tree;
};

class tree
{
	treenode *root;
	public:
		tree();
		void create_r();
		void create_r(treenode *);
		void inorder_r();
		void inorder_r(treenode *);
		void preorder_r();
		void preorder_r(treenode *);
		void postorder_r();
		void postorder_r(treenode *);
		
		void create_nr();
		void inorder_nr();
		void preorder_nr();
		void postorder_nr();
};

class stack
{
	int top;
	treenode *dataS[30];
	public:
		stack()
		{
			top=-1;
		}
	void push (treenode *temp);
	treenode *pop();
	int empty();
	friend class tree;

};

void stack :: push(treenode *temp)
{
	if (top ==(30-1))
		cout<<"stack full\n";
	else{
		top++;
		dataS[top]=temp;
	}
}

treenode* stack :: pop()
{
	treenode *temp;
	if (top == -1)
	{
		//cout<<"stack empty\n";
		return NULL;
		}
	else
	{
		temp=dataS[top];
		top--;
		return temp;
	}
		
}

int stack :: empty()
{
	if (top == -1)
	{
		//cout<<"stack empty\n";
		return 0;
	}
	else 
		return 1;
}

tree ::tree()
{
	root=NULL;
}

void tree:: create_r()
{
	root= new treenode;
	cout<<"enter the data for root: ";
	cin>>root->data;
	create_r(root);
}

void tree:: create_r(treenode *temp) 
{	
	char ch;
	cout<<"enter y if node to be added left of "<<temp->data;
	cin>>ch;
	if(ch =='y' || ch =='Y')
	{
		treenode *curr= new treenode;
		cout<<"enter data";
		cin>>curr->data;
		temp->left=curr;
		create_r(curr);
	}
	cout<<"enter y if node to be added right of "<<temp->data;
	cin>>ch;
	if(ch=='y' || ch=='Y')
	{
		treenode *curr= new treenode;
		cout<<"enter data";
		cin>>curr->data;
		temp->right=curr;
		create_r(curr);
	}
	
}	
void tree ::inorder_r()
{
	inorder_r(root);
}

void tree ::inorder_r(treenode *temp)
{
	if(temp !=NULL)
	{
		inorder_r(temp->left);
		cout<<temp->data<<" ";
		inorder_r(temp->right);
	}
} 

void tree ::preorder_r()
{
	preorder_r(root);
}

void tree ::preorder_r(treenode *temp)
{
	if(temp !=NULL)
	{
		preorder_r(temp->right);
		preorder_r(temp->left);
		cout<<temp->data<<" ";		
	}
} 

void tree ::postorder_r()
{
	postorder_r(root);
}

void tree ::postorder_r(treenode *temp)
{
	if(temp !=NULL)
	{
		postorder_r(temp->left);
		postorder_r(temp->right);
		cout<<temp->data<<" ";
	}
} 

void tree::create_nr()
{
	char ch;
	
		if(root == NULL)
		{
			root = new treenode();
			cout << "Enter the data: ";
			cin >> root->data;
			root->left = NULL;
			root->right = NULL;
		}
		do
		{
			treenode *temp;
			temp = root;
			int flag = 0;
			treenode *curr;
			curr = new treenode;
			curr->left=NULL;
			curr->right=NULL;
			cout << "Enter the data: ";
			cin >> curr->data;

			while (flag == 0)
			{
				char choice;
				cout << "Enter the choice left(l) or right(r): "<< temp->data <<endl;
				cin >> choice;
				
				if (choice == 'l')
				{
					if (temp->left == NULL)
					{
						temp->left = curr;
						flag = 1;
					}
					else
						temp = temp->left;
				}
				else
				{
					if (choice == 'r')
					{
						if (temp->right == NULL)
						{
							temp->right = curr;
							flag = 1;
						}
						else
							temp = temp->right;
					}
				}
			}
		
		cout << "Do you want to continue?(y/n) : ";
		cin >> ch;

	} while (ch == 'y' || ch == 'Y');
}

void tree::inorder_nr()
{
	stack st;
	treenode *temp= new treenode;
	temp=root;
	while(1)
	{
		while(temp !=NULL)
		{
			st.push(temp);
			temp=temp->left;
		}
		if (st.empty()==0)   //stack empty
			break;
		temp=st.pop();
		cout<<temp->data;
		temp=temp->right;
	}
	cout<<"\n";
}

void tree::preorder_nr()
{
	stack st;
	treenode *temp= new treenode;
	temp=root;
	while(1)
	{
		while(temp !=NULL)
		{	
			cout<<temp->data;
			st.push(temp);
			temp=temp->left;
		}
		if (st.empty()==0)   //stack empty
			break;
		temp=st.pop();		
		temp=temp->right;
	}
	cout<<"\n";
}

void tree::postorder_nr()
{
	stack st;
	treenode *temp= new treenode;
	temp=root;
	while(1)
	{
		while(temp !=NULL)
		{	
			
			st.push(temp);
			temp=temp->left;
		}
		if ( st.dataS[st.top]->right=NULL)
			cout<<temp->data;
		while(st.empty()!=0 && st.dataS[st.top]->right==temp)
		{	
			temp=st.pop();
			cout<<temp->data;
		}
		if (st.empty()==0)   //stack empty
			break;
		temp=st.dataS[st.top]->right;	
		
	}
	cout<<"\n";
}

int main()
{
	tree bt_r;
	int choice1,choice2=0,c1,c2;
	do 
	{
		cout<<"1.binary tree recursive\n";
		cout<<"2.binary tree non recursive\n";
		cout<<"enter choice";
		cin>>choice1;
		while (choice1==1)
		{
			
			cout<<"1.binary tree recursive creation\n";
			cout<<"2.binary tree inorder traversal\n";
			cout<<"3.binary tree preorder traversal\n";
			cout<<"4.binary tree postorder traversal\n";
			cout<<"5.exit to main menu\n";
			cout<<"enter choice";
			cin>>c1;
			switch(c1)
			{	
				case 1:
				bt_r.create_r();
				break;
				case 2:
				bt_r.inorder_r();
				break;
				case 3:
				bt_r.preorder_r();
				break;
				case 4:
				bt_r.postorder_r();
				break;
				default:
				cout<<"wrong choice:";
				break;
			}
			cout<<"enter 1 to continue recursive or 5 to break recursion\n";
			cin>>choice1;
			if (choice1==5)
			 	break;
			
		}

		while (choice1==2)
		{
			tree bt_t;
			cout<<"1.binary tree non recursive creation\n";
			cout<<"2.binary tree inorder traversal nr\n";
			cout<<"3.binary tree preorder traversal nr\n";
			cout<<"4.binary tree postorder traversal nr\n";
			cout<<"5.exit to main menu\n";
			cout<<"enter choice";
			cin>>c2;
			switch(c2)
			{	
				case 1:
				bt_r.create_nr();
				break;
				case 2:
				bt_r.inorder_nr();
				break;
				case 3:
				bt_r.preorder_nr();
				break;
				case 4:
				bt_r.postorder_nr();
				break;
				default:
				cout<<"wrong choice:";
				break;
			}
			cout<<"enter 2 to continue recursive or 5 to break recursion\n";
			cin>>choice1;
			if (choice2==5)
			 	break;					
		}
		cout<<"enter 0 to continue main recursion loop ";
		cin>>choice2;
		return 0;		
	} while (choice2==0);	
}
