#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n, q;
	cin >> n >> q;

	rep(i,q){
		int a, b;
		cin >> a >> b;
		a-=2; b-=2;

		if(n == 1){
			cout << min(a,b) + 2 << endl;
			continue;
		}

		while(a != b){
			if(a > b){
				a = a / n - 1;
			}else{
				b = b / n - 1;
			}
		}
		cout << a + 2 << endl;
	}
}
