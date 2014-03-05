#include "grafo.h"

void Grafo::menu()
{
        cout<<"\n\tREPRESENTACION DE GRAFOS DIRIGIDOS\n\n";
        cout<<" 1. INSERTAR UN NODO                 "<<endl;
        cout<<" 2. INSERTAR UNA ARISTA              "<<endl;
        cout<<" 3. ELIMINAR UN NODO                 "<<endl;
        cout<<" 4. ELIMINAR UNA ARISTA              "<<endl;
        cout<<" 5. MOSTRAR  GRAFO                   "<<endl;
        cout<<" 6. MOSTRAR ARISTAS DE UN NODO       "<<endl;
        cout<<" 7. SALIR                            "<<endl;

        cout<<"\n INGRESE OPCION: ";
}

void Grafo::insertar_nodo()
{
        Nodo *t,*nuevo = new Nodo();
        cout<<"INGRESE VARIABLE:";
        cin>>nuevo->nombre;
        nuevo->sgte = NULL;
        nuevo->ady=NULL;

        if(p==NULL)
         {
            p = nuevo;
            cout<<"PRIMER NODO...!!!"<<endl;
          }
        else
         {
            t = p;
            while(t->sgte!=NULL)
             {
                t = t->sgte;
              }
            t->sgte = nuevo;
            cout<<"NODO INGRESADO...!!!"<<endl;
        }
}

void Grafo::agrega_arista(Nodo *aux, Nodo *aux2, Arista *nuevo)
{
      Arista *q;
      if(aux->ady==NULL)
      {   aux->ady=nuevo;
          nuevo->destino=aux2;
          cout<<"PRIMERA ARISTA....!"<<endl;
      }
      else
      {   q=aux->ady;
          while(q->sgte!=NULL)
              q=q->sgte;
          nuevo->destino=aux2;
          q->sgte=nuevo;
          cout<<"ARISTA AGREGADA...!!!!"<<endl;
      }
}

void Grafo::insertar_arista()
{
       char ini, fin;
        Arista *nuevo=new Arista();
        Nodo *aux, *aux2;

        if(p==NULL)
         {
             cout<<"GRAFO VACIO...!!!!";
             return;
         }
        nuevo->sgte=NULL;
        cout<<"INGRESE NODO DE INICIO:";
        cin>>ini;
        cout<<"INGRESE NODO FINAL:";
        cin>>fin;
        aux=p;
        aux2=p;
        while(aux2!=NULL)
        {
            if(aux2->nombre==fin)
            {
                break;
            }

            aux2=aux2->sgte;
        }
        while(aux!=NULL)
        {
            if(aux->nombre==ini)
            {
                agrega_arista(aux,aux2, nuevo);
                return;
            }

            aux = aux->sgte;
        }
}

void Grafo::vaciar_aristas(Nodo *aux)
{
   Arista *q,*r;
        q=aux->ady;
        while(q->sgte!=NULL)
        {
            r=q;
            q=q->sgte;
            delete(r);
        }
}

void Grafo::eliminar_nodo()
{
       char var;
        Nodo *aux,*ant;
        aux=p;
        cout<<"ELIMINAR UN NODO\n";
        if(p==NULL)
         {
             cout<<"GRAFO VACIO...!!!!";
             return;
         }
        cout<<"INGRESE NOMBRE DE VARIABLE:";
        cin>>var;

        while(aux!=NULL)
        {
            if(aux->nombre==var)
            {
                if(aux->ady!=NULL)
                    vaciar_aristas(aux);

                if(aux==p)
                {

                        p=p->sgte;
                        delete(aux);
                        cout<<"NODO ELIMINADO...!!!!";
                        return;
                }
                else
                {
                    ant->sgte = aux->sgte;
                    delete(aux);
                    cout<<"NODO ELIMINADO...!!!!";
                    return;
                }
            }
            else
            {
                ant=aux;
                aux=aux->sgte;
             }
        }
}

void Grafo::eliminar_arista()
{
        char ini, fin;
        Nodo *aux, *aux2;
        Arista *q,*r;
        cout<<"\n ELIMINAR ARISTA\n";
        cout<<"INGRESE NODO DE INICIO:";
        cin>>ini;
        cout<<"INGRESE NODO FINAL:";
        cin>>fin;
        aux=p;
        aux2=p;
        while(aux2!=NULL)
        {
            if(aux2->nombre==fin)
            {
                break;
            }
            else
            aux2=aux2->sgte;
        }
         while(aux!=NULL)
        {
            if(aux->nombre==ini)
            {
                q=aux->ady;
                while(q!=NULL)
                {
                    if(q->destino==aux2)
                    {
                        if(q==aux->ady)
                            aux->ady=aux->ady->sgte;
                        else
                            r->sgte=q->sgte;
                        delete(q);
                        cout<<"ARISTA  "<<aux->nombre<<"----->"<<aux2->nombre<<" ELIMINADA.....!!!!";
                        return;
                    }
                }
                r=q;
                q=q->sgte;
            }
            aux = aux->sgte;
         }
}

void Grafo::mostrar_grafo()
{
        Nodo *ptr;
        Arista *ar;
        ptr=p;
        cout<<"NODO|LISTA DE ADYACENCIA\n";

        while(ptr!=NULL)
        {   cout<<"   "<<ptr->nombre<<"|";
            if(ptr->ady!=NULL)
            {
                ar=ptr->ady;
                while(ar!=NULL)
                {   cout<<" "<<ar->destino->nombre;
                    ar=ar->sgte;
                 }

            }
            ptr=ptr->sgte;
            cout<<endl;
        }
}

void Grafo::mostrar_aristas()
{
        Nodo *aux;
        Arista *ar;
        char var;
        cout<<"MOSTRAR ARISTAS DE NODO\n";
        cout<<"INGRESE NODO:";
        cin>>var;
        aux=p;
        while(aux!=NULL)
        {
            if(aux->nombre==var)
            {
                if(aux->ady==NULL)
                {   cout<<"EL NODO NO TIENE ARISTAS...!!!!";
                    return;
                 }
                else
                {
                    cout<<"NODO|LISTA DE ADYACENCIA\n";
                    cout<<"   "<<aux->nombre<<"|";
                    ar=aux->ady;

                    while(ar!=NULL)
                    {
                        cout<<ar->destino->nombre<<" ";
                        ar=ar->sgte;
                    }
                    cout<<endl;
                    return;
                }
            }
            else
            aux=aux->sgte;
        }
}

Grafo::Grafo()
{
    this->p=NULL; //ctor
}
