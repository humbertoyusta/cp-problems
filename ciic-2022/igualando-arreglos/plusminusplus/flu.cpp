#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define yes cout<<'Y'<<'E'<<'S'<<endl
#define no cout<<'N'<<'O'<<endl

///

vector<ll> dp;
ll calc(ll n){
	return dp[(n+6)%6]+dp[(n+5)%6]-dp[(n+3)%6]-dp[(n+2)%6];
}

void solve(){
	
	dp.assign(10, 0);
	
	ll n, q;
	cin >> n >> q;
	
	vector< vector<ll> > contador(n+10, vector<ll>(10, 0));

		
	ll a[n+1], b[n+1];
	for(ll i = 1; i <= n; i++) cin >> a[i];
	for(ll i = 1; i <= n; i++) cin >> b[i];
			
	for(ll i = 1; i <= n; i++){
		contador[i] = contador[i-1];
		contador[i][i%6]++;
	}
	
	for(ll i = 1; i <= n-2; i++){
		dp[i%6]+= b[i] - a[i];
	}
	
	ll dn1 = b[n] - a[n], dn2 = b[n-1] - a[n-1];
	ll en0, en1;
	ll n2, n3; 
	
	n2 = calc(n-2), n3 = calc(n-3);
	en0 = dn1 - n2;
	en1 = dn2 + n2 - n3; 
	if(en1 == 0 && en0 == 0) yes;
	else no;
	cout.flush();

	ll l, r, v;
	for(ll i = 0; i < q; i++){
		cin >> l >> r >> v;
		l--;
				
		if(r == n){
			dn1 -= v;
			r--;  
		}
		
		if(r == n-1){
			dn2 -= v;
			r--;
		}
		
		for(ll i2 = 0; i2 < 6; i2++){
			dp[i2] -= (contador[r][i2] - contador[l][i2])*v;
		} 
		
		n2 = calc(n-2), n3 = calc(n-3);
		en0 = dn1 - n2;
		en1 = dn2 + n2 - n3; 
		if(en1 == 0 && en0 == 0) yes;
		else no;
		cout.flush();
	}	
}

int main (){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  //cin >> t;
  while(t-->0) solve();
  return 0;
}
