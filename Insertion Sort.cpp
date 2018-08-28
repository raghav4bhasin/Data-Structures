#include<iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << " " << endl;
}

int main()
{
    int x;
    cout << "Enter size of array: ";
    cin >> x;
    cout << " " << endl;
	int arr[x];
	{
	    cout << "Enter the elements of the array:-" << endl;
        for(int i = 0; i < x; i++)
        {
            cin >> arr[i];
        }
        cout << "Unsorted Array: ";
        cout << " " << endl;
        printArray(arr, x);
        cout << " " << endl;

	}

	//int n = sizeof(arr)/sizeof(arr[0]);
    //cout << sizeof(arr) << " " << sizeof(arr[0]) << endl;
	insertionSort(arr, x);
	cout << "Sorted Array: ";
	printArray(arr, x);

	return 0;
}
