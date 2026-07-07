#include <iostream>
using namespace std;

void printReverse(int arr[], int index) {
    if(index < 0)
        return;

    cout << arr[index] << " ";
    printReverse(arr, index - 1);
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    printReverse(arr, n - 1);

    return 0;
}
