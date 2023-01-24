#pragma once
#include "Conta.hpp"

class ContaPoupanca final: public Conta
{
public:
	ContaPoupanca(std::string numeroConta, Titular titular);
	float taxaDeSaque() const override;
};

