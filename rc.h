#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>

typedef struct { void *ptr; } rc_t;

rc_t rc_malloc(size_t size);
void rc_move(rc_t, rc_t *);
void rc_free(rc_t *);

#endif
