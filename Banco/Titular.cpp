#include <iostream>
#include "Titular.hpp"

Titular::Titular(Cpf cpf, std::string nome, std::string senha):
	Pessoa(cpf, nome), 
	Autenticavel(senha)
{
}
