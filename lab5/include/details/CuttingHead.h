#ifndef CUTTINGHEAD_H
#define CUTTINGHEAD_H

#include "Part.h"
#include "../strategy/DefaultPartStrategy.h"

class CuttingHead : public Part
{
	public:
		CuttingHead() : Part(Constants::replacement_cost_cutting_head, Constants::repair_cost_cutting_head, Constants::repair_time_cutting_head, Constants::service_life_cutting_head, new DefaultPartStrategy()) {}

		friend std::ostream& operator << (std::ostream& os, const CuttingHead& ch);
};

std::ostream& operator << (std::ostream& os, const CuttingHead& ch)
{
    os << "CuttingHead " << static_cast<const Part&>(ch);
    return os;
}

#endif
