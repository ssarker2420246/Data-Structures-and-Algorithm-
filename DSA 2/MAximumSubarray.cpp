#include <bits/stdc++.h>

using namespace std;

struct Result
{
    int sum;
    int start;
    int end;
};

Result maxCrossingSum(int arr[], int low, int mid, int high)
{
    int sum = 0;
    int leftSum = INT_MIN;
    int maxLeft = mid;

    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    int maxRight = mid + 1;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
        {
            rightSum = sum;
            maxRight = i;
        }
    }

    return {(leftSum + rightSum), maxLeft, maxRight};
}

Result maxSubArrayDC(int arr[], int low, int high)
{
    if (low == high)
    {
        return {arr[low], low, high};//for 1 element
    }

    int mid = (low + high) / 2;

    Result left = maxSubArrayDC(arr, low, mid);
    Result right = maxSubArrayDC(arr, mid + 1, high);
    Result cross = maxCrossingSum(arr, low, mid, high);


    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    else if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    else
        return cross;

}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    Result res = maxSubArrayDC(arr, 0, n - 1);

    cout << "Maximum Subarray Sum: " << res.sum << endl;
    cout << "Subarray: ";

    for (int i = res.start; i <= res.end; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << "Start Index: " << res.start << endl;
    cout << "End Index: " << res.end << endl;

    return 0;
}
