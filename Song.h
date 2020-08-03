//
// Created by harri on 6/11/2020.
//

#ifndef PLAYLISTPROJECT_SONG_H
#define PLAYLISTPROJECT_SONG_H

#include <iostream>
#include <vector>


class Song {
public:

    ////////////////////////////////////////
    //CONSTRUCTORS
    ////////////////////////////////////////
    Song(std::string inputName = "none", std::string inputFirstLine = "none", int initialCount = 0);

    ~Song();

    ////////////////////////////////////////
    //SETTERS
    ///////////////////////////////////////

    void SetSongName(std::string inputName);

    void SetInitialLine(std::string inputLine);

    void IncrementCount();

    //////////////////////////////////////
    //GETTERS
    //////////////////////////////////////
    std::string GetSongName() const;

    std::string GetInitialLine() const;

    int GetPlayCount() const;


private:
    std::string songName;
    std::string firstLine;
    int playCount = 0;
};

#endif //PLAYLISTPROJECT_SONG_H
