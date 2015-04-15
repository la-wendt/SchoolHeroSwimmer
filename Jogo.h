#pragma once
#include "libUnicornio.h"
#include "Global.h"
#include "nota.h"
#include "Botao.h"
#include "Interruptor.h"


class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void textos();
	void finalizar();
	void executar();
	void notaExe(int numNot);
	void textExe();
	void notaInic(int botao, int numNota);
	void ExeBotoes();
	void pressbotaoA();
	void pressbotaoS();
	void pressbotaoD();
	void pressbotaoJ();
	void pressbotaoK();
	void pressbotaoL();

private:
	Acerto acerto;
	Texto great, perfect, good, bad, miss, start;
	int i, i2, k, numFase;
	Sprite fundo;
	Nota nota[6];
	Botao botao[6];
	Contador contar;
	Interruptor interuptor;
};

