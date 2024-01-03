# A PECSN' project


## Description

## Objectives


Our main objectives for this study are two:

1. Find the best configuration of K and p given a realistic workload (i.e. inter-arrival time and number of items in a customer's cart) so that the average waiting time and the average response time are minimized.

2. Prove that, at the steady-state, the performance indexes of the system in the optimal configuration (found in the point 1.) are similar when the classifier implements the join the shortest queue policy (dynamic load balancing) and when the classifier implements the equally likely policy (static load balancing).

Analizzare il comportamento delle code sia in termini di dimensioni che in termini di tempo di attesa per 
ogni cliente.

Dimostrare che, allo Steady State, gli indici di performance di un sistema che implementa la policy di join the shortest queue (dynamic load balancing) tendono a quelli in cui la probabilità di routing è equa per ogni nuovo arrivo (i.e. 1/numero code), al variare di p e K.

## Key Performance Indices (KPIs)

### Main
The main objectives of this study are comparing the:
- Waiting time per la singola coda ed anche riferito ai due sottosistemi
- Numero medio della dimensione di code nel sottosistema delle code veloci e in quello delle code normali
- il Throughput


### Other KPIs
- routing probability inside the two subsystems
- Utilizzazione del sistema complessivo

## Model
Come si può vedere dal modello disegnato, il sistema che viene considerato all'interno delle specifiche viene schematizzato come vari sottosistemi M/M/1 in parallelo. Nello specifico possiamo distinguere due sottoinsiemi composti da SCs diversi, il primo riservato ai clienti con M<=K oggetti definito "Casse Veloci" ed il secondo atto ad accogliere tutti gli altri clienti (i.e. M>K).
La percentuale di casse viene suddivisa tra i due sottosistemi secondo al parametro p, che va ad indicare la percentuale di casse veloci rispetto al totale di casse del sistema.

![Model of the System](Resources/Model.jpg)


### Assumptions
All'interno delle assunzioni bisogna nominare le seguenti:

- La dimensione delle code è infinita e le persone mettendosi in coda non possono superare la gente di fronte a loro (FIFO).
- Non è possibile abbandonare una coda una volta che ci si è entrati
- Un cliente con pochi oggetti può solamente accodarsi in code veloci
- La probabilità di routing all'interno dei due sottosistemi individuati è equa (1 / numero di casse del sottosistema). E' da dimostrare che tale static load balancing perfetto porti ad una situazione simile a quella che si avrebbe in caso di dynamic load balancing, ove il cliente venga instradato nella coda con il numero minore di persone in coda.
- All'interno di una simulazione non è possibile modificare il numero p di casse veloci nè tantomeno vengono aggiunte nuove casse sotto situazioni di carico intenso.
- Idle time in caso di coda piena è pari a 0. Il cassiere inizia subito a servire il prossimo cliente nella coda (se presente) dopo la partenza del precedente cliente

Considerando le assunzioni sopra indicate è possibile formalizzare le probabilità $\pi_i$ che compaiono nella Figura X relativa al modello:
Ipotesi:
- Lo stato del sistema corrisponde con il numero di clienti in coda.
- $C$ numero di casse complessivo del sistema
- $p$ percentuale di casse veloci
- $(1-p)$ percentuale di casse normali
- $C\cdot p$ numero di casse veloci all'interno del sistema
- $C\cdot (1-p)$ numero di casse normali
- $\alpha(K) = P\{ M\leq K\}$ probabilità che un cliente abbia meno, o al più, K oggetti e conseguentemente esprime la probabilità di un cliente di essere routato sul primo sottosistema.

A questo punto possiamo scrivere che:

$$\left\{\begin{matrix}
 \pi_i = \frac{\alpha}{C\cdot p} & \ \ 0\leq i \leq r \\[10pt] 
 \pi_j = \frac{(1-\alpha)}{C\cdot (1-p)} & \ \ r+1\leq j \leq n
\end{matrix}\right.$$


Bisogna scrivere anche che ci si mette in coda nella coda con meno persone ma non si conta se in una coda ci sono 0 persone e qualcuno viene servito. Dunque una coda con 0 persone e con qualcuno in fase di pagamento viene vista allo stesso modo di una coda con 0 persone e nessuno in fase di pagamento.
In più nel nostro modello le persone con pochi oggetti possono andare solo nelle code veloci e NON in quelle con molti oggetti...! Aggiungere queste osservazioni nelle assumptions.



## Validation
AKA Common Sense Validation:
Prima di passare all'implementazione del modello teorico bisogna cercare di validare il modello considerando un sistema reale. E' chiaro che considerando un qualsiasi supermercato (tranne il CarreFour di Lucca) risulta che le assunzioni fatte non sono poi così drastiche perché:

1. Anche in un sistema reale succede che la dimensione delle code in un supermercato non ha un limite prefissato, infatti i clienti potrebbero accodarsi all'interno di tutte le corsie in cui vengono venduti i prodotti. In più i clienti seguono una policy FIFO perché il cliente che si è messo per primo in fila difficilmente farà passare altra gente di fronte a lui.
2. Una volta che una persona è in fila con i propri oggetti nel carrello non lascerà mai il carrello pieno ed uscirà dal supermercato.
3. Se un cliente ha pochi oggetti preferirà sempre andare nelle code veloci per sbrigarsi prima.

****
- La probabilità di routing all'interno dei due sottosistemi individuati è equa (1 / numero di casse del sottosistema). E' da dimostrare che tale static load balancing perfetto porti ad una situazione simile a quella che si avrebbe in caso di dynamic load balancing, ove il cliente venga instradato nella coda con il numero minore di persone in coda.
****

5. Consideriamo solamente il caso a regime (in cui tutte le casse del supermercato sono già aperte ed è impossibile creare una nuova cassa perché non esiste) di un supermercato in cui non vengono aperte nuove casse (e nemmeno chiuse).
6. Se il cassiere ha clienti in fila non si ferma per prendersi una pausa.


## Factors
Considering the factors here we have:

- p: percentage of quick-checkout tills;
- K: maximum number of items that a customer can have in his (her) cart to be served in a quick-checkout till;
  
## Parameters
When we consider the parameters we have:

- $C$ total number of tills;
- Distribution of the inter-arrival time of customers:
  - Exponential:
    - rate T;
- Distribution of the number of items in a customer's cart:
  - Exponential:
    - rate M;
  - Lognormal:
    - mean M;
    - standard deviation $\sigma$;


## Simulation Tool
The simulation tool used for this project is Omnet++. 

## Implementation
To implement the theoretical model we will consider the following modules:

- **Source**: generates customers according to the inter-arrival time distribution;
- **Local-Sink**: represents a till;
- **Queue**: represents the queue of a till;
- **Global-Sink**: collects statistics about the simulation run.
- **LoadBalancer**: represents the load balancer that routes the customers to the two subsystems.


## Verification of the Implemented Simulation Model





Aggiungendo 1 come cambia il Service time? Peggiora di molto? E se condizioni stabilità si modificano?

If you add a constant \( c \) to each observation, the mean of the new distribution will be the sum of the original mean and the constant:

\[ \text{New Mean} = \text{Original Mean} + c \]

In general, adding a constant to every observation of a random variable increases the mean by that constant.


### Consistency Test
The consistency test that we performed is the following: we halved both the inter-arrival time ($T$) and the mean number of items in a customer's cart ($M$) and we saw that the waiting time in each queue was halved too (maybe in the plot we could show the behaviour of only one queue, or as another possibility we could plot the behaviour of the overall system but i don't know if doing so the behaviour in the different configurations is the same). The distributions used for the inter-arrival time and the number of items in a customer's cart were both exponential. To support this test we have also performed some theoretical considerations. In our system the service time of each till is given by $S = M\cdot 3s$. So, when we halve the mean number of items in a customer's cart, the service time is halved too. At this point it remains to show that in M/M/1 the waiting time is halved when both the inter-arrival time and the service time are halved (or if you prefer when the inter-arrival rate and the service rate are doubled). We do this in the following example.

Let $T$ and $S$ be the inter-arrival time and the service time of an M/M/1, respectively:

- $T = \frac{1}{2}$

- $S = \frac{1}{4}$

Taking their reciprocals we obtain the arrival rate $t$ and the service rate $s$:

- $t = \frac{1}{T} = 2$

- $s = \frac{1}{S} = 4$

```
         -----
t=2 ----      | --> O
         -----    s=4
```

The performance indexes in this case are the following:

- $\rho = \frac{t}{m} = \frac{2}{4} = \frac{1}{2}$

- $E[N] = \frac{\rho}{1-\rho} = \frac{ \frac{1}{2} }{ 1-\frac{1}{2} } = 1$

<!--$$E[R] = \frac{E[N]}{t} = \frac{1}{2}$$-->

- $E[N_q] = E[N] - \rho = 1 - \frac{1}{2} = \frac{1}{2}$

- $E[W] = \frac{E[N_q]}{t} = \frac{ \frac{1}{2} }{2} = \frac{1}{4}$

Now by halving the inter-arrival time and the service time we obtain:

- $T' = \frac{T}{2} = \frac{1}{4}$

- $S' = \frac{S}{2} = \frac{1}{8}$

This translates into doubling the arrival rate and the service rate:

- $t' = 2\cdot t = 4$

- $s' = 2\cdot s = 8$

```
          -----
t'=4 ----      | --> O 
          -----   s'=8
```

Now the performance indexes are the following:

- $\rho' = \frac{t'}{m'} = \frac{4}{8} = \frac{1}{2}$

- $E[N]' = \frac{\rho'}{1-\rho'} = \frac{ \frac{1}{2} }{ 1-\frac{1}{2} } = 1$

<!-- - $E[R]' = \frac{E[N]'}{t'} = \frac{1}{4}$-->

- $E[N_q]' = E[N]' - \rho' = 1 - \frac{1}{2} = \frac{1}{2}$

- $E[W]' = \frac{E[N_q]'}{t'} = \frac{ \frac{1}{2} }{4} = \frac{1}{8} = \frac{E[W]}{2}$

We can clearly see that here the waiting time is halved.

After this considerations we proceeded in the following way.

We set the number of repetitions $n$ to be equal to 50 (i.e. greater than 30). We run the simulation for 24 hours (of sim-time) using different configurations of $T$ and $M$. In each of them we set $K$ in a way that the percentage of customers routed to the quick-checkout tills is the same (i.e. 33%). Referring to the previous defined quantity $\aplha(K)$, we set $K$ in a way that $\alpha(K) = 0.33$. At this point we proposed the following configurations:

- Slow Behaviour Experiment:
  - T = 60
  - M = 40
  - K = 16

- Balanced Behaviour Experiment:
  - T = 30
  - M = 20 
  - K = 8

- Fast Behaviour Experiment:
  - T = 15  
  - M = 10
  - K = 4

Now we can show the plot that we have obtained for the different queues among the different configurations. Here we can see the behaviour that we proved before in the mathematical considerations, that is: when considering two consecutive configurations, we see that the waiting time in each queue is halved.

<!---->
<!-- ![Plot of the different queues](Resources/Plot.png) -->


## Degeneracy Test(s)

Here we propose different tests to assess the behaviour of the system in borderline cases. In all the tests we will consider the following parameters:
M = 20 
T = 30
C = 4
(balanced configuration)
Both Exponential

In all these tests we will consider the Mean number of customers in queue.


1. K = 0 (i.e. unused quick-checkout tills)
p = 0.5
Running 100 simulations we saw that in both queues[0] and queues[1] (i.e. quick-checkout tills) the max value of the samples was 0. This means that in both queues there were no customers at all. This is because all the customers had more than K items in their cart and so they were routed to the normal-checkout tills.


2. K = 1000 (negligible probability of being served in a normal-checkout till).
p = 0.5
Again, running 100 simulations we saw that in both queues[2] and queues[3] (i.e. normal-checkout tills) the max value of the samples was 0. This means that in both queues there were no customers at all. This is because all the customers had less than K items in their cart and so they were routed to the quick-checkout tills.


3. p = 0 (i.e. no quick-checkout tills)

K = NA (not applicable) NO!!! K = 0 sennò va tutto in coda 0!!!!

FARE PROVA CON K = 1000 e vedere se va tutto in coda 0!!!

Problema risolto perché int(exp) mi fa generare roba con 0 oggetti e quindi va tutto in coda 0!!! (vedi codice classifier) provare a risolvere questo problema con ceil per non modificare mean value dell'exp sennò aggiungendo 1 si modifica la media e quindi bisognerebbe sottrarre 1 alla media per non modificare il valore medio della distribuzione.


[[Here will have Nq less than case 1. because we will have 2 more normal-checkout tills (C is fixed to be equal to 4 in both cases).]]
100 simulations.
In this case as we could imagine, the mean number of customers in queus is lower (really low and below 1 indeed) and if compared with the case 1 (K=0 and p=0.5) we have that the mean number of customers in every queue of this configuration is lower than the mean number of customers in the two queues of the previous configuration. This is because in this case we have 4 normal-checkout tills instead of 2 normal-checkout tills and 2 quick-checkout tills that were unused. So we have more tills and so the mean number of customers in queue is lower.


4. p = 1 (i.e. only quick-checkout tills)
K = 1000 (negligible probability of being served in a normal-checkout till) because otherwise we will have an error thrown when the classifier tries to route a customer to a normal-checkout till. In this situation compared to the 2nd case we will have an analogous behaviour as the one described in the previous case. If instead we compare this situation with the 3rd case we will have an equal behaviour because in both cases we have only 4 tills. Note that the service time by a quick-checkout till and a normal-checkout till is the same. And by not having different type of tills we will have the exactly the same behaviour.


Sistemare commenti su!

## Continuity Test
Here we consider the base configuration (i.e. again the balanced configuration) and we try to see how the system behaves when we slightly change T.
Base configuration:
  - T = 30
  - M = 20 
  - K = 8
  - C = 4

By slightly increasing T we expect to see the Total Queueing time as seen by the global sink, decreasing. This is because by increasing T we will have less customers in the system and so the Total Queueing time will decrease.
We try this by increasing T by 1. The last configuration will be when T = 35.
For each configuration we run 50 simulations.



Verification against the theoretical model
When we verify the implemented model against the theoretical model we have to consider the "equallylikely" configuration of the classifier, because in the theoretical model that we proposed the load balancing is static and not dependent on the actual state of the system. For this reason we considered the case where inside a subsystem (quick or normal tills) the probability to be routed in a till is the same.

The configuration that we consider in the simulator is the following:
- C = 4
- p = 0.5
- T = 30 --> $t = \frac{1}{30}$
- M = 20 --> $m = \frac{1}{20}$
- K = 8 
- $\alpha(K) = 0.33$

The service time of a till is given by $S = M\cdot 3s$.
So the service rate is given by $s = \frac{1}{S} = \frac{1}{M\cdot 3s} = \frac{1}{20\cdot 3s} = \frac{1}{60s}$.

Now we can compute the probability of a customer to be routed in particular a quick-checkout till and in a normal-checkout till. We have that:


Quick-checkout till ($0\le i \le 1$):
$\pi_i = 0.165$

Here we have that the rate in input is given by:
$t_i = t*\pi_i = \frac{1}{30}\cdot 0.165 = \frac{1}{182} = 0.0055$ 

The service rate is the same:
$s_i = s = \frac{1}{60}$

So in these cases the performance indexes are the following:

$\rho_i = \frac{t_i}{s_i} = \frac{0.0055}{\frac{1}{60}} = 0.33$
$E[N_i] = \frac{\rho_i}{1-\rho_i} = \frac{0.33}{1-0.33} = 0.5$
$E[N_{q_i}] = E[N_i] - \rho_i = 0.5 - 0.33 = 0.167$
$E[R_i] = \frac{E[N_i]}{t_i} = \frac{0.5}{0.0055} = 90$
$E[W_i] = E[R_i] - \frac{1}{s_i} = 90 - 60 = 30$


Normal-checkout till ($2\le j \le 3$):
$\pi_j = 0.335$ 

Here we have that the rate in input is given by:
$t_j = t*\pi_j = \frac{1}{30}\cdot 0.335 = \frac{1}{89} = 0.0112$

The service rate is the same:
$s_j = s = \frac{1}{60}$

So in these cases the performance indexes are the following:
$\rho_j = \frac{t_j}{s_j} = \frac{0.0112}{\frac{1}{60}} = 0.67$
$E[N_j] = \frac{\rho_j}{1-\rho_j} = \frac{0.67}{1-0.67} = 2$
$E[N_{q_j}] = E[N_j] - \rho_j = 2 - 0.67 = 1.33$
$E[R_j] = \frac{E[N_j]}{t_j} = \frac{2}{0.0112} = 180$
$E[W_j] = E[R_j] - \frac{1}{s_j} = 180 - 60 = 120$



buttare via i signal che non uso fare tutto in funzioe di s e rho. + fare formula condizionata con denominatore = P{1<=X<=8}


Togliere round togliere +1 e tutto... mettere anche double clienti...





Discrete Case:

M = 20

M' = 19

M = M' + 1
M' = M -1
F_M(K) - F_M(1) = P{1<=M<=K} = P{M<=K} - P{M<=1} = P{M'+1<=K} - P{M'+1<=1} = P{M'<=K-1} - P{M'<=0} = P{M'<=K-1} = F_M'(K-1)

F_M'(K-1) = 1-e^(-(K-1)/(M-1)) = 1-e^(-(K-1)/(M'))

