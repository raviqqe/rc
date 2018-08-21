#include "../src/rc.h"

int main() {
  rc_t rc = rc_malloc(sizeof(double));

  rc_free(&rc);

  return 0;
}
