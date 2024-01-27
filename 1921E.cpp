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

string solve(){
    int m, n, xa, ya, xb, yb;
    cin >> m >> n >> xa >> ya >> xb >> yb;

    if(xa >= xb) return "DRAW";

    int rowDiff = abs(xa - xb);
    int colDiff = abs(ya - yb);
    
    if((rowDiff&1) == 0){
        string winner = "BOB";
        int moves = rowDiff/2;

        if(ya == yb) return winner;

        if(ya > yb){
            int nyb = (yb + moves) <= n ? (yb + moves) : n;
            int nya = (ya + moves) <= n ? (ya + moves) : n;

            winner = (nya != nyb) ? "DRAW" : "BOB";
        }
        else{
            int nyb = (yb - moves) >= 1 ? (yb - moves) : 1;
            int nya = (ya - moves) >= 1 ? (ya - moves) : 1;

            winner = (nya != nyb) ? "DRAW" : "BOB";
        }

        return winner;
    }

    else{
        string winner = "ALICE";
        int moves = rowDiff / 2;

        if(ya == yb) return winner;

        if(ya > yb){
            int nyb = (yb - moves) >= 1 ? (yb - moves) : 1;
            int nya = (ya - moves - 1) >= 1 ? (ya - moves - 1) : 1;

            winner = (nya != nyb) ? "DRAW" : "ALICE";
        }
        else{
            int nyb = (yb + moves) <= n ? (yb + moves) : n;
            int nya = (ya + moves + 1) <= n ? (ya + moves + 1) : n;

            winner = (nya != nyb) ? "DRAW" : "ALICE";
        }

        return winner;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) cout << solve() << endl;
    return 0;
}