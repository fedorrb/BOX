#include "station_ident.h"

char station_id[20];
bool bFlagAccess = false;


int bosWAccess (StayEvent s, StayEvent id)
{
  IWStayWin* item;
  switch (s) {
    case _BeforeWindow:
      if (Size(B_Access) == 0)
      {
        Access_Code = 1;
        Put(B_Access);
      }
      SetBegin(B_Access);
      GetNext(B_Access);
      break;
    case _AfterWindow:
      break;
    case _ShowRecord: //  Расскрасить задачи
      item = GetItem (NULL, 3201);
      if (item)
      {
        if (Access_Active) item->SetProperty ("color", 0xff0000);
        else item->SetProperty ("color", 0x000000);
        if (strcmp (station_id, Access_Ident) == 0) item->SetProperty ("color", 0x00ff00);
        StayRelease (item);
      }
      Access_AccFlag ? GetItem (NULL, 3206)->SetProperty ("text", (DWORD)"Зняти доступ") : GetItem (NULL, 3206)->SetProperty ("text", (DWORD)"Надати доступ");
      break;
    case 3203://Кнопка Додати
      *Access_Ident = *Access_Comment = 0;
      if (Display (WAddComp, bosWAddComp) == _Ok)
      {
        Access_Active = 0;
        Access_AccFlag = 1;
        Put (B_Acc_List);
        Modify (B_Access);
      }
      //else
      ShowTable (NULL, 0);
      break;
    case 3206://Кнопка Доступ
      if (Locate (B_Acc_List))
      {
        Access_AccFlag = !Access_AccFlag;
        if (Modify (B_Acc_List))
        {
          Modify (B_Access);
          Access_AccFlag ? GetItem (NULL, 3206)->SetProperty ("text", (DWORD)"Зняти доступ") : GetItem (NULL, 3206)->SetProperty ("text", (DWORD)"Надати доступ");
        }
      }
      ShowTable (NULL, 0);
      break;
    case 3207://Кнопка Редагувати
      if (Display (WAddComp, bosWAddComp) == _Ok)
        if (Locate (B_Acc_List))
          if (! (Modify (B_Acc_List) && Modify (B_Access)))
            ::MessageBox (NULL, "Не можливо змінити ідентифікатор робочої станції.\nТакий ідентифікатор вже існує.", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
      //else
      ShowTable (NULL, 0);
      break;
    case 3208://Кнопка Видалити
      if (QueryBox ("Оболонка середовища функціонування", "Видалити запис?", "Так", "Ні") != _Ok)
        if (Locate (B_Acc_List))
          Delete (B_Acc_List);
      //else
      ShowTable (NULL, 0);
      break;
    case _Up:
    case _Down:
      //ShowWnd(NULL);
      ShowTable (NULL, 0);
      break;
    case _Esc:
      Exit (_Cancel);
      break;
  }
  return FALSE;
}

int bosWAddComp (StayEvent s, StayEvent id)
{
  switch (s) {
    case _BeforeWindow:
      strcpy (Access_Ident_loc, Access_Ident);
      strcpy (Access_Comment_loc, Access_Comment);
      break;
    case _AfterWindow:
      _strupr (Access_Ident_loc);
      strcpy (Access_Ident, Access_Ident_loc);
      strcpy (Access_Comment, Access_Comment_loc);
      break;
    case 3303:
    case _Esc:
      *Access_Ident = *Access_Comment = 0;
      Exit (_Cancel);
      break;
    case 3302:
      /*if (!CheckIdent())
      {
        ::MessageBox (NULL, "Введено некоректний ідентифікатор.\nДля ідентифікації робочих станцій використовуйте MAC-адресу компютеру.", "Оболонка середовища функціонування",  MB_ICONWARNING | MB_OK);
        break;
      }*/
      Exit (_Ok);
      return TRUE;
  }
  return FALSE;
}

bool get_station_id ()
{
  StayFile f;
  char buf[20];
  char windir[256];
  GetWindowsDirectory (windir, 256);
  strcat (windir, "\\station_id");
  if (!FFind (windir)) return false;
  f = FOpen (windir, RD);
  if (!f) return false;
  if (FReadText (f, buf, sizeof (buf)) != -1) strcpy (station_id, _strupr (buf));
  FClose (f);
  return true;
}

void SetActiveStation (bool en)
{
  if (!FFind ("RES:B_ACCESS.DT")) return;
  if (Open (B_Access, RDWR | ANRDWR))
  {
    SetBegin (B_Access);
    if (GetNext (B_Access))
    {
      //if (Access_Code == 1)
      {
        SetIndex (B_Acc_List, 1);
        strcpy (Access_Ident, station_id);
        if (GetKey (B_Acc_List))
        {
          Access_Active = en ? 1 : 0;
          Modify (B_Acc_List);
          Modify (B_Access);
        }
      }
    }
    Close (B_Access);
  }
}

bool GetAccess ()
{
  if (!FFind ("RES:B_ACCESS.DT")) return TRUE;
  if (Open (B_Access, RDWR | ANRDWR))
  {
    if (Size (B_Access) == 0) return TRUE;
    SetBegin (B_Access);
    if (GetNext (B_Access))
    {
      //if (Access_Code == 0) return TRUE;
      //else if (Access_Code == 1)
      {
        SetIndex (B_Acc_List, 1);
        _strupr (station_id);
        strcpy (Access_Ident, station_id);
        if (GetKey (B_Acc_List))
        {
          Close (B_Access);
          return (Access_AccFlag != 0);
        }
      }
    }
    Close (B_Access);
  }
  return FALSE;
}

bool CheckIdent ()
{
  bool result = true;
  StrUpr (Access_Ident);
  for (int i = 0; i < 17; i++)
  {
    if (i == 2 || i == 5 || i == 8 || i == 11 || i == 14)
    {
      if (Access_Ident[i] != 45) result = false;
    }
    else
    {
      if (! ((48 <= Access_Ident[i] <= 57) || (65 <= Access_Ident[i] <= 70))) result = false;
    }
  }
  return result;
}