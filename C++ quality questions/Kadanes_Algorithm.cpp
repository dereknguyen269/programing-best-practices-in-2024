#include <iostream>
using namespace std;

// A program to find the maximum sum of a subarray which can be obtained from a given array.

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    int cs = 0, ms = 0; // cs=current sum    ms=maxm sum

    for (int i = 1; i < n; i++)
    {
        cs += arr[i];
        if (cs < 0)
        {
            cs = 0;
        }

        ms = max(cs, ms);
    }
    cout << ms << endl;
    return 0;
}