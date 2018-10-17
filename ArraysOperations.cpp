#include<iostream>
using namespace std;

class arr_op
{
    int arr[];
    int size_;

    public:
        void input();
        void display();
        void insert_el();
        void delete_el();
        void bubble_sort();
        void bin_search_el();

};


void arr_op :: input()
{
    size_ = 10;
    for(int i = 0; i < size_; i++)
    {
        cout << "Enter the element " << (i+1) << ": ";
        cin >> arr[i];
    }
    cout << "Congratulations!! You have entered all the values." << endl;
    cout << " " << endl;

}

void arr_op :: display()
{

    cout << "The stored values are:";

    for(int i = 0; i < size_; i++)
    {
        cout << "\t" << arr[i] << endl;
    }

}

void arr_op ::bubble_sort()
{
    int p, c, temp;
    for(p = 1; p<size_; p++)
    {
        for(c = 0; c < size_ - p; c++)
        {
            if(arr[c] > arr[c+1])
            {
                temp = arr[c];
                arr[c] = arr[c+1];
                arr[c+1] = temp;
            }
        }
    }
    cout << " " << endl;
    cout << "Sorted array:" << endl;
    cout << "\t";
    for(int i = 0; i < size_; i++)
        cout << arr[i] << " ";
    cout << " " << endl;
    cout << " " << endl;

}

void arr_op :: bin_search_el()
{
    int val, beg, endd, mid, flag;
/*    //Sorting the array
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size-1; j++)
        {
            int temp;
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    cout << "Sorted Array: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";

    }

    }
*/
    cout << " " << endl;
    cout << " " << endl;


    cout << "Enter the value to search in the array: ";
    cin >> val;
    beg = 0;
    endd = size_-1;
    while(beg <= endd)
    {
        mid = (beg + endd)/2;

        if(val < arr[mid])
        {
            endd = mid - 1;
        }
        else if(val > arr[mid])
        {
            beg = mid + 1;
        }
        else if(val == arr[mid])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        cout << "The Value is found." << endl;
        cout << " " << endl;
    }
    else
    {
        cout << "The Value was not found." << endl;
        cout << " " << endl;
    }



}


int main()
{
    arr_op mileStone1;
    int flag = 0;
    do
    {
        int op;
        cout << "Enter 1 to input the elements." << endl;
        cout << "Enter 2 to display the elements." << endl;
        cout << "Enter 3 to use Binary Search." << endl;
        cout << "Enter 4 to bubble sort the array." << endl;
        cout << "Enter 0 to exit." << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "Please enter the option: ";
        cin >> op;
        cout << " " << endl;
        cout << " " << endl;
        switch(op)
        {
            case(1): mileStone1.input();
                break;
            case(2): mileStone1.display();
                break;
            case(3): mileStone1.bin_search_el();
                break;
            case(4): mileStone1.bubble_sort();
                break;
            case(0): flag = 1;
                break;

        }


    }while(flag == 0);


}
