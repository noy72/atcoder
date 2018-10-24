#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

int main(){
	int n;
	cin >> n;

	vector<int> a(n);
	cin >> a;

	vector<bool> dp(100001, false);
	dp[0] = true;
	rep(i,n){
		for (int j = 100000; j >= 0; j--) {
			if(j - a[i] < 0) continue;
			dp[j] = dp[j] | dp[j - a[i]];
		}
	}
	cout << accumulate(all(dp), 0) << endl;
}
