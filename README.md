# Airline Management Simulation

## Contributors

* **Matthew Wilson** – Plane, PlaneType, PlaneSeats hash tables
* **Dani (Chloe) Hancock** – Passenger and Reservation hash tables
* **Cody Walls** – FlightLeg, FlightInstance, FlightLegInstance hash tables
* **Alex Prince** – Airport and Pilot hash tables

## Overview

This project implements multiple hash tables to manage airline-related data efficiently. The hash tables cover planes, plane types, plane seats, passengers, reservations, flight legs, flight instances, airports, and pilots. Each hash table uses an appropriate hashing strategy and collision resolution method for optimal data access.

### Key Features

* **PHash (Plane Hash Table)** – Stores plane information using mid-square hashing and linear probing for collisions.
* **PSHash (Plane Seats Hash Table)** – Stores seat details for planes with chaining for collision handling.
* **PTHash (Plane Type Hash Table)** – Stores plane type attributes with double hashing for collisions.
* **Passenger & Reservation Hash Tables** – Uses modulo hashing with chaining to manage passenger and reservation data.
* **Display, Insert, Update, and Select Operations** – Each hash table supports basic CRUD operations and selective queries.

## File Structure

* **main.cpp** – Demonstrates usage of plane, plane seats, and plane type hash tables.
* **PHash.h / PHash.cpp** – Plane hash table implementation.
* **PSHash.h / PSHash.cpp** – PlaneSeats hash table implementation.
* **PTHash.h / PTHash.cpp** – PlaneType hash table implementation.
* **passenger.h / passenger.cpp** – Passenger hash table implementation.
* **reservation.h / reservation.cpp** – Reservation hash table implementation.
* **makefile** – Compiles all relevant `.cpp` files into the `project2` executable.
* **README.md** – Project documentation.

## Compilation & Execution

1. Compile the project using the makefile:

   ```bash
   make
   ```

   This will generate the `project2` executable.

2. Run the program:

   ```bash
   ./project2
   ```

3. Clean compiled files:

   ```bash
   make clean
   ```

   This removes all `.o` object files and the `project2` executable.

## Notes

* Ensure all CSV data files (`DATA_Plane.CSV`, `DATA_PlaneSeats.CSV`, `Data_PlaneType.CSV`, etc.) are located in the same directory as the executable for proper loading.
* Each hash table is initialized with a fixed size of 23, with collision strategies adapted per table type.
* The project demonstrates object-oriented design, file I/O, and different hashing strategies for practical airline data management.
