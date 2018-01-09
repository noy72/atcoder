#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n, m, s;
	cin >> n >> m >> s;

	vector<int> sum(s + 1, 0);
	rep(i,n){
		int t, k;
		cin >> t >> k;
		sum[t - 1] = k;
	}

	int cnt = 0;
	rep(i,s - 1){
		if(i != 0){
			sum[i] += sum[i - 1];
		}
		if(sum[i] >= m) cnt++;
	}
	cout << cnt << endl;
}
