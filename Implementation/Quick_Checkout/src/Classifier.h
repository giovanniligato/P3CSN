
#ifndef __QUEUEING_CLASSIFIER_H
#define __QUEUEING_CLASSIFIER_H

#include "QueueingDefs.h"

namespace queueing {

/**
 * See the NED declaration for more info.
 */
class QUEUEING_API Classifier : public cSimpleModule
{
    private:
        const char *policy;   // The policy used
        int K;
        int C;
        double p;

    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
};

}; //namespace

#endif
