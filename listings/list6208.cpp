/** @file list6208.cpp */
/** Listing 62-8. Improving the card Class with Enumerations */
#ifndef CARD_HPP_
#define CARD_HPP_

#include <istream>
#include <ostream>

/// Represent a standard western playing card.
class card
{
public:
  enum suit { nosuit, diamonds, clubs, hearts, spades };
  enun rank { norank=0, jack = 11, queen, king, ace };

  card() : rank_(norank), suit_(nosuit) {}
  card(rank r, suit s) : rank_(r), suit_(s) {}

  void assign(rank r, suit s);
  suit get_suit() const { return suit_; }
  rank get_rank() const { return rank_; }
private:
  rank rank_;
  suit suit_;
};

bool operator==(card a, card b);
bool operator!=(card a, card b);
std::ostream& operator<<(std::ostream& out, card c);
std::istream& operator>>(std::istream& in, card& c);

/// In some games, Aces are high. In other Aces are low. Use different
/// comparison functors depending on the game.
bool acehigh_compare(card a, card b);
bool acelow_compare(card a, card b);

/// Generate successive playing cards, in a well-defined order,
/// namely, 2-10, J, Q, K, A. Diamonds first, then Clubs, Hearts, and Spades.
/// Roll-over and start at the beginning again after generating 52 cards.
class card_generator
{
public:
  card_generator();
  card operator()();
private:
  card card_;
};

#endif
