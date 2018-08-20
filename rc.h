#ifndef MAIN_H
#define MAIN_H

typedef struct rc { void *ptr; } rc_t;

void rc_move(rc_t, rc_t *);

#endif
