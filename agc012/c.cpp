#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

/* 黒が勝つ＋黒が一つ多い
 * 白が勝つ＋黒と白の数は同じ
 *
 * 白が一つ以上多い
 * 一列に10個以上同じ色が並んでいる
 * 5個以上並んでいる箇所が2箇所以上ある
 *
 * 正常な条件は
 *５個以上の並びが0or1で、一列には10個以上同じ色が並んでいなくて、
 *黒が勝つときは黒が一つ多くて、白が勝つときは1:1になっている
 *勝敗が決まっていないときは、黒が0ro1個多い
 */

const int dy[16] = { 0, 1, 1,-1, 1,-1, 0,-2, 0, 2};
const int dx[16] = { 1, 0, 1, 1,-1,-1, 2, 0,-2, 0};

int bfs(int x, int y, int d, int cnt, char m[20][20], char ox){
    if(m[y][x] == ox){
        m[y][x] = '.';
        return bfs(x + dx[d], y + dy[d], d, cnt + 1, m, ox);
    }
    return cnt;
}

pair<int, int> solve(char m[20][20], char ox){
    int row = 0, longest = 0;
    rep(k,3){
        char cp[20][20];
        rep(i,19) rep(j,19) cp[i][j] = m[i][j];
        rep(i,19){
            rep(j,19){
                if(m[i][j] == 'o'){
                    int tmp = bfs(j,i,k,0,cp,ox);
                    if(tmp >= 5) row++;
                    longest = max(longest, tmp);
                }
            }
        }
    }
    return make_pair(row, longest);
}

int main(){
    char m[20][20];
    int white = 0, black = 0;
    rep(i,19) rep(j,19){
        cin >> m[i][j];
        if(m[i][j] == 'o') black++;
        else if(m[i][j] == 'x') white++;
    }

    pair<int, int> b = solve(m, 'o');
    pair<int, int> w = solve(m, 'x');

    bool f = false;
    if(b.first + w.first == 1 && max(b.second, w.second) < 10 ){ //5つ以上並んでいる部分が一つ、かつ一列が10以下
        if(b.first == 1 && black == white + 1) f = true;
        else if(w.first == 1 && black == white) f = true;
    }else if(b.first + w.first == 0){ //並んでいる部分がない
        if(black - white == 1 || black - white == 0) f = true;
    }

    auto YesOrNo = [](bool f) { cout << (f ? "YES" : "NO") << endl; };
    YesOrNo(f);
}
