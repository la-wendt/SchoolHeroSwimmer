#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

}

void Jogo::finalizar()
{


	uniFinalizar();
}

void Jogo::executar()
{
	while(!teclado.soltou[TECLA_ESC] && !aplicacao.sair)
	{
		uniIniciarFrame();
		notaExe();
		uniTerminarFrame();
	}
}

void Jogo::notaExe()
{ // modo de inicialização para teste
	if (nota.getVivo())
	{
		// se estiver vivo, atualiza
		nota.atualizar();
	}
	else
	{ //senão estiver, inicializa.
		nota.inicializar("nota", "./data/spritesheet/pegar.png", 1, 1, 100, 100); 
	}
}