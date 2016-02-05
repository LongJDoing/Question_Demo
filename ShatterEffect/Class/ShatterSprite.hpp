//
//  ShatterSprite.hpp
//  IBattleDemo
//
//  Created by jianglong on 16/2/3.
//
//

#ifndef ShatterSprite_hpp
#define ShatterSprite_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ensCommon.h"
#include "GameConfig.h"

using namespace std;
using namespace cocos2d;
namespace_ens_begin

namespace shatter{
    class ShatterAction;
    class Frag: public Sprite
    {
    public:
        int m_randomNumber;
        Frag()
        {
            m_randomNumber = -1;
        }
        bool initWithTexture(Texture2D* texture){
            Sprite::initWithTexture(texture);
            return true;
        }
    };
}


class ShatterSprite: public Sprite
{
public:
    friend class shatter::ShatterAction;
public:
    ShatterSprite();
    virtual ~ShatterSprite();
    
    static ShatterSprite* create(const string &texFileName, float gridSideLen, GameTextureResType resType);
    bool init(const string &texFileName, float gridSideLen, GameTextureResType resType);
    
protected:
    void createShatter();
    void resetShatter();
    void updateShatterAction(float time, float dt, float growSpeedOfTargetR);
    
protected:
    float m_gridSideLen; //grid side length, also frag size
    float m_initalFrageScale; //we want to make frags a litte bigger at start time.
    vector<vector<shatter::Frag*>> m_grid; //hold all the frags
    SpriteBatchNode* m_fragBatchNode;
};

namespace shatter {
    //http://user.qzone.qq.com/350479720/blog/1403318648
    class ShatterAction :public ActionInterval
    {
    public:
        ShatterAction();
        virtual ~ShatterAction();
        static ShatterAction* create(float fDuration);
        bool init(float fDuration);
        virtual void stop();
        virtual void startWithTarget(Node* pTarget);
        virtual void update(float time);
        virtual bool isDone();
        
    protected:
        float m_timeFoe;
        float m_timeCur;
        float m_growSpeedOfTargetR;
    };
}

namespace_ens_end
#endif /* ShatterSprite_hpp */
