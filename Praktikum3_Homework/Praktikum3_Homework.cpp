#include <iostream>
#include "Duelist.hpp"
#include <iostream>


int main()
{  
    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine ofdestruction.", 43, 3000, 2500);
    MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare anattack.", 123, CardType::SPELL);
    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9,CardType::TRAP);
    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap MagicCards", 3, 1200, 600, 8, CardType::SPELL);
    Duelist firstDuelist("Ivan Ivanov");
    firstDuelist.getDeck().setDeckname("Magician Deck");
   
    firstDuelist.getDeck().addCard(&dragon);
    firstDuelist.getDeck().addCard(&swords);
    firstDuelist.getDeck().addCard(&magician);
    firstDuelist.getDeck().addCard(&cylinder);
    firstDuelist.getDeck().addCard(&timegazer);
    MagicCard box("Mystic Box", "Destroy one monster.", 0, CardType::SPELL);
    firstDuelist.getDeck().setCard(1, &box);
    firstDuelist.saveDeck("magician_deck.txt");
    return 0;
}


