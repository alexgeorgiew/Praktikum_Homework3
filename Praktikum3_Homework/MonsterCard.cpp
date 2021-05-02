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
#include "MonsterCard.hpp"
#include <string>
#include <sstream>
#include <vector>

MonsterCard::MonsterCard(std::string input_name, std::string input_effect, unsigned int input_attack, unsigned int input_defense):Card(input_name, input_effect)
{
    this->attack = input_attack;
    this->defense = input_defense;
}
void MonsterCard::setName(const std::string input)
{
    Card::name = input;
}
void MonsterCard::setEffect(const std::string input)
{
    Card::effect = input;
}
void MonsterCard::setAttackPoints(const std::string input)
{
    unsigned int attack;
    std::stringstream stream(input);
    stream >> attack;
    this->attack = attack;
}
void MonsterCard::setDefensePoints(const std::string input)
{
    unsigned int defense;
    std::stringstream stream(input);
    stream >> defense;
    this->defense = defense;
}
std::string MonsterCard::getName()const
{
    return Card::name;
}
std::string MonsterCard::getEffect()const
{
    return Card::effect;
}
unsigned int  MonsterCard::getAttackPoints()const
{
    return this->attack;
}
unsigned int  MonsterCard::getDefensePoints()const
{
    return this->defense;
}
std::string MonsterCard::getInfo()const
{
    std::string result;
    result = this->getName() + '|' + this->getEffect() + '|' + std::to_string(this->attack) + '|' + std::to_string(this->defense) + '\n';
    return result;
}

std::ifstream& operator>>(std::ifstream& fin, MonsterCard& to_read)
{
    std::string line;
    std::getline(fin, line);
    std::stringstream stream(line);
    std::string segment;
    std::vector<std::string> info;

    while (std::getline(stream, segment, '|'))
    {
        info.push_back(segment);
    }
    to_read.setName(info[0]);
    to_read.setEffect(info[1]);
    to_read.setAttackPoints(info[2]);
    to_read.setDefensePoints(info[3]);
    return fin;
}
