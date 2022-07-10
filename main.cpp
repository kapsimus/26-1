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
    void setName(const std::string& name) {
        if (!name.empty()) {
            this->name = name;
        }
    }

    void setDate(int year, int month, int day) {
        std::time_t t = time(nullptr);
        std::tm* tm = localtime(&t);
        if (year <= tm->tm_year) {
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
    mode playerMode = stop_mode;
    int trackCount = 0;
    int currentTrack = 0;

public:

    void addTrack(Track track) {
        trackList.push_back(track);
        trackCount = trackList.size();
    }

    void play() {
        if (!trackList.empty()) {
            if (playerMode == stop_mode) {
                std::string name;
                std::cout << "Enter track name: ";
                std::cin >> name;
                for (int i = 0; i < trackCount; i++) {
                    if (trackList[i].getName() == name) {
                        currentTrack = i;
                        std::tm* tm = trackList[i].getDate();
                        std::cout << "Played track:" << std::endl;
                        std::cout << trackList[i].getName() << std::put_time(tm, "%Y:%M:%D") << " duration: " <<
                                  trackList[i].getDuration() / 60 << " min, " << trackList[i].getDuration() % 60 << " sec." << std::endl;
                        break;
                    }
                }
            }
            if (playerMode == pause_mode) {

            }
        }

    }

    void pause() {

    }

    void stop() {

    }

    void exit() {

    }
};

int main()
{
    std::cout << "Hello World!\n";
}
