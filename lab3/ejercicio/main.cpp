#include <iostream> // flujo de entrada y salida hacia la consola
#include <fstream> // flujo de entrada y salida hacia archivos
#include <string.h> // trabajar con strings
#include <stdlib.h> // libreria estandar. para el exit por ejemplo

using namespace std;

//funciones
string lectura(string name);
string archivoBinario(string cadena);
string dectobin(int n);
string metodoDos(string bin, int sem);
string encriptar2(string frac);
void escribir(string name, string escritura);
string decodificacionDos(string bin, int sem);
string decoDos(string frac);
string represetacion (string cadBin);
int bintodec(string bin);
int dos_exp (int exp);


int main()
{

    bool continuar = true;

    while (continuar){

        cout << endl;
        cout << "Ingrese el numero de operacion a realizar:" << endl;
        cout << "1.Codificar archivos" << endl;
        cout << "2.Decodificar archivos" << endl;
        cout << "O cualquier otro para salir" << endl;
        cout << endl;
        int opc_menu;
        cin >> opc_menu;

        // codificar archivos
        if(opc_menu == 1){

            cout << endl;

            //leo los nombres de los archivos y la semilla
            string name_entrada;
            cout << "Ingrese el nombre del archivo a codificar (no incluya .txt): ";
            cin >> name_entrada;

            string name_salida;
            cout << "Ingrese el nombre del archivo en el que se guarda la codificacion (no incluya .txt): ";
            cin >> name_salida;

            cout << "Ingrese la semilla de codificacion: ";
            int semilla;
            cin >> semilla;



            string texto_original = lectura(name_entrada+".txt");
            string texto_binario = archivoBinario(texto_original);

            string texto_cod = metodoDos(texto_binario,semilla);
            escribir(name_salida+".txt",texto_cod);

            cout << "Se ha completado la codificacion en: " << name_salida << ".txt" << endl;
            cout << endl;

        }

        // decodificar archivos
        else if (opc_menu == 2){
            //leo los nombres de los archivos y la semilla
            string name_entrada;
            cout << "Ingrese el nombre del archivo a decodificar (no incluya .txt): ";
            cin >> name_entrada;

            string name_salida;
            cout << "Ingrese el nombre del archivo en el que se guarda la decodificacion (no incluya .txt): ";
            cin >> name_salida;

            cout << "Ingrese la semilla de decodificacion: ";
            int semilla;
            cin >> semilla;



            string bin_codificado = lectura(name_entrada+".txt");
            string bin_deco = decodificacionDos(bin_codificado,semilla);
            string tex_deco = represetacion(bin_deco);
            escribir(name_salida+".txt",tex_deco);

            cout << "Se ha completado la decodificacion en: " << name_salida << ".txt" << endl;
            cout << endl;

        }

        // salir del programa
        else{
            continuar = false;
        }
    }


    return 0;
}

string lectura(string name){ // funcion que da lectura a un fichero y returna el string leido
    ifstream archivo; // tipo de dato que me permite leer un archivo

    string texto;
    string linea;

    archivo.open(name,ios::in); // abrimos el archivo en modo lectura

    if(archivo.fail()){
        cout << "Asegurese que el archivo exista" << endl;
        cout << endl;
        exit(1);
    }

    while(!archivo.eof()){ // mientras no sea el final del archivo
        getline(archivo,linea);
        texto = texto + linea + "\n";
    }

    archivo.close(); // cerramos el archivo

    return texto;

}

string archivoBinario(string cadena){ // recibe una cadena y la trasnforma en binario
    string palinbi;
    string vacio = "";
    int lon = cadena.length();
    int n;

    for (int i=0; i < lon ; i++){
        n = cadena[i];
        palinbi = dectobin(n);
        vacio.append(palinbi);
    }
    return vacio;
}

string dectobin(int n){ // recibe un numero decimal y lo retorna en binario (string)
    int b;
    string vacio = "";
    string vacioinv = "";

    for (int i=0; i<8 ; i++){
        b = n%2;
        n = n/2;
        if (b==0){
            vacio.append("0");
        }
        else{
            vacio.append("1");
        }
    }
    for (int k=7; k>=0 ; k--){
        vacioinv.append(vacio.substr(k,1)); // posición, elementos
    }
    return vacioinv;
}

string metodoDos(string bin, int sem){ // Metodo dos, recibe un numero binario y una semilla para ecnriptar
    int len = bin.length();
    int lim;

    string fracc; // fraccion
    string encDos = "";

    if ( len % sem == 0){
        lim = (len/sem);
    }
    else{
        lim = (len/sem)+1;
    }

    for (int i=0 ; i < lim; i++){
        fracc = bin.substr(i*sem,sem); // posición, elementos
        encDos.append(encriptar2(fracc));
    }
    return encDos;

}

string encriptar2(string frac){ // encripata una FRACCION o GRUPO con el metodo 2
    string enc_vacio = "";

    int len = frac.length();

    enc_vacio.append(frac.substr(len-1,1));

    for (int i=0; i<(len-1) ; i++){
        enc_vacio.append(frac.substr(i,1));
    }

   return enc_vacio;

}

void escribir(string name, string escritura){ // Recibe el nombre del fichero, y el string lo que va a escribir en el fichero
    ofstream archivo; // tipo de dato que me permite escribir un archivo

    archivo.open(name.c_str(),ios::out); // abrimos el archivo en modo escritura

    if (archivo.fail()){
        cout << "Error al crear el archivo!" << endl;
        cout << endl;
        exit(1);
    }
    archivo<<escritura;
    archivo.close();
}

string decodificacionDos(string bin, int sem){ // Decofifica, recibe un numero binario y una semilla para ecnriptar
    int len = bin.length();
    int lim;

    string fracc; // fraccion
    string encDos = "";

    if ( len % sem == 0){
        lim = (len/sem);
    }
    else{
        lim = (len/sem)+1;
    }

    for (int i=0 ; i < lim; i++){
        fracc = bin.substr(i*sem,sem);
        encDos.append(decoDos(fracc));
    }
    return encDos;

}

string decoDos(string frac){ // decodifica una FRACCION o GRUPO con el metodo 2
    string enc_vacio = "";

    int len = frac.length();


    for (int i=1; i<len ; i++){
        enc_vacio.append(frac.substr(i,1));
    }

    enc_vacio.append(frac.substr(0,1));

   return enc_vacio;
}

string represetacion (string cadBin){  // recibe un binario y retorna su palabra o texto correpondiente
    string palabra = "";
    int len = cadBin.length();
    int let;

    for (int i=0; i < len/8 ; i++){
        let = bintodec(cadBin.substr(i*8,8));
        palabra += let;
    }

    return palabra;
}

int bintodec(string bin){ // recibe un binario y retorna un decimal en tipo entero
    int dec = 0;
    for(int i=0; i<8 ; i++){
        if (bin.substr(i,1)=="1"){
                dec = dec + (dos_exp(7-i));
        }
    }
    return dec;
}

int dos_exp (int exp){
    int acu = 1;
    for (int i=0 ; i<exp ; i++){
        acu = acu*2;
    }
    return acu;
}
