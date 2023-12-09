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

package quick_checkout.simulations;

import quick_checkout.Source;
import quick_checkout.Checkout;
// import quick_checkout.GlobalSink;

network SuperMarket
{
    @display("bgb=530,355");


    submodules:
        source: Source {
            @display("p=76,144");
        }
        checkout: Checkout {
            @display("p=249,144");
        }
        // globalSink: GlobalSink {
        //     @display("p=419,144");
        // }

    connections:
        source.out --> checkout.in;
        // checkout.out --> globalSink.in;



}
