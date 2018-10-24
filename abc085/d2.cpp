#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n, h;
	cin >> n >> h;

	vector<int> a(n), b(n);
	rep(i,n){
		cin >> a[i] >> b[i];
	}
	sort(all(a));
	sort(all(b));

	int cnt = 0;
	int p = n - 1;
	while(h > 0){
		if(n >= 0 and b[p] > a.back()){
			cnt++;
			h -= b[p];
			p--;
		}else{
			cnt += h / a.back();
			if(h % a.back() != 0) cnt++;
			break;
		}
	}
	cout << cnt << endl;
}
