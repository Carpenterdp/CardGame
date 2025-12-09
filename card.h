#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, };
 
class Card {
private:
  std::string suit;
  int value;

public: 

  Card();
  Card(const std::string& _suit, const int &value);
  std::string get_suit();
  std::string get_rank();
  void display();

};

#endif 
