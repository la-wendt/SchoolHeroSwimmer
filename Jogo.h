#pragma once
#include "libUnicornio.h"
#include "Global.h"
#include "nota.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
	void notaExe();

private:
	Nota nota;
};

