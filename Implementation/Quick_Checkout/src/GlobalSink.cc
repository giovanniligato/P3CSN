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

    qF = qN = 0;
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

    customer->getNumberOfItems() <= (int)getParentModule()->
                                    getSubmodule("checkout")->
                                    getSubmodule("classifier")->
                                    par("K") ? qF++ : qN++;

    if (!keepCustomers)
        delete msg;
}

void GlobalSink::finish()
{
    EV<<"Tot. code veloci : "<<qF<<"\n";
    EV<<"Tot. code normali : "<<qN<<"\n";
    EV<<"Percentuale code veloci : "<<(double)qF/(qF+qN)<<"\n";
    EV<<"Percentuale code normali : "<<(double)qN/(qF+qN)<<"\n";
    // TODO missing scalar statistics
}

}; //namespace

