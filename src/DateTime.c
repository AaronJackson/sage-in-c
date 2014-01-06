#include "DateTime.h"

long mstime_to_unixtime(double d) {
  long ms_epoch = -2209161600; /* Microsoft time as Unix Timestamp */
  double one_day = 86400;      /* Seconds in a day */

  long secs = d * one_day;
  long unix_time = ms_epoch + secs;

  return unix_time;
}
