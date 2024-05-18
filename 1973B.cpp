#include<bits/stdc++.h>
using namespace std;

// Macros
#define f(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define pf push_front
#define MOD = 1e9 + 7
#define PI 3.141592653589
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define numOfDigits(n) ((int)log10(n) + 1)
#define inint(x) int x; cin>>x;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define out(x) cout<<x<<endl;
#define all(a) a.begin(),a.end()
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl

//typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

//Constants
vector <ll> primes;
vector <bool> isPrime;

// Mathematical Functions
void Sieve(int n){ isPrime.assign(n + 1, true); isPrime[0] = isPrime[1] = false; for(ll i = 2; i * i <= n; i++) if(isPrime[i]) for(ll j = i * i; j <= n; j += i) isPrime[j] = false;}
void get_primes(int n){ for(int i = 2; i <= n; i++)  if(isPrime[i])  primes.push_back(i); }

bool solve(int k, vi arr){
    vi cnt(21, 0);

    f(i,0,k){
        int num = arr[i];
        
        f(j,0,21){
            if((num >> j) & 1) cnt[j]++;
        }
    }

    int left = 0, right = k;

    while(right < arr.size()){
        int num1 = arr[left];
        int num2 = arr[right];
        
        f(j,0,21){
            bool isZero = (cnt[j] == 0);

            if((num1 >> j) & 1) cnt[j]--;
            if((num2 >> j) & 1) cnt[j]++;

            if(isZero && cnt[j]) return false;
            if(!isZero && cnt[j] == 0) return false;
        }

        right++;
        left++;
    }

    return true;
}

void solve(){
    inint(n);
    vi arr(n);

    f(i,0,n) cin >> arr[i];

    int low = 1, high = n, ans;

    while(low <= high){
        int mid = low + (high - low)/2;

        bool flag = solve(mid, arr);

        if(flag){
            ans = mid;
            high = mid-1;
        }

        else low = mid+1;
    }
    
    out(ans);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    inint(t);
    //int t = 1;
    while(t--) solve();
    return 0;
}