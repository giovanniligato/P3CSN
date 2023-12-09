//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2015 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#include "Source.h"
#include "Customer_m.h"

namespace queueing {

void SourceBase::initialize()
{
    createdSignal = registerSignal("created");
    customerCounter = 0;
    WATCH(customerCounter);
}

Customer *SourceBase::createCustomer()
{
    char buf[80];
    sprintf(buf, "%.60s-%d", "Customer", ++customerCounter);
    Customer *customer = new Customer(buf);
    customer->setNumberOfItems(par("numberOfItems"));
    return customer;
}

void SourceBase::finish()
{
    emit(createdSignal, customerCounter);
}

//----

Define_Module(Source);

void Source::initialize()
{
    SourceBase::initialize();
    startTime = par("startTime");
    stopTime = par("stopTime");
    numCustomers = par("numCustomers");

    // schedule the first message timer for start time
    scheduleAt(startTime, new cMessage("newCustomerTimer"));
}

void Source::handleMessage(cMessage *msg)
{
    ASSERT(msg->isSelfMessage());

    if ((numCustomers < 0 || numCustomers > customerCounter) && (stopTime < 0 || stopTime > simTime())) {
        // reschedule the timer for the next message
        scheduleAt(simTime() + par("interArrivalTime").doubleValue(), msg);

        Customer *customer = createCustomer();
        send(customer, "out");
    }
    else {
        // finished
        delete msg;
    }
}

//----

Define_Module(SourceOnce);

void SourceOnce::initialize()
{
    SourceBase::initialize();
    simtime_t time = par("time");
    scheduleAt(time, new cMessage("newCustomerTimer"));
}

void SourceOnce::handleMessage(cMessage *msg)
{
    ASSERT(msg->isSelfMessage());
    delete msg;

    int n = par("numCustomers");
    for (int i = 0; i < n; i++) {
        Customer *customer = createCustomer();
        send(customer, "out");
    }
}

}; //namespace

