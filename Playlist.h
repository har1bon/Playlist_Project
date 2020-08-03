//
// Created by harri on 6/11/2020.
//

#ifndef PLAYLISTPROJECT_PLAYLIST_H
#define PLAYLISTPROJECT_PLAYLIST_H

#include "Song.h"
#include <iostream>

class Playlist {

public:

    ////////////////////////////////////////
    //CONSTRUCTORS
    ////////////////////////////////////////
    Playlist(std::string inputName = "none");

    ~Playlist();

    ////////////////////////////////////////
    //SETTERS
    ///////////////////////////////////////
    void AddSongToPlaylist(Song *inputSong);

    void RemoveSongFromPlaylistMenuOption(int userIndex);


    //////////////////////////////////////
    //GETTERS
    //////////////////////////////////////

    void PlayPlaylistMenuOption();

    void PrintPlaylistSongs();

    Song *GetSong(int indexInput);

    std::string GetPlaylistName() const;

    std::vector<Song *> GetSongVector();


private:
    std::string playlistName;
    std::vector<Song *> playlistSongs;
};

#endif //PLAYLISTPROJECT_PLAYLIST_H
