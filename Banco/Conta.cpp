#include "Conta.hpp"
#include <iostream>

int Conta::numeroDeContas = 0;

// M�todo Construtor Conta
Conta::Conta(std::string numeroConta, Titular titular):
	numeroConta(numeroConta), 
	titular(titular),
	saldo(0) 
{
	numeroDeContas++;
}

// M�todo destrutor ~Conta
Conta::~Conta() {
	numeroDeContas--;
}

void Conta::sacar(float valorASacar) {
	if (valorASacar < 0) {
		std::cout << "N�o pode sacar valor negativo" << std::endl;
		return;
	}

	if (valorASacar > saldo) {
		std::cout << "Saldo insuficiente" << std::endl;
		return;
	}

	saldo -= valorASacar;
}

void Conta::depositar(float valorADepositar) {
	if (valorADepositar < 0) {
		std::cout << "N�o pode sacar valor negativo" << std::endl;
		return;
	}

	saldo += valorADepositar;
}

std::string Conta::recuperaNumero() const {
	return numeroConta;
}

std::string Conta::recuperaCPF() const {
	return titular.recuperaCPF();
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
