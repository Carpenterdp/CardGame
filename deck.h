#ifndef DECK_H
#define DECK_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include "card.h"

class Deck {
private:
  std::vector<Card> cards;
  Card current;
  int card_position;

public:
  Deck();
  void loadDeck();
  void shuffle();
  void output();
  void removeCard();
  void pickCard();
  bool compare_card(std::string s, std::string v);
  bool compare_suit(std::string s);
  bool compare_rank(std::string v);
  std::string getCard();
  Card getCardIndex(int index);
  int deckSize();
  friend std::ofstream& operator<<(std::ofstream& os, Deck& c);
};


#endif 
