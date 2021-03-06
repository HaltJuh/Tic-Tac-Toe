
#include "pch.h"
#include <iostream>
#include "Zone.h"
#include "ZoneMaster.h"
#include "conio.h"

void drawField(ZoneMaster* zoneMaster);
bool gameOver(ZoneMaster* zoneMaster, bool* tie);
bool* tie = new bool;
int main()
{
	int turnPlayer = 1;
	int chosenNumber;
	*tie = false;
	ZoneMaster* zoneMaster = new ZoneMaster();
	while (!gameOver(zoneMaster,tie))
	{
		system("cls");
		drawField(zoneMaster);
		chosenNumber = 0;
		std::cout << "\nPlayer " << turnPlayer << ", choose a number between 1-9.\n";
		do
		{
			
			if (!std::cin >> chosenNumber)
			{
				std::cin.clear();
				std::cin.ignore();
			}
			else
			{
				std::cin >> chosenNumber;
			}
			for (int i = 0; i < 9; i++)
			{
				if (zoneMaster->getZoneIndex(i) == chosenNumber)
				{
					if (zoneMaster->getZoneState(i) != 0)
					{
						chosenNumber = 0;
						std::cout << "That zone has already been marked.\nTry again.\n";
					}
					else
					{
						zoneMaster->setZoneState(i, turnPlayer);
					}
				}
			}
			std::cin.get();
		} while (chosenNumber < 1 || chosenNumber > 9);
		std::cout <<"\n";
		if (!gameOver(zoneMaster,tie))
		{
			if (turnPlayer == 1)
			{
				turnPlayer = 2;
			}
			else
			{
				turnPlayer = 1;
			}
		}
	}
	std::cout << "\n";
	drawField(zoneMaster);
	if (!*tie)
	{
		std::cout <<"\nPlayer " << turnPlayer << " Won!";
	}
	else
	{
		std::cout << "\nThe game ended in a draw.";
	}
}
void drawField(ZoneMaster* zoneMaster)
{
	for (int i = 0; i < 9; i++)
	{
		if (zoneMaster->getZoneState(i) == 1)
		{
			std::cout << "X ";
		}
		else if (zoneMaster->getZoneState(i) == 2)
		{
			std::cout << "O ";
		}
		else
		{
			std::cout << zoneMaster->getZoneIndex(i) << " ";
		}
		if (i == 2 || i == 5 || i == 8)
		{
			std::cout << "\n";
		}
	}
}
bool gameOver(ZoneMaster* zoneMaster,bool* tie)
{
	if ((zoneMaster->getZoneState(0) == zoneMaster->getZoneState(1) && zoneMaster->getZoneState(1) == zoneMaster->getZoneState(2)) && zoneMaster->getZoneState(0) != 0)
	{
		std::cout << "123";
		return true;
	}
	else if ((zoneMaster->getZoneState(3) == zoneMaster->getZoneState(4) && zoneMaster->getZoneState(4) == zoneMaster->getZoneState(5)) && zoneMaster->getZoneState(3) != 0)
	{
		std::cout << "456";
		return true;
	}
	else if ((zoneMaster->getZoneState(6) == zoneMaster->getZoneState(7) && zoneMaster->getZoneState(7) == zoneMaster->getZoneState(8)) && zoneMaster->getZoneState(6) != 0)
	{
		std::cout << "789";
		return true;
	}
	else if ((zoneMaster->getZoneState(0) == zoneMaster->getZoneState(3) && zoneMaster->getZoneState(3) == zoneMaster->getZoneState(6)) && zoneMaster->getZoneState(0) != 0)
	{
		std::cout << "147";
		return true;
	}
	else if ((zoneMaster->getZoneState(1) == zoneMaster->getZoneState(4) && zoneMaster->getZoneState(4) == zoneMaster->getZoneState(7)) && zoneMaster->getZoneState(1) != 0)
	{
		std::cout << "258";
		return true;
	}
	else if ((zoneMaster->getZoneState(2) == zoneMaster->getZoneState(5) && zoneMaster->getZoneState(5) == zoneMaster->getZoneState(8)) && zoneMaster->getZoneState(2) != 0)
	{
		std::cout << "369";
		return true;
	}
	else if ((zoneMaster->getZoneState(0) == zoneMaster->getZoneState(4) && zoneMaster->getZoneState(4) == zoneMaster->getZoneState(8)) && zoneMaster->getZoneState(0) != 0)
	{
		std::cout << "159";
		return true;
	}
	else if ((zoneMaster->getZoneState(2) == zoneMaster->getZoneState(4) && zoneMaster->getZoneState(4) == zoneMaster->getZoneState(6)) && zoneMaster->getZoneState(2) != 0)
	{
		std::cout << "357";
		return true;
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (zoneMaster->getZoneState(i) == 0)
			{
				return false;
			}
		}
		*tie = true;
		return true;
	}
	
}