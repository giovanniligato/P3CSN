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
#include <math.h>

namespace queueing {

Define_Module(Classifier);

void Classifier::initialize()
{
    policy = par("policy");

    K=par("K");
    C=getParentModule()->par("C");
    p=getParentModule()->par("p");

}

void Classifier::handleMessage(cMessage *msg)
{
    Customer *customer = check_and_cast<Customer *>(msg);
    int outGateIndex = -1;
    int quickTills = floor(C*p);
    int normalTills = C - quickTills;

    if(customer->getNumberOfItems() <= K){
        if(strcmp(policy, "equallylikely") == 0){
            outGateIndex = uniform(0, quickTills);
        }
        else if(strcmp(policy, "jtsq") == 0){
            int minQueueIndex = (check_and_cast<cQueue*>(getParentModule()->getSubmodule("queues", 0)))->getLength();
            for(int i=1; i<quickTills; i++){
                if((check_and_cast<cQueue*>(getParentModule()->getSubmodule("queues", i)))->getLength() < minQueueIndex){
                    minQueueIndex = i;
                }
            }
            // In the case of two queues having the same length, the first one is chosen
            outGateIndex = minQueueIndex;
        }
        else
            throw cRuntimeError("Invalid policy parameter, must be \"equallylikely\" or \"jtsq\"");
    }
    else{
        if(strcmp(policy, "equallylikely") == 0){
            outGateIndex = uniform(quickTills, C);
        }
        else if(strcmp(policy, "jtsq") == 0){
            int minQueueIndex = (check_and_cast<cQueue*>(getParentModule()->getSubmodule("queues", 0)))->getLength();
            for(int i=quickTills+1; i<C; i++){
                if((check_and_cast<cQueue*>(getParentModule()->getSubmodule("queues", i)))->getLength() < minQueueIndex){
                    minQueueIndex = i;
                }
            }
            // In the case of two queues having the same length, the first one is chosen
            outGateIndex = minQueueIndex;
        }
        else
            throw cRuntimeError("Invalid policy parameter, must be \"equallylikely\" or \"jtsq\"");
    }

    send(customer, "out", outGateIndex);

}

}; //namespace

