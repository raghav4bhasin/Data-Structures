#include <iostream>
#define sizee 7
using namespace std;

class Q1
{

    int x = 5;
    int q_arr[sizee];
    int ft;
    int re;
    int num;
public:
    Q1()
    {
        ft = -1;
        re = -1;
    }

    void Enqueue() //Adding New Elements to the rear of queue.
    {
        if((ft == 0 && re == sizee -1) || (ft == re +1)) //OverFlow Condition
        {
            cout << "\tERROR!! The Queue has Overflown and Cannot add any New Elements." << endl;

        }
        else if(ft == -1 && re == -1) //For the first insertion
        {
            ft = 0;
            re = 0;
            line();
            cout << "Enter the number to add to the queue: ";
            cin >> num;
            q_arr[re] = num;
        }
        else //General Case
        {
            cout << "Enter the number to add to the queue: ";
            cin >> num;
            if(re == sizee -1)
                re = 0;
            else
                re++;
            q_arr[re] = num;
        }
        line();
    }
    void line()
    {
        for(int i = 0; i < 18; i++)
        {    
            cout << " *-_-* ";
              
        }
        cout << " " << endl;
    }
    void Dequeue() //Removing Elements
    {
        if(ft == -1 && re == -1) //Underflow Condition
        {
            cout  << "\tERROR!! No Elements To Delete." << endl;
        }
        else if(ft == re)
        {
            cout << q_arr[ft]<<" is removed from the Queue." << endl;
            ft = -1;
            re = -1;
        }
        else
        {
            if(ft == sizee-1)
            {
                cout << q_arr[ft]<<" is removed from the Queue." << endl;
                ft = 0;
            }
            else
            {
                cout << q_arr[ft]<<" is removed from the Queue." << endl;
                ft++;
            }
        }
        line();
    }


};

int main()
{
    int op;
    Q1 x;
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

