//  Write a program to simulate music player application using suitable data 
// structure. There is no estimation about number of music files to be managed by 
// the music player. Your program should support all the basic music player 
// operations to play and manage the playlist. 




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char song[100];
    struct node* next;
    struct node* prev;
};

struct node* First = NULL;
struct node* current = NULL;


void insertEnd(char song[100]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->song, song);
    newNode->next = NULL;

    if (First == NULL) {
        newNode->prev = NULL;
        First = newNode;
        current = First;
    } else {
        struct node* temp = First;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Added '%s' to the playlist.\n", song);
}


void printList() {
    struct node* temp = First;
    printf("\nPlaylist:\n");
    while (temp != NULL) {
        printf(" %s\n", temp->song);
        temp = temp->next;
    }
}


void playCurrent() {
    if (current == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    printf("Now playing: %s\n", current->song);
}


void playNext() {
    if (current == NULL || current->next == NULL) {
        printf("No next song.\n");
        return;
    }
    current = current->next;
    playCurrent();
}


void playPrev() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous song available.\n");
        return;
    }
    current = current->prev;
    playCurrent();
}


void deleteSong(char song[100]) {
    struct node* temp = First;

    while (temp != NULL && strcmp(temp->song, song) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song '%s' not found.\n", song);
        return;
    }

    if (temp == First){
        First = temp->next;
    }
    if (temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL){
        temp->next->prev = temp->prev;
    }

    if (current == temp){
        current = temp->next != NULL ? temp->next : temp->prev;
    }

    printf("Deleted '%s' from playlist.\n", temp->song);
    free(temp);
}


void searchSong(char song[100]) {
    struct node* temp = First;
    while (temp != NULL) {
        if (strcmp(temp->song, song) == 0) {
            printf(" Found song: %s\n", temp->song);
            return;
        }
        temp = temp->next;
    }
    printf(" Song '%s' not found.\n", song);
}

int main() {
    insertEnd("Love Story");
    insertEnd("Senorita");
    insertEnd("Believer");
    insertEnd("Faded");

    printList();

    printf("\nMusic Player:\n");
    playCurrent();
    playNext();
    playNext();
    playPrev();

    printf("\n Searching for 'Believer':\n");
    searchSong("Believer");

    printf("\n Deleting 'Perfect':\n");
    deleteSong("Perfect");

    printf("\nUpdated Playlist:\n");
    printList();

    return 0;
}
