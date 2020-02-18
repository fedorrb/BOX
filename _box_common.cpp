/* Begin FCbegin */
//-------------------------------------------------------------------------
// STAY / W      Resource file _BOX_COMMON.XME
//-------------------------------------------------------------------------
// Created 11\02\2014 15:19
//-------------------------------------------------------------------------

#include "_BOX_COMMON.h"

/* End FCbegin */
/* Begin FCinclude */
/* End FCinclude */
/* Begin FChead */
PICMODULEBEG(_BOX_COMMON)

static StayFD _nn__BOX_COMMON = {NULL,TAG_PIC,0,0,0,0,"_BOX_COMMON",NULL};
/* End FChead */
/* Begin FCtypedef */
/* End FCtypedef */
/* Begin FCfield */
char GU_NameGroup[17];
StayFD _n_GU_NameGroup = {&GU_NameGroup,0,0,0,CLS_V,16,"GU_NameGroup","наимен. группы пользователей"};
StayFD *_GU_NameGroup = &_n_GU_NameGroup;

char NL_NetName[15];
StayFD _n_NL_NetName = {&NL_NetName,0,0,0,CLS_V,14,"NL_NetName","имя узла"};
StayFD *_NL_NetName = &_n_NL_NetName;

char RajName[201];
StayFD _n_RajName = {&RajName,0,0,0,CLS_V,200,"RajName",""};
StayFD *_RajName = &_n_RajName;

char RL_RnName[17];
StayFD _n_RL_RnName = {&RL_RnName,0,0,0,CLS_V,16,"RL_RnName","имя района"};
StayFD *_RL_RnName = &_n_RL_RnName;

char SB_Prg[33];
StayFD _n_SB_Prg = {&SB_Prg,0,0,0,CLS_V,32,"SB_Prg","задача"};
StayFD *_SB_Prg = &_n_SB_Prg;

char SB_Proc[33];
StayFD _n_SB_Proc = {&SB_Proc,0,0,0,CLS_V,32,"SB_Proc","имя задачи"};
StayFD *_SB_Proc = &_n_SB_Proc;

BYTE  SB_ProcC;
StayFD _n_SB_ProcC = {&SB_ProcC,0,0,0,CLS_S,0,"SB_ProcC","цвет  задачи"};
StayFD *_SB_ProcC = &_n_SB_ProcC;

char SB_ProcCD[80];
StayFD _n_SB_ProcCD = {&SB_ProcCD,0,0,0,CLS_V,79,"SB_ProcCD","текущий дирректорий"};
StayFD *_SB_ProcCD = &_n_SB_ProcCD;

char SB_ProcComm[128];
StayFD _n_SB_ProcComm = {&SB_ProcComm,0,0,0,CLS_V,127,"SB_ProcComm","комментарий к задаче"};
StayFD *_SB_ProcComm = &_n_SB_ProcComm;

WORD  SB_ProcNpp;
StayFD _n_SB_ProcNpp = {&SB_ProcNpp,0,0,0,CLS_I,0,"SB_ProcNpp","порядковый номер задачи"};
StayFD *_SB_ProcNpp = &_n_SB_ProcNpp;

char SB_ProcStr[80];
StayFD _n_SB_ProcStr = {&SB_ProcStr,0,0,0,CLS_V,79,"SB_ProcStr","строка вызова задачи"};
StayFD *_SB_ProcStr = &_n_SB_ProcStr;

WORD  SB_ProcView;
StayFD _n_SB_ProcView = {&SB_ProcView,0,0,0,CLS_I,0,"SB_ProcView","порядок отображения задачи"};
StayFD *_SB_ProcView = &_n_SB_ProcView;

BYTE  SU_Screen;
StayFD _n_SU_Screen = {&SU_Screen,0,0,0,CLS_S,0,"SU_Screen","режим экрана"};
StayFD *_SU_Screen = &_n_SU_Screen;

char TmpAccW[41];
StayFD _n_TmpAccW = {&TmpAccW,0,0,0,CLS_V,40,"TmpAccW","права в окне"};
StayFD *_TmpAccW = &_n_TmpAccW;

char TmpDtW[51];
StayFD _n_TmpDtW = {&TmpDtW,0,0,0,CLS_V,50,"TmpDtW","текущая дата в главном окне"};
StayFD *_TmpDtW = &_n_TmpDtW;

char TmpNetName[256];
StayFD _n_TmpNetName = {&TmpNetName,0,0,0,CLS_V,255,"TmpNetName",""};
StayFD *_TmpNetName = &_n_TmpNetName;

char TmpNetW[15];
StayFD _n_TmpNetW = {&TmpNetW,0,0,0,CLS_V,14,"TmpNetW","узел в главном окне"};
StayFD *_TmpNetW = &_n_TmpNetW;

char TmpRnNet[9];
StayFD _n_TmpRnNet = {&TmpRnNet,0,0,0,CLS_V,8,"TmpRnNet","жутко временная подстрока"};
StayFD *_TmpRnNet = &_n_TmpRnNet;

char TmpRnNet2[6];
StayFD _n_TmpRnNet2 = {&TmpRnNet2,0,0,0,CLS_V,5,"TmpRnNet2","жутко временная подстрока"};
StayFD *_TmpRnNet2 = &_n_TmpRnNet2;

char TmpRnW[17];
StayFD _n_TmpRnW = {&TmpRnW,0,0,0,CLS_V,16,"TmpRnW","р-н в главном окне"};
StayFD *_TmpRnW = &_n_TmpRnW;

char TmpUsNW[81];
StayFD _n_TmpUsNW = {&TmpUsNW,0,0,0,CLS_V,80,"TmpUsNW","имя пользователя в главном окне"};
StayFD *_TmpUsNW = &_n_TmpUsNW;

char User_Comm[128];
StayFD _n_User_Comm = {&User_Comm,0,0,0,CLS_V,127,"User_Comm","комментарий к пользователю"};
StayFD *_User_Comm = &_n_User_Comm;

BYTE  User_Hay;
StayFD _n_User_Hay = {&User_Hay,0,0,0,CLS_S,0,"User_Hay","режим доступа"};
StayFD *_User_Hay = &_n_User_Hay;

char User_ID[33];
StayFD _n_User_ID = {&User_ID,0,0,0,CLS_V,32,"User_ID","идентификатор пользователя"};
StayFD *_User_ID = &_n_User_ID;

char User_IDName[65];
StayFD _n_User_IDName = {&User_IDName,0,0,0,CLS_V,64,"User_IDName","имя пользователя"};
StayFD *_User_IDName = &_n_User_IDName;

char User_Passw[33];
StayFD _n_User_Passw = {&User_Passw,0,0,0,CLS_V,32,"User_Passw","пароль пользователя"};
StayFD *_User_Passw = &_n_User_Passw;

WORD  User_UserNum;
StayFD _n_User_UserNum = {&User_UserNum,0,0,0,CLS_I,0,"User_UserNum","код инспектора"};
StayFD *_User_UserNum = &_n_User_UserNum;

