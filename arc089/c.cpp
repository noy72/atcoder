#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> t(n + 1);
	vector<pair<int, int>> p(n + 1);
	rep(i,n){
		cin >> t[i + 1] >> p[i + 1].first >> p[i + 1].second;
	}
	t[0] = 0;
	p[0] = make_pair(0,0);

	range(i,1,n + 1){
		int sum = abs(p[i].first - p[i - 1].first) + abs(p[i].second - p[i - 1].second);
		if(sum > t[i] - t[i - 1]){
			cout << "No" << endl;
			return 0;
		}else if((t[i] - t[i - 1] - sum) % 2 == 1){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
