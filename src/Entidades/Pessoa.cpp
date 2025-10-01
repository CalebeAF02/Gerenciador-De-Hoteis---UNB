#include "../Entidades/Pessoa.h"
void Pessoa::setNome(const Nome& nome)
{
    this->nome = nome;
}

void Pessoa::setEmail(const Email& email)
{
    this->email = email;
}

string Pessoa::getNome() const
{
    return nome.getValor();
}

string Pessoa::getEmail() const
{
    return email.getValor();
}
