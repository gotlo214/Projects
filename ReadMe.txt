#############################################################
ReadMe for assignment submitted by 2017A7PS0214P
Practical section number: P12
Lab Instructor : Sakshi Kalra
Assignment question attempted: 6
Question Topic :Train Ticket Reservation System.
#############################################################
Team:
1. 2017A7PS0214P	Patel Abhishek Bipinkumar
#############################################################
NOTE :  Compiling the program will give warnings. The program will run smoothly. I request you to ignore the warnings.
	
NOTE : All read write operations on files will complete when the program is terminated. While the program is running, you wont be able to see the file contents being edited.

NOTE : For simplicity, some tickets are already booked and some are already cancelled. The new booking taking place will start from PNR 30.
       Booked ticket details can be found in booked_tickets.txt and cancelled PNRs in cancelled_PNRs.txt. 

Description of how to run the code and observe the output: 
1. The main file is named as 2017A7PS0214P_P12
2. To compile and creare an executable , enter gcc -o 2017A7PS0214P_P12.o 2017A7PS0214P_P12.c in the terminal window.
   This will compile the code. It may give out warnings, but the code will run perfectly fine on execution.
3. To execute the code, type ./2017A7PS0214P_P12.o
	If this method fails, the other method(gcc 2017A7PS0214P_P12.c followed by ./a.out works as well) 
4. The input files are
	1: list_of_trains.txt
	   This file contains all the details of the trains and the prices on the routes.
	   The format of this file is: 
		Train No - Source - Destination - Tickets Left - Price of the ticket
	2: booked_tickets.txt
	   This file contains details of all the booked tickets.
	   The format of this file is:
		PNR No - Passenger Name - Train No
	   Whenever a ticket is booked, its details are written to this file. 
	   When a ticket is cancelled, its entry from this file will be deleted.
	3: last_PNR.txt
	   This file contains the last PNR at which a ticket was booked in the previous session. This is to make sure that when this code is run at any later time, ticket booking starts from the last booked PNR.
	   When a ticket is booked, the PNR in this file is incremented by one.
	4: cancelled_PNRs.txt
	   This file stores PNR of the cancelled tickets.
	   When a ticket is cancelled, its entry from booked_tickets.txt is deleted and its PNR is added to cancelled.txt
5. When you run the exe, you would be presented with the enquiry menu.
	There are 3 options in this:
	1: User Enquiry
	2: Ticket Booking
	3: Ticket Cancellation

6. User needs to enter the code of the preferred function.
7. When choosing User Enquiry, the person will be greeted with other two options:
	1: Destination Details and seat avaibility
		On choosing this option, the user needs to enter his source and destination.
		The user will get output of the seats available between the two entered stations.
	2: Booked Ticket details
		On choosing this option, user has to enter his PNR number.
		If there exists a ticket, it will output ticket details of the given PNR like name, source, and destination.
		If PNR entered is already cancelled, it will give output that the ticket is already cancelled.
		If the PNR entered is invalid(No tickets ever booked on this PNR), it will show Invalid PNR.
8. When choosing Ticket Booking, the person will be asked to enter the source station.
   If it is other than delhi, it will throw an error.
   If the source station is delhi, it will show the list of available destinations and ask the user to enter his choice of destination.
   If the destination is available,and the train has seats remaining, the user has to enter his name(first name only) to proceed to book the ticket.
   The output will show the number of tickets remaining on that train and the cost of the ticket.
   The user has to confirm the booking by entering 1 and the ticket will be booked.
   The output will display ticket details like name, source, destination, ticket cost, PNR.
   The ticket details will be added to booked_tickets.txt
   A seat will be decreased from list_of_trains.txt from the corresponding train.
9. When choosing ticket cancellation, person will be asked to enter the PNR number of the ticket to be cancelled.
   If there exists a valid ticket withthe given PNR, it will show the details and ask for user confirmation for ticket cancellation.
   If a user enters a PNR whose ticket is already cancelled before, it will give output that the ticket is already cancelled.
   If the PNR entered is invalid(No tickets ever booked on this PNR), it will show Invalid PNR.
   If the user confirms the cancellation, the ticket will be cancelled and the refund amount(50% cancellation charge) will be displayed on the screen.
   This PNR entry will be deleted form booked_tickets.txt and a seat will be made available the corresponding train on list_of_trains.txt and its PNR added to cancelled_PNRs.txt
   
############################################################
Known limitations of the code:
1. When compiling the code, it will give up WARNINGS. This should cause NO EFFECT on the execution of the code. The code should RUN PERFECTLY FINE. 
All modules are completely functional.
#############################################################
Contributions of the team members:
Patel Abhishek Bipinkumar : All modules
#############################################################