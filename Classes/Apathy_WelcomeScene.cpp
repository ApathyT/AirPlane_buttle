#include "Apathy_WelcomeScene.h"
#include "ApathyVV.h"

Scene* Apathy_WelcomeScene ::CreateScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Apathy_WelcomeScene ::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool Apathy_WelcomeScene :: init()
{
	// super init first
	if ( !Layer::init() )
	{
		return false;
	}

	//��ǰʱ����Ϊ���������
	//srand((unsigned int)time(0));

	//����plist
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot_background.plist");//����ͼƬ
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot.plist");//�ɻ�

	//==========Ԥ����������Ч===========//

	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("game_music.mp3");

	SimpleAudioEngine::getInstance()->preloadEffect("achievement.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("big_spaceship_flying.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("bullet.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("button.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("enemy1_down.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("enemy2_down.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("enemy3_down.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("game_over.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("get_bomb.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("get_double_laser.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("out_porp.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("use_bomb.mp3");

	//==========��װ����===========//

	//Ӣ��
		//���ж���
	auto aniHero1Fly = Animation :: create();
	aniHero1Fly->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero1.png"));
	aniHero1Fly->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero2.png"));
	aniHero1Fly->setDelayPerUnit(0.2f);
	aniHero1Fly->setLoops(-1);
		//���˶���
	auto aniHeroHit = Animation :: create();
	aniHeroHit->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_blowup_n1.png"));
	aniHeroHit->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero1.png"));
	aniHeroHit->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero2.png"));	
	aniHeroHit->setDelayPerUnit(0.2f);
		//���ٶ���
	auto aniHeroDown = Animation :: create();
	for(int i = 0;i < 4;i++)
	{
		auto framename = StringUtils::format("hero_blowup_n%d.png", i + 1);
		aniHeroDown->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(framename));
	}
	aniHeroDown->setDelayPerUnit(0.2f);

	//�л�
		//С�л����ٶ���
	auto aniSmallEnemyDown = Animation::create();
	for(int i = 0;i < 4;i++)
	{
		auto framename = StringUtils::format("enemy1_down%d.png", i + 1);
		aniSmallEnemyDown->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(framename));
	}
	aniSmallEnemyDown->setDelayPerUnit(0.1f);
		//�ел��ܻ�����
	auto aniMiddleEnemyHit = Animation::create();
	aniMiddleEnemyHit->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2_hit.png"));
	aniMiddleEnemyHit->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2.png"));
	aniMiddleEnemyHit->setDelayPerUnit(0.2f);
		//�ел����ٶ���
	auto aniMiddleEnemyDown = Animation::create();
	for(int i = 0;i < 4;i++)
	{
		auto framename = StringUtils::format("enemy2_down%d.png", i + 1);
		aniMiddleEnemyDown->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(framename));
	}
	aniMiddleEnemyDown->setDelayPerUnit(0.2f);
		//��л����ж���
	auto aniBigEnemeyFly = Animation::create();
	aniBigEnemeyFly->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n1.png"));
	aniBigEnemeyFly->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n2.png"));
	aniBigEnemeyFly->setDelayPerUnit(0.2f);
	aniBigEnemeyFly->setLoops(-1);
		//��л��ܻ�����
	auto aniBigEnemyHit = Animation::create();
	aniBigEnemyHit->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_hit.png"));
	aniBigEnemyHit->setDelayPerUnit(0.2f);
		//��л����ٶ���
	auto aniBigEnemyDown = Animation::create();
	for(int i = 0;i < 6;i++)
	{
		auto framename = StringUtils::format("enemy3_down%d.png", i + 1);
		aniBigEnemyDown->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(framename));
	}
	aniBigEnemyDown->setDelayPerUnit(0.2f);
		
	//loading
	auto aniLoading = Animation::create();
	for (int i = 0; i < 4; i++)
	{
		auto png = StringUtils::format("game_loading%d.png", i+1);
		aniLoading->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(png));
	}
	aniLoading->setDelayPerUnit(0.2f);
	aniLoading->setLoops(2);

	//�������뻺���
	AnimationCache::getInstance()->addAnimation(aniHero1Fly, "aniHero1Fly");
	AnimationCache::getInstance()->addAnimation(aniHeroHit, "aniHeroHit");
	AnimationCache::getInstance()->addAnimation(aniHeroDown, "aniHeroDown");
	AnimationCache::getInstance()->addAnimation(aniSmallEnemyDown, "aniSmallEnemyDown");
	AnimationCache::getInstance()->addAnimation(aniMiddleEnemyHit, "aniMiddleEnemyHit");
	AnimationCache::getInstance()->addAnimation(aniMiddleEnemyDown, "aniMiddleEnemyDown");
	AnimationCache::getInstance()->addAnimation(aniBigEnemeyFly, "aniBigEnemeyFly");
	AnimationCache::getInstance()->addAnimation(aniBigEnemyHit, "aniBigEnemyHit");
	AnimationCache::getInstance()->addAnimation(aniBigEnemyDown, "aniBigEnemyDown");
	AnimationCache::getInstance()->addAnimation(aniLoading, "aniLoading");

	
	//��ת����(Loading����)
	auto Welcome_Bg1 = Sprite::createWithSpriteFrameName("background.png");
	auto Welcome_Bg2 = Sprite::createWithSpriteFrameName("shoot_copyright.png");
	Welcome_Bg1->setPosition(visibleSize.width / 2,visibleSize.height / 2);
	Welcome_Bg2->setPosition(Welcome_Bg2->getContentSize().width / 2,Welcome_Bg2->getContentSize().height / 2);
	this->addChild(Welcome_Bg1,BackGround_Layer,Welcome_Bg1_Tag);
	this->addChild(Welcome_Bg2,BackGround_Layer + 1,Welcome_Bg2_Tag);

	auto animate = Animate::create(aniLoading);
	auto Loading = Sprite::createWithSpriteFrameName("game_loading1.png");
	Loading->setPosition(visibleSize.width / 2,visibleSize.height / 2);
	this->addChild(Loading,BackGround_Layer);
	auto callFunc = CallFunc::create([]()
	{
		//��ת�����Ĵ���
		auto scene = ApathyVV::CreateScene();
		Director::getInstance()->replaceScene(scene);
	});
	Loading->runAction(Sequence::create(animate, callFunc, NULL));
	return true;
}