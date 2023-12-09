//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2015 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#include "Classifier.h"
#include "Customer_m.h"

namespace queueing {

Define_Module(Classifier);

void Classifier::initialize()
{
    dispatchField = par("dispatchField");
}

void Classifier::handleMessage(cMessage *msg)
{
    Customer *customer = check_and_cast<Customer *>(msg);
    int outGateIndex = -1;
    /*
    if (strcmp(dispatchField, "type") == 0)
        //outGateIndex = job->getKind();
    else if (strcmp(dispatchField, "priority") == 0)
        outGateIndex = customer->getNOfItems();
    else
        throw cRuntimeError("invalid dispatchField parameter, must be \"type\" or \"priority\"");  // TODO we could look for the value in the dynamically added parameters too

    if (outGateIndex < 0 || outGateIndex >= gateSize("out"))
        send(customer, "rest");
    else
        send(customer, "out", outGateIndex);
    */
}

}; //namespace

