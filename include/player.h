#pragma once
#include <vector>
#include "track.h"

class Player {
    std::vector<Track> trackList;
    enum mode {
        play_mode,
        pause_mode,
        stop_mode
    };
    mode playerMode;
    int trackCount;
    int currentTrack;

public:
    Player();
    void addTrack(const Track& track);
    void play();
    void pause();
    void stop();
    void next();
    void exit();
};
