KPR
===

HOWTO compile and run it (Linux only)
-------------------------------------
Create a folder most of the time called build  
$ mkdir build  
$ cd build

then run cmake and make as

$ cmake .. && make


To build de documentation go to the root of the project and run
and the log in the new folder doc ad run make

$ doxygen kpr.cfg && cd doc && make

Description of the problem
--------------------------

"El farol" bar problem and one of its variants.

As described by the author W.B. Arthur(1994):

"N people decide independently each week whether to go to a bar
on that offers entertainment a certain night.   
For concreteness,let us set N at 100. Space is limited, and
the evening is enjoyable if things are not too crowded
specifically, if fewer than 60 percent of the possible 100
are present.   
There is no sure way to tell the numbers coming in advance;
therefore a person or agent goes (deems it worth going) if
he expects fewer than 60 to show up or stays home if he
expects more than 60 to go.   
Choices are unaffected by previous visits; there is no
collusion or prior communication among the agents; and the
only information available is the numbers who camein past weeks.   
(The problemwas inspiredby the bar El Farol in Santa Fe
which offers Irish music on Thursday nights; but the
reader may recognize it as applying to noontime lunch-room
crowding, and to other commons or coordination problems
with limits to desired coordination.)   
Of interest is the dynamics of the numbers attending
from week to week."  

