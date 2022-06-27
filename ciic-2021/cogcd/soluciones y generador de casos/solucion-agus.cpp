#include <iostream>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

const int MAXN = 4100000;

typedef long long tint;

tint a[MAXN], b[MAXN];
bool composite[MAXN];

// g(p,k) = p^k - p^(k-1) = phi(p^k)

void calcAB(int p, int k)
{
    // A(p^k) = g(k) * (p^k+1) + sum i de 1 a k-1 { g(k-i) * (p^k - p^(i-1)) }
    #define g(k) (pot[k] - pot[(k)-1])
    static tint pot[32];
    pot[0] = 1;
    forsn(i,1,k+1)
        pot[i] = pot[i-1] * p;
    tint &A = a[pot[k]] = g(k) * (1 + pot[k]);
    forsn(i,1,k)
        A += g(k-i) * (pot[k] - pot[i-1]);
    // B(p^k) = g(k) + sum i de 1 a piso(k/2) { g(k-i)) }
    tint &B = b[pot[k]] = g(k);
    forsn(i,1,k/2+1)
        B += g(k-i);
}

void criba()
{
    forn(i,MAXN)
        a[i] = b[i] = 1;
    forsn(p,2,MAXN)
    if (!composite[p])
    {
        calcAB(p,1);
        for (int n = 2*p; n < MAXN; n += p)
        {
            composite[n] = true;
            int extra = n;
            int k = 0;
            while (extra % p == 0)
            {
                extra /= p;
                k++;
            }
            // n = extra * p^k
            if (extra > 1)
            {
                a[n] *= a[n/extra];
                b[n] *= b[n/extra];
            }
            else
                calcAB(p,k);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    criba();
    
    int TT; cin >> TT;
    assert(1 <= TT);
    assert(TT <= 1000000);
    forn(tt,TT)
    {
        int n;
        cin >> n;
        assert(1 <= n);
        assert(n <= 4000000);
        cout << (a[n] + b[n]) / 2 << "\n";
    }
    
    return 0;
}
