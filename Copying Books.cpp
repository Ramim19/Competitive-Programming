#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define lld long double
#define endl "\n"
#define e cout << endl
#define pb push_back
#define s(v) sort(v.begin(), v.end())
#define rs(v) sort(v.rbegin(), v.rend())
#define r(s) reverse(s.begin(), s.end())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define cout1 cout << -1 << endl
#define istg() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const ll M = 1e7 + 7;
const ll N = 1e7 + 7;
inline void normal(ll &a);
inline ll modMul(ll a, ll b);
inline ll modAdd(ll a, ll b);
inline ll modSub(ll a, ll b);
inline ll modPow(ll b, ll p);
inline ll modInverse(ll a);
inline ll modDiv(ll a, ll b);

vector<bool>mark(N+11);
vector<ll>prime;
void seive(){
    mark[0]=true;
    mark[1]=true;
    for(ll i=4;i<=N;i+=2)mark[i]=true;
    for(ll i=3;i*i<=N;i+=2){
        if(mark[i]==false){
            for(ll j=i*i;j<=N;j+=2*i)mark[j]=true;
        }
    }
    prime.push_back(2);
    for(ll i=3;i<=N;i+=2){
        if(mark[i]==false)prime.push_back(i);
    }
}

void solve(ll tc)
{
    ll n, k; cin>> n >> k;
    vector<ll>v(n);
    ll l = 0, r = 0;
    for(auto& i:v){
        cin>>i;
        l = max(l, i);
        r += i;
    }

    auto valid = [&] (ll x){
        ll part = 1, tot = 0;
        for(auto i:v){
            if(tot + i > x)part++, tot = i;
            else tot += i;
        }
        if(part > k)return false;
        return true;
    };

    ll lim = -1, mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(valid(mid))lim = mid, r = mid - 1;
        else l = mid + 1;
    }
    // cout<< lim << endl; // range limit 

    // printing 
    vector<ll>p = {n - 1}; // to store dividing points 
    ll tot = 0, sc = k;
    for(ll i = n - 1; i >= 0; i--){
        if(tot + v[i] > lim || i == sc - 2){
            p.pb(i);
            tot = v[i];
            sc--;
        }
        else tot += v[i];
    }
    // for(auto i:p)cout<< i << " ";e; 
    for(ll i = p.size() - 1, in = 0; i >= 0; i--){
        while(in <= p[i])cout<< v[in++] << " ";
        if(i > 0)cout<< "/ ";
    }e;


}

int main()
{
    istg();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    seive();
    ll t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++)
    solve(i);

}


inline void normal(ll &a){
    a %= M;
    (a < 0) && (a += M);
}
inline ll modMul(ll a, ll b){
    a %= M, b %= M;
    normal(a), normal(b);
    return (a*b)%M;
}
inline ll modAdd(ll a, ll b){
    a %= M, b %= M;
    normal(a), normal(b);
    return (a+b)%M;
}
inline ll modSub(ll a, ll b){
    a %= M, b %= M;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}
inline ll modPow(ll b, ll p){
    ll r = 1;
    while(p){
        if(p&1)r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1;
    }
    return r;
}
inline ll modInverse(ll a){
    return modPow(a, M-2);
}
inline ll modDiv(ll a, ll b){
    return modMul(a, modInverse(b));
}

