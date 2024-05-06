#include <iostream>
using namespace std;

class Heap
{
    int marks[20];

public:
    void accept(int n);
    void display(int n, int flag);
    void heapSort(int n, int order);
    void adjust(int n, int i);
};

void Heap::accept(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter marks of student " << i + 1 << " :";
        cin >> marks[i];
    }
}

void Heap::display(int n, int flag)
{
    cout << "\nMarks of students :";
    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << '\t';
    }
    if (flag == 0)
    {
        cout << "\nMinimum marks are: " << marks[0] << endl;
        cout << "Maximum marks are: " << marks[n - 1] << endl;
    }
}

void Heap::heapSort(int n, int order)
{
    int i, t;
    for (i = (n - 1) / 2; i >= 0; i--)
        adjust(n, i);
    
    if (order == 0)
        cout << "Max heap is:\n";
    else
        cout << "Min heap is:\n";

    display(n, 1);

    while (n > 0)
    {
        t = marks[0];
        marks[0] = marks[n - 1];
        marks[n - 1] = t;
        n--;
        adjust(n, 0);
    }
}

void Heap::adjust(int n, int i)
{
    int j, temp;
    while (2 * i + 1 < n)
    {
        j = 2 * i + 1;
        if ((j + 1 < n) && marks[j + 1] > marks[j])
            j = j + 1;
        
        if (marks[i] > marks[j])
            break;
        else
        {
            temp = marks[i];
            marks[i] = marks[j];
            marks[j] = temp;
        }
        i = j;
    }
}

int main()
{
    Heap h;
    int n, choice;
    cout << "Enter the number of students appearing for exam: ";
    cin >> n;
    h.accept(n);
    h.display(n, 0);
    
    cout << "\nChoose sorting order:\n";
    cout << "1. Ascending (Min heap)\n";
    cout << "2. Descending (Max heap)\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        h.heapSort(n, 0);
        cout << "\nSorted marks in ascending order:\n";
        h.display(n, 0);
        break;

    case 2:
        h.heapSort(n, 1);
        cout << "\nSorted marks in descending order:\n";
        h.display(n, 0);
        break;

    default:
        cout << "Invalid choice!";
        break;
    }

    return 0;
}
