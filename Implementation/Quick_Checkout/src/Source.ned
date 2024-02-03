
package quick_checkout;

//
// A module that generates customers. One can specify the number of customers to be generated,
// the starting and ending time, and interval between generating customers.
// customer generation stops when the number of customers or the end time has been reached,
// whichever occurs first. The name, type and priority of customers can be set as well.
//
@namespace(queueing);

simple Source
{
    
    parameters:
        @group(Queueing);
        @signal[created](type="long");
        @statistic[created](title="the number of customers created";record=last;interpolationmode=none);
        @display("i=block/source");
        int numCustomers = default(-1);                         // number of customers to be generated (-1 means no limit)
        volatile double interArrivalTime @unit(s);              // time between generated customers
        volatile double numberOfItems;                          // number of items in the cart
        double startTime @unit(s) = default(interArrivalTime);  // when the module sends out the first customer
        double stopTime @unit(s) = default(-1s);                // when the module stops the customer generation (-1 means no limit)
    	
    gates:
        output out;
        
}

