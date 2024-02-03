
package quick_checkout;

import quick_checkout.LocalSink;
import quick_checkout.Queue;
import quick_checkout.Classifier;

@namespace(queueing);

module Checkout
{
    parameters:
        double p = default(0.5);

        @display("bgb=622,373");

    gates:
        input in;
        output out[];

    submodules:
        classifier: Classifier {
            @display("p=80,184");
        }
        queues[parent.C]: Queue {
            @display("p=282,184,m,1,45,45");
        }
        localSink[parent.C]: LocalSink {
            @display("p=516,184,m,1,45,45");
        }
        
    connections:
        in --> classifier.in;
        for i=0..parent.C-1 {
            classifier.out++ --> queues[i].in;
            queues[i].out --> localSink[i].in;
            localSink[i].out --> out++;
        }


}
