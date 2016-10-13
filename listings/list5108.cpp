/** @file list5108.cpp */
/** Listing 51-8. Playing High-Card with a list */
#include <iostream>
#include <list>
#include <ostream>

#include "card.hpp"
#include "randomint.hpp"

int main()
{
  std::list<card> deck(52);
  std::generate(deck.begin(), deck.end(), card_generator());

  for (int i(0); i != 10; ++i)
  {
    randomint picker(0, deck.size() - 1);

    std::list<card>::iterator computer_pick(deck.begin());
    std::advance(computer_pick, picker());
    std::cout << "I picked " << *computer_pick << '\n';

    std::list<card>::iterator user_pick(deck.begin());
    std::advance(user_pick, picker());
    std::cout << "You picked " << *user_pick << '\n';

    if (acehigh_compare(*computer_pick, *user_pick))
      std::cout << "You win.\n";
    else
      std::cout << "I win.\n";

    // Discard the two cards.
    deck.erase(computer_pick);
    deck.erase(user_pick);
  }
}
