#include "Conta.hpp"
#include <iostream>

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

std::string Conta::recuperaNumero() {
	return numeroConta;
}

std::string Conta::recuperaCPFTitular() {
	return cpfTitular;
}

std::string Conta::recuperaNomeTitular() {
	return nomeTitular;
}

float Conta::recuperaSaldo() const {
	return saldo;
}

void Conta::definirNumero(std::string numero) {
	numeroConta = numero;
}

void Conta::definirCPFTitular(std::string cpf) {
	cpfTitular = cpf;
}

void Conta::definirNomeTitular(std::string nome) {
	nomeTitular = nome;
}
