
package quick_checkout;

//
// A queue with a built-in server (till)
//

@namespace(queueing);


simple Queue
{
    parameters:
        @group(Queueing);
        @display("i=block/activeq;q=queue");
        @signal[dropped](type="long");
        @signal[queueLength](type="long");
        @signal[queueingTime](type="simtime_t");
        @signal[busy](type="bool");
        @statistic[dropped](title="drop event";record=vector?,count;interpolationmode=none);
        @statistic[queueLength](title="queue length";record=vector,timeavg,max;interpolationmode=sample-hold);
        @statistic[queueingTime](title="queueing time at dequeue";record=vector?,mean,max;unit=s;interpolationmode=none);
        @statistic[busy](title="server busy state";record=vector?,timeavg;interpolationmode=sample-hold);

        int capacity = default(-1);                             // negative capacity means unlimited queue
        bool fifo = default(true);                              // whether the module works as a queue (fifo=true) or a stack (fifo=false)
        volatile double serviceTime @unit(s) = default(3s);     // service time of the till (per item)
		
    gates:
        input in;
        output out;

}
