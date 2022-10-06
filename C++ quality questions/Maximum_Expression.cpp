#include <bits/stdc++.h>
using namespace std;

/* You are given answer string S of length N, consisting of the digits 0-9 and the characters '+' and '-'.
S represents answer valid mathematical expression.
Rearrange the characters of S to form answer valid mathematical expression such that the result
obtained upon evaluating it is maximum.*/

int main()
{

    int n;
    cout << "Please enter the length of the string you want to enter: ";
    cin >> n;
    string str;
    cout << "Please enter the string you want: ";
    cin >> str;
    int plus = 0;  // for counting the number of times '+' operator comes.
    int minus = 0; // for counting the number of times '-' operator comes.
    vector<char> num;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '+')
        {
            plus++;
        }
        else if (str[i] == '-')
        {
            minus++;
        }
        else
        {
            num.push_back(str[i]);
        }
    }

    sort(num.begin(), num.end());

    string answer = "";

    for (int j = 0; j < num.size(); j++)
    {
        if (minus != 0)
        {
            answer = answer + num[j];
            answer = answer + '-';
            minus--;
        }
        else if (plus != 0)
        {
            answer = answer + num[j];
            answer = answer + '+';
            plus--;
        }

        else
        {
            answer = answer + num[j];
        }
    }
    reverse(answer.begin(), answer.end());

    cout << "The required answer is: ";

    cout << answer << endl;

    return 0;
}
