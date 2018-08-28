#include<iostream>
using namespace std;

class Llist
{
        int num;

    struct node
    {
        int value;
        struct node *next;
    };
    struct node *save;
    struct node *start;
    struct node *ptr;
    struct node *copy_;
    struct node *temp;


public:

    Llist()
    {
        start = NULL;


    }
    void create_beg()
    {
        int num;
        struct node *new_node;
        cout << "Please enter the elements (-1 to EXIT): " << endl;
        cin >> num;
        int flag1 = 1;

        while(num != -1)
        {

            new_node = new node;
            if (flag1 == 1)
            {
                temp = new_node;
            }
            new_node ->value = num;
            new_node ->next = start;
            flag1 = 0;
            start = new_node;
            cin >> num;

        }
        temp ->next = start;
    }

    void show_ll()
    {
        ptr = start;
        cout << "The Circular Linked list Elements are: " << endl;

        do
        {
            cout << ptr ->value << " ";
            ptr = ptr ->next;
        }while(ptr != start);

        cout << " " <<endl;
    }
    void insert_beg()
    {

    cout << " " << endl;
    cout << "Enter the number to insert at the beginning of the list: ";
    cin >> num;

        struct node *new_node;
        new_node= new node;
        new_node->value=num;
        new_node->next=start;
        start=new_node;
        ptr = new_node->next;
        while(ptr->next!=start)
        {
            ptr = ptr ->next;
        }
        ptr ->next = start;
    }
    void del_beg()
    {
        ptr = start;
        start = ptr ->next;
        ptr ->next = NULL;
        temp ->next = start;
        delete ptr;



    }

    void insert_end(int num)
    {
        struct node *new_node;
        new_node=new node;
        new_node->value=num;
        new_node->next=save->next;
        save->next=new_node;
        save=new_node;
    }

};

int main()
{
    int flag = 0;
    Llist ops;
    int op;
    do
    {
        int op;
        cout << "  " << endl;
        cout << "Enter 1 to create the Circular Linked List (By Insertion at the beginning)." << endl;
        cout << "Enter 2 to display the elements." << endl;
        cout << "Enter 3 to insert new element into the list." << endl;
        cout << "Enter 4 to delete the first Element." << endl;
        cout << "Enter 0 to exit." << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "Please enter the option: ";
        cin >> op;
        cout << " " << endl;
        cout << " " << endl;

        switch(op)
        {
            case(1): ops.create_beg();
                break;
            case(2): ops.show_ll();
                break;
            case(3): ops.insert_beg();
                break;
            case(4): ops.del_beg();
                break;
            case(0): flag = 1;
                break;
        }
    }while(flag == 0);
    cout << " " << endl;
}
