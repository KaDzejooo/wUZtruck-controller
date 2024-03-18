#ifndef CONTAINERTRUCK_HPP
#define CONTAINERTRUCK_HPP

#include <gui_generated/containers/containerTruckBase.hpp>
#include <BitmapDatabase.hpp>

class containerTruck : public containerTruckBase
{
public:
    containerTruck();
    virtual ~containerTruck() {}

    virtual void initialize();

    void setActive();
    void setNumber(int no)
    	{

    	//model passes number,type, of available trucks
    	//list of all configured trucks @ model
    	//list of all display parameters @ here //2-3d array
    	//	nameOfTruck, iconTruck
    	//

    	// set number of active trucks
    	// set bitmap "x" for all entries
    	// set "OK" for all available trucks
    	// set "connected" to connected truck entry
    	// sort truck on the list
    	// move to closest active/connected truck
    	// allow for selection of custom truck




    	icon.setBitmap(Bitmap(BITMAP_CLICKZONE50PX_ID));
    	Unicode::snprintf(textTruckNameBuffer, TEXTTRUCKNAME_SIZE,"%d",no);
    	iconType.setBitmap(Bitmap(BITMAP_CLICKZONE50PX_ID));
    	imageLine.setBitmap(Bitmap(BITMAP_LINE23050_ID));

    	if (no==1){
    		Unicode::snprintf(textTruckNameBuffer, TEXTTRUCKNAME_SIZE,"SCANIA");

    		iconType.setBitmap(Bitmap(BITMAP_SCANIA5050_ID));
    		imageLine.setBitmap(Bitmap(BITMAP_CLICKZONE50PX_ID));
    	}
    	if (no==2){
    		Unicode::snprintf(textTruckNameBuffer, TEXTTRUCKNAME_SIZE,"MAN");

    		iconType.setBitmap(Bitmap(BITMAP_MAN5050_ID));
    		imageLine.setBitmap(Bitmap(BITMAP_CLICKZONE50PX_ID));
    	}


       }


protected:



};

#endif // CONTAINERTRUCK_HPP
