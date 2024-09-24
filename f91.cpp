#include <bits/stdc++.h>

using namespace std;

int mCarty(int n){
    if(n >= 101){
        return n - 10;
    }
    return mCarty(mCarty(n + 11));
}

int main(){
    int n;

    while(cin >> n && n != 0){
        cout << "f91(" << n << ") = " << mCarty(n) << endl;
    }
    return 0;
}