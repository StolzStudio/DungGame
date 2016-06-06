
#ifndef unit_hpp
#define unit_hpp

#include <stdio.h>
#include "point.hpp"

#define SKIN_KNIGHT 'K'
#define SKIN_ZOMBIE 'Z'


class Unit {
protected:
    int   hp;
    int   dmg;
    Point position;
    char  skin;
public:
    Unit(int aHp, int aDmg, char aSkin, Point aPos): hp(aHp), dmg(aDmg), skin(aSkin), position(aPos) {};
    
    virtual int  HP();
    virtual void HP(int aHP);
    
    virtual int  DMG();
    virtual void DMG(int aDMG);
    
    virtual Point POS();
    virtual void  POS(Point aPOS);
    
    virtual char  SKIN();
    virtual void  SKIN(char aSKIN);
    
    virtual void  move(Point aUserWay);
};

class Knight: public Unit {
protected:
    int level;
    int experience;
    int needExperienceToNextLevel;
public:
    Knight(Point aPos): Unit(20, 15, SKIN_KNIGHT, aPos), level(1), experience(0), needExperienceToNextLevel(10) {};
    
    void EXP(int aEXP);
    int  EXP();
    
    int  NEEDEXP();

};

class Mob: public Unit {
protected:
    int countEXP;
public:
    Mob(Point aPos): Unit(10, 2, SKIN_ZOMBIE, aPos), countEXP(10) {};
};

#endif
