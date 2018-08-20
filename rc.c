#include "rc.h"

static void *rc_alloc_ptr(rc_t rc) {
  return (void *)((size_t)(rc.ptr) - sizeof(size_t));
}

static size_t *rc_count(rc_t rc) { return (size_t *)(rc_alloc_ptr(rc)); }

void rc_move(rc_t src, rc_t *dst) {
  // TODO: Write real move code.
}

void rc_free(rc_t *rc) {
  size_t *count = rc_count(*rc);

  (*count)--;

  if (*count == 0) {
    free(rc_alloc_ptr(*rc));
  }

  rc->ptr = NULL;
}
