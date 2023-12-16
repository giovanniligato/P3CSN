//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2015 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#include "GlobalSink.h"
#include "Customer_m.h"

namespace queueing {

Define_Module(GlobalSink);

void GlobalSink::initialize()
{
    lifeTimeSignal = registerSignal("lifeTime");
    totalQueueingTimeSignal = registerSignal("totalQueueingTime");
    queuesVisitedSignal = registerSignal("queuesVisited");
    totalServiceTimeSignal = registerSignal("totalServiceTime");
    totalDelayTimeSignal = registerSignal("totalDelayTime");
    delaysVisitedSignal = registerSignal("delaysVisited");
    generationSignal = registerSignal("generation");
    keepCustomers = par("keepCustomers");
}

void GlobalSink::handleMessage(cMessage *msg)
{
    Customer *customer = check_and_cast<Customer *>(msg);

    // gather statistics
    emit(lifeTimeSignal, simTime()- customer->getCreationTime());
    emit(totalQueueingTimeSignal, customer->getTotalQueueingTime());
    emit(queuesVisitedSignal, customer->getQueueCount());
    emit(totalServiceTimeSignal, customer->getTotalServiceTime());
    emit(totalDelayTimeSignal, customer->getTotalDelayTime());
    emit(delaysVisitedSignal, customer->getDelayCount());
    emit(generationSignal, customer->getGeneration());

    if (!keepCustomers)
        delete msg;
}

void GlobalSink::finish()
{
    // TODO missing scalar statistics
}

}; //namespace

