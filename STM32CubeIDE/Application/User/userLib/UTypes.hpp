/*
 * Types.hpp
 *
 *  Created on: Feb 22, 2024
 *      Author: KaDzejoo
 */

#ifndef TYPES_HPP_
#define TYPES_HPP_
#include <stdint.h>
#include <vector>

//#include <gui/outputsscreen_screen/outputsScreenView.hpp>
//#include <touchgfx/widgets/Image.hpp>
//#include <gui/containers/functionSelect.hpp>
//#include <images/BitmapDatabase.hpp>
enum class MessageTypes
{
		messageD,
		messageQ
};
enum class MainScreenData
{
		mainScreenCam,
		mainScreenParams,
		mainScreenGauges,
		none
};
enum class User
{
		kaDzejoo,
		defaultUser,
		debugUser,
		pope,
		cptFrost
};

enum class ControllerLock
{
		fullLock,
		lightsOnly,
		noLock
};

enum class PerformancePriority
{
		gui,
		comms,
		io,
		forcedGui
};

enum TruckType
{
		none = -1,
		truck = 0,
		roadAssist = 1,
		drift = 2,
		heli = 3,
		custom1 = 4,
};

enum class batteryState
{
		charging,
		discharged,
		disconnected,
		fault,
		full,
		notFull
};
typedef struct
{
		int direction;
		int turn;
		int camx;
		int camy;
		uint8_t gearUp;
		uint8_t gearDown;
} controllerFunc;

//class vehicle
//{
//	public:
//		virtual std::string getName( ) = 0;
//		virtual std::string getDesc( )= 0;
//		virtual TruckType getType( )= 0;
//		virtual touchgfx::Image getIcon( )= 0;
//		virtual uint8_t getAdress( )= 0;
//		virtual std::vector <functionSelect&> getFunctions( )= 0;
//	private:
//		std::string name;
//		std::string desc;
//		TruckType type;
//		touchgfx::Image icon;
//		uint8_t adress;
//		std::vector <functionSelect*> functions;
//};
//class drift : public vehicle
//{
//		drift( )
//		{
//			name = "Porshe GT3";
//			desc = "vroooom";
//			type = TruckType::drift;
//			icon = BITMAP_DIRECTIONS_CAR_FILL0_WGHT100_GRAD200_OPSZ48_ID;
//			adress = 0x44;
//			//functions.push_back(&outputsScreenView::axleLifting);
//		}
//
//};
#endif /* TYPES_HPP_ */
