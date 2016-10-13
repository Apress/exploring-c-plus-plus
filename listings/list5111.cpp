/** @file list5111.cpp */
/** Listing 51-11. Playing High-Card Using an Explicit Specialization of std::less */
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>
#include <set>

#include "card.hpp"
#include "randomint.hpp"

namespace std
{
  template<>
  class less<card> : std::binary_function<card, card, bool>
  {
  public:
    bool operator()(card a, card b) const { return acehigh_compare(a, b); }
  };
}

int main()
{
  typedef std::set<card> cardset;
  cardset deck;
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
