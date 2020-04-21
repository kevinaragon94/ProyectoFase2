#include<iostream>
#include<fstream>
#include<windows.h>
#include<string.h>
#include<cstdlib>
#include<conio.h>
#include <stdlib.h>
#include <Mmsystem.h>


#define SND_FILENAME 0x20000
#define SND_LOOP 8
#define SND_ASYNC 2

using namespace std;

char espanol[15], ingles[15], frances[15], italiano[15],auxpalabra[15];

const wchar_t* URL = L"C:\\Users\\NoxPride\\Desktop\\Proyecto\\ProyectoFase2\\Fase l\\ ";

bool encontrado=false;

void menu();
void castellano();
void ingles_f();
void frances_f();
void italiano_f();


int main()
{
    menu();
    system("PAUSE");
    return 0;
}


void menu(){
int opcion=0;
	do{


	cout<<"_________________________________________"<<endl;
	cout<<"|          Traductor Google             |"<<endl;
	cout<<"|MENU                                   |"<<endl;
	cout<<"|_______________________________________|"<<endl;
	cout<<"|                                       |"<<endl;
	cout<<"|.......Seleccione el Idioma............|"<<endl;
	cout<<"|.......................................|"<<endl;
	cout<<"|1.-.Espanol............................|"<<endl;
	cout<<"|2.-.Ingles.............................|"<<endl;
	cout<<"|3.-.Frances............................|"<<endl;
	cout<<"|4.-.Italiano...........................|"<<endl;
	cout<<"|5.-.Salir..............................|"<<endl;
	cout<<"|.......................................|"<<endl;
	cout<<"|.......................................|"<<endl;
	cout<<"|,,,,,,.................................|"<<endl;
	cout<<"|_______________________________________|"<<endl;

    cout<<"Digite la opcion: ";
    cin>>opcion;

switch (opcion)
{
case 01:
    castellano(); // Hacemos el llamado al metodo void
	break;
	case 02:
	ingles_f();   // Hacemos el llamado al metodo void
	break;
	case 03:
	frances_f();   // Hacemos el llamado al metodo void
	break;
	case 04:
	italiano_f();  // Hacemos el llamado al metodo void
	break;
	case 5:
	cout<<"PROGRAMA FINALIZADO";
	exit(1);
	break;
	default:
    cout<<"Numero ingresado no se encuentra en el menu"<<endl;}

}while(opcion!=5);//el menu se seguira ejecutando hasta que se presione la opcion 5 que es salir del programa

}


void castellano(){

    int opcion;
    ifstream lectura;//Creamos la variable de tipo lectura
    lectura.open("traducidas.txt",ios::out|ios::in);//Abrimos el archivo
    //validando la apertura del archivo
    encontrado=false;
    if(lectura.is_open()){
        cout<<"Ingrese la palabra a traducir: ";
        cin>>auxpalabra;   //creamos una variable para que haga la comparacion con el dato del archivo txt
        lectura>>espanol;//lectura adelantada del primer campo

        while(!lectura.eof()){
          lectura>>ingles>>frances>>italiano;//leyendo los campos del registro

            if (strcmp(auxpalabra,espanol)== 0){ //Comparar cada registro para ver si es encontrado

                 cout<<"Seleccione el idioma al que desea traducir:"<<endl;
                cout<<"| 1.Ingles   |  2.frances  |   3.italiano  |>>>";
                cin>>opcion;
                switch (opcion){   // esta opcion es para poder seleccionar el idioma que deseamps que se tradusca

                  case 1:
                      cout<<"______________________________"<<endl;
                      cout<<"Ingles: "<<ingles<<endl;
                      cout<<"______________________________"<<endl;
                      PlaySound ((URL,ingles),NULL,SND_FILENAME | SND_ASYNC);
                      break; //Hacemos el llamado al audio seleecionado
                  case 2:
                      cout<<"______________________________"<<endl;
                      cout<<"Frances: "<<frances<<endl;
                      cout<<"______________________________"<<endl;
                      PlaySound ((URL,frances),NULL,SND_FILENAME | SND_ASYNC);
                      break;//Hacemos el llamado al audio seleecionado
                  case 3:
                      cout<<"______________________________"<<endl;
                      cout<<"Italiano: "<<italiano<<endl;
                      cout<<"______________________________"<<endl;
                      PlaySound ((URL,italiano),NULL,SND_FILENAME | SND_ASYNC);
                      break;//Hacemos el llamado al audio seleecionado,
                      default:
                      cout<<"Opcion Incorrecta"<<endl;  //si usuario digite la opcion incorrecta volvera a pedir datos

            }
            encontrado=true; //si arrojo un true quiere decir que encontro lo que se le habia pedido

            }
            lectura>>espanol;//lectura adelantada
            }
        if(encontrado==false){
            cout<<"No hay registros con esta palabra "<<auxpalabra<<endl;//si arroja un false mandara un mensaje que no hay registros con esa palabra
        }
    }else{
        cout<<"Error en el Archivo"<<endl; //se encontro un error o no exite el archivo
        exit(1);
    }
    //cerrando el archivo
    lectura.close();

    }


