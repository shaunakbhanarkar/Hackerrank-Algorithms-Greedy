#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int search(vector<int> v, int x)
{
    for(int i=0;i<v.size();i++)
    {
        if (v[i]==x)
            return i;
    }
    return -1;
}

// Complete the largestPermutation function below.
vector<int> largestPermutation(int k, vector<int> arr) {

    vector<int> temp = arr;
    sort(temp.begin(),temp.end());

    for (int i=0;i<arr.size();i++)
    {
        if (arr[i]!=temp[temp.size()-i-1])
        {
            int index = search(arr,temp[temp.size()-i-1]);
            int x = arr[index];
            arr[index]=arr[i];
            arr[i]=x;
            k--;
        }
        if(k<=0)
            break;
    }

    return arr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = largestPermutation(k, arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
