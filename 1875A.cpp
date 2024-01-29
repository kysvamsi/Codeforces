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
using namespace std;

void solve(){
    int a, b, n, ans = 0;
    cin >> a >> b >> n;

    f(i, 0, n){
        int temp;
        cin >> temp;
        ans += min(temp, a - 1);
    }

    cout << ans + b << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}