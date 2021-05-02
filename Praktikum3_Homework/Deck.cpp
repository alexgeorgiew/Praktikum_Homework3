/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Alex Georgiev
* @idnumber 62604
* @task 1
* @compiler VC
*/
#include "Deck.hpp"

Deck::Deck(std::string input_name, std::vector<MonsterCard> input_monsters, std::vector<MagicCard> input_magicians, std::vector<PendulumCard> input_pendulums)
{
	this->name = input_name;
	this->monstercards = input_monsters;
	this->magiccards = input_magicians;
	this->pendulumcards = pendulumcards;
}
unsigned int Deck::monsterCardsCount() const
{
	return this->monstercards.size();
}
unsigned int Deck::magicCardsCount() const
{
	return this->magiccards.size();
}
unsigned int Deck::pendulumCardsCount() const
{
	return this->pendulumcards.size();
}
void Deck::addMonsterCard(const MonsterCard& card)
{
	this->monstercards.push_back(card);
}
void Deck::addMagicCard(const MagicCard& card)
{
	this->magiccards.push_back(card);
}
void Deck::addPendulumCard(const PendulumCard& card)
{
	this->pendulumcards.push_back(card);
}
void Deck::setDeckname(std::string input)
{
	this->name = input;
}
void Deck::setMonsterCard(const  unsigned int index,const MonsterCard& card)
{
	if (this->monstercards.size() > index)
	{
		this->monstercards[index] = card;
	}
	else
	{
		this->monstercards.push_back(card);
	}
}
void Deck::setMagicCard(const  unsigned int index, const MagicCard& card)
{
	if (this->magiccards.size() > index)
	{
		this->magiccards[index] = card;
	}
	else
	{
		this->magiccards.push_back(card);
	}
}
void Deck::setPendulumCard(const  unsigned int index, const PendulumCard& card)
{
	if (this->pendulumcards.size() > index)
	{
		this->pendulumcards[index] = card;
	}
	else
	{
		this->pendulumcards.push_back(card);
	}
}
void Deck::Delete()
{
	this->magiccards.clear();
	this->monstercards.clear();
	this->pendulumcards.clear();
}
std::string Deck::getName()const
{
	return this->name;
}
std::vector<MonsterCard> Deck::getMonsterCards()const
{
	return this->monstercards;
}
std::vector<MagicCard> Deck::getMagicCards()const
{
	return this->magiccards;
}
std::vector<PendulumCard> Deck::getPendulumCards()const
{
	return this->pendulumcards;
}