#pragma once

#include "ui/components/Instance.h"
#include <vector>

class Page
{
private:
    std::vector<Instance *> instances;
    bool isVisible = false;

public:
    virtual void setup() = 0;
    void draw();
    void addInstance(Instance *instance);
    void setVisible(bool visible);
};