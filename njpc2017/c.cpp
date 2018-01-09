#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n, l;
	cin >> n >> l;
	
	l*=2;
	vector<int> x(n);
	rep(i,n){
		int a;
		cin >> a;
		x[i] = a * 2;
	}

}