char Cont_Name[21];
StayFD _n_Cont_Name = {&Cont_Name,0,0,0,CLS_V,20,"Cont_Name","Найменування модулю"};
StayFD *_Cont_Name = &_n_Cont_Name;

char Cont_Path[256];
StayFD _n_Cont_Path = {&Cont_Path,0,0,0,CLS_V,255,"Cont_Path","Шлях до модулю"};
StayFD *_Cont_Path = &_n_Cont_Path;

char Cont_ChkSum[33];
StayFD _n_Cont_ChkSum = {&Cont_ChkSum,0,0,0,CLS_V,32,"Cont_ChkSum","Контрольна сума модулю"};
StayFD *_Cont_ChkSum = &_n_Cont_ChkSum;

char Cont_Version[41];
StayFD _n_Cont_Version = {&Cont_Version,0,0,0,CLS_V,40,"Cont_Version","Версія модулю"};
StayFD *_Cont_Version = &_n_Cont_Version;

/* End FCfield */
/* Begin FCextern */
extern StayDataset _n_B_AccProc;
extern StayDataset _n_B_AccR;
extern StayDataset _n_B_GroupU;
extern StayDataset _n_B_ListUsers;
extern StayDataset _n_B_Proc;
extern StayDataset _n_B_User;
extern StayDataset _n_B_Content;
extern StayWindow _n_WBMain;
extern StayWindow _n_WSocFlash;
extern StayWindow _n_WAsopdFlash;
extern StayWindow _n_WCenterFlash;
extern StayWindow _n_WEdarpFlash;
extern StayWindow _n_WgetID;
extern StayWindow _n_WGroup;
extern StayWindow _n_WListRn;
extern StayWindow _n_WListUserID;
extern StayWindow _n_WProcParam;
extern StayWindow _n_WProcSet;
extern StayWindow _n_WSelProc;
extern StayWindow _n_WUserParam;
extern StayWindow _n_WUserSet;
/* End FCextern */
/* Begin FCdataset */
static StayFD *tcm_B_AccProc[] =
{
 (StayFD *)&_n_SB_ProcNpp,
 NULL
};
static BYTE ix_B_AccProc[] = {1,1,1,0};
StayDataset _n_B_AccProc = {NULL,TAG_DATASET,0,0,DS_ARRAY,0,1,0,NULL,tcm_B_AccProc,NULL,
NULL,ix_B_AccProc,"список доступных польз.задач","B_AccProc",0};
StayDataset *B_AccProc = &_n_B_AccProc;

static StayFD *tcm_B_AccR[] =
{
 (StayFD *)&_n_NL_NetName,
 (StayFD *)&_n_RL_RnName,
 NULL
};
static BYTE ix_B_AccR[] = {1,1,2,0,1};
StayDataset _n_B_AccR = {NULL,TAG_DATASET,0,0,DS_ARRAY,0,1,0,NULL,tcm_B_AccR,NULL,
NULL,ix_B_AccR,"список доступных польз. р-нов","B_AccR",0};
StayDataset *B_AccR = &_n_B_AccR;

static StayFD *tcm_B_GroupU[] =
{
 (StayFD *)&_n_GU_NameGroup,
 (StayFD *)&_n_B_ListUsers,
 NULL
};
static BYTE ix_B_GroupU[] = {1,1,1,0};
StayDataset _n_B_GroupU = {NULL,TAG_DATASET,0,0,DS_ARRAY,0,1,0,NULL,tcm_B_GroupU,NULL,
"RES:BGROUPU.DT",ix_B_GroupU,"группы пользователей","B_GroupU",0};
StayDataset *B_GroupU = &_n_B_GroupU;

static StayFD *tcm_B_ListUsers[] =
{
 (StayFD *)&_n_User_UserNum,
 NULL
};
static BYTE ix_B_ListUsers[] = {1,1,1,0};
StayDataset _n_B_ListUsers = {NULL,TAG_DATASET,0,0,DS_ARRAY,0,1,0,NULL,tcm_B_ListUsers,NULL,
NULL,ix_B_ListUsers,"список пользователей группы","B_ListUsers",0};
StayDataset *B_ListUsers = &_n_B_ListUsers;

static StayFD *tcm_B_Proc[] =
{
 (StayFD *)&_n_SB_ProcNpp,
 (StayFD *)&_n_SB_ProcView,
 (StayFD *)&_n_SB_Proc,
 (StayFD *)&_n_SB_ProcCD,
 (StayFD *)&_n_SB_ProcC,
 (StayFD *)&_n_SB_ProcStr,
 (StayFD *)&_n_SB_ProcComm,
 NULL
};
static BYTE ix_B_Proc[] = {2,1,1,0,2,1,1};
StayDataset _n_B_Proc = {NULL,TAG_DATASET,0,0,DS_QBASE,0,1,0,NULL,tcm_B_Proc,NULL,
"ASOPD:BPROC4.DT",ix_B_Proc,"Задачи","B_Proc",16};
StayDataset *B_Proc = &_n_B_Proc;

static StayFD *tcm_B_User[] =
{
 (StayFD *)&_n_User_UserNum,
 (StayFD *)&_n_SU_Screen,
 (StayFD *)&_n_User_Hay,
 (StayFD *)&_n_NL_NetName,
 (StayFD *)&_n_User_ID,
 (StayFD *)&_n_GU_NameGroup,
 (StayFD *)&_n_User_IDName,
 (StayFD *)&_n_RL_RnName,
 (StayFD *)&_n_User_Passw,
 (StayFD *)&_n_SB_ProcNpp,
 (StayFD *)&_n_User_Comm,
 (StayFD *)&_n_B_AccProc,
 (StayFD *)&_n_B_AccR,
 NULL
};
static BYTE ix_B_User[] = {1,1,1,0};
StayDataset _n_B_User = {NULL,TAG_DATASET,0,0,DS_BBASE,0,1,0,NULL,tcm_B_User,NULL,
"RES:BUSER.DT",ix_B_User,"Список пользователей","B_User",16};
StayDataset *B_User = &_n_B_User;

static StayFD *tcm_B_Content[] =
{
 (StayFD *)&_n_Cont_Name,
 (StayFD *)&_n_Cont_Path,
 (StayFD *)&_n_Cont_ChkSum,
 (StayFD *)&_n_Cont_Version,
 NULL
};
static BYTE ix_B_Content[] = {1,1,65,128,20};
StayDataset _n_B_Content = {NULL,TAG_DATASET,0,0,DS_ARRAY,0,1,0,NULL,tcm_B_Content,NULL,
NULL,ix_B_Content,"Перелік модулів системи","B_Content",0};
StayDataset *B_Content = &_n_B_Content;

