#include <iostream>
using namespace std;

// Count occurrences of a number in a range
int count(int arr[], int left, int right, int num) {
    int cnt = 0;
    for (int i = left; i <= right; i++) {
        if (arr[i] == num)
            cnt++;
    }
    return cnt;
}

// Divide & Conquer function
int majorityElement(int arr[], int left, int right) {

    // Base case
    if (left == right)
        return arr[left];

    // Divide
    int mid = (left + right) / 2;

    // Conquer
    int leftMajor = majorityElement(arr, left, mid);
    int rightMajor = majorityElement(arr, mid + 1, right);

    // If both are same
    if (leftMajor == rightMajor)
        return leftMajor;

    // Count both
    int leftCount = count(arr, left, right, leftMajor);
    int rightCount = count(arr, left, right, rightMajor);

    // Return the one with higher count
    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int main() {
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = majorityElement(arr, 0, n - 1);

    cout << "Majority Element: " << result << endl;

    return 0;
}
