//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2015 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#include "LocalSink.h"
#include "Customer_m.h"

namespace queueing {

Define_Module(LocalSink);

void LocalSink::initialize()
{
    lifeTimeSignal = registerSignal("lifeTime");
    totalQueueingTimeSignal = registerSignal("totalQueueingTime");
    queuesVisitedSignal = registerSignal("queuesVisited");
    totalServiceTimeSignal = registerSignal("totalServiceTime");
    totalDelayTimeSignal = registerSignal("totalDelayTime");
    delaysVisitedSignal = registerSignal("delaysVisited");
    generationSignal = registerSignal("generation");
}

void LocalSink::handleMessage(cMessage *msg)
{
    Customer *customer = check_and_cast<Customer *>(msg);

    // gather statistics
    emit(lifeTimeSignal, simTime() - customer->getCreationTime());
    emit(totalQueueingTimeSignal, customer->getTotalQueueingTime());
    emit(queuesVisitedSignal, customer->getQueueCount());
    emit(totalServiceTimeSignal, customer->getTotalServiceTime());
    emit(totalDelayTimeSignal, customer->getTotalDelayTime());
    emit(delaysVisitedSignal, customer->getDelayCount());
    emit(generationSignal, customer->getGeneration());

    send(customer, "out");

}

void LocalSink::finish()
{
    // TODO missing scalar statistics
}

}; //namespace

