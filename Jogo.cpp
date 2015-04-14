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
	nota.inicializar("nota", "./data/spritesheet/nota.png", 1, 1, 100, 100);
	botaoA.inicializar("botao", "./data/spritesheet/pegar.png", 1, 1, 100, 500);

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


		botaoA.atualizar();
		notaExe();
		pressbotaoA();
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
	{ //senão estiver, muda o lugar para onde estiver e nasce de novo.
		nota.inicializar(100, 100);
	}
}

void Jogo::pressbotaoA()
{
	if (teclado.pressionou[TECLA_A])
	{
		if (uniColisaoSpriteComSprite(nota.getSprite(), nota.getPosX(), nota.getPosY(), nota.getRot(), botaoA.getSprite(), botaoA.getPosX(), botaoA.getPosY(), botaoA.getRot()))
		{
			nota.morrer();
		}
	}
}