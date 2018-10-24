#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

int main(){
	int n, m;
	cin >> n >> m;

	vector<vector<long long>> a(n, vector<long long>(3));
	rep(i,n){
		rep(j,3) cin >> a[i][j];
	}


	long long ans = 0;
	rep(s,1 << 3){
		vector<long long> p(n);

		rep(i,n){
			long long cnt = 0;
			rep(j,3){
				if(s >> j & 1){
					cnt += a[i][j];
				}else{
					cnt -= a[i][j];
				}
			}
			p[i] = cnt;
		}

		sort(all(p), greater<long long>());

		long long sum = 0;
		rep(i,m){
			sum += p[i];
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}
