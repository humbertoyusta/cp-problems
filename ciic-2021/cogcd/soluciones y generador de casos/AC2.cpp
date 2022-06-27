/**    Solucion oficial aceptada -- Complejidad O(n)      */
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(4e6+5)

ll prime[MAXN];
ll tot[MAXN];
ll eq[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!prime[i])
            for(int j=i;j<MAXN;j+=i)
                prime[j]=i;
    tot[1]=1;
    eq[1]=1;
    for(int i=2;i<MAXN;i++)
    {
        int cpy_i=i;
        ll p=prime[i];
        ll e=0;
        while(!(cpy_i%p))
        {
            cpy_i/=p;
            e++;
        }
        vector<ll> phis;
        phis.push_back(1);
        phis.push_back(p-1);
        ll ac=p;
        for(int i=1;i<e;i++)
        {
            phis.push_back(phis.back()*p);
            ac*=p;
        }

        reverse(all(phis));

        ll m_tot=0;
        ll m_eq=0;
        for(int i=0;2*i<=e;i++)
            m_eq+=phis[i];
        for(int i=0;i<=e;i++)
        {
            m_tot+=phis[i]*ac;
            ac-=phis[e-i];
        }

        tot[i]=m_tot*tot[cpy_i];
        eq[i]=m_eq*eq[cpy_i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    //freopen("a.in","r",stdin);

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout << (tot[n]+eq[n])/2 << '\n';
    }

    return 0;
}
/**
20
1
2
3
4
5
6
7
8
9
10
20
30
50
100
500
600
1000
3000
4000
10000
**/
