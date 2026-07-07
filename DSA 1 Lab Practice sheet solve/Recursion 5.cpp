#include <iostream>
using namespace std;

bool search(int arr[], int n, int index, int target) {
    if(index == n)
        return false;

    if(arr[index] == target)
        return true;

    return search(arr, n, index + 1, target);
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    if(search(arr, n, 0, target))
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}
