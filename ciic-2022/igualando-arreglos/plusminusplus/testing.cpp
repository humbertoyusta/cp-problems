#include<bits/stdc++.h>
using namespace std;
/// Pragmas
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
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

int tc;
vector<int> A, B, F;

int rand_(int l,int r){
    return l + rand() % (r - l + 1);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    freopen("a.in","w",stdout);

//    vector<int> A, B;
//    for(int i=0; i<30; i++){
//        A.pb(1);
//        B.pb(1);
//        if( i % 6 == 0 ) A[i] += 10;
//        if( i % 6 == 3 ) B[i] += 10;
//    }
//    for(int i=30; i<60; i++){
//        A.pb(1);
//        B.pb(1);
//        if( i % 6 == 0 ) B[i] += 10;
//        if( i % 6 == 3 ) A[i] += 10;
//    }
//
//    cout << A.size() << ' ' << 0 << '\n';
//    for( auto i : A ) cout << i << ' ';
//    cout << '\n';
//    for( auto i : B ) cout << i << ' ';
//    cout << '\n';

                int n = 1000;
                A.clear();
                B.clear();
                F.clear();
                F.pb(0);
                vector<int> D;

                for(int i=1; i<=n; i++){
                    if( i < n - 2 ) D.pb( rand_(-(1000000/3-10),1000000/3-10) );
                    if( i == n - 2 ) D.pb(0);
                    if( i == n - 1 ) D.pb(0);

                    A.pb(1);
                    B.pb(1);

                    if( i > 1 ) F.pb( B[i-1] - A[i-1] + F[i-1] - F[i-2] );
                        else F.pb( B[i-1] - A[i-1] );

                    int toch = D.back() - F.back();
                    if( toch >= 0 ) B[i-1] += toch;
                        else A[i-1] -= toch;

                    //if( A[i-1] > limit || B[i-1] > limit ) break;
                    int toadd = rand_( 0 , min( 1000000 - A[i-1] , 1000000 - B[i-1] ) );
                    A[i-1] += toadd;
                    B[i-1] += toadd;

                    if( i > 1 ) F[i] = B[i-1] - A[i-1] + F[i-1] - F[i-2];
                        else F[i] = B[i-1] - A[i-1];
                    cout << A[i-1] << ' ' << B[i-1] << ' ' << F[i] << '\n';
                }

    return 0;
}
