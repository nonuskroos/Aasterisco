//
//  main.cpp
//  ProcuraAasterisco
//
//  Created by Nuno Cruz on 22/02/18.
//  Copyright © 2018 Nuno Cruz. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// Estrutura possibidade expansão

struct	Vizinho
{
    string	Nome;
    int	Distancia;
};


//Informacao necessaria do nó para aplicar o algoritmo de procura A*

class	Cidade
{
    public :
    
    vector<Vizinho>::iterator	NumeroVizinho;
    vector<Vizinho>		Vizinhos;
    
    string				Nome;
    string				CaminhoAcumulado;
    int				DistanciaAcumulada;
    int				DistanciaEmLinhaRecta;
    
    Cidade();
    Cidade(string, int);
    
    void	AdicionarVizinho	(string, int);
};

//Construtor Cidade não inicializada

Cidade::Cidade()
{
    Nome="";
    NumeroVizinho=Vizinhos.begin();
    CaminhoAcumulado="";
    DistanciaAcumulada=0;
    DistanciaEmLinhaRecta=0;
}


//Construtor Cidade Inicializada

Cidade::Cidade(string nome, int elr)
{
    Nome=nome;
    NumeroVizinho=Vizinhos.begin();
    CaminhoAcumulado=nome;
    DistanciaAcumulada=0;
    DistanciaEmLinhaRecta=elr;
}

//AdicionarVizinho - requer adicionar nome e distancia à cidade

void	Cidade::AdicionarVizinho(string nome, int distancia)
{
    Vizinho	VizinhoTemporario;
    
    VizinhoTemporario.Nome		= nome;
    VizinhoTemporario.Distancia	= distancia;
    Vizinhos.push_back(VizinhoTemporario);
    NumeroVizinho=Vizinhos.begin();
}

vector<Cidade>	Cidades;
vector<Cidade>	Fronteira;


//Funcao usada para introduzir o mapa da roménia manualmente

