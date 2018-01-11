#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

bool s[2005][2005];
bool c[2005][2005] = {{0}};
char t[2005][2005];

int maximumRectangule(int h, int w, char m[2005][2005]){
	int c[2005][2005] = {{0}};
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
	rep(i,h) c[i][w] = 0;

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
						ans = max(ans, v.back().first * (j - v.back().second));
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

	rep(i,h){
		rep(j,w){
			char x;
			cin >> x;
			s[i][j] = x  == '#' ? 1 : 0;
		}
	}

	rep(i,h - 1){
		rep(j,w - 1){
			int cnt = 0;
			if(s[i][j]) cnt++;
			if(s[i + 1][j]) cnt++;
			if(s[i][j + 1]) cnt++;
			if(s[i + 1][j + 1]) cnt++;
			if(cnt % 2) c[i][j] = 1;
		}
	}

	rep(i,2005) rep(j,2005) t[i][j] = '.';
	rep(i,h - 1){
		rep(j, w - 1){
			if(c[i][j]){
				t[i][j] = '#';
				t[i][j + 1] = '#';
				t[i + 1][j] = '#';
				t[i + 1][j + 1] = '#';
			}
		}
	}
	rep(i,h - 0){
		rep(j,w - 0){
			cout << t[i][j] << ' ';
		}
		cout << endl;
	}



	cout << maximumRectangule(h, w, t) << endl;
}
