#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include "track.h"
#include "player.h"

Player::Player() {
    trackCount = 0;
    currentTrack = -1;
    playerMode = stop_mode;
}
void Player::addTrack(const Track& track) {
    trackList.push_back(track);
    trackCount = trackList.size();
}

void Player::play() {
    if (!trackList.empty()) {
        if (playerMode == stop_mode) {
            std::string name;
            std::cout << "Enter track name: ";
            std::getline(std::cin, name);
            for (int i = 0; i < trackCount; i++) {
                if (trackList[i].getName() == name) {
                    currentTrack = i;
                    std::tm* tm = trackList[i].getDate();
                    std::cout << "Played track:" << std::endl;
                    std::cout << trackList[i].getName() << " " << std::put_time(tm, "%Y:%m:%d") << " duration: " <<
                              trackList[i].getDuration() / 60 << " min, " << trackList[i].getDuration() % 60 << " sec." << std::endl;
                    break;
                }
            }
            playerMode = play_mode;
        }
        if (playerMode == pause_mode) {
            std::tm* tm = trackList[currentTrack].getDate();
            std::cout << "Played track:" << std::endl;
            std::cout << trackList[currentTrack].getName() << " " << std::put_time(tm, "%Y:%m:%d") <<
                      " duration: " << trackList[currentTrack].getDuration() / 60 << " min, " <<
                      trackList[currentTrack].getDuration() % 60 << " sec." << std::endl;
            playerMode = play_mode;
        }
    }

}

void Player::pause() {
    if (playerMode == play_mode) {
        std::cout << "Track paused." << std::endl;
        playerMode = pause_mode;
    }
}

void Player::stop() {
    if (playerMode == play_mode) {
        std::cout << "Track stopped." << std::endl;
        playerMode = stop_mode;
    }
}

void Player::next() {
    if (trackCount > 1) {
        int selectTrack;
        do {
            selectTrack = std::rand() % trackCount;
        } while (selectTrack == currentTrack);
        currentTrack = selectTrack;
        playerMode = pause_mode;
        play();
    } else if (trackCount == 1) {
        currentTrack = 0;
        playerMode = pause_mode;
        play();
    }
}

void Player::exit() {
    return;
}

