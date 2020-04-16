#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;
//-------------------------------------------------------------------------------------
//							Estructura del Nodo
//-------------------------------------------------------------------------------------
struct nodos{
	char ingles[50];
	char espanol[50];
	struct nodos *der;
	struct nodos *izq;
	int Fe;
};
//-------------------------------------------------------------------------------------
//							--------------------
//-------------------------------------------------------------------------------------
typedef struct nodos Arbol;
typedef Arbol *ARBOL;
int listo;
char in[50],es[50];
//-------------------------------------------------------------------------------------
//							Protótipos de las funciones
//-------------------------------------------------------------------------------------
void menu();
void menu_agregar();
void menu_ingles();
void menu_espanol();
void menu_borrar();
void menu_listar();
void agregar(ARBOL  *nodoarb);
void buscar_ingles(ARBOL nodoarb);
void buscar_espanol(ARBOL nodoarb);
void listar(ARBOL nodoarb);
void rotacionddsimple(ARBOL *nodoarb);
void rotaciondidoble(ARBOL *nodoarb);
void rotaciondd2(ARBOL *nodoarb);
void rotacionii2(ARBOL *nodoarb);
void rotacioniisimple(ARBOL *nodoarb);
void rotacioniddoble(ARBOL *nodoarb);
void menor(ARBOL nodoarb);
void actualizarbi(ARBOL *nodoarb, int *ban);
void actualizarbd(ARBOL *nodoarb, int *ban);
void eliminar(ARBOL *nodoarb, int *ban);
void borrar(ARBOL *nodoarb , int *ban);
//-------------------------------------------------------------------------------------
//						    	PROGRAMA PRINCIPAL
//-------------------------------------------------------------------------------------
int main()
{
	char opc='1';
	int ban=1;
	ARBOL raiz=NULL;
	do
		{
			menu();
			cin>>opc;
			switch(opc){
						case '1':
								menu_agregar();
							    cout<<"Introduzca Palabra en Ingles : ";
								cin>>in;
								cout<<"Introduzca Palabra en Espanol : ";
								cin>>es;
								agregar(&raiz);
							    break;
						case '2':
								menu_borrar();
								cout<<"Que Palabra en Ingles desea Borrar? : ";
								cin>>in;
								borrar(&raiz,&ban);
								cout<<"Elemento Borrado!";
							    break;
						case '3':
							    menu_ingles();
								cout<<"Que Palabra en Ingles desea Buscar? : ";
								cin>>in;
								listo=0;
								buscar_ingles(raiz);
								if (listo==0)
									cout<<"Elemento no encontrado!";
								getch();
								listo=0;
								break;

						case '4':
								menu_espanol();
								cout<<"Que Palabra en Espanol desea Buscar? : ";
								cin>>es;
								listo=0;
								buscar_espanol(raiz);
								if (listo==0)
									cout<<"Elemento no encontrado!";
								getch();
								listo=0;
								break;
						case '5':
								menu_listar();
								listar(raiz);
								getch();
							    break;
						}
		}	while (opc !='6');
}
//-------------------------------------------------------------------------------------
//						    	Funcion Menu
//-------------------------------------------------------------------------------------
void menu()
{
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"               TRADUCTOR INGLES - ESPANOL / ESPANOL INGLES                      "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  1. Agregar palabras al diccionario                            "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  2. Borrar palabras del diccionario                            "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  3. Consultar Palabra en Ingles                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  4. Consultar Palabra en Espanol                               "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  5. Listar Palabras                                            "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                  6. Salir                                                      "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"  Digite su Opcion?????                                                         "<<endl;

}

//-------------------------------------------------------------------------------------
//						    	Funcion Menu Agregar
//-------------------------------------------------------------------------------------
void menu_agregar()
{
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                      AGREGAR PALABRAS AL TRADUCTOR                             "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
}

//-------------------------------------------------------------------------------------
//						    	Funcion Menu Buscar Ingles
//-------------------------------------------------------------------------------------
void menu_ingles()
{
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                         BUSCAR PALABRA EN INGLES                               "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
}

//-------------------------------------------------------------------------------------
//						    	Funcion Menu Buscar Espanol
//-------------------------------------------------------------------------------------
void menu_espanol()
{
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                        BUSCAR PALABRA EN ESPANOL                               "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
}

//-------------------------------------------------------------------------------------
//						    	Funcion Menu Borrar
//-------------------------------------------------------------------------------------
void menu_borrar()
{
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                      BORRAR PALABRA DEL DICCIONARIO                            "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
}
//-------------------------------------------------------------------------------------
//						    	Funcion Menu Listar
//-------------------------------------------------------------------------------------
void menu_listar()
{
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                      LISTAR PALABRAS DEL TRADUCTOR                             "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                "<<endl;
}

