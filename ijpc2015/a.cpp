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
	
	long long sum = 0;
	long long maxi = 0;
	rep(i,n){
		long long a;
		cin >> a;
		maxi = max(maxi, a);
		sum += a;
	}
	cout << sum + maxi + n << endl;
}
