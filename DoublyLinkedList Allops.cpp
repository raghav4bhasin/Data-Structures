#include<iostream>

using namespace std;

class doubly_ll
{
     struct node
    {
        int value;
        struct node *previous;
        struct node *next;
    };
    struct node *ptr;
    struct node *temp;
    struct node *tail;
    struct node *start;
public:

    doubly_ll()
    {
        start = NULL;
    }

    void create_dll_beg()
    {
        int num = 0;
        struct node *new_node;
        cout << "Please enter the elements (-1 to EXIT): " << endl;
        cin >> num;

        while(num != -1)
        {
            struct node *new_node;
            new_node = new node;
            new_node ->value = num;
            if(start != NULL)
            {
                new_node ->previous = NULL;
                new_node ->next = start;
            }
            else
            {
                new_node ->previous = NULL;
                new_node ->next = NULL;
            }

            start ->previous = new_node;
            start = new_node;
            cin >> num;
        }
    }

    void create_dll_end()
    {
        int num = 0;
        struct node *new_node;
        cout << "Please enter the elements (-1 to EXIT): " << endl;
        cin >> num;
        tail = start;

        while(num != -1)
        {
            new_node = new node;

            new_node ->value = num;
            new_node ->next = NULL;

            if(start == NULL)
            {
                new_node ->previous = start;
                start = new_node;

            }
            else
            {
                new_node ->previous = tail;
                tail ->next = new_node;
            }
            tail = new_node;
            cin >> num;
        }
    }

    void show()
    {
        ptr = start;
        cout << "\tElements in the list are: ";
        while(ptr != NULL)
        {
            cout << ptr ->value << " ";
            ptr = ptr ->next;
        }
        cout << " " << endl;

    }

};


int main()
{
    int flag = 0;
    doubly_ll d_list;
    do
    {
        int opt;
        cout << "Enter 1 to create a Doubly Linked List (by INSERTING EACH ELEMENT AT THE BEGINNING)." << endl;
        cout << "Enter 2 to create a Doubly Linked List (by INSERTING EACH ELEMENT AT THE END)." << endl;
        cout << "Enter 3 to display the complete List." << endl;
        cout << "Enter 4 to insert new Elements into the list." << endl;

        cout << " " << endl;
        cout << " " << endl;
        cout << "Please enter the option: ";
        cin >> opt;
        cout << " " << endl;
        cout << " " << endl;


        switch(opt)
        {
            case(1): d_list.create_dll_beg();
                break;
            case(2): d_list.create_dll_end();
                break;
            case(3): d_list.show();
                break;

            case(0): flag = 1;
                break;

        }
    }while(flag == 0);

    return 0;
}
