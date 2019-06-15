#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> res;

    for (int i = 0; i < n; i++) 
    {
      int x, y;
      cin >> x >> y;
      res.push_back(x + y);
    }

    
    int min=res[0];
    int index=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (min>res[j] and res[j]!=-1)
            {
                min=res[j];
                index=j;
            }
        }
        cout<<index+1<<" ";
        min=INT32_MAX;
        res[index]=-1;
    }
}
