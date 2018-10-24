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

	vector<int> a(n,0);
	rep(i,n){
		int x;
		cin >> x;
		a[x - 1]++;
	}

	int cnt = 0;
	for(auto i : a) if(i != 0) cnt++;
	
	int l = 0, r = 100000 - 1;
	while(l < r - 1){
		while(a[l] == 0 and l < n) l++;
		while(a[r] == 0 and r >= 0) r--;

	}
}
