#pragma once
#include <string>
#include "Titular.hpp"

class Conta {
private:
	static int numeroDeContas;

public:
	static int recuperaNumeroDeContas();

private:
	std::string numeroConta;
	Titular titular;

protected:
	float saldo;

public:
	Conta(std::string numeroConta, Titular titular);
	~Conta();
	virtual void sacar(float valorASacar);
	void depositar(float valorADepositar);
	float recuperaSaldo() const;

	std::string recuperaNumero() const;
	std::string recuperaNome() const;
};