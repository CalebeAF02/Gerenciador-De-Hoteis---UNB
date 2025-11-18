//
// Created by caleb on 18/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_SOLICITACAOHOSPEDAGEMDTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_SOLICITACAOHOSPEDAGEMDTO_HPP

#include <string>

using namespace std;
namespace Hotelaria {
    class SolicitacaoHospedagemDTO {
    private:
        int solicitacaoHospedagemId;
        int hospedeId;
        int hotelId;
        int quartoId;
        string chegada;
        string partida;
        string status;
        string motivoRecusa;

    public:
        SolicitacaoHospedagemDTO() = default;

        SolicitacaoHospedagemDTO(int solicitacaoHospedagemId, int hospedeId, int hotelId, int quartoId, string chegada, string partida, string(status), string motivoRecusa) : solicitacaoHospedagemId(solicitacaoHospedagemId), hospedeId(hospedeId), hotelId(hotelId), quartoId(quartoId), chegada(chegada), partida(partida), status(status), motivoRecusa(motivoRecusa) {};

        int getSolicitacaoHospedagemId() const {
            return solicitacaoHospedagemId;
        }

        void setSolicitacaoHospedagemId(int valor) {
            this->solicitacaoHospedagemId = valor;
        }

        int getHospedeId() const {
            return hospedeId;
        }

        void setHospedeId(int valor) {
            this->hospedeId = valor;
        }

        int getHotelId() const {
            return hotelId;
        }

        void setHotelId(int valor) {
            this->hotelId = valor;
        }

        int getQuartoId() const {
            return quartoId;
        }

        void setQuartoId(int valor) {
            this->quartoId = valor;
        }

        string getChegada() const {
            return chegada;
        }

        void setChegada(const string &valor) {
            this->chegada = valor;
        }

        string getPartida() const {
            return partida;
        }

        void setPartida(const string &valor) {
            this->partida = valor;
        }

        string getStatus() const {
            return status;
        }

        void setStatus(const string &valor) {
            this->status = valor;
        }
        string getMotivoRecusa() const {
            return motivoRecusa;
        }

        void setMotivoRecusa(const string &valor) {
            this->motivoRecusa = valor;
        }
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_SOLICITACAOHOSPEDAGEMDTO_HPP