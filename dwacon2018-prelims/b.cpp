#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	string s;
	cin >> s;

	vector<int> v[3000];
	for(auto i : s){
		bool in = false;
		rep(j,3000){
			if(v[j].empty() and i == '5'){
				continue;
			}else if(v[j].empty() and i == '2'){
				in = true;
				v[j].emplace_back(2);
				break;
			}else if(v[j].back() == 2 and i == '5'){
				in = true;
				v[j].emplace_back(5);
				break;
			}else if(v[j].back() == 5 and i == '2'){
				in = true;
				v[j].emplace_back(2);
				break;
			}
		}
		if(not in){
			cout << -1 << endl;
			return 0;
		}
	}

	int cnt = 0;
	rep(i,3000){
		if(v[i].empty()) continue;
		if(v[i].back() == 2){
			cout << -1 << endl;
			return 0;
		}
		cnt++;
	}
	cout << cnt << endl;
}
