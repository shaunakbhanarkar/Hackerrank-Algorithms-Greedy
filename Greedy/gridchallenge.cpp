#include <bits/stdc++.h>

using namespace std;

// Complete the gridChallenge function below.
string gridChallenge(vector<string> grid) {

    for (int i=0;i<grid.size();i++)
    {
        string s = grid[i];
        sort(s.begin(),s.end());
        grid[i] = s;
    }
    for (int i=0;i<grid.size()-1;i++)
    {
        for (int j=0;j<grid.size();j++)
        {
            string s = grid[i];
            char c = s[j];

            string s2 = grid[i+1];
            char c2 = s2[j]; 
            if (c>c2)
                return "NO";
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
