// C includes
#include <stdio.h>
#include <stdarg.h>

// Local includes
#include "Utils.h"

using namespace std;

void logging(const char *fmt, ...)
{
    va_list args;
    fprintf( stderr, "LOG: " );
    va_start( args, fmt );
    vfprintf( stderr, fmt, args );
    va_end( args );
    fprintf( stderr, "\n" );
}

// Get number of ms from epoch
chrono::milliseconds millisecs_since_epoch()
{
return chrono::duration_cast< chrono::milliseconds >(
            chrono::system_clock::now().time_since_epoch());
}