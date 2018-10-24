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

const int INF = 1e8;
int n, m;
vector<int> a, b;

vector<vector<int>> memo;
int dfs(int t, int i, int j){
	if(i >= n and j >= m) return 0;
	if(memo[i][j] != -1) return memo[i][j];

	int res;
	if(t){
		res = INF;
		if(i < n){
			res = min(res, dfs(t ^ 1, i + 1, j));
		}
		if(j < m){
			res = min(res, dfs(t ^ 1, i, j + 1));
		}
	}else{
		res = -INF;
		if(i < n){
			res = max(res, dfs(t ^ 1, i + 1, j) + a[i]);
		}
		if(j < m){
			res = max(res, dfs(t ^ 1, i, j + 1) + b[j]);
		}
	}
	return memo[i][j] = res;
}

int main(){
	cin >> n >> m;
	
	a = vector<int>(n);
	b = vector<int>(m);
	memo = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
	cin >> a >> b;
	cout << dfs(0, 0, 0) << endl;
}
