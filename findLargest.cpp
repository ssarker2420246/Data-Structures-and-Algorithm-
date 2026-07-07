#include <iostream>
#include <climits>
using namespace std;

// Divide and Conquer function
pair<int, int> findLargestPair(int arr[], int left, int right) {

    // Base case: one element
    if (left == right) {
        return {arr[left], INT_MIN};
    }

    // Base case: two elements
    if (right == left + 1) {
        if (arr[left] > arr[right])
            return {arr[left], arr[right]};
        else
            return {arr[right], arr[left]};
    }

    // Divide
    int mid = (left + right) / 2;

    // Conquer
    pair<int, int> leftPair = findLargestPair(arr, left, mid);
    pair<int, int> rightPair = findLargestPair(arr, mid + 1, right);
    //<23,17>
    //<15,5>

    // Combine
    int largest = max(leftPair.first, rightPair.first);

    int secondLargest;
    if (leftPair.first > rightPair.first)
        secondLargest = max(leftPair.second, rightPair.first);
    else
        secondLargest = max(rightPair.second, leftPair.first);

    return {largest, secondLargest};
}

int main() {
    int arr[] = {10, 5, 20, 8, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> ans = findLargestPair(arr, 0, n - 1);

    cout << "Largest: " << ans.first << endl;
    cout << "Second Largest: " << ans.second << endl;

    return 0;
}
