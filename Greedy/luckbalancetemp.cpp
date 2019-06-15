#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> imp, nonimp;
    for (int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if (y==1)
            imp.push_back(x);
        else
            nonimp.push_back(x);
    }

    int ans=0;

    for (int i=0;i<nonimp.size();i++)
    {
        ans = ans + nonimp[i];
    }

    sort(imp.begin(),imp.end());

    for(int i=0;i<imp.size();i++)
    {
        if (i<imp.size()-k)
            ans = ans - imp[i];
        else
            ans = ans + imp[i];

    }

    cout<<ans<<endl;

    
}
