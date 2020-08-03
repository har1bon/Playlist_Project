//
// Created by harri on 6/11/2020.
//

#include "Song.h"


///////////////////////////////
//Constructors
///////////////////////////////

Song::Song(std::string inputName, std::string inputFirstLine, int initialCount) {
    this->songName = inputName;
    this->firstLine = inputFirstLine;
    this->playCount = initialCount;
}

Song::~Song() {}


//////////////////////////////////////
//SETTERS
//////////////////////////////////////

void Song::SetSongName(std::string inputName) {
    songName = inputName;
}

void Song::SetInitialLine(std::string inputLine) {
    firstLine = inputLine;
}

void Song::IncrementCount() {
    ++playCount;
}

//////////////////////////////////////
//GETTERS
//////////////////////////////////////

std::string Song::GetSongName() const {
    return songName;
}

std::string Song::GetInitialLine() const {
    return firstLine;
}

int Song::GetPlayCount() const {
    return playCount;
}


