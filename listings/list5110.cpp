/** @file list5110.cpp */
/** Listing 51-10. Playing High-Card with a set */
#include <iostream>
#include <iterator>
#include <ostream>
#include <set>

#include "card.hpp"
#include "randomint.hpp"

int main()
{
  typedef std::set<card, bool(*)(card, card)> cardset;
  cardset deck(acehigh_compare);
  std::generate_n(std::inserter(deck, deck.begin()), 52, card_generator());

  for (int i(0); i != 10; ++i)
  {
    randomint picker(0, deck.size() - 1);

    cardset::iterator computer_pick(deck.begin());
    std::advance(computer_pick, picker());
    std::cout << "I picked " << *computer_pick << '\n';

    cardset::iterator user_pick(deck.begin());
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
