#include "rc.h"

const size_t count_size = sizeof(atomic_size_t);

static void *rc_alloc_ptr(rc_t rc) { return rc.ptr - count_size; }

static atomic_size_t *rc_count(rc_t rc) { return rc_alloc_ptr(rc); }

static void rc_increment_count(rc_t rc) { atomic_fetch_add(rc_count(rc), 1); }
static void rc_decrement_count(rc_t rc) { atomic_fetch_sub(rc_count(rc), 1); }
static void rc_initialize_count(rc_t rc) { atomic_store(rc_count(rc), 1); }
static size_t rc_load_count(rc_t rc) { return atomic_load(rc_count(rc)); }

rc_t rc_malloc(size_t size) {
  rc_t rc = (rc_t){malloc(count_size + size) + count_size};

  rc_initialize_count(rc);

  return rc;
}

rc_t rc_copy(rc_t rc) {
  rc_increment_count(rc);

  return rc;
}

void rc_move(rc_t src, rc_t *dst) {
  if (dst->ptr != NULL) {
    rc_free(dst);
  }

  *dst = src;
}

void rc_free(rc_t *rc) {
  rc_decrement_count(*rc);

  if (rc_load_count(*rc) == 0) {
    free(rc_alloc_ptr(*rc));
  } else {
    rc->ptr = NULL;
  }
}
