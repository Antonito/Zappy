# Makefile dependencies directory
MK_DIR=		./mk/
MK_COMMON_DIR=	./../mk/

# Definitions for Makefile
NAME=		$(ROOT_DIR)/zappy_server

NO_LOG=		no

LOCAL_DEBUG_CFLAGS=

LOCAL_COMP_CFLAGS=	-D_GNU_SOURCE -O2

LOCAL_COMP_FLAGS=

LOCAL_LINK_FLAGS=	-L$(ROOT_DIR)/build/ -lzappy_clogger	\
			-lzappy_cqueue	-lzappy_cmempool -lm

LOCAL_DEBUG_FLAGS=

ifeq ($(NO_LOG),yes)
LOCAL_COMP_CFLAGS+=	-DCLOGGER_NO_LOG
endif

include $(MK_COMMON_DIR)colors.mk $(MK_COMMON_DIR)defs.mk

LD=			$(CC)

# Project's directories

SRC_DIR=	./src/

INCLUDE_DIR=	./include/

DIR_LIST=	$(SRC_DIR)		\
		$(SRC_DIR)state		\
		$(SRC_DIR)client_cmd	\
		$(SRC_DIR)graphic_cmd

HEADER=

# Project's files


SRC_FILES=	admin.c				\
		admin_auth.c			\
		admin_cmd.c			\
		admin_io.c			\
		alloc.c				\
		alloc_message.c			\
		alloc_queue.c			\
		alloc_serial.c			\
		argvs_func.c			\
		argvs_func_freq.c		\
		broadcast.c			\
		cleanup.c			\
		cleanup_client.c		\
		cleanup_map.c			\
		cleanup_admin.c			\
		client.c			\
		client_for_each.c		\
		client_game.c			\
		client_manager.c		\
		client_move.c			\
		client_rotate.c			\
		elevation.c			\
		graphic_cmd.c			\
		graphic_monitor.c		\
		io.c				\
		logic.c				\
		main.c				\
		map.c				\
		map_case.c			\
		message.c			\
		multiplexer.c			\
		network.c			\
		order.c				\
		parse.c				\
		resource.c			\
		ring_buffer.c			\
		server.c			\
		socket.c			\
		team_manager.c			\
		time.c				\
		vision.c			\
		state/auth.c			\
		state/connect.c			\
		state/resp.c			\
		client_cmd/forward.c		\
		client_cmd/broadcast.c		\
		client_cmd/look.c		\
		client_cmd/right.c		\
		client_cmd/left.c		\
		client_cmd/inventory.c		\
		client_cmd/take.c		\
		client_cmd/set.c		\
		client_cmd/eject.c		\
		client_cmd/fork.c		\
		client_cmd/incantation.c	\
		client_cmd/connect_nbr.c	\
		client_cmd/err.c		\
		client_cmd/dead.c		\
		graphic_cmd/msz.c		\
		graphic_cmd/bct.c		\
		graphic_cmd/tna.c		\
		graphic_cmd/pnw.c		\
		graphic_cmd/ppo.c		\
		graphic_cmd/plv.c		\
		graphic_cmd/pin.c		\
		graphic_cmd/pex.c		\
		graphic_cmd/pbc.c		\
		graphic_cmd/pic.c		\
		graphic_cmd/pie.c		\
		graphic_cmd/pfk.c		\
		graphic_cmd/pdr.c		\
		graphic_cmd/pgt.c		\
		graphic_cmd/pdi.c		\
		graphic_cmd/enw.c		\
		graphic_cmd/eht.c		\
		graphic_cmd/ebo.c		\
		graphic_cmd/edi.c		\
		graphic_cmd/sgt.c		\
		graphic_cmd/seg.c		\
		graphic_cmd/smg.c		\
		graphic_cmd/suc.c		\
		graphic_cmd/sbp.c

SRC=		$(addprefix $(SRC_DIR), $(SRC_FILES))


INC_DIR=	$(DIR_LIST:$(SRC_DIR)%=$(INCLUDE_DIR)%)		\
		$(ROOT_DIR)/libs/clogger/include/		\
		$(ROOT_DIR)/libs/cqueue/include/		\
		$(ROOT_DIR)/libs/cmempool/include/

PRECOMPILED_HEADER= $(addprefix $(INCLUDE_DIR),$(HEADER))

# Rules
ifeq ($(shell uname -s),Darwin)
include $(MK_COMMON_DIR)rules_osx.mk
else
include $(MK_COMMON_DIR)rules.mk
endif
