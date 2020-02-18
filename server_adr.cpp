#include <stdio.h>
#include "server_adr.h"
#include "serveraddr.h"
#include "vcconfig.h"

bool GetParamForRunTCPClient (char * params, int length) {
	bool result = false;
	memset(params, 0, length);
	if(FFind(B_SvrAdr->file)) {
		if(Open(B_SvrAdr, RD|ANRDWR)) {
			SetBegin(B_SvrAdr);
			if(GetNext(B_SvrAdr)) {
				strcpy(params, J_SRVIP);
				strcat(params, " ");
				strcat(params, J_SRVPORT);
				unsigned short rajon = fGetTech ("–¿…ŒÕ");
				unsigned short insCode = 0;
				StartProcSet(&insCode,NULL,NULL,NULL);
				char rn[6];
				char insp[6];
				memset(rn, 0, sizeof(rn));
				memset(insp, 0, sizeof(insp));
				sprintf(rn, "%d", rajon);
				sprintf(insp, "%d", insCode);
				strcat(params, " ");
				strcat(params, rn);
				strcat(params, " ");
				strcat(params, insp);
				result = true;
			}
		}
	}
	return result;
}