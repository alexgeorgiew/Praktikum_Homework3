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
	Deck(std::string input_name);  //add vector
	Deck(const Deck& input);
	~Deck();
	Deck& operator=(const Deck& input);
	Card* operator[](const unsigned index)const;
	unsigned int monsterCardsCount() const;
	unsigned int magicCardsCount() const;
	unsigned int pendulumCardsCount() const;
	unsigned int allcardsCount()const;
	void addCard(const Card* input);
	void setCard(unsigned int index,const Card* input);
	void shuffle();
	void setDeckname(const std::string input);
	void Delete();

	std::vector<Card*> getCards()const;
	std::string getName()const;

	friend std::ifstream& operator>>(std::ifstream& fin, Deck& deck);
	friend std::ofstream& operator<<(std::ofstream& fout, Deck& deck);
private:
	std::string name;
	std::vector<Card*> cards;
};