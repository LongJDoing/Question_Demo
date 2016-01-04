//
//  DataManager.cpp
//  LongJiang
//
//
//

#include "KSCCJsonRapid.h"
#include "cocos2d.h"

using namespace cocos2d;

#define BATTLE_TROOP_MAX                    3

std::string ccdictionaryToString(CCDictionary* dict){
    
    std::string str = KSCCJsonRapid::jsonStringFromDictionary(dict)->getCString();
    return str;
}

void MainLayerCSBLayer::onStageBtnClicked(cocos2d::Ref *pSender)
{
    CCArray *troops = CCArray::createWithCapacity(BATTLE_TROOP_MAX*2);
    for (int i = 0; i < BATTLE_TROOP_MAX; i++) {
        troops->addObject(CCString::createWithFormat("101"));
        troops->addObject(CCString::createWithFormat("5"));
        troops->addObject(CCString::createWithFormat("4"));
    }
    for (int i = 0; i < BATTLE_TROOP_MAX; i++) {
        for (int i = 0; i < BATTLE_TROOP_MAX; i++) {
            troops->addObject(CCString::createWithFormat("103"));
            troops->addObject(CCString::createWithFormat("2"));
            troops->addObject(CCString::createWithFormat("3"));
        }
    }
    CCDictionary *dict = CCDictionary::create();
    dict->setObject(troops, "array");

    std::string result = ccdictionaryToString(dict);
}
