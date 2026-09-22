#if defined __ARMEL__ || defined __ARMEB__
#ifdef __AXM0
#include "axm0.h"
#endif
#ifdef __AXM0F2
#include "axm0f2.h"
#endif
#else
#include "ax8052.h"
#endif
#include "libaxlcd2.h"

LCD2_DEFINE_TXBUFFER(64)
