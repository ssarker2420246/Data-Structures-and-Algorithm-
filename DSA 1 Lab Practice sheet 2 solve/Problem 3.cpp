#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    string type;
    cin>>type;      // even or odd

    vector<int> temp;
    vector<int> index;

    if(type=="even")
    {
        for(int i=0;i<n;i+=2)
        {
            temp.push_back(arr[i]);
            index.push_back(i);
        }
    }
    else
    {
        for(int i=1;i<n;i+=2)
        {
            temp.push_back(arr[i]);
            index.push_back(i);
        }
    }

    sort(temp.begin(),temp.end());

    for(int i=0;i<temp.size();i++)
        arr[index[i]]=temp[i];

    for(int x:arr)
        cout<<x<<" ";
}
