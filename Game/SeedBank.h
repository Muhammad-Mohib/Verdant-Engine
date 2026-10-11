#pragma once
#include <Application.h>
#include<vector>
#include "SeedSlot.h"
class SeedBank
{
public:
	SeedBank(Application& application);
	void SetupSeedBank();
private:
	Application& _application;

	std::vector<std::unique_ptr<SeedSlotBase>> _slots;
	SeedSlotBase* _selectedSlot = nullptr;

	template<typename PlantType>
	void AddSlot(typename PlantType::Config configuration)
	{
		_slots.push_back(
			std::make_unique<SeedSlot<PlantType>>(
				std::move(configuration),
				_application
			)
		);
	}
};

