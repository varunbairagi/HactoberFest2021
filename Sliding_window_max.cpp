#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

vector<int> maxInWindow(vector<int> input, int k)
{
    deque<int> dq;
    vector<int> out;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && input.at(dq.back()) < input.at(i))
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k; i < input.size(); i++)
    {
        out.push_back(input.at(dq.front()));
        if (dq.front() + k <= i)
            dq.pop_front();
        while (!dq.empty() && input.at(dq.back()) < input.at(i))
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    out.push_back(input.at(dq.front()));
    return out;
}
int main()
{
    vector<int> input = {1, 0, 0};
    int k = 2;
    vector<int> out = maxInWindow(input, k);
    for (int x : out)
        cout << x << " ";
    return 0;
}
