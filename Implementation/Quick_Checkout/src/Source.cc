
#include "Source.h"
#include "Customer_m.h"
#include <cmath>

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
    
    // The round operation is performed to assure an integer number of items inside a cart
    customer->setNumberOfItems(round((double)par("numberOfItems")));
    return customer;
}

void SourceBase::finish()
{
    emit(createdSignal, customerCounter);
}


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

