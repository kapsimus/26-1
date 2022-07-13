#include <iostream>
#include "track.h"
#include "player.h"

int main()
{
    std::string op;
    Track tempTrack;
    Player* player = new Player();
    //create tracklist
    tempTrack.setName("Song 1");
    tempTrack.setDate(1999, 01, 01);
    tempTrack.setDuration(300);
    player->addTrack(tempTrack);
    tempTrack.setName("Song 2");
    tempTrack.setDate(2001, 10, 02);
    tempTrack.setDuration(200);
    player->addTrack(tempTrack);
    tempTrack.setName("Song 3");
    tempTrack.setDate(2002, 03, 11);
    tempTrack.setDuration(310);
    player->addTrack(tempTrack);
    tempTrack.setName("Song 4");
    tempTrack.setDate(2020, 11, 21);
    tempTrack.setDuration(110);
    player->addTrack(tempTrack);

    do {
        std::cout << "Enter command: ";
        std::getline(std::cin, op);
        if (op == "play") {
            player->play();
        }
        if (op == "pause") {
            player->pause();
        }
        if (op == "stop") {
            player->stop();
        }
        if (op == "next") {
            player->next();
        }

    } while (op != "exit");
    delete player;
}
