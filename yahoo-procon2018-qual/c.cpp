#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const long long INF = (1LL << 60);
using namespace std;

//i番目のビットを返す
bool getBit(int num, int i){
	return ((num & (1 << i)) != 0);
}

//i番目を1にする
int setBit(int num, int i){
	return num | (1 << i);
}

//i番目を0にする
int clearBit(int num, int i){
	int mask = ~(1 << i);
	return num & mask;
}

//i番目をvで置き換える
int updateBit(int num, int i, int v){
	int mask = ~(1 << i);
	return (num & mask) | (v << i);
}

long long dfs(vector<long long>& v, vector<long long>& c, long long W, long long V, int i){
	if(i == v.size()) return V;

	long long res = 0;
	if(W - v[i] >= 0) res = dfs(v, c, W - v[i], V + c[i], i + 1);
	res = max(res, dfs(v, c, W, V, i + 1));
	return res;
}

int main(){
	int n;
	cin >> n;

	vector<long long> x(n), v(n), c(n);
	rep(i,n){ cin >> x[i]; }
	rep(i,n){ cin >> v[i]; }
	rep(i,n){ cin >> c[i]; }

	vector<long long> sum(n + 1, 0);
	rep(i,n){
		sum[i + 1] = sum[i] + x[i];
	}

	vector<long long> sc, sv;
	long long ans = 0;
	int s = 0;
	rep(i,n){
		long long ns, mini = INF;
		rep(j,n){
			if(not getBit(s,j)){
				sv.emplace_back(v[j]);
				sc.emplace_back(c[j]);
				long long tmp = dfs(sv, sc, sum[n - i - 1], 0, 0);
				if(tmp < mini){
					mini = tmp;
					ns = j;
				}
				sv.pop_back();
				sc.pop_back();
			}
		}
		sv.emplace_back(v[ns]);
		sc.emplace_back(c[ns]);
		s = setBit(s,ns);
		ans = max(ans, mini);
	}
	cout << ans << endl;
}
