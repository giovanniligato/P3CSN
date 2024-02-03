

#ifndef __QUEUEING_QUEUEINGDEFS_H
#define __QUEUEING_QUEUEINGDEFS_H

#include <omnetpp.h>

using namespace omnetpp;

#if OMNETPP_VERSION < 0x0400
#  error At least OMNeT++/OMNEST version 4.0 required
#endif

#if defined(QUEUEING_EXPORT)
#  define QUEUEING_API OPP_DLLEXPORT
#elif defined(QUEUEING_IMPORT)
#  define QUEUEING_API OPP_DLLIMPORT
#else
#  define QUEUEING_API
#endif

#endif


