#ifndef LANGUAGESCREENVIEW_HPP
#define LANGUAGESCREENVIEW_HPP

#include <gui_generated/languagescreen_screen/languageScreenViewBase.hpp>
#include <gui/languagescreen_screen/languageScreenPresenter.hpp>

class languageScreenView : public languageScreenViewBase
{
public:
    languageScreenView();
    virtual ~languageScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LANGUAGESCREENVIEW_HPP