void ingles_f(){

    int opcion;
    ifstream lectura;//Creamos la variable de tipo lectura
    lectura.open("traducidas.txt",ios::out|ios::in);//Abrimos el archivo
    //validando la apertura del archivo
    encontrado=false;
    if(lectura.is_open()){
        cout<<"Ingrese la palabra a traducir: ";
        cin>>auxpalabra;  //creamos una variable para que haga la comparacion con el dato del archivo txt
        lectura>>espanol>>ingles;//lectura adelantada

        while(!lectura.eof()){
          lectura>>frances>>italiano;//leyendo los campos del registro
            //Comparar cada registro para ver si es encontrado
            if (strcmp(auxpalabra,ingles)== 0){

                 cout<<"Seleccione el idioma al que desea traducir:"<<endl;
                cout<<"| 1.espanol  |  2.frances  |   3.italiano  |>>>";
                cin>>opcion;
                switch (opcion){// esta opcion es para poder seleccionar el idioma que deseamps que se tradusca

                  case 1:
                      cout<<"______________________________"<<endl;
                      cout<<"Espanol: "<<espanol<<endl;
                      cout<<"______________________________"<<endl;
                       PlaySound ((URL,espanol),NULL,SND_FILENAME | SND_ASYNC);
                      break;//Hacemos el llamado al audio seleecionado
                  case 2:
                      cout<<"______________________________"<<endl;
                      cout<<"Frances: "<<frances<<endl;
                      cout<<"______________________________"<<endl;
                       PlaySound ((URL,frances),NULL,SND_FILENAME | SND_ASYNC);
                      break;//Hacemos el llamado al audio seleecionado
                  case 3:
                      cout<<"______________________________"<<endl;
                      cout<<"Italiano: "<<italiano<<endl;
                      cout<<"______________________________"<<endl;
                       PlaySound ((URL,italiano),NULL,SND_FILENAME | SND_ASYNC);
                      break;//Hacemos el llamado al audio seleecionado
                      default:
                      cout<<"Opcion Incorrecta"<<endl; //si usuario digite la opcion incorrecta volvera a pedir datos

            }
            encontrado=true;//si arrojo un true quiere decir que encontro lo que se le habia pedido

            }
            lectura>>espanol>>ingles;//lectura adelantada
            }
        if(encontrado==false){
            cout<<"No hay registros con esta palabra "<<auxpalabra<<endl;//si arroja un false mandara un mensaje que no hay registros con esa palabra
        }
    }else{
        cout<<"Error en el Archivo"<<endl;//se encontro un error o no exite el archivo
        exit(1);
    }
    //cerrando el archivo
    lectura.close();

    }




