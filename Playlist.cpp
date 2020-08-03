//
// Created by harri on 6/11/2020.
//

#include "Playlist.h"
#include <vector>
#include <iostream>

////////////////////////////////////////
//CONSTRUCTORS
////////////////////////////////////////
Playlist::Playlist(std::string inputName) {
    playlistName = inputName;
}

Playlist::~Playlist() {}


////////////////////////////////////////
//SETTERS
///////////////////////////////////////

void Playlist::PrintPlaylistSongs() {
    for (int i = 0; i < (int) playlistSongs.size(); ++i) {
        std::cout << i << ": " << playlistSongs.at(i)->GetSongName() << std::endl;
    }//end of for loop
}

void Playlist::AddSongToPlaylist(Song *inputSong) {
    playlistSongs.push_back(inputSong);
}

void Playlist::RemoveSongFromPlaylistMenuOption(int userIndex) {
    playlistSongs.erase(playlistSongs.begin() + userIndex);
}

//////////////////////////////////////
//GETTERS
//////////////////////////////////////

void Playlist::PlayPlaylistMenuOption() {
    for (int i = 0; i < (int) playlistSongs.size(); ++i) {
        std::cout << playlistSongs.at(i)->GetInitialLine() << std::endl;
        playlistSongs.at(i)->IncrementCount();
    } //end of for-loop
}

Song *Playlist::GetSong(int indexInput) {
    return playlistSongs.at(indexInput);
}

std::string Playlist::GetPlaylistName() const {
    return playlistName;
}

std::vector<Song *> Playlist::GetSongVector() {
    return playlistSongs;
}


