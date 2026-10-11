#pragma once
#include<string>
#include <memory>
#include "Plant.h"

class SeedSlotBase
{
public:
    virtual ~SeedSlotBase() = default;
    virtual std::unique_ptr<Plant> CreatePlant() const = 0;
};

template<typename PlantType>
class SeedSlot : public SeedSlotBase
{
public:
    using Config = typename PlantType::Config;

    explicit SeedSlot(Config configuration)
        : config(std::move(configuration))
    {
    }

    std::unique_ptr<Plant> CreatePlant() const override
    {
        return std::make_unique<PlantType>(config);
    }

private:
    Config config;
};

