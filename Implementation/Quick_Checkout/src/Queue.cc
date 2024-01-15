//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2015 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#include "Queue.h"
#include "Customer_m.h"

namespace queueing {

Define_Module(Queue);

Queue::~Queue()
{
    delete customerServiced;
    cancelAndDelete(endServiceMsg);
}

void Queue::initialize()
{
    droppedSignal = registerSignal("dropped");
    queueingTimeSignal = registerSignal("queueingTime");
    queueLengthSignal = registerSignal("queueLength");
    emit(queueLengthSignal, 0);
    busySignal = registerSignal("busy");
    emit(busySignal, false);

    endServiceMsg = new cMessage("end-service");
    fifo = par("fifo");
    capacity = par("capacity");
    queue.setName("queue");
}

void Queue::handleMessage(cMessage *msg)
{
    if (msg == endServiceMsg) {
        endService(customerServiced);
        if (queue.isEmpty()) {
            customerServiced = nullptr;
            emit(busySignal, false);
        }
        else {
            customerServiced = getFromQueue();
            emit(queueLengthSignal, length());
            simtime_t serviceTime = startService(customerServiced);
            scheduleAt(simTime()+serviceTime, endServiceMsg);
        }
    }
    else {
        Customer *customer = check_and_cast<Customer *>(msg);
        arrival(customer);

        if (!customerServiced) {
            // processor was idle
            customerServiced = customer;
            emit(busySignal, true);
            simtime_t serviceTime = startService(customerServiced);
            scheduleAt(simTime()+serviceTime, endServiceMsg);
        }
        else {
            // check for container capacity
            //
            // The condition inside this if is always false if the capacity
            // of the queue is infinite (i.e. capacity = -1)
            if (capacity >= 0 && queue.getLength() >= capacity) {
                EV << "Capacity full! Customer dropped.\n";
                if (hasGUI())
                    bubble("Dropped!");
                emit(droppedSignal, 1);
                delete customer;
                return;
            }
            queue.insert(customer);
            emit(queueLengthSignal, length());
            customer->setQueueCount(customer->getQueueCount() + 1);
        }
    }
}

void Queue::refreshDisplay() const
{
    getDisplayString().setTagArg("i2", 0, customerServiced ? "status/execute" : "");
    getDisplayString().setTagArg("i", 1, queue.isEmpty() ? "" : "cyan");
}

Customer *Queue::getFromQueue()
{
    Customer *customer;
    if (fifo) {
        customer = (Customer *)queue.pop();
    }
    else {
        customer = (Customer *)queue.back();
        // FIXME this may have bad performance as remove uses linear search
        queue.remove(customer);
    }
    return customer;
}

int Queue::length()
{
    return queue.getLength();
}

void Queue::arrival(Customer *customer)
{
    customer->setTimestamp();
}

simtime_t Queue::startService(Customer *customer)
{
    // gather queueing time statistics
    simtime_t d = simTime() - customer->getTimestamp();
    emit(queueingTimeSignal, d);
    customer->setTotalQueueingTime(customer->getTotalQueueingTime() + d);
    EV << "Starting service of " << customer->getName() << endl;
    customer->setTimestamp();

    return customer->getNumberOfItems() * par("serviceTime").doubleValue();
}

void Queue::endService(Customer *customer)
{
    EV << "Finishing service of " << customer->getName() << endl;
    simtime_t d = simTime() - customer->getTimestamp();
    customer->setTotalServiceTime(customer->getTotalServiceTime() + d);
    send(customer, "out");
}

void Queue::finish()
{
}

}; //namespace

