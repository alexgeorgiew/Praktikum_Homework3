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
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
class PendulumCard :public MagicCard,public MonsterCard{
public:
	PendulumCard() = default;
	PendulumCard(std::string input_name, std::string input_effect,unsigned int input_rarity, unsigned int input_attack, unsigned int input_defense, unsigned int input_pendulum,CardType input_type);

	std::string getName()const;
	std::string getEffect()const;
	unsigned int getAttackPoints()const;
	unsigned int getDefensePoints()const;
	std::string getStringType()const;
	unsigned int getPendulumScale()const;
	std::string getInfo()const;           //gives all information about card

	void setName(const std::string input);
	void setEffect(const std::string input);
	void setAttackPoints(const std::string input);
	void setDefensePoints(const std::string input);
	void setPendulumScale(const std::string input);
	void setType(const std::string input);

	bool operator>(const Card& input)const;
	bool operator<(const Card& input)const;

	friend std::ifstream& operator>>(std::ifstream& fin, PendulumCard& card);
private:
     unsigned int pendulumScale;
};