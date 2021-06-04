/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lista.h
 * Author: paulo
 *
 * Created on January 26, 2021, 11:32 AM
 */

#ifndef LISTA_H
#define LISTA_H

typedef struct no_ {
	std::string modelo; 
        std::string marca; 
        std::string tipo; 
        int ano; 
        int km;
        std::string pot_motor; 
        std::string combustivel; 
        std::string cambio;
        std::string direcao; 
        std::string cor; 
        int porta; 
        std::string placa; 
	struct no_ * prox;  // ponteiro para o próximo nó da lista encadeada
} no, elem_no;

typedef struct {
	int tam;            //critério de busca da ordenação
	struct no_ * lista; // ponteiro para o próximo nó da lista encadeada
} tLista;



typedef struct noGen_{
    struct no_ *listaGen;
    struct noGen_ * prox;
}noGen;

typedef struct {
    int tam;
    struct noGen_ * listaGen;
}tListaGen;



tLista* inicia_lista();
tLista * encerra_lista(tLista * ptlista);

tListaGen* inicia_listaGen();
tListaGen * encerra_listaGen(tListaGen * ptlista);

no * busca(tLista * ptlista, std::string modelo);

void insere_inicio(tLista * ptlista, std::string modelo, std::string marca, std::string tipo, int ano, int km, std::string pot_motor, std::string combustivel, std::string cambio, std::string direcao, std::string cor, int porta, std::string placa);
no * remove_inicio(tLista * ptlista);

void insere_fim(tLista * ptlista, std::string modelo, std::string marca, std::string tipo, int ano, int km, std::string pot_motor, std::string combustivel, std::string cambio, std::string direcao, std::string cor, int porta, std::string placa);
no * remove_fim(tLista * ptlista);

no * remove(tLista * ptlista, std::string placa);
void removeGen(tListaGen * ptlista, std::string placa);

void ordenaPlacaC(tLista * ptlista);
void ordenaPlacaD(tLista * ptlista);

void insere_inicio_Gen(no * pno, tListaGen * ptlistagen);

void busca(tListaGen * lista1 , tListaGen * listaT, tListaGen *listaAnoP, tListaGen *listaK, tListaGen *listaP, tListaGen *listaC, tListaGen *listaM);

void buscaInsPorta(tLista * ptlista, tListaGen * ptlistagen,int porta);
void buscaInsKm(tLista * ptlista, tListaGen * ptlistagen,int km);
void buscaInsAnoP(tLista * ptlista, tListaGen * ptlistagen,int ano,std::string potencia);
void buscaInsMarca(tLista * ptlista, tListaGen * ptlistagen, std::string marca);
void buscaInsComb(tLista * ptlista, tListaGen * ptlistagen,std::string combustivel);
void buscaInsMod(tLista * ptlista, tListaGen * ptlistagen,std::string modelo);

void imprime(tLista * ptlista);
void imprimeGen(tListaGen * ptlistagen);

void salva_arqOrd(tLista * ptlista, std::string nome_arq);
void salva_arqGen(tListaGen * ptlistagen, std::string nome_arq);


void insereOrd(tLista * ptlista, struct no_ elem_no);


#endif /* LISTA_H */

