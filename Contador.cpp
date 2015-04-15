#include "Contador.h"


Contador::Contador()
{
	vivo = false;
}


Contador::~Contador()
{
}

void Contador::iniciarCont()
{
	//Iniciando ele reseta o tempo e faz ele viver.
	tempo = 0;
	vivo = true;
}

void Contador::addTempo()
{
	tempo++;
}
void Contador:: morrer()
{
	vivo = false;
}
int Contador::getTempo()
{
	return tempo;
}
bool Contador::getVivo()
{
	return vivo;
}