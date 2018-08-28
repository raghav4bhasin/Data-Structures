#include<iostream>
#define MAX_SIZE 5
using namespace std;




class Q_with_LL
{
    struct node
    {
        int value;
        struct node *next;
    };

    struct node *start;
    struct node *tail;
    struct node *ptr;
    int counter;
    int num;

public:
    Q_with_LL()
    {
        start = NULL;
        tail = NULL;
        counter = 0;
    }
    void enq() //Need to add elements at the end.
    {
        cout << " " << endl;
        struct node *new_node;
        if(counter <= MAX_SIZE-1)
        {

            cout << "Enter new element to add: ";
            cin >> num;
            if(start == NULL && tail == NULL)
            {
               new_node = new node;
               new_node ->next = start;
               new_node ->value = num;
               start = new_node;
               tail = new_node;
               counter++;
            }
            else if(start != NULL)
            {
                new_node = new node;
                new_node ->next = NULL;
                new_node ->value = num;
                tail ->next = new_node;
                tail = new_node;
                counter++;
            }

        }

        else
        {
            cout << "\tERROR!! The queue has overflown." << endl;
        }
        cout << " " << endl;

    }

    void dq()
    {
        cout << " " << endl;

        if(start == NULL)
        {
           cout <<  "\tERROR!! No Elements to remove." << endl;

        }
        else
        {
            cout << start ->value <<" has been removed." << endl;
            ptr = start;
            start = start ->next;
            ptr ->next = NULL;
            delete ptr;
        }
        cout << " " << endl;
    }


};

int main()
{
    int op;
    Q_with_LL x;
    int flag = 0;
   do
   {
       cout << "Enter 1 to add elements to the Queue" << endl;
       cout << "Enter 2 to remove elements from the Queue" << endl;
       cout << "Enter 0  to exit" << endl;

       cout << " " << endl;
       cout  << "Please enter your option: ";
       cin >> op;
       cout <<  " " << endl;

       switch(op)
       {
            case(1) : x.enq();
                break;
           case(2) : x.dq();
                break;
            case(0) : flag = 1;
                break;
       }
   }while(flag == 0);
}

