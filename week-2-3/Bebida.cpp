/*
Participantes:
João Otavio Martini Korczovei - BCC - 790913
Leticia Bossatto Marchezi - BCC - 791003
Luana de Queiroz Garcia - BCC - 740953
Luís Augusto Simas do Nascimento - BCC - 790828
Vitor Caligaris Figueira - ENC - 790743

Objetivo: Arquivo com os métodos de Bebida
*/

#include <iostream>
#include <string.h>
#include "Bebida.h"

using namespace std;

//Construtores
Bebida::Bebida(){
  //Construtor sem parametros, atributos pre definidos.
  sabor = "";
  tipo = "";
  marca = "";
  quantidade = 0;
  aberto = false;
}

Bebida::Bebida(string s, string t, string m, int q, bool a){
  //Construtor com parametros, atributos definidos pelo programador.
  setSabor(s);
  setTipo(t);
  setMarca(m);
  setQuantidade(q);
  aberto = a;
}

//Getters
string Bebida::getSabor(){ //Obter o sabor.
  return sabor;
}

string Bebida::getTipo(){ //Obter o  tipo.
  return tipo;
}

string Bebida::getMarca(){ //Obter a marca.
  return marca;
}

int Bebida::getQuantidade(){ //Obter a quantidade.
  return quantidade;
}

bool Bebida::isAberto(){ //Obter o estado (aberto/fechado)
  return aberto;
}

//setters
void Bebida::setSabor(string s){ //Definir sabor.
  sabor = s;
}

void Bebida::setTipo(string t){ //Definir tipo.
  tipo = t;
}

void Bebida::setMarca(string m){ //Definir marca.
  marca = m;
}

void Bebida::setQuantidade(int q){ //Definir quantidade.
  if(q >= 0){ //Caso a quantidade no parametro for positiva ou nula.
    quantidade = q; //Atributo quantidade e definido.
  }else{ //Caso a quantidade seja negativa.
    cout << marca << ": Erro ao atribuir quantidade: O valor deve ser maior que 0." << endl; //Mensagem de erro.
  }
}

// Ações
void Bebida::abrir(){//Metodo para abrir o recipiente.
  if (aberto){//Caso ja esteja aberto.
    cout <<  marca << " já está aberto!" << endl << endl;//Informe.
  }else{//Caso esteja fechado.
    aberto = true;//Abrir a bebida
    cout << marca << " aberto com sucesso" << endl << endl;//Informe.
  }
}

void Bebida::fechar(){//Metodo para fechar o recipiente.
  if (aberto){//Caso esteja aberto.
    aberto = false;//Fechar o recipiente.
    cout <<   marca <<" fechado com sucesso" << endl << endl;//Informe.
  }else{//Caso ja esteja fechado.
    cout << marca <<" já está fechado!" << endl << endl;//Informe.
  }
}

bool Bebida::isVazio(){//Metodo para checar se o recipiente esta vazio.
  return (quantidade) ? false : true;//Se estiver vazio retorna true caso tiver algum volume retorna false.
}

void Bebida::beber(int q){//Metodo para beber a bebida.
  cout << "Tentando beber " << marca << "..." << endl;
  if(q<=0){
    cout << "A quantidade não é válida " << endl << endl;
  }
  else{
    if(aberto){//Checar se o recipiente esta aberto.
      if(!isVazio()){//Se nao estiver vazio.
        if(quantidade - q < 0){//Se a quantidade desejada for maior que a dentro do recipiente.
          cout << marca << " não tem " << q << ", mas bebeu " << quantidade << " e acabou! (ml)" << endl << endl;//Informe que nao tem a quantidade pedida.  
          setQuantidade(0);//Beba o restante
        } else {//Se a quantidade desejada for menor ou igual a do recipiente.
          setQuantidade(quantidade-q);//Beba a quantidade desejada.
          cout << "Você bebeu " << q << " de "<< marca <<" e ainda tem " << quantidade << "! (ml)" << endl << endl;//Informe que a quantidade foi bebida e quanto resta no recipiente.
        }
      }else{//Se ja estiver vazio.
        cout << marca << " já acabou :(" << endl << endl;//Informe que ja acabou.
      }
    } else {//Se a bebida ja estiver fechada.  
      cout << marca << " está fechada, tem que abrir pra beber!" << endl << endl;
    }//Informe que a bebida deve ser aberta antes de consumida.
  }
}

void Bebida::imprimeBebida(){//Metodo para imprimir a bebida.
  cout << "Marca: " << marca << endl;//Imprime marca da bebida.
  cout << "Sabor: " << sabor << endl;//Imprime sabor da bebida.
  cout << "Tipo: " << tipo << endl;//Imprime tipo da bebida.
  cout << "Quantidade: " << quantidade << "ml" << endl;//Imprime quantidade da bebida.
  cout << "Aberto? " << (aberto ? "Sim" : "Não") << endl << endl;//Imprime estado da bebida.
}