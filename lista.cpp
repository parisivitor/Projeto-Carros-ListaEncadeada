/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "lista.h"

using namespace std;


tLista* inicia_lista() {
	tLista* tmp = new (tLista);
	tmp->tam = 0;
	tmp->lista = NULL;

        cout << "-A lista foi iniciada."<<endl;
	return tmp;
}
tLista * encerra_lista(tLista * ptlista) {
	no * ant = ptlista->lista;
	no * pont = ptlista->lista;
	
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(ptlista);
        cout << "-A lista foi removida."<<endl;
	
        return NULL;
}


no * busca(tLista * ptlista, std::string placa) {
	no * ptr = ptlista->lista;
        //no * ant = ptlista->lista;
       
	while (ptr != NULL && ptr->placa != placa) {
            //ant = ptr;
            ptr = ptr->prox;
        }
	return ptr;
}


tListaGen* inicia_listaGen() {
	tListaGen* tmp = new (tListaGen);
	tmp->tam = 0;
	tmp->listaGen = NULL;

        cout << "A lista busca generica foi iniciada."<<endl;
	return tmp;
}
tListaGen * encerra_listaGen(tListaGen * ptlista) {
	noGen * ant = ptlista->listaGen;
	noGen * pont = ptlista->listaGen;
	
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(ptlista);
        cout << "-A lista foi removida."<<endl;
	
        return NULL;
}

void insere_inicio_Gen(no * pno, tListaGen * ptlistagen){
        noGen* pGen;
        pGen = new(noGen);
       
        pGen->listaGen = pno;
        pGen->prox =  ptlistagen->listaGen;
        ptlistagen->listaGen = pGen;      
        ptlistagen->tam++;        
}

void buscaInsPorta(tLista * ptlista, tListaGen * ptlistagen,int porta){
	no * ptr = ptlista->lista;
	while(ptr != NULL ){
            if(ptr->porta==porta){
                insere_inicio_Gen(ptr, ptlistagen);
            }
            ptr = ptr->prox;
	}
        cout << endl;
}


void buscaInsKm(tLista * ptlista, tListaGen * ptlistagen,int km){
	no * ptr = ptlista->lista;
	while(ptr != NULL ){
            if(ptr->km<=km){
                insere_inicio_Gen(ptr, ptlistagen);
            }
            ptr = ptr->prox;
	}
}
void buscaInsAnoP(tLista * ptlista, tListaGen * ptlistagen,int ano,std::string potencia){
        
	no * ptr = ptlista->lista;
	while(ptr != NULL ){
            if(ptr->ano==ano && ptr->pot_motor == potencia){
                insere_inicio_Gen(ptr, ptlistagen);
            }
            ptr = ptr->prox;
	}
        cout << endl;
}
void buscaInsMarca(tLista * ptlista, tListaGen * ptlistagen, std::string marca){
	no * ptr = ptlista->lista;
	while(ptr != NULL ){
            if(ptr->marca==marca){
                insere_inicio_Gen(ptr, ptlistagen);
            }
            ptr = ptr->prox;
	}
        cout << endl;
}
void buscaInsComb(tLista * ptlista, tListaGen * ptlistagen,std::string combustivel){
	no * ptr = ptlista->lista;
	while(ptr != NULL ){
            if(ptr->combustivel==combustivel){
                insere_inicio_Gen(ptr, ptlistagen);
            }
            ptr = ptr->prox;
	}
        cout << endl;
}
void buscaInsMod(tLista * ptlista, tListaGen * ptlistagen,std::string modelo){
	no * ptr = ptlista->lista;
	while(ptr != NULL ){
            if(ptr->modelo==modelo){
                insere_inicio_Gen(ptr, ptlistagen);
            }
            ptr = ptr->prox;
	}
        cout << endl;
}

