/** @file list5112.cpp */
/** Listing 51-12. Playing High-Card with an unordered_set */
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>
#include <unordered_set>

#include "card.hpp"
#include "randomint.hpp"

namespace std { namespace tr1
{
  template<>
  class hash<card>
  {
  public:
    std::size_t operator()(card a)
    const
    {
      return hash<card::suit>()(a.get_suit()) + hash<card::rank>()(a.get_rank());
    }
  };
} }

int main()
{
  typedef std::tr1::unordered_set<card> cardset;
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
