/**    Solucion oficial para las subtareas 1 2 3 y 4 -- Complejidad O(n*log(n)*cubic_root(n)) pero con baja constante    */
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
const int maxn = 4000010;
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

int tc, phi[maxn], pr[maxn], prpw[maxn], pot[(int)sqrt(maxn)+11][25], f[maxn];
vector<int> dv[maxn];

int qpot(int x,int y){
    if( y == 0 ) return 1;
    if( y == 1 ) return x;
    return pot[x][y];
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    phi[1] = 1;

    for(int i=0; i<sqrt(maxn)+10; i++){
        pot[i][0] = 1;
        for(int j=1; j<24; j++){
            pot[i][j] = pot[i][j-1] * i;
            if( pot[i][j] > (1ll<<30) ) break;
        }
    }

    for(int i=0; i<maxn; i++){
        prpw[i] = 1;
        pr[i] = i;
    }

    for(int i=2; i<maxn; i++){
        if( pr[i] == i ){
            for(int j=i*i; j<maxn; j+=i){
                if( pr[j] == j ){
                    pr[j] = i;
                    if( pr[j/i] == i ) prpw[j] = prpw[j/i] + 1;
                        else prpw[i] = 1;
                }
            }
        }
        if( i == qpot(pr[i],prpw[i]) ) phi[i] = qpot(pr[i],prpw[i]) - qpot(pr[i],prpw[i]-1);
            else phi[i] = phi[i/qpot(pr[i],prpw[i])] * phi[qpot(pr[i],prpw[i])];
    }

    int C = 0;
    for(int i=1; i<maxn; i++){
        for(int j=i; j<maxn; j+=i){
            dv[j].pb(i);C++;
        }
        //db(C)
    }

    for(int n=1; n<maxn; n++){
        int ans = 0;
        for(auto i : dv[n]){
            for(auto j : dv[n/i]){
                if( i != j ){
                    ans += phi[n/i] * phi[n/j];
                }
            }
        }
        for( auto i : dv[n] ){
            if( n % ( i * i ) == 0 ){
                ans += phi[n/i] * ( phi[n/i] + 1 );
            }
        }
        f[n] =  ans / 2;
    }

    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;
        cout << f[n] << '\n';
    }

    return 0;
}
