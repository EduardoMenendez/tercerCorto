#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

/*
    La funcion para calcular el salario devuelve un vector para no hacer multiples funciones para calcular cada cosa
    el vector tiene el orden de
    salario[0] => salario total
    salario[1] => impuestos
    salario[2] => salario real
*/
vector<double> calcularSalario(int horasOrdinarias, int horasExtra){
    vector<double> salario;
    double total, real, impuestos;

    total = (horasOrdinarias*1.75);
    total += (horasExtra*2.50);
    salario.push_back(total);

    //Condicion para definir si hay que agregar el impuesto sobre la renta
    if(total > 500){
        impuestos = (total*0.04)+(total*0.0625)+(total*0.1);
    }else{
        impuestos = (total*0.04)+(total*0.0625);
    }
    salario.push_back(impuestos);
    real = total-impuestos;
    salario.push_back(real);
    return salario;
}


int main(){
    //Declarar variables
    int cantidad;
    string resultados = "Los salarios son: \n \n";

    
    cout << "Programa para calcular salarios" << endl;
    cout << "--------------------------------------------\n" << endl;

    cout << "Ingrese la cantidad de salarios que desea calcular" << endl;
    cin >> cantidad;

    //condicion para definir si la cantidad ingresada es valida
    if(cantidad > 0){

        string mostrar;
        
        for(size_t i = 0; i < cantidad; i++){
            //Variables para calcular los salarios
            int horasOrdinarias, horasExtra;


            cout << "Ingrese la cantidad de horas normales trabajadas por el empleado # " << (i+1) << endl;
            cin >> horasOrdinarias;
            cout << "Ingrese la cantidad de horas extra trabajadas por el empleado # " << (i+1) << endl;
            cin >> horasExtra;

            //Conicional para validar las horas ingresadas
            if(horasExtra > 0 && horasOrdinarias > 0){
                vector<double> salario = calcularSalario(horasOrdinarias, horasExtra);
                string respuesta = " El salario del empleado #"+to_string(i+1)+" es: \n  Total:         $"+to_string(salario[0])+
                "\n  Impuestos:     $"+ to_string(salario[1])+"\n  Real:          $"+to_string(salario[2])+"\n\n";
                cout << respuesta;
                resultados += respuesta;
                system("PAUSE()");
                system("CLS()");
            }else{
                cout << "Los valores ingresados no son validos" << endl;
                cantidad = 0;
                break;
            }
        }

        if(cantidad > 1){
            cout << "Desea mostrar una lista con todos los empleados? Y / N"<< endl;
            cin >> mostrar;
            if(mostrar == "Y" || mostrar == "y"){
                cout << resultados;
            }
        }
    }else{
        cout << "Ingrese una cantidad validad" << endl;
    }

}