/* End FCdataset */
/* Begin FCmenu */
HMENU pop_menu ()
{HMENU _menu[6];
 _menu[0] = CreatePopupMenu ();
 AppendMenu (_menu[0], MF_STRING, 10102, "Змінити користувача");
 AppendMenu (_menu[0], MF_STRING, 10101, "Змінити район");
 AppendMenu (_menu[0], MF_SEPARATOR, 0, NULL);
 AppendMenu (_menu[0], MF_STRING, 10202, "Калькулятор");
 AppendMenu (_menu[0], MF_STRING, 10201, "Календар");
 AppendMenu (_menu[0], MF_STRING, 10203, "Папка звітів");
 AppendMenu (_menu[0], MF_STRING, 10204, "Принтер");
 AppendMenu (_menu[0], MF_STRING, 10205, "Бази даних");
 AppendMenu (_menu[0], MF_SEPARATOR, 0, NULL);
 AppendMenu (_menu[0], MF_STRING, 10206, "Вихід");
 return _menu[0];
}


HMENU WBMain_menu ()
{HMENU _menu[6];
 _menu[0] = CreateMenu ();
 _menu[1] = CreatePopupMenu ();
 AppendMenu (_menu[0], MF_POPUP, (DWORD)_menu[1], "Сервiс");
 AppendMenu (_menu[1], MF_STRING, 10201, "Календар");
 AppendMenu (_menu[1], MF_STRING, 10202, "Калькулятор");
 AppendMenu (_menu[1], MF_STRING, 10203, "Папка звітів");
 AppendMenu (_menu[1], MF_STRING, 10204, "Принтер");
 AppendMenu (_menu[1], MF_STRING, 10205, "Бази даних");
 AppendMenu (_menu[1], MF_SEPARATOR, 0, NULL);
 AppendMenu (_menu[1], MF_STRING, 10305, "Перегляд протоколу");
 AppendMenu (_menu[1], MF_SEPARATOR, 0, NULL);
 AppendMenu (_menu[1], MF_STRING, 10206, "Вихід");
 _menu[1] = CreatePopupMenu ();
 AppendMenu (_menu[0], MF_POPUP, (DWORD)_menu[1], "Змiнити");
 AppendMenu (_menu[1], MF_STRING, 10101, "Район");
 AppendMenu (_menu[1], MF_STRING, 10102, "Користувача");
 _menu[1] = CreatePopupMenu ();
 AppendMenu (_menu[0], MF_POPUP, (DWORD)_menu[1], "Настроювання");
 AppendMenu (_menu[1], MF_STRING, 10301, "Задач");
 AppendMenu (_menu[1], MF_STRING, 10302, "Користувачiв");
 AppendMenu (_menu[1], MF_STRING, 10306, "Робочих станцій");
 AppendMenu (_menu[1], MF_SEPARATOR, 0, NULL);
 AppendMenu (_menu[1], MF_STRING, 10303, "Областей");
 AppendMenu (_menu[1], MF_STRING, 10304, "Районiв");
 _menu[1] = CreatePopupMenu ();
 AppendMenu (_menu[0], MF_POPUP, (DWORD)_menu[1], "Допомога");
 AppendMenu (_menu[1], MF_STRING, 11001, "Як користуватися допомогою");
 AppendMenu (_menu[1], MF_STRING, 11002, "Контекстна допомога");
 AppendMenu (_menu[1], MF_SEPARATOR, 0, NULL);
 AppendMenu (_menu[1], MF_STRING, 11003, "Про програму");
 return _menu[0];
}

/* End FCmenu */
/* Begin FCframe */

IWStayWin *_init_WBMain ()
{
 IWStayWin *item[8];
 CreateFrame ("WBMain", 5, 5, 780, 430, STM_MODIFIED, STW_MINBOX|STW_MAXBOX|STW_SIZEBOX|STW_CENTER|STW_MAXIMIZE, "Оболонка середовища функціонування    ІОЦ Мінсоц політики України", &item[0]);
 item[0]->SetProperty ("menu", (DWORD)WBMain_menu());
 item[0]->CreateItem ("STAYGRID", "B_Proc", 0, 0, 455, 355, STM_SELECTED, 0, 3000, "", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT|ANCHORTOP|ANCHORBOTTOM);
 item[1]->SetProperty ("source", (DWORD)&_n_B_Proc);
 item[1]->SetProperty ("hrow", 20);
 item[1]->CreateItem ("STAYEDIT", "SB_Proc", 5, 0, 420, 18, STM_NORMAL, 0, 3012, "", &item[2]);
 item[2]->SetProperty ("font", (DWORD)"Arial");
 item[2]->SetProperty ("fontsize", 10);
 item[2]->SetProperty ("bold", 1);
 item[2]->SetProperty ("source", (DWORD)&_n_SB_Proc);
 item[2]->Release ();
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 5, 360, 100, 20, STM_CLICKED, 0, _F1, "F1-Допомога", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(F1) - Виклик довідкової системі");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 110, 360, 100, 20, STM_CLICKED, 0, _Enter, "Enter-Вибір", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(Enter) - Вибір задачи для виконання");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 215, 360, 100, 20, STM_CLICKED, 0, _F12, "F12-Задача", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(F12) - Показ шляху та имені модуля задачи");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 320, 360, 100, 20, STM_CLICKED, 0, _AltX, "AltX-Вихід", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(AltX) - Вихід із оболонки");
 item[1]->Release ();
 item[0]->CreateItem ("STAYGROUP", NULL, 463, 15, 305, 110, STM_GREYED, 0, 5000, "", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORRIGHT);
 item[1]->CreateItem ("STAYEDIT", "TmpDtW", 7, 10, 290, 20, STM_GREYED, STW_CENTER, 3001, "", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_TmpDtW);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", "TmpUsNW", 7, 33, 290, 18, STM_GREYED, 0, 3002, "", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_TmpUsNW);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", "TmpNetW", 139, 54, 76, 18, STM_GREYED, STW_RIGHT, 3003, "", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_TmpNetW);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", "TmpRnW", 217, 54, 80, 18, STM_GREYED, STW_RIGHT, 3004, "", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_TmpRnW);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", "TmpNetName", 7, 75, 290, 18, STM_GREYED, STW_CENTER, 3006, "", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_TmpNetName);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", "TmpAccW", 7, 54, 130, 18, STM_GREYED, 0, 3007, "", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_TmpAccW);
 item[2]->Release ();
 item[1]->Release ();
 item[0]->CreateItem ("STAYGROUP", NULL, 461, 232, 300, 145, STM_GREYED, 0, 3015, "", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORRIGHT|ANCHORBOTTOM);
 item[1]->CreateItem ("STAYEDIT", "SB_ProcComm", 5, 5, 288, 134, STM_GREYED, 0, 3016, "", &item[2]);
 item[2]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT|ANCHORTOP|ANCHORBOTTOM);
 item[2]->SetProperty ("source", (DWORD)&_n_SB_ProcComm);
 item[2]->Release ();
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 465, 202, 144, 20, STM_MODIFIED, 0, 3010, "Коментар до задачі", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORRIGHT|ANCHORBOTTOM);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 465, 150, 300, 20, STM_GREYED, 0, 0, "Контекстний пошук задачі:", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORRIGHT|ANCHORBOTTOM);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 465, 170, 300, 20, STM_GREYED, 0, 8000, "", &item[1]);
 item[1]->SetProperty ("color", 0x0000ff);
 item[1]->SetProperty ("anchor", ANCHORRIGHT|ANCHORBOTTOM);
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WBMain = {NULL,TAG_FRAME,0,0,0,"WBMain",_init_WBMain};
StayWindow *WBMain = &_n_WBMain;


