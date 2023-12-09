//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package quick_checkout;
// import quick_checkout.LocalSink;
import quick_checkout.Queue;
import quick_checkout.Classifier;

module Checkout
{
    parameters:
        int C = default(10);
        double p = default(0.5);

        @display("bgb=622,373");

    gates:
        input in;
        output out;

    submodules:
        classifier: Classifier {
            @display("p=80,184");
        }
        queues[C]: Queue {
            @display("p=287,184");
        }
        // localSink[C]: LocalSink {
        //    @display("p=528,184");
        // }
    connections:
        in --> classifier.in;
        for i=0..C-1 {
            classifier.out++ --> queues[i].in;
            // queues[i].out --> localSink[i].in;
            // localSink[i].out --> out;
        }


}
