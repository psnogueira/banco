#include <iostream>
#include "Conta.hpp"
#include "ContaPoupanca.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "Funcionario.hpp"

using namespace std;

void ExibeSaldo(const Conta& conta) {
	cout << "O saldo da conta de " << std::fixed << conta.recuperaNome()
		 << " e: R$" << conta.recuperaSaldo() << endl;
}

void RealizaSaque(Conta& conta) {
	conta.sacar(200);
}

int main() {
	cout.precision(2);
	
	ContaPoupanca umaConta("123456", Titular(Cpf("123.456.789-10"), "Pedro"));
	umaConta.depositar(500);
	//umaConta.sacar(200);
	RealizaSaque(umaConta);

	ExibeSaldo(umaConta);

	Conta umaOutraConta("111222", Titular(Cpf("123.123.123-11"), "Sophia"));
	umaOutraConta.depositar(300);
	//umaOutraConta.sacar(50);
	RealizaSaque(umaOutraConta);

	ExibeSaldo(umaOutraConta);

	cout << "Numero total de contas: " << Conta::recuperaNumeroDeContas() << endl;

	Funcionario pedro(Cpf("111.222.333-44"), "Pedro Nogueira", 1250.50);
	
	
	cout << "Nome Funcionario: " << std::fixed << pedro.recuperaNome() << endl
		 << "Salario: R$" << pedro.recuperaSalario() << endl;

	return 0;
}