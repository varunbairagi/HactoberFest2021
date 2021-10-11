#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int start, int end)
{
    int mid = (start + end) / 2;
    int i = start, j = mid + 1;
    vector<int> temp(end - start + 1);
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (arr.at(i) >= arr.at(j))
        {
            temp[k++] = arr.at(j++);
        }
        else
            temp[k++] = arr.at(i++);
    }
    while (i <= mid)
        temp[k++] = arr.at(i++);
    while (j <= end)
        temp[k++] = arr.at(j++);
    for (int i = 0; i < temp.size(); i++)
    {
        arr.at(i + start) = temp.at(i);
    }
}
void MergeSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        //cout << mid << " ";
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        merge(arr, start, end);
    }
}
int main()
{
    vector<int> arr = {2, 5, 9, 1, 8};
    int start = 0, end = arr.size() - 1;
    MergeSort(arr, start, end);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
