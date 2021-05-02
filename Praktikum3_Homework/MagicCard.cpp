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
#include "MagicCard.hpp"
#include <iostream>
MagicCard::MagicCard(std::string input_name, std::string input_effect, CardType input_type):Card(input_name, input_effect)
{
	this->type = input_type;
}
std::string MagicCard::getName()const
{
	return Card::name;
}
std::string MagicCard::getEffect()const
{
	return Card::effect;
}
std::string MagicCard::getStringType()const
{
	if (this->type == CardType::TRAP)return "TRAP";
	else if (this->type == CardType::BUFF)return "BUFF";
	else return "SPELL";
}
std::string MagicCard::getInfo()const
{
	std::string result;
	result = this->getName() + '|' + this->getEffect() + '|' + this->getStringType() + '\n';
	return result;

}
void MagicCard::setName(std::string input)
{
    Card::name = input;
}
void MagicCard::setEffect(std::string input)
{
    Card::effect = input;
}
void MagicCard::setType(std::string input)
{
    if (input == "TRAP")this->type = CardType::TRAP;
    else if (input == "BUFF")this->type = CardType::BUFF;
    else this->type = CardType::SPELL;
}
std::ifstream& operator>>(std::ifstream& fin, MagicCard& card)
{
    std::string line;
    std::getline(fin , line);
    std::stringstream stream(line);
    std::string segment;
    std::vector<std::string> info;

    while (std::getline(stream, segment, '|'))
    {
        info.push_back(segment);
    }

    card.setName(info[0]);
    card.setEffect(info[1]);
    card.setType(info[2]);

	return fin;
}