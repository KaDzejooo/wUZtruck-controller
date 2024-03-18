#include <gui/common/FrontendApplication.hpp>
#include <gui/mainscreen_screen/mainScreenView.hpp>
#include <gui/mainscreen_screen/mainScreenPresenter.hpp>
#include <gui/common/CyberTransition.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/lcd/LCD24DebugPrinter.hpp>
#include <touchgfx/Bitmap.hpp>
#include "SetupSettings.hpp"
#include "IntegrityManager.hpp"

extern ControllerSettings settingsM;
LCD24DebugPrinter lcd24DebugPrinter;
uint16_t cache[256*144*2];


FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{


#ifndef DISABLE_DYNAMIC_BITMAP_MEMORY_ALLOCATION
//    uint16_t* const cacheStartAddr = (uint16_t*)0x08000000;
//    const uint32_t cacheSize = 256*144*2; // 256x144x2 (16 bit img) image + 500
//    Bitmap::setCache(cacheStartAddr, cacheSize+500, 1);

     Bitmap::setCache(cache, sizeof(cache),1);
   //  Bitmap::dynamicBitmapCreate(100,100,Bitmap::BW);

#endif

#ifdef ENABLE_DEBUG_PRINTER

    lcd24DebugPrinter.setPosition(5, 5, 475, 266);
    lcd24DebugPrinter.setScale(1);
    lcd24DebugPrinter.setColor(touchgfx::Color::getColorFromRGB(0,255,0)); //white
    Application::setDebugPrinter(&lcd24DebugPrinter);

#endif
}

void FrontendApplication::gotomainScreenScreenCyberTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplication>(this, &FrontendApplication::gotomainScreenScreenCyberTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotomainScreenScreenCyberTransitionImpl()
{
    touchgfx::makeTransition<mainScreenView, mainScreenPresenter, CyberTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
