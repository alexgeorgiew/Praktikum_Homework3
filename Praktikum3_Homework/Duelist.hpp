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
#include "Deck.hpp"
#include <string>

enum ResultFight {
	 can_not_start = 0,
     win_first = 1,
     win_second = 2,
     remi = 3,
};

class Duelist {
public:
	Duelist() = default;
	Duelist(std::string input_name);

	Deck& getDeck();
	std::string getName()const;
	bool saveDeck(const std::string filename)const;
	bool loadDeck(const std::string filename);
	ResultFight duel(Duelist& second_duelist);
	void display()const;
private:
	std::string name;
	Deck deck;
};

