#pragma once

#ifndef  _COMMON_DATA_H_
#define  _COMMON_DATA_H_

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

//��Ļ�ߴ�
#define visibleSize Director::getInstance()->getVisibleSize()
//��Чȫ��
#define Audio SimpleAudioEngine::getInstance()

//===========���־===========//

#define BackGround_Layer   0
#define Label_Layer        1
#define Menu_Layer		   1
#define Button_Layer	   1
#define Airplane_Layer     2
#define Item_Layer         2
#define UI_Layer           3

//===========��ǩ==========//

//����ͼƬ
#define  Welcome_Bg1_Tag	  10
#define  Welcome_Bg2_Tag	  11
#define  BackGround1_Tag	  1
#define  BackGround2_Tag	  2
#define  Game_Over_Bg_Tag	  9
#define  Game_Restart_Bg_Tag  16
//Ӣ��
#define Hero_Tag 3

//����
#define Score_Label_Tag 4
#define Highest_Score_Lable_Tag 14

//Ѫ��
#define HP_Label_Tag 5

//ը����ť
#define MenuItemBomb_Tag 6

//ը������
#define Bomb_Count_Tag 7

//�˵�
#define Menu_Tag 8
#define Game_Over_Menu_Tag 13

//���¿�ʼ��ť
#define  menuItemRestart_Tag 12 
#define  Restart_Game_Label_Tag 15


#endif
