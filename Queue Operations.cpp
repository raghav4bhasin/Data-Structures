    #include <iostream>
#define size_ 5
using namespace std;

class SimpleQ
{
    int arrQ[size_];
    int f;
    int r;
    int num;
public:
    SimpleQ()
    {
        f = -1;
        r = -1;
    }

    void enq()
    {
        cout << " " << endl;
        if(r == size_ - 1)
        {
            cout << "\tERROR!! The Queue has overflown." << endl;
        }
        else if(f == -1 && r == -1)
        {
            cout << "Enter the new element: ";
            cin >> num;
            r = 0;
            f = 0;
            arrQ[r] = num;
        }/*
        It doesn't matter
        crying for help
        */
        else
        {
            cout << "Enter the new element: ";
            cin >> num;
            r = r+1;
            arrQ[r] = num;
        }
        cout <<  " " << endl;
    }

    void dq()
    {
        cout << " " << endl;
        if(f == -1 && r == -1 || f > r)
        {
            cout << "\tERROR!! No Elements to remove." << endl;
        }
        else if(f == r && f != -1)
        {
            cout << arrQ[f] <<" has been removed." << endl;
            f = f+1;
        }
        else
        {
            cout << arrQ[f] << " has been removed." << endl;
            f = f+1;
        }
    }
};

int main()
{
    int op;
    SimpleQ x;
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












/*
class Queue_ops
{

    int qu[];
    int frontptr;
    int rearptr;

public:
    void Enqueue();
    void Dequeue();

    Queue_ops()
    {
      frontptr = -1;
      rearptr = -1;
    }

};

void Queue_ops :: Enqueue()
{
    int el;

    if(rearptr == (size_ - 1) )
    {
        cout <<  "The Queue is Full." << endl;
    }
    else if(rearptr == -1 && frontptr == -1)
    {
        cout  << "The Queue is empty." << endl;
        cout << " " << endl;
        cout << "Please enter the first element to the queue: ";
        cin >> el;
        frontptr = 0;
        rearptr = 0;
        qu[rearptr] = el;
        rearptr++;
    }
    else
    {
        cout << " " << endl;
        cout << "Enter the element to add to the queue: ";
        cin >> el;
        qu[rearptr] = el;
        rearptr++;
    }
}

void Queue_ops ::Dequeue()
{
    if(frontptr == -1 && rearptr == -1)
    {
        cout  << " " << endl;
        cout << "The queue is already empty." << endl;

    }
    else if(frontptr == rearptr)
    {
        cout << " " << endl;
        cout << qu[rearptr] << " has been removed" << endl;
        rearptr = -1;
        frontptr = -1;

    }
    else
    {
        cout << " " << endl;
        cout << qu[frontptr] << " has been removed." << endl;
        frontptr++;

    }
}

int main()
{
    int op;
    Queue_ops x;
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
            case(1) : x.Enqueue();
                break;
            case(2) : x.Dequeue();
                break;
            case(0) : flag = 1;
                break;
       }
   }while(flag == 0);
}
*/
