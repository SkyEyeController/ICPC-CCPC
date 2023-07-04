#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
using ll = long long;
const int N = 1e6 + 10;

int a[N];
int b[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i ++) a[i] += i + 1e5 - 1;

    int cnt = 0;
    while(a[n]){
        b[++cnt] = a[n] % 10;
        a[n] /= 10;
    }
    if(a[n])
        b[++cnt] = a[n];

    cout << b[6] << b[6] << b[5] << b[4] << b[3] << b[3] << b[2]<< b[1] << b[2];
    system("pause");
    return 0;
}
