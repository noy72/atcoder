#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

template <class T> class CumulativeSum2D {
	public:
		vector<vector<T>> s;
		int h, w;
		CumulativeSum2D(const vector<vector<T>> &a) {
			h = a.size();
			w = a[0].size();
			s = vector<vector<T>>(h + 1, vector<T>(w + 1, 0));
			rep(i, h) rep(j, w) s[i + 1][j + 1] = a[i][j];
			rep(i, h + 1) rep(j, w) s[i][j + 1] += s[i][j];
			rep(i, h) rep(j, w + 1) s[i + 1][j] += s[i][j];
		}

		int sum(int i, int j, int h, int w) {
			return s[i + h][j + w] - s[i][j + w] + s[i][j] - s[i + h][j];
		}

		int maximum(){
			int res = -INF;
			rep(i,h){
				rep(j,w){
					cout << s[i][j] << ' ';
					res = max(res, s[i][j]);
				}
				cout << endl;
			}
			return res;
		}

		int maximumSubMatrix(){
			int ret = -INF;
			rep(i,h + 1) rep(j,w + 1) range(k,1,h - i + 1) range(l,1,w - j + 1){
				ret = max(ret, sum(i,j,k,l));
			}
			return ret;
		}
};

int main(){
	int n, k;
	cin >> n >> k;

	vector<vector<int>> v(k * 2 + 1, vector<int>(k * 2 + 1,0));
	rep(i,n){
		int x, y;
		char c;
		cin >> x >> y >> c;
		x = x % (2 * k);
		if(c == 'B'){
			y = y % (2 * k);
		}else{
			y = (y + k) % (2 * k);
		}

		//左上、右下
		int lx = max(0, x - k + 1);
		int ly = y;
		int rx = min(k * 2 - 1, x + 1);
		int ry = max(0, y - k);
		cout << lx << ' ' << ly << ' ' << rx << ' ' << ry << endl;
		v[ly][lx]++;
		v[ry][rx]++;
		v[ly][rx]--;
		v[ry][lx]--;
	}
	rep(i,k * 2){
		rep(j,k * 2){
			cout << v[i][j] << ' ' ;
		}
		cout << endl;
	}
	CumulativeSum2D<int> sum(v);
	cout << sum.maximum() << endl;
}
