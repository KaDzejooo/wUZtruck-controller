#ifndef GAUGES_HPP
#define GAUGES_HPP

#include <gui_generated/containers/gaugesBase.hpp>

class gauges : public gaugesBase
{
public:
    gauges();
    virtual ~gauges() {};


    void setGaugeL(int value);
    void setGaugeR(int value);

    void gearUp(bool state);
    void gearDown(bool state);

    void setBatteryController(int value);
    void setBatteryVehicle(int value);

    void setLimmiter(bool state);
    void setTrailerConnect(bool state);

    int getValueR(){return gaugeValueR;}
    int getValueL(){return gaugeValueL;}
    void setGear(uint8_t gear);


    virtual void initialize();
protected:
    int map(int x, int in_min, int in_max, int out_min, int out_max);
    int angleEnd = 245;
	int angleStart = 115;

	int gaugeValueL;
	int gaugeValueR;
};

#endif // GAUGES_HPP
