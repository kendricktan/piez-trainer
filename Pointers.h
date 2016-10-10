#include <Windows.h>

//Defines all the pointers here for easier updating

//Pointers

//Char Base 
const unsigned long ulCharRelated = 0x011698E8; // A1 ? ? ? ? 85 ? 74 ? 8D ? ? ? ? ? 52 8D ? ? ? ? ? E8
const unsigned long ulAnimation = 0x5F4; // 8b 88 ? ? ? ? 83 e1 fe 83 f9 12 0f 84
const unsigned long ulAnimationFrame = ulAnimation + 0x8;
const unsigned long ulAnimationDelay = ulAnimation + 0xC;
const unsigned long ulAnimationDelay2 = ulAnimation + 0x10;
const unsigned long ulAnimationToggle = ulAnimation + 0x18;
const unsigned long ulAttackCount = 0x4264; // 89 ? ? ? 00 00 C7 ? ? ? 00 00 ? 00 00 00 89 ? ? ? 00 00 89 ? ? ? 00 00 89 ? ? ? 00 00 C7 ? ? ? 00 00 ? 00 00 00 89 ? ? ? 00 00 8D
const unsigned long ulBreathCount = 0x05F0; // 83 B8 ? ? ? ? 00 7E ? 6A 00 6A 00 6A 00 6A 00
const unsigned long ulMorphOffset = 0x0584; // 8B 81 ?? ?? ?? ?? 56 8D B1 ?? ?? ?? ?? 85 C0 74 ?? 50 E8
const unsigned long ulCharFacingOffset = 0x1B80;
const unsigned long ulpIDOffset  = 0x20E0;
const unsigned long ulCharItemX = 0x4D6C; // 89 8E ? ? 00 00 8b 50 ? 8b 06
const unsigned long ulCharItemY = ulCharItemX + 0x4;
const unsigned long ulTeleOffset = 0x4048; // 83 BE ? ? 00 00 00 89 44 ? ? 0F 84 // TeleX = Teleoffset + 8 , TeleY = Teleoffset + 12

//Map
const unsigned long ulMapBase = 0x01169FBC; // 8B ? ? ? ? ? E8 ? ? ? ? E9 ? ? ? ? 8B ? ? ? ? ? 6A 00 E8 ? ? ? ? 8B
const unsigned long ulMapOffset = 0x0D28; // 8B ? ? ? ? ? 50 8D ? ? ? 51 8B ? ? ? ? ? C6 ? ? ? ? ? ? ? E8

//Stat 
const unsigned long ulStatBase = 0x01169BC4; // 8B ? ? ? ? ? 56 E8 ? ? ? ? C7 ? ? ? FF FF FF FF 3B ? 74 ? 83 ? ? 56 E8
const unsigned long ulHpOffset = 0x1848; // 89 86 ? ? ? ? 89 86 ? ? ? ? FF 15 ? ? ? ? 8D
const unsigned long ulMpOffset = 0x184C; // 89 86 ? ? ? ? FF 15 ? ? ? ? 8D 8E ? ? ? ? 89
const unsigned long ulExpOffset = 0x1788; // 89 ? ? ? 00 00 E8 ? ? ? FF 8D ? ? ? 00 00 33 C9 89 ? ? ? 00 00 E8 ? ? ? FF 89 ? ? ? 00 00 8D ? ? ? 00 00 BB

//Mouse 
const unsigned long ulMouseBase = 0x01169D68; // 8B 0D ? ? ? ? 74 ? 83 B9 ? ? ? ? 00 74 ? C7 44 24
const unsigned long ulMouseLocation = 0x978; // 8B B1 ? ? ? ? 85 F6 75 ? 68 ? ? ? ? E8 ? ? ? 00 8B 4C 24 ? 8B 06 8B 90 ? ? ? ? F7 D9
const unsigned long ulMouseXOffset = 0x8C; // 8B 88 ? ? ? ? 6A FF 57 83 C5 FE 55
const unsigned long ulMouseYOffset = ulMouseXOffset + 0x04;
const unsigned long ulMouseAnimation = 0x9C4; // 83 B9 ? ? ? 00 00 74 ? C7 44 24

//People 
const unsigned long ulPeopleBase = 0x011698E0; // 8B 0D ? ? ? ? 50 E8 ? ? ? 00 8B F8 85 FF 0F 84 ? ? ? ? 39 AF ? ? ? ? 0F 85
const unsigned long ulPeopleOffset = 0x18; // Fixed Offset ... for now 

//Mob Structure 
const unsigned long ulMobBase = 0x011698E4; // 8B ? ? ? ? ? 50 E8 ? ? ? ? 8B ? 85 ? 74 ? 8B ? ? 8B ? ? 8D
const unsigned long ulMobOffset1 = 0x28;
const unsigned long ulMobOffset2 = 0x4;
const unsigned long ulMobOffset3 = 0x10C;
const unsigned long ulMobOffset4 = 0x24;
const unsigned long ulMobXOffset = 0x58; 
const unsigned long ulMobYOffset = 0x5C; 
const unsigned long ulMobCountOffset = 0x10; // Fixed Offset ... for now

//Item 
const unsigned long ulItemBase = 0x0116C184; // 89 ? ? ? ? ? EB ? 89 ? ? ? ? ? 8D ? ? C7 ? ? ? ? ? 89
const unsigned long ulItemOffset = 0x14;// Fixed Offset ... for now

//Wall 
const unsigned long ulWallBase = 0x01169820; // 8B ? ? ? ? ? 52 C6 ? ? ? E8 ? ? ? ? 8B ? ? 89 ? ? 85
const unsigned long ulLeftWallOffset = 0x1C; // 8B 50 ? 83 C0 ? 81 C1 ? ? 00 00 89 11
const unsigned long ulRightWallOffset = ulLeftWallOffset + 0x8;
const unsigned long ulTopWallOffset = ulLeftWallOffset + 0x4;
const unsigned long ulBottomWallOffset = ulLeftWallOffset + 0xC;

//Server 
const unsigned long ulServerBase = 0x01165358; // A1 ? ? ? ? 8B ? C7 ? ? ? 00 00 00 00 00 00 E8 ? ? ? ? 8D
const unsigned long ulWorldOffset = 0x2070; // 8B ? ? ? 00 00 89 ? ? ? 00 00 8B ? ? ? 00 00 8B ? ? ? 00 00 51 8B
const unsigned long ulChannelOffset = ulWorldOffset + 0x04;
const unsigned long ulTubiOffset = ulWorldOffset + 0x40;

//----------------------------------------