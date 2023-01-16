#include <iostream>
#include "Titular.hpp"

Titular::Titular(Cpf cpf, std::string nome):
	cpf(cpf),
	nome(nome)
{
	verificaTamanhoDoNome();
}

void Titular::verificaTamanhoDoNome() {
	if (nome.size() < 5) {
		std::cout << "ERRO: Nome muito curto" << std::endl;
		exit(1);
	}
}

std::string Titular::recuperaCPF() const {
	return cpf.recuperaNumero();
}

std::string Titular::recuperaNome() const {
	return nome;
}