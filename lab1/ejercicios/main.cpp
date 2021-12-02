//librerias:
#include <iostream>

using namespace std;

//funciones:
float Potencia(float base, int exponente);

int main()
{
    int opcion;

    do{
        cout<<"\n\nIngrese:\n-0 para salir\n-el numero del ejercicio que desea ejecutar"<<endl;
        cin>>opcion;
        cout<<"\n\n"<<endl;
        switch (opcion) {

        case 1:{
            cout<<"Ejercicio 1. Escriba un programa que pida dos numeros A y B e imprima en pantalla el residuo de la division A/B."<<endl;
            int numeroA, numeroB;
            cout<<"ingrese un numero:"<<endl;
            cin>>numeroA;
            cout<<"ingrese el segundo numero:"<<endl;
            cin>>numeroB;
            cout<<"El residuo de la division "<<numeroA<<"/"<<numeroB<<" es: "<<numeroA%numeroB<<endl;
            break;
        }

        case 2:{
            cout<<"Ejercicio 2. Escriba un programa que pida un numero N e imprima en pantalla si es par o impar."<<endl;
            int num;
            cout<<"ingrese un numero"<<endl;
            cin>>num;
            if(num%2==0){
                cout<<num<<" es par"<<endl;
            }
            else{
                cout<<num<<" es impar"<<endl;
            }
            break;
        }
        case 3:{
            cout<<"Ejercicio 3. Escriba un programa que pida dos numeros A y B e imprima en pantalla el mayor."<<endl;
            float numeroA, numeroB;
            cout<<"ingrese un numero:"<<endl;
            cin>>numeroA;
            cout<<"ingrese el segundo numero:"<<endl;
            cin>>numeroB;
            if(numeroA>numeroB){
                cout<<"El mayor es "<<numeroA<<endl;
            }
            else if(numeroA<numeroB){
                cout<<"El mayor es "<<numeroB<<endl;
            }
            else{
                cout<<"los numeros son iguales"<<endl;
            }
            break;
        }
        case 4:{
            cout<<"Ejercicio 4. Escriba un programa que pida dos numeros A y B e imprima en pantalla el menor."<<endl;
            float numeroA, numeroB;
            cout<<"ingrese un numero:"<<endl;
            cin>>numeroA;
            cout<<"ingrese el segundo numero:"<<endl;
            cin>>numeroB;
            if(numeroA>numeroB){
                cout<<"El menor es "<<numeroB<<endl;
            }
            else if(numeroA<numeroB){
                cout<<"El menor es "<<numeroA<<endl;
            }
            else{
                cout<<"los numeros son iguales"<<endl;
            }
            break;
        }
        case 5:{
            cout<<"Ejercicio 5. Escriba un programa que pida dos numeros A y B e imprima en pantalla la division A/B con redondeo."<<endl;
            float numeroA, numeroB;
            int resultado;
            cout<<"ingrese un numero:"<<endl;
            cin>>numeroA;
            cout<<"ingrese el segundo numero:"<<endl;
            cin>>numeroB;
            resultado=numeroA/numeroB;
            if(numeroA/numeroB-resultado>=0.5){
                resultado++;
            }
            cout<<numeroA<<"/"<<numeroB<<"="<<resultado<<endl;
            break;
        }
        case 6:{
            cout<<"Ejercicio 6. Escriba un programa que pida dos numeros A y B e imprima en pantalla la potencia A^B, sin hacer uso de librerias matematicas."<<endl;
            float numeroA, resultado;
            int numeroB;
            cout<<"ingrese un numero:"<<endl;
            cin>>numeroA;
            cout<<"ingrese el segundo numero:"<<endl;
            cin>>numeroB;
            resultado=Potencia(numeroA, numeroB);
            cout<<numeroA<<"^"<<numeroB<<"="<<resultado<<endl;
            break;
        }
        case 7:{
            cout<<"Ejercicio 7. Escriba un programa que pida un numero N e imprima en pantalla la suma de todos los numeros entre 0 y N (incluyendose el mismo)."<<endl;
            int num, resultado=0;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            for(int i=0;i<=num;i++){
                resultado+=i;
            }
            cout<<"La sumatoria desde 0 hasta "<<num<<" es: "<<resultado<<endl;
            break;
        }
        case 8:{
            cout<<"Ejercicio 8. Escriba un programa que pida un numero N e imprima en pantalla su factorial."<<endl;
            int num, resultado=1;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            for(int i=1;i<=num;i++){
                resultado*=i;
            }
            cout<<num<<"!="<<resultado<<endl;
            break;
        }
        case 9:{
            cout<<"Ejercicio 9. Escriba un programa que pida un numero N e imprima el perimetro y area de un circulo con radio N. Nota: use 3.1416 como una aproximacion de pi."<<endl;

            float pi=3.1416, radio, perimetro, area;
            cout<<"ingrese el radio:"<<endl;
            cin>>radio;
            perimetro=2*pi*radio;
            area=pi*radio*radio;
            cout<<"Perimetro: "<<perimetro<<endl;
            cout<<"Area: "<<area<<endl;
            break;
        }
        case 10:{
            cout<<"Ejercicio 10. Escriba un programa que pida un numero N e imprima en pantalla todos los multiplos de dicho numero entre 1 y 100."<<endl;
            int num;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            cout<<"Multiplos de \""<<num<<"\" menores que 100:"<<endl;
            for(int i=1;i<101;i++){
                if(i%num==0){
                    cout<<i<<endl;
                }
            }
            break;
        }
        case 11:{
            cout<<"Ejercicio 11. Escriba un programa que pida un numero N e imprima en pantalla su tabla de multiplicar hasta 10xN."<<endl;
            float num;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            for(int i=1;i<11;i++){
                cout<<i<<"x"<<num<<"="<<num*i<<endl;
            }
            break;
        }
        case 12:{
            cout<<"Ejercicio 12. Escriba un programa que pida un numero N e imprima todas las potencias desde N1 hasta N5."<<endl;
            float num;
            cout<<"ingrese un numero"<<endl;
            cin>>num;
            for(int i=1;i<6;i++){
                cout<<num<<"^"<<i<<"="<<Potencia(num, i)<<endl;
            }
            break;
        }
        case 13:{
            cout<<"Ejercicio 13. Escriba un programa que pida un numero N e imprima todos los divisores de N."<<endl;
            int num;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            cout<<"Los divisores de "<<num<<"\" son:"<<endl;
            for(int i=1;i<=num;i++){
                if(num%i==0){
                    cout<<i<<endl;
                }
            }
            break;
        }
        case 14:{
            cout<<"Ejercicio 14. Escriba un programa que imprima dos columnas paralelas, una con los numeros del 1 al 50 y otra con los numeros del 50 al 1."<<endl;
            for(int i=1;i<=50;i++){
                cout<<i<<"   "<<51-i<<endl;
            }
            break;
        }
        case 15:{
            cout<<"Ejercicio 15. Escriba un programa que pida constantemente números hasta que se ingrese el numero cero e imprima en pantalla la suma de todos los numeros ingresados"<<endl;
            float num, total=0;
            do{
                cout<<"ingrese un numero:"<<endl;
                cin>>num;
                total+=num;
            }while(num!=0);
            cout<<"El resultado de la sumatoria es: "<<total<<endl;
            break;
        }
        case 16:{
            cout<<"Ejercicio 16. Escriba un programa que pida constantemente numeros hasta que se ingrese el numero cero e imprima en pantalla el promedio de los numeros ingresados (excluyendo el cero)."<<endl;
            float num, total=0;
            int cantidadDeNumeros=-1;
            do{
                cantidadDeNumeros++;
                cout<<"ingrese un numero:"<<endl;
                cin>>num;
                total+=num;
            }while(num!=0);
            cout<<"El promedio es: "<<total/cantidadDeNumeros<<endl;
            break;
        }
        case 17:{
            cout<<"Ejercicio 17. Escriba un programa que pida constantemente numeros hasta que se ingrese el numero cero e imprima en pantalla el mayor de todos los numeros ingresados."<<endl;
            float num, mayor;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            mayor=num;
            while(num!=0){
                cout<<"ingrese un numero:"<<endl;
                cin>>num;
                if(num>mayor){
                    mayor=num;
                }
            }
            cout<<"El numero mayor fue: "<<mayor<<endl;
            break;
        }
        case 18:{
            cout<<"Ejercicio 18. Escriba un programa que pida un numero N e imprima si es o no un cuadrado perfecto."<<endl;

            break;
        }

        default:{
            if(opcion!=0){
                cout<<"Ese numero de ejercicio no existe"<<endl;
            }
        }
        }
    }while(opcion!=0);

    return 0;
}
float Potencia(float base, int exponente){
    float resultado=1;
    for(int i=0;i<exponente;i++){
        resultado*=base;
    }
    return resultado;
}

