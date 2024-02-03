
namespace queueing;

cplusplus {{
#include "QueueingDefs.h"
}}


message Customer {
    
    int priority;                // queueing priority
    simtime_t totalQueueingTime; // total time spent standing in queues
    simtime_t totalServiceTime;  // total time spent in servers
    simtime_t totalDelayTime;    // total time spent in delay modules
    int queueCount;              // the number of queue modules visited by the job
    int delayCount;              // the number of delay modules visited by the job
    int generation;              // how many times the original ancestor was copied
    
    int numberOfItems;           // Number of Items inside the cart
}
