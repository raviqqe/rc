#include "rc.h"

const size_t count_size = sizeof(atomic_size_t);

static void *rc_alloc_ptr(rc_t rc) { return rc.ptr - count_size; }

static atomic_size_t *rc_count(rc_t rc) { return rc_alloc_ptr(rc); }

rc_t rc_malloc(size_t size) {
  rc_t rc = (rc_t){malloc(count_size + size) + count_size};

  atomic_store(rc_count(rc), 1);

  return rc;
}

void rc_move(rc_t src, rc_t *dst) {
  rc_free(dst);

  *dst = src;
}

void rc_free(rc_t *rc) {
  atomic_size_t *count = rc_count(*rc);

  atomic_fetch_sub(count, 1);

  if (atomic_load(count) == 0) {
    free(rc_alloc_ptr(*rc));
  } else {
    rc->ptr = NULL;
  }
}
