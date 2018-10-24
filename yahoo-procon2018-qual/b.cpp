#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	long long x, k;
	cin >> x >> k;
	
	if(k == 0){
		cout << x + 1 << endl;
		return 0;
	}

	long long t = pow(10,k);
	long long tmp = x + t;
	cout << tmp / t * t << endl;
}
