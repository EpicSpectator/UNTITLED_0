#ifndef WEAPON_H
#define WEAPON_H

enum DMG_TYPES
{
	PIERCING,
	SLASHING,
	FORCE,
	HEAT,
	CHILL,
	TOXIC,
	ELECTRIC,
	ENCUMBER,
	
	NUM_TYPES
};

struct Damage
{
	float type_damage[NUM_TYPES];
	
	float duration;	// Number of turns the damage lasts
	
//============================= OPERATOR OVERLOADS =============================
	
	float & operator[](int i)
	{
		return type_damage[i % NUM_TYPES];
	}
	
	Damage & operator*=(const int &r)
    {
		for(int i = 0; i < NUM_TYPES; i++)
			type_damage[i] *= r;
		
        return *this;
    }
	
	Damage operator+=(const Damage &r)
	{
		for(int i = 0; i < NUM_TYPES; i++)
			type_damage[i] += r.type_damage[i];
		
		return *this;
	}
	
	Damage operator+(Damage l, const Damage &r)
    {
		l += r;
        return l;
    }
};

class Weapon
{
	private:
	
		float range;
		float accurracy;
	
	public:
	
//========================= CONSTRUCTORS & DESTRUCTORS =========================
	
		Weapon();
		
		virtual ~Weapon();
};

#endif // WEAPON_H