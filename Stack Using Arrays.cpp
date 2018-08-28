#include<iostream>

using namespace std;

class stack_arr
{
    int top;
    int num;
    int maxx = 5;

    int arr[5];

public:
    stack_arr()
    {
        top = -1;

        cout << " " << endl;

    }

    void push()
    {
        if (top < maxx-1)
        {
            cout << "Please enter the element to insert: ";
            cin >> num;
            top++;
            arr[top] = num;
        }
        else
            cout << "The Stack has Overflown!!" << endl;

        cout << " " << endl;

    }

    void pop()
    {
        if(top >= 0)
            top--;
        else
            cout << " " << endl;
            cout << "The Stack is Underflowing!!" << endl;
            cout << " " << endl;
    }
};

int main()
{
    int op;
    int flag = 0;

    stack_arr st1;
    do
    {
        cout << "MENU: " << endl;
        cout << "\t Enter 1 to insert new element to the Stack. " << endl;
        cout << "\t Enter 2 to remove the last element from the Stack. " << endl;
        cout << "\t Enter 0 to Exit." << endl;

        cout << " " << endl;
        cout << "Please enter the option: ";
        cin >> op;
        cout << " " << endl;

        switch(op)
        {
            case(1):

                st1.push();
                break;
            case(2):
                st1.pop();
                break;
            case(0): flag = 1;
                break;
        }
    }while(flag==0);
}
