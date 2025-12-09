g++ -o cards deck.cpp card.cpp cardgame.cpp driver.cpp `pkg-config --cflags --libs gtkmm-4.0` -o gtkmm_app -std=c++23
