
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
#include <fstream>
#include <sstream>
#include <vector>
enum CardType
{
	TRAP= 0,
    BUFF = 1,
	SPELL=2,
};

class MagicCard :virtual public Card
{
public:
	MagicCard() = default;
	MagicCard(std::string input_name, std::string input_effect,unsigned int input_rarity, CardType input_type);
	std::string getName()const;
	std::string getEffect()const;
	std::string getStringType()const;
	std::string getInfo()const;          //gives all the information about carda

	void setName(std::string input);
	void setEffect(std::string input);
	void setType(std::string input);

	bool operator>(const Card& input)const;
	bool operator<(const Card& input)const;
	friend std::ifstream& operator>>(std::ifstream& fin, MagicCard& card);
	friend std::ofstream& operator<<(std::ofstream& fout,MagicCard& card);
protected:
	CardType type;
};