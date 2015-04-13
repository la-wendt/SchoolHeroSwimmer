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
	nota.inicializar("nota", "./data/spritesheet/pegar.png", 1, 1);

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
		
		uniTerminarFrame();
	}
}

void Jogo::notaExe()
{
	if (nota.getEstado() == 0)
		nota.desenhar(100, 100);

}