#pragma once
#include "libUnicornio.h"
#include "Global.h"
class Nota
{
	
public:
	
	Nota();
	~Nota();
	void inicializar(string nome, string endereco, int numAnim, int numFrame);
	void inicializar(int x, int y);
	void cair();
	Sprite* getSprite();
	int getPosX();
	int getPosY();
	int getRot();
	void nascer();
	void morrer();
	void addvel();
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

