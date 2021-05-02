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
#include "Card.hpp"
#include <string>
#include <fstream>
class MonsterCard :virtual public Card {
public:
	MonsterCard() = default;
	MonsterCard(std::string input_name, std::string input_effect, unsigned int input_attack, unsigned int input_defense);

	void setName(const std::string input);
	void setEffect(const std::string input);
	void setAttackPoints(const std::string input);
	void setDefensePoints(const std::string input);

	std::string getName()const;
	std::string getEffect()const;
	unsigned int getAttackPoints()const;
	unsigned int getDefensePoints()const;
	std::string getInfo()const;            //gives all information about card

	friend std::ifstream& operator>>(std::ifstream& fin, MonsterCard& to_read);
protected:
	unsigned int attack, defense;
};
