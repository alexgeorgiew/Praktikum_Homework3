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
#include "MagicCard.hpp"
#include <algorithm>
#include <random>
#include <iostream>
Deck::Deck(std::string input_name)
{
	this->name = input_name;
}
Deck::~Deck()
{
	Delete();
}
Deck& Deck::operator=(const Deck& input)
{
	if (this != &input)
	{
		this->Delete();
		for (int i = 0; i < input.cards.size(); i++)
		{
			this->cards.push_back(input.cards[i]->copy());
		}
	}
	return *this;
}
Deck::Deck(const Deck& input)
{
	for (int i = 0; i < input.cards.size(); i++)
	{
		this->cards.push_back(input.cards[i]->copy());
	}
}

unsigned int Deck::monsterCardsCount() const
{
	int result = 0;
	for (int i = 0; i < this->cards.size(); i++)
	{
		if (PendulumCard* pendulum = dynamic_cast<PendulumCard*>(cards[i]));
		else if (MonsterCard* monster = dynamic_cast<MonsterCard*>(cards[i]))
		{
			result++;
		}
	}
	return result;
}
unsigned int Deck::magicCardsCount() const
{
	int result = 0;
	for (int i = 0; i < this->cards.size(); i++)
	{
		if (PendulumCard* pendulum = dynamic_cast<PendulumCard*>(cards[i]));
		else if (MagicCard* monster = dynamic_cast<MagicCard*>(cards[i]))
		{
			result++;
		}
	}
	return result;
}
unsigned int Deck::pendulumCardsCount() const
{
	int result = 0;
	for (int i = 0; i < this->cards.size(); i++)
	{
		if (PendulumCard* monster = dynamic_cast<PendulumCard*>(cards[i]))
		{
			result++;
		}
	}
	return result;
}
unsigned int Deck::allcardsCount()const
{
	return this->cards.size();
}

void Deck::addCard(const Card* input)
{
	this->cards.push_back(input->copy());
}

void Deck::setCard(unsigned int index, const Card* input)
{
	if (PendulumCard* pendulum = dynamic_cast<PendulumCard*>(cards[index]))
	{
	    if (const PendulumCard* card_input = dynamic_cast<const PendulumCard*>(input))
	    {
		  delete pendulum;
		  this->cards[index] = input->copy();
	    }
	}
	else if (MagicCard* magic = dynamic_cast<MagicCard*>(cards[index]))
	{
		if (const MagicCard* card_input = dynamic_cast<const MagicCard*>(input))
		{
		   delete magic;        //not sure!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		   this->cards[index] = input->copy();
		}
	}
	else if (const MonsterCard* monster = dynamic_cast<const MonsterCard*>(cards[index]))
	{
		if (const MonsterCard* card_input = dynamic_cast<const MonsterCard*>(input))
		{
			delete monster;
			this->cards[index] = input->copy();
		}
	}
}
void Deck::setDeckname(std::string input)
{
	this->name = input;
}

void Deck::shuffle() {
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(this->cards), std::end(this->cards), rng);
}

void Deck::Delete()
{
	for (auto card : cards)
	{
		delete card;
	}
     this->cards.clear();
}

std::string Deck::getName()const
{
	return this->name;
}
std::ifstream& operator>>(std::ifstream& fin, Deck deck)
{
	std::string line;
	std::getline(fin, line);
	std::stringstream stream(line);
	std::string segments_of_line;
	std::vector<std::string> info;

	while (std::getline(stream, segments_of_line, '|'))             //get first line of the file separated on |
	{
		info.push_back(segments_of_line);
	}
	deck.setDeckname(info[0]);                               // we set new name for deck 
	for (int i = 0; i < std::stoi(info[1]); i++)
	{
		MonsterCard current;
		fin >> current;
		deck.addCard(&current);
	}
	for (int i = 0; i < std::stoi(info[2]); i++)
	{
		MagicCard current;
		fin>> current;
		deck.addCard(&current);
	}
	for (int i = 0; i < std::stoi(info[3]); i++)
	{
		PendulumCard current;
		fin >> current;
		deck.addCard(&current);
	}
	return fin;
}
std::ofstream& operator<<(std::ofstream& fout,Deck& deck)
{
	fout << deck.getName() + '|' + std::to_string(deck.monsterCardsCount()) + '|' + std::to_string(deck.magicCardsCount()) + '|' + std::to_string(deck.pendulumCardsCount()) + '\n';
	
	for (int i = 0; i < deck.allcardsCount(); i++)
	{
		if (PendulumCard* pendulum = dynamic_cast<PendulumCard*>(deck[i]));
		else
		{
			if (MonsterCard* monster = dynamic_cast<MonsterCard*>(deck[i]))
			{
				fout << monster->getInfo();
			}
		}
	}	
	for (int i = 0; i < deck.allcardsCount(); i++)
	{
		if (PendulumCard* pendulum = dynamic_cast<PendulumCard*>(deck[i]));
		else
		{
			if (MagicCard* magic = dynamic_cast<MagicCard*>(deck[i]))
			{
				fout << magic->getInfo();
			}
		}
	}
	for (int i = 0; i < deck.allcardsCount(); i++)
	{
		if (PendulumCard* pendulum = dynamic_cast<PendulumCard*>(deck[i]))
		{
			fout << pendulum->getInfo();
		}
	}
	return fout;
}
Card* Deck::operator[](const unsigned index)const
{
	return this->cards[index];
}