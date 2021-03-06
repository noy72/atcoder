#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

int main(){
	int n, t;
	cin >> n >> t;

	vector<int> a(n);
	rep(i,n){
		cin >> a[i];
	}

	vector<int> maxi(n,0);
	for(int i = n - 1; i >= 0; i--){
		if(i == n - 1) maxi[i] = a[i];
		else maxi[i] = max(maxi[i + 1], a[i]);
	}

	vector<int> result(n);
	rep(i,n - 1){
		result[i] = maxi[i + 1] - a[i];
	}

	int max_res = *max_element(all(result));
	int ans = 0;
	for_each(all(result), [&](int a){ if(max_res == a) ans++; });
	cout << ans << endl;
}
