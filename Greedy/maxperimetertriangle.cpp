#include<bits/stdc++.h>
using namespace std;

bool formtriangle(int x, int y, int z)
{
    bool a=false,b=false,c=false;
    if (x + y > z)
        a=true;
    if (y + z > x)
        b=true;
    if (z + x > y)
        c=true;
    return a&b&c;
}
int main()
{
    int n;
    cin>>n;

    vector<int> v;

    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    int i=n-1;
    while(i>=2)
    {
        if (formtriangle(v[i], v[i-1], v[i-2]))
        {
            cout<<v[i-2]<<" ";
            cout<<v[i-1]<<" ";
            cout<<v[i];
            goto label;
        }
        i--;
    }
    cout<<-1;
    label: return 0;
}
