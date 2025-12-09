/*
Name: Devan Carpenter
Date: 12/8/2025
Author: Devan Carpenter
Description: A gui applications to play a card game where you try and guess the card out of 52 different cards. You will either guess the face, the value, or both. 
Special-Concerns: It is not plug and play accross all platforms you will need the correct libraries to run it. gtkmm 4.0 dependencies on a ubuntu 25.10 system.
 *
 */

#include <cstdlib>
#include <gtkmm.h>
#include "cardgame.h"


int main(int argc, char* argv[])
{
    srand(time(0));
    auto app = Gtk::Application::create("org.g.cardgame");

    return app->make_window_and_run<CardGame>(argc, argv);

}
