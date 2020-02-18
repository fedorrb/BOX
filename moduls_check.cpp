#include <openssl/des.h>
#include "moduls_check.h"
#include "md5.h"

//Проверка контрольной суммы загружаемых модулей, для отключения закоментировать:
#ifndef _DEBUG
#define _MOD_CHECK
#endif

#define MAX_BUFF    100000

bool InitPrototype_impl ();

bool InitPrototype ()
{
#ifdef _MOD_CHECK
  return InitPrototype_impl ();
#else
  return true;
#endif
}

void TermPrototype ()
{
#ifdef _MOD_CHECK
  if (B_Content->cntopen > 0)
    Close (B_Content);
#endif
}
/*
typedef struct {
  ULONG         i[2];
  ULONG         buf[4];
  unsigned char in[64];
  unsigned char digest[16];
} MD5_CTX;

typedef
void (WINAPI* t_MD5Init) (
  MD5_CTX* context
);
t_MD5Init MD5Init;

typedef
void (WINAPI* t_MD5Update) (
  MD5_CTX* context,
  const unsigned char* input,
  unsigned int inlen
);
t_MD5Update MD5Update;

typedef
void (WINAPI* t_MD5Final) (
  MD5_CTX* context
);
t_MD5Final MD5Final;
*/
char* GetMD5 (char* FileName)
{
  FILE* fInput;
  char* StrSum;
  char tmp[16] = "";
  unsigned char bBuffer[4096], digest[16];
  //GetProcAddress;
  /*
  HMODULE hCryptdll = LoadLibraryA ("Cryptdll.dll");
  if (hCryptdll == NULL) return "ERROR";
  MD5Init = (t_MD5Init)GetProcAddress (hCryptdll, "MD5Init");
  MD5Update = (t_MD5Update)GetProcAddress (hCryptdll, "MD5Update");
  MD5Final = (t_MD5Final)GetProcAddress (hCryptdll, "MD5Final");
  */
  //Computer hash
  MD5_CTX md5;
  MD5Init (&md5);
  fInput = fopen (FileName, "rb");
  if (!fInput) {
    MsgBox (" ", "Error: Failed to open '%s'.\n\n", FileName);
    return "ERROR";
  }
  while (!feof (fInput)) {
    unsigned int nCount = fread (bBuffer, sizeof (unsigned char), 4096, fInput);
    MD5Update (&md5, bBuffer, nCount);
  }
  MD5Final (digest, &md5);
  if (fInput) fclose (fInput);
  //print hexdigest
  StrSum = (char*)malloc (300);
  memset (StrSum, 0, 300);
  for (int i = 0; i < 16; i++) {
    sprintf (tmp, "%02X", digest[i]);
    strcat (StrSum, tmp);
  }
  strcat (StrSum, "\0");
  return StrSum;
}

bool CheckSum_impl (char* module, char* path)
{
  char realCheckSum[33] = "";
  char protoPath[256]   = "";
  char realPath[256]    = "";
  char msg[256] = "";
  char module_name[80] = "";
  char *pstr;

  IWStayWin* frame = GetFrame (NULL);
  HWND hwnd = NULL;
  frame->GetWnd (&hwnd);
  SetIndex (B_Content, 1);
  strcpy(module_name, module);
  if (pstr = strchr (module_name, ' ')) *pstr = 0;
  StrUpr(module_name);
  strcpy(Cont_Name, module_name);
  Part(B_Content, 1);
  if (Size(B_Content) == 0) {
    wsprintf (msg, "Модуль не знайдено у переліку модулів системи");
    ::MessageBox (hwnd, msg, "Помилка!",  MB_ICONWARNING | MB_OK);
    Part(B_Content, 0);
    return false;
  }
  SetBegin(B_Content);
  while (GetNext(B_Content))
  {
    StrForm (protoPath, 255, "%s%s", Cont_Path, module_name);
    FullPath (protoPath, protoPath);
    FullPath (path, path);
    StrForm (realPath, 255, "%s\\%s",  path, module_name);
    StrUpr (protoPath);
    StrUpr (realPath);
    if (strcmp (protoPath, realPath) == 0)
    {
      strcpy (realCheckSum, GetMD5 (realPath));
      if (strcmp (realCheckSum, Cont_ChkSum) != 0)
      {
        wsprintf (msg, "Спроба запуску несанкціонованого модулю %s!\nХибна контрольна сума модулю!\nПодальша робота не можлива,\nзверніться до адміністратора системи!", module_name);
        ::MessageBox (hwnd, msg, "Помилка!",  MB_ICONWARNING | MB_OK);
        Part(B_Content, 0);
        return false;
      }
      else 
      {
        Part(B_Content, 0);
        return true;
      }
    }
  }
  wsprintf (msg, "Модуль не знайдено у переліку модулів системи");
  ::MessageBox (hwnd, msg, "Помилка!",  MB_ICONWARNING | MB_OK);
  Part(B_Content, 0);
  return false;
}

// \|/ ЧАСТИНА ШИФРУВАННЯ \|/
#  pragma comment ( lib, "libeay32" )
#  pragma comment ( lib, "ssleay32" )

