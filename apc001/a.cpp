#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	long long a, b;
	cin >> a >> b;

	if(a % b == 0){
		cout << -1 << endl;
	}else{
		while(a % b == 0){
			a+=a;
		}
		cout << a << endl;
	}
}
