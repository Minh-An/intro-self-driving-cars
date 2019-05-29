# Bayesian Thinking

## Overview
- Allows for uncertainty 
- Core of stats 
- Project Zero
- Basic + Conditional Probability 
- Bayes’ rule 
- Probability distributions 
- Localization
- Project 1 -> 2D histogram filter, implementing localization

## Probability: 
- Uncertainty in every part of the car 
- Learning Objectives:
  - Independent Events 
  - Data -> Stats -> Causes
  - Data <- Prob <- Causes 

## Conditional Probability:
- P (A | B) - probability of A GIVEN B
  - Sensor measurement of data to make better estimates 
  - = P(A, B) / P(B)
- P(A) - prob of A
- P(-A) - prob of NOT A
- P(A, B) - prob of A AND B
- P(A) = P(A|C) * P(C) + P(A|!C) * P(!C)
- NEXT: P(C|A)???

## Bayes' Rule 
- Given init prediction, we can improve that init prediction with more information 
  - GPS, more data: sensor data 
### Sensors: 3 Main Types
    - Camera (video)
    - Lidar (light based)
    - Radar (radio waves)
    - detect objects + scenery
    - Internal sensors: speed/direction of car, wheel orientation, internal temp

- Example: if wheels are turning to the right, located at curved section of road 
- **Bayes' Rule: mathematical way to correct measurements**
- Not only used to incorporate sensor data, also used for medical diagnosis
- "Holy Grail" of Probabilistic Inference 

### Example
- P(Cancer) = .01
- Test: 90% positive if you have C 
  - SENSITIVITY
- Test: 90% neg if don't have C
  - SPECITIVITY
- Question: P(C|P)?
- **Bayes' Rule: prior probability * test evidence = posterior probability**
- PRIOR = P(C) = .01
- ~~POSTERIOR~~ / **JOINT** =
  -  **P(C,P)** = P(C) * P(P|C) = .01 * .9 = **.009**
  - **P(!C,P)** = P(!C) * P(P|!C) = .99 * .1 = **.099**
- Normalize: 
  - STEP 1: Sum of 2 vals : .009 + .099 = **.108 = P(P)**
  - POSTERIOR
    - P(C|P) - .009 / P(P) (.108) = .0833333
  - Will work with negative as well!

Summary: ![Bayes' Rule Summary](images/bayes.png)

## Probability Distributions 
- way in which self-driving car represents its internal beliefs about the world 
- **mathematical way to represent uncertainty across all possible outcomes**
- can be visualized using a graph esp in 2D cases 
- examples:
  -  tells most/least likely locations of cars 
  - rep. uncertainty in sensor measurements
### Types 
- discrete vs continous 
- ![](images/distributions.png)
#### Discrete Variables 
- can only take on certain values (usually countable var)
- ex: coin flips/dice roll
#### Continuous Varaibles
- ex: temp
- can take on decimal values 
- use some sort of instrument to measure them 
- can't associate counts with them 
### Discrete Probability Distribution 
- example: how many times a coin -> heads
- x-axis: outcomes (0-3 times heads)
- y-axis: probabili8ty 
- y-axis >= 0
- sum of all y-axis = 1
### Continous Probability Distributions 
- Probability over a continous range is almost zero (since there are so many values)
- Every outcome has probability 0
- Probabilities are over a range 
- P(a<x<=b) = |b-a|/range
#
- x-axis: unbroken line across range 
- y-axis: "probability density function"
  - doesn't rep. P directly
  - the area underneath the curve rep. P
#### Characteristics of a Continuous Distribution
- y values >= 0
- P(x) = 0
- P(a<x<=b) = area under the curve
- total area under curve = 1
#### Uniform Contineous Distribution 
- area forms a rectangle (base x height = prob)
  
  