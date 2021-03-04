#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "block.hpp"

class Wall : public Block
{
public:
	/* Metoda wyswitlajaca komunikat o strowrzeniu
	nieprawidlowego wskaznika */
	virtual void SetUp() override;
};