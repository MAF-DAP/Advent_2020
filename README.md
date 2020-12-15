# Advent Day of Code 2020

Here are my solutions to Advent Day of Code 2020.  

I do not claim that my solutions are particularly great but I did them all on my lonesome


<h2>Day 10: Joltage Adapter</h2>
- Part 1: Find the appropriate set of power adapters based on set rules.  Implemented with recursion.  No issues
- Part 2: Finding all the different ways that the adpaters can be organized.  First pass used recursion and I halted it when I realized that it would take over 6,000 years to run.  Second version was implemented when I looked at the data and noticed that the joltage rating changed by either "1" or "3" - this version runs much more quickly 

<h2>Day 11: Airport Seating</h2>
- Part 1: Simulating people choosing seats.  Like "The Game of Life" - kind of fun.  No issues
- Part 2: Updating the seat rules.  No issues 

<h2>Day 12: Ferry Navigation Computer</h2>
- Part 1: Navigating from computer program.  No issues
- Part 2: More navigating from computer program.  No issues 

<h2>Day 13: Shuttle Bus Scheduling</h2>
- Part 1: Finding the Bus that will arrive closest to you disembarking the boat.  No issues
- Part 2: Finding a time when the buses will come in in order.  First approach was going through each lowest increment in time to find when the buses will come in order - this was very slow (would take about three days to complete).  I spent some time looking at the sample data approach and noticed that the increment time should be based on the number of buses that have come through on time - this version worked much more quickly

<h2>Day 14: Docking Data</h2>
- Part 1: Initialization Docking Program with Data Specified by Mask.  No issues
- Part 2: Initialization Docking Program with Address Specified by Mask.  Should not have had any issues, but found that MindGW (the compiler I'm using) ALWAYS returns 0 for (1 << bit) where "bit" is 32 or greater

