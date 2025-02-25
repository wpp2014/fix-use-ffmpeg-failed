#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
#include "libavutil/avutil.h"
#ifdef __cplusplus
}
#endif

int main() {
  printf("version:\n  %s\nconfiguration:\n  %s\n",
         av_version_info(),\
         avutil_configuration());
  return 0;
}
