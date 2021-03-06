// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#ifndef ZAPPY_AI_STDAFX_HPP_
#define ZAPPY_AI_STDAFX_HPP_

#ifdef _WIN32
#include "targetver.hpp"
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#endif                      // !_WIN32

#include <exception>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/transform.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include <cctype>

#include "Logger.hpp"
#include "OptionParser.hpp"
#include "OptionException.hpp"

#include "Player.hpp"
#include "GraphicClient.hpp"
#include "GameMap.hpp"
#include "Tile.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "ResourceStack.hpp"

#include "ai/AI.hpp"
#include "ai/PlayerInfo.hpp"

#endif // !ZAPPY_AI_STDAFX_HPP_
