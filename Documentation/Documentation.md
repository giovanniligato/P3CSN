# A PECSN' project



## Objectives
Analizzare il comportamento delle code sia in termini di dimensioni che in termini di tempo di attesa per ogni cliente.


## Key Performance Indices (KPIs)
The main objectives of this study are comparing the:

### Main
- average length of the queues
- average response time


### Other KPIs
- average service time calculated w.r.t the complete simulation time (Tempo di lavoro medio di un cassiere considerando anche gli intervalli di tempo in cui non ci sono clienti in fila)
- average loss of customers (due to too large queue)



## Model



### Assumptions



## Validation

## Factors

## Simulation Tool

## Implementation

## Verification of the Implemented Simulation Model

## Factors Calibration

## Experiments Design

## Simulation Run

## Results Analysis

## Conclusions


# Other

## Parameters
- T Distribution
- M Distribution
- A (pAtience) Distribution
- Total number of tills

## Factors
- p: percentage of quick-checkout tills, where a customer can be served if his (her) cart holds less than K items;
- K **ask to Prof. Nardini if it is a Factor instead, because the text it isn't clear enough**.



## Osservazioni ITA
La lognormale essendo solo positiva si presta a quelle cose che valgono solo per distribuzioni positive.

Quando andremo a vedere il load balancing dinamico ci potrà tornare utile per la questione del nodo di bilanciamento relativo ai due sottosistemi M/M/C che compongono il nostro sistema completo.
Avremo in ingresso a ciascun sottosistema un certo inter-arrival time funzione di T, K e tipo di distribuzione che ha T.

Classifier in Omnet++ per nodo probabilistico.
