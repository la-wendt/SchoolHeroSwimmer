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
	numFase = 0;
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
	good.adicionarString("Good");
	bad.setFonte("fonte padrao");
	bad.adicionarString("Bad");
	miss.setFonte("fonte padrao");
	miss.adicionarString("Miss");
	recursos.carregarFonte("fonte grande", "./fonte_padrao.ttf", 50);
	start.setFonte("fonte grande");
	start.adicionarString("Press space.");


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
		switch (numFase)
		{
		case 0:
			if (!contar.getVivo())
				contar.iniciarCont();
			else if (contar.getTempo() == 30)
			{
				contar.morrer();
				interuptor.trocar();
			}
			else
				contar.addTempo();
			if (interuptor.getTroca())
			{
				start.desenhar(600, 545);
			}
			else{}
				

			if (teclado.pressionou[TECLA_ESPACO])
				numFase = 1;
				break;
		case 1:
			for (i = 0; i < 6; i++)
			{
				botao[i].atualizar();
			}
			notaExe(0);
			ExeBotoes();
			textExe();
			uniDepurar("x", mouse.x);
			uniDepurar("y", mouse.y);
			break;
		}
		//fundo.desenhar(janela.getLarguraTela() / 2, janela.getAlturaTela() / 2);
		
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
			if (uniColisaoLinhaComSprite(231, 620, 339, 620, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()) && uniColisaoLinhaComSprite(231, 684, 339, 684, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()))
			{
				nota[i].morrer();
				acerto = perfeito;
				
			}
			// GREAT - Para ser great tem que estar entre a linha inicial e a do 2º meio ou a final e a 1º meio
			else if (uniColisaoLinhaComSprite(231, 620, 339, 620, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()) && uniColisaoLinhaComSprite(231, 668, 339, 668, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()))
			{
				nota[i].morrer();
				acerto = otimo;
			}
			else if (uniColisaoLinhaComSprite(231, 636, 339, 636, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()) && uniColisaoLinhaComSprite(231, 684, 339, 684, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()))
			{
				nota[i].morrer();
				acerto = otimo;
			}
			// GOOD - primeiras e ultimas linhas com o meio
			else if (uniColisaoLinhaComSprite(231, 620, 339, 620, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()) && uniColisaoLinhaComSprite(231, 652, 339, 652, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()))
			{
				nota[i].morrer();
				acerto = bom;
			}
			else if (uniColisaoLinhaComSprite(231, 684, 339, 684, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()) && uniColisaoLinhaComSprite(231, 652, 339, 652, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()))
			{
				nota[i].morrer();
				acerto = bom;
			}
			// BAD - tá dentro, mas não bate em nenhum dos outros lugares.
			else if (uniColisaoLinhaComSprite(231, 620, 339, 620, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()) || uniColisaoLinhaComSprite(231, 684, 339, 684, nota[i].getSprite(), nota[i].getPosX(), nota[i].getPosY(), nota[i].getRot()))
			{
				nota[i].morrer();
				acerto = ruim;
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