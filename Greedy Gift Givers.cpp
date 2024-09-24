#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    bool bandera = false;
    while(cin >> n){
        if(bandera == true){
            cout << endl;
        }
        bandera = true;
        map<string, int> mapa;
        int i, j, gasto, cantP;
        string nombres[10], pRegalo, pAct;
        //Leemos nombres e inicializamos el mapa
        for(i = 0; i < n; i++){
            cin >> nombres[i];
            mapa[nombres[i]] = 0;
        }
        //Leemos por cada persona gasto y a quienes
        for(i = 0; i < n; i++){
            cin >> pAct >> gasto >> cantP;
            if(cantP != 0){
                //No debo contar el residuo de un gasto, tiene que ser exacta la division
                //gasto y cant de personas, lo sobrante no se toma en cuenta
                mapa[pAct] -= gasto - (gasto % cantP);
            }
            //Leo cada persona q regale y le aumento la parte que gaste en el
            for(j = 0; j < cantP; j++){
                cin >> pRegalo;
                mapa[pRegalo] += gasto / cantP;
            }
        }
        for(i = 0; i < n; i++){
            cout << nombres[i] << " " << mapa[nombres[i]] << endl;
        }
    }
    return 0;
}