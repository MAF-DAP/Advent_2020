# Advent Day of Code 2020

Here are my solutions to Advent Day of Code 2020.  

I do not claim that my solutions are particularly great but I did them all on my lonesome


<h2>Day 13: Shuttle Bus Scheduling</h2>
- Part 1: Finding the Bus that will arrive closest to you disembarking the boat.  No issues
- Part 2: Finding a time when the buses will come in in order.  First approach was going through each lowest increment in time to find when the buses will come in order - this was very slow (would take about three days to complete).  I spent some time looking at the sample data approach and noticed that the increment time should be based on the number of buses that have come through on time - this version worked much more quickly.  

<h2>Day 14: Docking Data</h2>
- Part 1: Initialization Docking Program with Data Specified by Mask.  No issues
- Part 2: Initialization Docking Program with Address Specified by Mask.  Should not have had any issues, but found that MindGW (the compiler I'm using) ALWAYS returns 0 for (1 << bit) where "bit" is 32 or greater