7 = K-1
x = [0,7]
round(x) = floor(x+0.5)
round(x+1) = floor(x+1+0.5)
x = [1,2,...,8]

[0...., 7.5]
+1
[>0.5,.... 8.5]
round()
[1...... 8]


$$X$$
$$g(X) = round(X+1)$$
$$g(X) = floor(X+1+0.5)$$
$$E[X|P\{M\leq K\}]_i = \frac{1}{P\{M \leq K\}} \int_{0}^{K-0.5} g(x) f_X(x) dx =$$
$$\frac{1}{P\{M \leq K\}} \int_{0}^{K-0.5} floor(x+1+0.5) \frac{1}{M-1}e^{-\frac{x}{M-1}}$$
$$E[X|P\{M> K\}]_j = \frac{1}{P\{M> K\}} \int_{K-0.5}^{+\infty} floor(x+1+0.5) \frac{1}{M-1}e^{-\frac{x}{M-1}}$$

$$Var(X) = E[X^2] - (E[X])^2$$

$$l(x)=x^2$$
$$l(g(x))=(g(x))^2= (floor(x+1+0.5))^2$$

$$E[X^2 |P\{M> K\}]_j = \frac{1}{P\{M> K\}} \int_{K-0.5}^{+\infty} (floor(x+1+0.5))^2 \frac{1}{M-1}e^{-\frac{x}{M-1}}$$