IWStayWin *_init_WSocFlash ()
{
 IWStayWin *item[8];
 CreateFrame ("WSocFlash", 5, 5, 640, 320, STM_NORMAL, STW_CENTER|STW_MAXIMIZE, "МПСП", &item[0]);
 item[0]->SetProperty ("bgcolor", 0xc08000);
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 25, 610, 25, STM_NORMAL, STW_CENTER, 6001, "АВТОМАТИЗОВАНА СИСТЕМА", &item[1]);
 item[1]->SetProperty ("font", (DWORD)"Arial");
 item[1]->SetProperty ("fontsize", 14);
 item[1]->SetProperty ("bold", 1);
 item[1]->SetProperty ("color", 0xffffff);
 item[1]->SetProperty ("bgcolor", 0xc08000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 55, 615, 20, STM_NORMAL, STW_CENTER, 6002, "МІНІСТЕРСТВА СОЦІАЛЬНОЇ ПОЛІТИКИ УКРАЇНИ", &item[1]);
 item[1]->SetProperty ("font", (DWORD)"Arial");
 item[1]->SetProperty ("fontsize", 14);
 item[1]->SetProperty ("bold", 1);
 item[1]->SetProperty ("color", 0xffffff);
 item[1]->SetProperty ("bgcolor", 0xc08000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 265, 610, 20, STM_NORMAL, STW_CENTER, 6003, "(C) Copyright Інформаційно-обчислювальний центр МПСП України - 2010", &item[1]);
 item[1]->SetProperty ("fontsize", 12);
 item[1]->SetProperty ("color", 0xffffff);
 item[1]->SetProperty ("bgcolor", 0xc08000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT|ANCHORBOTTOM);
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WSocFlash = {NULL,TAG_FRAME,0,0,0,"WSocFlash",_init_WSocFlash};
StayWindow *WSocFlash = &_n_WSocFlash;


IWStayWin *_init_WAsopdFlash ()
{
 IWStayWin *item[8];
 CreateFrame ("WAsopdFlash", 5, 5, 640, 320, STM_NORMAL, STW_CENTER|STW_MAXIMIZE, "АСОПД - W", &item[0]);
 item[0]->SetProperty ("bgcolor", 0x800000);
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 15, 625, 20, STM_NORMAL, STW_CENTER, 6003, "АВТОМАТИЗОВАНА СИСТЕМА ОБРОБКИ", &item[1]);
 item[1]->SetProperty ("font", (DWORD)"Arial");
 item[1]->SetProperty ("fontsize", 14);
 item[1]->SetProperty ("bold", 1);
 item[1]->SetProperty ("color", 0x00ffff);
 item[1]->SetProperty ("bgcolor", 0x800000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 45, 620, 20, STM_NORMAL, STW_CENTER, 6004, "ПЕНСІЙНОЇ ДОКУМЕНТАЦІЇ", &item[1]);
 item[1]->SetProperty ("font", (DWORD)"Arial");
 item[1]->SetProperty ("fontsize", 14);
 item[1]->SetProperty ("bold", 1);
 item[1]->SetProperty ("color", 0x00ffff);
 item[1]->SetProperty ("bgcolor", 0x800000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 80, 625, 25, STM_NORMAL, STW_CENTER, 6005, "АСОПД / КОМТЕХ-W", &item[1]);
 item[1]->SetProperty ("font", (DWORD)"Arial");
 item[1]->SetProperty ("fontsize", 16);
 item[1]->SetProperty ("bold", 1);
 item[1]->SetProperty ("color", 0xffff00);
 item[1]->SetProperty ("bgcolor", 0x800000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 265, 625, 20, STM_NORMAL, STW_CENTER, 6006, "(C) Copyright Інформаційно-обчислювальний центр МПСП України - 2002", &item[1]);
 item[1]->SetProperty ("font", (DWORD)"Arial");
 item[1]->SetProperty ("fontsize", 12);
 item[1]->SetProperty ("bold", 1);
 item[1]->SetProperty ("color", 0xffffff);
 item[1]->SetProperty ("bgcolor", 0x800000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT|ANCHORBOTTOM);
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WAsopdFlash = {NULL,TAG_FRAME,0,0,0,"WAsopdFlash",_init_WAsopdFlash};
StayWindow *WAsopdFlash = &_n_WAsopdFlash;


IWStayWin *_init_WCenterFlash ()
{
 IWStayWin *item[8];
 CreateFrame ("WCenterFlash", 5, 5, 640, 320, STM_NORMAL, STW_CENTER|STW_MAXIMIZE, "МПСП", &item[0]);
 item[0]->SetProperty ("bgcolor", 0x404000);
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 25, 610, 25, STM_NORMAL, STW_CENTER, 6001, "ЦЕНТРАЛЬНЕ СХОВИЩЕ", &item[1]);
 item[1]->SetProperty ("font", (DWORD)"Arial");
 item[1]->SetProperty ("fontsize", 14);
 item[1]->SetProperty ("bold", 1);
 item[1]->SetProperty ("color", 0xffffff);
 item[1]->SetProperty ("bgcolor", 0x404000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 55, 615, 20, STM_NORMAL, STW_CENTER, 6002, "МІНІСТЕРСТВА СОЦІАЛЬНОЇ ПОЛІТИКИ УКРАЇНИ", &item[1]);
 item[1]->SetProperty ("font", (DWORD)"Arial");
 item[1]->SetProperty ("fontsize", 14);
 item[1]->SetProperty ("bold", 1);
 item[1]->SetProperty ("color", 0xffffff);
 item[1]->SetProperty ("bgcolor", 0x404000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 265, 610, 20, STM_NORMAL, STW_CENTER, 6003, "(C) Copyright Інформаційно-обчислювальний центр МСП України - 2003", &item[1]);
 item[1]->SetProperty ("font", (DWORD)"Arial");
 item[1]->SetProperty ("fontsize", 12);
 item[1]->SetProperty ("color", 0xffffff);
 item[1]->SetProperty ("bgcolor", 0x404000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT|ANCHORBOTTOM);
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WCenterFlash = {NULL,TAG_FRAME,0,0,0,"WCenterFlash",_init_WCenterFlash};
StayWindow *WCenterFlash = &_n_WCenterFlash;


