#include <bits/stdc++.h>

using namespace std;

vector <long long> v;

string comp(string str1, string str2, long long tipo){
    if(tipo == -1){
        return str2;
    }
    if(str1.size() > str2.size()){
        swap(str1, str2);
    }
    if(str1.size() == str2.size()){
        if(str1 == str2){
            return str1;
        }
        int limite = str1.size();
        for(int i = 0; i < limite; i++){
            if(str1[i] != str2[i]){
                if(str1[i] > str2[i]){
                    return str1;
                }else{
                    return str2;
                }
            }
        }
    }
    return str2;
}

string mult(string str, long long valor){
    if(valor < 0){
        valor = valor * -1;
    }
    reverse(str.begin(), str.end());
    int carry = 0;
    int limite = str.size();
    for(int i = 0; i < limite; i++){
        carry += (str[i] - 48) * valor;
        str[i] = (carry % 10 + 48);
        carry /= 10;
    }
    while(carry){
        str += (carry % 10 + 48);
        carry /=  10;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main(){
    long long num;
    while(cin >> num){
        long long max1 = -999999;
        max1 = max(num, max1);
        v.push_back(num);
        while(cin >> num && num != -999999){
            v.push_back(num);
            max1 = max(num, max1);
        }
        string rP = "1";
        string r = "";
        int limite = v.size();
        for(int j = 0; j < limite; j++){
            rP = "1";
            long long tipo = 1;
            for(int i = j; i < limite; i++){
                if(v[i] == 0){
                    rP = "1";
                    tipo = 1;
                }else{
                    if(v[i] < 0){
                        tipo = tipo * -1;
                    }
                    rP = mult(rP, v[i]);
                    r = comp(rP, r, tipo);
                }
            }
        }
        v.clear();
        if(max1 <= 0){
            cout << max1 << endl;
        }else{
            cout << r << endl;
        }
    }
}