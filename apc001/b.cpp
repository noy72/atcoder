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

	vector<long long> a(n), b(n);
	rep(i,n){
		cin >> a[i];
	}
	rep(i,n){
		cin >> b[i];
	}

	long long plus = 0, minus = 0;
	rep(i,n){
		long long tmp = a[i] - b[i];
		if(tmp > 0LL) plus += tmp;
		else minus += tmp / 2;
	}
	cout << (plus <= -minus ? "Yes" : "No") << endl;
}
