#include <bits/stdc++.h>
using namespace std;
string uniqueSubstring(string arr)
{
    string out;
    int begin = 0, end = 0;
    unordered_map<char, int> visited;
    for (int low = 0, high = 0; high < arr.size(); high++)
    {
        if (visited[arr.at(high)] >= low)
        {
            low = visited[arr.at(high)] + 1;
        }
        visited[arr.at(high)] = high;
        if (high - low > end - begin)
        {
            begin = low;
            end = high;
        }
    }
    for (int i = begin; i <= end; i++)
    {
        out += arr.at(i);
    }
    return out;
}
int main()
{
    string arr = "Prateekbhaiya";
    cout << uniqueSubstring(arr);
    return 0;
}
