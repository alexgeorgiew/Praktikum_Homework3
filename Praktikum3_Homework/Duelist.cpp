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

std::string Duelist::getName()const
{
	return this->name;
}

bool Duelist::saveDeck(const std::string filename)const
{
	std::ofstream file(filename, std::ios::out);
	if (file.is_open())
	{
		file << this->deck.getName() + '|' + std::to_string(this->deck.monsterCardsCount()) + '|' + std::to_string(this->deck.magicCardsCount()) + '|' + std::to_string(this->deck.pendulumCardsCount()) + '\n';
		for (int i = 0; i < this->deck.allcardsCount(); i++)
		{
			if (PendulumCard* pendulum = dynamic_cast<PendulumCard*>(this->deck[i]));
			else
			{
				if (MonsterCard* monster = dynamic_cast<MonsterCard*>(this->deck[i]))
				{
					file << monster->getInfo();
				}
			}
		}
		for (int i = 0; i < this->deck.allcardsCount(); i++)
		{
			if (PendulumCard* pendulum = dynamic_cast<PendulumCard*>(this->deck[i]));
			else
			{
				if (MagicCard* magic = dynamic_cast<MagicCard*>(this->deck[i]))
				{
					file << magic->getInfo();
				}
			}
		}
		for (int i = 0; i < this->deck.allcardsCount(); i++)
		{
			if (PendulumCard* pendulum = dynamic_cast<PendulumCard*>(this->deck[i]))
			{
				file << pendulum->getInfo();
			}
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
				this->deck.addCard(&current);
			}
			for (int i = 0; i < std::stoi(info[2]); i++)
			{
				MagicCard current;
				file >> current;
				this->deck.addCard(&current);
			   
			}
			for (int i = 0; i < std::stoi(info[3]); i++)
			{
				PendulumCard current;
				file >> current;
				this->deck.addCard(&current);
		
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

	for (int i = 0; i < this->deck.allcardsCount(); i++)
	{
		if (PendulumCard* pendulum = dynamic_cast<PendulumCard*>(this->deck[i]));
		else
		{
			if (MonsterCard* monster = dynamic_cast<MonsterCard*>(this->deck[i]))
			{
				std::cout << i;
				std::cout << monster->getInfo();
			}
		}
	}
	for (int i = 0; i < this->deck.allcardsCount(); i++)
	{
		if (PendulumCard* pendulum = dynamic_cast<PendulumCard*>(this->deck[i]));
		else
		{
			if (MagicCard* magic = dynamic_cast<MagicCard*>(this->deck[i]))
			{
				std::cout << i;
				std::cout << magic->getInfo();
			}
		}
	}
	for (int i = 0; i < this->deck.allcardsCount(); i++)
	{
		if(PendulumCard* pendulum = dynamic_cast<PendulumCard*>(this->deck[i]))
		{
			std::cout << i;
			std::cout << pendulum->getInfo();
		}
	}
}

ResultFight Duelist::duel(Duelist& second_duelist)
{
	if (this->deck.allcardsCount() == second_duelist.getDeck().allcardsCount())
	{
		unsigned int points_first = 0, points_second = 0;
		second_duelist.getDeck().shuffle();
		this->getDeck().shuffle();
		for (int i = 0; i < this->getDeck().allcardsCount(); i++)
		{
			if (*(this->getDeck()[i]) > *(second_duelist.getDeck()[i]))
			{
				points_first++;
				
			}
			else if (*(this->getDeck()[i]) < *(second_duelist.getDeck()[i]))
			{
				points_second++;
			}
		}
		if (points_first == points_second)return ResultFight::remi;
		else if (points_first > points_second)return ResultFight::win_first;
		return win_second;
	}
	else
	{
		return ResultFight::can_not_start;
	}
}