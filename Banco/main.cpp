#include <iostream>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "Funcionario.hpp"
#include "Caixa.hpp"
#include "Gerente.hpp"

using namespace std;

void ExibeSaldo(const Conta& conta) {
	cout << "O saldo da conta de " << std::fixed << conta.recuperaNome()
		 << " e: R$" << conta.recuperaSaldo() << endl;
}

void RealizaSaque(Conta& conta) {
	conta.sacar(200);
}

void FazLogin(Autenticavel& alguem, string senha) {
	if (alguem.autentica(senha)) {
		cout << "Login realizado com sucesso " << endl;
	}
	else {
		cout << "Senha invalida " << endl;
	}
}

int main() {
	cout.precision(2);
	
	ContaPoupanca umaConta("123456", Titular(Cpf("123.456.789-10"), "Pedro", "umasenha"));
	umaConta.depositar(500);
	//umaConta.sacar(200);
	RealizaSaque(umaConta);

	ExibeSaldo(umaConta);

	ContaCorrente umaOutraConta("111222", Titular(Cpf("123.123.123-11"), "Sophia", "outrasenha"));
	umaOutraConta.depositar(2000);
	ExibeSaldo(umaOutraConta);

	ContaCorrente outraContaCorrente("333333", Titular(Cpf("333.333.333-33"), "Arthur","maisumasenha "));
	ExibeSaldo(outraContaCorrente);

	cout << endl;
	cout << "Transferencia " << endl;
	cout << endl;
	umaOutraConta.transferePara(umaConta, 100);
	umaOutraConta.transferePara(outraContaCorrente, 1500);

	ExibeSaldo(umaConta);
	ExibeSaldo(umaOutraConta);
	ExibeSaldo(outraContaCorrente);

	cout << endl;
	cout << "Numero total de contas: " << Conta::recuperaNumeroDeContas() << endl;
	cout << endl;

	Gerente pedro(Cpf("111.222.333-44"), "Pedro Nogueira", 1250.50, "senhapedro");
	
	cout << "Nome Funcionario: " << std::fixed << pedro.recuperaNome() << endl
		 << "CPF: " << pedro.recuperaCpf() << endl
		 << "Salario: R$" << pedro.recuperaSalario() << endl
		 << "Bonificacao: R$" << pedro.bonificacao() << endl;

	cout << endl;
	cout << "Tentativa de Login de 'Pedro': " << endl;

	FazLogin(pedro,"senhapedro");

	return 0;
}