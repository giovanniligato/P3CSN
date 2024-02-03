
package quick_checkout;

//
// Sends the customers to different outputs depending on the number
// of items inside their cart. Inside a subsystem, two policies can
// be used: "equallylikely" and "jtsq" (join the shortest queue).
//

@namespace(queueing);

simple Classifier
{
    parameters:
        @group(Queueing);
        @display("i=block/classifier");
        int K = default(5);                 // Threshold for being routed to the Quick-Checkout Subsystem

        // Policies
        string policy @enum("equallylikely", "jtsq") = default("equallylikely");
        
        
    gates:
        input in;
        output out[];
   	
}
