/*
Participantes:
João Otavio Martini Korczovei - BCC - 790913
Leticia Bossatto Marchezi - BCC - 791003
Luana de Queiroz Garcia - BCC - 740953
Luís Augusto Simas do Nascimento - BCC - 790828
Vitor Caligaris Figueira - ENC - 790743

Objetivo: Arquivo de teste da classe Bebida
*/

#include <iostream>
#include <string.h>
#include "Bebida.cpp"

using namespace std;

// Exibir menu na tela
int menu(){//Procedimento para gerar um menu de escolhas.
  int opcao;

  do {//Repetir o codigo enquanto a opcao esta entre 1 e 6. 
    cout << "1. Informações bebidas" << endl;//Selecionar 1 para obter informacoes da bebida.
    cout << "2. Abrir" << endl;//Selecionar 2 para abrir a bebida.
    cout << "3. Fechar" << endl;//Selecionar 3 para fechar a bebida.
    cout << "4. Está vazio?" << endl;//Selecionar 4 para checar se esta vazio.
    cout << "5. Beber" << endl;//Selecionar 5 para beber uma quantidade.
    cout << "6. Sair " << endl;//Selecionar 6 para sair.
    cout << "Informe a opcao: ";
    cin >> opcao;
    cout << endl;
  } while (opcao < 1 || opcao > 6);

  return opcao;
}
// Funcao principal
int main() {
  int qtBeber, opcao;

  // Instanciando dois objetos da classe Bebida
  Bebida sprite("limao", "refrigerante", "Sprite", 1000, false);
  Bebida guarana("guarana","refrigerante","Guarana Antarctica", 350, true);
  
  // Chama a funcao de mostrar menu na tela
  opcao = menu();

  while(opcao!=6){
    switch(opcao){
      case 1: // Mostra todas as informacoes das bebidas
        sprite.imprimeBebida();
        guarana.imprimeBebida();
        break;
      case 2: // Abre as bebidas
        sprite.abrir();
        guarana.abrir();
        break;
      case 3: // Fecha as bebidas
        sprite.fechar();
        guarana.fechar();
        break; 
      case 4: // Mostra se a bebida esta vazia
        if(sprite.isVazio()){
          cout << "Sprite esta vazio" << endl << endl;
        }else{
          cout << "Sprite nao esta vazio" << endl << endl;
        }
        if(guarana.isVazio()){
          cout << "Guaraná esta vazio" << endl << endl;
        }else{
          cout << "Guaraná não esta vazio" << endl << endl;
        }
        break;
      case 5: // Bebe 
        cout << "Informe quantos ml quer beber: ";
        cin >> qtBeber;
        cout << endl;
        sprite.beber(qtBeber);
        guarana.beber(qtBeber);
        break;
      case 6: // Encerrar programa
        cout << "Saindo do programa..." << endl;
        break;
      default: // Caso padrão (Opção inválida)
        cout << "Opção inválida" << endl;
    }
    opcao = menu();    
  }
}