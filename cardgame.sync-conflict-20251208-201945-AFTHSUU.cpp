#include "cardgame.h"
#include <iostream>

CardGame::CardGame()
  : restart_button("Restart Game"),
    guess_button("Submit Guess"),
    continue_button("Continue"),
    logs("game_logs.txt")
{
  logs << "Deck of Cards:\n"
  logs << cards;
  set_title("Cards Guessing Game Game");
  cardFace.set("images/cardBack.png");
  card_count_label.set_text("52 Cards Remain");

  set_default_size(800, 450);
  card_count_label.set_margin_top(20);
  cardFace.set_pixel_size(200);
  cardFace.set_margin(10);
  combo.set_margin(20);
  e_rank.set_margin_bottom(10);
  e_rank.set_margin_top(10);
  guess_button.set_margin_start(10);
  guess_button.set_margin_end(10);
  game_status.set_margin_top(20);
  game_status.set_margin_bottom(20);

  box.set_orientation(Gtk::Orientation::VERTICAL);
  button_box.set_orientation(Gtk::Orientation::HORIZONTAL);
  combo.set_orientation(Gtk::Orientation::VERTICAL);

  combo.append(e_suit);
  combo.append(e_rank);
  combo.append(game_style);

  button_box.append(restart_button);
  button_box.append(guess_button);
  button_box.append(continue_button);

  restart_button.signal_clicked().connect( sigc::mem_fun(*this,
              &CardGame::on_button_restart_clicked) );
  guess_button.signal_clicked().connect( sigc::mem_fun(*this,
              &CardGame::on_button_guess_clicked) );
  continue_button.signal_clicked().connect( sigc::mem_fun(*this,
              &CardGame::on_button_next_clicked) );

  button_box.set_halign(Gtk::Align::CENTER);

  box.append(card_count_label);
  box.append(cardFace);
  box.append(combo);
  box.append(button_box);
  box.append(game_status);

  e_suit.append("Choose a Suit...");
  e_suit.append("Clubs");
  e_suit.append("Hearts");
  e_suit.append("Spades");
  e_suit.append("Diamonds");
  e_suit.set_active(0);

  e_rank.append("Choose a Rank...");
  e_rank.append("Ace");
  e_rank.append("Two");
  e_rank.append("Three");
  e_rank.append("Four");
  e_rank.append("Five");
  e_rank.append("Six");
  e_rank.append("Seven");
  e_rank.append("Eight");
  e_rank.append("Nine");
  e_rank.append("Ten");
  e_rank.append("Jack");
  e_rank.append("Queen");
  e_rank.append("King");
  e_rank.set_active(0);

  game_style.append("Guess by Suit");
  game_style.append("Guess by Rank");
  game_style.append("Guess by Both");
  game_style.set_active(0);

  set_child(box);

}

 
void CardGame::on_button_guess_clicked()
{
  if (game_status.get_label() != "" && game_status.get_label() != "You Must Guess First") 
  {
    game_status.set_text("Click Continue to Play More");
    return; 
  }
  int style = get_game_style();
  std::string suit = e_suit.get_active_text();
  std::string rank = e_rank.get_active_text();
  std::string card_image = std::format( "images/{}.png", cards.getCard());

switch(style)
{
  case GUESS_SUIT:
      logs << "Guess by Suit: \n";
      logs << "Guess: " << suit << std::endl;
      if(cards.compare_suit(suit)) 
      {
        game_status.set_text("You are correct!");
        std::cout << "You are correct!\n\n";
      } else { 
        game_status.set_text("You guessed wrong!"); 
        std::cout << "You guessed wrong!\n\n";
      }
    break;
  
  case GUESS_RANK:
      logs << "Guess by Rank: \n";
      logs << "Guess: " << rank << std::endl;
      if(cards.compare_rank(rank)) 
      {
        game_status.set_text("You are correct!");
        logs << "You are correct!\n\n"; 
      }else { 
        game_status.set_text("You guessed wrong!"); 
        logs << "You guessed wrong!\n\n";
      }
    break;

  case GUESS_BOTH:
      logs << "Guess by Rank: \n";
      logs << "Guess: " << rank << " of " << suit << std::endl;

      if(cards.compare_card(suit, rank)) 
      {
        game_status.set_text("You are correct!");
        logs << "You are correct!\n\n";
      } else { 
        game_status.set_text("You guessed wrong!"); 
        logs << "You guessed wrong!\n\n";
      }
    break;

  default:
    logs << "error!\n";
    break;
  }

  cardFace.set(card_image);
}

void CardGame::on_button_restart_clicked()
{
  cardFace.set("images/cardBack.png");
  card_count_label.set_text("52 Cards Remain");


}

void CardGame::on_button_next_clicked()
{
  if (game_status.get_label() == "" || game_status.get_label() == "You Must Guess First") 
  {
    game_status.set_text("You Must Guess First");
    return;
  }
  
  cards.removeCard();
  cards.pickCard();
  std::string cardsRemaining = std::format("{} Cards Remain", cards.deckSize());

  cardFace.set("images/cardBack.png");
  card_count_label.set_text(cardsRemaining);
  game_status.set_text("");

}

int CardGame::get_game_style() 
{
  std::string  style = game_style.get_active_text();

  if (style == "Guess by Suit") return 1;
  if (style == "Guess by Rank") return 2;
  if (style == "Guess by Both") return 3;
  return -1;
}

