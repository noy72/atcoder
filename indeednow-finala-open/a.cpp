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

	vector<int> a(n);
	rep(i,n){
		cin >> a[i];
	}
	sort(all(a));

	vector<int> p(n / 2);
	rep(i,n / 2){
		p[i] = a[i] + a[n - i - 1];
	}

	cout << *max_element(all(p)) - *min_element(all(p)) << endl;
}
