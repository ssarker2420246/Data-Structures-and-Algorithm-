#include <iostream>
using namespace std;

int Count_Right_Smaller(int arr[], int i, int n) {
    int count = 0;
    for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[i])
            count++;
    }
    return count;
}


void solve(int arr[], int left, int right, int result[], int n) {
    if (left > right)
        return;

    if (left == right) {
        result[left] = Count_Right_Smaller(arr, left, n);
        return;
    }

    int mid = (left + right) / 2;

    solve(arr, left, mid, result, n);
    solve(arr, mid + 1, right, result, n);
}

int main() {
    int arr[] = {5, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result[n];

    solve(arr, 0, n - 1, result, n);

    cout << "Counts: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
