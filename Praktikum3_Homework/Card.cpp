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
#include "Card.hpp"

Card::Card(std::string input_name, std::string input_effect, unsigned int rarity):name(input_name),effect(input_effect),rarity(rarity)
{

}
unsigned int Card::getRarity()const
{
	return this->rarity;
}
void Card::setRarity(unsigned int input)
{
	this->rarity = input;
}
bool Card::operator>(const Card& input)
{
	if (this->rarity > input.getRarity())return true;
	return false;
}
bool Card::operator<(const Card& input)
{
	if (this->rarity < input.getRarity())return true;
	return false;
}