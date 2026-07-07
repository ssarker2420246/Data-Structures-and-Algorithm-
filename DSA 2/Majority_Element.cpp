#include <iostream>
using namespace std;

int countElement(int arr[], int Low, int High, int x)
{
    if(Low == High)
    {
        if(arr[Low] == x)
            return 1;
        else
            return 0;
    }

    int Mid  = (Low + High) / 2;

    int left = countElement(arr, Low, Mid, x);
    int right = countElement(arr, Mid  + 1, High, x);

    return left + right;
}

int majorityElement(int arr[], int Low, int High)
{
    if(Low == High)
        return arr[Low];

    int Mid  = (Low + High) / 2;

    int left = majorityElement(arr, Low, Mid );
    int right = majorityElement(arr, Mid  + 1, High);

    if(left == right)
        return left;

    int Left_Half = countElement(arr, Low, High, left);
    int Right_Half = countElement(arr, Low, High, right);

    if(Left_Half > Right_Half)
        return left;
    else
        return right;
}

int main()
{
    int arr[] = {4, 7, 1, 9, 3, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Majority element: " << majorityElement(arr, 0, n - 1) << endl;

    return 0;
}
