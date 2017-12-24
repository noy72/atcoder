#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

char in[2005][2005];
char m[2005][2005];
int c[2005][2005];

int maximumRectangule(int h, int w){
	rep(i,w){
		int cnt = 0;
		rep(j,h){
			if(m[j][i] == '.'){
				cnt++;
				c[j][i] = cnt;
			}else{
				cnt = 0;
			}
		}
	}

	//rep(i,h){ rep(j,w){ cout << c[i][j]; } cout << endl; }

	int ans = 0;
	rep(i,h){
		vector<pair<int, int>> v; //height, pos
		rep(j,w + 1){
			if(v.empty()) v.emplace_back(c[i][j],j);
			else{
				if(v.back().first < c[i][j]) v.emplace_back(c[i][j],j);
				else{
					int target = j;
					while(not v.empty() && v.back().first >= c[i][j]){
						ans = max(ans, (v.back().first + 1) * (j - v.back().second + 1));
						target = v.back().second;
						v.pop_back();
					}
					v.emplace_back(c[i][j],target);
				}
			}
		}
	}
	return ans;
}


int main(){
	int h, w;
	cin >> h >> w;

	rep(i,h) cin >> in[i];
	rep(i,h) rep(j,w) m[i][j] = '.';

	rep(i,h - 1){
		rep(j,w - 1){
			int w = 0, b = 0;
			rep(k,2){
				rep(l,2){
					if(in[i + k][j + l] == '#') b++;
					else w++;
				}
			}
			if(w == 3 or b == 3){
				m[i][j] = '#';
			}
		}
	}

	//rep(i,h - 1){ rep(j,w - 1){ cout << m[i][j]; } cout << endl; }

	cout << max({maximumRectangule(h - 1, w - 1), h, w}) << endl;
}
