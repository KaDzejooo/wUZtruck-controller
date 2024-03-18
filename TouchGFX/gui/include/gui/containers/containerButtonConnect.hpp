#ifndef CONTAINERBUTTONCONNECT_HPP
#define CONTAINERBUTTONCONNECT_HPP

#include <gui_generated/containers/containerButtonConnectBase.hpp>
#include <touchgfx/Bitmap.hpp>
#include "InputOutputModel.hpp"
#include <string>


class containerButtonConnect : public containerButtonConnectBase
{
public:
    containerButtonConnect();
    virtual ~containerButtonConnect() {}

    virtual void initialize();
    /*
     * Sets icon according to TruckType
     */
    virtual void setButtonIcon(TruckType type);
    /*
     * Sets battery icon
     */
    virtual void setBatteryIcon(int battery);
    /*
     * Sets status icon to any 24dp specified in parameter
     */
    virtual void setStatusIcon(const Bitmap& newIcon);
    /*
     * Sets connection status (signal strength)
     */
    virtual void setConnectionStatus(int connection);
    /*
     * Sets name to display on widget
     */
    virtual void setName(const char* newName);
    /*
     * Variant of setName(const char* newName), taking std::string as parameter
     */
    virtual void setName(std::string newName);
    /*
     * Sets actual widget as Selected and renders outline
     */
    virtual void setSelected();
    /*
     * Sets actual widget as Deselected and Derenders outline
     */
    virtual void setDeselected();
    /*
     * Gets selected
     */
    virtual bool getSelected();



    virtual void setAdress(int adress);
    virtual int getAdress();


protected:
    int adressToConnect;
    bool selected = 0;


};

#endif // CONTAINERBUTTONCONNECT_HPP
