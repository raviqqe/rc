#include "../src/rc.h"
#include <assert.h>

int main() {
  rc_t rc = rc_malloc(sizeof(double));

  *(double *)rc.ptr = 123;

  assert(*(double *)rc.ptr == 123);

  return 0;
}
