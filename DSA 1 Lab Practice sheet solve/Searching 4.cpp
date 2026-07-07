#include <iostream>
using namespace std;

int main() {
    int n, target;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> target;

    int left = 0, right = n - 1;
    int ans = -1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == target) {
            ans = mid;
            right = mid - 1;
        }
        else if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    cout << ans;

    return 0;
}
