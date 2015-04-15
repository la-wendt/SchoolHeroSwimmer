#pragma once
class Interruptor
{
public:
	Interruptor();
	~Interruptor();
	void trocar();
	bool getTroca();
	void setTroca(bool i);
private:
	bool troca;
};

