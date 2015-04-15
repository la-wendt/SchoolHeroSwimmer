#pragma once
#include "libUnicornio.h"
#include "Global.h"
#include "Contador.h"
class Botao
{
public:
	Botao();
	~Botao();
	void inicializar(string nome, string endereco, int numAnim, int numFrame, int x, int y);
	Sprite* getSprite();
	int getPosX();
	int getPosY();
	int getRot();
	Estado getEstado();
	void desenhar(int x, int y);
	void atualizar();
	void pressionar();
	void despressionar();
	void iniciarContador();
	void atualizarContador();
	void morrerCont();
	int getContTemp();
private:
	Sprite sprite;
	int x, y;
	Estado estado;
	Contador contador;
};

