# Advent Day of Code 2020

Here are my solutions to Advent Day of Code 2020.  

Note that the base code I use for each project becomes simpler as the days go on.  The reason for this is that I had to get a rhythm for the questions and how the data came through.  You'll see in the initial question, I copied in the sample and actual data directly into the program in the format I thought best and then read it in.  I also started off as quite anal when it comes to checking the file reads but then slacked off as I reaized that the error checking wasn't required for these applications.  

I do not claim that my solutions are particularly great but I did them all on my lonesome


<h2>Day 5: Binary Boarding</h2>
- Part 1: Decoding boarding pass to understand seat assignments.  No issues
<p>- Part 2: Find available seat.  No issues 

<h2>Day 6: Custom Customs</h2>
- Part 1: Counting question answers.  No issues
<p>- Part 2: More counting question answers.  No issues 

<h2>Day 7: Handy Haversacks</h2>
- Part 1: Pick a bag and find out how many "shiny gold" bags end up in it.  Did a very simple first pass with only taking the first letters of the two word colour - big mistake as while it works for the demo set, there are multiple colours with the same initials.  No issues other than having to redo with the full colour name
<p>- Part 2: Find out how many bags are in one "shiny gold" one.  No issues 

<h2>Day 8: Handheld Halting</h2>
- Part 1: Find accumulator value in repeating code.  No issues
<p>- Part 2: Find the corrupted instruction.  No issues 

<h2>Day 9: Encoding Error</h2>
- Part 1: Find the Incorrect Sum of List Element Numbers.  No issues
<p>- Part 2: Find the next invalid number in the list.  No issues 

<h2>Day 10: Adapter Array</h2>
- Part 1: Find the appropriate set of power adapters based on set rules.  Implemented with recursion.  No issues
<p>- Part 2: Finding all the different ways that the adpaters can be organized.  First pass used recursion and I halted it when I realized that it would take over 6,000 years to run.  Second version was implemented when I looked at the data and noticed that the joltage rating changed by either "1" or "3" with a set number of options for the number of "1"s found - this version runs much more quickly 

<h2>Day 11: Seating System</h2>
- Part 1: Simulating people choosing seats.  Like "The Game of Life" - kind of fun.  No issues
<p>- Part 2: Updating the seat rules.  No issues 

<h2>Day 12: Rain Risk</h2>
- Part 1: Navigating from computer program.  No issues
<p>- Part 2: More navigating from computer program.  No issues 

<h2>Day 13: Shuttle Search</h2>
- Part 1: Finding the Bus that will arrive closest to you disembarking the boat.  No issues
<p>- Part 2: Finding a time when the buses will come in in order.  First approach was going through each lowest increment in time to find when the buses will come in order - this was very slow (would take about three days to complete).  I spent some time looking at the sample data approach and noticed that the increment time should be based on the number of buses that have come through on time - this version worked much more quickly

<h2>Day 14: Docking Data</h2>
- Part 1: Initialization Docking Program with Data Specified by Mask.  No issues
<p>- Part 2: Initialization Docking Program with Address Specified by Mask.  Should not have had any issues, but found that MindGW (the compiler I'm using) ALWAYS returns 0 for (1 << bit) where "bit" is 32 or greater

