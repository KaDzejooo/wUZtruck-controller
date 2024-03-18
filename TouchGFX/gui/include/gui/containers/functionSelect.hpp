#ifndef FUNCTIONSELECT_HPP
#define FUNCTIONSELECT_HPP

#include <gui_generated/containers/functionSelectBase.hpp>
#include "UTypes.hpp"
#include <vector>
enum class funcType
{
		toggle = 0,
		upDown = 1
};
enum class upDown
{
		up = 0,
		down = 1,
		none = 2
};

class functionSelect : public functionSelectBase
{
	public:
		functionSelect( );
		virtual ~functionSelect( )
		{
		}

		void setType(funcType newType);
		void setIcon(touchgfx::Bitmap newIcon);
		void forceState(bool newState);
		void forceState( );
		void setText(const char *newText);
		void setTextSec(const char *newText);
		void setColor(uint8_t newR, uint8_t newG, uint8_t newB);
		void resetUpDown( );


		void addAllowedVehicle(TruckType data){vehicle.push_back(data);}
		std::vector<TruckType> getAllowedVehicleList(){return vehicle;}

		void setStateValue(bool *variable);
		void setUpValue(bool *variable);
		void setDownValue(bool *variable);

		bool getState( )
		{
			return state;
		}
		bool getUp( )
		{
			return up;
		}
		bool getDown( )
		{
			return down;
		}

		void setUpDownIcon(upDown newState);
		virtual void initialize( );
		void setStateIcon(bool stateIcon);
		void setStateIconDef();

	protected:
		void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer &src);
		touchgfx::Callback <functionSelect, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

		funcType type;
		std::vector<TruckType> vehicle;

		bool *stateVal;
		bool *upVal;
		bool *downVal;

		bool state = 0;
		bool up = 0;
		bool down = 0;
};

#endif // FUNCTIONSELECT_HPP
