#include <iostream>

using namespace std;

//La funcion evalua si es bisiesto o no
string definirSiEsBisiesto(int year){
    if(year % 400 == 0){
        return "El anio es bisiesto";
    }else if(year % 4 == 0 && year%100 != 0){
        return "El anio es bisiesto";
    }else{
        return "El anio no es bisiesto";
    }
}


int main(){
    int year;

    cout << "Programa para definir si un anio es bisiesto o no" << endl;
    cout << "-------------------------------------------------------------\n" << endl;

    cout << "Por favor ingrese un anio" << endl;
    cin >> year;

    if(year > 0){
        cout << definirSiEsBisiesto(year) << endl;
        system("PAUSE()");
    }else{
        cout << "El valor que ingreso no es valido" << endl;
        system("PAUSE()");
    }

}