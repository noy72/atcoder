#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n, p;
	cin >> n >> p;

	int b = 0;
	vector<pair<int, pair<int,int>>> in;
	rep(i,n){
		int x, y;
		cin >> x >> y;
		b += y;
		in.emplace_back(x / x + y, make_pair(x,y));
	}
	sort(all(in), greater<pair<int, pair<int,int>>>());

	int w = 0;
	rep(i,n){
		w += in[i].second.first;
		b -= in[i].second.second;
		if(w * 100 >= p * (w + b)){
			cout << i + 1 << endl;
			return 0;
		}
	}
}
