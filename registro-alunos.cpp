#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Aluno {
private:
  std::string _nome;
  int _matricula;
  set<int>
      _materias; // como o set guarda valores unicos, estou utilizando ele para
                 // que um aluno so posso se cadastrar na mesma materia uma vez.
public:
  Aluno(std::string nome, int matricula) {
    _nome = nome;
    _matricula = matricula;
  }

  std::string get_nome() { return _nome; }

  int get_matricula() { return _matricula; }

  void matricular(int materia) {
    _materias.insert(materia); // vou inserir dentro do set materias.
  }

  set<int> get_materias() { // guardei as materias em um set<int>, entao a funcao precisa ter esse tipo.
    return _materias;
  }

  /*int quantidadeMatriculasUnicas(vector<Aluno> alunos) {
    set<int> matriculas;
    for (Aluno a : alunos) {
      matriculas.insert(a.get_matricula());
    }
    return matriculas.size();
  }*/
};

class RegistroAlunos {
private:
  map<int, Aluno>
      _registro_alunos; // map recebe um par de valores. chave e outra coisa. tads guardam dados e cumprem contratos
public:
  void inserir_aluno(Aluno a) {
    _registro_alunos.insert(
        pair<int, Aluno>(a.get_matricula(), a) // o par que vou inserir no map.
    );
  }

  void adicionar_materia(int matricula, int materia) {
    _registro_alunos.at(matricula).matricular(materia);
  }

  bool ja_registrada(int matricula) {
    return _registro_alunos.count(matricula) > 0;
  }

  void imprime_registro() {
    auto it = _registro_alunos.begin();
    while (it != _registro_alunos.end()) {
      int matricula = it->first;
      Aluno a = it->second;
      int n = a.get_materias().size();

      cout << "O aluno com nome: " << a.get_nome();
      cout << " e matricula " << matricula;
      cout << " se matriculou em " << n << " materias";
      cout << endl;

      it = next(it);
    }
  }
};

int main() {
  fstream arquivoEntrada;
  arquivoEntrada.open("alunos.dat");

  RegistroAlunos registro;

  while (!arquivoEntrada.eof()) {
    string nome;
    arquivoEntrada >> nome;

    int matricula;
    arquivoEntrada >> matricula;

    int cod_disciplina;
    arquivoEntrada >> cod_disciplina;

    if (!registro.ja_registrada(matricula)) { // se essa condicap for falsa.
      Aluno a = Aluno(nome, matricula);
      registro.inserir_aluno(a);
    }

    registro.adicionar_materia(matricula, cod_disciplina);
  }

  // fstream arquivoSaida;
  // arquivoSaida.open("teste.dat", fstream::out);
  // arquivoSaida << "Deu certo";

  registro.imprime_registro();

  arquivoEntrada.close();
}