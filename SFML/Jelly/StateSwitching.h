#ifndef STATESWITCHING_H
#define STATESWITCHING_H

#include "Consumables.h"

class StateSwitching : virtual public Consumables
{
public:
	StateSwitching();
	~StateSwitching();
	

		// LoadItems - Resets all settings (health to full, enemies back, etc)
	void LoadItems();
	
		// SaveGame - Saves the current state (enemies defeated, jellies freed, etc) of the game into a textfile
	void SaveGame();

		// LoadGame - Loads the saved state from a textfile
	void LoadGame();

private:
};

#endif