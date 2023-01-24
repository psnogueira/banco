#pragma once
#include <string>
#include <utility>
#include <variant>
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
	enum ResultadoDeErroDoSaque 
	{
		Sucesso, ValorNegativo, SaldoInfuficiente
	};

	Conta(std::string numeroConta, Titular titular);
	virtual ~Conta();
	std::variant<ResultadoDeErroDoSaque, float> sacar(float valorASacar);
	void depositar(float valorADepositar);
	float recuperaSaldo() const;
	virtual float taxaDeSaque() const = 0;

	void operator += (float valorADepositar);
	bool operator < (const Conta& outraConta);
	friend std::ostream& operator << (std::ostream& cout, const Conta& conta);

	std::string recuperaNumero() const;
	std::string recuperaNome() const;
};