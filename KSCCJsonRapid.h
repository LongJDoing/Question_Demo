//
//  KSCCJsonRapid.h
//  DisasterGuy
//
//  Created by kisupark on 12. 11. 29..
//
//

#ifndef __DisasterGuy__KSCCJsonRapid__
#define __DisasterGuy__KSCCJsonRapid__

#include <cocos2d.h>
#include "cocos-ext.h"
#include "json/stringbuffer.h"
#include "json/writer.h"
#include "json/document.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace rapidjson;


class KSCCJsonRapid : public cocos2d::CCObject {
private:
    KSCCJsonRapid() {}
    
	static rapidjson::Value* jsonValueFromArray(cocos2d::CCArray *array, rapidjson::Document *document = NULL);
    static rapidjson::Value* jsonValueFromDictionary(cocos2d::CCDictionary *dic, rapidjson::Document *document = NULL);
    static rapidjson::Value* jsonValueFromString(cocos2d::CCString *str, rapidjson::Document *document = NULL);
	static rapidjson::Value* jsonValueFromBool(cocos2d::CCBool *boolObj, rapidjson::Document *document = NULL);

public:
    virtual ~KSCCJsonRapid();
    CREATE_FUNC(KSCCJsonRapid);
    virtual bool init();
    static cocos2d::CCString* jsonStringFromDictionary(cocos2d::CCDictionary *dic);
    static cocos2d::CCString* jsonStringFromArray(cocos2d::CCArray *arr);
    
    static cocos2d::CCObject* objectFromJsonString(const std::string &jsonStr);
    static cocos2d::CCObject* objectFromJsonString(cocos2d::CCString *jsonStr);
    static cocos2d::CCObject* objectFromJsonValue(rapidjson::Value::ConstValueIterator valueIt);
    
    // Check
    static bool isString(cocos2d::CCObject *dest);
    static bool isDictionary(cocos2d::CCObject *dest);
    static bool isArray(cocos2d::CCObject *dest);
};


#endif /* defined(__DisasterGuy__KSCCJsonRapid__) */
