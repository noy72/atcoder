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

const long long M = 1000000007;

template<typename T>
class CumulativeSum {
	vector<T> a;
	public:
	CumulativeSum(vector<T>& x) : a(x.size() + 1,0) {
		rep(i,x.size()){
			a[i + 1] = a[i] + x[i];
		}
	}
	T get(int l, int r){ // [l, r]の区間の合計を求める
		return a[r + 1] - a[l];
	}
	T operator [] (const int i) const {
		return a[i];
	}
};

long long div2(long long a){
	int cnt = 0;
	while(a != 0){
		a/=2;
		cnt++;
	}
	return cnt;
}

long long solve(long long n, long long k, vector<long long> c, bool haveZero){
	k = min(3500LL, k);

	vector<vector<long long>> dp(n + 1, vector<long long>(k + 2));
	dp[0][1] = 1;
	range(i,1,n + 1){
		rep(j,k + 1){
			(dp[i - 1][j + 1] += dp[i - 1][j]) %= M;
		}
		//cout << "rui" << endl; rep(j,dp.size()){ rep(l,dp[j].size()){ cout << dp[j][l] << ' '; } cout << endl; } cout << endl;
		range(j,1,k + 2){
			//cout << j - c[i - 1] << ' ' << j + 1 << endl;
			//cout << dp[i - 1][j] - dp[i - 1][max<int>(0, j - c[i - 1] - 1)] << endl;
			dp[i][j] = (dp[i - 1][j] - dp[i - 1][max<int>(0, j - c[i - 1] - 1)] + M) % M;
		}

		//show("kekka") rep(j,dp.size()){ rep(l,dp[j].size()){ cout << dp[j][l] << ' '; } cout << endl; } cout << endl;
	}

	long long sum = 0;
	if(haveZero){
		rep(i, dp.back().size()){
			(sum += dp.back().at(i)) %= M;
		}
	}else{
		sum = dp.back().back();
	}
	//show(sum)
	return sum;
}

int main(){
	long long n, k;
	cin >> n >> k;

	vector<long long> a(n), c(n);
	cin >> a;

	rep(i,a.size()) c[i] = div2(a[i]);

	if(any_of(all(a), [](long long x) { return x == 0; })){
		cout << solve(n, k, c, true) << endl;
	}else{
		vector<long long> temp(all(c));
		for(auto &i : temp) if(i > 0) i--;
		long long sum = solve(n, k, temp, false);
		rep(i,n){
			if(c[i] <= k){
				int save = c[i];
				c[i] = 0;
				(sum += solve(n, k - save, c, true)) %= M;
				c[i] = save;
			}
			if(c[i] > 0) c[i]--;
		}
		cout << sum % M << endl;
	}
}
