#ifndef POPUPINFO_HPP
#define POPUPINFO_HPP

#include <gui_generated/containers/popupInfoBase.hpp>

class popupInfo : public popupInfoBase
{
public:
    popupInfo();
    virtual ~popupInfo() {}

    virtual void initialize();
protected:
};

#endif // POPUPINFO_HPP