IWStayWin *_init_WEdarpFlash ()
{
 IWStayWin *item[8];
 CreateFrame ("WEdarpFlash", 5, 5, 640, 320, STM_NORMAL, STW_CENTER|STW_MAXIMIZE, "ЄДАРП", &item[0]);
 item[0]->SetProperty ("bgcolor", 0x404000);
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 25, 610, 25, STM_NORMAL, STW_CENTER, 6001, "ЄДИНИЙ ДЕРЖАВНИЙ АВТОМАТИЗОВАНИЙ РЕЄСТР", &item[1]);
 item[1]->SetProperty ("font", (DWORD)"Arial");
 item[1]->SetProperty ("fontsize", 14);
 item[1]->SetProperty ("bold", 1);
 item[1]->SetProperty ("color", 0xffffff);
 item[1]->SetProperty ("bgcolor", 0x404000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 55, 615, 20, STM_NORMAL, STW_CENTER, 6002, "ОСІБ, ЯКІ МАЮТЬ ПРАВО НА ПІЛЬГИ", &item[1]);
 item[1]->SetProperty ("font", (DWORD)"Arial");
 item[1]->SetProperty ("fontsize", 14);
 item[1]->SetProperty ("bold", 1);
 item[1]->SetProperty ("color", 0xffffff);
 item[1]->SetProperty ("bgcolor", 0x404000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 5, 265, 610, 20, STM_NORMAL, STW_CENTER, 6003, "(C) Copyright Інформаційно-обчислювальний центр МПСП України - 2004", &item[1]);
 item[1]->SetProperty ("font", (DWORD)"Arial");
 item[1]->SetProperty ("fontsize", 12);
 item[1]->SetProperty ("color", 0xffffff);
 item[1]->SetProperty ("bgcolor", 0x404000);
 item[1]->SetProperty ("anchor", ANCHORLEFT|ANCHORRIGHT|ANCHORBOTTOM);
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WEdarpFlash = {NULL,TAG_FRAME,0,0,0,"WEdarpFlash",_init_WEdarpFlash};
StayWindow *WEdarpFlash = &_n_WEdarpFlash;


IWStayWin *_init_WgetID ()
{
 IWStayWin *item[8];
 CreateFrame ("WgetID", 5, 5, 340, 160, STM_MODIFIED, STW_CENTER, "Реєстрація користувача", &item[0]);
 item[0]->SetProperty ("bgcolor", 0xc0c0c0);
 item[0]->CreateItem ("STAYEDIT", "User_ID", 10, 30, 292, 18, STM_MODIFIED, 0, 3001, "", &item[1]);
 item[1]->SetProperty ("source", (DWORD)&_n_User_ID);
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 302, 30, 18, 18, STM_CLICKED, STW_LEFT, _F2, "...", &item[1]);
 item[1]->SetProperty ("tip", (DWORD)"(F2) - Вибір користувача із переліку груп і користувачів.");
 item[1]->Release ();
 item[0]->CreateItem ("STAYEDIT", "User_Passw", 10, 70, 292, 18, STM_MODIFIED, 0, 3002, "", &item[1]);
 item[1]->SetProperty ("source", (DWORD)&_n_User_Passw);
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 8, 100, 80, 20, STM_SELECTED, 0, 2001, "Далі", &item[1]);
 item[1]->SetProperty ("tip", (DWORD)"(Enter) - Продовження виконання программи після введення ідентификатору та паролю.");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 93, 100, 80, 20, STM_SELECTED, 0, _Esc, "Вихід", &item[1]);
 item[1]->SetProperty ("tip", (DWORD)"(Esc) - Вихід із программи");
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 10, 10, 293, 15, STM_NORMAL, 0, 0, "Ідентифікатор", &item[1]);
 item[1]->SetProperty ("bgcolor", 0xc0c0c0);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 10, 50, 292, 15, STM_NORMAL, 0, 0, "Пароль", &item[1]);
 item[1]->SetProperty ("bgcolor", 0xc0c0c0);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 178, 102, 151, 15, STM_MODIFIED, 0, 0, "F2 Вибір користувача", &item[1]);
 item[1]->SetProperty ("bgcolor", 0xc0c0c0);
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WgetID = {NULL,TAG_FRAME,0,0,0,"WgetID",_init_WgetID};
StayWindow *WgetID = &_n_WgetID;


IWStayWin *_init_WGroup ()
{
 IWStayWin *item[8];
 CreateFrame ("WGroup", 5, 5, 240, 270, STM_MODIFIED, STW_CENTER, "Групи користувачів", &item[0]);
 item[0]->CreateItem ("STAYGRID", "B_GroupU", 0, 0, 233, 180, STM_MODIFIED, STW_INS|STW_DEL, 3000, "", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("dock", DOCKTOP);
 item[1]->SetProperty ("source", (DWORD)&_n_B_GroupU);
 item[1]->SetProperty ("hrow", 20);
 item[1]->CreateItem ("STAYEDIT", "GU_NameGroup", 0, 0, 210, 20, STM_MODIFIED, 0, 0, "", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_GU_NameGroup);
 item[2]->Release ();
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 10, 190, 80, 20, STM_SELECTED, 0, 3002, "Вибір", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"Вибір");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 92, 190, 80, 20, STM_SELECTED, STW_EXIT, _Esc, "Вихід", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(Esc) - Вихід");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 10, 215, 80, 20, STM_SELECTED, 0, _Ins, "Додати", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(Ins) - Додати");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 92, 215, 80, 20, STM_SELECTED, 0, _CtY, "Видалити", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(CtY) - Видалити");
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WGroup = {NULL,TAG_FRAME,0,0,0,"WGroup",_init_WGroup};
StayWindow *WGroup = &_n_WGroup;


IWStayWin *_init_WListRn ()
{
 IWStayWin *item[8];
 CreateFrame ("WListRn", 4, 4, 466, 268, STM_MODIFIED, STW_MINBOX|STW_MAXBOX|STW_SIZEBOX|STW_CENTER, "Доступні райони та вузли", &item[0]);
 item[0]->CreateItem ("STAYTABLE", "B_AccR", 0, 0, 460, 204, STM_SELECTED, 0, 3000, "", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("dock", DOCKTOP);
 item[1]->SetProperty ("source", (DWORD)&_n_B_AccR);
 item[1]->SetProperty ("hrow", 18);
 item[1]->SetProperty ("hhead", 20);
 item[1]->CreateItem ("STAYEDIT", "NL_NetName", 0, 0, 60, 0, STM_NORMAL, 0, 3001, "Область", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_NL_NetName);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", "RL_RnName", 0, 0, 60, 0, STM_NORMAL, 0, 3002, "Район", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_RL_RnName);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", "RajName", 0, 0, 337, 0, STM_NORMAL, 0, 3003, "Назва", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_RajName);
 item[2]->Release ();
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 6, 215, 80, 20, STM_SELECTED, 0, 2001, "Додати", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"Додати район");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 88, 215, 96, 20, STM_SELECTED, 0, 2003, "Додати всі", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"Додати всі райони");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 186, 215, 80, 20, STM_SELECTED, 0, 2002, "Видалити", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"Видалити район");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 268, 215, 100, 20, STM_SELECTED, 0, 2004, "Видалити всі", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"Видалити всі райони");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 370, 215, 80, 20, STM_SELECTED, 0, _Esc, "Вихід", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(Esc) - Вихід");
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WListRn = {NULL,TAG_FRAME,0,0,0,"WListRn",_init_WListRn};
StayWindow *WListRn = &_n_WListRn;


