/* Begin FHbegin */
//-------------------------------------------------------------------------
// STAY / W      Resource header file _BOX_COMMON.XME
//-------------------------------------------------------------------------
// Created 11\02\2014 15:19
//-------------------------------------------------------------------------

/* End FHbegin */
/* Begin FHhead */
#ifndef __BOX_COMMON_H_
#define __BOX_COMMON_H_

#include "staypic.h"
HPICMODULEBEG(_BOX_COMMON)

/* End FHhead */
/* Begin FHdefine */
#define SELGroupU 7033
#define SELUARM 9527
#define SELURN 9525
/* End FHdefine */
/* Begin FHtypedef */
/* End FHtypedef */
/* Begin FHfield */
extern char GU_NameGroup[17];
extern StayFD *_GU_NameGroup;
extern StayFD _n_GU_NameGroup;

extern char NL_NetName[15];
extern StayFD *_NL_NetName;
extern StayFD _n_NL_NetName;

extern char RajName[201];
extern StayFD *_RajName;
extern StayFD _n_RajName;

extern char RL_RnName[17];
extern StayFD *_RL_RnName;
extern StayFD _n_RL_RnName;

extern char SB_Prg[33];
extern StayFD *_SB_Prg;
extern StayFD _n_SB_Prg;

extern char SB_Proc[33];
extern StayFD *_SB_Proc;
extern StayFD _n_SB_Proc;

extern BYTE  SB_ProcC;
extern StayFD *_SB_ProcC;
extern StayFD _n_SB_ProcC;

extern char SB_ProcCD[80];
extern StayFD *_SB_ProcCD;
extern StayFD _n_SB_ProcCD;

extern char SB_ProcComm[128];
extern StayFD *_SB_ProcComm;
extern StayFD _n_SB_ProcComm;

extern WORD  SB_ProcNpp;
extern StayFD *_SB_ProcNpp;
extern StayFD _n_SB_ProcNpp;

extern char SB_ProcStr[80];
extern StayFD *_SB_ProcStr;
extern StayFD _n_SB_ProcStr;

extern WORD  SB_ProcView;
extern StayFD *_SB_ProcView;
extern StayFD _n_SB_ProcView;

extern BYTE  SU_Screen;
extern StayFD *_SU_Screen;
extern StayFD _n_SU_Screen;

extern char TmpAccW[41];
extern StayFD *_TmpAccW;
extern StayFD _n_TmpAccW;

extern char TmpDtW[51];
extern StayFD *_TmpDtW;
extern StayFD _n_TmpDtW;

extern char TmpNetName[256];
extern StayFD *_TmpNetName;
extern StayFD _n_TmpNetName;

extern char TmpNetW[15];
extern StayFD *_TmpNetW;
extern StayFD _n_TmpNetW;

extern char TmpRnNet[9];
extern StayFD *_TmpRnNet;
extern StayFD _n_TmpRnNet;

extern char TmpRnNet2[6];
extern StayFD *_TmpRnNet2;
extern StayFD _n_TmpRnNet2;

extern char TmpRnW[17];
extern StayFD *_TmpRnW;
extern StayFD _n_TmpRnW;

extern char TmpUsNW[81];
extern StayFD *_TmpUsNW;
extern StayFD _n_TmpUsNW;

extern char User_Comm[128];
extern StayFD *_User_Comm;
extern StayFD _n_User_Comm;

extern BYTE  User_Hay;
extern StayFD *_User_Hay;
extern StayFD _n_User_Hay;

extern char User_ID[33];
extern StayFD *_User_ID;
extern StayFD _n_User_ID;

extern char User_IDName[65];
extern StayFD *_User_IDName;
extern StayFD _n_User_IDName;

extern char User_Passw[33];
extern StayFD *_User_Passw;
extern StayFD _n_User_Passw;

extern WORD  User_UserNum;
extern StayFD *_User_UserNum;
extern StayFD _n_User_UserNum;

extern char Cont_Name[21];
extern StayFD *_Cont_Name;
extern StayFD _n_Cont_Name;

extern char Cont_Path[256];
extern StayFD *_Cont_Path;
extern StayFD _n_Cont_Path;

extern char Cont_ChkSum[33];
extern StayFD *_Cont_ChkSum;
extern StayFD _n_Cont_ChkSum;

extern char Cont_Version[41];
extern StayFD *_Cont_Version;
extern StayFD _n_Cont_Version;

/* End FHfield */
/* Begin FHdataset */
extern StayDataset _n_B_AccProc;
extern StayDataset *B_AccProc;
extern StayDataset _n_B_AccR;
extern StayDataset *B_AccR;
extern StayDataset _n_B_GroupU;
extern StayDataset *B_GroupU;
extern StayDataset _n_B_ListUsers;
extern StayDataset *B_ListUsers;
extern StayDataset _n_B_Proc;
extern StayDataset *B_Proc;
extern StayDataset _n_B_User;
extern StayDataset *B_User;
extern StayDataset _n_B_Content;
extern StayDataset *B_Content;
/* End FHdataset */
/* Begin FHmenu */
HMENU pop_menu ();
HMENU WBMain_menu ();
/* End FHmenu */
/* Begin FHframe */
extern StayWindow _n_WBMain;
extern StayWindow *WBMain;
extern StayWindow _n_WSocFlash;
extern StayWindow *WSocFlash;
extern StayWindow _n_WAsopdFlash;
extern StayWindow *WAsopdFlash;
extern StayWindow _n_WCenterFlash;
extern StayWindow *WCenterFlash;
extern StayWindow _n_WEdarpFlash;
extern StayWindow *WEdarpFlash;
extern StayWindow _n_WgetID;
extern StayWindow *WgetID;
extern StayWindow _n_WGroup;
extern StayWindow *WGroup;
extern StayWindow _n_WListRn;
extern StayWindow *WListRn;
extern StayWindow _n_WListUserID;
extern StayWindow *WListUserID;
extern StayWindow _n_WProcParam;
extern StayWindow *WProcParam;
extern StayWindow _n_WProcSet;
extern StayWindow *WProcSet;
extern StayWindow _n_WSelProc;
extern StayWindow *WSelProc;
extern StayWindow _n_WUserParam;
extern StayWindow *WUserParam;
extern StayWindow _n_WUserSet;
extern StayWindow *WUserSet;
/* End FHframe */
/* Begin FHtabl */
extern void *_BOX_COMMON[];
/* End FHtabl */
/* Begin FDfield */
/* End FDfield */
/* Begin FDextern */
/* End FDextern */
/* Begin FHend */

HPICMODULEEND(_BOX_COMMON)

#endif
/* End FHend */
