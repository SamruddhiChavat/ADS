//CREATE AND DISPLAY GRAPH +  PRIMS
#include<iostream>
#include<cstring>
using namespace std;

class Graph {
    int cost[10][10];
    string cities[10];
    int n;
public:
    Graph() {
        cout << "Enter number of cities: ";
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cost[i][j] = 9999;
            }
            cout << "Enter City name: ";
            cin >> cities[i];
        }
    }
    void createCostMatrix();
    void displayCostMatrix();
    int getId(string city);
    int primsAlgo();
};

int Graph::getId(string city) {
    for(int i = 0; i < n; i++) {
        if(cities[i] == city)
            return i;
    }
    return -1;
}

void Graph::createCostMatrix() {
    int again;
    for(int i = 0; i < n; i++) {
        do {
            string adjCity;
            int j, d, ifPresent, flag = 0;
            cout << "Is there any city adjacent to " << cities[i] << " (1/0)? ";
            cin >> ifPresent;
            if(ifPresent == 1) {
                flag = 1;
                cout << "Enter city adjacent to " << cities[i] << ": ";
                cin >> adjCity;
                j = getId(adjCity);
                if(j == -1) {
                    cout << "City doesn't exist!" << endl;
                } else {
                    if(cost[i][j] == 9999) {
                        cout << "Enter distance to the city: ";
                        cin >> d;
                        cost[i][j] = d;
                        cost[j][i] = d;
                    } else {
                        cout << "Entry already made" << endl;
                    }
                }
                cout << "Do you want to add more adjacent cities? (1/0): ";
                cin >> again;
            } else {
                continue;
            }
        } while(again == 1);
    }
}

void Graph::displayCostMatrix() {
    cout << "Cost matrix:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cost[i][j] == 9999) {
                cout << "INF ";
            } else {
                cout << cost[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int Graph::primsAlgo() {
    string city;
    int nearest[10];
    int t[10][2];
    int minCost = 0, startV, j, r;
    cout << "Enter starting city: ";
    cin >> city;
    startV = getId(city);
    nearest[startV] = -1;
    for(int i = 0; i < n; i++) {
        if(i != startV) {
            nearest[i] = startV;
        }
    }
    r = 0;
    for(int i = 0; i < n - 1; i++) {
        int min = 9999;
        for(int k = 0; k < n; k++) {
            if(nearest[k] != -1 && cost[k][nearest[k]] < min) {
                j = k;
                min = cost[k][nearest[k]];
            }
        }
        t[r][0] = j;
        t[r][1] = nearest[j];
        cout << cities[nearest[j]] << " -> " << cities[j];
        r++;
        minCost += cost[j][nearest[j]];
        cout << "\tCost = " << cost[j][nearest[j]] << endl;
        nearest[j] = -1;
        for(int k = 0; k < n; k++) {
            if(nearest[k] != -1 && cost[k][nearest[k]] > cost[k][j])
                nearest[k] = j;
        }
    }
    cout << endl;
    cout << "Minimum Cost = " << minCost << endl;
    return minCost;
}

int main() {
    Graph g;
    int choice, minCost;
    do {
        cout << "Choose from the following:" << endl;
        cout << "1. Create Graph" << endl;
        cout << "2. Display Graph" << endl;
        cout << "3. Prim's Algorithm" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Creation of graph" << endl;
                cout << endl;
                g.createCostMatrix();
                break;
            case 2:
                cout << "Display of graph" << endl;
                cout << endl;
                g.displayCostMatrix();
                break;
            case 3:
                cout << "PRIM'S ALGORITHM" << endl;
                cout << endl;
                minCost = g.primsAlgo();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while(choice != 4);
    return 0;
}
