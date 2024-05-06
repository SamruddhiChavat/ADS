//BFT DFT
#include<iostream>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

class node {
public:
    int user_id;
    string user_data;
    node* next;
};

class graph {
public:
    void create_adj_list();
    void display();
    node* head[14];
    int visited[16];
    int n;

    graph() {
        cout << "Enter the number of vertices (up to 14): ";
        cin >> n;
    }

    void DFT_recursive();
    void DFT_rec(int);
    void DFT_nonrec();
    void BFT_nonrec();
};

void graph::create_adj_list() {
    char ch, choice;
    node* temp, * curr;

    for (int i = 0; i < n; i++) {
        head[i] = new node();
        head[i]->user_id = i;
        cout << "Enter the name of user " << i << ": ";
        cin >> head[i]->user_data;
        head[i]->next = NULL;
    }

    for (int i = 0; i < n; i++) {
        temp = head[i];
        do {
            cout << "Is there any vertex connected with user " << head[i]->user_id << " ? (y/n): ";
            cin >> ch;
            if (ch == 'y') {
                curr = new node();
                cout << "Enter connected user_id: ";
                cin >> curr->user_id;
                curr->user_data = head[curr->user_id]->user_data;
                cout << "The connected name is : " << curr->user_data << endl;
                curr->next = NULL;
                temp->next = curr;
                temp = curr;
            }
            cout << "Do you want to add more? (y/n): ";
            cin >> choice;
        } while (choice == 'y');
    }
}

void graph::display() {
    for (int i = 0; i < n; i++) {
        node* temp = head[i]->next;
        cout << "The connections of user " << head[i]->user_id << " are: " << endl;
        while (temp != NULL) {
            cout << "User ID: " << temp->user_id << ", Name: " << temp->user_data << endl;
            temp = temp->next;
        }
    }
}

void graph::DFT_recursive() {
    int v;
    cout << "Enter start vertex id: ";
    cin >> v;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    visited[v] = 1;
    DFT_rec(v);
}

void graph::DFT_rec(int v) {
    cout << v << "->" << head[v]->user_data << endl;
    visited[v] = 1; 
    node* temp = head[v]->next;
    while (temp != NULL) {
        if (visited[temp->user_id] == 0) {
        
            DFT_rec(temp->user_id);
        }
        temp = temp->next;
    }
}


void graph::DFT_nonrec() {
    int v;
    cout << "Enter start vertex id: ";
    cin >> v;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    visited[v] = 1;
    s.push(v);
    while (!s.empty()) {
        v = s.top();
        s.pop();
        cout << v << "->" << head[v]->user_data << endl;
        node* temp = head[v]->next;
        while (temp != NULL) {
            if (visited[temp->user_id] == 0) {
                s.push(temp->user_id);
                visited[temp->user_id] = 1;
            }
            temp = temp->next;
        }
    }
}

void graph::BFT_nonrec() {
    int v;
    cout << "Enter start vertex id: ";
    cin >> v;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    visited[v] = 1;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        cout << v << "->" << head[v]->user_data << endl;
        node* temp = head[v]->next;
        while (temp != NULL) {
            if (visited[temp->user_id] == 0) {
                q.push(temp->user_id);
                visited[temp->user_id] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    graph g;
    g.create_adj_list();
    g.display();
    int choice;
    do {
        cout << "Choose traversal method:" << endl;
        cout << "1. Depth-First Traversal (Recursive)" << endl;
        cout << "2. Depth-First Traversal (Non-Recursive)" << endl;
        cout << "3. Breadth-First Traversal (Non-Recursive)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            g.DFT_recursive();
            break;
        case 2:
            g.DFT_nonrec();
            break;
        case 3:
            g.BFT_nonrec();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
