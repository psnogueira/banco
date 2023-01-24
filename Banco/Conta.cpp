#include "Conta.hpp"
#include <iostream>

int Conta::numeroDeContas = 0;

// Método Construtor Conta
Conta::Conta(std::string numeroConta, Titular titular):
	numeroConta(numeroConta), 
	titular(titular),
	saldo(0)
{
	numeroDeContas++;
}

// Método destrutor ~Conta
Conta::~Conta() {
	numeroDeContas--;
}

std::variant<Conta::ResultadoDeErroDoSaque, float> Conta::sacar(float valorASacar) {
	if (valorASacar < 0) {
		std::cout << "Não pode sacar valor negativo" << std::endl;
		return ValorNegativo;
	}

	float tarifaDeSaque = valorASacar * taxaDeSaque();
	float valorDoSaque = valorASacar + tarifaDeSaque;

	if (valorDoSaque > saldo) {
		std::cout << "Saldo insuficiente" << std::endl;
		return SaldoInfuficiente;
	}

	saldo -= valorDoSaque;

	return saldo;
}

void Conta::depositar(float valorADepositar) {
	if (valorADepositar < 0) {
		std::cout << "Não pode sacar valor negativo" << std::endl;
		return;
	}

	saldo += valorADepositar;
}

void Conta::operator += (float valorADepositar) {
	depositar(valorADepositar);
}

bool Conta::operator < (const Conta& outraConta) {
	return this->saldo < outraConta.saldo;
}

std::string Conta::recuperaNumero() const {
	return numeroConta;
}

std::string Conta::recuperaNome() const {
	return titular.recuperaNome();
}

float Conta::recuperaSaldo() const {
	return saldo;
}

int Conta::recuperaNumeroDeContas() {
	return numeroDeContas;
}
