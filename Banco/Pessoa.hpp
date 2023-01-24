#pragma once
#include <iostream>
#include <string>

template<typename Documento>
class Pessoa
{
protected:
	Documento documento;
	std::string nome;

public:
	Pessoa(Documento documento, std::string nome) :
		documento(documento),
		nome(nome)
	{
		verificaTamanhoDoNome();
	}

private:
	void verificaTamanhoDoNome() {
		if (nome.size() < 5) {
			std::cout << "ERRO: Nome muito curto" << std::endl;
			exit(1);
		}
	}

public:
	std::string recuperaNome() const {
		return nome;
	}
	std::string recuperaCpf() const {
		return documento.recuperaNumero();
	}
};

