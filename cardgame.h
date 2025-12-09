#ifndef CARDGAME_H
#define CARDGAME_H

#include "deck.h"
#include <fstream>
#include <format>
#include <gtkmm.h>

enum { GUESS_SUIT = 1, GUESS_RANK, GUESS_BOTH, };

class CardGame : public Gtk::Window 
{
  private:
    //Member widgets:
    Gtk::Label card_count_label, game_status;
    Gtk::Image cardFace;
    Gtk::ComboBoxText e_suit, e_rank, game_style; 
    Gtk::Box button_box, box, combo;
    Gtk::Button restart_button, continue_button, guess_button;
    Deck cards;   
    std::ofstream logs;
    int score;

  public:
    CardGame();

  protected:
    //Signal handlers:
    void on_button_guess_clicked();
    void on_button_restart_clicked();
    void on_button_next_clicked();

    int get_game_style();
};

#endif
