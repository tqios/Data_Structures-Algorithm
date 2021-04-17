#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K, temp, sum = 0;
    stack<int> S;

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> temp;
        if (temp == 0)
            S.pop();
        else
            S.push(temp);
    }

    while (!S.empty())
    {
        sum += S.top();
        S.pop();
    }

    cout << sum << endl;

    return 0;
}