https://en.wikipedia.org/wiki/Truncated_distribution



### Verification against the theoretical model


### Lognormal Distribution
Here we consider the case where the distribution of the number of items in a customer's cart is lognormal. We consider the following parameters:

$sT = 3$

M is a random variable with a lognormal distribution with parameters $\mu$ and $\sigma^2$.

The PDF of M is given by:

$f_M(m) = \frac{1}{m\sigma\sqrt{2\pi}}e^{-\frac{(\ln(m) - \mu)^2}{2\sigma^2}}$


Mean Service Time
$E[t_s] = sT * E[M] = sT * e^{\mu + \frac{\sigma^2}{2}}$

Variance of the Service Time
$Var(t_s) = Var(sT * M)= sT^2 * (e^{\sigma^2} - 1) * e^{2\mu + \sigma^2}$

For computing the parameters $\mu$ and $\sigma^2$ we use:

$\mu = \ln(\frac{E[M]^2}{\sqrt{Var(M) + E[M]^2}})$

$\sigma^2 = \ln(1 + \frac{Var(M)}{E[M]^2})$


## Factors Calibration

We have to tune the simulation parameters so that scenarios are realistic. Considering the information reported in (https://homafiles.info/2009/08/20/how-long-do-you-wait-in-line-to-checkout-at-the-supermarket/) we can see that there is stated that:

    Supermarket lines may not be the longest, just the most loathed. Two years ago, in 20 out of 25 major U.S. cities, the average wait time at grocery stores was under five minutes.

So we consider the worst case where the average waiting time is 5 minutes. At this point by imposing that the average wait time is 5 minutes we can compute the other parameters.


Average waiting time
$E[W] = 5m = 300s = E[R] - E[t_S]$

Average number of items in a customer's cart
$E[M] = 30items$

Service Time for item $3s$

Mean Service Time
$E[t_S] = 3s * E[M] = 3s * 30 = 90s$
$E[t_S] = \frac{1}{s} = \frac{1}{90s}$ (Exponential Distribution of the number of items in a customer's cart)

Average Response Time
$E[R] = E[W] + E[t_S] = 300s + 90s = 390s$


In our everyday life the mean number of tills in a supermarket that we visit for buying groceries is 10. So we fix the parameter C to be equal to 10.

For computing the upper bound of the inter-arrival rate we can consider the formula for the stability of an M/M/C.

$\rho = \frac{t}{C\cdot s} < 1$
$t < C\cdot s = 10 \cdot \frac{1}{90s} = \frac{1}{9}$
$9 < \frac{1}{t}$
$9 < T$
$T > 9s$

This is the lower bound for the inter-arrival time.
If T = 20s 

For choosing a right value for the parameters at this point we can consider the simplified case where there are only normal-checkout tills. In the next phase of experiments design we will introduce the quick-checkout tills and we will see how the systems behaves. We however expect to see the averge waiting time to decrease because customers with few items in their cart will be routed to the quick-checkout tills and so the average waiting time of the overall system will decrease. So we start from the situation where without quick-checkout tills the average waiting time is 5 minutes. For finding the right value of T we start from the minimum possible and we increase this value by 5 until we reach the situation where the average waiting time is 5 minutes. So let's do this.

C=10
p=0
K=0

T = [10, 15, 20, 25, 30, 35, 40]

But we obtained that when T = 120 the average waiting time is 120s so we decided to do a step back and consider a smaller interval that is always above 9, but less than 10. So we consdered:

T = [9.1, 9.2, 9.3, 9.4, 9.5, 9.6, 9.7]

At this point we can see that when T is between 9.2 and 9.3 we cover the 5 minutes of average waiting time. So we can consider a smaller interval that is always above 9.2, but less than 9.3. So we considered:

T = [9.23, 9.24, 9.25, 9.26, 9.27]

Now we choose the value of T to be 9.26 because the mean value of the waiting time is 300s (5 minutes) with the CI we do not go too far from this value. So we can consider T = 9.26.


p = [0.1,0.2,0.3,0.4,0.5]
K = [9,10,11,12,13,14,15,16,17,18,19,20,21]


E[M] = 30
Var(M) = 900 = 1/s^2  = 1/(1/30)^2 = 30^2 

$\mu = \ln(\frac{E[M]^2}{\sqrt{Var(M) + E[M]^2}})$
$\sigma^2 = \ln(1 + \frac{Var(M)}{E[M]^2})$

mu = 3.055
sigma = 0.833


### Warmup-Period and Simulation Time
Now when talking about the estimation for the warmup-period we have to consider another index, because considering the mean waiting time we saw that it was unstable due to the fact that it can assume many times the value 0. For this reason we focus on the mean service time at each till.

Running the simulation for 24 hours (sim-time) and plotting the Time average of the mean service time at each till we obtain the following plot.

![Plot of the Time average of the mean service time at each till](../Implementation/Calibration/Before_WarmupPeriod.svg)

Observing the plot we can see that after the first 10'000s the mean service time surpasses the intial transient beginning to stabilize around the value that it will reach at the steady-state. So we can consider the warmup-period to be equal to 10'000s.

At this point it is also clear that 24 hours (sim-time) are too much for the simulation. So we reduce the total simulation time of each run to 16 hours (i.e. 57'600s) that would be enough for the next phases. A mapping to the reality would be a supermarket that is open from 7:00 to 23:00 (i.e. 16 hours). 


## Experiments Design

Having only 2 factors (p and K) we can consider a full factorial design. So we consider the following configurations:

T = 9.26
M = 30
C = 10

p = [0.1, 0.2, 0.3, 0.4, 0.5]
K = [9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21]

p = ${0.1, 0.2, 0.3, 0.4, 0.5}
K = ${9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21}

Further studies:


p = [0.1,0.2,0.3]
K = [13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32]
p = ${0.1,0.2,0.3}
K = ${13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32}



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


M/M/1


$$\rho < 1$$
$$\rho = \frac{\lambda}{\mu}$$
$$\lambda < \mu$$

$$\lambda < \frac{1}{S}$$

$$\frac{1}{\lambda} > S$$

$$S < \frac{1}{\lambda}$$

$$M \cdot 3s < \frac{1}{\lambda}$$

$$M < \frac{1}{\lambda} \cdot \frac{1}{3s}$$

$$M < \frac{T}{3s}$$

$$T > 3s\cdot M$$


Rate in ingresso a ciascun SC:
Per soddisfare la condizione di stabilità del sistema, tutti i singoli SC devono essere stabili. In questo caso basta che la condizione sia soddisfatta per una qualsiasi cassa normale, e di conseguenza tutte le altre saranno stabili.

$$\pi_j = \frac{(1-\alpha)}{C\cdot (1-p)}$$
$$\pi_j = \frac{(1-0.33)}{4\cdot (1-0.5)}$$
$$\pi_j = \frac{0.67}{4\cdot 0.5}$$
$$\pi_j = \frac{0.67}{2}$$
$$\pi_j = 0.335$$

$$\lambda_j = \lambda \cdot \pi_j$$
$$\lambda = \frac{1}{T}$$
$$\lambda_j = \frac{1}{T_j}$$
$$\frac{1}{T_j} = \frac{1}{T} \cdot \pi_j$$
$$T_j = \frac{T}{\pi_j}$$

$$T_j > 3s\cdot M$$
$$\frac{T}{\pi_j} > 3s\cdot M$$
$$T > 3s\cdot M \cdot \pi_j$$

p = 0.5
M = 40
C = 4
alfa = 0.33

$$T > 3\cdot 40 \cdot 0.335 = 40.2$$