void frances_f(){

    int opcion;
    ifstream lectura;//Creamos la variable de tipo lectura
    lectura.open("traducidas.txt",ios::out|ios::in);//Abrimos el archivo
    //validando la apertura del archivo
    encontrado=false;
    if(lectura.is_open()){
        cout<<"Ingrese la palabra a traducir: ";
        cin>>auxpalabra;  //creamos una variable para que haga la comparacion con el dato del archivo txt
        lectura>>espanol>>ingles>>frances;//lectura adelantada

        while(!lectura.eof()){
          lectura>>italiano;//leyendo los campos del registro
            //Comparar cada registro para ver si es encontrado
            if (strcmp(auxpalabra,frances)== 0){

                 cout<<"Seleccione el idioma al que desea traducir:"<<endl;
                cout<<"| 1.espanol  |  2.ingles  |   3.italiano  |>>>";
                cin>>opcion;
                switch (opcion){// esta opcion es para poder seleccionar el idioma que deseamps que se tradusca

                  case 1:
                      cout<<"______________________________"<<endl;
                      cout<<"Espanol: "<<espanol<<endl;
                      cout<<"______________________________"<<endl;
                       PlaySound ((URL,espanol),NULL,SND_FILENAME | SND_ASYNC);
                      break;//Hacemos el llamado al audio seleecionado
                  case 2:
                      cout<<"______________________________"<<endl;
                      cout<<"Ingles: "<<ingles<<endl;
                      cout<<"______________________________"<<endl;
                       PlaySound ((URL,ingles),NULL,SND_FILENAME | SND_ASYNC);
                      break;//Hacemos el llamado al audio seleecionado
                  case 3:
                      cout<<"______________________________"<<endl;
                      cout<<"Italiano: "<<italiano<<endl;
                      cout<<"______________________________"<<endl;
                       PlaySound ((URL,italiano),NULL,SND_FILENAME | SND_ASYNC);
                      break;//Hacemos el llamado al audio seleecionado
                      default:
                      cout<<"Opcion Incorrecta"<<endl;//si usuario digite la opcion incorrecta volvera a pedir datos

            }
            encontrado=true; //si arrojo un true quiere decir que encontro lo que se le habia pedido

            }
            lectura>>espanol>>ingles>>frances;//lectura adelantada
            }
        if(encontrado==false){
            cout<<"No hay registros con esta palabra "<<auxpalabra<<endl;//si arroja un false mandara un mensaje que no hay registros con esa palabra
        }
    }else{
        cout<<"Error en el Archivo"<<endl;//se encontro un error o no exite el archivo
        exit(1);
    }
    //cerrando el archivo
    lectura.close();

    }




void italiano_f(){

    int opcion;
    ifstream lectura;//Creamos la variable de tipo lectura
    lectura.open("traducidas.txt",ios::out|ios::in);//Abrimos el archivo
    //validando la apertura del archivo
    encontrado=false;
    if(lectura.is_open()){
        cout<<"Ingrese la palabra a traducir: ";
        cin>>auxpalabra;  //creamos una variable para que haga la comparacion con el dato del archivo txt
        lectura>>espanol>>ingles>>frances>>italiano;//lectura adelantada

        while(!lectura.eof()){
            //Comparar cada registro para ver si es encontrado
            if (strcmp(auxpalabra,italiano)== 0){

                 cout<<"Seleccione el idioma al que desea traducir:"<<endl;
                cout<<"| 1.espanol  |  2.ingles  |   3.frances  | >>>";
                cin>>opcion;
                switch (opcion){  // esta opcion es para poder seleccionar el idioma que deseamps que se tradusca

                  case 1:
                      cout<<"______________________________"<<endl;
                      cout<<"Espanol: "<<espanol<<endl;
                      cout<<"______________________________"<<endl;
                       PlaySound ((URL,espanol),NULL,SND_FILENAME | SND_ASYNC);
                      break;//Hacemos el llamado al audio seleecionado
                  case 2:
                      cout<<"______________________________"<<endl;
                      cout<<"Ingles: "<<ingles<<endl;
                      cout<<"______________________________"<<endl;
                       PlaySound ((URL,ingles),NULL,SND_FILENAME | SND_ASYNC);
                      break;//Hacemos el llamado al audio seleecionado
                  case 3:
                      cout<<"______________________________"<<endl;
                      cout<<"Frances: "<<frances<<endl;
                      cout<<"______________________________"<<endl;
                       PlaySound ((URL,frances),NULL,SND_FILENAME | SND_ASYNC);
                      break;//Hacemos el llamado al audio seleecionado
                      default:
                      cout<<"Opcion Incorrecta"<<endl;//si usuario digite la opcion incorrecta volvera a pedir datos

            }
            encontrado=true; //si arrojo un true quiere decir que encontro lo que se le habia pedido

            }
            lectura>>espanol>>ingles>>frances>>italiano;//lectura adelantada
            }
        if(encontrado==false){
            cout<<"No hay registros con esta palabra "<<auxpalabra<<endl;//si arroja un false mandara un mensaje que no hay registros con esa palabra
        }
    }else{
        cout<<"Error en el Archivo"<<endl;//se encontro un error o no exite el archivo
        exit(1);
    }
    //cerrando el archivo
    lectura.close();

    }
