/* 
 * File:   main.cpp
 * Author: Parisi, Vitor
 * RA: 2016.1.08.037
 * Created on 11 de Março de 2021, 16:34
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "lista.h"

using namespace std;

tLista * lista1;
tListaGen * listaT, *listaAnoP, *listaK, *listaP, *listaC, *listaM;
elem_no elem;
int porta, km, ano;
string modelo, marca, potencia, combustivel;

void le_arq() {
    //std::string modelo, marca, pot_motor, combustivel, cambio, direcao, cor, placa, nome_arq, tipo; 
    //int ano, porta, km; 

    ifstream arq("veiculos.txt");
    if (arq.is_open()) {

        while (!arq.eof()) {
            arq >> elem.modelo;
            arq >> elem.marca;
            arq >> elem.tipo;
            arq >> elem.ano;
            arq >> elem.km;
            arq >> elem.pot_motor;
            arq >> elem.combustivel;
            arq >> elem.cambio;
            arq >> elem.direcao;
            arq >> elem.cor;
            arq >> elem.porta;
            arq >> elem.placa;

            //insere_inicio(lista1, modelo, marca, tipo, ano, km, pot_motor, combustivel, cambio, direcao, cor, porta, placa );
            //insere_fim(lista1, modelo, marca, tipo, ano, km, pot_motor, combustivel, cambio, direcao, cor, porta, placa );
            insereOrd(lista1, elem);
        }

        arq.close();



    } else {

        cout << "Não foi possivel ler as informações. \n";
    }
}

void insere() {

    cout << "+------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|--------------------------------------------------------- INSERIR ------------------------------------------------------------------------|" << endl;
    cout << "+------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|--- PLACA --- MODELO  ---  MARCA --- TIPO --- ANO --- KM --- POTERNCIA DO MOTOR --- COMBUSTIVEL -- CAMBIO --- DIRECAO --- COR --- PORTA ---|" << endl;
    cout << "|----------------- PLACA -> ";
    cin >> elem.placa;
    cout << "|---------------- MODELO -> ";
    cin >> elem.modelo;
    cout << "|----------------- MARCA -> ";
    cin >> elem.marca;
    cout << "|------------------ TIPO -> ";
    cin >> elem.tipo;
    cout << "|------------------- ANO -> ";
    cin >> elem.ano;
    cout << "|-------------------- KM -> ";
    cin >> elem.km;
    cout << "|---- POTERNCIA DO MOTOR -> ";
    cin >> elem.pot_motor;
    cout << "|----------- COMBUSTIVEL -> ";
    cin >> elem.combustivel;
    cout << "|---------------- CAMBIO -> ";
    cin >> elem.cambio;
    cout << "|--------------- DIRECAO -> ";
    cin >> elem.direcao;
    cout << "|------------------- COR -> ";
    cin >> elem.cor;
    cout << "|----------------- PORTA -> ";
    cin >> elem.porta;
    insereOrd(lista1, elem);
    cout << "INSERIDO:" << endl;
    cout << "|--- PLACA --- MODELO  ---  MARCA --- TIPO --- ANO --- KM --- POTERNCIA DO MOTOR --- COMBUSTIVEL -- CAMBIO --- DIRECAO --- COR --- PORTA ---|" << endl;
    cout << elem.placa << "\t" << elem.modelo << "\t" << elem.marca << "\t" << elem.tipo << "\t" << elem.ano << "\t" << elem.km << "\t" << elem.pot_motor << "\t" << elem.combustivel << "\t" << elem.cambio << "\t" << elem.direcao << "\t" << elem.cor << "\t" << elem.porta << endl;
    cout << endl << endl;
    no * nob = busca(lista1, elem.placa);
    if (listaP != NULL) {
        if (elem.porta == porta) 
            insere_inicio_Gen(nob, listaP);
    }
    if (listaK != NULL) {
        if (elem.km <= km) 
            insere_inicio_Gen(nob, listaK);
    }
    if (listaAnoP != NULL) {
        if (elem.ano == ano && elem.pot_motor == potencia) 
            insere_inicio_Gen(nob, listaAnoP);
    }
    if (listaT != NULL) {
        if (elem.marca == marca) 
            insere_inicio_Gen(nob, listaT);
    }
    if (listaM != NULL) {
        if (elem.modelo == modelo) 
            insere_inicio_Gen(nob, listaM);
    }
    if (listaC != NULL) {
        if (elem.combustivel == combustivel) 
            insere_inicio_Gen(nob, listaC);
    }

}

void remove() {
    string placa, resposta;
    cout << "+------------------------------------------+" << endl;
    cout << "|-----------------REMOVER------------------|" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|----- Digite a placa a ser removida ------|" << endl;
    cout << "+------------------------------------------+" << endl;
    cin>>placa;

    no* busc = busca(lista1, placa);
    if (busc == NULL) {
        cout << "NUNHUM CARRO ENCONTRADO COM ESSA PLACA" << endl << endl << endl;
    } else {
        cout << "|--- PLACA --- MODELO  ---  MARCA --- TIPO --- ANO --- KM --- POTERNCIA DO MOTOR --- COMBUSTIVEL -- CAMBIO --- DIRECAO --- COR --- PORTA ---|" << endl;
        cout << "|---" << busc->placa << "---" << busc->modelo << "--------" << busc->marca << "-------" << busc->tipo << "-----" << busc->ano << "----------" << busc->km << "--------------" << busc->pot_motor << "-----" << busc->combustivel << "---" << busc->cambio << "---" << busc->direcao << "---" << busc->cor << "----" << busc->porta << "---|" << endl;
        cout << "|---- Deseja realmente remover o carro (Y / N)" << endl;
        cin>>resposta;

        if (resposta == "Y" || resposta == "y") {
            no* removido = remove(lista1, placa);
            cout << "Veiculo removido com a placa -> " << removido->placa << endl << endl << endl;
            if(listaP != NULL){
                if (removido->porta == porta)
                    removeGen(listaP, placa);
            }
            if(listaK != NULL){
                if (removido->km == km)
                    removeGen(listaK, placa);
            }
            if(listaAnoP != NULL){
                if (removido->ano == ano && removido->pot_motor == potencia)
                    removeGen(listaAnoP, placa);
            }
            if(listaT != NULL){
                if (removido->marca == marca)
                    removeGen(listaT, placa);
            }
            if(listaM != NULL){
                if (removido->modelo == modelo)
                    removeGen(listaM, placa);
            }
            if(listaC != NULL){
                if (removido->combustivel == combustivel)
                    removeGen(listaC, placa);
            }
        }
    }

}

void busca() {
    char op = '1';

    while (op != '0') {
        cout << "+----------------------------------------------+" << endl;
        cout << "|------------- CRIAR BUSCAS -------------------|" << endl;
        cout << "|-------- 1 - NUMERO de PORTAS ----------------|" << endl;
        cout << "|-------- 2 - KILOMETRAGEM MENOR QUE ----------|" << endl;
        cout << "|-------- 3 - ANO E POTENCIA DO MOTOR ---------|" << endl;
        cout << "|-------- 4 - MARCA ---------------------------|" << endl;
        cout << "|-------- 5 - MODELO --------------------------|" << endl;
        cout << "|-------- 6 - COMBUSTIVEL ---------------------|" << endl;
        cout << "|-------- 0 - SAIR ----------------------------|" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << "|----- Digite 1, 2, 3, 4, 5, 6 ou 0 -----------|" << endl;
        cout << "+----------------------------------------------+" << endl;
        cin>>op;

        switch (op) {
            case '1':
                cout << "Digite a quantidade de portas -> ";
                cin>>porta;
                if (listaP == NULL) {
                    listaP = inicia_listaGen();
                    buscaInsPorta(lista1, listaP, porta);
                } else if (listaP->listaGen->listaGen->porta == porta)
                    cout << "Ja existe uma busca com numero de portas = " << porta << endl;
                else {
                    listaP = inicia_listaGen();
                    buscaInsPorta(lista1, listaP, porta);
                }
                imprimeGen(listaP);
                break;
            case '2':
                cout << "Digite a Kilometragem -> ";
                cin>>km;
                if (listaK == NULL) {
                    listaK = inicia_listaGen();
                    buscaInsKm(lista1, listaK, km);
                } else if (listaK->listaGen->listaGen->km == km)
                    cout << "Ja existe uma busca com numero de kilometrage = " << km << endl;
                else {
                    listaK = inicia_listaGen();
                    buscaInsKm(lista1, listaK, km);
                }
                imprimeGen(listaK);

                break;
            case '3':
                cout << "Digite a Ano -> ";
                cin>>ano;
                cout << "Digite a Potencia do motor -> ";
                cin>>potencia;
                if (listaAnoP == NULL) {
                    listaAnoP = inicia_listaGen();
                    buscaInsAnoP(lista1, listaAnoP, ano, potencia);
                } else if (listaAnoP->listaGen->listaGen->ano == ano && listaAnoP->listaGen->listaGen->pot_motor == potencia )
                    cout << "Ja existe uma busca com ano = " << km << " e potencia = "<<potencia<<endl;
                else {
                    listaAnoP = inicia_listaGen();
                    buscaInsAnoP(lista1, listaAnoP, ano, potencia);
                }
                imprimeGen(listaAnoP);

                break;
            case '4':
                cout << "Digite a Marca -> ";
                cin>>marca;
                if (listaT == NULL) {
                    listaT = inicia_listaGen();
                    buscaInsMarca(lista1, listaT, marca);
                } else if (listaT->listaGen->listaGen->marca == marca )
                    cout << "Ja existe uma busca com a marca = " << marca << endl;
                else {
                    listaT = inicia_listaGen();
                    buscaInsMarca(lista1, listaT, marca);
                }
                imprimeGen(listaT);

                break;
            case '5':
                cout << "Digite o Modelo -> ";
                cin>>modelo;
                if (listaM == NULL) {
                    listaM = inicia_listaGen();
                    buscaInsMod(lista1, listaM, modelo);
                } else if (listaM->listaGen->listaGen->marca == modelo )
                    cout << "Ja existe uma busca com a marca = " << modelo << endl;
                else {
                    listaM = inicia_listaGen();
                    buscaInsMod(lista1, listaM, modelo);
                }
                imprimeGen(listaM);

                break;
            case '6':
                cout << "Digite o combustivel -> ";
                cin>>combustivel;
                if (listaC == NULL) {
                    listaC = inicia_listaGen();
                buscaInsComb(lista1, listaC, combustivel);
                } else if (listaC->listaGen->listaGen->combustivel == combustivel )
                    cout << "Ja existe uma busca com o combustivel = " << combustivel << endl;
                else {
                    listaC = inicia_listaGen();
                buscaInsComb(lista1, listaC, combustivel);
                }
                imprimeGen(listaC);
                break;
        }
    }
}

char relatorio() {
    char ope = '1', cont = '1';
    while (ope != '0') {
        cout << "+----------------------------------------------+" << endl;
        cout << "|------------- IMPRIME ------------------------|" << endl;
        cout << "|-------- 1 - PRINCIAL ORDEM CRESCENTE --------|" << endl;
        cout << "|-------- 2 - PRINCIAL ORDEM DESCRECENTE ------|" << endl;
        cout << "|-------- 3 - NUMERO de PORTAS ----------------|" << endl;
        cout << "|-------- 4 - KILOMETRAGEM MENOR QUE ----------|" << endl;
        cout << "|-------- 5 - ANO E POTENCIA DO MOTOR ---------|" << endl;
        cout << "|-------- 6 - MARCA ---------------------------|" << endl;
        cout << "|-------- 7 - MODELO --------------------------|" << endl;
        cout << "|-------- 8 - COMBUSTIVEL ---------------------|" << endl;
        cout << "|-------- 0 - SAIR ----------------------------|" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << "|----- Digite 1, 2, 3, ..., 8 ou 0 ------------|" << endl;
        cout << "+----------------------------------------------+" << endl;
        cin>>ope;

        switch (ope) {
            case '1':
                if (cont == '2') {
                    cout << cont << endl;
                    ordenaPlacaC(lista1);
                    imprime(lista1);
                } else {
                    cout << ope << endl;
                    imprime(lista1);
                }
                break;
            case '2':
                ordenaPlacaD(lista1);
                imprime(lista1);
                break;
            case '3':
                if (listaP == NULL)
                    cout << "Não existe busca por esse criterio ainda" << endl << endl;
                else
                    imprimeGen(listaP);
                break;
            case '4':
                if (listaK == NULL)
                    cout << "Não existe busca por esse criterio ainda" << endl << endl;
                else
                    imprimeGen(listaK);
                break;
            case '5':
                if (listaAnoP == NULL)
                    cout << "Não existe busca por esse criterio ainda" << endl << endl;
                else
                    imprimeGen(listaAnoP);
                break;
            case '6':
                if (listaT == NULL)
                    cout << "Não existe busca por esse criterio ainda" << endl << endl;
                else
                    imprimeGen(listaT);
                break;
            case '7':
                if (listaM == NULL)
                    cout << "Não existe busca por esse criterio ainda" << endl << endl;
                else
                    imprimeGen(listaM);
                break;
            case '8':
                if (listaC == NULL)
                    cout << "Não existe busca por esse criterio ainda" << endl << endl;
                else
                    imprimeGen(listaC);
                break;
        }
        if (ope != '0') {
            cont = ope;
        }

    }
    return cont;
}

char menu() {
    char op = '7', ope = '1';
    while (op != '0') {
        cout << "+--------------------------------+" << endl;
        cout << "|--------------MENU--------------|" << endl;
        cout << "|-------- 1 - Inclusão ----------|" << endl;
        cout << "|-------- 2 - Exclusão ----------|" << endl;
        cout << "|-------- 3 - Criar Busca -------|" << endl;
        cout << "|-------- 4 - Relatorio ---------|" << endl;
        cout << "|-------- 0 - Salvar e Sair -----|" << endl;
        cout << "+--------------------------------+" << endl;
        cout << "|----- Digite 1, 2, 3 ou 4 ------|" << endl;
        cout << "+--------------------------------+" << endl;
        cin>>op;
        cout << endl << endl << endl;
        switch (op) {
            case '1':
                insere();
                break;
            case '2':
                remove();
                break;
            case '3':
                busca();
                break;
            case '4':
                ope = relatorio();
                break;
            default:
                cout << "ERRO!!!   Digite 1, 2, 3, 4 ou 0" << endl;
                break;
        }
    }
    return ope;
}

int main() {
    char ope;
    lista1 = inicia_lista();

    le_arq();

    ope = menu();
    if (ope == '1') {
        salva_arqOrd(lista1, "veiculosOrdC.txt");
        ordenaPlacaD(lista1);
        salva_arqOrd(lista1, "veiculosOrdD.txt");
    } else {
        salva_arqOrd(lista1, "veiculosOrdD.txt");
        ordenaPlacaC(lista1);
        salva_arqOrd(lista1, "veiculosOrdC.txt");
    }

    if (listaT != NULL) {
        salva_arqGen(listaT, "veiculosMarcaX.txt");
        listaT = encerra_listaGen(listaT);
    }
    if (listaAnoP != NULL) {
        salva_arqGen(listaAnoP, "veiculosAnoXPotenciaX.txt");
        listaAnoP = encerra_listaGen(listaAnoP);
    }
    if (listaK != NULL) {
        salva_arqGen(listaK, "veiculosKilometragemX.txt");
        listaK = encerra_listaGen(listaK);
    }
    if (listaP != NULL) {
        salva_arqGen(listaP, "veiculosPortaX.txt");
        listaP = encerra_listaGen(listaP);
    }
    if (listaC != NULL) {
        salva_arqGen(listaC, "veiculosCombusX.txt");
        listaC = encerra_listaGen(listaC);
    }
    if (listaM != NULL) {
        salva_arqGen(listaM, "veiculosModeloX.txt");
        listaM = encerra_listaGen(listaM);
    }
    lista1 = encerra_lista(lista1);
    return (EXIT_SUCCESS);
}