IWStayWin *_init_WListUserID ()
{
 IWStayWin *item[8];
 CreateFrame ("WListUserID", 5, 5, 435, 260, STM_MODIFIED, STW_MINBOX|STW_MAXBOX|STW_SIZEBOX|STW_CENTER, "Вибір користувача", &item[0]);
 item[0]->CreateItem ("STAYTREE", NULL, 0, 0, 428, 197, STM_SELECTED, 0, 3002, "STAYGROUP", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("dock", DOCKTOP);
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 5, 205, 80, 20, STM_SELECTED, 0, _Enter, "Вибір", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(Enter) - Вибір користувача");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 340, 205, 80, 20, STM_SELECTED, STW_EXIT, _Esc, "Вихід", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(Esc) - Вихід без вибору");
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WListUserID = {NULL,TAG_FRAME,0,0,0,"WListUserID",_init_WListUserID};
StayWindow *WListUserID = &_n_WListUserID;


IWStayWin *_init_WProcParam ()
{
 IWStayWin *item[8];
 CreateFrame ("WProcParam", 4, 4, 541, 264, STM_MODIFIED, STW_MINBOX|STW_MAXBOX|STW_SIZEBOX|STW_CENTER, "Властивостi задачі", &item[0]);
 item[0]->CreateItem ("STAYEDIT", "SB_Proc", 10, 30, 400, 20, STM_MODIFIED, STW_DUTY|STW_SPACE|STW_ZERO, 3001, "", &item[1]);
 item[1]->SetProperty ("source", (DWORD)&_n_SB_Proc);
 item[1]->Release ();
 item[0]->CreateItem ("STAYEDIT", "SB_ProcComm", 80, 60, 330, 60, STM_MODIFIED, STW_CLEAR|STW_ZERO, 3002, "", &item[1]);
 item[1]->SetProperty ("source", (DWORD)&_n_SB_ProcComm);
 item[1]->Release ();
 item[0]->CreateItem ("STAYEDIT", "SB_ProcCD", 10, 140, 400, 20, STM_MODIFIED, STW_CLEAR|STW_ZERO, 3003, "", &item[1]);
 item[1]->SetProperty ("source", (DWORD)&_n_SB_ProcCD);
 item[1]->Release ();
 item[0]->CreateItem ("STAYEDIT", "SB_ProcStr", 10, 180, 400, 20, STM_MODIFIED, STW_DUTY|STW_SPACE|STW_ZERO, 3004, "", &item[1]);
 item[1]->SetProperty ("source", (DWORD)&_n_SB_ProcStr);
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 8, 8, 100, 16, STM_NORMAL, 0, 0, "Назва задачі", &item[1]);
 item[1]->SetProperty ("tip", (DWORD)"Назва задачі");
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 10, 60, 64, 16, STM_NORMAL, 0, 0, "Коментар", NULL);
 item[0]->CreateItem ("STAYSTATIC", NULL, 10, 120, 92, 16, STM_NORMAL, 0, 0, "Робоча папка", &item[1]);
 item[1]->SetProperty ("tip", (DWORD)"Повний путь папки, де розміщується модуль");
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 10, 160, 73, 16, STM_NORMAL, 0, 0, "Параметри", &item[1]);
 item[1]->SetProperty ("tip", (DWORD)"Повне им\'я модуля та параметри його запуска");
 item[1]->Release ();
 item[0]->CreateItem ("STAYGROUP", NULL, 416, 32, 110, 162, STM_CLICKED, 0, 0, "", &item[1]);
 item[1]->SetProperty ("tip", (DWORD)"Колір назви задачі");
 item[1]->CreateItem ("STAYEDIT", NULL, 10, 10, 20, 20, STM_CLICKED, STW_CENTER, 5001, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x8080ff);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 30, 10, 20, 20, STM_CLICKED, STW_CENTER, 5002, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x0000ff);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 60, 10, 20, 20, STM_CLICKED, STW_CENTER, 5003, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x404080);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 80, 10, 20, 20, STM_CLICKED, STW_CENTER, 5004, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x000040);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 10, 30, 20, 20, STM_CLICKED, STW_CENTER, 5005, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x80ffff);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 30, 30, 20, 20, STM_CLICKED, STW_CENTER, 5006, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x4080ff);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 60, 30, 20, 20, STM_CLICKED, STW_CENTER, 5007, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x008080);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 80, 30, 20, 20, STM_CLICKED, STW_CENTER, 5008, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x80ff80);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 10, 60, 20, 20, STM_CLICKED, STW_CENTER, 5009, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x008000);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 30, 60, 20, 20, STM_CLICKED, STW_CENTER, 5010, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x808000);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 60, 60, 20, 20, STM_CLICKED, STW_CENTER, 5011, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x808080);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 80, 60, 20, 20, STM_CLICKED, STW_CENTER, 5012, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0xffff00);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 10, 80, 20, 20, STM_CLICKED, STW_CENTER, 5013, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x804000);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 30, 80, 20, 20, STM_CLICKED, STW_CENTER, 5014, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0xff0000);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 60, 80, 20, 20, STM_CLICKED, STW_CENTER, 5015, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0xff8000);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 80, 80, 20, 20, STM_CLICKED, STW_CENTER, 5016, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0xff8080);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 10, 110, 20, 20, STM_CLICKED, STW_CENTER, 5017, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0xc080ff);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 30, 110, 20, 20, STM_CLICKED, STW_CENTER, 5018, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0xc08080);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 60, 110, 20, 20, STM_CLICKED, STW_CENTER, 5019, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x400080);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 80, 110, 20, 20, STM_CLICKED, STW_CENTER, 5020, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x800080);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 10, 130, 20, 20, STM_CLICKED, STW_CENTER, 5021, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0x8000ff);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 30, 130, 20, 20, STM_CLICKED, STW_CENTER, 5022, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0xff0080);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 60, 130, 20, 20, STM_CLICKED, STW_CENTER, 5023, "", &item[2]);
 item[2]->SetProperty ("color", 0x000000);
 item[2]->SetProperty ("bgcolor", 0xffffff);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", NULL, 80, 130, 20, 20, STM_CLICKED, STW_CENTER, 5024, "", &item[2]);
 item[2]->SetProperty ("color", 0xffffff);
 item[2]->SetProperty ("bgcolor", 0xc08000);
 item[2]->Release ();
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 100, 210, 70, 20, STM_SELECTED, STW_EXIT, _Esc, "Вихід", &item[1]);
 item[1]->SetProperty ("tip", (DWORD)"(Esc) - Вихід");
 item[1]->Release ();
 item[0]->CreateItem ("STAYSTATIC", NULL, 417, 12, 49, 20, STM_MODIFIED, 0, 0, "Колір", NULL);
 item[0]->CreateItem ("STAYBUTTON", NULL, 20, 210, 70, 20, STM_MODIFIED, STW_EXIT, _Ok, "Зберегти", &item[1]);
 item[1]->SetProperty ("tip", (DWORD)"Зберегти параметры та вийти");
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WProcParam = {NULL,TAG_FRAME,0,0,0,"WProcParam",_init_WProcParam};
StayWindow *WProcParam = &_n_WProcParam;


