////////////////////////////////////////////////////////////////////////////////////
//
//  Функции среды функционирования
//
////////////////////////////////////////////////////////////////////////////////////
#include "vcconfig.h"
#include "_box_common.h"
#include "resource.h"
#include "station_ident.h"
#include "moduls_check.h"

//Идентификация рабочих станций, для отключения закоментировать:
#define _STATION_IDENTIFICATION


enum working_mode_e {
  _wm_unknown_ = 255,
  _wm_asopd_ = 0,
  _wm_soc_ = 1,
  _wm_centr_ = 2,
  _wm_edarp_ = 3
};

static DWORD bg_colors [] = {
  0xffff80, 0xffc080, 0xc0c080, 0xd00000
};

int working_mode = _wm_unknown_;


char* icon_text [] = {
  "АСОПД-W: %s район %s",
  "АС МСП: %s район %s",
  "ЦС МСП: %s район %s",
  "ЄДАРП: %s район %s",
};

char* cfg_file [] = {
  "SYSMAIN:asopd.cfg",
  "SYSMAIN:soc.cfg",
  "SYSMAIN:centr.cfg",
  "SYSMAIN:edarp.cfg",
};


#define IDI_ICON IDI_ASOPD_ICON_1

//char IconText[] = "ЦС МСП: %s район %s";
//char CfgFile[] = "SYSMAIN:centr.cfg";

char* IconText;// = "ЦС МСП: %s район %s";
char* CfgFile;// = "SYSMAIN:centr.cfg";

BOOL fltGrpAt = FALSE;

char AboutText[] =
  "Автоматизована система\n"
  "Міністерства соціальної політики України\n\n"
  "Оболонка середовища функціонування v7.0 (25.10.2013)\n\n"
  "STAY.45";

#define _ASOPD_RESTORE 65000

//-------------------------------------------------------------------------
VCCONFIGMAIN ("Запуск задач середовища функцiонування");
//-------------------------------------------------------------------------
static char buf[255];
static char Spr_[255];
BYTE  Find_Context (StayDataset* Base, StayEvent s, StayFD* FindName);

int GetIni (const char* fname);
int SetIni (const char* fname);
void add_all_regions ();
void remove_all_regions ();


HCURSOR Cursor = NULL, OldCursor = NULL;
HICON TrayIcon = NULL;

//  Операции работы с паролем
static char __codes [] = {
  102, 69,  83, 90,  112, 120, 100, 94,
  102, 89,  76, 65,  117, 117, 80,  68,
  62,  109, 63, 115, 99,  67,  106, 64,
  124, 84,  61, 71,  93,  71,  92 , 63,
  123, 0
};

// Табица цветов при раскрашивании задач
static DWORD _clrs[] = {
  0x8080ff, 0x0000ff, 0x404080, 0x000040,
  0x80ffff, 0x4080ff, 0x008080, 0x80ff80,
  0x008000, 0x808000, 0x808080, 0xffff00,
  0x804000, 0xff0000, 0xff8000, 0xff8080,
  0xc080ff, 0xc08080, 0x400080, 0x800080,
  0x8000ff, 0xff0080, 0xffffff, 0xc08000,
};

bool MainLoop ();
static  HANDLE  ssf;

