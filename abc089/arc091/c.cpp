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
	if(a == 1 and b == 1){
		cout << 1 << endl;
	}else if(a == 1 or b == 1){
		cout << max(a,b) - 2 << endl;
	}else if(a == 2 or b == 2){
		cout << 0 << endl;
	}else{
		cout << a * b - 2 * a - 2 * b + 4 << endl;
	}
}
