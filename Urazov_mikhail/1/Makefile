CC = gcc
CFLAGS = -Wall -g -Werror=attributes

SRCS := $(shell find . -name '*.c')
OBJS := $(patsubst ./%.c,$(BUILD_DIR)/%.o,$(SRCS))

NAME = Simulator

program: $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(NAME)