#include<bits/stdc++.h>
#define int long long
#define f(i,a,b) for (int i=a;i<b;i++)
#define all(a) a.begin(),a.end()
#define vint vector<int>
#define mint map<int,int>
#define sint set<int>
#define qint queue<int>
#define pb push_back
#define pf push_front
const int MOD = 1e9 + 7;
using namespace std;

void solve(){
    int n, last = 0;
    cin >> n;

    vint a(n);

    f(i, 0, n) cin >> a[i];

    f(i, 0, n){
        if(last < a[i]) last = a[i];

        else{
            int k = last/a[i];

            last = (k+1)*(a[i]);
        }
    }

    cout << last << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
