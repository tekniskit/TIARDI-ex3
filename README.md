Topic
-----
Reactor pattern used in a PC server application
 
References
----------
POSA2, p.179-214.
 
Goal
----
Obtaining experience with design and implementation of the Reactor pattern and knowledge of the different implementation options.
 
Platform
--------
PC, windows application
 
Assignment
----------
<ol>
<li>
Develop a PC server console application based on the Reactor pattern.

The server application shall handle the following three event types:
<ul>
  <li>an alarm event (carrying a priority field and a text string)</li>
  <li>a patient value event (carrying a type field and a value field)</li>
  <li>a log event (carrying a text string)</li>
</ul>
 
Each time an alarm event is received the application shall display the alarm info together with a time stamp.
The received patient values are displayed as they are received.

Received log events are displayed as the are received (would normally in real life be stored in a log file).
<ol>
<li>Design the application using a UML class diagram and a sequence diagram.</li>
<li>Implement the different Reactor classes in C++ and the necessary event handler classes.

Follow the implementation description for the Reactor pattern and make the appropriate implementation choices.</li>

<li>Develop a test stub simulating the Synchronous Event Demultiplexer class.
 
The test stub simulates a client application sending the different three event types at certain times – defined in the test stub class.</li>

<li>Test the application with input form this test stub.</li>
</ol>
</li>

<li>Discuss and evaluate the value of the Reactor pattern.</li>
</ol>
 
Product / delivery / deadline
-----------------------------
A UML class diagram showing the classes in the application and one or more sequence diagrams and the source code.
This is included in the first hand-in called TIARDI-Delivery 1 (includes ex.1-3).
 
Evaluation
----------
UML designs from one or more groups will be presented in plenum.
