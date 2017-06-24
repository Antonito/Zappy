// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#ifndef ZAPPY_AI_STDAFX_HPP_
#define ZAPPY_AI_STDAFX_HPP_

#ifdef _WIN32
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#endif                      // !_WIN32

#include <exception>
#include <utility>

#include "Logger.hpp"
#include "OptionParser.hpp"
#include "OptionException.hpp"

#include "GraphicClient.hpp"
#include "GameMap.hpp"
#include "Tile.hpp"
#include "Player.hpp"

#endif // !ZAPPY_AI_STDAFX_HPP_
