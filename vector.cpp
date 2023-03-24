
#include <vector>
#include <iostream>

using namespace std;

class Matriz{
    private:
        //double _dados[20][20]; //um array precisa ter tamanhos definidos
        unsigned int _nlinhas;
        unsigned int _ncolunas;
        vector<vector<double> > _dados;
    public:
        Matriz(unsigned int nlinhas, unsigned int ncolunas){ //inciando a matriz com tudo = 0
            for (int linha = 0; linha < nlinhas; linha++){
                vector<double> dados_linhas;
                _dados.push_back(dados_linhas);

                for (int coluna = 0; coluna < ncolunas; coluna++){
                    _dados[linha].push_back(0);
                }
            }
            _nlinhas = nlinhas;
            _ncolunas = ncolunas;
        }

        void seta(int linha, int coluna, double valor){
            if (linha >= _nlinhas || coluna >= _ncolunas) {
                cout <<"Nao consigo setar";
            }
            _dados[linha][coluna] = valor;
        }

        Matriz soma(Matriz outra){
            if (outra._ncolunas != _ncolunas) {
                cout << "Nao da pra somar";
                return Matriz(0,0);
            }
            if (outra._nlinhas != _nlinhas) {
                cout << "Nao da pra somar";
                return Matriz(0,0);
            }

            Matriz retorno = Matriz(_nlinhas, _ncolunas);
            for (int linha = 0; linha < _nlinhas; linha++) {
                for (int coluna = 0; coluna < _ncolunas; coluna++) {
                    double soma = _dados[linha][coluna] + outra._dados[linha][coluna];
                    retorno._dados[linha][coluna] = soma;
                }
            }

        return retorno;
        }

        void imprimir(){
            for (int linha = 0; linha < _nlinhas; linha++) {
                for (int coluna = 0; coluna < _ncolunas; coluna++) {
                    cout << _dados[linha][coluna];
                }
                cout << endl;
            }
          cout << endl;
        }
};

int main(){
  Matriz m1 = Matriz(2,3);
  m1.imprimir();

  m1.seta(0, 0, 1);
  m1.seta(0, 1, 2);
  m1.seta(0, 2, 3);
  m1.seta(1, 0, 4);
  m1.seta(1, 1, 2);
  m1.seta(1, 2, 3);

  m1.imprimir();

  
  Matriz m2 = Matriz(2,3);
  m2.imprimir();

  m2.seta(0, 0, 1);
  m2.seta(0, 1, 1);
  m2.seta(0, 2, 1);
  m2.seta(1, 0, 1);
  m2.seta(1, 1, 1);
  m2.seta(1, 2, 1);

  m2.imprimir();


  Matriz m3 = m1.soma(m2);
  m3.imprimir();
}