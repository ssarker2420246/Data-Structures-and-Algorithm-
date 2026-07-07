#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.second==b.second)
        return a.first<b.first;

    return a.second<b.second;
}

int main()
{
    int n;
    cin>>n;

    unordered_map<int,int> freq;

    int x;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        freq[x]++;
    }

    vector<pair<int,int>> v;

    for(auto p:freq)
        v.push_back(p);

    sort(v.begin(),v.end(),cmp);

    for(auto p:v)
    {
        for(int i=0;i<p.second;i++)
            cout<<p.first<<" ";
    }
}
