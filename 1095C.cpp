#include <bits/stdc++.h>
#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define vint vector<int>
#define mint map<int, int>
#define sint set<int>
#define qint queue<int>
#define pb push_back
#define pf push_front
const int MOD = 1e9 + 7;
using namespace std;

void solve()
{
    int n, k, c = 0;
    cin >> n >> k;
    qint q;

    string binary = bitset<30>(n).to_string();

    for (int i = 29; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            c++;
            q.push(pow(2, 29 - i));
        }
    }

    if (c > k || k > n)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    int cnt = 0;

    while (q.size() + cnt != k)
    {
        int top = q.front();
        q.pop();

        if (top == 1)
        {
            cout << "1 ";
            cnt++;
        }
        else
        {
            q.push(top / 2);
            q.push(top / 2);
        }
    }

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}