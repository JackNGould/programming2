# LAB 05
 This program involves the creation of a templated, node-based singly linked list. It derives from an interface.
  A linkedList is used to crudely simulate the history functionality of a web browser.

## New Topics:
  * LinkedList - singly linked. Node based. templated.

## Input:
  * Input file passed in at runtime.
  * One command per line. 
### Valid Commands:
   * NAVIGATE <URL>
     * Navigates browser to URL. Retains history that would've been accessible with BACK, but FORWARD history is lost from the previous spot onwards.
   * BACK
     * Navigates the browser 1 URL back in history
   * FORWARD
     * Navigates the browser 1 URL forward in history
   * HISTORY
     * Prints the URL history to the screen
## Example run
With Contents of input.txt:
```
NAVIGATE http://wikipedia.com
NAVIGATE http://reddit.com
NAVIGATE https://github.com
NAVIGATE http://myspace.com
bad input
HISTORY
BACK
BACK
HISTORY
FORWARD
FORWARD
FORWARD
FORWARD
HISTORY
BACK
BACK
NAVIGATE https://sony.com
NAVIGATE https://apple.com
BACK
NAVIGATE https://google.com
FORWARD
HISTORY
BACK
HISTORY
```
Sample execution:
```
~/Downloads/programming2/lab05_browser_singlyLinkedList:./lab05 input.txt
```
Output to Screen:
```
./lab05 input.txt

Looking for valid input lines...

Line #5 - "bad input" could not be interpreted as a valid command.
Consult the README.md
	Input file: Bad line ignored!

Line #6 requests HISTORY.
Oldest
===========
http://wikipedia.com
http://reddit.com
https://github.com
http://myspace.com  <==current
===========
Newest

Line #9 requests HISTORY.
Oldest
===========
http://wikipedia.com
http://reddit.com  <==current
https://github.com
http://myspace.com
===========
Newest

Line #12 - "FORWARD" Already at end of history.
	No URL further forward in history, staying in place.

Line #13 - "FORWARD" Already at end of history.
	No URL further forward in history, staying in place.

Line #14 requests HISTORY.
Oldest
===========
http://wikipedia.com
http://reddit.com
https://github.com
http://myspace.com  <==current
===========
Newest

Line #21 - "FORWARD" Already at end of history.
	No URL further forward in history, staying in place.

Line #22 requests HISTORY.
Oldest
===========
http://wikipedia.com
http://reddit.com
https://sony.com
https://google.com  <==current
===========
Newest

Line #24 requests HISTORY.
Oldest
===========
http://wikipedia.com
http://reddit.com
https://sony.com  <==current
https://google.com
===========
Newest


SUMMARY:
	Lines Parsed:24
	Bad Lines:1
	Commands Found:23
	Command Errors:3
Exiting Program now...
```
