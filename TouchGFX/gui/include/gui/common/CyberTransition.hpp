#ifndef CYBERTRANSITION_HPP
#define CYBERTRANSITION_HPP

#include <touchgfx/Drawable.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/hal/Types.hpp>
#include <touchgfx/transitions/Transition.hpp>
#include <touchgfx/widgets/SnapshotWidget.hpp>
#include <random>

class CyberTransition : public touchgfx::Transition
{
	public:
		CyberTransition():
			Transition(),
			animationCounter(0)
		{
            blocksHorizontal = 64;
            blocksVertical = 48;
            blockWidth = (HAL::DISPLAY_WIDTH+10) / blocksHorizontal;
            blockHeight = (HAL::DISPLAY_HEIGHT+10) / blocksVertical;
            animationSteps = blocksVertical*blocksHorizontal;
		}
	    virtual void handleTickEvent()
	    {
	        Transition::handleTickEvent();
	        if (animationCounter >= animationSteps)
	        {
	            done = true;
	            Rect invRect(0, 0, 480, 272);
	            screenContainer->invalidateRect(invRect);
	            return;
	        }
	        if (animationCounter == 0 && HAL::USE_DOUBLE_BUFFERING)
	        {
	            Application::getInstance()->copyInvalidatedAreasFromTFTToClientBuffer();
	        }
	        int blocks_per_tick = rand()%80;
	        while (blocks_per_tick-- > 0 && animationCounter <= animationSteps)
	        {
	            const int index = animationCounter; //indeces[animationCounter];
	            const int16_t x = (index % blocksHorizontal) * blockWidth;
	            const int16_t y = (index / blocksHorizontal) * blockHeight;
	            Rect invRect(x, y, blockWidth, blockHeight);
	            screenContainer->invalidateRect(invRect);
	            animationCounter++;
	        }
	    }
	    virtual void tearDown()
	    {
	    }
	    virtual void init()
	    {
	        Transition::init();
	    }
	    /**
	     * Cyber transition does not require an invalidation. Invalidation
	     * is handled by the class. Do no invalidation initially.
	     */
	    virtual void invalidate()
	    {
	    }
	private:
	protected:
	    int animationSteps;
	    uint16_t blockWidth;
	    uint16_t blockHeight;
	    uint16_t blocksHorizontal;
	    uint16_t blocksVertical;
	    uint16_t animationCounter; ///< Current step in the transition animation.
};
#endif
