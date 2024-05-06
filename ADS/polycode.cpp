//Polynomial operations using CLL
#include<iostream>
#include<cmath>
using namespace std;

class node{
	int exp;
	int coef;
	node *next;
	friend class poly;
	};
	
class poly{
	node *head;
	public:
		poly(){
			head=new node();
			head->next=head;
		      }
		
		void create_poly();
		void display_poly();
		void add_poly(poly p1,poly p2);
		void eval_poly();
	};
	
	
void poly :: create_poly(){
	node *ptr;
	int deg;
	cout<<"Enter degree of the polynomial"<<endl;
	cin>>deg;
	node *last;
	last=head;
	
	for(int i=deg;i>=0;i--){
		ptr=new node();
		cout<<"Enter coefficient of x^"<<i;
		
		cin>>ptr->coef;
		ptr->exp=i;
		
		last->next=ptr;
		ptr->next=head;
		last=ptr;
		}
		
	}
	
void poly::display_poly(){
	node *temp;
	temp=head->next;
	while(temp!=head){
		cout<<temp->coef<<"x^"<<temp->exp<<"+";
		
		temp=temp->next;
		
		}
		
	}
	
void poly::add_poly(poly p1,poly p2){
	node *t1;
	node *t2;
	node *t3;
	
	t1=p1.head->next;
	t2=p2.head->next;
	t3=this->head; //can also write t3=head;
	
	while(t1!=p1.head && t2!=p2.head){
		node *ptr=new node();
		if(t1->exp == t2->exp){
			ptr->coef=t1->coef + t2->coef;
			ptr->exp=t1->exp;
			t1=t1->next;
			t2=t2->next;
			}
		else if(t1->exp > t2->exp){
			ptr->coef=t1->coef;
			ptr->exp=t1->coef;
			t1=t1->next;
			}
			
		else{
			ptr->coef=t2->coef;
			ptr->exp=t2->coef;
			t2=t2->next;
			}
			
		t3->next=ptr;
		ptr->next=head;
		t3=t3->next;
		}
		
		
	}

void poly::eval_poly(){
	int x;
	int sum=0;
	int deg;
	int coef;
	int exp;
	cout<<"Enter value of x:"<<endl;
	cin>>x;
	for(int i=deg;i>=0;i--){
		sum=sum+coef*pow(x,exp);
		}
	cout<<sum;
	}
				
int main(){
    int choice;
    poly p1, p2, p3;

    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Enter and display 1st polynomial\n";
        cout << "2. Enter and display 2nd polynomial\n";
        cout << "3. Add polynomials\n";
        cout << "4. Evaluate polynomial\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter 1st polynomial\n";
                p1.create_poly();
                cout << "1st polynomial: ";
                p1.display_poly();
                break;

            case 2:
                cout << "Enter 2nd polynomial\n";
                p2.create_poly();
                cout << "2nd polynomial: ";
                p2.display_poly();
                break;

            case 3:
                cout << "Addition of polynomials\n";
                p3.add_poly(p1, p2);
                cout << "Resultant polynomial: ";
                p3.display_poly();
                break;

            case 4:
                cout << "Evaluate polynomial\n";
                p1.eval_poly();
                break;

            case 5:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 5);

    return 0;
}

	
	
	
	