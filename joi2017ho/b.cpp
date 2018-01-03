#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;


int main(){
	int t, b, A;
	cin >> t >> b >> A;
	vector<int> a(11);
	a[0] = 0;

	int sum = 0;
	range(i,1,10){
		sum += a[i - 1];
		a[i] = (t - sum * b) / A;
	}

	show(a.size())
	for(auto i : a){
		cout << i << ' ' ;
	}
	cout << endl;
}
