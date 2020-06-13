#include <iostream>
#include <time.h>  

using namespace std;

/*Funcion que define si el numero es el correcto o si es mayor o menor
    esta puede devolver tres numeros
    1 = el numero es correcto
    2 = el numero es mayor
    3 = el numero es menor
*/
int evaluarNumero(int intento, int numeroPorAdivinar){
    if(intento == numeroPorAdivinar){
        return 1;
    }else if(intento > numeroPorAdivinar){
        return 2;
    }else{
        return 3;
    }
}



int main(){

    srand (time(NULL));
    int numeroGanador = rand() % 100 + 1;
    bool gano = false;

    cout << "Juego del numero magico" << endl;
    cout << "Este juego consiste en que adivines un numero en el rango del 1 al 100" << endl;
    cout << "Tienes 5 intentos para lograrlo, suerte!" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for(size_t i = 0; i < 5; i++){
        int num;
        cout << "\nIntento #" << (i+1) << endl;
        cout << "Ingresa un numero" << endl;
        cin >> num;

        switch (evaluarNumero(num, numeroGanador))
        {
            case 1:
                cout << "FELICIDADES GANASTE!!!!";
                gano = true;
                break;
            case 2:
                cout << "El numero que ingresaste es mayor \n";
                break;
            case 3:
                cout << "El numero que ingresaste es menor \n";
                break;
        }

        if(i < 4){
            if(gano){
                break;
            }else{
                string seguir;
                cout << "Deseas seguir jugando? Y/N" << endl;
                cin >> seguir;
                if(!(seguir == "Y" || seguir == "y")){
                    break;
                }
            }
        }

    }

    if(!gano){
        cout << "Sigue intentandolo, vuelve a jugar!" << endl;
        cout << "El numero era: "<< numeroGanador << endl;
        system("PAUSE()");
    }
}