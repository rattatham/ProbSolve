#include <bits/stdc++.h>

using namespace std;

vector<pair<long long,long long>> mask;
vector<pair<long long,long long>> quarter;
int res[5];

int main(void){
    long long N;
    long long X;
    cin >> N;
    for(int i=0;i<4*N;i++){
        cin >> X;
        mask.push_back(make_pair(X,i+1));
    }
    long long tmp=1;
    /*for(int i=0;i<4*N;i++){
        cout << mask[i].first << " " << mask[i].second << endl;
    }*/
    /*cout << mask.begin()+N << " " << mask.begin()+2*N-1 << endl;
    cout << mask.begin()+2*N << " " << mask.begin()+3*N-1 << endl;
    cout << mask.begin()+3*N << " " << mask.begin()+4*N-1 << endl;*/
    //cout << endl;
    sort(mask.begin(),mask.begin()+N);
    sort(mask.begin()+(N),mask.begin()+(2*N));
    sort(mask.begin()+(2*N),mask.begin()+(3*N));
    sort(mask.begin()+(3*N),mask.begin()+(4*N));
    /*for(int i=0;i<4*N;i++){
        cout << mask[i].first << " " << mask[i].second << endl;
    }*/
    int wina,winb;
    int indexa,indexb;
    //cout << mask[N-1].first << mask[2*N-1].first << mask[3*N-1].first << mask[4*N-1].first << endl;
    if(mask[N-1].first>=mask[2*N-1].first){
        wina=mask[N-1].first;
        indexa=mask[N-1].second;
        res[2]=mask[2*N-1].second;
    }
    else{
        wina=mask[2*N-1].first;
        indexa=mask[2*N-1].second;
        res[2]=mask[N-1].second;
    }
    if(mask[3*N-1].first>=mask[4*N-1].first){
        winb=mask[3*N-1].first;
        indexb=mask[3*N-1].second;
        res[3]=mask[4*N-1].second;
    }
    else{
        winb=mask[4*N-1].first;
        indexb=mask[4*N-1].second;
        res[3]=mask[3*N-1].second;
    }
    if(wina>winb){
        res[0]=indexa;
        res[1]=indexb;
    }
    else{
        res[0]=indexb;
        res[1]=indexa;
    }
    //cout << wina << " " << winb << endl;
    for(int i=0;i<4;i++){
        cout << res[i] << " ";
    }
    return 0;
}