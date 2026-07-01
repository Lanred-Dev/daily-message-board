#pragma once

#include "classes/BootStatus.h"
#include "ui/components/Instance.h"
#include <vector>
#include "ui/pages/Message.h"
#include "ui/Navbar.h"

namespace UI
{
    inline MessagePage messagePage;
    inline Navbar navbar;
    inline std::vector<Page *> pages = {&messagePage};
    inline std::vector<Instance *> instances;
    inline int currentPageIndex = 0;

    BootStatus setup();
    void addInstance(Instance *instance);
    void draw();
    void setCurrentPage(int pageIndex);
}