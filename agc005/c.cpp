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

	vector<int> a(n);
	map<int,int> m;
	rep(i,n){
		cin >> a[i];
		m[ a[i] ]++;
	}

	int diameter = prev(m.end(),1)->first;

	bool f = true;
	if(diameter % 2 == 0){
		range(i, diameter / 2 + 1, diameter + 1){
			m[i]-=2;
		}
		m[diameter / 2]--;

		for(auto i : m){
			if(i.second < 0){
				f = false;
			}
			if(i.second > 0 && i.first < diameter / 2 + 1){
				f = false;
			}
		}
	}else{
		range(i, (diameter + 1) / 2, diameter + 1){
			m[i]-=2;
		}

		for(auto i : m){
			if(i.second < 0){
				f = false;
			}
			if(i.second > 0 && i.first < (diameter + 1) / 2 + 1){
				f = false;
			}
		}
	}
	cout << (f ? "Possible" : "Impossible") << endl;
}
