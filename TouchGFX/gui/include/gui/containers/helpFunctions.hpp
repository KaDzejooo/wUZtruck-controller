#ifndef HELPFUNCTIONS_HPP
#define HELPFUNCTIONS_HPP

#include <gui_generated/containers/helpFunctionsBase.hpp>

class helpFunctions : public helpFunctionsBase
{
public:
    helpFunctions();
    virtual ~helpFunctions() {}
    void setBitmap(touchgfx::Bitmap newBitmap);
    void setColor(uint8_t r,uint8_t g,uint8_t b);
    void setTitle(const char * newTitle);
    void setDesc(const char * newDesc);

    virtual void initialize();
protected:
};

#endif // HELPFUNCTIONS_HPP
