//Programa para detectar números pares e impares.
#include <iostream>

using namespace std;

bool par(int);
bool impar(int);

bool par(int n){
    if(!n) return true;
    else return impar(n-1);
}

bool impar(int n){
    if(!n) return false;
    else return par(n-1);
}

int main(){
    int n;
    cin >> n;

    if(par(n)) cout << "Es par" <<endl;
    else cout << "Es impar" << endl;

    return 0;
}
