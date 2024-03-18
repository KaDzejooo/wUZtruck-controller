#ifndef INCREMENTSETTING_HPP
#define INCREMENTSETTING_HPP

#include <gui_generated/containers/incrementSettingBase.hpp>
#include <string>
#include <vector>


class incrementSetting : public incrementSettingBase
{
public:
    incrementSetting();
    virtual ~incrementSetting() {}

    virtual void initialize();


    int getValue();
    void setValue(int newVal);
    void setMaxVal(int newVal);
    void setMinVal(int newVal);
    void setVariableBottomText();
    void bind(uint8_t* newValue);

    void setText(const char* newText);
    void setText2(const char* newText);
    void setIcon(touchgfx::Bitmap icon);
    void setColor(uint8_t r,uint8_t g, uint8_t b);

    void setIncrementText(std::vector<std::string>newTexts);

    touchgfx::Callback <incrementSetting, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
protected:
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
   std::vector<std::string>texts;
    bool variableBottomText = 0;
    uint8_t *selectedValue = 0;

    uint16_t value=5;
    uint16_t maxVal=255;
    uint16_t minVal=0;

};

#endif // INCREMENTSETTING_HPP
