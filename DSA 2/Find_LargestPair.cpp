#include <iostream>
#include <climits>
using namespace std;


pair<int, int> findLargestPair(int arr[], int left , int right) {


    if (left  == right) {
        return {arr[left ], INT_MIN};
    }

    if (right == left  + 1) {
        if (arr[left ] > arr[right])
            return {arr[left ], arr[right]};
        else
            return {arr[right], arr[left ]};
    }


    int Mid  = (left  + right) / 2;

    pair<int, int> left_Pair = findLargestPair(arr, left , Mid );
    //(20,15)
    pair<int, int> right_Pair = findLargestPair(arr, Mid  + 1, right);
    //(10,8)



    int largest = max(left_Pair.first, right_Pair.first);

    int secondLargest;
    if (left_Pair.first > right_Pair.first)
        secondLargest = max(left_Pair.second, right_Pair.first);
    else
        secondLargest = max(right_Pair.second, left_Pair.first);

    return {largest, secondLargest};
}

int main() {
    int arr[] = {15, 5, 20, 8, 10,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> ans = findLargestPair(arr, 0, n - 1);

    cout << "Largest Pair is " << ans.first<<","<<ans.second << endl;


    return 0;
}
