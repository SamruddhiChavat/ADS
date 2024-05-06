#include <iostream>
#include <fstream>
using namespace std;

#define MAX 10

class Record
{
    int roll_no;
    string name;
    char grade;

public:
    Record()
    {
        roll_no = -1;
        name = "";
        grade = ' ';
    }
    friend class Hashing;
    friend class Student;
};

class Hashing
{
    int roll_no, pos;

public:
    Hashing()
    {
    }
    friend class Student;
};

class Student
{
    Hashing h[10];
    int s, relt;

public:
    Student()
    {
        s = sizeof(Record);
        for (int i = 0; i < MAX; i++)
        {
            h[i].roll_no = -1;
            h[i].pos = -1;
        }
        relt = 0;
    }
    void create_without_replacement();
    void create_with_replacement();
    void retrieve();
    void display(Record rec);
    void display_all();
    void modify();
};

void Student::create_without_replacement()
{
    Record rec;
    fstream f;
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    f.open("studentdetail.txt", ios::binary | ios::out | ios::app); // Open file in append mode
    if (!f)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    for (int loop = 0; loop < n; loop++)
    {
        cout << "Enter student roll no: ";
        cin >> rec.roll_no;
        cout << "Enter student name: ";
        cin >> rec.name;
        cout << "Enter student grade: ";
        cin >> rec.grade;
        int loc = (rec.roll_no) % 10;
        if (h[loc].roll_no == -1)
        {
            h[loc].roll_no = rec.roll_no;
            h[loc].pos = relt;
            f.write((char *)&rec, s);
            relt++;
        }
        else
        {
            int j = (loc + 1) % MAX;
            while (j != loc)
            {
                if (h[j].roll_no == -1)
                {
                    h[j].roll_no = rec.roll_no;
                    h[j].pos = relt;
                    f.write((char *)&rec, s);
                    relt++;
                    break;
                }
                j = (j + 1) % MAX;
            }
            if (j == loc)
                cout << "Hash table full" << endl;
        }
    }
    f.close(); // Close the file after writing
}

void Student::create_with_replacement()
{
    Record rec;
    fstream f;
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    f.open("studentdetail.txt", ios::binary | ios::out | ios::app); // Open file in append mode
    if (!f)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    for (int loop = 0; loop < n; loop++)
    {
        cout << "Enter student roll no: ";
        cin >> rec.roll_no;
        cout << "Enter student name: ";
        cin >> rec.name;
        cout << "Enter student grade: ";
        cin >> rec.grade;
        int loc = (rec.roll_no) % 10;
        if (h[loc].roll_no == -1)
        {
            h[loc].roll_no = rec.roll_no;
            h[loc].pos = relt;
            f.write((char *)&rec, s);
            relt++;
        }
        else
        {
            int temp = rec.roll_no;
            int tempPos = relt;
            if (loc != (h[loc].roll_no % 10))
            {
                temp = h[loc].roll_no;
                tempPos = h[loc].pos;
                h[loc].roll_no = rec.roll_no;
                h[loc].pos = relt;
            }
            int j = (loc + 1) % MAX;
            while (j != loc)
            {
                if (h[j].roll_no == -1)
                {
                    h[j].roll_no = temp;
                    h[j].pos = tempPos;
                    f.write((char *)&rec, s);
                    relt++;
                    break;
                }
                j = (j + 1) % MAX;
            }
            if (j == loc)
                cout << "Hash table full" << endl;
        }
    }
    f.close();
}

void Student::retrieve()
{
    Record rec;
    fstream f;
    f.open("studentdetail.txt", ios::binary | ios::in);
    if (!f)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    cout << "Enter the roll no to be searched: ";
    cin >> rec.roll_no;
    int loc = rec.roll_no % 10;
    int i;
    for (i = 1; i < MAX; i++)
    {
        if (h[loc].roll_no == rec.roll_no)
        {
            int p = h[loc].pos * s;
            f.seekg(p, ios::beg);
            f.read((char *)&rec, s);
            display(rec);
            break;
        }
        else
        {
            loc = (loc + 1) % 10;
        }
    }
    if (i >= 10)
        cout << "Record doesn't exist" << endl;
    f.close();
}

void Student::display_all()
{
    cout << "Hash Table" << endl;
    cout << "Index\tRoll No\tPosition" << endl;
    cout << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << i << "\t" << h[i].roll_no << "\t" << h[i].pos << endl;
    }
}

void Student::display(Record rec)
{
    cout << "Roll No: " << rec.roll_no << endl;
    cout << "Name: " << rec.name << endl;
    cout << "Grade: " << rec.grade << endl;
}

void Student::modify()
{
    fstream f;
    Record rec;
    f.open("studentdetail.txt", ios::binary | ios::in | ios::out);
    if (!f)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    cout << "Enter roll no to be modified: ";
    cin >> rec.roll_no;
    int loc = (rec.roll_no % 10);
    int i;
    for (i = 1; i < MAX; i++)
    {
        if (h[loc].roll_no == rec.roll_no)
        {
            int p = h[loc].pos * s;
            f.seekg(p, ios::beg);
            f.read((char *)&rec, s);
            display(rec);
            cout << "Enter new details for roll no: " << rec.roll_no << endl;
            cout << "Enter name: ";
            cin >> rec.name;
            cout << "Enter grade: ";
            cin >> rec.grade;
            p = h[loc].pos * s;
            f.seekp(p, ios::beg);
            f.write((char *)&rec, s);
            break;
        }
        else
        {
            loc = (loc + 1) % 10;
        }
    }

    if (i >= 10)
        cout << "Record not found!" << endl;
    f.close();
}

int main()
{
    Student s;
    int choice;
    while (true)
    {
        cout << "Choose from the following:" << endl;
        cout << "1. Linear Probing with replacement" << endl;
        cout << "2. Linear Probing without replacement" << endl;
        cout << "3. Display Hash Table" << endl;
        cout << "4. Retrieve Data" << endl;
        cout << "5. Modify Data" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.create_with_replacement();
            break;

        case 2:
            s.create_without_replacement();
            break;

        case 3:
            s.display_all();
            break;

        case 4:
            s.retrieve();
            break;

        case 5:
            s.modify();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }
    return 0;
}
