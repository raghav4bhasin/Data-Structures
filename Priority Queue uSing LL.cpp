#include<iostream>

using namespace std;



class Pri_Q
{
    struct node
{
    int value;
    int priority;
    struct node  * next;
};

    struct node * front;
    struct node * rear;
    struct node * ptr;
public:

    Pri_Q()
    {
        front = NULL;
    }

    void Enqueue()
    {
        int num;
        int pri;
        cout << "Enter number to add to the Queue: ";
        cin >> num;
        cout << "Enter priority of the new element: ";
        cin >> pri;
        struct node *new_node;

        new_node = new node;
        new_node ->value = num;
        new_node ->priority = pri;

        ptr = front;

        if (ptr == NULL)
        {
            front = new_node;
            new_node ->next = front;

        }
        else
        {
            while(ptr != NULL)
            {
                if(new_node ->priority < ptr ->priority)
                {

                    break;
                }
                else
                {
                    ptr = ptr ->next;
                }

            }
            new_node ->next = ptr ->next;
            ptr ->next = new_node;

        }
        if(new_node ->next == NULL)
        {
            rear = new_node;
        }
        cout << "Value: " << new_node ->value << "priority: " << new_node ->priority << endl;
        cout << " " << endl;
    }

    void Dequeue()
    {
        int num;
        int pri;
        ptr = front;
        cout << "Enter element to be removed from the queue: ";
        cin >> num;
        cout << "Enter priority:";
        cin >> pri;

        while(ptr != NULL)
        {
            if(num == ptr ->next ->value && pri == ptr ->next ->priority)
            {
                break;
            }
        }
    }

};



int main()
{
    Pri_Q Obj;
    int opt;
    int flag = 0;
    do
    {
        int op;
        cout << "Enter 1 to add an element in a priority queue." << endl;
        cout << "Enter 0 to exit." << endl;
        cout << "\tEnter option: ";
        cin >> opt;
        cout << " " << endl;
        switch(opt)
        {
            case (1): Obj.Enqueue();
                break;
            case (0): flag = 1;
                break;
            default: cout << "\tERROR!! Invalid Input." << endl;
                break;

        }

    }while(flag == 0);
}

