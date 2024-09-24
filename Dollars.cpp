#include <bits/stdc++.h>
using namespace std;
//Inicializa todos los elementos en 0 menos el primero que sera con 1
long long dp[30003] = {1};
//Cortes que da el problema (11 cortes)
int cortes[] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
int main(){
    for(int i = 10; i >= 0; i--){ //Vemos todos los cortes
        for(int j = cortes[i]; j <= 30000; j = j + 5){
            //La cantidad de formas de devolver una cantidad = j sera igual a la cantidad que
            //tenia mas la cantidad de formas de devolver j menos el corte de esta iteracion.
            dp[j] = dp[j] + dp[j - cortes[i]];
        }
    }
    double monto;
    while(cin >> monto && monto != 0){
        int aux = monto * 100; //Convertirlo en los cortes con lo que estoy trabajando
        if(aux % 5 == 4){
            aux++;
        }
        cout.width(17); //Ancho total de la linea que imprimire
        cout << fixed << setprecision(2) << setw(6) << monto << setw(17) << dp[aux] << endl;
        //fixed -> Formato de salida del punto flotante
        //setprecision(2) -> 2 decimales para flotantes
        //setw(6) -> 6 espacios contando "monto", si monto es de tamaño 6 no pasa nade, en otro caso llena
        //           de espacios en blanco
    }
    return 0;
}