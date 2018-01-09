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

	vector<pair<int, int>> v(n); //b a
	int p = 0;
	rep(i,n){
		cin >> v[i].second >> v[i].first; 
		if(v[p].second < v[i].second){
			p = i;
		}else if(v[p].second == v[i].second and v[p].first > v[i].first){
			p = i;
		}
	}
	pair<int, int> m = v[p];
	v.erase(next(v.begin(), p));
	sort(all(v), greater<pair<int, int>>());

	int cnt = 0;
	int i = 0;
	while(h > 0){
		if(not v.empty() and i < v.size() and m.second < v[i].first){
			h -= v[i].first;
			cnt++;
			i++;
		}else{
			if(m.first > m.second){
				cnt++;
				h -= m.first;
			}
			if(h <= 0) break;
			cnt += h / m.second + (h % m.second == 0 ? 0 : 1);
			break;
		}
	}
	cout << cnt << endl;
}