void DesenharMapa()
{
    Cidade	CidadeTemporaria;
    //Dados para Arad
    
    CidadeTemporaria.Nome="Arad";
    CidadeTemporaria.DistanciaEmLinhaRecta=366;
    CidadeTemporaria.Vizinhos.clear();
    
    CidadeTemporaria.AdicionarVizinho("Zerind",75);
    CidadeTemporaria.AdicionarVizinho("Sibiu", 140);
    CidadeTemporaria.AdicionarVizinho("Timisoara",118);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Bucharest
    
    CidadeTemporaria.Nome="Bucharest";
    CidadeTemporaria.DistanciaEmLinhaRecta=0;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Giurgiu",90);
    CidadeTemporaria.AdicionarVizinho("Urziceni",85);
    CidadeTemporaria.AdicionarVizinho("Fagaras",211);
    CidadeTemporaria.AdicionarVizinho("Pitesti",101);
    Cidades.push_back(CidadeTemporaria);
    
    
    //Dados para Craiova
    
    CidadeTemporaria.Nome="Craiova";
    CidadeTemporaria.DistanciaEmLinhaRecta=160;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Pitesti",138);
    CidadeTemporaria.AdicionarVizinho("Rimnicu Vilcea",97);
    CidadeTemporaria.AdicionarVizinho("Drobeta",120);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Drobeta
    
    CidadeTemporaria.Nome="Drobeta";
    CidadeTemporaria.DistanciaEmLinhaRecta=242;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Craiova",120);
    CidadeTemporaria.AdicionarVizinho("Mehadia",75);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Eforie
    
    CidadeTemporaria.Nome="Eforie";
    CidadeTemporaria.DistanciaEmLinhaRecta=161;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Hirsova",86);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Fagaras
    
    CidadeTemporaria.Nome="Fagaras";
    CidadeTemporaria.DistanciaEmLinhaRecta=176;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Bucharest",211);
    CidadeTemporaria.AdicionarVizinho("Sibiu",99);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Giurgiu
    
    CidadeTemporaria.Nome="Giurgiu";
    CidadeTemporaria.DistanciaEmLinhaRecta=77;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Bucharest",90);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Hirsova
    
    CidadeTemporaria.Nome="Hirsova";
    CidadeTemporaria.DistanciaEmLinhaRecta=151;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Eforie",86);
    CidadeTemporaria.AdicionarVizinho("Uriceni",98);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Iasi
    
    CidadeTemporaria.Nome="Iasi";
    CidadeTemporaria.DistanciaEmLinhaRecta=226;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Valsui",92);
    CidadeTemporaria.AdicionarVizinho("Neamt",87);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Lugoj
    
    CidadeTemporaria.Nome="Lugoj";
    CidadeTemporaria.DistanciaEmLinhaRecta=244;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Mehadia",70);
    CidadeTemporaria.AdicionarVizinho("Timisoara",111);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Mehadia
    
    CidadeTemporaria.Nome="Mehadia";
    CidadeTemporaria.DistanciaEmLinhaRecta=241;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Drobeta",75);
    CidadeTemporaria.AdicionarVizinho("Lugoj",70);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Neamt
    
    CidadeTemporaria.Nome="Neamt";
    CidadeTemporaria.DistanciaEmLinhaRecta=234;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Iasi",87);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Oradea
    
    CidadeTemporaria.Nome="Oradea";
    CidadeTemporaria.DistanciaEmLinhaRecta=380;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Zerind",71);
    CidadeTemporaria.AdicionarVizinho("Sibiu",151);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Pitesti
    
    CidadeTemporaria.Nome="Pitesti";
    CidadeTemporaria.DistanciaEmLinhaRecta=100;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Bucharest",101);
    CidadeTemporaria.AdicionarVizinho("Rimnicu Vilcea",97);
    CidadeTemporaria.AdicionarVizinho("Craiova",138);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Rimnicu Vilcea
    
    CidadeTemporaria.Nome="Rimnicu Vilcea";
    CidadeTemporaria.DistanciaEmLinhaRecta=193;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Pitesti",97);
    CidadeTemporaria.AdicionarVizinho("Sibiu",80);
    CidadeTemporaria.AdicionarVizinho("Craiova",146);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Sibiu
    
    CidadeTemporaria.Nome="Sibiu";
    CidadeTemporaria.DistanciaEmLinhaRecta=253;
    CidadeTemporaria.Vizinhos.clear();
    
    CidadeTemporaria.AdicionarVizinho("Rimnicu Vilcea",80);
    CidadeTemporaria.AdicionarVizinho("Fagaras",99);
    CidadeTemporaria.AdicionarVizinho("Oradea",151);
    CidadeTemporaria.AdicionarVizinho("Arad",140);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Timsoara
    
    CidadeTemporaria.Nome="Timisoara";
    CidadeTemporaria.DistanciaEmLinhaRecta=329;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Lugoj",70);
    CidadeTemporaria.AdicionarVizinho("Arad",118);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Urziceni
    
    CidadeTemporaria.Nome="Urziceni";
    CidadeTemporaria.DistanciaEmLinhaRecta=80;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Hirsova",98);
    CidadeTemporaria.AdicionarVizinho("Bucharest",85);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Valusi
    
    CidadeTemporaria.Nome="Valsui";
    CidadeTemporaria.DistanciaEmLinhaRecta=199;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Iasi",92);
    CidadeTemporaria.AdicionarVizinho("Urziceni",142);
    Cidades.push_back(CidadeTemporaria);
    
    //Dados para Zerind
    
    CidadeTemporaria.Nome="Zerind";
    CidadeTemporaria.DistanciaEmLinhaRecta=374;
    CidadeTemporaria.Vizinhos.clear();
    CidadeTemporaria.AdicionarVizinho("Oradea",71);
    CidadeTemporaria.AdicionarVizinho("Arad",75);
    Cidades.push_back(CidadeTemporaria);
}


bool LigarCidadeFilha(Vizinho,Cidade*);

void DesenharMapa();

Cidade EncontrarCaminhoMaisCurto(int *DistanciaMaisCurta);

bool ProcuraAasterisco(string,string);


//EncontrarCaminhoMaisCurto - com base na distancia ao destino

Cidade	EncontrarCaminhoMaisCurto(int *DistanciaMaisCurta)
{
    vector<Cidade>::iterator	NumeroFronteira;
    vector<Cidade>::iterator	NumeroNoMaisBaixo;
    
    Cidade	CidadeAtual;
    
    NumeroFronteira=Fronteira.begin();
    CidadeAtual=*NumeroFronteira;
    *DistanciaMaisCurta=CidadeAtual.DistanciaAcumulada +
    CidadeAtual.DistanciaEmLinhaRecta;
    NumeroNoMaisBaixo=NumeroFronteira;
    NumeroFronteira++;
    
    while(NumeroFronteira<Fronteira.end())
    {
        CidadeAtual=*NumeroFronteira;
        if(*DistanciaMaisCurta>CidadeAtual.DistanciaAcumulada +
           CidadeAtual.DistanciaEmLinhaRecta)
        {
            *DistanciaMaisCurta=CidadeAtual.DistanciaAcumulada +
            CidadeAtual.DistanciaEmLinhaRecta;
            NumeroNoMaisBaixo=NumeroFronteira;
        }
        NumeroFronteira++;
    }
    CidadeAtual=*NumeroNoMaisBaixo;
    Fronteira.erase(NumeroNoMaisBaixo);
    return CidadeAtual;
}

//Funcao LigarCidadeFilha

