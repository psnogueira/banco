#include "Cpf.hpp"

Cpf::Cpf(std::string numero):
	numero(numero)
{
	//validação complexa de CPF
}

std::string Cpf::recuperaNumero() const {
	return numero;
}