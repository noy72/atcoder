#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

class LineGraph{
	int hol_1, hol_2;	//傾きが変わる位置
	int high_1, high_2;	//傾きが変わった時のf(x)の値
	int t;				//現在時刻
	int x;				//縦軸の上限

	LineGraph(int x){	//最初はf(x) = a + t の単調増加なグラフ
		t = 0;
		this->x = x;
		hol_1 = 0;
		hol_2 = x;
		high_1 = 0;
		high_2 = x;
	}

	void translation(int nt, int slope){
	}

	void translation(int nt, int slope){
		assert(slope == 1 or slope == -1);
		high_1 += (nt - t) * slope;
		high_2 += (nt - t) * slope;
		t = nt;

		if(slope == 1){
			if(high_1 >= x){ //グラフが上側に張り付く
				hol_1 = nt;
				hol_2 = nt;
				high_1 = x;
				high_2 = x;
			}else{

			}
		}
	}
};

int main(){
	int x, k;
	cin >> x >> k;

	vector<int> r(k + 1, 0);
	rep(i,k){
		cin >> r[i];
	}

	vector<int> diff(k);
	rep(i,k){
		diff[i] = r[i + 1] - r[i];
	}

	int low = 0, high = x;
	vector<pair<int, int>> limit; // a > limit[i].first and a < limit[i + 1].first のとき、i回目の反転で砂がなくなる
	rep(i,k){
		if(i % 2){

		}else{
			int d = x - diff[i];
			if(high > d){
				limit.emplace_back(high, i);
			}
		}
	}

	int q;
	cin >> q;
	rep(i,q){
		int t, a;
		cin >> t >> a;
	}
}
