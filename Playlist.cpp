#include "Playlist.h"
#include <iostream>
#include <string>

PlaylistNode::PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string id, string song, string artist, int length) {
    uniqueID = id;
    songName = song;
    artistName = artist;
    songLength = length;
    nextNodePtr = 0;
}

string PlaylistNode::GetID(){
    return uniqueID;
}

string PlaylistNode::GetSongName(){
    return songName;
}

string PlaylistNode::GetArtistName() {
    return artistName;
}

int PlaylistNode::GetSongLength() {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
    return nextNodePtr;
}

void PlaylistNode::SetNext(PlaylistNode* x) {
    nextNodePtr = x;
}

void PlaylistNode::InsertAfter(PlaylistNode* y) {
    PlaylistNode* temp = 0;
    temp = nextNodePtr;
    nextNodePtr = y;
    y->SetNext(temp);
}

void PlaylistNode::PrintPlaylistNode() {
    cout <<"Unique ID: "<< uniqueID << endl;
    cout << "Song Name: "<< songName << endl;
    cout <<"Artist Name: "<< artistName << endl;
    cout <<"Song Length (in seconds): "<< songLength<<endl;
    cout<<endl;

}