IWStayWin *_init_WProcSet ()
{
 IWStayWin *item[8];
 CreateFrame ("WProcSet", 5, 5, 610, 452, STM_MODIFIED, STW_MINBOX|STW_MAXBOX|STW_SIZEBOX|STW_CENTER, "Настроювання задач", &item[0]);
 item[0]->CreateItem ("STAYTABLE", "B_Proc", 0, 0, 603, 367, STM_SELECTED, 0, 3001, "", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("dock", DOCKTOP);
 item[1]->SetProperty ("source", (DWORD)&_n_B_Proc);
 item[1]->SetProperty ("hrow", 20);
 item[1]->SetProperty ("hhead", 20);
 item[1]->CreateItem ("STAYEDIT", "SB_Proc", 0, 0, 290, 0, STM_NORMAL, 0, 3012, "Задача", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_SB_Proc);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", "SB_ProcStr", 0, 0, 288, 0, STM_NORMAL, 0, 0, "Модуль", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_SB_ProcStr);
 item[2]->Release ();
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 10, 375, 80, 20, STM_SELECTED, 0, _F3, "Змінити", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(F3) - змінити параметри задачі");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 180, 375, 100, 20, STM_SELECTED, 0, _F2, "Перенести  /\\", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(F2) - перенести задачу догори у списку задач");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 180, 400, 100, 20, STM_SELECTED, 0, _CtF2, "Перенести  \\/", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(CtF2) - перенести задачу донизу у списку задач");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 10, 400, 80, 20, STM_SELECTED, 0, _Ins, "Додати", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(Ins) - додати нову задачу");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 94, 400, 80, 20, STM_SELECTED, 0, _CtY, "Видалити", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(CtY) - видалити задачу");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 515, 400, 80, 20, STM_SELECTED, STW_EXIT, _Esc, "Вихід", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(Esc) - Вихід");
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WProcSet = {NULL,TAG_FRAME,0,0,0,"WProcSet",_init_WProcSet};
StayWindow *WProcSet = &_n_WProcSet;


