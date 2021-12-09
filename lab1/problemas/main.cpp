#include <iostream>

using namespace std;

//funciones
int factorial(int num);
bool esPrimo(int num);
int terminosSemilla(int num);

int main()
{
    int opcion;

    do{
        cout<<"\n\nIngrese:\n-0 para salir\n-el numero del problema que desea ejecutar"<<endl;
        cin>>opcion;
        cout<<"\n\n"<<endl;
        switch (opcion) {

        case 2:{
            cout<<"Problema 2. Se necesita un programa que permita determinar la minima combinacion de billetes y monedas para una cantidad de dinero determinada. Los billetes en circulacion son de $50.000, $20.000, $10.000, $5.000, $2.000 y $1.000, y las monedas son de $500, $200, $100 y $50. Hacer un programa que entregue el numero de billetes y monedas de cada denominacion para completar la cantidad deseada. Si por medio de los billetes y monedas disponibles no se puede lograr la cantidad deseada, el sistema debera decir lo que resta para lograrla."<<endl;
            int b50, b20, b10, b5, b2, b1, m500, m200, m100, m50, dinero;
            cout<<"ingrese la cantidad de dinero:"<<endl;
            cin>>dinero;
            if(dinero<0){
                cout<<"no puede ingresar una cantidad negativa"<<endl;
            }
            else{
                b50=dinero/50000;
                dinero%=50000;
                b20=dinero/20000;
                dinero%=20000;
                b10=dinero/10000;
                dinero%=10000;
                b5=dinero/5000;
                dinero%=5000;
                b2=dinero/2000;
                dinero%=2000;
                b1=dinero/1000;
                dinero%=1000;
                m500=dinero/500;
                dinero%=500;
                m200=dinero/200;
                dinero%=200;
                m100=dinero/100;
                dinero%=100;
                m50=dinero/50;
                dinero%=50;
                cout<<"50000 : "<<b50<<endl<<"20000 : "<<b20<<endl<<"10000 : "<<b10<<endl;
                cout<<"5000 : "<<b5<<endl<<"2000 : "<<b2<<endl<<"1000 : "<<b1<<endl;
                cout<<"500 : "<<m500<<endl<<"200 : "<<m200<<endl<<"100 : "<<m100<<endl;
                cout<<"50 : "<<m50<<endl<<"Faltante: "<<dinero<<endl;
            }
            break;
        }
        case 3:{
            cout<<"Problema 3. Escriba un programa que debe leer un mes y un dia de dicho mes para luego decir si esa combinacion de mes y dia son validos. El caso mas especial es el 29 de febrero, en dicho caso imprimir: posiblemente ano bisiesto."<<endl;
            int mes, dia;
            bool valida=false, bisiesto=false;
            cout<<"ingrese el numero del mes:"<<endl;
            cin>>mes;
            cout<<"ingrese el numero del dia:"<<endl;
            cin>>dia;
            if(mes>12 || mes<1){
                cout<<mes<<" es un mes invalido."<<endl;
            }
            else{
                if(mes==2 && dia==29){
                    cout<<dia<<"/"<<mes<<" es valida en bisiesto."<<endl;
                    bisiesto=true;
                }
                else if(mes==2 && dia<=28){
                    valida=true;
                }
                else if(dia<=31 && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) ){
                    valida=true;
                }
                else if(dia<=30 && (mes==4 || mes==6 || mes==9 || mes==11) ){
                    valida=true;
                }
                if(valida && !bisiesto){
                    cout<<dia<<"/"<<mes<<" es una fecha valida."<<endl;
                }
                else if(!valida && !bisiesto){
                    cout<<dia<<"/"<<mes<<" es una fecha invalida."<<endl;
                }
            }
            break;
        }
        case 4:{
            cout<<"Problema 4. Escriba un programa para leer dos numeros enteros con el siguiente significado: el valor del primer numero representa una hora del dia en un reloj de 24 horas, de modo que 1245 representa las doce y cuarenta y cinco de la tarde. El segundo entero representa un tiempo de duracion de la misma manera, por lo que 345 representa tres horas y 45 minutos. El programa debe sumar esta duracion primer numero, y el resultado sera impreso en la misma notacion, en este caso 1630, que es el tiempo de 3 horas y 45 minutos despues de 12:45."<<endl;
            cout<<"Nota: el formato de salida debe ser: La hora es 1630."<<endl;
            cout<<"Otra nota: se debe imprimir un mensaje como el siguiente cuando uno de los datos ingresados en invalido: 1560 es un tiempo invalido."<<endl;
            int numeroA, numeroB, horas, minutos;
            cout<<"ingrese el primer numero:"<<endl;
            cin>>numeroA;
            cout<<"ingrese el segundo numero:"<<endl;
            cin>>numeroB;
            if(numeroA%100>=60 || numeroA/100>=24){
                cout<<numeroA<<" es un tiempo invalido."<<endl;
            }
            else if(numeroB%100>=60 || numeroB/100>=24){
                cout<<numeroB<<" es un tiempo invalido."<<endl;
            }
            else{
                minutos=(numeroA%100)+(numeroB%100);
                horas=(numeroA/100)+(numeroB/100);
                if(minutos>=60){
                    minutos-=60;
                    horas++;
                }
                if(horas>=24){
                    horas-=24;
                }
                cout<<"La hora es "<<horas<<":"<<minutos<<endl;
            }
            break;
        }
        case 6:{
            cout<<"Escriba un programa que encuentre el valor aproximado del numero de euler en base a la siguiente suma infinita: e = 1/0! + 1/1! + 1/2! + ... \nEl usuario debe ingresar el numero de elementos usados en la aproximacion."<<endl;
            int num;
            float sumatoria=0;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            for(int i=0;i<num;i++){
                sumatoria+=1/float(factorial(i));
            }
            cout<<"e es aproximadamente: "<<sumatoria<<endl;
            break;
        }
        case 9:{
            cout<<"Problema 9. Escriba un programa que pida un numero entero N e imprima el resultado de la suma de todos sus digitos elevados a si mismos."<<endl;
            int num, sumatoria=0, digito, productoria;
            bool tieneCero=false;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            do{
                digito=num%10;
                num/=10;
                if(digito==0){
                    tieneCero=true;
                }
                productoria=1;
                for(int i=0;i<digito;i++){
                    productoria*=digito;
                }
                sumatoria+=productoria;
            }while(num>0);
            if(tieneCero){
                cout<<"no es posible elevar 0 a la 0"<<endl;
            }
            else{
                cout<<"El resultado de la suma es: "<<sumatoria<<endl;
            }
            break;
        }
        case 10:{
            cout<<"Problema 10. Escriba un programa que reciba un numero n e imprima el enésimo numero primo."<<endl;
            int num, posicionPrimo=0, primoActual=1;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            while(num!=posicionPrimo){
                primoActual++;
                if(esPrimo(primoActual)){
                    posicionPrimo++;
                }
            }
            if(num<=0){
                cout<<"la posicion no es valida"<<endl;
            }
            else{
                cout<<"El primo numero "<<num<<" es: "<<primoActual<<endl;
            }
            break;
        }
        case 11:{
            cout<<"Problema 11. Escriba un programa que reciba un numero y calcule el minimo comun multiplo de todos los numeros enteros entre 1 y el numero ingresado."<<endl;
            int num, primo=2, mcm=1, temporal, divisoresMaximos, divisores;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            //recorrer cada uno de los primos hasta el numero ingresado
            while(num>=primo){
                if(esPrimo(primo)){
                    divisoresMaximos=0;
                    //recorrer todos los numeros para encontrar quien tiene mas divisores del primo
                    for(int i=1;i<=num;i++){
                        temporal=i;
                        divisores=0;
                        while(temporal%primo==0){
                            divisores++;
                            temporal/=primo;
                        }
                        if(divisores>divisoresMaximos){
                            divisoresMaximos=divisores;
                        }
                    }
                    for(int i=0;i<divisoresMaximos;i++){
                        mcm=mcm*primo;
                    }
                }
                primo++;
            }
            cout<<"El minimo comun multiplo es: "<<mcm<<endl;
            break;
        }
        case 13:{
            cout<<"Problema 13. Escriba un programa que reciba un numero y calcule la suma de todos los primos menores que el numero ingresado."<<endl;
            int num, sumatoriaPrimos=0, primoActual=2;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            while(primoActual<num){
                if(esPrimo(primoActual)){
                    sumatoriaPrimos+=primoActual;
                }
                primoActual++;
            }
            cout<<"El resultado de la suma es: "<<sumatoriaPrimos<<endl;
            break;
        }
        case 15:{
            cout<<"Problema 15. Empezando con el numero 1 y moviendose hacia la izquierda y en sentido horario se genera una espiral de numeros como la siguiente:"<<endl;
            int num, sumatoria=1, numeroASumar=1;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            if(num%2==0){
                cout<<"el numero no es valido"<<endl;
            }
            else{
                for(int i=2;i<num;i+=2){
                    for(int j=0;j<4;j++){
                        numeroASumar+=i;
                        sumatoria+=numeroASumar;
                    }
                }
                cout<<"En una espiral de "<<num<<"x"<<num<<", la suma es: "<<sumatoria<<endl;
            }

            //imprimir la espiral(?)-------------------------------------------------------
            cout<<"intento espiral de bonificacion:"<<endl;
            for(int i=0;i<num;i++){
                for(int j=0;j<num;j++){
                    cout<<num*num-num+1+j;
                }
                cout<<endl;
            }
            break;
        }
        //preguntar a la profe
        case 16:{
            cout<<"Problema 16. La serie de Collatz se conforma con la siguiente regla: sea n un elemento de la serie, si n es par, el siguiente elemento es n/2, y si n es impar, el siguiente elemento es 3n+1. Escriba un programa que reciba un numero k y calcule cual es el elemento inicial j (semilla), menor que k, que produce la serie mas larga y diga cuantos terminos m tiene la serie. Tip: la serie termina al llegar a un elemento cuyo valor sea 1."<<endl;
            int num, semillaMayor=1;
            cout<<"ingrese un numero:"<<endl;
            cin>>num;
            for(int i=num-1;i>0;i--){
                if(terminosSemilla(i)>terminosSemilla(semillaMayor)){
                    semillaMayor=i;
                }
            }
            cout<<"La serie mas larga es con la semilla: "<<semillaMayor<<" teniendo "<<terminosSemilla(semillaMayor)<<" terminos."<<endl;
            cout<<"para la semilla "<<semillaMayor<<": "<<num;
            while(semillaMayor!=1){
                if(semillaMayor%2==0){
                    semillaMayor/=2;
                    cout<<", "<<semillaMayor;
                }
                else{
                    semillaMayor=3*semillaMayor+1;
                    cout<<", "<<semillaMayor;
                }
            }
            cout<<"."<<endl;
            break;
        }

        default:{
            if(opcion!=0){
                cout<<"Ese numero de ejercicio no existe o no me toca jeje"<<endl;
            }
        }
        }
    }while(opcion!=0);

    return 0;
}

int factorial(int num){
    int facto=1;
    for(int i=1;i<=num;i++){
        facto*=i;
    }
    return facto;
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
int terminosSemilla(int num){
    int terminos=1;
    while(num!=1){
        if(num%2==0){
            num/=2;
        }
        else{
            num=3*num+1;
        }
        terminos++;
    }
    return terminos;
}

