#ifndef _STATION_IDENT_
#define _STATION_IDENT_

#include "wstay.h"
#include "..\xme\station_id.h"

extern char station_id[20];
extern bool bFlagAccess;

bool GetAccess ();
bool CheckIdent ();
bool get_station_id ();
void SetActiveStation (bool en);
int bosWAccess (StayEvent s, StayEvent id);
int bosWAddComp (StayEvent s, StayEvent id);

#endif