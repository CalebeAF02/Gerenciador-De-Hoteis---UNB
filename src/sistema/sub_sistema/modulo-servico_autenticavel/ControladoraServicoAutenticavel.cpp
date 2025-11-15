//
// Created by caleb on 14/11/2025.
//

#include "ControladoraServicoAutenticavel.hpp"

/*
#include "InterfaceServicoAutenticavel.hpp"
#include "InterfaceAcessoInformacao.hpp" // Dependência na Interface de Persistência (CAI)

// ControladoraServicoAutenticavel implementa o contrato de serviço (ISA).
class ControladoraServicoAutenticavel : public InterfaceServicoAutenticavel {
private:
    // Referência para o servidor de persistência.
    // O DIP é respeitado: o serviço depende da Interface (IAI), não da Controladora (CAI) concreta.
    InterfaceAcessoInformacao *controladora_acesso_informacao;

public:
    // Implementação do contrato ISA
    bool autenticar(const Email email, const Senha senha) override;

    // injeção de dependência da Controladora de Persistência.
    void setControladoraAcessoInformacao(InterfaceAcessoInformacao *controladora_acesso_informacao);
};

// Definição inline da injeção de dependência
void inline ControladoraServicoAutenticavel::setControladoraAcessoInformacao(
    InterfaceAcessoInformacao *controladora_acesso_informacao) {
    this->controladora_acesso_informacao = controladora_acesso_informacao;
}
*/

/*
o que eu possuo em persistencia

bool PersistenciaGerente::autenticarGerente(const string &email, const string &senha) {
BancoDeDados banco;

if (email.empty() || senha.empty())
return false;

if (!banco.abrindoConexao())
return false;

sqlite3 *db = banco.getConexao();
sqlite3_stmt *stmt = nullptr;

const char *sql = "SELECT COUNT(*) FROM gerentes WHERE email = ? AND senha = ? LIMIT 1;";
int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
if (rc != SQLITE_OK) {
cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << endl;
banco.fechandoConexao();
return false;
}

sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_STATIC);
sqlite3_bind_text(stmt, 2, senha.c_str(), -1, SQLITE_STATIC);

bool statusAutenticacao = false;
if (sqlite3_step(stmt) == SQLITE_ROW) {
int quantidade = reinterpret_cast<int>(sqlite3_column_int(stmt, 0));
if (quantidade > 0) {
statusAutenticacao = true;
}
}

sqlite3_finalize(stmt);
banco.fechandoConexao();
return statusAutenticacao;
}
*/