bool	LigarCidadeFilha (Vizinho Familia, Cidade* CidadeFilha)
{
    vector<Cidade>::iterator	NumeroCidade;
    
    for(NumeroCidade=Cidades.begin();NumeroCidade<Cidades.end();NumeroCidade++)
    {
        *CidadeFilha=*NumeroCidade;
        if((CidadeFilha->Nome) == Familia.Nome)
            return true;
    }
    return false;
}



//Funcao Heuristica A*

bool	ProcuraAasterisco(string NomePartida, string NomeChegada)
{
    vector<Cidade>::iterator	NumeroCidade;
    
    Cidade		CidadeAtual;
    Cidade		CidadePartida;
    Cidade		CidadeFilha;
    
    Vizinho	VizinhoAtual;
    
    bool		CidadePartidaEncontrada=false;
    bool		DestinoEncontrado=false;
    
    int		DistanciaMinimaPossivel=0;
    int		DistanciaDestino=0;
    int     NumeroNiveis=-1;
    int     NumeroIteracoes;
    
    string		CaminhoDestino;
    
    if(NomePartida=="" || NomeChegada=="") return false;
    
    //Procurar pelo ponto de partida
    
    for(NumeroCidade=Cidades.begin();NumeroCidade<Cidades.end();NumeroCidade++)
    {
        CidadeAtual=*NumeroCidade;
        if(CidadeAtual.Nome==NomePartida)
        {
            CidadePartida=CidadeAtual;
            CidadePartidaEncontrada=true;
            CidadePartida.CaminhoAcumulado=NomePartida;
        }
    }
    
    if(CidadePartidaEncontrada==false) return false;
    
    Fronteira.push_back(CidadePartida);
    
    cout<<"\nA gravar processo de procura:\n"<<"\nCidade de Partida: "<<
    NomePartida<<"\t Cidade de Chegada: "<<NomeChegada<<"\n"<<endl;
    
    //Procurar nova cidade na Fronteira
    
    while(!Fronteira.empty() && (DistanciaDestino>DistanciaMinimaPossivel || DestinoEncontrado==false))
    {
        NumeroNiveis=NumeroNiveis+1;
        cout<<"Nível: "<<NumeroNiveis<<endl;
        
        CidadeAtual=EncontrarCaminhoMaisCurto(&DistanciaMinimaPossivel);
        if(DistanciaDestino>DistanciaMinimaPossivel || DestinoEncontrado==false)
        {
            for(CidadeAtual.NumeroVizinho=CidadeAtual.Vizinhos.begin();
                CidadeAtual.NumeroVizinho<CidadeAtual.Vizinhos.end();
                CidadeAtual.NumeroVizinho++)
            {
                VizinhoAtual=*CidadeAtual.NumeroVizinho;
                if(LigarCidadeFilha(VizinhoAtual, &CidadeFilha)==false)
                {
                    cout<<"Cidade seguinte não encontrada - Fim de Procura\n";
                    return false;
                }
                
                CidadeFilha.CaminhoAcumulado=CidadeAtual.CaminhoAcumulado +
                " - " + CidadeFilha.Nome;
                CidadeFilha.DistanciaAcumulada=CidadeAtual.DistanciaAcumulada +
                VizinhoAtual.Distancia;
                //teste1
                //cout<<CidadeFilha.CaminhoAcumulado << " " << CidadeFilha.Nome << " " << CidadeFilha.DistanciaEmLinhaRecta<<" " << CidadeFilha.DistanciaAcumulada <<endl;
                //teste2
                //cout<<VizinhoAtual.Nome << " " << VizinhoAtual.Distancia<<endl;
                cout<<"Caminho Atual Expandido: "<<CidadeFilha.CaminhoAcumulado<<
                " Distância: "<<CidadeFilha.DistanciaAcumulada + CidadeFilha.DistanciaEmLinhaRecta<<endl;
                
                if(CidadeFilha.Nome==NomeChegada && CidadeFilha.DistanciaEmLinhaRecta==0)
                {
                    DistanciaDestino=CidadeFilha.DistanciaAcumulada;
                    CaminhoDestino=CidadeFilha.CaminhoAcumulado;
                    cout<<"\nCaminho Destino: "<<CaminhoDestino<<" Distância: "<<
                    DistanciaDestino<< "\n "<<endl;
                    DestinoEncontrado=true;
                }
                Fronteira.push_back(CidadeFilha);
                
                
            }
            
        }
    }
    NumeroIteracoes = NumeroNiveis+1;
    cout<<"\nNúmero de Iterações: "<< NumeroIteracoes<<endl;
    cout<<"\n\nO melhor caminho é:\n";
    cout<<CaminhoDestino<<"\t Distância: "<<DistanciaDestino<<endl;
    cout<<"\nAnálise Completa! \nAlgoritmo Procura A* - TP04 IA ESTG-IPG Nuno Cruz nº1006699\n";
    return true;
}


int	main(int argc, const char * argv[])
{
    
    DesenharMapa();
    ProcuraAasterisco("Arad", "Bucharest");
    return 0;
}


