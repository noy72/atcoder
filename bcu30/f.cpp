#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

//x^n mod M
typedef long long ull;
const ull M = 1000000007;
ull power(ull x, ull n){
	ull res = 1;
	if(n > 0){
		res = power(x, n / 2);
		if(n % 2 == 0) res = (res * res) % M;
		else res = (((res * res) % M) * x ) %M;
	}
	return res;
}

long long accumu_mod(vector<long long>& v){
	long long res = 0;
	for(auto i : v){
		(res += i) %= M;
	}
	return res;
}

int main(){
	int n;
	cin >> n;

	vector<long long> a(n), s(n);
	rep(i,n){
		cin >> a[i];
		if(i == 0){
			s[i] = a[i] * power(2,max(n - 2, 0)) % M;
		}else if(i == n - 1){
			s[i] = s[i - 1] * a[i] % M;
		}else{
			s[i] = s[i - 1] * a[i] % M * power(2, M - 2) % M;
		}
	}

	long long sum = accumu_mod(s);
	long long ans = 0;
	rep(i,n){
		(ans += sum) %= M;
		sum -= a[i] * power(2, max(i - 1, 0)) % M * power(2, max(n - i - 2, 0)) % M; //右端がa[i]の項目を消す
		(sum += M) %= M;

		(sum *= power(a[i], M - 2)) %= M; //合計をa[i]で割る
		if(i) sum *= 2;

	}
	cout << ans << endl;
}
