#include <iostream>

using namespace std;

void max_heap(int arr[], int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	 if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		max_heap(arr, n, largest);
	}
}
int delete_(int arr[],int &n)
{
    int save;
    save=arr[1];
    arr[1]=arr[n];
    n=n-1;
    max_heap(arr,1,n);
    return save;
}
void printArray(int arr[], int n)
{
	for (int i=0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
int main()
{
	int arr[100],n,i,op;
	cout<<"enter size of array "<<endl;
	cin>>n;
	for(i=0;i<n;i++)
    {
        cout<<"enter element "<<endl;
        cin>>arr[i];
    }
   do{
    cout<<"enter option "<<endl;
    cin>>op;
    switch(op)
    {
case 1:
    max_heap(arr, n, 0);
    break;
case 2:
    delete_(arr,n);
    break;
default:
    break;
    }
   }
   while (op==-1);
cout << "heap array is \n";
printArray(arr, n);
}
