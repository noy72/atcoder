#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

int main(){
    int n;
    cin >> n;

    int cnt[3] = {0};
    rep(i,n){
        int a;
        cin >> a;

        int d = 0;
        while(a % 2 == 0){
            a /= 2;
            d++;
        }
        if(d >= 2) d = 2;
        cnt[d]++;
    }
    //rep(i,3){ show(cnt[i]) }


    bool f = true;
    if(cnt[1] == 1 && cnt[2] == 0) f = false;
    else if(cnt[1] >= 1 && cnt[0] >= 1 && cnt[2] == 0) f = false;
    else if(cnt[1] == 0 && cnt[0] > cnt[2] + 1) f = false;
    else if(cnt[1] >= 1 && cnt[0] > cnt[2]) f = false;

    auto YesOrNo = [](bool f) { cout << (f ? "Yes" : "No") << endl; };
    YesOrNo(f);
}
