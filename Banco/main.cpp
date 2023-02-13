#include <iostream>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "Funcionario.hpp"
#include "Caixa.hpp"
#include "Gerente.hpp"
#include "DiaDaSemana.hpp"

using namespace std;

void ExibeSaldo(const Conta& conta) {
	cout << "O saldo da conta de " << std::fixed << conta.recuperaNome()
		 << " e: R$" << conta.recuperaSaldo() << endl;
}

void RealizaSaque(Conta& conta) {
	std::variant<Conta::ResultadoDeErroDoSaque, float> resultado = conta.sacar(200);
	if (auto saldo = std::get_if<float>(&resultado))
	{
		cout << std::fixed << "Novo saldo da conta: " << *saldo << endl;
	}
}

void FazLogin(Autenticavel& alguem, string senha) {
	if (alguem.autentica(senha)) {
		cout << "Login realizado com sucesso " << endl;
	}
	else {
		cout << "Senha invalida " << endl;
	}
}

ostream& operator<<(ostream& cout, const Conta& conta)
{
	Pessoa titular = conta.titular;
	cout << "O saldo da conta de (operador) " << std::fixed << titular.recuperaNome()
		<< " e: R$" << conta.recuperaSaldo() << endl;
	
	return cout;
}

template<typename MeuTipo> MeuTipo Menor(MeuTipo a, MeuTipo b) {
	return a < b ? a : b;
}

int main() {
	cout.precision(2);
	
	ContaPoupanca umaConta("123456", Titular(Cpf("123.456.789-10"), "umaConta", "umasenha"));
	umaConta.depositar(500);
	//umaConta.sacar(200);
	RealizaSaque(umaConta);

	ExibeSaldo(umaConta);

	ContaCorrente umaOutraConta("111222", Titular(Cpf("123.123.123-11"), "umaOutraConta", "outrasenha"));
	(Conta&) umaOutraConta += 2000;
	cout << umaOutraConta;

	ContaCorrente outraContaCorrente("333333", Titular(Cpf("333.333.333-33"), "outraContaCorrente","maisumasenha"));
	ExibeSaldo(outraContaCorrente);

	cout << endl;
	cout << "Transferencia " << endl;
	cout << endl;

	//umaOutraConta.transferePara(umaConta, 100);
	outraContaCorrente += umaOutraConta;
	//umaOutraConta.transferePara(outraContaCorrente, 1500);

	ExibeSaldo(umaConta);
	ExibeSaldo(umaOutraConta);
	ExibeSaldo(outraContaCorrente);

	cout << Menor<Conta&>(umaConta, umaOutraConta);

	cout << endl;
	cout << "Numero total de contas: " << Conta::recuperaNumeroDeContas() << endl;
	cout << endl;

	Gerente umGerente(
		Cpf("111.222.333-44"), 
		"Nome de Gerente", 
		1250.50, 
		DiaDaSemana::Terca, 
		"1234"
	);

	cout << "Nome Funcionario: " << std::fixed << umGerente.recuperaNome() << endl
		 << "CPF: " << umGerente.recuperaCpf() << endl
		 << "Salario: R$" << umGerente.recuperaSalario() << endl
		 << "Bonificacao: R$" << umGerente.bonificacao() << endl;

	cout << endl;
	cout << "Tentativa de Login de 'Nome de Gerente': " << endl;

	FazLogin(umGerente,"1234");

	return 0;
}