#include "msl/robot/IntRobotIDFactory.h"

#include <supplementary/IAgentID.h>
#include <limits>
#include <random>

namespace msl
{
namespace robot
{

IntRobotIDFactory::IntRobotIDFactory()
{
}

IntRobotIDFactory::~IntRobotIDFactory()
{
}

const supplementary::IAgentID *IntRobotIDFactory::create(std::vector<uint8_t> &robotID) const
{
    unsigned char *_robotRosID = reinterpret_cast<unsigned char *>(robotID.data());
    return new IntRobotID(_robotRosID, robotID.size());
}

const supplementary::IAgentID *IntRobotIDFactory::generateID() const
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int> dis (std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max());

    int tmpID = dis(gen);

	std::vector<uint8_t> agentIDVector;
	for (int i = 0; i < sizeof(int); i++)
	{
		agentIDVector.push_back(*(((uint8_t *)&tmpID) + i));
	}
	return this->create(agentIDVector);
}

} /* namespace robot */
} /* namespace msl */