//-------------------------------------------------------------------------------------
//  			    	Funcion Agregar palabras al Diccionario
//-------------------------------------------------------------------------------------

void agregar(ARBOL  *nodoarb)
{

	int det;
	if (*nodoarb == NULL){
		*nodoarb = new(Arbol);
		if (*nodoarb != NULL){
			strcpy((*nodoarb)->ingles,in);
			strcpy((*nodoarb)->espanol,es);
			(*nodoarb)->der=NULL;
			(*nodoarb)->izq=NULL;
		}
		else{
            system("cls");
			cout<<"No hay memoria suficiente!";
		}
	}
	else
	{
		det=strcmp(in,(*nodoarb)->ingles);

		if (det < 0)
			agregar (&((*nodoarb)->izq));
		else
			if (det > 0)
				agregar (&((*nodoarb)->der));
			else
			{
				system("cls");
				cout<<"¡¡¡ Dato duplicado !!!";
				getch();
				system("cls");
			}
	}
}

//-------------------------------------------------------------------------------------
//						    	Funcion Buscar Ingles
//-------------------------------------------------------------------------------------

void buscar_ingles(ARBOL nodoarb)
{
	if (nodoarb != NULL){
		buscar_ingles(nodoarb->izq);
		if (strcmp(in,nodoarb->ingles)==0)
		{
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"                        "<<nodoarb->ingles<<" -> "<<nodoarb->espanol<<endl;
			listo=1;
			return;
		}
		buscar_ingles(nodoarb->der);
	}
}

//-------------------------------------------------------------------------------------
//						    	Funcion Buscar Ingles
//-------------------------------------------------------------------------------------

void buscar_espanol(ARBOL nodoarb)
{
	if (nodoarb != NULL){
		buscar_espanol(nodoarb->izq);
		if (strcmp(es,nodoarb->espanol)==0)
		{
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"                        "<<nodoarb->espanol<<" -> "<<nodoarb->ingles<<endl;
			listo=1;
			return;
		}
		buscar_espanol(nodoarb->der);
	}
}
//-------------------------------------------------------------------------------------
//						    	Funcion listar Palabras
//-------------------------------------------------------------------------------------


void listar(ARBOL nodoarb)
{
	if (nodoarb != NULL){
		listar(nodoarb->izq);
		cout<<"                            "<<nodoarb->ingles<<" -> "<<nodoarb->espanol<<endl;
		listar(nodoarb->der);
	}
}

//-------------------------------------------------------------------------------------
//						    	Funcion rotacionddsimple
//-------------------------------------------------------------------------------------

void rotacionddsimple(ARBOL *nodoarb)
{
  ARBOL nda=NULL;
	nda=(*nodoarb)->der;
	(*nodoarb)->der=nda->izq;
	nda->izq=(*nodoarb);
	nda->Fe=0;
	(*nodoarb)->Fe=0;
}

//-------------------------------------------------------------------------------------
//						    	Funcion rotaciondidoble
//-------------------------------------------------------------------------------------

void rotaciondidoble(ARBOL *nodoarb)
{
  ARBOL nda1=NULL, nda2=NULL;
	nda1=(*nodoarb)->der;
	nda2=nda1->der;

	nda1->izq=nda2->der;
	nda2->der=nda1;
	(*nodoarb)->der=nda2->izq;
	nda2->izq=(*nodoarb);

	if (nda2->Fe == 1)
		(*nodoarb)->Fe=-1;
	else
		(*nodoarb)->Fe=0;
	if (nda2->Fe == -1)
		(*nodoarb)->Fe=1;
	else
		(*nodoarb)->Fe=0;

	nda2->Fe=0;
	(*nodoarb)=nda2;
}

//-------------------------------------------------------------------------------------
//						    	Funcion rotaciondd2
//-------------------------------------------------------------------------------------

void rotaciondd2(ARBOL *nodoarb)
{
  ARBOL nda=NULL;
	nda=(*nodoarb)->der;
	(*nodoarb)->der=nda->izq;
	nda->izq=(*nodoarb);
	nda->Fe=-1;
	(*nodoarb)->Fe=1;
	(*nodoarb)=nda;
}

//-------------------------------------------------------------------------------------
//						    	Funcion rotacionii2
//-------------------------------------------------------------------------------------

void rotacionii2(ARBOL *nodoarb)
{
  ARBOL nda=NULL;
	nda=(*nodoarb)->izq;
	(*nodoarb)->izq=nda->der;
	nda->der=(*nodoarb);
	nda->Fe=1;
	(*nodoarb)->Fe=-1;
	(*nodoarb)=nda;
}

