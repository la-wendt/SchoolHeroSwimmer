#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1280, 700, false, "LoveLive School Hero Swimmer");
	i2 = 0;
	k = 0;
	for (i = 0; i < 6; i++)
	{
		nota[i].inicializar("nota", "./data/spritesheet/nota.png", 1, 1);
	}
	for (i = 0; i < 6; i++)
	{
		botao[i].inicializar("botao", "./data/spritesheet/botao.png", 2, 1, 285 + i2, 655);
		i2 += 146;
	}
	recursos.carregarSpriteSheet("fundo", "./data/spritesheet/fundoprov.png", 1, 1);
	fundo.setSpriteSheet("fundo");
	textos();
}
void Jogo::textos()
{
	// inicialização dos textos e fontes
	recursos.carregarFonte("fonte padrao", "./fonte_padrao.ttf", 24);
	perfect.setFonte("fonte padrao");
	perfect.adicionarString("PERFECT!");
	great.setFonte("fonte padrao");
	great.adicionarString("Great!");
	good.setFonte("fonte padrao");
	good.adicionarString("good");
	bad.setFonte("fonte padrao");
	bad.adicionarString("bad");
	miss.setFonte("fonte padrao");
	miss.adicionarString("miss");

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
		//fundo.desenhar(janela.getLarguraTela() / 2, janela.getAlturaTela() / 2);
		for (i = 0; i < 6; i++)
		{
			botao[i].atualizar();
		}
			notaExe(0);
		ExeBotoes();
		textExe();
		uniDepurar("x", mouse.x);
		uniDepurar("y", mouse.y);
		uniTerminarFrame();
		
	}
}

void Jogo::notaExe(int numNota)
{ // modo de inicialização para teste
	if (nota[numNota].getVivo())
	{
		// se estiver vivo, atualiza
		nota[numNota].atualizar();
	}
	else
	{ //senão estiver, muda o lugar para onde estiver e nasce de novo.
			notaInic(k, numNota);
			k++;
			if (k > 6)
				k = 0;
	}
}

void Jogo::notaInic(int botao, int numNota)
{
	switch(botao)
	{
	case 0:
		nota[numNota].inicializar(285, 216);
		break;
	case 1:
		nota[numNota].inicializar(431, 216);
		break;
	case 2:
		nota[numNota].inicializar(577, 216);
		break;
	case 3:
		nota[numNota].inicializar(723, 216);
		break;
	case 4:
		nota[numNota].inicializar(869, 216);
		break;
	case 5:
		nota[numNota].inicializar(1015, 216);
		break;
	}

}

void Jogo::ExeBotoes()
{
	pressbotaoA();
	pressbotaoS();
	pressbotaoD();
	pressbotaoJ();
	pressbotaoK();
	pressbotaoL();
}
void Jogo::pressbotaoA()
{
	if (teclado.pressionou[TECLA_A])
	{
		botao[0].pressionar();
		botao[0].iniciarContador();
		for (i = 0; i < 6; i++)
		{
			// PERFECT - Para ser perfect a nota tem que estar entre uma das primeiras linhas do botao e uma das ultimas.
			if (uniColisaoLinhaComSprite(231, 618, 339, 618, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()) && uniColisaoLinhaComSprite(231, 686, 339, 686, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()))
			{
				nota[i].morrer();
				acerto = perfeito;
				
			}
			// GREAT - Para ser great tem que estar entre duas 
			else if (uniColisaoLinhaComSprite(231, 670, 339, 670, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()) && uniColisaoLinhaComSprite(231, 640, 339, 640, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()))
			{
				nota[i].morrer();
				acerto = otimo;
			}
			else if (true)
			{
				
			}

			//if (uniColisaoSpriteComSprite(nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()
		}
	}
	if (botao[0].getContTemp() == 15)
	{
		botao[0].morrerCont();
		botao[0].despressionar();
	}
}
void Jogo::pressbotaoS()
{
	if (teclado.pressionou[TECLA_S])
	{
		botao[1].pressionar();
		botao[1].iniciarContador();
		for (i = 0; i < 6; i++)
		{
			// PERFECT:








			if (uniColisaoSpriteComSprite(nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot(), botao[1].getSprite(), botao[1].getPosX(), botao[1].getPosY(), botao[1].getRot()))
			{
				nota[i].morrer();
			}
		}
	}
	if (botao[1].getContTemp() == 15)
	{
		botao[1].morrerCont();
		botao[1].despressionar();
	}
}
void Jogo::pressbotaoD()
{
	if (teclado.pressionou[TECLA_D])
	{
		botao[2].pressionar();
		botao[2].iniciarContador();
		for (i = 0; i < 6; i++)
		{
			if (uniColisaoSpriteComSprite(nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot(), botao[0].getSprite(), botao[0].getPosX(), botao[0].getPosY(), botao[0].getRot()))
			{
				nota[i].morrer();
			}
		}
	}
	if (botao[2].getContTemp() == 15)
	{
		botao[2].morrerCont();
		botao[2].despressionar();
	}
}
void Jogo::pressbotaoJ()
{
	if (teclado.pressionou[TECLA_J])
	{
		botao[3].pressionar();
		botao[3].iniciarContador();
		for (i = 0; i < 6; i++)
		{
			if (uniColisaoSpriteComSprite(nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot(), botao[0].getSprite(), botao[0].getPosX(), botao[0].getPosY(), botao[0].getRot()))
			{
				nota[i].morrer();
			}
		}
	}
	if (botao[3].getContTemp() == 15)
	{
		botao[3].morrerCont();
		botao[3].despressionar();
	}
}
void Jogo::pressbotaoK()
{
	if (teclado.pressionou[TECLA_K])
	{
		botao[4].pressionar();
		botao[4].iniciarContador();
		for (i = 0; i < 6; i++)
		{
			if (uniColisaoSpriteComSprite(nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot(), botao[0].getSprite(), botao[0].getPosX(), botao[0].getPosY(), botao[0].getRot()))
			{
				nota[i].morrer();
			}
		}
	}
	if (botao[4].getContTemp() == 15)
	{
		botao[4].morrerCont();
		botao[4].despressionar();
	}
}
void Jogo::pressbotaoL()
{
	if (teclado.pressionou[TECLA_L])
	{
		botao[5].pressionar();
		botao[5].iniciarContador();
		for (i = 0; i < 6; i++)
		{
			if (uniColisaoSpriteComSprite(nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot(), botao[0].getSprite(), botao[0].getPosX(), botao[0].getPosY(), botao[0].getRot()))
			{
				nota[i].morrer();
			}
		}
	}
	if (botao[5].getContTemp() == 15)
	{
		botao[5].morrerCont();
		botao[5].despressionar();
	}
}
void Jogo::textExe()
{
	switch (acerto)
	{
	case nada:
		break;
	case perfeito:
		perfect.desenhar(550, 300);
		break;
	case otimo:
		great.desenhar(550, 300);
		break;
	case bom:
		good.desenhar(550, 300);
		break;
	case ruim:
		bad.desenhar(550, 300);
		break;
	case erro:
		miss.desenhar(550, 300);
		break;

	}
}