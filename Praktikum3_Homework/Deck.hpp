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
#pragma once

#include "Pendulum.hpp"
#include <string>
#include <vector>
class Deck {
public:
	Deck() = default;
	Deck(std::string input_name, std::vector<MonsterCard> input_monsters, std::vector<MagicCard> input_magicians, std::vector<PendulumCard> input_pendulums);

	unsigned int monsterCardsCount() const;
	unsigned int magicCardsCount() const;
	unsigned int pendulumCardsCount() const;
	void addMonsterCard(const MonsterCard& card);
	void addMagicCard(const MagicCard& card);
	void addPendulumCard(const PendulumCard& card);
	void setDeckname(const std::string input);
	void setMonsterCard(const unsigned int index,const MonsterCard& card);
	void setMagicCard(const unsigned int index,const MagicCard& card);
	void setPendulumCard(const unsigned int index,const PendulumCard& card);
	void Delete();

	std::string getName()const;
	std::vector<MonsterCard> getMonsterCards()const;
	std::vector<MagicCard> getMagicCards()const;
	std::vector<PendulumCard> getPendulumCards()const;

	friend std::ifstream& operator>>(std::ifstream& fin, Deck deck);
	friend std::ofstream& operator<<(std::ofstream& fout, Deck deck);
private:
	std::string name;
	std::vector<MonsterCard> monstercards;
	std::vector<MagicCard> magiccards;
	std::vector<PendulumCard> pendulumcards;
};