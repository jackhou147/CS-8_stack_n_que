#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H
/*
 *
 * ***** ALL RESULTS ARE VERIFIED ******
 *
 *
 *
 *
//-------------------------------
// STACK
//-------------------------------

s: [9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||

s2: [9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||

{ 9 } [8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||

{ 8 } [7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||

{ 7 } [6]->[5]->[4]->[3]->[2]->[1]->[0]->|||

{ 6 } [5]->[4]->[3]->[2]->[1]->[0]->|||

{ 5 } [4]->[3]->[2]->[1]->[0]->|||

{ 4 } [3]->[2]->[1]->[0]->|||

{ 3 } [2]->[1]->[0]->|||

{ 2 } [1]->[0]->|||

{ 1 } [0]->|||

{ 0 } |||

assigning s2 back into s: s: [9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||

s2: [9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||





//-------------------------------
// QUEUE
//-------------------------------

q: [0]->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||

q2: [0]->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||

{ 0 } [1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||

{ 1 } [2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||

{ 2 } [3]->[4]->[5]->[6]->[7]->[8]->[9]->|||

{ 3 } [4]->[5]->[6]->[7]->[8]->[9]->|||

{ 4 } [5]->[6]->[7]->[8]->[9]->|||

{ 5 } [6]->[7]->[8]->[9]->|||

{ 6 } [7]->[8]->[9]->|||

{ 7 } [8]->[9]->|||

{ 8 } [9]->|||

{ 9 } |||

assigning q2 back into q: q: [0]->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||

q2: [0]->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||



//-------------------------------
// GENERAL TESTING FOR STACK
//-------------------------------

: outputting an empty stack
: |||

: calling the copy constructor with source being empty
: |||

: calling assignment operator with source being empty
: |||

: popping from empty stack
Assertion failed: (head), function delete_head, file ../StackNQue/node.h, line 176.

: accessing the front of an empty stack
Assertion failed: (pos), function operator*, file ../StackNQue/list.h, line 66.

: push item to empty stack then access its top
: 1

: assigning an empty stack to a non-empty stack
: destination:
: |||

: source:
: |||

: Stack of other other data types

: Stack of strings
: [Jack]->[is]->[a]->[Genius]->|||

: Stack of Queues
: que 1:
: [J]->[a]->[c]->[k]->|||

: que 2:
: [g]->[e]->[n]->[i]->[u]->[s]->|||

: stack of que 1 + que 2
: [[J]->[a]->[c]->[k]->|||
]->[[g]->[e]->[n]->[i]->[u]->[s]->|||
]->|||

//!--- note: the above formatting may look weird due to
//! line breaks. This is as expected, not a bug. To modify
//! or delete the line breaks, change the insertion operators
//! located in file que.h and file stack.h.







//-------------------------------
// GENERAL TESTING FOR QUEUE
//-------------------------------

: outputting an empty queue
: |||

: calling the copy constructor with source being empty
: |||

: calling assignment operator with source being empty
: |||

: popping from empty que
Assertion failed: (head), function delete_head, file ../StackNQue/node.h, line 176.

: accessing the front of an empty queue
Assertion failed: (_head), function front, file ../StackNQue/que.h, line 99.

: push item to empty queue then access its front
: 1

: assigning an empty queue to a non-empty queue
: destination:
: |||

: source:
: |||

: Queue of other other data types
: Queue of strings
: [Jack]->[is]->[a]->[genius]->|||


//-------------------------------
// GENERAL TESTING FOR LIST
//-------------------------------
: outputting an empty list
: |||

: calling the copy constructor with source being empty
: |||

: calling assignment operator with source being empty
: |||

: accessing the top  of an empty list
Assertion failed: (pos), function operator*, file ../StackNQue/list.h, line 66.

: accessing the end of an empty list
Assertion failed: (pos), function operator*, file ../StackNQue/list.h, line 66.

: push item to empty list then access its top AND end
: top:
: 1
: end:
Assertion failed: (pos), function operator*, file ../StackNQue/list.h, line 66.
//!--NOTE: ABOVE BEHAVIOR(ASSERTION FAIL) IS AS EXPECTED. SEE MORE IN z_work_report.h

: assigning an empty list to a non-empty list
: destination:
: |||
: source:
: |||


*/
#endif // Z_OUTPUT_H
