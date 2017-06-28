# Makefile dependencies directory
MK_DIR=		./mk/
MK_COMMON_DIR=	./../mk/

# Definitions for Makefile
NAME=		$(ROOT_DIR)/zappy_ai

LOCAL_COMP_FLAGS=	-Wno-exit-time-destructors		\
			-Wno-global-constructors		\
			-I/opt/X11/include/

LOCAL_LINK_FLAGS=	-lstdc++ -L $(ROOT_DIR)/build		\
			-lzappy_logger				\
			-lzappy_option				\
			-lzappy_network				\
			-lzappy_exceptions			\
			-lsfml-graphics				\
			-lsfml-window				\
			-lsfml-system				\
			-lGLEW

LOCAL_DEBUG_FLAGS=

include $(MK_COMMON_DIR)colors.mk $(MK_COMMON_DIR)defs.mk

LD=		$(CXX)

ifeq ($(CXX), clang++)
CXXFLAGS+=

endif

# Project's directories

SRC_DIR=	./src/

INCLUDE_DIR=	./include/

DIR_LIST=	$(SRC_DIR)

HEADER=		zappy_ai_stdafx.hpp

# Project's files

SRC_FILES=	main.cpp				\
		AI.cpp					\
		GraphicClient.cpp			\
		GameMap.cpp				\
		Player.cpp				\
		Tile.cpp				\
		Mesh.cpp				\
		Model.cpp				\
		Window.cpp				\
		Shader.cpp				\
		ai/AI.cpp				\
		ai/AState.cpp				\
		ai/ArrivedState.cpp			\
		ai/CheckMessageState.cpp		\
		ai/InitAIConnectState.cpp		\
		ai/CollectFoodState.cpp			\
		ai/CollectStoneState.cpp		\
		ai/FindFoodState.cpp			\
		ai/FindStoneState.cpp			\
		ai/FixRecipeState.cpp			\
		ai/FoodOnCaseState.cpp			\
		ai/IncantState.cpp			\
		ai/LevelState.cpp			\
		ai/MissingPlayerState.cpp		\
		ai/MissingStoneState.cpp		\
		ai/MoveToFoodState.cpp			\
		ai/MoveToStoneState.cpp			\
		ai/MoveToTeammateState.cpp		\
		ai/SetRecipeState.cpp			\
		ai/StarvingState.cpp			\
		ai/StoneOnCaseState.cpp			\
		ai/TrollState.cpp			\
		ai/basic_state/BroadcastState.cpp	\
		ai/basic_state/ConnectnbrState.cpp	\
		ai/basic_state/EjectState.cpp		\
		ai/basic_state/ForkState.cpp		\
		ai/basic_state/ForwardState.cpp		\
		ai/basic_state/IncantationState.cpp	\
		ai/basic_state/InventoryState.cpp	\
		ai/basic_state/LeftState.cpp		\
		ai/basic_state/LookState.cpp		\
		ai/basic_state/RightState.cpp		\
		ai/basic_state/SetState.cpp		\
		ai/basic_state/TakeState.cpp

SRC=		$(addprefix $(SRC_DIR), $(SRC_FILES))


INC_DIR=	$(DIR_LIST:$(SRC_DIR)%=$(INCLUDE_DIR)%)		\
		$(ROOT_DIR)/libs/logger/include/		\
		$(ROOT_DIR)/libs/network/include/		\
		$(ROOT_DIR)/libs/option/include/

PRECOMPILED_HEADER= $(addprefix $(INCLUDE_DIR),$(HEADER))

# Rules
ifeq ($(shell uname -s),Darwin)
include $(MK_COMMON_DIR)rules_osx.mk
else
include $(MK_COMMON_DIR)rules.mk
endif
