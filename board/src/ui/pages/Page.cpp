#include "Page.h"
#include <algorithm>

void Page::draw()
{
    for (Instance *instance : instances)
    {
        if (!instance->isVisible)
            continue;

        instance->draw();
    }
}

void Page::addInstance(Instance *instance)
{
    instances.push_back(instance);
    std::sort(instances.begin(), instances.end(), [](Instance *a, Instance *b)
              { return a->zIndex < b->zIndex; });
}

void Page::setVisible(bool visible)
{
    isVisible = visible;

    for (Instance *instance : instances)
    {
        instance->isVisible = visible;
    }
}