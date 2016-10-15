#include "Armor.h"
		
Armor::Armor(float _stats[NUM_TYPES], float endurance) :
	enduranceRating(endurance),
	stats(_stats)
{
	integrity = 1.0f;
}
	
Armor::~Armor()
{
	
}

Damage * Armor::absorbDamage(Damage *dmg)
{
	Damage r_dmg = *dmg;
	for(int i = 0; i < NUM_TYPES; i++)
		r_dmg[i] *= (1 - (stats[i] * integrity));
	
	float intDmg;
	for(int i = 0; i < NUM_TYPES; i++)
	{
		intDmg = (r_dmg[i] / enduranceRating) - 1;
		if (intDmg > 0.0f)
			integrity -= intDmg;
	}
	
	return &r_dmg;
}

Armor * Armor::calcDamage(Damage *dmg)
{
	Damage t_dmg = *dmg;
	for(int i = 0; i < NUM_TYPES; i++)
		t_dmg[i] *= (1 - (stats[i] * integrity));
	
	Armor r_armor = this;
	
	float intDmg;
	for(int i = 0; i < NUM_TYPES; i++)
	{
		intDmg = (r_dmg[i] / enduranceRating) - 1;
		if (intDmg > 0.0f)
			r_armor.integrity -= intDmg;
	}
	
	return &r_armor;
}