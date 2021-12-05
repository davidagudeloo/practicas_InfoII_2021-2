//librerias:
#include <iostream>
#include <cstdlib> //para el ejercicio 30
#include <time.h>  //para asegurar que se tenga un valor aleatorio en el ejercicio 30

using namespace std;

//funciones:
float Potencia(float base, int exponente);
bool esPrimo(int num);

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
            int num;
            bool esCuadrado=false;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            for(int i=0;i<num;i++){
                if(num==i*i){
                    esCuadrado=true;
                }
            }
            if(esCuadrado){
                cout<<num<<" es un cuadrado perfecto."<<endl;
            }
            else{
                cout<<num<<" NO es un cuadrado perfecto."<<endl;
            }
            break;
        }
        case 19:{
            cout<<"Ejercicio 19. Escriba un programa que pida un numero N e imprima si es o no un numero primo."<<endl;
            int num;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            if(esPrimo(num)){
                cout<<num<<" es un numero primo."<<endl;
            }
            else{
                cout<<num<<" NO es un numero primo."<<endl;
            }
            break;
        }
        case 20:{
            cout<<"Ejercicio 20. Escriba un programa que pida un numero N e imprima si es o no un palindromo (igual de derecha a izquierda que de izquierda a derecha)."<<endl;
            int num, numAlReves=0, copiaNum, digito;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            copiaNum=num;
            for(int i=1;copiaNum>0;i=10){
                numAlReves*=i;
                digito=copiaNum%10;
                copiaNum=copiaNum/10;
                numAlReves=(numAlReves+digito);
            }
            if(numAlReves==num){
                cout<<num<<" es un numero palindromo."<<endl;
            }
            else{
                cout<<num<<" NO es un numero palindromo."<<endl;
            }
            break;
        }
        case 21:{
            cout<<"Ejercicio 21. Escriba un programa que pida un caracter C, si es una letra la debe convertir de mayuscula a minuscula y viceversa e imprimirla."<<endl;
            char letra;
            cout<<"ingrese un caracter:"<<endl;
            cin>>letra;
            if(letra>=65 && letra<=90){
                cout<<"Letra convertida: "<<char(letra+32)<<endl;
            }
            else if(letra>=97 && letra<=122){
                cout<<"Letra convertida: "<<char(letra-32)<<endl;
            }
            else{
                cout<<"no ingreso una letra."<<endl;
            }
            break;
        }
        case 22:{
            cout<<"Ejercicio 22. Escriba un programa que pida una cantidad entera de segundos y la imprima en formato horas:minutos:segundos."<<endl;
            int num, horas, minutos;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            horas=num/3600;
            num%=3600;
            minutos=num/60;
            num%=60;
            cout<<horas<<":"<<minutos<<":"<<num<<endl;
            break;
        }
        case 23:{
            cout<<"Ejercicio 23. Escriba un programa que pida dos numeros A y B e imprima en pantalla el minimo comun multiplo entre los dos."<<endl;
            int numeroA, numeroB, temp, mcm=1;
            cout<<"ingrese un numero:"<<endl;
            cin>>numeroA;
            cout<<"ingrese el segundo numero"<<endl;
            cin>>numeroB;
            if(numeroB>numeroA){
                temp=numeroA;
                numeroA=numeroB;
                numeroB=temp;
            }
            cout<<"El MCM de "<<numeroA<<" y "<<numeroB<<" es: ";
            for(int i=1;i<=numeroA;i++){
                bool hayDivisores=true;
                if(esPrimo(i)){
                    while(hayDivisores){
                        if(numeroA%i==0 && numeroB%i==0){
                            numeroA/=i;
                            numeroB/=i;
                            mcm*=i;
                        }
                        else if(numeroA%i==0){
                            numeroA/=i;
                            mcm*=i;
                        }
                        else if(numeroB%i==0){
                            numeroB/=i;
                            mcm*=i;
                        }
                        else{
                            hayDivisores=false;
                        }
                    }
                }
            }
            cout<<mcm<<endl;
            break;
        }
        case 24:{
            cout<<"Ejercicio 24. Escriba un programa que pida una numero entero e imprima un cuadrado de dicho tamano, los bordes del cuadrado deben estar hechos con el caracter `+' y el interior debe estar vacio."<<endl;
            int num;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            for(int i=0;i<num;i++){
                for(int j=0;j<num;j++){
                    if(i==0 || i==num-1 || j==0 || j==num-1){
                        cout<<"+";
                    }
                    else{
                        cout<<" ";
                    }
                }
                cout<<endl;
            }
            break;
        }
        case 25:{
            cout<<"Ejercicio 25. Escriba un programa que pida un numero N e imprima en pantalla la cantidad de digitos de N."<<endl;
            int num, numDeDigitos=0;
            cout<<"ingrese un num:"<<endl;
            cin>>num;
            cout<<num<<" tiene ";
            while(num>0){
                num/=10;
                numDeDigitos++;
            }
            cout<<numDeDigitos<<" digitos "<<endl;
            break;
        }
        case 26:{
            cout<<"Ejercicio 26. Escriba un programa que pida tres numeros e imprima el tipo de triangulo (isosceles, equilatero, escaleno) que se formaria, si sus lados tienen la longitud definida por los numeros ingresados. Tenga en cuenta el caso en que los numeros ingresados no forman un triangulo."<<endl;
            float lado1, lado2, lado3;
            cout<<"ingrese un numero:"<<endl;
            cin>>lado1;
            cout<<"ingrese el segundo numero:"<<endl;
            cin>>lado2;
            cout<<"ingrese el tercer numero:"<<endl;
            cin>>lado3;
            if(lado1<=0 || lado2<=0 || lado3<=0 || lado1+lado2==lado3 || lado1+lado3==lado2 || lado3+lado2==lado1){
                cout<<"Las longitudes ingresadas no forman un triangulo."<<endl;
            }
            else{
                if(lado1==lado2 && lado1==lado3){
                    cout<<"Se forma un triangulo equilatero."<<endl;
                }
                else if(lado1==lado2 || lado1==lado3 || lado2==lado3){
                    cout<<"Se forma un triangulo isosceles."<<endl;
                }
                else{
                    cout<<"Se forma un triangulo escaleno."<<endl;
                }
            }
            break;
        }
        case 27:{
            cout<<"Ejercicio 27. Escriba un programa que actue como una calculadora con operaciones de suma, resta, multiplicacion y division, el usuario debe ingresar los operandos y la operacion a realizar."<<endl;
            float numeroA, numeroB;
            char operacion;
            cout<<"ingrese un numero:"<<endl;
            cin>>numeroA;
            cout<<"ingrese la operacion a realizar: +, -, *, /"<<endl;
            cin>>operacion;
            cout<<"ingrese el segundo numero:"<<endl;
            cin>>numeroB;
            if(operacion==42){
                cout<<numeroA<<operacion<<numeroB<<"="<<numeroA*numeroB<<endl;
            }
            else if(operacion==43){
                cout<<numeroA<<operacion<<numeroB<<"="<<numeroA+numeroB<<endl;
            }
            else if(operacion==45){
                cout<<numeroA<<operacion<<numeroB<<"="<<numeroA-numeroB<<endl;
            }
            else if(operacion==47){
                cout<<numeroA<<operacion<<numeroB<<"="<<numeroA/numeroB<<endl;
            }
            else{
                cout<<"la operacion '"<<operacion<<"' No es valida"<<endl;
            }
            break;
        }
        case 28:{
            cout<<"Escriba un programa que encuentre el valor aproximado de pi en base a la siguiente suma infinita: pi=4(1- 1/3 + 1/5 - 1/7 + ...)"<<endl;
            cout<<"El usuario debe ingresar el numero de elementos usados en la aproximacion."<<endl;
            int num;
            float aproximacion=0;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            for(int i=0, j=1;i<num;i++, j+=2){
                if(i%2==0){
                    aproximacion=aproximacion+1/float(j);
                }
                else{
                    aproximacion=aproximacion-1/float(j);
                }
            }
            cout<<"pi es aproximadamente: "<<4*aproximacion<<endl;
            break;
        }
        case 29:{
            cout<<"Ejercicio 29. Escriba un programa que adivine un numero A (entre 0 y 100) seleccionado por el usuario (el numero NO se ingresa al programa), el programa imprimira en pantalla un numero B y el usuario usara los simbolos `>', `<' y `=' para indicarle al programa si B es mayor, menor o igual que A. El programa imprimira un nuevo número B, con base en simbolo ingresado por el usuario, y repetira el proceso hasta acertar el numero seleccionado por usuario."<<endl;
            int numMayor=100, numMenor=0;
            char simbolo;
            do{
                cout<<"Su numero es el... "<<(numMayor+numMenor)/2<<endl;
                cin>>simbolo;
                if(simbolo==60){
                    numMayor=(numMayor+numMenor)/2;
                }
                else if(simbolo==62){
                    numMenor=(numMayor+numMenor)/2;
                }
                else if(simbolo!=61){
                    cout<<"el simbolo no es valido"<<endl;
                }
            }while(simbolo!='=');
            cout<<"ja! lo sabia :)"<<endl;
            break;
        }
        case 30:{
            cout<<"Ejercicio 30. Escriba un programa que genere un numero aleatorio A (entre 0 y 100) y le pida al usuario que lo adivine, el usuario ingresa un numero B y el programa le dira si B es mayor o menor que A, esto se repetira hasta que el usuario adivine el numero, en ese momento el programa le dira el numero de intentos que tardo el usuario en adivinar el numero."<<endl;
            cout<<"Nota: para generar el numero aleatorio use la funcion rand() de la libreria <cstdlib>, recuerde convertirlo al rango (0,100)."<<endl;
            srand(time(NULL)); //inicializo la semilla aleatoria
            int intentos=0, num, numSecreto = rand()%101; //num aleatorio entre 0 y 100
            do{
                cout<<"ingrese un numero:"<<endl;
                cin>>num;
                if(num>numSecreto){
                    cout<<"el numero secreto es menor que "<<num<<endl;
                }
                else if(num<numSecreto){
                    cout<<"el numero secreto es mayor que "<<num<<endl;
                }
                intentos++;
            }while(numSecreto!=num);
            cout<<"¡Correcto! el numero secreto era: "<<numSecreto<<endl;
            cout<<"el numero de intentos fue: "<<intentos<<endl;
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
bool esPrimo(int num){
    int divisores=0;
    for(int i=1;i<=num;i++){
        if(num%i==0){
            divisores++;
        }
    }
    if(divisores==2){
        return true;
    }
    else{
        return false;
    }
}


