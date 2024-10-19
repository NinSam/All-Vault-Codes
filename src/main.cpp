#include <Geode/Geode.hpp>
#include <Geode/modify/SecretLayer2.hpp>
#include <Geode/modify/SecretLayer4.hpp>

using namespace geode::prelude;

class CodeLayer : public FLAlertLayer
{

	public:

	static CodeLayer* create(){
		auto ret = new CodeLayer;
		if (ret && ret->init()){
			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}

	bool init(){
		if (!this->initWithColor({0,0,0,0}))
		return false;

		geode::cocos::handleTouchPriority(this);
		registerWithTouchDispatcher();
		m_noElasticity = true;

		auto menu = CCMenu::create();
		auto layer = CCLayer::create();

		auto winSize = CCDirector::get()->getWinSize();
		auto bg = CCScale9Sprite::create("GJ_square01.png");
	    bg->setPosition(winSize / 2);
		bg->setContentSize({500.0f, 280.0f});
		layer->addChild(bg);
		bg->setZOrder(-1);

		auto spr = CCSprite::create("bg_new.png"_spr);
	    spr->setPosition(winSize / 2);
		spr->setScale(5.0f);
		layer->addChild(spr);
		spr->setZOrder(-2);

		auto closebutton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
			this,
			menu_selector(CodeLayer::CloseLayer)
		);
		menu->addChild(closebutton);
		closebutton->setID("my-button"_spr);
		closebutton->setPosition({-245.0f, 133.0f});

		auto goldtext = CCLabelBMFont::create("All Vault Codes", "goldFont.fnt");
		goldtext->setPosition({284.0f, 279.0f});
		layer->addChild(goldtext);
		goldtext->setZOrder(1);

		auto goldtext2 = CCLabelBMFont::create("The Vault", "goldFont.fnt");
		goldtext2->setPosition({284.0f, 235.0f});
		goldtext2->setContentSize({129.0f, -200.0f});
		goldtext2->setScale(0.5f);
		layer->addChild(goldtext2);
		goldtext2->setZOrder(1);

		auto goldtext3 = CCLabelBMFont::create("The Vault Of Secrets", "goldFont.fnt");
		goldtext3->setPosition({284.0f, 177.0f});
		goldtext3->setContentSize({129.0f, -200.0f});
		goldtext3->setScale(0.5f);
		layer->addChild(goldtext3);
		goldtext3->setZOrder(1);

		auto goldtext4 = CCLabelBMFont::create("Chamber Of Time", "goldFont.fnt");
		goldtext4->setPosition({284.0f, 88.0f});
		goldtext4->setContentSize({129.0f, -200.0f});
		goldtext4->setScale(0.5f);
		layer->addChild(goldtext4);
		goldtext4->setZOrder(1);
	

		auto thevaultcodes = CCLabelBMFont::create("Lenny, BlockBite, Robotop, Sparky, Spooky, Ahead, Mule, Neverending, Gandalfpotter, ''16, 30, 32, 46, 84'', Your Player Name, Final Boss", "chatFont.fnt");
		thevaultcodes->setPosition({284.0f, 205.0f});
		thevaultcodes->setScale(0.5f);
		layer->addChild(thevaultcodes);
		thevaultcodes->setZOrder(1);

		auto thevaultofsecretscodes = CCLabelBMFont::create("The challenge, Octocube, Seven, Brainpower, Thechickenisonfire, Gimmiethecolor, (Your number stars), Cod3breaker (3584568), D4ahg30me7ry", "chatFont.fnt");
		thevaultofsecretscodes->setPosition({284.0f, 142.0f});
		thevaultofsecretscodes->setScale(0.5f);
		layer->addChild(thevaultofsecretscodes);
		thevaultofsecretscodes->setZOrder(1);

		auto Glubfub = CCLabelBMFont::create("Thechickenisready, Glubfub (use code Sparky FIRST in the vault keep clicking when green text appears then go back to the vault of secrets)", "chatFont.fnt");
		Glubfub->setPosition({284.0f, 120.0f});
		Glubfub->setScale(0.5f);
		layer->addChild(Glubfub);
		Glubfub->setZOrder(1);


		auto chamberoftimecodes = CCLabelBMFont::create("Volcano, Darkness, Silence, River, Hunger, Backontrack, Givemehelper", "chatFont.fnt");
		chamberoftimecodes->setPosition({284.0f, 57.0f});
		chamberoftimecodes->setScale(0.5f);
		layer->addChild(chamberoftimecodes);
		chamberoftimecodes->setZOrder(1);
		

		this->setKeypadEnabled(true);
		this->setTouchEnabled(true);

		layer->addChild(menu);
		addChild(layer);


		return true;
	}
	void CloseLayer(CCObject*){
		setTouchEnabled(false);
		removeFromParentAndCleanup(true);
	}

};
class $modify(MySecretLayer2, SecretLayer2) {
	bool init() {
		if (!SecretLayer2::init()) 
			return false;
		
		  auto winSize = CCDirector::sharedDirector()->getWinSize();

		log::debug("Hello from mySecretLayer2::init hook! This layer has {} children.", this->getChildrenCount());

		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_infoBtn_001.png"),
			this,
			menu_selector(MySecretLayer2::onMyButton)
		);

		auto menu = CCMenu::create();
		auto layer = CCLayer::create();

		layer->addChild(menu);
		this->addChild(layer);
		menu->addChild(myButton);
		menu->setPosition({41.0f, 32.0f});

		myButton->setID("my-button"_spr);

		menu->updateLayout();

		return true;
	}

	void onMyButton(CCObject*) {
		CodeLayer::create()->show();	
	}
};
class $modify(MySecretLayer4, SecretLayer4) {
	bool init() {
		if (!SecretLayer4::init()) 
			return false;
	
		  auto winSize = CCDirector::sharedDirector()->getWinSize();

		log::debug("Hello from mySecretLayer4::init hook! This layer has {} children.", this->getChildrenCount());

		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_infoBtn_001.png"),
			this,
			menu_selector(MySecretLayer4::onMyButton)
		);

		auto menu = CCMenu::create();
		auto layer = CCLayer::create();

		layer->addChild(menu);
		this->addChild(layer);
		menu->addChild(myButton);
		menu->setPosition({41.0f, 32.0f});

		myButton->setID("my-button"_spr);

		menu->updateLayout();

		return true;
	}

	void onMyButton(CCObject*) {
		CodeLayer::create()->show();	
	}
};
/* bool init doesn't work for SecretLayer for now
class $modify(MySecretLayer, SecretLayer) {
	bool init() {
		if (!SecretLayer::init()) 
			return false;
	
		  auto winSize = CCDirector::sharedDirector()->getWinSize();

		log::debug("Hello from mySecretLayer4::init hook! This layer has {} children.", this->getChildrenCount());

		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_infoBtn_001.png"),
			this,
			menu_selector(MySecretLayer::onMyButton)
		);

		auto menu = CCMenu::create();
		auto layer = CCLayer::create();

		layer->addChild(menu);
		this->addChild(layer);
		menu->addChild(myButton);
		menu->setPosition({41.0f, 32.0f});

		myButton->setID("my-button"_spr);

		menu->updateLayout();

		return true;
	}

	void onMyButton(CCObject*) {
		CodeLayer::create()->show();	
	}
};
*/