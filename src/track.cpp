#include <string>
#include <ctime>
#include "track.h"


void Track::setName(const std::string& trackName) {
    if (!name.empty()) {
        name = trackName;
    }
}

void Track::setDate(int year, int month, int day) {
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

void Track::setDuration(int dur) {
    if (dur > 0) {
        duration = dur;
    }
    else {
        duration = 0;
    }
}

std::string Track::getName() {
    return name;
}

std::tm* Track::getDate() {
    return &date;
}

int Track::getDuration() {
    return duration;
}
