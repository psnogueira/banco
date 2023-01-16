#include <iostream>
#include "Conta.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"

using namespace std;

void ExibeSaldo(const Conta& conta) {
	cout << "O saldo da conta " << conta.recuperaNome()
		 << " e: " << conta.recuperaSaldo() << endl;
}

int main() {
	Conta umaConta("123456", Titular(Cpf("123.456.789-10"), "Pedro"));
	umaConta.depositar(500);
	umaConta.sacar(200);

	ExibeSaldo(umaConta);

	Conta umaOutraConta("111222", Titular(Cpf("123.123.123-11"), "Sophia"));
	umaOutraConta.depositar(300);
	umaOutraConta.sacar(50);

	ExibeSaldo(umaOutraConta);

	cout << "Numero de contas: " << Conta::recuperaNumeroDeContas() << endl;

	return 0;
}