unsigned char* Encrypt ( char* Key, char* Msg, int size)
{
  unsigned char*    Res;
  int             n = 0;
  DES_cblock      Key2;
  DES_key_schedule schedule;
  Res = (unsigned char* ) malloc ( size );
  /* Prepare the key for use with DES_cfb64_encrypt */
  memcpy ( Key2, Key, 8);
  DES_set_odd_parity ( &Key2 );
  DES_set_key_checked ( &Key2, &schedule );
  /* Encryption occurs here */
  DES_cfb64_encrypt ( ( unsigned char* ) Msg, ( unsigned char* ) Res,
                      size, &schedule, &Key2, &n, DES_ENCRYPT );
  return (Res);
}


unsigned char* Decrypt ( char* Key, char* Msg, int size)
{
  unsigned char*    Res;
  int             n = 0;
  DES_cblock      Key2;
  DES_key_schedule schedule;
  Res = (unsigned char* ) malloc ( size );
  /* Prepare the key for use with DES_cfb64_encrypt */
  memcpy ( Key2, Key, 8);
  DES_set_odd_parity ( &Key2 );
  DES_set_key_checked ( &Key2, &schedule );
  /* Decryption occurs here */
  DES_cfb64_encrypt ( ( unsigned char* ) Msg, ( unsigned char* ) Res,
                      size, &schedule, &Key2, &n, DES_DECRYPT );
  return (Res);
}

void CharToByte (char* chars, byte* bytes, unsigned int count)
{
  for (unsigned int i = 0; i < count; i++)
    bytes[i] = (byte)chars[i];
}

bool DecryptPrototypeFile (char* FileName, char* key, char* Res, unsigned long& size)
{
  char clear[MAX_BUFF];
  char* decrypted, *encrypted, ErrBuff[1024];
  FILE* fInput;
  if (!FileName) return false;
  fInput = fopen (FileName, "rb");
  if (!fInput) {
    sprintf (ErrBuff, "Error: Failed to open %s", FileName);
    MessageBox (NULL, ErrBuff, NULL, MB_ICONERROR | MB_OK);
    return false;
  }
  decrypted = (char*)malloc (sizeof (clear));
  while (!feof (fInput)) {
    unsigned int nCount = fread (clear, sizeof (unsigned char), MAX_BUFF, fInput);
    size += nCount;
    memset (decrypted, 0, MAX_BUFF);
    memcpy (decrypted, Decrypt (key, clear, nCount), nCount);
    strcat (Res, decrypted);
    //if (nCount < MAX_BUFF) strcat(Res, "\x0");
    if (decrypted) free (decrypted);
  }
  * (Res + size) = '\x0';
  if (fInput) fclose (fInput);
  return true;
}

bool InitPrototype_impl ()
{
  //StayFile f = NULL;
  char row[1024] = "";
  char path[256] = "";
  char protoType[MAX_BUFF] = "";
  char msg[256] = "";
  IWStayWin* frame = GetFrame (NULL);
  HWND hwnd = NULL;
  frame->GetWnd (&hwnd);
  Create (B_Content, RDWR | ANRDWR);
  if (!FFind ("ASOPD:prototype.ini")) {
    wsprintf (msg, "Не знайдено перелік модулів системи");
    ::MessageBox (hwnd, msg, "Помилка!",  MB_ICONWARNING | MB_OK);
    return false;
  }
  //f = FOpen("ASOPD:prototype.ini", RD|ANRDWR);
  //if(!f)
  //  return false;
  FullPath (path, "ASOPD:prototype.ini");
  unsigned long size = 0;
  if (!DecryptPrototypeFile (path, "password", protoType, size))
    return false;
  //while(FReadText(f, row, 1023))
  while (strstr (protoType, "\r\n")) {
    strncpy (row, protoType, strlen (protoType) - strlen (strstr (protoType, "\r\n")));
    row[strlen (protoType) - strlen (strstr (protoType, "\r\n"))] = '\x0';
    strcpy (protoType, strstr (protoType, "\r\n") + 2);
    char buf[1024] = "";
    strcpy (buf,  row);
    strncpy (Cont_Name, buf, strlen (buf) - strlen (strstr (buf, ";")));
    Cont_Name[strlen (buf) - strlen (strstr (buf, ";"))] = '\x0';
    strcpy (buf, strstr (buf, ";") + 1);
    strncpy (Cont_Path,  buf, strlen (buf) - strlen (strstr (buf, ";")));
    Cont_Path[strlen (buf) - strlen (strstr (buf, ";"))] = '\x0';
    strcpy (buf, strstr (buf, ";") + 1);
    strncpy (Cont_ChkSum,  buf, strlen (buf) - strlen (strstr (buf, ";")));
    Cont_ChkSum[strlen (buf) - strlen (strstr (buf, ";"))] = '\x0';
    strcpy (buf, strstr (buf, ";") + 1);
    strncpy (Cont_Version,  buf, strlen (buf) - strlen (strstr (buf, ";")));
    Cont_Version[strlen (buf) - strlen (strstr (buf, ";"))] = '\x0';
    strcpy (buf, strstr (buf, ";") + 1);
    StrUpr (Cont_Name);
    Put (B_Content);
  }
  //FClose(f);
  return true;
}

bool CheckSum (char* module, char* path)
{
#ifdef _MOD_CHECK
  return CheckSum_impl (module, path);
#else
  return true;
#endif
}