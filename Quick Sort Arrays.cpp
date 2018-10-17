#include<iostream>

using namespace std;


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(int arr[], int size_)
{

    cout << "Sorted Array: ";
    for (int i = 0; i < size_; i++)
    {
        cout  << arr[i] << " ";
    }

    cout << " " << endl;

}


int main()
{
    int r = 0;
    int n;


    cout<< "Enter the number of elements: ";
	cin >> n;

	int arr[n];
	for(int i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}


    quickSort(arr, 0, n-1);


    printArray(arr, n);
    return 0;
}
