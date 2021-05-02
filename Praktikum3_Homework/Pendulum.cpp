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
#include "Pendulum.hpp"

PendulumCard::PendulumCard(std::string input_name, std::string input_effect, unsigned int input_attack, unsigned int input_defense, unsigned int input_pendulumScale, CardType input_type)
	:Card(input_name, input_effect),MagicCard(input_name, input_effect, input_type),MonsterCard(input_name, input_effect, input_attack, input_defense)
{
	this->pendulumScale = input_pendulumScale;
}
std::string PendulumCard::getName()const
{
	return Card::name;
}
std::string PendulumCard::getEffect()const
{
	return Card::effect;
}
unsigned int PendulumCard::getAttackPoints()const
{
	return MonsterCard::attack;
}
unsigned int PendulumCard::getDefensePoints()const
{
	return MonsterCard::defense;
}
std::string PendulumCard::getStringType()const
{
	return MagicCard::getStringType();
}
unsigned int PendulumCard::getPendulumScale()const
{
	return this->pendulumScale;
}
std::string PendulumCard::getInfo()const
{
	std::string result;
	result = this->getName() + '|' + this->getEffect() + '|' + std::to_string(this->getAttackPoints()) + '|' + std::to_string(this->getDefensePoints()) + '|' + std::to_string(this->pendulumScale) + '|' + this->getStringType()+'\n';
	return result;
}
void PendulumCard::setName(const std::string input)
{
	Card::name = input;
}
void PendulumCard::setEffect(const std::string input)
{
	Card::effect = input;
}
void PendulumCard::setAttackPoints(const std::string input)
{
	MonsterCard::setAttackPoints(input);
}
void PendulumCard::setDefensePoints(const std::string input)
{
	MonsterCard::setDefensePoints(input);
}
void PendulumCard::setPendulumScale(const std::string input)
{
	std::stringstream stream(input);
	stream >> this->pendulumScale;
}
void PendulumCard::setType(const std::string input)
{
	MagicCard::setType(input);
}
std::ifstream& operator>>(std::ifstream& fin, PendulumCard& card)
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
	card.setAttackPoints(info[2]);
	card.setDefensePoints(info[3]);
	card.setPendulumScale(info[4]);
	card.setType(info[5]);
	return fin;
}