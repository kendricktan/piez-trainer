#include <Windows.h>
#include <WinInet.h>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#pragma comment (lib, "WinInet.lib")
#pragma comment(lib, "urlmon.lib")
using namespace std;

//Acts as a medium with Forms that have used this functions with Main.cpp

int GetCharHp();
int GetCharMp();
double GetExp();
int GetCharX();
int GetCharY();
int GetAnimationDelay();
int GetAnimationToggle();
int GetMouseX();
int GetMouseY();
int GetMapId();
int GetAttackCount();
int GetPeopleCount();
int GetMobCount();
int GetBreathCount();
int GetItemCount();
int GetLeftWall();
int GetRightWall();
int GetTopWall();
int GetBottomWall();
int GetCurrentWorld();
int GetCurrentChannel();
void NoBreath();
void MorphHack();
void FLACC();
void iEatSteroids();
void WallVacHookCharXY();
void WallVacCustomXY();
void SSMouseFly();
void OffMap();
void B4OffMap();
void RefreshMap();
void KamiVac();
void B4KamiVac();
void KamiLoot();
void B4KamiLoot();
void SuperTubi();
void AutoRefreshMap();
void AfterAutoRefreshMap();
void NoPlayerKb();
void vHotKeys();
void AutoTimedCC();
void AutoAttackCC();
void AutoPeopleCC();
__inline void Teleport(int CharX, int CharY);
char *convertStringToChar(const string &str);
