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
    int n, m, left = 0, right, prod = 1;
    cin >> n >> m;
    vint res;

    vint a(n);

    f(i,0,n) cin >> a[i];

    string s;
    cin >> s;

    f(i,0,n-1) left += (s[i] == 'L');

    right = left;
    prod = a[left];
    
    res.push_back(prod % m);

    for(int i = n-2; i >= 0; i--){

        if(prod % m == 0) break;

        if(s[i] == 'L'){
            left--;
            prod *= a[left];
            prod %= m;
        }
        else{
            right++;
            prod *= a[right];
            prod %= m;
        }
        
        res.push_back(prod % m);
    }

    int rem = n - res.size();

    while(rem--){
        cout << "0 ";
    }

    for(int i = res.size()-1; i >= 0; i--){
        cout << res[i] << " ";
    }

    cout << endl;
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
