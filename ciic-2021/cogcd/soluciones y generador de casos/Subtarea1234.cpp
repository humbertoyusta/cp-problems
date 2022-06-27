/**    Solucion oficial para las subtareas 1 2 3 y 4 -- Complejidad O(n*cubic_root(n))     */
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

ll phi[MAXN];
ll p[MAXN];
ll e[MAXN];

void criba()
{
    p[1]=1;
    for(int i=2;i<MAXN;i++)
        if(!p[i])
            for(int j=i;j<MAXN;j+=i)
                p[j]=i;
    phi[1]=1;
    for(int i=2;i<MAXN;i++)
    {
        if((i/p[i])%p[i])
            phi[i]=phi[i/p[i]]*(p[i]-1);
        else
            phi[i]=phi[i/p[i]]*(p[i]);
    }
}

vector<pii> fac(int n)
{
    vector<pii> ans;
    while(n!=1)
    {
        e[p[n]]++;
        if(e[p[n]]==1)
            ans.push_back(pii(p[n],1));
        else
            ans.back().s++;
        n/=p[n];
    }
    for(auto pe : ans)
        e[pe.f]=0;
    return ans;
}

ll solve(int n)
{
    if(n==1)
        return 1;

    vector<pii> dec=fac(n);
    ll tot=1;
    ll eq=1;
    for(auto pe : dec)
    {
        vector<ll> phis;
        ll p=pe.f;
        ll e=pe.s;
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

        tot*=m_tot;
        eq*=m_eq;
    }
    return (tot+eq)/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    //for(int i=1; i<maxn; i++)
    //    f[i] = solve(i);

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}
