#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));

    return eventList;
}

void DestroyEventList(EventList *this)
{


    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{


    return NULL;
}

void AddEvent(EventList *this, Event *event)
{
    Event *r = this->head;
    if (this->isEmpty != 0)
    {
        while (r != NULL)
        {
            if (*(r->eventName + 2) == *(event->eventName + 2) && *(r->eventName + 3) == *(event->eventName + 3))
                return;

            r = r->next;
        }
        this->last->next = event;
        this->last = event;
    }
    else
    {
        this->head = event;
        this->last = event;
        this->isEmpty = 1;
    }
}

void RemoveEvent(EventList *this, char *name)
{
}

void ListEvents(EventList *this)
{
    
    printf("empty\n");
}
