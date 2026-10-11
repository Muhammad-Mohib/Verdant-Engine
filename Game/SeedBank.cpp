#include "SeedBank.h"
////#include<vector>
//
SeedBank::SeedBank(Application& application) : _application(application)
{
	SetupSeedBank();
}

void SeedBank::SetupSeedBank()
{
	std::vector<float> seedbank_verts = {
		// Position       // UV
		  0.0f,  0.0f,   0.0f, 0.0f,
		446.0f,  0.0f,   1.0f, 0.0f,
		446.0f, 90.0f,   1.0f, 1.0f,
		  0.0f, 90.0f,   0.0f, 1.0f
	};

	std::vector<unsigned int> seedbank_indices = {
		0, 1, 2,
		2, 3, 0
	};

	_application.CreateGameObject(seedbank_verts, seedbank_indices, "SeedBank.png")->setPosition(glm::vec2(15.0f, 0.0f));

}
