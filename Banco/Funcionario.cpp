#include "Funcionario.hpp"

Funcionario::Funcionario(Cpf cpf, std::string nome, float salario):
	Pessoa(cpf, nome),
	salario(salario)
{
}

float Funcionario::recuperaSalario() const {
	return salario;
}