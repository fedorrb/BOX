#ifndef _SINGLETON
#define _SINGLETON
// ласс существующий в единственном экземл€ре
//дл€ хранени€ глобальных переменных
#include <string>
class Singleton;  // опережающее объ€вление
  
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
    //объ€влени€ глобальных переменных
    char params [816];
	char path[_MAX_PATH];
	char logFile[_MAX_PATH];
	char pathWithArgs[1080]; //_MAX_PATH + 816
};
#endif