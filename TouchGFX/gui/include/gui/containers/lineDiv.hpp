#ifndef LINEDIV_HPP
#define LINEDIV_HPP

#include <gui_generated/containers/lineDivBase.hpp>
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>
class lineDiv : public lineDivBase
{
public:
    lineDiv();
    virtual ~lineDiv() {}

    virtual void initialize();
    void setText(const char * newTitle)
    {
    	Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, newTitle);
    	textArea.resizeToCurrentText();
    	textArea.invalidate();

    	line.setStart((float)textArea.getWidth()+6, 7.5f);
    	line.invalidate();
    }
    void setColor(uint8_t r,uint8_t g,uint8_t b){
    	linePainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b));
    	textArea.setColor(touchgfx::Color::getColorFromRGB(r, g, b));
    	textArea.invalidate();
    }
    void setColor(touchgfx::colortype color){
    	linePainter.setColor(color);
    	textArea.setColor(color);
    	textArea.invalidate();
    }
//    PainterRGB888* getPainter(){
//    	return linePainter;
//    }


protected:
};

#endif // LINEDIV_HPP
