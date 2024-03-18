#ifndef SCREENSPACEEFFECTS_HPP
#define SCREENSPACEEFFECTS_HPP

#include <gui_generated/containers/screenSpaceEffectsContBase.hpp>

class screenSpaceEffectsCont : public screenSpaceEffectsContBase
{
public:
    screenSpaceEffectsCont();
    virtual ~screenSpaceEffectsCont() {}

    virtual void initialize();


    void setBrightness(int eff);
    void setBlinkColor(colortype color = 0xe21f); // violet lol ?
    void setAlpha(int newAlpha);

    int getAlpha();
    int getBrightness();

protected:
    int alpha;
    int brightness;
};

#endif // SCREENSPACEEFFECTS_HPP
