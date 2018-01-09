#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	rep(i,n) cin >> a[i];

	int l = 0, r = -1;
	int ans = 0;
	int h = 0;
	while(true){
		while(r < n - 1){
			if(a[r + 1] == 1){
				r++;
			}else if(a[r + 1] == 0 and h + 1 <= k){
				r++;
				h++;
			}else{
				break;
			}
		}
		//show(h)
		//cout << l << ' ' << r << endl;
		ans = max(ans, r - l + 1) ;
		if(h < k) break;
		h -= a[l++] ? 0 : 1;
	}

	cout << ans << endl;
}
