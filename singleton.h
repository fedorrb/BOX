#ifndef _SINGLETON
#define _SINGLETON
//����� ������������ � ������������ ���������
//��� �������� ���������� ����������
#include <string>
class Singleton;  // ����������� ����������
  
class SingletonDestroyer
{
  private:
    Singleton* p_instance;
  public:    
    ~SingletonDestroyer();
    void initialize( Singleton* p );
};
  
class Singleton
{
  private:
    static Singleton* p_instance;
    static SingletonDestroyer destroyer;
  protected: 
    Singleton() { }
    Singleton( const Singleton& );
    Singleton& operator=( Singleton& );
   ~Singleton() { }
    friend class SingletonDestroyer;
  public:
    static Singleton& getInstance();    
    //���������� ���������� ����������
    char params [816];
	char path[_MAX_PATH];
	char logFile[_MAX_PATH];
	char pathWithArgs[1080]; //_MAX_PATH + 816
};
#endif