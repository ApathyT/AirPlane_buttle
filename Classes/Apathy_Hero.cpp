#include "Apathy_Hero.h"

Apathy_Hero :: Apathy_Hero()
{
	Current_Type = UNKNOWN_HERO;
	H_Speed	     = 0;
	H_HP         = 0;
	Vec          = Point::ZERO;
}

Apathy_Hero :: ~Apathy_Hero()
{
	Current_Type = UNKNOWN_HERO;
	H_Speed	     = 0;
	H_HP         = 0;
	Vec          = Point::ZERO;
}

Apathy_Hero * Apathy_Hero :: Create(HeroType type)
{
	auto *pEn = new Apathy_Hero();

	if (pEn && pEn->Init(type))
	{
		pEn->autorelease();
		return pEn;
	}
	else
	{
		delete pEn;
		pEn = NULL;
		return NULL;
	}
}

bool Apathy_Hero :: Init(HeroType type)
{
	this->Current_Type = type;
	switch(type)
	{
	case HERO1:
		if (!Sprite::initWithSpriteFrameName("hero1.png")) 
		{
			return false;
		}
		auto aniHero1Fly = AnimationCache::getInstance()->getAnimation("aniHero1Fly");
		this->runAction(Animate::create(aniHero1Fly));
		this->H_HP = 10;
		this->H_Speed = 5;
		break;
	}
	return true;
}

void Apathy_Hero :: Move()
{
	//��Ӵ����¼�
	//�����˿�
	auto listener = EventListenerTouchOneByOne :: create();
	//�ֽⴥ���¼�
		//began
	listener->onTouchBegan = [=](Touch * t,Event * E)
	{
		log("=====began=====");
		//��Ϸ�Ƿ���ͣ
		if (Director::getInstance()->isPaused())
		{
			return false;
		}
		auto currentPos = t->getLocation();
		this->Vec = this->getPosition() - currentPos;//��ȡƫ����
		bool iscontain = this->getBoundingBox().containsPoint(currentPos);
		return iscontain;
	};	
		//move
	listener->onTouchMoved = [=](Touch * t,Event * E)
	{
		log("=====move=====");
		//�߽����
		auto nextPos = t->getLocation() + this->Vec;
		float minX = this->getContentSize().width / 2;
		float maxX = visibleSize.width - minX;
		float minY = this->getContentSize().height / 2;
		float maxY = visibleSize.height - minY;
		float x = MAX(minX,MIN(nextPos.x,maxX));
		float y = MAX(minY,MIN(nextPos.y,maxY));
		this->setPosition(x,y);
	};
	//end
	listener->onTouchEnded = [=](Touch * t,Event * E)
	{
		log("=====end=====");
		this->Vec = Point::ZERO;
	};
	//�����˿ڵķ���
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

bool Apathy_Hero :: Hit()
{
	this->H_HP--;
	if(H_HP <= 0)
	{
		//�����������
		//this->Hit_Down();
		return true;
	}
	auto aniHeroHit = Animation::create();
	switch (this->Current_Type)
	{
	case HERO1:
		aniHeroHit = AnimationCache::getInstance()->getAnimation("aniHeroHit");
		break;	
	default:
		break;
	}
	//aniHeroHit->setDelayPerUnit(0.2f);
	this->runAction(Animate::create(aniHeroHit));

	return false;
}

void Apathy_Hero :: Hit_Down()
{
	auto aniHeroDown = Animation::create();
	switch (this->Current_Type)
	{
	case HERO1:
		aniHeroDown = AnimationCache::getInstance()->getAnimation("aniHeroDown");
		break;
	default:
		break;
	}
	//aniHeroDown->setDelayPerUnit(0.1f);

	auto animate = Animate::create(aniHeroDown);

	//CallFunc�Ƕ������������ǵĴ�����Ϊ����ִ��
	//Sequence�Ƕ����������ǽ����������˳������ִ��
	
	auto callFuncN = CallFuncN::create([](Node* node) 
	{
		//Node���������������ִ����
		//���Լ��Ӹ�����ɾ�������(��ʱ��������)
		node->removeFromParentAndCleanup(true);
	});
	
	//this->stopAllActions();
	this->runAction(Sequence::create(animate,callFuncN,NULL));

	//this->runAction(Sequence :: create(Animate :: create(aniEnemyDown),RemoveSelf :: create(),nullptr));
}

int Apathy_Hero :: GetSpeed()
{
	return this->H_Speed;
}

int Apathy_Hero :: GetHP()
{
	return this->H_HP;
}