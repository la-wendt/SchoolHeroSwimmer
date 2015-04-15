#include "Botao.h"


Botao::Botao()
{
}


Botao::~Botao()
{
}
Sprite* Botao::getSprite()
{
	return &sprite;
}
int Botao::getPosX()
{
	return x;
}
int Botao::getPosY()
{
	return y;
}
Estado Botao::getEstado()
{
	return estado;
}
void Botao::desenhar(int x, int y)
{
	sprite.desenhar(x, y);
}
void Botao::atualizar()
{
	switch (estado)
	{
	case pressionado:
		sprite.setAnimacao(1);
			break;
	case naopressionado:
		sprite.setAnimacao(0);
		break;
	}
	sprite.desenhar(x, y);
	atualizarContador();
}
void Botao::inicializar(string nome, string endereco, int numAnim, int numFrame, int x, int y)
{
	this->x = x;
	this->y = y;

	if (!recursos.carregouSpriteSheet(nome))
	{
		recursos.carregarSpriteSheet(nome, endereco, numAnim, numFrame);
	}
	sprite.setSpriteSheet(nome);
}
int Botao::getRot()
{
	return 0;
}
void Botao::pressionar()
{
	estado = pressionado;
}

void Botao::despressionar()
{
	estado = naopressionado;
}

void Botao::iniciarContador()
{
	contador.iniciarCont();
}
void Botao::atualizarContador()
{
	if (contador.getVivo())
		contador.addTempo();
}
int Botao::getContTemp()
{
	return contador.getTempo();
}
void Botao::morrerCont()
{
	contador.morrer();
}