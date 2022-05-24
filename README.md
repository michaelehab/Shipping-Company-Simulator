# Shipping Company Simulator
<div align = "center">
  
  ![Trucks](https://user-images.githubusercontent.com/29122581/170028682-a60b3954-15ef-472a-84f6-9eba11109cee.png)
  This is an educational Project for Data Structures and Algorithms course taken during Spring 2022 semester.
</div>

## Introduction
A shipping company needs to handle cargo delivery the most efficient and profitable way.  
The company needs to automate the cargo-truck assignment process to achieve good and fair use
of its trucks.  
This CLI program that simulates the operation of the cargo delivery process of a Shipping Company and calculates some related statistics.

### Cargos and Trucks
#### Cargos
The following pieces of information are available for each cargo:
* Preparation (Ready) Time: the Time (day:hour) when the cargo is ready to be
assigned to a truck.
* Load/Unload Time: Time (in hours) to load/unload the cargo to/from the truck.
* Cargo Type: There are 3 types of cargos: VIP, Special and Normal cargos.
  * VIP cargos must be assigned first before other cargos.
  * Special cargos are cargos to need special trucks like frozen cargos or
chemical cargos,… etc
  * Normal cargos: all other cargos
* Delivery Distance: The distance (in kilometers) from the company to the delivery
location of the cargo.
* Cost: The cost of delivering the cargo.

#### Trucks
Trucks:
At startup, the system loads (from a file) information about the available trucks. For
each truck, the system will load the following information:
* Truck Type: There are 3 types of trucks: VIP trucks, Normal trucks, and Special
trucks.
  * VIP trucks (VT) are trucks that are used basically for VIP cargos.
  * Special trucks (ST) are trucks that are equipped to carry special cargos.
  * Normal trucks (NT)
* Truck Capacity (TC): A truck can deliver many cargos in the same journey. TC is
the number of cargos a truck can carry to be fully loaded. (TC is read from input
file).
* Maintenance (Checkup) time: The duration (in hours) of checkups/maintenance
that a truck needs to perform after finishing J delivery journeys. (J is read from
input file)
* Speed: in kilometers/hour.
* Delivery interval (DI): The time a truck takes to deliver all its cargos. and come
back to the company. It can be calculated as:
> DI = (Delivery Distance of furthest cargo)/truck speed + Sum of unload times of all
its cargos + time to come back

### Cargo Assignment Criteria
To determine the next cargo to assign (if a truck is available), the following assignment criteria is applied for all the ready un-assigned cargos on each hour:
* The Company working hours are from 5:00 to 23:00. Otherwise, it is off-hours.
* New Assignment can be done ONLY during working hours.
* The allowed activities during off-hours are: truck maintenance and trucks moving
for delivery or returning back to the company.
* All trucks of the same type have the same capacity.
* Loading Rule: If some cargos are ready and waiting to be assigned to a truck,
don’t start loading cargos as long as the number of ready cargos is less than
capacity of the fist available truck (TC).
For example: if you have 3 ready normal cargos and you have an available normal
truck but with TC=4, don’t load those cargos until a 4th cargo is ready. Only then
start loading the cargos. This rule may be ignored in favor of Maximum Wait Rule
(See next point).
* Maximum Wait Rule: If there is an available truck that is suitable for a cargo that
has been waiting for MaxW hours (or more), such cargo should be immediately
loaded and moved to its destination. MaxW is loaded from input file. Ignore
“Loading Rule” in this case.
* A truck can’t be loaded with more than one cargo type in the same journey.

### Assignment Order: (if TC cargos of certain type are ready)
1. First, assign VIP cargos to ANY available truck of any type. However, there is a
priority based on the truck type: first choose from VIP trucks THEN normal
trucks THEN special trucks. This means that we do not use normal trucks unless
all VIP trucks are out, and we do not use special trucks unless trucks of all other
types are out.
2. Second, assign special cargos using the available special trucks ONLY. If no
special truck is available, wait until one comes back.
3. Third, assign normal cargos using any type of trucks EXCEPT special trucks.
First use the available normal trucks THEN VIP trucks (if all normal trucks are
out).
4. If a cargo cannot be assigned on the current hour, it should wait for the next
hour. On the next hour, it should be checked whether the cargo can be assigned
now or not. If not, it should wait again and so on.

#### This is how we prioritize the assignment of cargos of different types, but how will we prioritize the assignment of cargos of the same type?
* For special and normal cargos, assign them based on a first-come first-serve
basis. Cargos that are ready first are assigned first.
* For VIP cargos, you should design a priority equation for deciding which of the
available VIP cargos should be assigned first. VIP cargos with a higher priority
are the ones to be assigned first.
> VIP Priority = (20 * Cost) + (10 * Delivery distance) + (4 * ready day)

#### There are some additional services that the company accommodates:
* For normal cargos ONLY, a request can be issued to promote the cargo to
become a VIP one. A request of cargo cancellation could also be issued.
A Cargo that has been already loaded to a truck cannot be canceled or
promoted.
* For normal cargos ONLY, if a cargo waits more than AutoP days from its
preparation time to be assigned to a truck, it should be automatically
promoted to be an VIP cargo. (AutoP is read from the input file).

### Sample Input file
```
3 3 2 🡺 no. of trucks of each type (N, S, V)
80 70 140 🡺 truck speeds of each type (km/h)
6 4 2 🡺 Capacity of each truck type (N, S, V)
12 9 8 7 🡺 no. of journeys before checkup and the checkup durations
10 20 🡺 auto promotion limit (days), MaxW (hours)
8 🡺 no. of events in this file
R N 1:3 1 200 2 500 🡺 Ready event example
R N 1:10 2 25 1 413
R S 1:10 3 50 2 356
R V 2:22 4 90 3 400
X 4:12 1 🡺 cancellation event example
R N 5:7 5 56 2 187
P 9:3 2 200 🡺 promotion event example
R V 11:6 6 19 3 1006
```

### Sample Output file
The following numbers are just for clarification and are not produced by actual
calculations.
```
CDT   ID  PT    WT    TID
18:3  1   7:4   0:9   3
20:5  10  2:10  12:5  5
20:5  4   15:1  3:6   15
………………………………………………
………………………………………………
Cargos: 124 [N: 100, S: 15, V: 9]
Cargo Avg Wait = 3:10
Auto-promoted Caros: 4%
Trucks: 20 [N: 13, S: 5, V: 2]
Avg Active time = 91%
Avg utilization = 87%
```

## Program Interface Screenshots
### Interactive Mode
Allows user to monitor the cargos and trucks. The
program should print an output like that shown below. In this mode, the program
prints the current time then pauses for an input from the user (“Enter” key) to display the output of the next time.

![interactive mode](https://user-images.githubusercontent.com/29122581/170033471-d2ab7a87-ad17-499c-823f-6952831dad91.png)
### Step-By-Step Mode
Step-By-Step Mode is identical to the interactive mode except that after
each hour, the program waits for one second (not for user input) then resumes
automatically.
### Silent Mode
The program produces only an output file (See the “FileFormats” section). It does not print any simulation steps on the console. It just printsthe following screen

![silent mode](https://user-images.githubusercontent.com/29122581/170032981-2b74415b-c808-4660-a68d-6124b986f76a.png)

NOTE: No matter what mode of operation your program is running in, the output file is produced.
