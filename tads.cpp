#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Discente{ //se fosse struct, eu poderia colocar coisas "na mao", entao colcoco como class
    private:
        string _nome;
        unsigned short _idade; //nao pode ter idade negativa
        unsigned int _matricula;
        vector<string> _materias; //o tipo vector vai crescendo
        double _cre; //o professor utiliza o "_" para quando as coisas sao privadas

    public:

        Discente(string nome, unsigned short idade, unsigned int matricula){ //, vector<string> materias){
            _nome = nome;
            _idade = idade;
            _matricula = matricula;
            //_materias = materias;
        } //construtor

        void adicionar_matricula(string disciplina){
        for (int i = 0; i < _materias.size(); i++ ) {
            if (_materias[i] == disciplina) {
                cout << "O aluno já está matriculado nessa materia!" << endl;
                return;
            }
        }
        _materias.push_back(disciplina);}

        void imprimir_materias(){
            for (int i = 0; i < _materias.size(); i++) {
                cout << _materias[i] << endl;
            }
        }

        string get_nome(){
            return  _nome;
        } //chamando o private para conseguir acessa-lo
};

int main(){
    std::vector<string> vectorDaGabizona;
    vectorDaGabizona.push_back("PDS");


    Discente d1 = Discente("Gabriella", 19, 20221047);
    d1.adicionar_matricula("ADM");
    cout << "O aluno " << d1.get_nome() << " está matriculado em: ";
    d1.imprimir_materias();
   
   return 0;
}



