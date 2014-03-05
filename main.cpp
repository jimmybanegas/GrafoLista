#include <QCoreApplication>
#include "grafo.h"
#include <iostream>
using namespace  std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Grafo miGrafo;

    int op;     // opcion del menu

        do
        {
            miGrafo.menu();
            cin>>op;

            switch(op)
            {
                case 1:
                        miGrafo.insertar_nodo();
                        break;
                case 2:  miGrafo.insertar_arista();
                        break;
                case 3:  miGrafo.eliminar_nodo();
                        break;
                case 4:  miGrafo.eliminar_arista();
                        break;
                case 5:  miGrafo.mostrar_grafo();
                        break;
                case 6:  miGrafo.mostrar_aristas();
                        break;
                case 7: break;

                default: cout<<"OPCION NO VALIDA...!!!";
                         break;


            }

           // cout<<endl<<endl;
            //system("pause");  system("cls");

        }while(op!=7);


    return a.exec();
}
