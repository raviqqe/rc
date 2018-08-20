CC ?= clang
AR ?= ar
CFLAGS = -fPIC -Wall -Wextra -O2 -g
LIB = librc.a

SRCS = rc.c
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: $(LIB)

$(LIB): $(OBJS)
	$(AR) rcs $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	rm -f *.a *.d *.o
