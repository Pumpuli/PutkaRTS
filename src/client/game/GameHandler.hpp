/*
 * Client-side game handler class definition.
 *
 * Copyright 2011 Lauri Kenttä
 * Copyright 2011 Mika Katajamäki
 *
 * This file is part of PutkaRTS.
 *
 * PutkaRTS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PutkaRTS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PutkaRTS.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PUTKARTS_GameHandler_HPP
#define PUTKARTS_GameHandler_HPP

#include "GameConnection.hpp"

#include <memory>
#include <SFML/Graphics.hpp>

#include "client/graphics/ImageCache.hpp"

/**
 * Class for the client-side game GUI.
 */
class GameHandler {
	/** The view to use for rendering. */
	sf::View view;

	/** All images needed for rendering. */
	ImageCache images;

	/** The game connection to use. */
	std::auto_ptr<GameConnection> connection;

	/** Camera position and zoom */
	sf::View gameView;
public:
	/** The current GameHandler instance; there should always be only one. */
	static std::auto_ptr<GameHandler> instance;

	/**
	 * Constructor.
	 *
	 * @param connection The game connection to use.
	 */
	GameHandler(std::auto_ptr<GameConnection> connection);

	/**
	 * Load map graphics etc.
	 */
	void loadMapData();

	/**
	 * Draw the map and the units.
	 */
	void drawGame(sf::RenderWindow& window) const;

	/**
	 * Run the game until it ends.
	 *
	 * @param window The window to use for input and rendering.
	 */
	void run(sf::RenderWindow& window);
};

#endif