void insere_inicio(tLista * ptlista, std::string modelo, std::string marca, std::string tipo, int ano, int km, std::string pot_motor, std::string combustivel, std::string cambio, std::string direcao, std::string cor, int porta, std::string placa){
	no* p;
        p = new(no);
        p->modelo = modelo;
        p->marca = marca;
        p->tipo = tipo;
        p->ano = ano ;
        p->km = km;
        p->pot_motor = pot_motor;
        p->combustivel = combustivel;
        p->cambio = cambio;
        p->direcao = direcao;
        p->cor = cor;
        p->porta = porta;
        p->placa = placa;
        p->prox = ptlista->lista;
        ptlista->lista = p;
        ptlista->tam++;
}
void insere_fim(tLista * ptlista, std::string modelo, std::string marca, std::string tipo, int ano, int km, std::string pot_motor, std::string combustivel, std::string cambio, std::string direcao, std::string cor, int porta, std::string placa){
    
        if (ptlista->tam == 0)
           insere_inicio(ptlista, modelo, marca, tipo, ano, km, pot_motor, combustivel, cambio, direcao, cor, porta, placa );
        else {
            no* p = ptlista->lista;
            while (p->prox != NULL)
                p = p->prox;
                p->prox = new(no);
                p->modelo = modelo;
                p->marca = marca;
                p->tipo = tipo;
                p->ano = ano ;
                p->km = km;
                p->pot_motor = pot_motor;
                p->combustivel = combustivel;
                p->cambio = cambio;
                p->direcao = direcao;
                p->cor = cor;
                p->porta = porta;
                p->placa = placa;
                p->prox->prox = NULL;
                ptlista->tam++;
        }
}

no * remove(tLista * ptlista, std::string placa) {
	no * ptr = ptlista->lista;
        no * ant = ptlista->lista;
        if(ptlista->tam == 0)
            return NULL;
        
        int cont=0;
       
	while (ptr != NULL && ptr->placa != placa) {
            ant = ptr;
            ptr = ptr->prox;
            cont++;
        }
        if(cont==0){
            ptlista->lista = ptr->prox;
        }else{
            ant->prox = ptr->prox;
        }
        
	return ptr;
}

void removeGen(tListaGen * ptlista, std::string placa) {
	noGen * ptr = ptlista->listaGen;
        noGen * ant = ptlista->listaGen;
        //if(ptlista->tam == 0)
            
        
        int cont=0;
       
	while (ptr != NULL && ptr->listaGen->placa != placa) {
            ant = ptr;
            ptr = ptr->prox;
            cont++;
        }
        if(cont==0){
            ptlista->listaGen = ptr->prox;
        }else{
            ant->prox = ptr->prox;
        }
}

no * remove_inicio(tLista * ptlista){
	no * p;

	if(ptlista->tam == 0)
            return NULL;

        p = ptlista->lista;
        ptlista->lista = p->prox;
        p->prox = NULL;
        ptlista->tam--;
	return p;
}
no * remove_fim(tLista * ptlista){
	no * p, * ant;

	if(ptlista->tam == 0)
            return NULL;

        p = ptlista->lista;
        while (p->prox != NULL){
            ant = p;
            p = p->prox;
        }
        if (p == ptlista->lista)
            ptlista->lista = NULL;
        else
            ant->prox = NULL;
        p->prox = NULL;
        ptlista->tam--;
	return p;
}


void imprime(tLista * ptlista){
	no * ptr = ptlista->lista;
        cout<< "|--- PLACA --- MODELO  ---  MARCA --- TIPO --- ANO --- KM --- POTERNCIA DO MOTOR --- COMBUSTIVEL -- CAMBIO --- DIRECAO --- COR --- PORTA ---|"<<endl; 
	while(ptr != NULL){
            cout << ptr->placa<< " " << ptr->modelo << " " << ptr->marca << " " << ptr->tipo << " " << ptr->ano << " " << ptr->km << " " << ptr->pot_motor << " " << ptr->combustivel << " " << ptr->cambio << " " << ptr->direcao << " " << ptr->cor << " " << ptr->porta << endl;
            ptr = ptr->prox;
	}
        cout << endl;
}
void imprimeGen(tListaGen * ptlistagen){
	noGen * ptr = ptlistagen->listaGen;
        cout<< "+----------------------------------------------- RESULTADO DA BUSCA ------------------------------------------------------------+"<<endl;
        cout<< "|--- PLACA --- MODELO --- MARCA --- TIPO --- ANO --- KM --- P.MOTOR --- COMBUSTIVEL --- CAMBIO --- DIRECAO --- COR --- PORTA ---|"<<endl; 
	while(ptr != NULL){
            cout <<"|-- "<< ptr->listaGen->placa<<"  "<<ptr->listaGen->modelo<< "  " << ptr->listaGen->marca << "  " << ptr->listaGen->tipo << "     " << ptr->listaGen->ano << "  " << ptr->listaGen->km << "      " << ptr->listaGen->pot_motor << "         " << ptr->listaGen->combustivel << "        " << ptr->listaGen->cambio << "  " << ptr->listaGen->direcao << "  " << ptr->listaGen->cor << "    " << ptr->listaGen->porta<<"    --|" << endl;
            ptr = ptr->prox;
	}
        cout<< "+--------------------------------------------- "<<ptlistagen->tam<<" RESULTADOS ENCONTRADOS --------------------------------------------------------+"<<endl<<endl<<endl;        
}


