RM			=	rm -rf
SRCS_DIR	=	srcs/
BUILD_DIR	=	build/

SRCS		=	$(wildcard $(SRCS_DIR)*.cpp)

test:
	@ cmake -S . -B build
	@ cmake --build build
	@ cd build && ctest

fclean:
	$(RM) $(BUILD_DIR)

format:
	$(if $(SRCS), clang-format --style=Google -i $(SRCS))

.PHONY:	test format
