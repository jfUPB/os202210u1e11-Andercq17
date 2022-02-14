#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventlist = malloc(sizeof(EventList));
    eventlist->isEmpty = 0;
    eventlist->head = NULL;
    eventlist->last = NULL;
    return eventlist;
}

void DestroyEventList(EventList *this)
{
    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *evento = this->head;
    if (this->isEmpty == 0){return NULL;}
    else{
        while (evento != NULL){
            if (*(evento->eventName + 2) == *(name + 2) && *(evento->eventName + 3) == *(name + 3)){return evento;}
            evento = evento->next;
        }
    }
    return NULL;
}

void AddEvent(EventList *this, Event *event)
{
    Event *evento = this->head;
    if (this->isEmpty != 1){
        this->head = event;
        this->last = event;
        this->isEmpty = 1;
    }
    else{    
        while (evento != NULL){
            if (*(evento->eventName + 2) == *(event->eventName + 2) && *(evento->eventName + 3) == *(event->eventName + 3)){return;}
            evento = evento->next;
        }
        this->last->next = event;
        this->last = event;
    }
}

void RemoveEvent(EventList *this, char *name)
{
    Event *evento = this->head;
    Event *remover = SearchEvent(this, name);
    if (remover == NULL || this->isEmpty == 0){return;}
    else{
        while (evento != NULL){
            if(*(this->head->eventName + 2) == *(name + 2)){
                this->head = this->head->next;
                break;
            }else if (*(evento->next->eventName + 2) == *(name + 2)){
                evento->next = evento->next->next;
                break;
            }
            evento = evento->next;
        }
        if (this->head == NULL){this->isEmpty = 0;}
    }
}

void ListEvents(EventList *this)
{
    Event *evento = this->head;
    if (this->isEmpty == 0){printf("empty\n");}
    else{
        while (evento != NULL){
            printf("%s\n", evento->eventName);
            evento = evento->next;
        }
    }
}
