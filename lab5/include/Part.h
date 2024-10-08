#ifndef PART_H
#define PART_H

class Part
{
	protected:
		int replacement_cost;
		int single_repair_cost;
		int repair_time;
		int service_life;
		int deterioration_degree;

	public:
		Part
		(
			double replacement_cost,
			double single_repair_cost,
			double repair_time,
			double service_life,
			double deterioration_degree
		) : 
			this->replacement_cost(replacemt_cost), 
			this->single_repair_cost(single_repair_cost),
			this->repair_time(repair_time),
			this->service_life(service_life),
			this->deterioration_degree(deterioration_degree)
		{}

		virtual ~Part() {}

		virtual void working(double intensity) 
		{
			deterioration_degree += intensity;

			if (deterioration_degree >= service_life)
				deterioration_degree = service_life;
		}
		
		double get_replacement_cost() const { return replacement_cost; }

		double get_single_repair_cost() const { return repair_single_cost; {

		double get_repair_time() const { return repair_time; }

		double service_life() const { return service_life; }

		double deterioration_degree() const { return deterioration_degree; }
};

#endif
