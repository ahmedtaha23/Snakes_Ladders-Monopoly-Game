#pragma once

#include "GameObject.h"
#include "Player.h"

// Base Class of All Types of Cards (CardOne, CardTwo, CardThree, ...etc.)
// Note: We will make each type of Card in a separate class because:
// it may have additional data members and functions like: Apply(), ...etc. which have different implementation depending on Card Number
class Card : public GameObject
{
	static int CardsCount;			// A static member to get the created cards count

protected:
	int cardNumber; // an integer representing the card number
	const CellPosition *cellPosition;

public:
	Card(const CellPosition & pos); // A Constructor for card that takes the cell position of it

	void SetCardNumber(int cnum);   // The setter of card number
	int GetCardNumber();            // The getter of card number

	void Draw(Output* pOut) const;  // Draws the card number in the cell position of the card
	                                // It has the same implementation for all Card Types (Non-Virtual)

	virtual void ReadCardParameters(Grid * pGrid); // It reads the parameters specific for each Card Type
	                                               // It is a virtual function (implementation depends on Card Type)

	virtual void Apply(Grid* pGrid, Player* pPlayer);  // It applies the effect of the Card Type on the passed player
	                                                   // It is a virtual function (implementation depends on Card Type)
	virtual bool IsOverlapping(GameObject* newObj);

	virtual Card* GetCopy(CellPosition&) = 0;
	static int getCardsCount();

	virtual void Save(ofstream& OutFile) = 0;
	virtual void Load(ifstream& Infile, Grid* pGrid) = 0;

	virtual ~Card(); // A Virtual Destructor
};

