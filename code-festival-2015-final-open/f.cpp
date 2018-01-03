#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	vector<long long> c(7);
	rep(i,7) cin >> c[i];

	if(*min_element(all(c)) == 0 or c[0] < 2){
		cout << "NO" << endl;
		return 0;
	}


}
