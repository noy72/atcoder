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

		int maximumSubMatrix(){
			int ret = -INF;
			rep(i,h + 1) rep(j,w + 1) range(k,1,h - i + 1) range(l,1,w - j + 1){
				ret = max(ret, sum(i,j,k,l));
			}
			return ret;
		}
		void output(){
			rep(i,h + 1){
				rep(j,w + 1){
					cout << s[i][j] << ' ';
				}
				cout << endl;
			}
		}
};

int main(){
	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<int>> va(n, vector<int>(m,0));
	rep(i,n){
		rep(j,m){
			char a;
			cin >> a;
			va[i][j] = a - '0';
		}
	}

	vector<vector<int>> hol(n, vector<int>(m,0));
	vector<vector<int>> var(n, vector<int>(m,0));
	rep(i,n - 1){
		rep(j,m){
			if(va[i][j] && va[i + 1][j]) var[i][j] = 1;
			//cout << var[i][j];
		}
		//cout << endl;
	}
	rep(i,n){
		rep(j,m - 1){
			if(va[i][j] && va[i][j + 1]) hol[i][j] = 1;
			//cout << hol[i][j];
		}
		//cout << endl;
	}


	CumulativeSum2D<int> s(va), h(hol), v(var);
	//v.output();
	//h.output();

	rep(i,q){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		//show(s.sum(a,b,c - a + 1,d - b + 1))
		//show(h.sum(a,b,c - a + 1,d - b))
		//show(v.sum(a,b,c - a,d - b + 1))
		cout << s.sum(a,b,c - a + 1,d - b + 1) -
			h.sum(a,b,c - a + 1,d - b) -
			v.sum(a,b,c - a,d - b + 1) << endl;
	}
}
