#include "event.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Event *CreateEvent(char *name)
{
    Event *evento = malloc(sizeof(Event));
    evento->next = NULL;
    name[15]=0;
    sscanf(name,"%s",evento->eventName);
    return evento;
}

void DestroyEvent(Event *this)
{
    free(this);
}





