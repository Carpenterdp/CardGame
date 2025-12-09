#include "deck.h"

  Deck::Deck() 
  { 
    loadDeck(); 
    shuffle();
    pickCard();
  }
  
  void Deck::loadDeck()
  {
    cards.clear();
    for (int x = 1; x <= 13; ++x)
    {
      cards.push_back(Card("Clubs", x));
    }
    for (int x = 1; x <= 13; ++x)
    {
      cards.push_back(Card("Hearts", x));
    }
    for (int x = 1; x <= 13; ++x)
    {
      cards.push_back(Card("Spades", x));
    }
    for (int x = 1; x <= 13; ++x)
    {
      cards.push_back(Card("Diamonds", x));
    }
  }
 
  void Deck::shuffle()
  {
 
    std::random_device rd;
    std::mt19937 gen{rd()};

    std::shuffle(cards.begin(), cards.end(), gen);

  }
 
  void Deck::output()
  {
    for (int count = 0; count < 52; ++count){
      std::cout << cards[count].get_rank() << " of ";
      std::cout << cards[count].get_suit() << std::endl;
    }
  }

  void Deck::removeCard()
  {
    cards.erase(cards.begin()+card_position);
  }
  
  void Deck::pickCard()
  {
     int x = rand() % (cards.size());
      
     card_position = x;
     current = cards[x];
  }
  
  bool Deck::compare_card(std::string s, std::string v)
  {
    if (s == current.get_suit() && v == current.get_rank()){ return true; }
    return false;
  }

  bool Deck::compare_suit(std::string s)
 {
    if (s == current.get_suit() ){ return true; }
    return false;
 }
  
  bool Deck::compare_rank(std::string v)
  {
    if ( v == current.get_rank()){ return true; }
    return false;
  }
  
  std::string Deck::getCard()
  {
    return (current.get_rank() + " of " + current.get_suit());
  }
  
  int Deck::deckSize()
  {
    return cards.size();
  }
  
  Card Deck::getCardIndex(int index)
  {
    return cards[index];
  }
  
  std::ofstream& operator<<(std::ofstream& os, Deck& c)
  {
    Card card;
    os << "\nDeck:\n";
    for (int count = 0; count < 52; ++count)
    {
      card = c.getCardIndex(count);
      os << card.get_rank() << " of ";
      os << card.get_suit() << std::endl;
    }
    os << std::endl;
    return os;
  }
