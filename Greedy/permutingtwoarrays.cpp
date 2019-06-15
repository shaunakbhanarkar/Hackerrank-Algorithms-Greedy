#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;

    while(q--)
    {
        
        int n,k;
        cin>>n>>k;

        vector<int> a,b;
        for (int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        string res = "YES";
        for (int i=0;i<n;i++)
        {
            if (a[i]+b[n-i-1]<k)
                res = "NO";
        }

        cout<<res<<endl;
    }
}
