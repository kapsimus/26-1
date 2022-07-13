#pragma once
#include <string>
#include <ctime>

class Track {
    std::string name = "unnamed";
    std::tm date = {0};
    int duration;

public:
    void setName(const std::string &trackName);
    void setDate(int year, int month, int day);
    void setDuration(int dur);
    std::string getName();
    std::tm* getDate();
    int getDuration();
};