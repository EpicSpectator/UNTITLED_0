#ifndef ARMOR_H
#define ARMOR_H

#include "Weapon.h"

class Armor
{
	private:
	
		float integrity;			// The condition of the armor
		
		float enduraceRating;		// Integrity damage threshold
		float stats[NUM_TYPES];		// Armor resistances
	
	public:
		
//========================= CONSTRUCTORS & DESTRUCTORS =========================
		
		Armor(float _stats[NUM_TYPES], float endurace = 1.0f);
			
		virtual ~Armor();
		
//============================== MEMBER FUNCTIONS ==============================

		// Called during damage encounter and returns the damage not absorbed
		// by the armor.
		Damage * absorbDamage(Damage *dmg);

		// Called during targeting encounter and returns the best and worst case
		// conditions the armor would be in after a damage encounter.
		Armor * calcDamage(Damage *dmg);
			  
//==================================== GETS ====================================
		
		inline float & getIntegrity(){ return &integrity; }
		
		inline float & getEndurance(){ return &enduraceRating; }
		inline float & getStats(DMG_TYPES type){ return &stats[type]; }
		
//==================================== SETS ====================================
		
		inline void setIntegrity(float status){ integrity = status; }
		
		inline void setEndurance(float rating){ enduraceRating = rating; }
		inline void setStats(DMG_TYPES type, float val){ stats[type] = val; }
};

#endif // ARMOR_H