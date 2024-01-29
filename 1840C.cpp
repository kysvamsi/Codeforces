#include <bits/stdc++.h>
#define int long long
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
    int n, minDays, minTemp, c = 0, ans = 0;
    cin >> n >> minDays >> minTemp;

    f(i, 0, n)
    {
        int temp;
        cin >> temp;

        if (temp <= minTemp)
            c++;
        else
        {
            if (c >= minDays)
            {
                ans += ((c - minDays + 1) * (c - minDays + 2) / 2);
            }
            c = 0;
        }
    }

    if (c >= minDays)
        ans += ((c - minDays + 1) * (c - minDays + 2) / 2);

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}