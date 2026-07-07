#include <iostream>
using namespace std;

/*Given the heights of n students standing in a line, count the number of pairs of students (i, j) such that i < j and the student at position i is taller than the student at position j.

Input

First line: an integer n
Second line: n integers representing the heights of the students.

Output

Print the number of such pairs.*/

long long merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[low + i];
    }

    for(int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    long long count = 0;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];

            // L[i], L[i+1], ..., L[n1-1] are all greater than R[j]
            count += (n1 - i);

            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return count;
}

long long mergeSort(int arr[], int low, int high)
{
    long long count = 0;

    if(low < high)
    {
        int mid = (low + high) / 2;

        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long ans = mergeSort(arr, 0, n - 1);

    cout << ans << endl;

    return 0;
}
