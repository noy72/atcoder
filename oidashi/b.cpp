#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int dy[5] = { 0,-1, 0, 1, 0};
const int dx[5] = { 1, 0,-1, 0, 0};

class FlipPazzule{
	private:
		int h, w;
		vector<vector<int>> tile;
		vector<vector<int>> opt;		//最適解保存用
		vector<vector<int>> flip;		//作業用
		vector<vector<int>> broken;		//反転できない場所
		int get(int y, int x){			//色を求める
			int c = tile[y][x];
			rep(i,5){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
				c += flip[ny][nx];
			}
			return c % 2;
		}
		int calc(){						//一行目を決めた場合の最小操作回数
			range(i,1,h){
				rep(j,w){
					if(get(i - 1, j) != 0){
						if(broken[i][j] == 1){
							return -1;
						}
						flip[i][j] = 1;
					}
				}
			}

			rep(i,w){
				if(get(h - 1, i) != 0){
					return -1;			//解なし
				}
			}

			int res = 0;
			rep(i,h){
				rep(j,w){
					res += flip[i][j];
				}
			}
			return res;
		}
	public:
		FlipPazzule(vector<vector<int>>& in, vector<vector<int>>& b){
			h = in.size();
			w = in[0].size();
			tile = in; 
			opt = vector<vector<int>>(h, vector<int>(w));
			flip = vector<vector<int>>(h, vector<int>(w));
			broken = b;
		}
		int solve(){
			int res = -1;

			rep(i,1 << w){				//一行目を辞書順で全探索
				flip = vector<vector<int>>(h, vector<int>(w,0));
				rep(j,w){
					flip[0][j] = i >> j & 1;
					if(flip[0][j] == 1 and broken[0][j] == 1){
						continue;
					}
				}
				int num = calc();
				if(num >= 0 and (res < 0 or res > num)){
					res = num;
					opt = flip;
				}
			}

			if(res < 0){
				assert(false);			//解なし
			}else{
				return res;
			}
		}
		void output(vector<vector<int>> v){
			rep(i,h){ rep(j,w){
				cout << v[i][j] << ' ';
			} cout << endl; }
		}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int h, w;
	cin >> h >> w;

	vector<vector<int>> in, b;
	if(h >= w){
		in = vector<vector<int>>(h, vector<int>(w));
		b = vector<vector<int>>(h, vector<int>(w,0));
		rep(i,h){
			rep(j,w){
				cin >> in[i][j];
			}
		}
		int n;
		cin >> n;
		rep(i,n){
			int y, x;
			cin >> x >> y;
			b[y][x] = 1;
		}
	}else{
		swap(h,w);
		in = vector<vector<int>>(h, vector<int>(w));
		b = vector<vector<int>>(h, vector<int>(w,0));
		rep(i,w){
			rep(j,h){
				cin >> in[j][w - 1 - i];
			}
		}
		int n;
		cin >> n;
		rep(i,n){
			int y, x;
			cin >> x >> y;
			b[x][w - 1 - y] = 1;
		}
	}


	FlipPazzule p(in,b);
	cout << p.solve() << endl;
}
