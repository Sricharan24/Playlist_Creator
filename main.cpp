#include <iostream>
#include <string>

#include "Playlist.h"

using namespace std;


void PrintMenu(string title) {
	cout << title << " PLAYLIST MENU" << endl;
	cout << "a - Add song" << endl;
	cout << "d - Remove song" << endl;
	cout << "c - Change position of song" << endl;
	cout << "s - Output songs by specific artist" << endl;
	cout << "t - Output total time of playlist (in seconds)" << endl;
	cout << "o - Output full playlist" << endl;
	cout << "q - Quit" << endl;
	cout << endl;
    cout << "Choose an option:"<<endl;
}
void outputPlaylist(PlaylistNode* &head){
    if(head == 0){
        cout<<"Playlist is empty"<<endl;
        cout<<endl;
    }
    else{
        int count =1;
        PlaylistNode* temp = head;
        while(temp!= 0){
            cout<<count<<"."<<endl;
            temp->PrintPlaylistNode();
            temp = temp->GetNext();
            ++count;
        }
    }
    
}

void addSong(PlaylistNode* &head, PlaylistNode* &tail){
    string id;
    string title;
    string artist;
    int length;
	cout << "ADD SONG" << endl;
	cout << "Enter song's unique ID:"<<endl;
	cin>>id;
    cin.ignore();
	cout << "Enter song's name:"<<endl;
	getline(cin,title);
	cout << "Enter artist's name:"<<endl;
	getline(cin,artist);
	cout << "Enter song's length (in seconds):"<<endl;
    cin>>length;
    cout<<endl;
    PlaylistNode* add  = new PlaylistNode(id,title,artist,length);
    if(head == 0){
        head = add;
        tail = add;
    }
    else{
        tail->InsertAfter(add);
        tail = add;   
    }   
}    


void removeSong(PlaylistNode* &head, PlaylistNode* &tail){
    string id;
    string title;
    if(head==0){
        cout<<"Playlist is empty"<<endl;
    }
    else{
        cout << "REMOVE SONG" << endl;
	    cout << "Enter song's unique ID:" << endl;
	    cin>>id;
	    PlaylistNode* temp = head;
        if (temp->GetID() == id) {
			title = temp->GetSongName();
			head = temp->GetNext();
			delete temp;
		}
        else{
            PlaylistNode* prev = 0;
            while(temp->GetID() != id){
                prev = temp;
                temp = temp->GetNext();
            }
            if (temp == tail) {
		        tail = prev;
		        prev->SetNext(0);
		        title = temp->GetSongName();
		        delete temp;
	        }
	        else {
		        prev->SetNext(temp->GetNext());
		        title = temp->GetSongName();
		        delete temp;
	        }
        }
        cout << "\"" << title << "\"" << " removed." << endl;
        cout<<endl;
    }    
}

void changePosition(PlaylistNode* &head, PlaylistNode* &tail){
    PlaylistNode* x = 0;
    int last = 0;
    int currpos;
    int newpos;
    cout << "CHANGE POSITION OF SONG" << endl;
    cout << "Enter song's current position:" << endl;
    cin >> currpos; 
    cout << "Enter new position for song:" << endl;
    cin >> newpos;
    while(x!=0) {
        last+=1;
    }
    if (currpos == 1) {
        x = head;
        head = head->GetNext();
    }
    else if (currpos == last) {
        x = tail;
        for (PlaylistNode* i = head; i->GetNext()->GetNext() != 0; i = i->GetNext()) {
            tail = i;
        }
        tail = tail->GetNext();
        tail->SetNext(0);
    }
    else {
        int count = 1;
        for (PlaylistNode* i = head; i != 0; i = i->GetNext()) {
            if (count == currpos - 1) {
                x = i->GetNext();
                i->SetNext(i->GetNext()->GetNext());
            }
            count+=1;
        }
    }
    int count = 1;
    if (newpos == 1) {
        PlaylistNode* temp = head;
        head = x;
        x->SetNext(temp);
    }
    else {
        for (PlaylistNode* i = head; i != 0; i = i->GetNext()) {
            if (count == newpos - 1) {
                PlaylistNode* temp = i->GetNext();
                i->SetNext(x);
                x->SetNext(temp);
            }
            count+=1;
        }
    }
    cout << "\"" << x->GetSongName() << "\"" << " moved to position " << newpos << endl << endl;
}

void outputSongByArtist(PlaylistNode* &head){
    int count = 1;
    cout<<"OUTPUT SONGS BY SPECIFIC ARTIST"<<endl;
    string art;
    cin.ignore();
    cout<<"Enter artist's name:"<<endl;
    getline(cin,art);
    cout<<endl;
    PlaylistNode* temp = head;
    while(temp!=0){
        if(art == temp->GetArtistName()){
            cout<< count<<"."<<endl;
            temp->PrintPlaylistNode();
        }
        temp  = temp ->GetNext();
        ++count;
    }
}

void outputTime(PlaylistNode* &head){
    int time = 0;
    PlaylistNode* temp = head;
    while(temp!= 0){
        time+= temp->GetSongLength();
        temp = temp->GetNext();
    }
    cout<<"OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)"<<endl;
    cout<<"Total time: "<< time<<" seconds"<<endl;
    cout<<endl;
    
}

int main(){
    PlaylistNode* head = 0;
    PlaylistNode* tail = 0; 
    string one;
    cout<<"Enter playlist's title:"<<endl;
    getline(cin,one);
    cout<<endl;
    char two;
    while(true){
        PrintMenu(one); 
        cin>>two;
        if(two == 'a'){
            addSong(head, tail);     
        }
        else if(two == 'd'){
            removeSong(head, tail);
        }
        else if(two == 'c'){
            changePosition(head, tail);
        }
        else if(two == 's'){
            outputSongByArtist(head);
        }
        else if(two == 't'){
            outputTime(head);
        }
        else if(two == 'o'){
            cout << one << " - OUTPUT FULL PLAYLIST" << endl;
            outputPlaylist(head);
        }
        else if(two == 'q'){
            break;
        }
        
    }
    return 0;
}

// g++ main.cpp Playlist.cpp




