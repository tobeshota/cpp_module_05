SRCS_DIR	=	srcs/

SRCS		=	$(wildcard $(SRCS_DIR)*.cpp)

test:
	@ cmake -S . -B build
	@ cmake --build build
	@ cd build && ctest

format:
	$(if $(SRCS), clang-format --style=Google -i $(SRCS))

.PHONY:	test format
