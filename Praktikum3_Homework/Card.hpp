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
#include <string>
class Card {
public:
	Card() = default;
	Card(std::string input_name, std::string input_effect);
protected:
	std::string name, effect;
};