IWStayWin *_init_WSelProc ()
{
 IWStayWin *item[8];
 CreateFrame ("WSelProc", 5, 5, 450, 250, STM_MODIFIED, STW_CENTER, "Перелiк доступних задач", &item[0]);
 item[0]->CreateItem ("STAYGRID", "B_Proc", 0, 0, 440, 185, STM_SELECTED, 0, 3000, "", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("dock", DOCKTOP);
 item[1]->SetProperty ("source", (DWORD)&_n_B_Proc);
 item[1]->SetProperty ("hrow", 20);
 item[1]->CreateItem ("STAYEDIT", "SB_Proc", 5, 0, 410, 20, STM_NORMAL, 0, 0, "", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_SB_Proc);
 item[2]->Release ();
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 5, 195, 90, 20, STM_SELECTED, 0, 3001, "Недоступні", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 105, 195, 90, 20, STM_SELECTED, 0, 3002, "Виключити", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 345, 195, 90, 20, STM_SELECTED, STW_EXIT, _Esc, "Вихід", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(Esc) - Вихід");
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WSelProc = {NULL,TAG_FRAME,0,0,0,"WSelProc",_init_WSelProc};
StayWindow *WSelProc = &_n_WSelProc;


IWStayWin *_init_WUserParam ()
{
 IWStayWin *item[8];
 CreateFrame ("WUserParam", 5, 5, 550, 205, STM_MODIFIED, STW_CENTER, "Властивості користувача", &item[0]);
 item[0]->CreateItem ("STAYEDIT", "User_ID", 120, 20, 292, 20, STM_MODIFIED, STW_DUTY|STW_SPACE|STW_ZERO, 3011, "", &item[1]);
 item[1]->SetProperty ("source", (DWORD)&_n_User_ID);
 item[1]->Release ();
 item[0]->CreateItem ("STAYEDIT", "User_UserNum", 120, 40, 49, 20, STM_MODIFIED, STW_DUTY|STW_SPACE, 3012, "", &item[1]);
 item[1]->SetProperty ("source", (DWORD)&_n_User_UserNum);
 item[1]->SetProperty ("min", (DWORD)"2");
 item[1]->Release ();
 item[0]->CreateItem ("STAYEDIT", "User_Passw", 120, 60, 292, 20, STM_MODIFIED, STW_CLEAR|STW_ZERO, 3013, "", &item[1]);
 item[1]->SetProperty ("source", (DWORD)&_n_User_Passw);
 item[1]->Release ();
 item[0]->CreateItem ("STAYGROUP", NULL, 120, 83, 145, 65, STM_MODIFIED, 0, 0, "", &item[1]);
 item[1]->CreateItem ("STAYRADIO", "User_Hay", 10, 4, 100, 16, STM_MODIFIED, 0, 0, "користувач", &item[2]);
 item[2]->SetProperty ("source", (DWORD)_User_Hay);
 item[2]->SetProperty ("mask", 0);
 item[2]->Release ();
 item[1]->CreateItem ("STAYRADIO", "User_Hay", 10, 22, 120, 16, STM_MODIFIED, 0, 0, "адміністратор", &item[2]);
 item[2]->SetProperty ("source", (DWORD)_User_Hay);
 item[2]->SetProperty ("mask", 1);
 item[2]->Release ();
 item[1]->CreateItem ("STAYRADIO", "User_Hay", 10, 40, 100, 16, STM_MODIFIED, 0, 0, "супервізор", &item[2]);
 item[2]->SetProperty ("source", (DWORD)_User_Hay);
 item[2]->SetProperty ("mask", 2);
 item[2]->Release ();
 item[1]->Release ();
 item[0]->CreateItem ("STAYEDIT", "User_IDName", 120, 151, 292, 20, STM_MODIFIED, STW_DUTY|STW_SPACE|STW_ZERO, 3014, "", &item[1]);
 item[1]->SetProperty ("source", (DWORD)&_n_User_IDName);
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 420, 14, 110, 20, STM_SELECTED, 0, SELURN, "Райони", NULL);
 item[0]->CreateItem ("STAYBUTTON", NULL, 420, 37, 110, 20, STM_SELECTED, 0, SELUARM, "Задачі", NULL);
 item[0]->CreateItem ("STAYBUTTON", NULL, 420, 60, 110, 20, STM_SELECTED, 0, SELGroupU, "Групи", NULL);
 item[0]->CreateItem ("STAYSTATIC", NULL, 10, 20, 97, 16, STM_NORMAL, 0, 0, "Ідентифікатор", NULL);
 item[0]->CreateItem ("STAYSTATIC", NULL, 10, 40, 107, 16, STM_NORMAL, 0, 0, "Код спецiалiста", NULL);
 item[0]->CreateItem ("STAYSTATIC", NULL, 10, 60, 49, 16, STM_NORMAL, 0, 0, "Пароль", NULL);
 item[0]->CreateItem ("STAYSTATIC", NULL, 10, 80, 42, 16, STM_NORMAL, 0, 0, "Права", NULL);
 item[0]->CreateItem ("STAYSTATIC", NULL, 10, 151, 24, 16, STM_NORMAL, 0, 0, "Ім\'я", NULL);
 item[0]->CreateItem ("STAYEDIT", "GU_NameGroup", 420, 80, 110, 20, STM_NORMAL, 0, 0, "", &item[1]);
 item[1]->SetProperty ("source", (DWORD)&_n_GU_NameGroup);
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 437, 147, 80, 20, STM_SELECTED, STW_EXIT, _Esc, "Вихід", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORRIGHT);
 item[1]->SetProperty ("tip", (DWORD)"(Esc) - Вийти без збереження параметрів");
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WUserParam = {NULL,TAG_FRAME,0,0,0,"WUserParam",_init_WUserParam};
StayWindow *WUserParam = &_n_WUserParam;


IWStayWin *_init_WUserSet ()
{
 IWStayWin *item[8];
 CreateFrame ("WUserSet", 5, 5, 600, 450, STM_MODIFIED, STW_MINBOX|STW_MAXBOX|STW_SIZEBOX|STW_CENTER, "Настроювання користувачiв", &item[0]);
 item[0]->CreateItem ("STAYTABLE", "B_User", 0, 0, 592, 342, STM_SELECTED, 0, 3001, "", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("dock", DOCKTOP);
 item[1]->SetProperty ("source", (DWORD)&_n_B_User);
 item[1]->SetProperty ("hrow", 18);
 item[1]->SetProperty ("hhead", 20);
 item[1]->CreateItem ("STAYEDIT", "User_UserNum", 0, 0, 50, 0, STM_NORMAL, 0, 3002, "Номер", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_User_UserNum);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", "User_ID", 0, 0, 190, 0, STM_NORMAL, 0, 3003, "Идентифікатор", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_User_ID);
 item[2]->Release ();
 item[1]->CreateItem ("STAYEDIT", "User_IDName", 0, 0, 321, 0, STM_NORMAL, 0, 3004, "І\'мя користувача", &item[2]);
 item[2]->SetProperty ("source", (DWORD)&_n_User_IDName);
 item[2]->Release ();
 item[1]->Release ();
 item[0]->CreateItem ("STAYEDIT", "SB_Prg", 5, 349, 580, 18, STM_GREYED, 0, 3005, "", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("source", (DWORD)&_n_SB_Prg);
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 5, 372, 85, 20, STM_SELECTED, 0, _F3, "Змінити", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(F3) - змінити параметри користувача");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 100, 372, 85, 20, STM_SELECTED, 0, _F5, "Оновити", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(F5) - оновити таблицю на основі стану мережi");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 5, 399, 85, 20, STM_SELECTED, 0, _Ins, "Додати", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(Ins) - додати нового користувача");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 100, 399, 85, 20, STM_SELECTED, 0, _CtY, "Видалити", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(CtY) - видалити користувача");
 item[1]->Release ();
 item[0]->CreateItem ("STAYBUTTON", NULL, 500, 398, 85, 20, STM_SELECTED, STW_EXIT, _Esc, "Вихід", &item[1]);
 item[1]->SetProperty ("anchor", ANCHORBOTTOM);
 item[1]->SetProperty ("tip", (DWORD)"(Esc) - Вийти");
 item[1]->Release ();
 return item[0];
}
StayWindow _n_WUserSet = {NULL,TAG_FRAME,0,0,0,"WUserSet",_init_WUserSet};
StayWindow *WUserSet = &_n_WUserSet;

/* End FCframe */
/* Begin FCtabl */
void *_BOX_COMMON[] =
 {NULL,
  &_nn__BOX_COMMON,
  &_n_GU_NameGroup,
  &_n_NL_NetName,
  &_n_RajName,
  &_n_RL_RnName,
  &_n_SB_Prg,
  &_n_SB_Proc,
  &_n_SB_ProcC,
  &_n_SB_ProcCD,
  &_n_SB_ProcComm,
  &_n_SB_ProcNpp,
  &_n_SB_ProcStr,
  &_n_SB_ProcView,
  &_n_SU_Screen,
  &_n_TmpAccW,
  &_n_TmpDtW,
  &_n_TmpNetName,
  &_n_TmpNetW,
  &_n_TmpRnNet,
  &_n_TmpRnNet2,
  &_n_TmpRnW,
  &_n_TmpUsNW,
  &_n_User_Comm,
  &_n_User_Hay,
  &_n_User_ID,
  &_n_User_IDName,
  &_n_User_Passw,
  &_n_User_UserNum,
  &_n_Cont_Name,
  &_n_Cont_Path,
  &_n_Cont_ChkSum,
  &_n_Cont_Version,
  (StayFD *)B_AccProc,
  (StayFD *)B_AccR,
  (StayFD *)B_GroupU,
  (StayFD *)B_ListUsers,
  (StayFD *)B_Proc,
  (StayFD *)B_User,
  (StayFD *)B_Content,
  (StayFD *)WBMain,
  (StayFD *)WSocFlash,
  (StayFD *)WAsopdFlash,
  (StayFD *)WCenterFlash,
  (StayFD *)WEdarpFlash,
  (StayFD *)WgetID,
  (StayFD *)WGroup,
  (StayFD *)WListRn,
  (StayFD *)WListUserID,
  (StayFD *)WProcParam,
  (StayFD *)WProcSet,
  (StayFD *)WSelProc,
  (StayFD *)WUserParam,
  (StayFD *)WUserSet,
  NULL};

PICMODULEEND(_BOX_COMMON)

/* End FCtabl */
/* Begin FTfield */
/* End FTfield */
/* Begin FTdataset */
/* End FTdataset */
/* Begin FTtcm */
/* End FTtcm */
/* Begin FTframe */
/* End FTframe */
/* Begin FTtabl */
/* End FTtabl */
/* Begin FCmmm */
/* End FCmmm */
/* Begin FMfield */
/* End FMfield */
/* Begin FMdataset */
/* End FMdataset */
/* Begin FMframe */
/* End FMframe */
/* Begin FMend */
/* End FMend */
/* Begin FTend */
/* End FTend */
/* Begin FCend */
/* End FCend */
