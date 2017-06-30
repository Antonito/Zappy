# Makefile dependencies directory
MK_DIR=		./mk/
MK_COMMON_DIR=	./../mk/

# Definitions for Makefile
NAME=		$(ROOT_DIR)/zappy_ai

LOCAL_COMP_FLAGS=

LOCAL_LINK_FLAGS=	-lstdc++ -L $(ROOT_DIR)/build		\
			-lzappy_logger				\
			-lzappy_option				\
			-lzappy_network				\
			-lzappy_exceptions				\
			-lsfml-graphics				\
			-lsfml-window				\
			-lsfml-system				\
			-lGLEW					\
			-lGL					\
			-lglut					\
			-lGLU

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
		GraphicClient.cpp			\
		GameMap.cpp				\
		Player.cpp				\
		Tile.cpp				\
		Mesh.cpp				\
		Model.cpp				\
		Window.cpp				\
		Shader.cpp				\
		Camera.cpp				\
		Resource.cpp				\
		ResourceStack.cpp

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
