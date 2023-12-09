//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2015 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#ifndef __QUEUEING_QUEUE_H
#define __QUEUEING_QUEUE_H

#include "QueueingDefs.h"

namespace queueing {

class Customer;

/**
 * Abstract base class for single-server queues.
 */
class QUEUEING_API Queue : public cSimpleModule
{
    private:
        simsignal_t droppedSignal;
        simsignal_t queueLengthSignal;
        simsignal_t queueingTimeSignal;
        simsignal_t busySignal;

        Customer *customerServiced = nullptr;
        cMessage *endServiceMsg = nullptr;
        cQueue queue;
        int capacity;
        bool fifo;

        Customer *getFromQueue();

    public:
        virtual ~Queue();
        int length();

    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        virtual void refreshDisplay() const override;
        virtual void finish() override;

        // hook functions to (re)define behaviour
        virtual void arrival(Customer *customer);
        virtual simtime_t startService(Customer *customer);
        virtual void endService(Customer *customer);
};

}; //namespace

#endif
