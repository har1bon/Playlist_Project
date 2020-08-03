#include <iostream>
#include <string>
#include <vector>

#include "Song.h"
#include "Playlist.h"

void RemovePlaylistMenuOption(std::vector<Playlist> &inputVector, int inputIndex);

void ListPlaylistsMenuOption(std::vector<Playlist> inputVector);

const void ListAllSongs(std::vector<Song *> inputVector);

std::string GetUserString(const std::string &prompt);

int GetUserInt(const std::string &prompt);

void ListSongsMenuOption(std::vector<Song *> inputVector);

void AddPlaylistMenuOption(std::vector<Playlist> &inputVector);

void AddSongsMenuOption(std::vector<Song *> &inputVector);

void OptionsMenuOption();

void QuitMenuOption();

void RemoveSongFromLibraryMenuOption();

int main() {

    std::cout << "Welcome to the \'FirstLine\' Player!  Enter options to see menu options." << std::endl << std::endl;

    //Create vectors to hold the songs and playlists
    std::vector<Song *> allSongs;
    std::vector<Playlist> allPlaylists;


    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(allSongs);
        } else if (userMenuChoice == "list") {

            ListSongsMenuOption(allSongs);

        } else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(allPlaylists);
        } else if (userMenuChoice == "addsp") {
            ListPlaylistsMenuOption(allPlaylists);
            int playlistIndex = GetUserInt("Pick a playlist index number: ");
            ListAllSongs(allSongs);
            int songIndex = GetUserInt("Pick a song index number: ");

            allPlaylists.at(playlistIndex).AddSongToPlaylist(allSongs.at(songIndex));

        } else if (userMenuChoice == "listp") {

            ListPlaylistsMenuOption(allPlaylists);
        } else if (userMenuChoice == "play") {

            ListPlaylistsMenuOption(allPlaylists);
            int playlistIndex = GetUserInt("Pick a playlist index number: ");
            std::cout << "Playing songs from playlist: ";
            std::cout << allPlaylists.at(playlistIndex).GetPlaylistName() << std::endl;

            //print the first lines
            allPlaylists.at(playlistIndex).PlayPlaylistMenuOption();

        } else if (userMenuChoice == "remp") {

            ListPlaylistsMenuOption(allPlaylists);
            int userInput = GetUserInt("Pick a playlist index number to remove: ");
            RemovePlaylistMenuOption(allPlaylists, userInput);

        } else if (userMenuChoice == "remsp") {
            ListPlaylistsMenuOption(allPlaylists);
            int userInput = GetUserInt("Pick a playlist index number: ");
            allPlaylists.at(userInput).PrintPlaylistSongs();
            int userSongInput = GetUserInt("Pick a song index number to remove: ");
            allPlaylists.at(userInput).RemoveSongFromPlaylistMenuOption(userSongInput);

        } else if (userMenuChoice == "remsl") {
            ListAllSongs(allSongs);
            int userInput = GetUserInt("Pick a song index number to remove: ");
            std::string songRemoveName = allSongs.at(userInput)->GetSongName();
            for (int i = 0; i < (int) allPlaylists.size(); ++i) {
                for (int j = 0; j < (int) allPlaylists.at(i).GetSongVector().size(); ++j) {
                    if (songRemoveName == allPlaylists.at(i).GetSongVector().at(j)->GetSongName()) {
                        allPlaylists.at(i).RemoveSongFromPlaylistMenuOption(j);
                        break;
                    }
                } //end of for loop
            }//end of for-loop
            delete allSongs.at(userInput);
            allSongs.erase(allSongs.begin() + userInput);

        } else if (userMenuChoice == "options") {
            OptionsMenuOption();
        } else if (userMenuChoice == "quit") {
            QuitMenuOption();
            continueMenuLoop = false;
        } else {
            OptionsMenuOption();
        }
    }

    //free up allotted space
    if (allSongs.size() >= 0) {
        for (int i = 0; i < (int) allSongs.size(); ++i) {
            delete allSongs.at(i);
        }//end of for-loop
    } //end of if-statement

    return 0;
}

void RemovePlaylistMenuOption(std::vector<Playlist> &inputVector, int inputIndex) {
    inputVector.erase(inputVector.begin() + inputIndex);
}

void ListPlaylistsMenuOption(std::vector<Playlist> inputVector) {
    for (int i = 0; i < (int) inputVector.size(); ++i) {
        std::cout << i << ": ";
        std::cout << inputVector.at(i).GetPlaylistName();
        std::cout << std::endl;
    } //end of for-loop
}

const void ListAllSongs(std::vector<Song *> inputVector) {
    for (int i = 0; i < (int) inputVector.size(); ++i) {
        std::cout << i << ": " << inputVector.at(i)->GetSongName() << std::endl;
    }//end of for-loop
}

void ListSongsMenuOption(std::vector<Song *> inputVector) {
    for (int i = 0; i < (int) inputVector.size(); ++i) {
        std::cout << inputVector.at(i)->GetSongName() + ": \"";
        std::cout << inputVector.at(i)->GetInitialLine() + "\", ";
        std::cout << inputVector.at(i)->GetPlayCount();
        std::cout << " play(s).";
        std::cout << std::endl;
    }//end of for-loop

}

void AddPlaylistMenuOption(std::vector<Playlist> &inputVector) {
    std::string playlistName = "none";

    std::cout << "Playlist Name: ";
    getline(std::cin, playlistName);
    Playlist nextPlaylist = playlistName;
    inputVector.push_back(nextPlaylist);

}

std::string GetUserString(const std::string &prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}

int GetUserInt(const std::string &prompt) {
    int userAnswer = 0.0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.clear();
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

void AddSongsMenuOption(std::vector<Song *> &inputVector) {
    const std::string DONE_KEYWORD = "DONE";
    std::cout << "Enter songs' names and first lines"
              << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

    std::string songName = "none";
    std::string firstLine = "none";
    int playCount = 0;

    songName = GetUserString("Song Name: ");
    while (songName != DONE_KEYWORD) {
        firstLine = GetUserString("Song's first line: ");

        Song *nextSong = new Song(songName, firstLine, playCount);
        inputVector.push_back(nextSong);


        songName = GetUserString("Song Name: ");
    }
}

void OptionsMenuOption() {
    std::cout << "add      Adds a list of songs to the library" << std::endl
              << "list     Lists all the songs in the library" << std::endl
              << "addp     Adds a new playlist" << std::endl
              << "addsp    Adds a song to a playlist" << std::endl
              << "listp    Lists all the playlists" << std::endl
              << "play     Plays a playlist" << std::endl
              << "remp     Removes a playlist" << std::endl
              << "remsp    Removes a song from a playlist" << std::endl
              << "remsl    Removes a song from the library (and all playlists)" << std::endl
              << "options  Prints this options menu" << std::endl
              << "quit     Quits the program" << std::endl << std::endl;
}

void QuitMenuOption() {
    std::cout << "Goodbye!" << std::endl;
}

