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

	vector<int> a(n),b(n);
	rep(i,n){
		cin >> a[i];
	}
	rep(i,n){
		cin >> b[i];
	}

	int ans = 0;
	rep(i,n){
		int sum = 0;
		rep(j,n){
			if(i >= j){
				sum += a[j];
			}
			if(i <= j){
				sum += b[i];
			}
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}
