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
import quick_checkout.Sink;
import quick_checkout.Queue;
import quick_checkout.Classifier;

module Checkout
{
    parameters:
        int C;
        double p;
        int K;
        
    @display("bgb=622,373");
    submodules:
        localSink1: Sink {
            @display("p=416,76");
        }
        localSink2: Sink {
            @display("p=416,181");
        }
        localSsink3: Sink {
            @display("p=416,280");
        }
        till1: Queue {
            @display("p=269,76");
        }
        till2: Queue {
            @display("p=269,181");
        }
        till3: Queue {
            @display("p=269,280");
        }
        clf: Classifier {
            @display("p=102,181");
        }
    connections:
        till1.in++ <-- clf.out[0];
        till2.in++ <-- clf.out[1];
        till3.in++ <-- clf.out[2];
        localSink1.in++ <-- till1.out;
        localSink2.in++ <-- till2.out;
        localSink3.in++ <-- till3.out;
    
    gates:
        input in;
        output out[];
}
