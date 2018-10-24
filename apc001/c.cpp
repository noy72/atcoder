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

	cout << 0 << endl;
	vector<string> res(n,"a");
	cin >> res[0];

	int l = 0, r = n;
	rep(_,19){
		int mid = (l + r) / 2;
		if(mid == l) mid = r;
		//cout << l << ' ' << r << ' ' << res[l] << endl;;
		cout << mid << endl;

		cin >> res[mid];
		if(res[mid][0] == 'V') break;

		bool f = res[mid] == res[l];
		if((mid - l) % 2 == 1) f ^= 1;

		if(f){
			l = mid;
		}else{
			r = mid;
		}
	}
}
