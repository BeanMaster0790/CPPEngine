#include <algorithm>
#include "Props/WorldProp.h"
#include "Addons/Addon.h"

void WorldProp::update()
{
    Prop::update();

    for(auto& addon : _addons)
    {
        if(!addon->Parent)
        {
            addon->Parent = this;
        }

        addon->update();
    }
}

void WorldProp::draw()
{
    Prop::draw();

    for(auto& addon : _addons)
    {
        if(!addon->Parent)
        {
            addon->Parent = this;
        }

        addon->draw();
    }
}

void WorldProp::lateUpdate()
{
    Prop::lateUpdate();

    for(auto& addon : _addons)
    {
        if(!addon->Parent)
        {
            addon->Parent = this;
        }

        addon->lateUpdate();
    }

    _addons.erase(std::remove_if(_addons.begin(), _addons.end(), [](const auto& addon){return addon->ToRemove;}), _addons.end());
}

void WorldProp::removeFromGame()
{
    Prop::removeFromGame();

    for(auto& addon : _addons)
    {
        addon->removeFromGame();
    }
}