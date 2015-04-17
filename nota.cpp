#include "nota.h"

Nota::Nota()
{
	estado = naopressionado; // Sempre inicia n�o pressionado.
	vivo = 0;
	ehnotalonga = false;
}


Nota::~Nota()
{
}

Sprite* Nota::getSprite()
{
	return &sprite;
}
int Nota::getPosX()
{
	return x;
}
int Nota::getPosY()
{
	return y;
}
Estado Nota::getEstado()
{
	return estado;
}

void Nota::cair()
{
	//A nota vai caindo
	y+=velocidade;
}
void Nota::desenhar(int x, int y)
{
	sprite.desenhar(x, y);
}
void Nota::atualizar()
{
	if (getVivo())
	{
		sprite.desenhar(x, y);
		cair();
		if (y > janela.getLarguraTela() + sprite.getAltura()/2)
			morrer();
	}
}
void Nota::inicializar(string nome, string endereco, int numAnim, int numFrame)
{
	velocidade = 2;
	if (!recursos.carregouSpriteSheet(nome))
	{
		recursos.carregarSpriteSheet(nome, endereco, numAnim, numFrame);
	}
	sprite.setSpriteSheet(nome);
}

void Nota::inicializar(int x, int y, bool notalonga, int setvel)
{
	//os parametros de x e y indentificam em qual local vai "nascer" a nota.
	ehnotalonga = notalonga;
	velocidade = setvel;
	this->x = x;
	this->y = y;
	vivo = true;
}
void Nota::setVel(int setvel)
{
	velocidade = setvel;
}
bool Nota::getVivo()
{
	return vivo;
}

void Nota::nascer()
{
	vivo = 1;
}

void Nota::morrer()
{
	vivo = 0;
}

int Nota::getRot()
{
	return 0;
}

bool Nota::getNotalonga()
{
	return ehnotalonga;
}