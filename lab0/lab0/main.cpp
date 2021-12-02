#include <iostream>

using namespace std;

int main()
{
    cout<<"problema1"<<endl<<endl;

    //construyo la matriz de 7x13
    for(int i=0;i<7;i++){
        for(int j=0;j<13;j++){
            //hago el hueco
            if(j<=i||j>=12-i){
                //letras de la A a la G
                if(j<7){
                    cout<<char(65+j);
                }
                //letras de la F a la A
                else{
                    cout<<char(65+12-j);
                }
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }


    cout<<endl<<endl;
    cout<<"problema2"<<endl<<endl;

    //construyo la matriz de 13x13
    for(int i=0;i<13;i++){
        for(int j=0;j<13;j++){
            //hago los huecos
            if( ( (j<=i || j>=12-i) && i<7) || ( (j<=12-i || j>=i) && i>=7) ){
                //letras de la A a la G
                if(j<7){
                    cout<<char(65+j);
                }
                //letras de la F a la A
                else{
                    cout<<char(65+12-j);
                }
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }


    cout<<endl<<endl;
    cout<<"problema3"<<endl<<endl;

    bool hayCero=false;
    int numero, total=0, digito, numElevado;
    cout<<"ingrese un numero:";
    cin>>numero;
    do{
        digito=numero%10;
        if(digito==0){
            hayCero=true;
        }
        numElevado=1;
        for(int i=0;i<digito;i++){
            numElevado*=digito;
        }
        numero/=10;
        total+=numElevado;
    }while(numero>0);
    if(hayCero){
        cout<<"no se puede elevar cero a la cero"<<endl;
    }
    else{
        cout<<total<<endl;
    }
}
