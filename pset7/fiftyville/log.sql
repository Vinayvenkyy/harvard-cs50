-- Keep a log of any SQL queries you execute as you solve the mystery.

--TO CHECK DESCRIPTION:
SELECT description FROM crime_scene_reports
WHERE year = 2020
AND day = 28
AND street = "Chamberlin Street"
AND month = 7;

------ description
--Theft of the CS50 duck took place 
--at 10:15am at the Chamberlin Street courthouse. 
--Interviews were conducted today with three witnesses
--who were present at the 
--time — each of their interview transcripts mentions the courthouse.


-- TO READ THE TRANSCRIPTS:
SELECT id, transcript FROM interviews
WHERE id IN
(SELECT id FROM interviews
WHERE year = 2020
AND day = 28
AND month = 7);

--id = 161;
--Sometime within ten minutes of the theft,
--I saw the thief get into a car in the courthouse parking lot
--and drive away. If you have security footage
--from the courthouse parking lot,
--you might want to look for cars that left the parking lot
--in that time frame.


--id = 162:
--I don't know the thief's name,
--but it was someone I recognized.
--Earlier this morning, before I arrived at the courthouse,
--I was walking by the ATM on Fifer Street and
--saw the thief there withdrawing some money.



--id = 163;
--As the thief was leaving the courthouse,
--they called someone who talked to them for
--less than a minute. In the call, I heard the thief
--say that they were planning to take the earliest
--flight out of Fiftyville tomorrow. The thief then
--asked the person on the other end of the phone to
--purchase the flight ticket.

--FIND original airport id : fiftyville
SELECT id from airports WHERE city = "Fiftyville";
--8

--FINAL NAME OF CULPRIT:
SELECT name FROM people

--get licence_plate (161)
WHERE license_plate IN
(SELECT license_plate FROM courthouse_security_logs
WHERE year = 2020 AND month = 7 AND day = 28
AND activity = "exit" AND hour = 10  AND minute > 15 AND minute < 25)

-- get atm account details (162)
AND id IN 
(SELECT person_id from bank_accounts
WHERE account_number IN 
(SELECT account_number FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28
AND atm_location = "Fifer Street" AND transaction_type = "withdraw"))

--get CALLER AND GET person taking earliest flight the next day (163)
AND phone_number IN 
(SELECT caller FROM phone_calls 
WHERE year = 2020 AND month = 7 AND day = 28 
AND duration < 60)

-- get person taking earliest flight the next day (163)
AND passport_number IN
(SELECT passport_number FROM passengers 
WHERE flight_id IN 
(SELECT id FROM flights
WHERE year = 2020 AND month = 7 AND day = 29
AND origin_airport_id = 8
ORDER BY hour, minute ASC LIMIT 1));

---ERNEST


--To get the accomplice :
SELECT name FROM people
WHERE phone_number IN 
(SELECT receiver FROM phone_calls 
WHERE year = 2020 AND month = 7 AND day = 28 
AND duration < 60 AND caller = (
SELECT phone_number from people 
WHERE name  = "Ernest"));

---BERTHOLD

--TO find where ernest is
--CITY
SELECT city from airports
WHERE id IN 
(SELECT destination_airport_id FROM flights
WHERE id IN 
(SELECT flight_id from passengers
WHERE passport_number IN 
(SELECT passport_number FROM people
WHERE name = "Ernest")));

--LONDON




