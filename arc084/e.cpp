#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const double EPS = 1e-18;

int main(){
	int k, n;
	cin >> k >> n;

	assert(k % 2 == 0);
	//kが偶数のときのみの解法を書いたら嘘だったので、問題を理解できていないっぽい
	cout << k / 2;
	rep(i,n - 1){
		cout << ' ' << k / 2 + 1;
	}
	cout << endl;
		return 0;

	double t = 0.5;
	double cnt = 0;

	vector<int> ans;
	while(t - cnt < EPS){

	}
}
