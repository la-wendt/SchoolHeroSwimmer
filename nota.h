#pragma once
#include "libUnicornio.h"
#include "Global.h"
class Nota
{
	
public:
	
	Nota();
	~Nota();
	void inicializar(string nome, string endereco, int numAnim, int numFrame, int x, int y);
	void cair();
	Sprite* getSprite();
	int getPosX();
	int getPosY();
	void nascer();
	void morrer();
	Estado getEstado();
	bool getVivo();
	void desenhar(int x, int y);
	void atualizar();
private:
	bool vivo;
	Sprite sprite;
	int x, y, velocidade;
	Estado estado;
};

