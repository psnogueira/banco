#include "Cpf.hpp"

Cpf::Cpf(std::string numero):
	numero(numero)
{
	//valida��o complexa de CPF
}

std::string Cpf::recuperaNumero() const {
	return numero;
}