#include <iostream>
#include "Duelist.hpp"
#include <iostream>


int main()
{  
    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine ofdestruction.", 43, 3000, 2500);
    MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare anattack.", 123, CardType::SPELL);
    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 339,CardType::TRAP);
    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap MagicCards", 3, 1200, 600, 8, CardType::SPELL);
    Duelist firstDuelist("Ivan Ivanov");
    firstDuelist.getDeck().setDeckname("Magician Deck");
   
    firstDuelist.getDeck().addCard(&dragon);
    firstDuelist.getDeck().addCard(&swords);
    firstDuelist.getDeck().addCard(&dragon);
    firstDuelist.getDeck().addCard(&dragon);
    firstDuelist.getDeck().addCard(&dragon);
    firstDuelist.saveDeck("magician_deck.txt");

    MagicCard box("Mystic Box", "Destroy one monster.", 0, CardType::SPELL);
    firstDuelist.getDeck().setCard(1, &box);
    Duelist secondDuelist("Gosho Goshev");
    secondDuelist.getDeck().addCard(&magician);
    secondDuelist.getDeck().addCard(&magician);
    secondDuelist.getDeck().addCard(&magician);
    secondDuelist.getDeck().addCard(&magician);
    secondDuelist.getDeck().addCard(&magician);

    ResultFight result=firstDuelist.duel(secondDuelist);
    if (result == ResultFight::remi)
    {
        std::cout << "remi";
    }
    else if (result == ResultFight::win_first)
    {
        std::cout << "win first";
    }
    else if (result == ResultFight::win_second)
    {
        std::cout << "win second";
    }
    if (swords > cylinder)std::cout<<"d";
    return 0;
}


