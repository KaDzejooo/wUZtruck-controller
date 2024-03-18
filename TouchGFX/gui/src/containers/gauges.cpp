#include <gui/containers/gauges.hpp>

gauges::gauges( )
{
	textCarBattery.setWildcard(textCarBatteryBuffer);
	textBattery.setWildcard(textBatteryBuffer);
}

void gauges::initialize( )
{
	gaugesBase::initialize( );
	iconGearUp.setVisible(0);
	iconGearDown.setVisible(0);
	;
	iconTrailerConnected.setAlpha(40);
	iconSpeedLim.setAlpha(40);
}
void gauges::setGaugeL(int value)
{
	gaugeValueL = value;

	static int count = 0;
	if (count == 120)
	{

		circleSpeedBcg.invalidate( );
		circleMarkR.invalidate( );
		invalidateContent();
		count = 0;
	}
	count++;

	//gaugeSpeed.updateValue(value,5);


	int setVal = map(value, 0, 100, 91.6, -91.6);
	gaugeLCircle.setArc(setVal, -91.6);
	gaugeLCircle.invalidate( );

}
void gauges::setGaugeR(int value)
{
	gaugeValueR = value;

	static int count = 0;
	if (count == 120)
	{

		circleRPMBcg.invalidate( );
		circleMark2.invalidate( );
		count = 0;
		invalidateContent();
	}
	count++;

	int setVal = map(value, 0, 100, 91.6, -91.6);
	gaugeRCircle.setArc(setVal, -91.6);
	gaugeRCircle.invalidate( );

}

void gauges::gearUp(bool state)
{
	iconGearUp.setVisible(state);
}
void gauges::gearDown(bool state)
{
	iconGearDown.setVisible(state);
	;
}

void gauges::setBatteryController(int value)
{

	Unicode::snprintf(textBatteryBuffer, TEXTBATTERY_SIZE, "%d", value);
	int setVal = map(value, 0, 100, 245, 115);
	circleBatteryJoy.setArc(setVal, 245);
	textBattery.invalidate( );
	circleBatteryJoy.invalidate( );

}
void gauges::setBatteryVehicle(int value)
{
	Unicode::snprintf(textCarBatteryBuffer, TEXTCARBATTERY_SIZE, "%d", value);
	int setVal = map(value, 0, 100, 245, 115);
	circleVehicleBattery.setArc(setVal, 245);
	circleVehicleBattery.invalidate( );
	textCarBattery.invalidate( );
}

void gauges::setLimmiter(bool state)
{
	if (state)
	{
		iconSpeedLim.setAlpha(255);
	}
	else
	{
		iconSpeedLim.setAlpha(40);
	}

}
void gauges::setTrailerConnect(bool state)
{
	if (state)
	{
		iconTrailerConnected.setAlpha(255);
	}
	else
	{
		iconTrailerConnected.setAlpha(40);
	}

}


int gauges::map(int x, int in_min, int in_max, int out_min, int out_max)
{
	return ( x - in_min ) * ( out_max - out_min ) / ( in_max - in_min ) + out_min;
}
void gauges::setGear(uint8_t gear)
{
	Unicode::snprintf(textGearBuffer,TEXTGEAR_SIZE,"%d",gear);
	textGear.invalidate();
}
