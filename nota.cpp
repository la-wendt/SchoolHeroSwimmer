#include "nota.h"


Nota::Nota()
{
	estado = naopressionado; // Sempre inicia não pressionado.
	presente = false;
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
	y++;
}
void Nota::desenhar(int x, int y)
{
	sprite.desenhar(x, y);
}
void Nota::atualizar()
{
	cair();
	sprite.desenhar(x, y);
}
void Nota::inicializar(string nome, string endereco, int numAnim, int numFrame)
{

	if (!recursos.carregouSpriteSheet(nome))
	recursos.carregarSpriteSheet(nome, endereco, numAnim, numFrame);
}

bool Nota::getPresente()
{
	return presente
}