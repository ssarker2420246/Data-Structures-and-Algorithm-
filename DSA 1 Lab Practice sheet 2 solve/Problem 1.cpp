#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void bubbleSort(int arr[], int n, bool ascending)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if((ascending && arr[j]>arr[j+1]) ||
               (!ascending && arr[j]<arr[j+1]))
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[], int n, bool ascending)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;

        while(j>=0 && ((ascending && arr[j]>key) ||
                       (!ascending && arr[j]<key)))
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

void selectionSort(int arr[], int n, bool ascending)
{
    for(int i=0;i<n-1;i++)
    {
        int index=i;

        for(int j=i+1;j<n;j++)
        {
            if((ascending && arr[j]<arr[index]) ||
               (!ascending && arr[j]>arr[index]))
            {
                index=j;
            }
        }

        swap(arr[i],arr[index]);
    }
}


int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int choice, order;

    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Selection Sort\n";
    cout << "Choose algorithm: ";
    cin >> choice;

    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "Choose order: ";
    cin >> order;

    if(choice == 1)
    {
        if(order == 1)
            bubbleSort(arr, n, true);
        else
            bubbleSort(arr, n, false);
    }
    else if(choice == 2)
    {
        if(order == 1)
            insertionSort(arr, n, true);
        else
            insertionSort(arr, n, false);
    }
    else if(choice == 3)
    {
        if(order == 1)
            selectionSort(arr, n, true);
        else
            selectionSort(arr, n, false);
    }

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
