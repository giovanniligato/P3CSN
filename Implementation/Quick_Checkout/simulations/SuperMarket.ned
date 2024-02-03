
package quick_checkout.simulations;

import quick_checkout.Source;
import quick_checkout.Checkout;
import quick_checkout.GlobalSink;

network SuperMarket
{
    
    parameters:
        int C = default(6);

	@display("bgb=530,355");
	
    submodules:
        source: Source {
            @display("p=76,144");
        }
        checkout: Checkout {
            @display("p=249,144");
        }
        globalSink: GlobalSink {
            @display("p=419,144");
        }

    connections:
        source.out --> checkout.in;
        for i=0..C-1 {
            checkout.out++ --> globalSink.in++;
        }

}
