#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

/*
 * 一度にc_i個石が取れる。
 * 高さ iの山がa_i個
 * 取れる量が、山の高さによって変わる
 *
 */

vector<int> c, a;
//c_i := 山の高さがi + 1のとき、いくつ取れるか

vector<int> m;
int grundy(int n){
	auto& p = m[n];
	if(p != -1) return p;

	set<int> s;
	//show(c[n - 1] + 1)
	range(i,1,c[n - 1] + 1){
		s.emplace(grundy(n - i));
		if(n - i == 0) break;
	}


	int res = 0;
	while(s.count(res)) res++;
	return p = res;
}

int main(){
	int n;
	cin >> n;

	assert(n <= 100);


	c = vector<int>(n);
	a = vector<int>(n);
	rep(i,n - 1){
		cin >> c[i] >> a[i];
	}

	m = vector<int>(n + 1, -1);
	grundy(n - 1);
	//rep(i,n + 1){ cout << m[i] << endl; }

	int ans = 0;
	rep(i,n){
		if(a[i] % 2) ans ^= m[i + 1];
	}
	cout << (ans ? "First" : "Second") << endl;
}