void salva_arqOrd(tLista * ptlista, std::string nome_arq){
    //std::string modelo, marca, pot_motor, combustivel, cambio, direcao, cor, placa, nome_arq, tipo; 
    //int ano, porta, km; 
    
    ofstream arqOrd;
    arqOrd.open (nome_arq);
    
    if (arqOrd.is_open()){
        no * ptr = ptlista->lista;
        while(ptr != NULL){
            arqOrd<<ptr->placa << " "<<ptr->modelo << " " << ptr->marca << " " << ptr->tipo << " " << ptr->ano << " " << ptr->km << " " << ptr->pot_motor << " " << ptr->combustivel << " " << ptr->cambio << " " << ptr->direcao << " " << ptr->cor << " " << ptr->porta << endl;
            ptr = ptr->prox;
        }
        arqOrd.close();
    }
    
    no * ptr = ptlista->lista;
    
    cout<< endl;
}
void salva_arqGen(tListaGen * ptlistagen, std::string nome_arq){
    //std::string modelo, marca, pot_motor, combustivel, cambio, direcao, cor, placa, tipo; 
    //int ano, porta, km; 
    
    ofstream arqGen;
    arqGen.open (nome_arq);
    
    if (arqGen.is_open()){
        noGen * ptr = ptlistagen->listaGen;
        while(ptr != NULL){
           arqGen << ptr->listaGen->placa<<" "<<ptr->listaGen->modelo<< " " << ptr->listaGen->marca << " " << ptr->listaGen->tipo << " " << ptr->listaGen->ano << " " << ptr->listaGen->km << " " << ptr->listaGen->pot_motor << " " << ptr->listaGen->combustivel << " " << ptr->listaGen->cambio << " " << ptr->listaGen->direcao << " " << ptr->listaGen->cor << " " << ptr->listaGen->porta << endl;
           ptr = ptr->prox;
        }
        arqGen.close();
    }
    
    noGen * ptr = ptlistagen->listaGen;
    
    cout<< endl;
}

