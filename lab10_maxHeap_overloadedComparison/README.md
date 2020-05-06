# LAB 10
 For this program I built a maxHeap.
 * MaxHeap is implemented to simulate a basic hospital patient queue
 * maxHeap uses default comparison, not coupled to type of objects inside
   * overloaded patient object comparison operators to order patients in BST by illness severity level 
   * Arrival order is used to break ties in severity

## Topics:
  * Max Heap
  * Overloaded comparison operators

## Input:
File name passed in at execution time. 
### File format
One command per line
#### Valid Commands:
    * ARRIVE <first name> <last name> <age> <illness> <severity>
      * A patient arrives to the waiting room, to be placed in the maxHeap
    * COUNT 
      * Prints the number of patients waiting to be seen
    * NEXT
      * Prints the info of the patient next to be seen(name,age,illness,severity)
    * TREAT
      * Treats the next patient to be seen, removes from maxHeap

## Example run:
With contents of input.txt as:
```
ARRIVE Lydia Johnson 37 sleep_deprivation 1
ARRIVE Grant Johnson 0 cries_at_night 2
ARRIVE Grigori Rasputin 47 everything 9
COUNT
NEXT
TREAT
NEXT
TREAT
COUNT
```
./lab10 input.txt
```
There are 3 patients waiting to be seen.

Next patient:
	Name: Rasputin, Grigori.
	Age: 47
	Suffers from: everything
	Illness Severity: 9

Next patient:
	Name: Johnson, Grant.
	Age: 0
	Suffers from: cries_at_night
	Illness Severity: 2

There are 1 patients waiting to be seen.
```