class CStayNotifyIcon {
public:
  NOTIFYICONDATA m_ntd;
  WNDPROC m_proc;
  BOOL m_enable;
  HMENU m_menu;
  IWStayWin* m_frame;
  IWStayWin* m_user;
  CStayNotifyIcon (StayWindow* w, DWORD icon, const char* tip, HMENU menu) {
    m_enable = true;
    m_menu = NULL;
    m_ntd.cbSize = sizeof (NOTIFYICONDATA);
    m_frame = GetFrame (w);
    m_frame->GetWnd (&m_ntd.hWnd);
    m_ntd.uID = 1;
    m_ntd.uFlags = NIF_MESSAGE;
    m_ntd.uCallbackMessage = _ASOPD_RESTORE;
    m_ntd.hIcon = NULL;
    if (tip) {
      m_ntd.uFlags |= NIF_TIP;
      StrCpy (m_ntd.szTip, tip);
    }
    if (icon) {
      m_ntd.uFlags |= NIF_ICON;
      m_ntd.hIcon = LoadIcon (pWStayApp->m_instance, MAKEINTRESOURCE (icon));
    }
    m_menu = menu;
    m_proc = (WNDPROC)GetWindowLong (m_ntd.hWnd, GWL_WNDPROC);
    m_user = (IWStayWin*)GetWindowLong (m_ntd.hWnd, GWL_USERDATA);
    //SetWindowLong (m_ntd.hWnd, GWL_USERDATA, (long)this);
    SetWindowLong (m_ntd.hWnd, GWL_WNDPROC, (LONG)WindowProc);
    Shell_NotifyIcon (NIM_ADD, &m_ntd);
  }
  ~CStayNotifyIcon () {
    StayRelease (m_frame);
    Shell_NotifyIcon (NIM_DELETE, &m_ntd);
    SetWindowLong (m_ntd.hWnd, GWL_WNDPROC, (LONG)m_proc);
    DestroyMenu (m_menu);
  }
  void Enable (BOOL p) {
    m_enable = p;
  }
  static LRESULT CALLBACK WindowProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

CStayNotifyIcon* icon = NULL;

LRESULT CALLBACK CStayNotifyIcon::WindowProc (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  POINT pos;
  LRESULT h;
  switch (msg) {
    case _ASOPD_RESTORE:
      if (lParam == WM_RBUTTONUP) { //Right mouse down
        GetCursorPos (&pos);
        if (icon->m_enable) TrackPopupMenuEx (icon->m_menu, TPM_VERTICAL | TPM_LEFTALIGN, pos.x, pos.y, wnd, NULL);
        break;
      }
      if (lParam == WM_LBUTTONDOWN) { //Left mouse down
        SetForegroundWindow (wnd);
        break;
      }
      break;
    case WM_COMMAND:
      if (!HIWORD (wParam)) {
        icon->m_frame->EventProc (wParam, 0);
      }
      break;
  }
// SetWindowLong (wnd, GWL_USERDATA, (long)notify->m_user);
  h = CallWindowProc (icon->m_proc, wnd, msg, wParam, lParam);
// SetWindowLong (wnd, GWL_USERDATA, (long)notify);
  return h;
}

inline void PackPassw (BOOL bPack)
{
  for (BOOL ch = true, i = 0; __codes[i]; i++) {
    if (bPack) { //  Упаковать пароль
      if (ch) {
        ch = User_Passw [i];
        User_Passw [i] ^= User_UserNum % 114;
        User_Passw [i] <<= 1;
      } else User_Passw [i] ^= __codes[i];
    } else { //  Распаковать пароль
      User_Passw [i] >>= 1;
      User_Passw [i] ^= User_UserNum % 114;
    }
  }
}

WORD OpenShellShareFile () //  Открыть файл разделения
{
  char path[MAX_PATH];
  FullPath (path, "RES:SHELL.SHR");
  return (ssf = CreateFile (path, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_ALWAYS, 0, 0)) != INVALID_HANDLE_VALUE;
}

WORD CloseShellShareFile () //  Закрыть файл разделения
{
  if (ssf != INVALID_HANDLE_VALUE) CloseHandle (ssf);
  return true;
}

WORD LockShellShareFile (long seek) //  Заблокировать файл разделения
{
  return ssf != INVALID_HANDLE_VALUE ? LockFile (ssf, 0xFFFC0000 + seek, 0, 1, 0) : 0;
}

WORD UnlockShellShareFile (long seek) //  Разблокировать файл разделения
{
  return ssf != INVALID_HANDLE_VALUE ? UnlockFile (ssf, 0xFFFC0000 + seek, 0, 1, 0) : 0;
}

//  Управление списком задач
int bosWFlash (StayEvent s, StayEvent id)
{
  switch (s) {
    case _Enter:
      if (Cursor) OldCursor = SetCursor (Cursor);
      MainLoop ();
      Exit (_Ok);
      break;
    case _BeforeWindow: {
      HICON ico;
      HWND wnd;
      IWStayWin* frame = GetFrame (NULL);
      frame->GetWnd (&wnd);
      ico = LoadIcon (pWStayApp->m_instance, MAKEINTRESOURCE (IDI_ICON));
      SetClassLong (wnd, GCL_HICON, (LONG)ico);
      StayRelease (frame);
      PutChar (_Enter);
      break;
    }
    case _AfterWindow:
      if (Cursor) SetCursor (OldCursor);
      break;
  }
  return 0;
}

static int atProc = FALSE;
//  Окно параметров задачи
int bosWProcParam (StayEvent s, StayEvent id)
{
  IWStayWin* tb;
  if (s == _BeforeWindow) {
    if (atProc) {
      Clear (B_Proc);
      Before (B_Proc);
      for (SetIndex (B_Proc, 2), SB_ProcView = 1; TestKey (B_Proc) && SB_ProcView < 0xFFFF; SB_ProcView++);
      for (SetIndex (B_Proc, 1), SB_ProcNpp  = 1; TestKey (B_Proc) && SB_ProcNpp  < 0xFFFF; SB_ProcNpp++);
    }
  }
  if (s == _BeforeWindow || (id > 5000 && id < 5025)) {
    if (tb = GetItem (NULL, 5000 + SB_ProcC)) {
      if (SB_ProcC && SB_ProcC <= sizeof (_clrs) / sizeof (*_clrs)) tb->SetProperty ("text", (DWORD)"");
      StayRelease (tb);
    }
  }
  if (id > 5000 && id < 5025) { // Выбрать цвет задачи
    SB_ProcC = (BYTE) (id - 5000);
    if (s == _Select) {
      ModifyField (NULL, id);
      SetCurrent (NULL, 3001);
    }
  }
  if (s == _BeforeWindow || (id > 5000 && id < 5025)) {
    if (tb = GetItem (NULL, 5000 + SB_ProcC)) {
      if (SB_ProcC && SB_ProcC <= sizeof (_clrs) / sizeof (*_clrs)) tb->SetProperty ("text", (DWORD)"X");
      StayRelease (tb);
    }
  }
  if (s == _Ok && IsModifyWindow (NULL)) {
    if (atProc) Put (B_Proc);
    else Modify (B_Proc);
  }
  if (s == _Esc) {
    if (IsModifyWindow (NULL)) {
      if (QueryBox ("Оболонка середовища функціонування", "Змінити задачу?", "Відмовитися", "Підтвердити") == _Ok) {
        if (atProc) Put (B_Proc);
        else Modify (B_Proc);
      }
    }
    Exit (_Cancel);
  }
  return 0;
}

//  Окно списка задач
int bosWProcSet (StayEvent s, StayEvent id)
{
  STAYBKMARK mark, markn;
  IWStayWin* tb;
  WORD npp, npp2;
  switch (s) {
    case _BeforeWindow:
      SetIndex (B_Proc, 2);
      break;
    case _BeforeRecord: // Расскрасить задачу
    case _ShowRecord:
      tb = GetItem (NULL, 3012);
      if (SB_ProcC && SB_ProcC <= sizeof (_clrs) / sizeof (*_clrs)) tb->SetProperty ("color", _clrs[SB_ProcC - 1]);
      else tb->SetProperty ("color", 0x7F0000);
      StayRelease (tb);
      break;
    case _F2:  //  Переместить задачу вниз
    case _CtF2:  //  Переместить задачу вверх
      if (!Locate (B_Proc)) break;
      mark = GetBookmark (B_Proc);
      for (int i = 0; ; i++) {
        SB_ProcView = 0xFFFF;
        if (!GetKey (B_Proc)) break;
        SB_ProcView = i;
        Modify (B_Proc);
      }
      GetByBookmark (B_Proc, mark);
      npp = SB_ProcView;
      if ((s != _F2 && GetNext (B_Proc)) || (s != _CtF2 && GetPrior (B_Proc))) {
        npp2 = SB_ProcView;
        SB_ProcView = 0xFFFF;
        markn = GetBookmark (B_Proc);
        Modify (B_Proc);
        GetByBookmark (B_Proc, mark);
        SB_ProcView = npp2;
        Modify (B_Proc);
        GetByBookmark (B_Proc, markn);
        SB_ProcView = npp;
        Modify (B_Proc);
      }
      GetByBookmark (B_Proc, mark);
      ShowTable (NULL, 0);
      break;
    case _F3:  //  Настройка задачи
      if (!Locate (B_Proc)) atProc = TRUE;
      else                 atProc = FALSE;
      npp = SB_ProcNpp;
      Display (WProcParam, bosWProcParam);
      SB_ProcNpp = npp;
      GetKey (B_Proc);
      ShowTable (NULL, 0);
      return TRUE;
    case _KeyInsert: //  Новая задача
      npp = SB_ProcNpp;
      atProc = TRUE;
      Display (WProcParam, bosWProcParam);
      SB_ProcNpp = npp;
      GetKey (B_Proc);
      ShowTable (NULL, 0);
      return TRUE;
    case _KeyDelete: //  Удалить задачу
      if (QueryBox ("Оболонка середовища функціонування", "Видалити задачу %D?\n'%D'", "Відмивитися", "ВИДАЛИТИ", _SB_Proc, _SB_ProcStr) == _Ok) {
        Delete (B_Proc);
        ShowTable (NULL, 0);
        return TRUE;
      }
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////////
//  Управление списком пользователей
////////////////////////////////////////////////////////////////////////////////////

static BOOL bMarked = FALSE; // Признак показа задач списка через марки

//  Фильтр по правам на задачи
StayEvent fltTsk ()
{
  if (User_Hay == SHELLSUPERVISOR) return _Suit; //  Супервизор
  return GetKey (B_AccProc) ? _Suit : _Unsuit; //  Задача принадлежит в списке пользоватьеля
}

//  Фильтр выбора списка задач
static StayEvent fltProc ()
{
  if (GetKey (B_AccProc)) return bMarked ? _Suit : _Unsuit;
  return !bMarked ? _Suit : _Unsuit;
}

//  Выбор района
int bosWListRn (StayEvent s, StayEvent id)
{
  switch (s) {
    case 2001:
      if (!SelectRn (RL_RnName, NL_NetName, false, true)) break;
      Put (B_AccR);
      SetCurrent (NULL, 3000);
      ShowTable (NULL, 0);
      break;
    case 2002: //_CtY:
      Delete (B_AccR);
      SetCurrent (NULL, 3000);
      ShowTable (NULL, 0);
      break;
    case 2003:
      add_all_regions ();
      SetCurrent (NULL, 3000);
      ShowTable (NULL, 0);
      break;
    case 2004:
      remove_all_regions ();
      SetCurrent (NULL, 3000);
      ShowTable (NULL, 0);
      break;
    case _Esc:
      Exit (_Ok);
      break;
    case _ShowRecord:
      KlAt_Code = atoi (RL_RnName);
      if (!GetKey (B_KlAt)) KlAt_Name[0] = 0;
      strcpy (RajName, KlAt_Name);
      break;
  }
  return 0;
}

//  Выбор группы
int bosWGroup (StayEvent s, StayEvent id)
{
  switch (s) {
    case 3002:
    case _Enter:
      Put (B_ListUsers);
      Exit (_Ok);
      break;
    case _CtY:
    case _Ins:
      if (CurrentChoice () == 3000) break;
      SetCurrent (NULL, 3000);
      break;
  }
  return 0;
}

//  Окно выбора списка
int bosWSelProc (StayEvent s, StayEvent id)
{
  IWStayWin* frame, *item1, *item2;
  switch (s) {
    case _BeforeWindow:
      PutChar (3010);
      break;
    case 3002:   // Выбрать запись и сменить список
    case _Enter:
      if (!Locate (B_Proc)) break;
      if (!bMarked)
        Put (B_AccProc);
      else {
        if (GetKey (B_AccProc)) Delete (B_AccProc);
      }
      PutChar (3011);
      break;
    case _F3:
    case 3001:
      bMarked ^= true;
      PutChar (3010);
      break;
    case 3010:
      SetBegin (B_Proc);
      GetNext  (B_Proc);
      PutChar (3011);
      break;
    case 3011:
      SetCurrent (NULL, 3000);
      frame = GetFrame (NULL);
      frame->GetItemByID (3001, &item1);
      frame->GetItemByID (3002, &item2);
      frame->SetProperty ("text", (long) (bMarked ? "Перелік доступних задач" : "Перелік недоступних задач"));
      item1->SetProperty ("text", (long) (bMarked ? "Недоступні" : "Доступні"));
      item2->SetProperty ("text", (long) (bMarked ? "Виключити" : "Включити"));
      item2->SetProperty ("enable", (long) (Locate (B_Proc) ? TRUE : FALSE));
      StayRelease (item2);
      StayRelease (item1);
      StayRelease (frame);
      ShowTable (NULL, 0);
      ShowWnd   (NULL);
      break;
  }
  return 0;
}

//  Окно изменения
int bosWUserParam (StayEvent s, StayEvent id)
{
  char gu[MAX_PATH];
  switch (s) {
    case SELGroupU:  //  Выбрать группу
      StrCpy (gu, GU_NameGroup);
      if (Display (WGroup, bosWGroup) != _Ok)
        StrCpy (GU_NameGroup, gu);
      else ShowWnd (NULL);
      break;
    case SELURN: //  Выбрать доступные районы
      StrDCpy (_TmpRnNet, "Область");
      StrDCpy (_TmpRnNet2, "Район");
      OpenCreate (B_KlAt, STAY_RD | STAY_ANRDWR);
      Display (WListRn, bosWListRn);
      Close (B_KlAt);
      ModifyField (NULL, 3015);
      break;
    case SELUARM:  //  Выбрать доступные задачи
      SetFilter (B_Proc, fltProc);
      bMarked = true;
      Display (WSelProc, bosWSelProc);
      SetFilter (B_Proc, fltTsk);
      SetBegin (B_Proc);
      break;
    case _AfterField:
      /*if (id == 3011) StrUpr (User_ID);
      if (id == 3013) StrUpr (User_Passw);*/
      break;
    case _Esc:
      if (QueryBox ("Оболонка середовища функціонування", "Змінити параметри користувача?", "Відмовитися", "Підтвердити") == _Ok)
        Exit (_Ok);
      else Exit (_Cancel);
      break;
    case _Exit:
      if (!TestKey (B_User)) { //  Проверить правильность User_UserNum
        ::MessageBox (NULL, "Дублювання властивостей користувача", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
        return true;
      }
      break;
  }
  return 0;
}

//  Окно списка
static int bosWUserSet (StayEvent s, StayEvent id)
{
  IWStayWin* tb2, *tb3, *tb4, *tb5;
  switch (s) {
    case _BeforeRecord:  //  Определить в подножие запущенную задачу активного пользователя
      tb5 = GetItem (NULL, 3005);
      if (!GetKey (B_Proc)) *SB_Proc = 0;
      if (tb5) {
        if (LockShellShareFile (User_UserNum)) {
          *SB_Proc = 0;
          UnlockShellShareFile (User_UserNum);
        }
        tb5->SetProperty ("text", (DWORD)SB_Proc);
        StayRelease (tb5);
      }
      break;
    case _ShowRecord:  //  Раскрасить пользователей в сети
      tb2 = GetItem (NULL, 3002);
      tb3 = GetItem (NULL, 3003);
      tb4 = GetItem (NULL, 3004);
      if (tb2 && tb3 && tb4) {
        if (!LockShellShareFile (User_UserNum)) {
          tb3->SetProperty ("color", 0x0000FF);
          tb4->SetProperty ("color", 0x0000FF);
          tb2->SetProperty ("color", 0x0000FF);
        } else {
          tb3->SetProperty ("color", 0x7F0000);
          tb4->SetProperty ("color", 0x7F0000);
          tb2->SetProperty ("color", 0x7F0000);
          UnlockShellShareFile (User_UserNum);
        }
        StayRelease (tb3);
        StayRelease (tb4);
        StayRelease (tb2);
      }
      break;
    case _F5:  //  Обновить пользователей в сети
      ShowTable (NULL, 0);
      break;
    case _F3:  //  Изменить пользователя
      if (!Locate (B_User)) break;
    case _KeyInsert: //  Новый пользователь
      if (s == _KeyInsert && QueryBox ("Оболонка середовища функціонування", "Створити нового користувача?", "Відмовитися", "Створити") != _Ok)
        return true;
      if (s == _KeyInsert) {
        WORD n = 0;
        SetEnd (B_User);
        if (GetPrev (B_User)) n = User_UserNum;
        Clear (B_User);
        Before (B_User);
        User_Hay = SHELLUSER;
        User_UserNum = ++n;
        StrCpy (User_ID, "USER");
        StrCpy (User_IDName, "USERNONAME");
      } else {
        ANSItoOEM (User_Passw);
        PackPassw (FALSE);
      }
      User_Hay = (User_Hay == SHELLADM) ? 0x0002 : (User_Hay == SHELLSUPERVISOR) ? 0x0004 : 0x0001;
      if (Display (WUserParam, bosWUserParam) == _Ok) {
        User_Hay = (User_Hay & 0x0002) ? SHELLADM : (User_Hay & 0x0004) ? SHELLSUPERVISOR : SHELLUSER;
        PackPassw (true);
        OEMtoANSI (User_Passw);
        if (s != _KeyInsert) Modify (B_User);
        else Put (B_User);
      }
      ShowTable (NULL, 0);
      return true;
    case _KeyDelete: //  Удалить пользователя
      if (QueryBox ("Оболонка середовища функціонування", "Видалити користувача %D?\n'%D'\n", "Відмовитися", "Видалити", _User_ID, _User_IDName) == _Ok) {
        Delete (B_User);
        ShowTable (NULL, 0);
        return 1;
      }
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////////
//  Регистрация пользователя
////////////////////////////////////////////////////////////////////////////////////
#include "commctrl.h"

//  Окно списка пользователей
int bosWListUserID (StayEvent s, StayEvent id)
{
  IWStayWin* tree;
  char text[200];
  HTREEITEM hroot, hgr;
  STAYBKMARK mark;
  switch (s) {
    case _BeforeWindow:  //  Обновить состав групп
      tree = GetItem (NULL, 3002);
      hroot = StayTree_InsertItem (tree, 0, "Пользователи", TVIS_BOLD | TVIS_EXPANDED, 0);
      for (SetBegin (B_GroupU); GetNext (B_GroupU);) {
        strcpy (text, "Группа ");
        strcat (text, GU_NameGroup);
        hgr = StayTree_InsertItem (tree, hroot, text, TVIS_BOLD, 0);
        for (SetBegin (B_User); GetNext (B_User);) {
          strcpy (text, User_IDName);
          StayTree_InsertItem (tree, hgr, text, 0, Position (B_User));
        }
      }
      *GU_NameGroup = 0;
      fltGrpAt = TRUE;
      for (SetBegin (B_User); GetNext (B_User);) {
        strcpy (text, User_IDName);
        //StayTree_InsertItem (tree, hgr, text, 0, Position (B_User));
        StayTree_InsertItem (tree, hroot, text, 0, Position (B_User));
      }
      fltGrpAt = FALSE;
      StayRelease (tree);
      break;
    case 3001: //  Выбрать пользователя
    case _Select:
      tree = GetItem (NULL, 3002);
      mark = StayTree_GetCurrentParam (tree);
      if (mark) {
        GetPosition (B_User, mark);
        Exit (_Ok);
      }
      StayRelease (tree);
      return 0;
    case _Esc:
      Exit (_Cancel);
      break;
  }
  return 0;
}

//  Окно регистрации пользователя
int bosWgetID (StayEvent s, StayEvent id)
{
  char userid[50];
  switch (s) {
    case _BeforeWindow:
      *User_ID = *User_Passw = 0;
      GetItem (NULL, 3002)->SetProperty ("password", true);
      GetIni ("WORK:shell.ini");
      break;
    case _AfterWindow:
      SetIni ("WORK:shell.ini");
      break;
    case _F2:  //  Выбрать пользователя
      strcpy (userid, User_ID);
      if (Display (WListUserID, bosWListUserID) == _Ok) {
        *User_Passw = 0;
        ModifyField (NULL, 3001);
        ModifyField (NULL, 3002);
        SetCurrent (NULL, 3002);
      } else {
        strcpy (User_ID, userid);
        *User_Passw = 0;
      }
      ShowWnd (NULL);
      break;
    case 2001: //  Выполнить регистрацию
      Exit (_Ok);
      return TRUE;
  }
  return FALSE;
}

//  Фильтр по группам пользователей
StayEvent fltGrp ()
{
  static char  gu[MAX_PATH];
  //if(User_Hay == SHELLSUPERVISOR) // Супервизор
  //  return _Suit;
  strcpy (gu, GU_NameGroup);
  if (fltGrpAt) {
    return *GU_NameGroup ? _Unsuit : _Suit;
  }
  Get (B_GroupU);
  return !_stricmp (gu, GU_NameGroup) ? _Suit : _Unsuit; // Пользователь принадлежит группе
}

//  Выбрать пользователя
BOOL SelectUser ()
{
  // Регистрация пользователя
  BOOL bLoged  = FALSE;
  BOOL bFailed = FALSE;  //  Успешная регистрация
  for (int n = 3; n-- && !bLoged;) {
    // Запрос пользователя
    SetFilter (B_User, fltGrp);
    SetBegin (B_User);
    if (Display (WgetID, bosWgetID) != _Ok) break;
    if (Cursor) OldCursor = SetCursor (Cursor);
    SetFilter (B_User, NULL);
    SetBegin (B_User);
    //  Найти запись пользователя
    char ID[MAX_PATH];
    char Passw[MAX_PATH];
    StrCpy (ID, User_ID);
    StrCpy (Passw, User_Passw);
    StrUpr (ID);
    StrUpr (Passw);
    for (SetBegin (B_User), bFailed = true; bFailed && GetNext (B_User);) {
      ANSItoOEM (User_Passw);
      PackPassw (FALSE);
      bFailed = (StrCmp (User_ID, ID) || StrCmp (User_Passw, Passw));
      if (!bFailed) {
        if (!LockShellShareFile (User_UserNum)) { //  'Пробная' блокировка
          ::MessageBox (NULL, "Користувач зареєстрований з іншої станції", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
        } else {
          bLoged = true;
          //UnlockShellShareFile (0xFFFC0000 + User_UserNum, 1); //  'Пробная' блокировка
          //if (GetProcState ()) UnlockShellShareFile (0xFFFC0000 + GetProcState(), 1);  //  Разблокировать предыдущего пользователя
          SetUser ((char*)User_UserNum, User_Passw); //  Новый пользователь
          ProtWrite (NULL, 0, STARTPROC,   "Реєстрація користувача.Доступ дозволено.");
        }
      }
    }
    //  Отказ в регистрации пользователя
    if (bFailed) {
      if (!Size (B_User) && (!StrCmp ("SUPERVISOR", ID) && !StrCmp ("SUPERVISOR", Passw))) { //  база пуста - SUPERVISOR/SUPERVISOR
        bLoged = true;
        User_Hay = SHELLSUPERVISOR;
        SetUser ((char*)0xffff, "SUPERVISOR"); //  Формальный пользователь
      } else {
        ::MessageBox (NULL, "Невірний ідентифікатор або пароль користувача", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
        ProtWrite (NULL, 0, STARTPROC, "Реєстрація користувача.В доступі відмовлено.Ідентифікатор-%s.", ID);
      }
    }
  }
  return bLoged;
}

//Проверка настройки первасива
bool CheckPervasive()
{
  HKEY    hk;
  char*   KeyPath[] =
  {
    "SOFTWARE\\Pervasive Software\\MicroKernel Workstation Engine\\Version 7\\Settings",
    "SOFTWARE\\Pervasive Software\\MicroKernel Server Engine\\Version 8\\Settings",
    "SOFTWARE\\Wow6432Node\\Pervasive Software\\MicroKernel Server Engine\\Version 8\\Settings",
    "SOFTWARE\\Wow6432Node\\Pervasive Software\\MicroKernel Server Engine\\Version 9\\Settings",
    "SOFTWARE\\Pervasive Software\\MicroKernel Server Engine\\Version 9\\Settings",
    NULL
  };
  char    Name[] = "File Version";
  char    Buff[10];
  DWORD   BuffLen = 10;
  bool    result = false;

  for (int i=0; KeyPath[i]; i++)
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, KeyPath[i], 0, KEY_ALL_ACCESS, &hk) == ERROR_SUCCESS)
    {
      if (RegQueryValueEx(hk, Name, 0, 0, (BYTE*)Buff, &BuffLen) == ERROR_SUCCESS)
      {
        if (strcmp(Buff, "0600") == 0)
        {
          result = true;
          RegCloseKey(hk);
          break;
        }
      }
      RegCloseKey(hk);
    }
  if (!result) ::MessageBox (NULL, "Не вірне налаштування Pervasive.\nПовинна бути встановлена 6-та версія файлів.", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
  return result;
}

static char cmd[MAX_PATH + 1] = "";   //  Имя запускаемой задачи
static char par[MAX_PATH + 1] = "";   //  Параметры запуска задачи

//  Ситуации при работе программы среды функционирования
#define SHELLEXIT 1           //  Выход из программы
#define SHELLEXECUTE  2           //  Запуск задачи
#define SHELLCHANGERN 3           //  Смена района
#define SHELLSHUTDOWN 4           //  Выход из программы
#define SHELLCHANGEUSER 5           //  Смена района

//  Главное окно
int bosWBMain (StayEvent s, StayEvent id)
{
  char rnname[MAX_PATH], ntname[MAX_PATH];
  char str[MAX_PATH * 2], str2[MAX_PATH * 2], *pstr;
  IWStayWin* item;
  switch (s) {
    case _BeforeWindow:
      if (!CheckPervasive()) Exit(SHELLEXIT);
      item = GetItem (NULL, 5000);
      if (item) {
        item->SetProperty ("bgcolor", bg_colors [working_mode]);
        StayRelease (item);
      }
      DateText (TmpDtW, GetSysDate (), 50);
      StrDCpy  (_TmpUsNW, User_IDName);
      StrDCpy  (_TmpNetW, NL_NetName);
      StrDCpy  (_TmpRnW, RL_RnName);
      StrDCpy  ( _TmpAccW, User_Hay == SHELLSUPERVISOR ? "SUPERVISOR" : User_Hay == SHELLADM ? "ADMIN" : "USER");
      if (OpenCreate (B_KlAt, STAY_RD | STAY_ANRD)) {
        KlAt_Code = atoi (RL_RnName);
        if (GetKey (B_KlAt)) StrCpy (TmpNetName, KlAt_Name);
        else *TmpNetName = 0;
        Close (B_KlAt);
        StrForm (str, 64, IconText, User_IDName, RL_RnName);
        icon = new CStayNotifyIcon (NULL, IDI_ICON, str, pop_menu ());
      }
#ifndef _STATION_IDENTIFICATION
      AvailableChoice (WBMain, 10306, FALSE);
#endif
      InitPrototype ();
      break;
    case _AfterWindow:
      StayDelete (icon);
      TermPrototype ();
      break;
    case _BeforeRecord:
      ShowWnd (NULL);
      item = GetItem (NULL, 3016);
      if (item) {
        item->Show ();
        StayRelease (item);
      }
//    break;
    case _ShowRecord:  //  Расскрасить задачи
      item = GetItem (NULL, 3012);
      if (item) {
        if (SB_ProcC && SB_ProcC <= sizeof (_clrs) / sizeof (*_clrs)) item->SetProperty ("color", _clrs[SB_ProcC - 1]);
        else item->SetProperty ("color", 0x7F0000);
        StayRelease (item);
      }
      break;
    case _Enter: //  Запустить задачу
      if (id != 3000 && id != _Enter)      break;
    case 3000:
      if (icon) icon->Enable (FALSE);//PopupFlag = false;
      StrForm (str, sizeof (str), "%s\\%s", SB_ProcCD, SB_ProcStr);
      if (pstr = StrChr (str, ' ')) * pstr++ = 0; //  Отделить параметры
      if (Cursor) OldCursor = SetCursor (Cursor);
      //  Запуск...
      if (FExist (str)) { //  Запуск по полному пути
        if (CheckSum (SB_ProcStr, SB_ProcCD)) {
          ProtWrite (NULL, 0, STARTPROC,  "Запуск користувачем АРМ \"%D\" з оболонки средовича функціонування.", _SB_Proc);
          strncpy (cmd, str, MAX_PATH);
          cmd[MAX_PATH] = 0;
          strncpy (par, pstr ? pstr : "", MAX_PATH);
          par[MAX_PATH] = 0;
          FullPath (str2, SB_ProcCD);
          SetCurrentDir (str2);
          SetLogDir ("SYSCURRENT", SB_ProcCD);
          //  Сохранить настройки пользователя
          User_UserNum = GetProcState ();
          GetKey (B_User);
          if (Locate (B_User)) Modify (B_User);
          int r;//try
          r = SpawnModule (cmd, par);
          User_UserNum = GetProcState ();
          GetKey (B_User);
          if (r == -9) { //catch (...)
            ProtWrite (NULL, 0, PROCERROR, "Невдале завершення АРМ \"%D\"", _SB_Proc);
          }
          if (Cursor) SetCursor (OldCursor);
          //     Exit(SHELLEXECUTE);
        }
      } else ::MessageBox (NULL, "Хибний шлях або ім'я задачі", str,  MB_ICONWARNING | MB_OK);
      if (icon) icon->Enable (TRUE);//PopupFlag = true;
      return TRUE;
    case _AltX:
      if (QueryBox ("Оболонка середовища функціонування", "Завершити роботу програми?", "Ні", "Так") != _Ok)
        return TRUE;
    case _Close: //  Сменить пользователя
    case 10206:
      if (Locate (B_User)) Modify (B_User); // Сохранить настройки пользователя
      ProtWrite (NULL, 0, STOPPROC, "Завершення работи с оболонкою средовища функціонування.");
      Exit (SHELLEXIT);
      break;
    case _F5:
    case 10102:
      if (Locate (B_User)) Modify (B_User); // Сохранить настройки пользователя
      ProtWrite (NULL, 0, STOPPROC, "Зміна користувача");
      Exit (SHELLCHANGEUSER);
      break;
    case _F6:
    case 10101:  //  Сменить район
      strcpy (rnname, RL_RnName);
      strcpy (ntname, NL_NetName);
      if (!SelectRn (RL_RnName, NL_NetName, true, false)) break;
      if (strcmp (rnname, RL_RnName) == 0 && strcmp (ntname, NL_NetName) == 0) break;
      strncpy (str, RL_RnName, 16);
      str[16] = 0;
      strncpy (str2, NL_NetName, 16);
      str2[16] = 0;
      // Сохранить настройки пользователя
      User_UserNum = GetProcState ();
      GetKey (B_User);
      StrDCpy (_RL_RnName, str);
      StrDCpy (_NL_NetName, str2);
      if (Locate (B_User)) Modify (B_User);
      Exit (SHELLCHANGERN);
      break;
    case 10201:
//      if (User_Hay == SHELLSUPERVISOR || User_Hay == SHELLADM)
        WinExec ("control.exe timedate.cpl", SW_SHOW);
//      else ::MessageBox (NULL, "Функція доступна тільки адміністратору чи супервізору", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      break;
    case 10202:
      WinExec ("calc.exe", SW_SHOW);
      break;
    case _F7:
    case 10204:
      SpawnModule ("SYSTEM:SELPRINT.DLL", NULL);
      break;
    case _F2:
    case 10203:
      if (User_Hay == SHELLSUPERVISOR || User_Hay == SHELLADM)
        SpawnModule ("SYSTEM:REPBOX.DLL", NULL);
      else ::MessageBox (NULL, "Функція доступна тільки адміністратору чи супервізору", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      break;
    case _F3:
    case 10205:
      if (User_Hay == SHELLSUPERVISOR || User_Hay == SHELLADM)
        SpawnModule ("SYSTEM:BSW45.EXE", NULL);
      else ::MessageBox (NULL, "Функція доступна тільки адміністратору чи супервізору", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      break;
    case 10301:
      if (User_Hay == SHELLSUPERVISOR || User_Hay == SHELLADM) {
        Display (WProcSet, bosWProcSet);
        //     SetBegin (B_Proc);
        ShowTable (NULL, 0); //  Окно списка задач
      } else ::MessageBox (NULL, "Функція доступна тільки адміністратору чи супервізору", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      break;
    case 10302:
      if (User_Hay == SHELLSUPERVISOR) {
        Display (WUserSet, bosWUserSet); //  Окно списка пользователей
        User_UserNum = GetProcState ();
        GetKey (B_User);
        SetBegin (B_Proc);
        ShowTable (NULL, 0); //  Восстановить пользователя
      } else ::MessageBox (NULL, "Функція доступна виключно супервізору", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      break;
    case 10303:  //  Редактировать файлы настроек
    case 10304:
      if (User_Hay == SHELLSUPERVISOR || User_Hay == SHELLADM) {
        strcpy (str, "start ");
        FullPath (str + strlen (str), s == 10303 ? "RES:SWOBL.INI" : "OBL:SWRAJ.INI");
        WinExec (str, SW_HIDE);
      } else ::MessageBox (NULL, "Функція доступна тільки адміністратору чи супервізору", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      break;
    case 10305:
      if (User_Hay == SHELLSUPERVISOR || User_Hay == SHELLADM)
        ProtShow (NULL, ON, 0);
      else ::MessageBox (NULL, "Функція доступна тільки адміністратору чи супервізору", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      break;
#ifdef _STATION_IDENTIFICATION
    case 10306:
      if (User_Hay == SHELLSUPERVISOR || User_Hay == SHELLADM) {
        if (OpenCreate (B_Access, RDWR | ANRDWR)) {
          Display (WAccess, bosWAccess);
          Close (B_Access);
        } else ::MessageBox (NULL, "Не можливо відкрити/створити файл бази даних робочих станцій.", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      } else ::MessageBox (NULL, "Функція доступна тільки адміністратору чи супервізору", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      break;
#endif
    case _F12: //  Путь запуска
    case _F11: //  Путь запуска
      if (Locate (B_Proc)) {
        StrForm (str, sizeof (str), "Робоча папка %D\n%D", _SB_ProcCD, _SB_ProcStr);
        ::MessageBox (NULL, str, SB_Proc,  /*MB_ICONWARNING |*/ MB_OK);
      }
      break;
    case _ShF1:
    case 11001:
      WinExec ("winhelp.exe",  SW_SHOW);
      break;
    case _F1:
    case 11002:
      WinExec ("winhelp.exe asopd.hlp",  SW_SHOW);
      break;
    case _CtF1:
    case 11003:
      ::MessageBox (NULL, AboutText, "Про програму",  /*MB_ICONWARNING |*/ MB_OK);
      break;
    case _Esc:
      buf[0] = '\0';
      ShowWnd (NULL);
      item = GetItem (NULL, 8000);
      if (item) {
        item->SetProperty ("text", (DWORD)buf);
        StayRelease (item);
      }
      return true;
    case _Up:
    case _Down:
      buf[0] = '\0';
      ShowWnd (NULL);
      item = GetItem (NULL, 8000);
      if (item) {
        item->SetProperty ("text", (DWORD)buf);
        StayRelease (item);
      }
      break;
    case _BackSp: {
      int i = StrLen (buf);
      if (i > 0) buf [i - 1] = 0;
      else buf[0] = 0;
      item = GetItem (NULL, 8000);
      if (item) {
        item->SetProperty ("text", (DWORD)buf);
        StayRelease (item);
      }
    }
    default:
      if (s < 256 && s > 31) {
        Find_Context (B_Proc, s, _SB_Proc);
        item = GetItem (NULL, 8000);
        if (item) {
          item->SetProperty ("text", (DWORD)buf);
          StayRelease (item);
        }
      }
      break;
  }
  return 0;
}

bool MainLoop ()
{
#ifdef _STATION_IDENTIFICATION
  if (!GetAccess ()) {
    ::MessageBox (NULL, "Відмовлено в доступі з цієї робочої станції.\nЗверніться до адміністратора.", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
    return false;
  }
  SetActiveStation (true);
#endif
  SetLanguage (1);
  OpenShellShareFile ();
  if (!OpenCreate (B_User, RDWR | ANRDWR) || !OpenCreate (B_GroupU, RDWR | ANRDWR)) {
    ::MessageBox (NULL, "Не відкрита база користувачів або груп", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
    return true;
  }
  if (!OpenCreate (B_Proc, RDWR | ANRDWR)) {
    ::MessageBox (NULL, "Не відкрита база задач", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
    return true;
  }
  SetIndex (B_User, 1);
  SetIndex (B_Proc, 2);
  for (SetBegin (B_User); GetNext (B_User); ) {
    if (*GU_NameGroup == 0) continue;
    if (GetKey (B_GroupU)) continue;
    *GU_NameGroup = 0;
    Modify (B_User);
  }
// Инициализация по пользователю
  int  r = SHELLEXIT;
  for (;;) {
    SetFilter (B_Proc, fltTsk);
    SetBegin (B_Proc);
    WORD ps = GetProcState ();
    UnlockShellShareFile (ps);
//SetUser(false, false); // Разблокировать предыдущего пользователя
    if (!SelectUser ()) {        // Регистрация пользователя
      if (r == SHELLCHANGEUSER)
        ::MessageBox (NULL, "Користувача відновлено", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      else  break;
      User_UserNum = ps;
      SetUser ((char*)ps, false);
    } else User_UserNum = GetProcState ();
    GetKey (B_User);
    // Инициализация по району
    SB_ProcNpp = 0;
    if (Locate (B_User)) Modify (B_User);
    for (;;) {
      SwitchRn (RL_RnName, NL_NetName);
      User_UserNum = GetProcState ();
      if (GetKey (B_User)) Modify (B_User);
      if (*RL_RnName) {
        char msg [256];
        wsprintf (msg, "Встановлений район %s\nОбласть %s\n", RL_RnName, NL_NetName);
        ::MessageBox (NULL, msg, "Оболонка середовища функціонування",  /*MB_ICONINFORMATION |*/ MB_OK);
        if (!fGetTech ("РАЙОН"))
          ::MessageBox (NULL, "Не визначений ресурс району", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      } else ::MessageBox (NULL, "Немає активного району", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      ProtWrite (NULL, 0, STARTPROC, "Встановлений район %D", _RL_RnName);
      // Цикл выбора-запуска задач
      int r;
      r = Display (WBMain, bosWBMain);
      if (r != SHELLCHANGERN) break;
    } // Смена района
  } // Смена пользователя
  SetFilter (B_Proc, NULL);
  SetBegin (B_Proc);
  Close (B_Proc);
  Close (B_GroupU);
  Close (B_User);
  CloseShellShareFile ();
#ifdef _STATION_IDENTIFICATION
  SetActiveStation (false);
#endif
  return false;
}

BYTE Find_Context (StayDataset* Base, StayEvent s, StayFD* FindName)
{
  int i;
  StrForm (buf + StrLen (buf), sizeof (buf), "%c\0", s);
  StrUpr  (buf);
  StrForm (Spr_, sizeof (Spr_) - 1, "%D", FindName);
  StrUpr  (Spr_);
  i = StrLen (buf);
  if (StrLen (Spr_) >= i) {
    if (!MemCmp (Spr_, buf, i)) {
      ShowTable (NULL, NULL);
      ShowWnd (NULL);
      return 1;
    }
  }
  Mark (Base, 1);
  SetBegin (Base);
  bool find = false;
  while (GetNext (Base)) {
    StrForm (Spr_, sizeof (Spr_) - 1, "%D", FindName);
    StrUpr  (Spr_);
    i = StrLen (buf);
    if (StrLen (Spr_) < i) continue;
    if (!MemCmp (Spr_, buf, i)) {
      Mark (Base, 1);
//      ShowTable (NULL, NULL);
//      ShowWnd (NULL);
      find = true;
      break;
    }
  }
  if (!find) {
    buf[i - 1] = 0;
  }
  GetMark (Base, 1);
  ShowTable (NULL, NULL);
  ShowWnd (NULL);
  return 0;
}

int GetIni (const char* fname)
{
  StayFile f;
  char buf[50];
  if (!FFind (fname)) return 0;
  f = FOpen (fname, RD);
  if (!f) return 0;
  if (FReadText (f, buf, sizeof (buf)) != -1) strcpy (User_ID, buf);
  FClose (f);
  return 1;
}

int SetIni (const char* fname)
{
  StayFile f;
  f = FCreate (fname, WR);
  if (!f) return 0;
  FWrite (f, User_ID, sizeof (User_ID));
  FClose (f);
  return 1;
}

bool skip_line (char* a)
{
  if (! (*a)) return true;
  if (*a == '/' && * (a + 1) == '/') return true;
  if (*a == 'R' && * (a + 1) == 'E' && * (a + 2) == 'M' && (!* (a + 3) || * (a + 3) == ' ')) return true;
  return false;
}

void remove_all_regions ()
{
  Destroy (B_AccR);
}

void add_all_regions ()
{
  remove_all_regions ();
  StayFile f_obl, f_rn;
  const char* obl_file_name = "RES:SWOBL.INI";
  const char* rn_file_name = "OBL:SWRAJ.INI";
  char default_obl_path [MAX_PATH];
  if (!FExist (obl_file_name) || ! (f_obl = FOpen (obl_file_name, RD | ANRDWR))) return;
  FullPath (default_obl_path, "OBL:");
  char obl_line [255];
  char* obl_name = obl_line, *obl_path = obl_line;
  for (; FReadText (f_obl, obl_name = obl_line, sizeof (obl_line) - 1) != -1;) {
    if (skip_line (obl_name)) continue;
    obl_path = strchr (obl_name, ' ');
    if (!obl_path) continue;
    *obl_path++ = 0;
    StrDCpy (_NL_NetName, obl_name);
    SetVirtualStorage ("OBL", obl_path);
    if (!FExist (rn_file_name) || ! (f_rn = FOpen (rn_file_name, RD | ANRDWR))) continue;
    char rn_line [255];
    char* rn_name = rn_line, *rn_path = rn_line;
    for (; FReadText (f_rn, rn_name = rn_line, sizeof (rn_line) - 1) != -1;) {
      if (skip_line (rn_name)) continue;
      rn_path = strchr (rn_name, ' ');
      if (!rn_path) continue;
      *rn_path++ = 0;
      StrDCpy (_RL_RnName, rn_name);
      Put (B_AccR);
    }
    FClose (f_rn);
  }
  FClose (f_obl);
  SetVirtualStorage ("OBL", default_obl_path);
}

//===========================================================
int main (int argc, char** argv)
{
  Cursor = LoadCursor (0, IDC_WAIT);
  working_mode = _wm_unknown_;
#ifdef _STATION_IDENTIFICATION
  get_station_id ();
#endif
  if (strcmp (argv[1], "centr") == 0) working_mode = _wm_centr_;
  if (strcmp (argv[1], "asopd") == 0) working_mode = _wm_asopd_;
  if (strcmp (argv[1], "soc") == 0) working_mode = _wm_soc_;
  if (strcmp (argv[1], "edarp") == 0) working_mode = _wm_edarp_;
  CfgFile = cfg_file [working_mode];
  IconText = icon_text [working_mode];
  if (argc > 2)
    SetDefaultConfig (argv[2]);
  else
    SetDefaultConfig (CfgFile);
  switch (working_mode) {
    case _wm_centr_:
      Display (WCenterFlash, bosWFlash);
      break;
    case _wm_asopd_:
      Display (WAsopdFlash, bosWFlash);
      break;
    case _wm_soc_:
      Display (WSocFlash, bosWFlash);
      break;
    case _wm_edarp_:
      Display (WEdarpFlash, bosWFlash);
      break;
    default: {
      char msg[255];
      wsprintf (msg, "Невірний параметер запуску: %s\n Можливі варіанти (asopd/soc/centr)\n", argv[1]);
      ::MessageBox (NULL, msg, "Оболонка середовища функціонування",  MB_OK);
      break;
    }
  }
  return 0;
}
