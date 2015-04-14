#pragma once
#include "libUnicornio.h"
#include "Global.h"
#include "nota.h"
#include "Botao.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
	void notaExe();
	void pressbotaoA();

private:
	Nota nota;
	Botao botaoA;
};

