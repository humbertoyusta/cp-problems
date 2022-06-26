    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
/// Macros:
//#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define enl '\n'
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const int mod2 = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lgx(x,b) ( log(x) / log(b) )
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Pow------------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){ return qpow(x,mod-2); }
bool isprime(int x){
    for(int i=2; i*i<=x; i++)
        if( x % i == 0 )
            return false;
    return true;
}
/// My Code -------------------------------------------------

int tc, n;
vector<int> pr;
vector<ii> fact;
int frec[maxn];
int g[12011][12011];

int gcd(int a,int b){
    if( a < b ) swap( a , b );
    return g[a][b] = g[b][a%b];
}

int brute(int x){
    int brute_ans = 0;
    for(int i=1; i<=x; i++)
        for(int j=1; j<=x; j++)
            if( i * __gcd(i,j) + j * __gcd(i,j) == x ){
                brute_ans ++;
            }
    return brute_ans;
}

int phi(int x){
    if( x == 1 ) return 0;
    int ret = x;
    for(auto i : fact){
        int cnt_ = 0;
        while( x % i.f == 0 ) cnt_ ++, x /= i.f;
        if( cnt_ )
            ret = ret - ret / i.f;
    }
    return ret;
}

int solve(int x){

    int y = floor( sqrt(x) + eps );

    fact.clear();

    for(auto i : pr){
        if( i * i > y ) break;
        if( y % i == 0 ){
            int cnt_ = 0;
            while( y % i == 0 ) cnt_++, y/=i;
            fact.pb({i,cnt_});
        }
    }
    if( y > 1 ){
        fact.pb({y,1});
    }

    y = floor( sqrt(x) + eps );

    int ans = 0;
    for(int i=1; i*i<=y; i++){
        if( y % i == 0 ){
            ans = ( ans + phi(x/(i*i)) ) % mod;
            if( i * i != y ){
                ans = ( ans + phi(x/((y/i)*(y/i))) ) % mod;
            }
        }
    }
    return ans;
}

void prec_slow(int lim){
    for(int i=1; i<=lim; i++)
        for(int j=1; j<=lim; j++){
            int x = __gcd(i,j);
            if( x * ( i + j ) < lim )
                frec[x * ( i + j )] ++;
        }
}

void prec_fast(int lim){
    for(int i=1; i<=lim; i++)
        for(int j=1; j<=lim; j++){
            int x = gcd(i,j);//2cout << i << ' ' << j << ' ' << gcd(i,j) << '\n';
            if( x * ( i + j ) < lim )
                frec[x * ( i + j )] ++;
        }
}

int query(int x){
    return frec[x];
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    for(int i=2; i*i<=1000000000; i++)
        if( isprime(i) )
            pr.pb(i);

    cin >> tc;
    vector<int> vv;
    int mx = 0;
    while( tc-- ){
        int u;
        cin >> u;
        vv.pb(u);
        mx = max( mx , u );
    }
    for(int i=0; i<=mx; i++)
        g[i][0] = g[0][i] = i;
    prec_fast(mx+1);

    for( auto i : vv ){
        cout << query(i) << '\n';
    }

    return 0;
}
