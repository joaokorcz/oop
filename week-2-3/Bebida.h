/*
Participantes:
João Otavio Martini Korczovei - BCC - 790913
Leticia Bossatto Marchezi - BCC - 791003
Luana de Queiroz Garcia - BCC - 740953
Luís Augusto Simas do Nascimento - BCC - 790828
Vitor Caligaris Figueira - ENC - 790743

Objetivo: Arquivo com interfaces dos métodos de Bebida
*/

#include <string.h>

using namespace std;

// definição classe bebida
class Bebida {
  // Atributos
  private:
    string sabor, tipo, marca; 
    int quantidade;
    bool aberto;

  // Métodos
  public:
    // Construtores
    Bebida();
    Bebida(string, string, string, int, bool);
    
    // Getters
    string getSabor();
    string getTipo();
    string getMarca();
    int getQuantidade();
    bool isAberto();

    // Setters
    void setSabor(string);
    void setTipo(string);
    void setMarca(string);
    void setQuantidade(int);
    
    // Ações
    void abrir();
    void fechar();
    bool isVazio();
    void beber(int);
    void imprimeBebida();
};