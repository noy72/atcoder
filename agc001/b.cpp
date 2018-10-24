#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

long long dfs(long long l, long long m){
	if(l % m){
		return l / m * 2 * m + dfs(m, l % m);
	}else{
		return l / m * 2 * m - m;
	}
}

int main(){
	long long n, x;
	cin >> n >> x;

	cout << dfs(n - x, x) + n << endl;
}
