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

void Conta::sacar(float valorASacar) {
	if (valorASacar < 0) {
		std::cout << "Não pode sacar valor negativo" << std::endl;
		return;
	}

	float tarifaDeSaque = valorASacar * 0.05;
	float valorDoSaque = valorASacar + tarifaDeSaque;

	if (valorDoSaque > saldo) {
		std::cout << "Saldo insuficiente" << std::endl;
		return;
	}

	saldo -= valorDoSaque;
}

void Conta::depositar(float valorADepositar) {
	if (valorADepositar < 0) {
		std::cout << "Não pode sacar valor negativo" << std::endl;
		return;
	}

	saldo += valorADepositar;
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