void ordenaPlacaC(tLista * ptlista){
    if(ptlista->lista != NULL){
        no* menor = new(no); 
        no* aux = new(no);
        no* anti = new(no);
        no* antj = new(no);
        int tmp =0;
        
        
        no* i = ptlista->lista;
        no* j ;
        while(i->prox !=NULL){
            menor = i;
            j = i->prox;
            while(j!=NULL){
                if(j->placa < menor->placa)
                    menor = j;
                antj=j;
                j=j->prox;
            }
            anti=i;
            aux->placa = i->placa;
            aux->modelo = i->modelo;
            aux->marca = i->marca;
            aux->ano = i->ano;
            aux->combustivel = i->combustivel;
            aux->cor = i->cor;
            aux->direcao = i->direcao;
            aux->km = i->km;
            aux->porta = i->porta;
            aux->tipo = i->tipo;
            aux->pot_motor = i->pot_motor;
            aux->direcao = i->direcao;
            
            i->placa = menor->placa;
            i->modelo = menor->modelo;
            i->marca = menor->marca;
            i->ano = menor->ano;
            i->combustivel = menor->combustivel;
            i->cor = menor->cor;
            i->direcao = menor->direcao;
            i->km = menor->km;
            i->porta = menor->porta;
            i->tipo = menor->tipo;
            i->pot_motor = menor->pot_motor;
            i->direcao = menor->direcao;
            
            menor->placa = aux->placa;
            menor->modelo = aux->modelo;
            menor->marca = aux->marca;
            menor->ano = aux->ano;
            menor->combustivel = aux->combustivel;
            menor->cor = aux->cor;
            menor->direcao = aux->direcao;
            menor->km = aux->km;
            menor->porta = aux->porta;
            menor->tipo = aux->tipo;
            menor->pot_motor = aux->pot_motor;
            menor->direcao = aux->direcao;
            
            i=i->prox;           
        }
    }
}
void ordenaPlacaD(tLista * ptlista){
    if(ptlista->lista != NULL){
        no* menor = new(no); 
        no* aux = new(no);
        
        for(no* i = ptlista->lista; i->prox != NULL; i = i->prox){
            menor = i;
            for(no* j = i->prox; j!=NULL; j=j->prox){
                if(j->placa > menor->placa)
                    menor = j;
            }         
                       
            aux->placa = i->placa;
            aux->modelo = i->modelo;
            aux->marca = i->marca;
            aux->ano = i->ano;
            aux->combustivel = i->combustivel;
            aux->cor = i->cor;
            aux->direcao = i->direcao;
            aux->km = i->km;
            aux->porta = i->porta;
            aux->tipo = i->tipo;
            aux->pot_motor = i->pot_motor;
            aux->direcao = i->direcao;
            
            i->placa = menor->placa;
            i->modelo = menor->modelo;
            i->marca = menor->marca;
            i->ano = menor->ano;
            i->combustivel = menor->combustivel;
            i->cor = menor->cor;
            i->direcao = menor->direcao;
            i->km = menor->km;
            i->porta = menor->porta;
            i->tipo = menor->tipo;
            i->pot_motor = menor->pot_motor;
            i->direcao = menor->direcao;
            
            menor->placa = aux->placa;
            menor->modelo = aux->modelo;
            menor->marca = aux->marca;
            menor->ano = aux->ano;
            menor->combustivel = aux->combustivel;
            menor->cor = aux->cor;
            menor->direcao = aux->direcao;
            menor->km = aux->km;
            menor->porta = aux->porta;
            menor->tipo = aux->tipo;
            menor->pot_motor = aux->pot_motor;
            menor->direcao = aux->direcao;
            
        }
    }
}

void insereOrd(tLista * ptlista,struct no_ elem_no){
	no* ptr = ptlista->lista;
        no* ant = ptlista->lista;
        no* p;
        p = new(no);
        p->modelo = elem_no.modelo;
        p->marca = elem_no.marca;
        p->tipo = elem_no.tipo;
        p->ano = elem_no.ano ;
        p->km = elem_no.km;
        p->pot_motor = elem_no.pot_motor;
        p->combustivel = elem_no.combustivel;
        p->cambio = elem_no.cambio;
        p->direcao = elem_no.direcao;
        p->cor = elem_no.cor;
        p->porta = elem_no.porta;
        p->placa = elem_no.placa;
        if (ptlista->tam == 0){
            p->prox = ptlista->lista;
            ptlista->lista = p;
            ptlista->tam++;
        }
        else if(ptlista->tam ==1){
            if(elem_no.placa < ptr->placa){ 
                p->prox = ptlista->lista;
                ptlista->lista = p;
                ptlista->tam++;
            }else{
                p->prox = NULL;
                ptr->prox = p;
                ptlista->tam++;
            }
        }
        else{
            while(ptr!=NULL && elem_no.placa > ptr->placa){
                ant = ptr;
                ptr = ptr->prox;
                
            }
            if(elem_no.placa == ant->placa){ // se [e igual 
                    cout<<"Ja existe carro com essa placa no BD"<<endl;
            }else if(ptr==NULL){ //insere no fim
                p->prox = ptr;
                ant->prox = p;
                ptlista->tam++;

            }else if(elem_no.placa < ant->placa){ // insere no inicio
                p->prox = ptlista->lista;
                ptlista->lista = p;
                ptlista->tam++;
            }
            else{ // insere no meio
                ant->prox = p;
                p->prox = ptr;
                ptlista->tam++;
            }
        }
}