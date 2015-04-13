#pragma once
#include "libUnicornio.h"
#include "Global.h"
class Nota
{
	
public:
	
	Nota();
	~Nota();
	void inicializar(string nome, string endereco, int numAnim, int numFrame);
	void cair();
	Sprite* getSprite();
	int getPosX();
	int getPosY();
	Estado getEstado();
	bool getPresente();
	void desenhar(int x, int y);
	void atualizar();
private:
	bool presente;
	Sprite sprite;
	int x, y;
	Estado estado;
};

