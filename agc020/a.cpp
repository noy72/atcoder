#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n, a, b;
	cin >> n >> a >> b;

	if((b - a) % 2 == 1){
		cout << "Borys" << endl;
	}else{
		cout << "Alice" << endl;
	}
}
