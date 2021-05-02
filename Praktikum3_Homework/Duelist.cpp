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
#include "Duelist.hpp"
#include <fstream>
#include <iostream>
Duelist::Duelist(std::string input_name)
{
	this->name = input_name;
}
Deck& Duelist::getDeck()
{
	return this->deck;
}
bool Duelist::saveDeck(const std::string filename)const
{
	std::ofstream file(filename, std::ios::out);
	if (file.is_open())
	{
		file << this->deck.getName() + '|' + std::to_string(this->deck.monsterCardsCount()) + '|' + std::to_string(this->deck.magicCardsCount()) + '|' + std::to_string(this->deck.pendulumCardsCount()) + '\n';
		std::vector<MonsterCard> monsters = this->deck.getMonsterCards();
		for (int i = 0; i < this->deck.monsterCardsCount(); i++)
		{
			file << monsters[i].getInfo();
		}
		std::vector<MagicCard> magicians = this->deck.getMagicCards();
		for (int i = 0; i < this->deck.magicCardsCount(); i++)
		{
			file << magicians[i].getInfo();
		}
		std::vector<PendulumCard> pendulums = this->deck.getPendulumCards();
		for (int i = 0; i < this->deck.pendulumCardsCount(); i++)
		{
			file << pendulums[i].getInfo();
		}
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
}
bool Duelist::loadDeck(const std::string filename)
{
	this->deck.Delete();
	std::ifstream file(filename, std::ios::in);
		if (file.is_open())
		{
			std::string line;
			std::getline(file, line);
			std::stringstream stream(line);
			std::string segments_of_line;
			std::vector<std::string> info;

			while (std::getline(stream, segments_of_line, '|'))             //get first line of the file separated on |
			{
				info.push_back(segments_of_line);
			}
			this->deck.setDeckname(info[0]);                               // we set new name for deck 
			for (int i = 0; i < std::stoi(info[1]); i++)
			{
				MonsterCard current;
				file >> current;
				this->deck.addMonsterCard(current);
			}
			for (int i = 0; i < std::stoi(info[2]); i++)
			{
				MagicCard current;
				file >> current;
				this->deck.addMagicCard(current);
			}
			for (int i = 0; i < std::stoi(info[3]); i++)
			{
				PendulumCard current;
				file >> current;
				this->deck.addPendulumCard(current);
			}
			file.close();
			return true;
		}
		else
		{
			file.close();
			return false;
		}
}
void Duelist::display()const
{
	std::cout << this->deck.getName() + '|' + std::to_string(this->deck.monsterCardsCount()) + '|' + std::to_string(this->deck.magicCardsCount()) + '|' + std::to_string(this->deck.pendulumCardsCount()) + '\n';
	std::vector<MonsterCard> monsters = this->deck.getMonsterCards();
	for (int i = 0; i < this->deck.monsterCardsCount(); i++)
	{
		std::cout << monsters[i].getInfo();
	}
	std::vector<MagicCard> magicians = this->deck.getMagicCards();
	for (int i = 0; i < this->deck.magicCardsCount(); i++)
	{
		std::cout << magicians[i].getInfo();
	}
	std::vector<PendulumCard> pendulums = this->deck.getPendulumCards();
	for (int i = 0; i < this->deck.pendulumCardsCount(); i++)
	{
		std::cout << pendulums[i].getInfo();
	}
}