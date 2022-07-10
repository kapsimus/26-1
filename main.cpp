#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
#include <iomanip>

class Track {
    std::string name = "unnamed";
    std::tm date = {0};
    int duration;

public:
    void setName(const std::string& trackName) {
        if (!name.empty()) {
            name = trackName;
        }
    }

    void setDate(int year, int month, int day) {
        std::time_t t = time(nullptr);
        std::tm* tm = localtime(&t);
        if (year <= (tm->tm_year + 1900)) {
            date.tm_year = year - 1900;
        }
        if (month > 0 && month < 13) {
            date.tm_mon = month - 1;
        }
        if (day >= 1 && day <= 31) {
            date.tm_mday = day;
        }
    }

    void setDuration(int dur) {
        if (dur > 0) {
            duration = dur;
        }
        else {
            duration = 0;
        }
    }


    std::string getName() {
        return name;
    }

    std::tm* getDate() {
        return &date;
    }

    int getDuration() {
        return duration;
    }
};

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

    Player() {
       trackCount = 0;
       currentTrack = -1;
       playerMode = stop_mode;
    }
    void addTrack(Track track) {
        trackList.push_back(track);
        trackCount = trackList.size();
    }

    void play() {
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

    void pause() {
        if (playerMode == play_mode) {
            std::cout << "Track paused." << std::endl;
            playerMode = pause_mode;
        }
    }

    void stop() {
       if (playerMode == play_mode) {
           std::cout << "Track stopped." << std::endl;
           playerMode = stop_mode;
       }
    }

    void next() {
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

    void exit() {
        return;
    }
};

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
