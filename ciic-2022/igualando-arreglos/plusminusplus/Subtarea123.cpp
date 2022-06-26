/**   Solucion aceptada para las subtareas 1, 2 y 3 -- Complejidad O(n+sum(r[i]-l[i]) )                   */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
/// Macros:
#define int long long
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
const int maxn = 200010;
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

vector<long long> F(maxn);

void init(int n,vector<int> &A,vector<int> &B){
    F[1] = B[1] - A[1];
    //cout << F[1] << ' ';
    for(int i=2; i<=n; i++){
        F[i] = B[i] - A[i] + F[i-1] - F[i-2];
        //cout << F[i]<< ' ';
    }
}

void process(int id,long long x,int n){
    int y = ( n - id ) % 6;
    if( y == 0 || y == 1 ) F[n] -= x;
    if( y == 3 || y == 4 ) F[n] += x;
    if( y == 2 || y == 5 ) F[n] += 0;

    if( id <= n - 1 ){
        y = ( n - 1 - id ) % 6;
        if( y == 0 || y == 1 ) F[n-1] -= x;
        if( y == 3 || y == 4 ) F[n-1] += x;
        if( y == 2 || y == 5 ) F[n-1] += 0;
    }
}

void slow_update(int l,int r,long long x,int n){
    for(int i=l; i<=r; i++)
        process(i,x,n);
}

void fast_update(int l,int r,long long x,int n){
    for(int i=r; i>=l; i--){
        process(i,x,n);
        if( i % 6 == l % 6 && i < n - 1 )
            break;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    int n, q;
    cin >> n >> q;

    vector<int> A(n+10), B(n+10);

    for(int i=1; i<=n; i++)
        cin >> A[i];

    for(int i=1; i<=n; i++)
        cin >> B[i];

    init(n,A,B);

    if( F[n] == 0 && F[n-1] == 0 ) cout << "YES\n";
        else cout << "NO\n";

    for(int i=1; i<=q; i++){
        int l, r, x;
        cin >> l >> r >> x;
        slow_update(l, r, x, n);
        if( F[n] == 0 && F[n-1] == 0 ) cout << "YES\n";
            else cout << "NO\n";
        //cout << F[n-1] << ' ' << F[n] << '\n';
    }

    return 0;
}
