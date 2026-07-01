#include "UI.h"
#include <algorithm>
#include "core/Display.h"

BootStatus UI::setup()
{
    for (Page *page : pages)
        page->setup();

    navbar.setup();
    setCurrentPage(0);

    return {"UI initialized successfully.", true};
}

void UI::draw()
{
    for (Instance *instance : instances)
    {
        if (!instance->isVisible)
            continue;

        instance->draw();
    }
}

void UI::addInstance(Instance *instance)
{
    instances.push_back(instance);
    std::sort(instances.begin(), instances.end(), [](Instance *a, Instance *b)
              { return a->zIndex < b->zIndex; });
}

void UI::setCurrentPage(int pageIndex)
{
    pages[currentPageIndex]->setVisible(false);
    currentPageIndex = pageIndex;
    pages[currentPageIndex]->setVisible(true);
}