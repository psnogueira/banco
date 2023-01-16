#pragma once
#include <string>

class Conta {
private:
	std::string numeroConta;
	std::string cpfTitular;
	std::string nomeTitular;
	float saldo{};

public:
	void sacar(float valorASacar);
	void depositar(float valorADepositar);
	float recuperaSaldo() const;

	std::string recuperaNumero();
	std::string recuperaCPFTitular();
	std::string recuperaNomeTitular();
	
	void definirNumero(std::string numero);
	void definirCPFTitular(std::string cpf);
	void definirNomeTitular(std::string nome);
	
};