//-------------------------------------------------------------------------------------
//						    	Funcion rotacionsimple
//-------------------------------------------------------------------------------------


void rotacioniisimple(ARBOL *nodoarb)
{
  ARBOL nda=NULL;
	nda=(*nodoarb)->izq;
	(*nodoarb)->izq=nda->der;
	nda->der=(*nodoarb);
	nda->Fe=0;
	(*nodoarb)->Fe=0;
        *nodoarb=nda;
}

//-------------------------------------------------------------------------------------
//						    	Funcion rotacioniddoble
//-------------------------------------------------------------------------------------

void rotacioniddoble(ARBOL *nodoarb)
{
  ARBOL nda1=NULL, nda2=NULL;

	nda1=(*nodoarb)->izq;
	nda2=nda1->der;
	nda1->der=nda2->izq;
	nda2->izq=nda1;

	(*nodoarb)->izq=nda2->der;
	nda2->der=(*nodoarb);

	if (nda2->Fe == 1)
		nda1->Fe=-1;
	else
		nda1->Fe=0;
	if (nda2->Fe == -1)
		(*nodoarb)->Fe=1;
	else
		(*nodoarb)->Fe=0;

	nda2->Fe=0;
	(*nodoarb)=nda2;
}

//-------------------------------------------------------------------------------------
//						    	Funcion Menor
//-------------------------------------------------------------------------------------

void menor(ARBOL nodoarb)
{
	if (nodoarb->izq == NULL)
	{
		strcpy(in,nodoarb->ingles);
		strcpy(es,nodoarb->espanol);
	}
	else
		menor(nodoarb->izq);
}

//-------------------------------------------------------------------------------------
//			 			    	Funcion Actualizarbi
//-------------------------------------------------------------------------------------

void actualizarbi(ARBOL *nodoarb, int *ban)
{
	switch((*nodoarb)->Fe){
		case -1:
			(*nodoarb)->Fe=0;
			break;
		case 0:
			(*nodoarb)->Fe=1;
			*ban=0;
			break;
		case 1:
			switch((*nodoarb)->der->Fe){
				case 1:
					rotacionddsimple(&(*nodoarb));
					break;
				case -1:
					rotaciondidoble(&(*nodoarb));
					break;
				case 0:
					rotaciondd2(&(*nodoarb));
					*ban=0;
					break;

			}
			break;
	}
}
//-------------------------------------------------------------------------------------
//						    	Funcion Actualizarbd
//-------------------------------------------------------------------------------------


void actualizarbd(ARBOL *nodoarb, int *ban)
{
	switch((*nodoarb)->Fe){
		case 1:
			(*nodoarb)->Fe=0;
			break;
		case 0:
			(*nodoarb)->Fe=-1;
			*ban=0;
			break;
		case -1:
			switch((*nodoarb)->izq->Fe){
				case -1:
					rotacioniisimple(&(*nodoarb));
					break;
				case 1:
					rotacioniddoble(&(*nodoarb));
					break;
				case 0:
					rotacionii2(&(*nodoarb));
					*ban=0;
					break;

			}
			break;
	}
}

//-------------------------------------------------------------------------------------
//						    	Funcion Eliminar
//-------------------------------------------------------------------------------------

void eliminar(ARBOL *nodoarb, int *ban)
{
 ARBOL aux=NULL;

	if ((*nodoarb)->izq == NULL){
		aux=*nodoarb;
		*nodoarb=(*nodoarb)->der;
		free(aux);
		*ban=1;
	}
	else{
		if ((*nodoarb)->der == NULL){
			aux=*nodoarb;
			*nodoarb=(*nodoarb)->izq;
			free(aux);
			*ban=1;
		}
		else{
			menor((*nodoarb)->der);
			borrar(&(*nodoarb)->der,&(*ban));
			if (*ban)
				actualizarbd(&(*nodoarb),&(*ban));
		}
	}
}


//-------------------------------------------------------------------------------------
//						    	Funcion Borrar
//-------------------------------------------------------------------------------------


void borrar(ARBOL *nodoarb , int *ban)
{
	if (nodoarb == NULL)
		*ban=0;
	else
		if (strcmp((*nodoarb)->ingles,in)==0)
			eliminar(&(*nodoarb),&(*ban));

		else
			if (strcmp((*nodoarb)->ingles,in) > 0 ){
				borrar(&(*nodoarb)->izq,&(*ban));
				if (*ban)
					actualizarbi(&(*nodoarb),&(*ban));
			}
			else{
				borrar(&(*nodoarb)->der,&(*ban));
				if (*ban)
					actualizarbd(&(*nodoarb),&(*ban));

			}
}

//-------------------------------------------------------------------------------------
//						               FIN
//-------------------------------------------------------------------------------------
