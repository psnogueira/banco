#include <iostream>
#include "Conta.hpp"

using namespace std;

void exibeSaldo(const Conta& conta) {
	cout << "O saldo da conta e: " << conta.recuperaSaldo() << endl;
}

int main() {
	Conta umaConta;
	umaConta.definirNomeTitular("Pedro");

	Conta umaOutraConta;
	umaOutraConta.depositar(500);
	umaOutraConta.sacar(200);

	cout << "Uma Conta: "   << umaConta.recuperaSaldo()      << endl 
		 << "Outra Conta: " << umaOutraConta.recuperaSaldo() << endl;

	cout << "Nome Titular: " << umaConta.recuperaNomeTitular() << endl;

	exibeSaldo(umaConta);
	exibeSaldo(umaOutraConta);

	return 0;
}