#pragma once

#include "Props/Prop.h"
#include "Utils/Vector2.h"
#include "Addons/Addon.h"

class WorldProp : public Prop
{
    public:

    Vector2 Position;

    int Layer = 0;

    float Rotation = 0;

    float Scale = 1;

    int Height;
    int Width;

    template<typename T, typename... Args>
    T& createAddon(Args&&... args)
    {
        auto addon = std::make_unique<T>(std::forward<Args>(args)...);

        T& addonReference = *addon;

        _addons.push_back(std::move(addon));

        return addonReference;
    }

    void update() override;
    void draw() override;
    void lateUpdate() override;
    void removeFromGame() override;


    protected:

    std::vector<std::unique_ptr<Addon>> _addons;

};
