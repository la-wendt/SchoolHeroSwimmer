#pragma once
class Contador
{
public:
	Contador();
	~Contador();
	void iniciarCont();
	int getTempo();
	void addTempo();
	bool getVivo();
	void morrer();
private:
	int tempo;
	bool vivo;
};

