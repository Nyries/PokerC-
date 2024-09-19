#pragma once
class Pot
{
private: 
	int chips;
public:
	Pot(int chips);
	~Pot();

	//Getter
	int getChips();

	//Setter
	void setChips(int chips);

	//State functions
	bool isEmpty();

	//Others
	void addChips(int amount);
	void substractChips(int amount);
	void takeChipsFrom(int amount, Pot* pot);
	void giveChipsTo(int amount, Pot* pot);
};

