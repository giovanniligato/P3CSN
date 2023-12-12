//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2015 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

package quick_checkout;

//
// Sends the messages to different outputs depending on messages type or priority.
// If no output found for a message, it is sent to the "rest" gate.
// Messages with type = i will be sent to out[i] (if dispatchField = type).
// Messages with priority = i will be sent to out[i] (if dispatchField = priority).
//
// @author rhornig
//

@namespace(queueing);

simple Classifier
{
    parameters:
        @group(Queueing);
        @display("i=block/classifier");
        int K = default(5);
        // Fare due possibilità per gestire numero minimo di persone in coda
        string policy @enum("equallylikely", "jtsq") = default("equallylikely");
        
        
    gates:
        input in;
        output out[];
   	
}
