# Makefile dependencies directory
MK_DIR=		./mk/
MK_COMMON_DIR=	./../mk/

# Definitions for Makefile
NAME=		$(ROOT_DIR)/zappy_server

LOCAL_DEBUG_CFLAGS=

LOCAL_COMP_CFLAGS=

LOCAL_COMP_FLAGS=

LOCAL_LINK_FLAGS=	-L$(ROOT_DIR)/build/ -lzappy_clogger	\
			-lzappy_cqueue

LOCAL_DEBUG_FLAGS=

include $(MK_COMMON_DIR)colors.mk $(MK_COMMON_DIR)defs.mk

LD=			$(CC)

# Project's directories

SRC_DIR=	./src/

INCLUDE_DIR=	./include/

DIR_LIST=	$(SRC_DIR)		\
		$(SRC_DIR)/state

HEADER=

# Project's files


SRC_FILES=	argvs_func.c		\
		argvs_func_freq.c	\
		cleanup.c		\
		client.c		\
		client_manager.c	\
		io.c			\
		logic.c			\
		main.c			\
		message.c		\
		multiplexer.c		\
		network.c		\
		parse.c			\
		server.c		\
		socket.c		\
		state/auth.c

SRC=		$(addprefix $(SRC_DIR), $(SRC_FILES))


INC_DIR=	$(DIR_LIST:$(SRC_DIR)%=$(INCLUDE_DIR)%)		\
		$(ROOT_DIR)/libs/clogger/include/		\
		$(ROOT_DIR)/libs/cqueue/include/

PRECOMPILED_HEADER= $(addprefix $(INCLUDE_DIR),$(HEADER))

# Rules
ifeq ($(shell uname -s),Darwin)
include $(MK_COMMON_DIR)rules_osx.mk
else
include $(MK_COMMON_DIR)rules.mk
endif
