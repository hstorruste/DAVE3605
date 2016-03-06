#ifndef BOOSTER
#define BOOSTER

#include <vector>
#include <string>
#include "utils/settings.hpp"
/**Abstract class*/
class Booster {
    std::string boostername;
    int boostTime;
    std::vector<float> attrib;
public:
    /** Do all the changes to the needs and return true.
     * Returns false when boostTime has elapsed*/
    Booster(std::string boostername_);
    Booster(std::string boostername_, int boostTime_,std::vector<float> &attrib_);
    Booster(const Booster &boo);
    Booster& operator =(const Booster &boo);
    /** Oppdater tiden */
    int getBoostTime();
    int decreaseBoostTime(int t_);

    void setAttrib(Settings::Attributes attr, float val);
    void reset();
    std::vector<float> getAttribs();
    /** getMetoder */
    std::string getTitle();
    float getHungerVal();
    float getSleepVal();
    float getInspirationVal();
    void setHunger(float hunger_);
    void setSleep(float sleep_);
    void setInspiration(float inspiration_);
    void setDuration(int boostTime_);
    /** toString method */
    std::string toStr();
    /** Virtual destructor */
    virtual ~Booster();
};


#endif // BOOSTER

