#include "card.h"
#include <print>

  Card::Card() : suit(""), value(0){}
  
  Card::Card(const std::string &_suit, const int& value) : suit(_suit), value(value){ }
  
  std::string Card::get_suit() 
  {
    return suit;
  }

  std::string Card::get_rank()
  {
    switch (value) {
      case ACE:
        return "Ace";
        break;
      case TWO:
        return "Two";
        break;
      case THREE:
        return "Three";
        break;
      case FOUR:
        return "Four";
        break;
      case FIVE:
        return "Five";
        break;
      case SIX:
        return "Six";
        break;
      case SEVEN:
        return "Seven";
        break;
      case EIGHT:
        return "Eight";
        break;
      case NINE:
        return "Nine";
        break;
      case TEN:
        return "Ten";
        break;
      case JACK:
        return "Jack";
        break;
      case QUEEN:
        return "Queen";
        break;
      case KING:
        return "King";
        break;
    }
    
    return "Error";
  }

void Card::display()
{
  std::cout << get_rank() << " of " << get_suit() << std::endl;
}
