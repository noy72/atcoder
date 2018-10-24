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

	vector<long long> a;
	a.emplace_back(0);
	rep(i,n){
		long long in;
		cin >> in;
		a.emplace_back(in);
	}
	a.emplace_back(0);

	long long ans = 0;
	rep(i,a.size() - 1){
		ans += abs(a[i] - a[i + 1]);
	}

	range(i,1,n + 1){
		if(a[i - 1] <= a[i] and a[i] <= a[i + 1]) cout << ans << endl;
		else if(a[i - 1] >= a[i] and a[i] >= a[i + 1]) cout << ans << endl;
		else{
			cout << ans - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]) + abs(a[i - 1] - a[i + 1]) << endl;
		}
	}
}
