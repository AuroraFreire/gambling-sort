#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

bool sort_check(vector<int> &arr)
{
    int n = arr.size();
    if (n < 2)
    {
        return true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return true;
}

vector<int> gambling_sort(vector<int> arr)
{
    int n = arr.size();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, n - 1);
    while (!sort_check(arr))
    {
        for (int j = 0; j < n; j++)
        {
            int i = dist(gen);
            int k = dist(gen);
            if (i == k)
            {
                continue;
            }
            swap(arr[i], arr[k]);
            for (int x : arr)
                cout << x << " ";
            cout << endl;
        }
    }
    return arr;
}

int main()
{
    int size;
    int min_value;
    int max_value;
    cout << "Size of the array: ";
    cin >> size;
    cout << "Minimum value of the array: ";
    cin >> min_value;
    cout << "Maximum value of the array: ";
    cin >> max_value;
    vector<int> arr;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min_value, max_value);
    for (int k = 0; k < size; k++)
    {
        arr.push_back(dist(gen));
    }
    gambling_sort(arr);
}