#ifndef VEHICLESELECTION_HPP
#define VEHICLESELECTION_HPP

#include <gui_generated/containers/vehicleSelectionBase.hpp>
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>
#include "InputOutputModel.hpp"

class vehicleSelection : public vehicleSelectionBase
{
public:
    vehicleSelection();
    virtual ~vehicleSelection() {}

    void setIconType(touchgfx::Bitmap newBitmap);
    touchgfx::Bitmap getIconType(){return iconTypeBitmap;}
    void setAdress(uint8_t newAdress);
    void setColor(uint8_t r,uint8_t g,uint8_t b);
    void setTitle(const char* newText);
    void setDescription(const char* newText);
    void setType(TruckType truckType){typeToSet = truckType;};
    TruckType getType(){return typeToSet;};

    const char* getTitle(){return title;};
    uint8_t getAdress(){return intAdress;};
    void setActive(bool set);

    void bind(uint8_t *variable){adress = variable;};

    const touchgfx::PainterRGB888& getPainter(){return lineDecoPainter;};

    void startAnimaion();
    virtual void initialize();


protected:
    bool active = 0;
    TruckType typeToSet;
    const char * title;
    uint8_t intAdress = 0;
    uint8_t *adress;
    touchgfx::Bitmap iconTypeBitmap;
};

#endif // VEHICLESELECTION_HPP
