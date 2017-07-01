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
#include <iostream>
#include <fstream>
#include <string>

#include <glm/gtc/matrix_transform.hpp>
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

#include "ai/AI.hpp"
#include "ai/AState.hpp"
#include "ai/ArrivedState.hpp"
#include "ai/CheckMessageState.hpp"
#include "ai/InitAIConnectState.hpp"
#include "ai/CollectFoodState.hpp"
#include "ai/CollectStoneState.hpp"
#include "ai/FindFoodState.hpp"
#include "ai/FindStoneState.hpp"
#include "ai/FixRecipeState.hpp"
#include "ai/FoodOnCaseState.hpp"
#include "ai/IState.hpp"
#include "ai/IncantState.hpp"
#include "ai/LevelState.hpp"
#include "ai/MissingPlayerState.hpp"
#include "ai/MissingStoneState.hpp"
#include "ai/MoveToFoodState.hpp"
#include "ai/MoveToStoneState.hpp"
#include "ai/MoveToTeammateState.hpp"
#include "ai/SetRecipeState.hpp"
#include "ai/StarvingState.hpp"
#include "ai/StoneOnCaseState.hpp"
#include "ai/TrollState.hpp"
#include "ai/PlayerInfo.hpp"

#include "ai/basic_state/BroadcastState.hpp"
#include "ai/basic_state/ConnectnbrState.hpp"
#include "ai/basic_state/EjectState.hpp"
#include "ai/basic_state/ForkState.hpp"
#include "ai/basic_state/ForwardState.hpp"
#include "ai/basic_state/IncantationState.hpp"
#include "ai/basic_state/InventoryState.hpp"
#include "ai/basic_state/LeftState.hpp"
#include "ai/basic_state/LookState.hpp"
#include "ai/basic_state/RightState.hpp"
#include "ai/basic_state/SetState.hpp"
#include "ai/basic_state/TakeState.hpp"

#endif // !ZAPPY_AI_STDAFX_HPP_
