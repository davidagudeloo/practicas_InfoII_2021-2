#include <iostream>
#include <cstdlib> //para el problema 2
#include <time.h>  //para asegurar que se tenga un valor aleatorio en el problema 2

using namespace std;


//funciones
int longitudCadenaChar(char* cadena);
int cadenaAInt(char* cadena);
int longitudInt(int numero);
void intACadena(int numero, char* cadena);
void eliminarCharsRepetidos(char* cadena);
int romanoAArabigo(char* romano);
bool esMagico(char* matriz, int numElementos);

int main()
{
    cout<<"ingrese el numero de problema"<<endl;
    int opcion;
    cin>>opcion;
    switch (opcion) {
    case 1:{
        cout<<"Problema 1. Se necesita un programa que permita determinar la minima combinacion de billetes y monedas para una cantidad de dinero determinada. Los billetes en circulacion son de $50.000, $20.000, $10.000, $5.000, $2.000 y $1.000, y las monedas son de $500, $200, $100 y $50. Hacer un programa que entregue el numero de billetes y monedas de cada denominacion para completar la cantidad deseada. Si por medio de los billetes y monedas disponibles no se puede lograr la cantidad deseada, el sistema debera decir lo que resta para lograrla. Use arreglos y ciclos para realizar el programa."<<endl;
        int dinero;
        cout<<"ingrese la cantidad de dinero:"<<endl;
        cin>>dinero;
        int billetesyMonedasCirculando[]={50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
        for(int i=0;i<10;i++){
            cout<<billetesyMonedasCirculando[i]<<" :"<<dinero/billetesyMonedasCirculando[i]<<endl;
            dinero%=billetesyMonedasCirculando[i];
        }
        cout<<"faltante: "<<dinero<<endl;
        break;
    }
    case 2:{
        cout<<"Problema 2. Elabore un programa que genere un arreglo de 200 letras mayusculas aleatorias, imprima este arreglo y luego imprima cuantas veces se repite cada letra en el arreglo."<<endl;
        char letrasMayusculas[200];
        int numLetrasRepetidas=0;
        srand(time(NULL)); //inicializo la semilla aleatoria
        for(int i=0;i<200;i++){
            letrasMayusculas[i]=rand()%26+65; //num aleatorio entre 65 y 95
            cout<<letrasMayusculas[i];
        }
        cout<<endl;
        for(char i=65;i<=90;i++){
            cout<<i<<": ";
            for(int j=0;j<200;j++){
                if(letrasMayusculas[j]==i){
                    numLetrasRepetidas++;
                }
            }
            cout<<numLetrasRepetidas<<endl;
            numLetrasRepetidas=0;
        }
        break;
    }
    case 4:{
        cout<<"Problema 4. Haga una funcion que reciba una cadena de caracteres numericos, la convierta a un numero entero y retorne dicho numero. Escriba un programa de prueba."<<endl;
        int numero=0;
        char cadena[]="123";//CADENA DE ENTRADA (Modificable)
        numero=cadenaAInt(cadena);
        cout<<"numero: "<<numero<<endl;
        break;
    }
    case 5:{
        cout<<"Problema 5. Haga una funcion que reciba un numero entero (int) y lo convierta a cadena de caracteres. Use parametros por referencia para retornar la cadena."<<endl;
        int numero=123;//CADENA DE ENTRADA (Modificable)
        char cadena[]="    ";
        intACadena(numero, cadena);
        cout<<"cadena: "<<cadena<<endl;
        break;
    }
    case 7:{
        cout<<"Problema 7. Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos."<<endl;
        char cadenaOriginal[]="bananas";//CADENA DE ENTRADA (Modificable)
        eliminarCharsRepetidos(cadenaOriginal);
        break;
    }
    case 10:{
        cout<<"Problema 10. Escribir un programa que permita convertir un numero en el sistema romano al sistema arabigo usado actualmente"<<endl;
        char numRomano[]="CLXXIV";//CADENA DE ENTRADA (Modificable)
        int numero=0;
        numero=romanoAArabigo(numRomano);
        cout<<"numero: "<<numero<<endl;
        break;
    }
    case 12:{
        cout<<"Problema 12. Un cuadrado magico es una matriz de numeros enteros sin repetir, en la que la suma de los numeros en cada columna, cada fila y cada diagonal principal tienen como resultado la misma constante. Escriba un programa que permita al usuario ingresar una matriz cuadrada, imprima la matriz y verifique si la matriz es un cuadrado magico."<<endl;
        int matriz[]={4, 9, 2, 3, 5, 7, 8, 1, 6};//CADENA DE ENTRADA (Modificable)

        break;
    }
    }
    return 0;
}



//declaracion de funciones:--------------------------------------------------
int longitudCadenaChar(char* cadena){
    int longitud=0;
    for(;cadena[longitud]!='\0';longitud++){
    }
    return longitud+1;//le sumo el \0
}
int cadenaAInt(char* cadena){
    int numero=0;
    for(int i=longitudCadenaChar(cadena)-2, j=1;i>=0;i--, j*=10){//ola: longitud=4, posición a=2, hay que restar 2
        numero=numero+((int)cadena[i]-48)*j;
    }
    return numero;
}
int longitudInt(int numero){
    int longitud=0;
    for(;numero>0;longitud++){
        numero/=10;
    }
    return longitud;
}
void intACadena(int numero, char* cadena){
    for(int i=longitudInt(numero)-1;i>=0;i--){
        cadena[i]=(char)(numero%10+48);
        numero/=10;
    }
}
void eliminarCharsRepetidos(char* cadena){
    cout<<"Original: "<<cadena<<" Sin repetidos: ";
    for(int i=0;i<longitudCadenaChar(cadena)-1;i++){
        if(cadena[i]!=' '){
            cout<<cadena[i];
        }
        char letra=cadena[i];
        for(int j=i;j<longitudCadenaChar(cadena)-1;j++){
            if(letra==(char)cadena[j]){
                cadena[j]=' ';
            }
        }
    }
    cout<<endl<<cadena<<endl;
}
int romanoAArabigo(char* romano){
    int numArabigo=0;
    int cantidadLetras=longitudCadenaChar(romano)-1;
    int numeros[cantidadLetras];
    for(int i=0;romano[i]!='\0';i++){
        if(romano[i]=='M'){
            numeros[i]=1000;
        }
        else if(romano[i]=='D'){
            numeros[i]=500;
        }
        else if(romano[i]=='C'){
            numeros[i]=100;
        }
        else if(romano[i]=='L'){
            numeros[i]=50;
        }
        else if(romano[i]=='X'){
            numeros[i]=10;
        }
        else if(romano[i]=='V'){
            numeros[i]=5;
        }
        else if(romano[i]=='I'){
            numeros[i]=1;
        }
    }
    for(int i=0;i<cantidadLetras-1;i++){
        if(numeros[i]>=numeros[i+1]){
            numArabigo+=numeros[i];
        }
        else{
            numArabigo=numArabigo-numeros[i];
        }
    }
    numArabigo+=numeros[cantidadLetras-1];
    return numArabigo;
}
bool esMagico(char* matriz, int numElementos){
    bool magico=true;
    if(magico==true){
        for(int i=0;i<numElementos;i++){

        }
    }
    if(magico==true){

    }
    if(magico==true){

    }
    return magico;
}
