#include<GameObject.h>

class Plant
{
public:
	Plant(std::vector<float> vertices, std::vector<unsigned int> indices, std::string texture_filename);

protected:
	GameObject gameObject;
};

