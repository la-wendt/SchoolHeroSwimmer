#include "Interruptor.h"


Interruptor::Interruptor()
{
	troca = true;
}


Interruptor::~Interruptor()
{
}

void Interruptor::trocar()
{
	if (troca)
		troca = false;
	else
		troca = true;
}

bool Interruptor::getTroca()
{
	return troca;
}
void Interruptor::setTroca(bool i)
{
	troca = i;
}