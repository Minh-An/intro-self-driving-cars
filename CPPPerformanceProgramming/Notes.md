# C++ Optimization 

## Testing Code W/ Standard Clock 
```C++
#include <ctime>

std::clock_t start;
double duration;

start = std::clock();

function_name(var1, var2);

duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

std::cout << "duration milliseconds initialize beliefs " << 1000 * duration << '\n';
```
- measures in terms of clock ticks, then divides by clock ticks per sec to get time in terms of sec 

## Techniques 
### Remove Dead Code 
- remove code that's no longer used b/c it'll still be read by CPU 
### Avoid Extra if Statements 
- use else statements instead of if statements when possible
```C++
int x = 5;
if (x >= 5) {x = x + 1;}
if (x < 5) {x = x - 1;}
```
#### If Statements on the CPU
There's one other aspect of if statements that you don't have much control over when using a high level language like C++. The CPU also tries to optimize if statement calculations by running simultaneous calculations.

When running a calculation, the CPU can look ahead and start working on another calculation in parallel. In terms of if statements, the CPU will try to predict which branch will be taken next and starts running the calculations inside the predicted branch. When it's time to evaluate the logical expression, the CPU might realize that it made a bad prediction. If the prediction is wrong, the predicted calculation stops and the CPU starts running the correct calculation.

So be aware that you might not get too much of a time boost when rearranging or eliminating if statements. Both the compiler and the CPU are already trying to optimize these operations for you.
### Avoid Nested For Loops 
- sometimes they're necessary, but if you need less than i x j iterations, avoid nested for loops 
### Avoid Creating Extra Varaibles 
- not much of a performance boost when it is a simple type
- having duplicates of a larger var like a VECTOR -> more memory writes -> slower code 
### Reserve Space in Memory for Vectors 
- C++ vectors are inefficient in terms of exec time 
- vectors reserve space in case it expands 
- if size > reserved memory -> reserved memory duplicates and the vector is copied to a different place in memory 
- to reserve specific number: 
``` C++ 
std::vector<int> foo;
foo.reserve(15);
```
### Passing Vars by Reference 
- faster than copying entire 
#### Using Static 
- instead of more copies 