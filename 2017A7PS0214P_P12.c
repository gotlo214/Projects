//Name : Patel Abhishek Bipinkumar
//ID : 2017A7PS0214P
//Practical section number: P12
//Lab Instructor : Sakshi Kalra
//Assignment question attempted: 6
//Question Topic :Train Ticket Reservation System.
#include <stdio.h>
#include <string.h>
struct trains           //creation of struct trains
{
  int trainNo;
  char source[6];
  char destination[20];
  int seats_left;
  int price;
};
struct tickets          //creation of struct tickets
{
  int PNR;
  char name[20];
  int trainNo;
};
void changeSeatNo (int key, int trainKey, int no_of_trains, struct trains TRAINS[])  //function to increase/decrease seat no in trains.
{
  FILE *fptr2;
  fptr2 = fopen ("temp.txt", "w");  //creates a temporary file temp.txt
  switch (key)	//if key is one, decrease the number of seats. If key is 2, increase the number of seats.
	{
	case 1:         //to decrease the number seats
	  {
	for (int x = 0; x < no_of_trains; x++)
	  {
		if (x != trainKey - 1)  //checks if current train printed is train.key or not
		  {
		fprintf (fptr2, "%d\t%s\t%s\t%d\t%d\n", TRAINS[x].trainNo, TRAINS[x].source, TRAINS[x].destination, TRAINS[x].seats_left, TRAINS[x].price); //prints normal no of seats
		  }
		else
		  {
		fprintf (fptr2, "%d\t%s\t%s\t%d\t%d\n", TRAINS[x].trainNo, TRAINS[x].source, TRAINS[x].destination, TRAINS[x].seats_left - 1, TRAINS[x].price); //prints one seat less
		  }
	  }
	break;
	  }
	case 2:         //for increasing the number of seats
	  {
	for (int x = 0; x < no_of_trains; x++)
	  {
		if (x != trainKey)  //checks if current train printed is train.key or not
		  {
		fprintf (fptr2, "%d\t%s\t%s\t%d\t%d\n", TRAINS[x].trainNo, TRAINS[x].source, TRAINS[x].destination, TRAINS[x].seats_left, TRAINS[x].price); //prints normal no of trains
		  }
		else
		  {
		fprintf (fptr2, "%d\t%s\t%s\t%d\t%d\n", TRAINS[x].trainNo, TRAINS[x].source, TRAINS[x].destination, TRAINS[x].seats_left + 1, TRAINS[x].price); //prints one seat more
		  }
	  }
	break;
	  }
	}
  fclose (fptr2);
  remove ("list_of_trains.txt");     //deletes the original file
  rename ("temp.txt", "list_of_trains.txt"); //renames the temp file to list_of_trains.txt

}

void IncrementPNR ()         //increases the current pnr whenever a ticket is booked
{
  FILE *file;
  file = fopen ("last_PNR.txt", "r");    //open last_PNR.txt
  int currPNR;          //get current PNR
  fscanf (file, "%d", &currPNR);
  fclose (file);
  FILE *file1;
  file1 = fopen ("dd.txt", "w+");   //create a temporary file
  currPNR = currPNR + 1;    //increment the value of current PNR
  fprintf (file1, "%d", currPNR);   //print the value in the temporary file
  fclose (file1);
  remove ("last_PNR.txt");       //remove the original file
  rename ("dd.txt", "last_PNR.txt"); //rename temporary file to last_PNR.txt
}

void passengerEnquiry (int no_of_trains, struct trains TRAINS[]) //function to enquire about details
{
  printf ("Enter Source Station\n");    //get source station
  char ch[10] = "delhi";    //as initial station for all trains is delhi
  char ch1[10];
  scanf ("%s", ch1);
  if (strcmp (ch, ch1) == 0)    //compares if entered station is delhi or not
	{
	  printf ("|code - destination|\n");
	  for (int i = 0; i < no_of_trains; i++)    //this for loop prints all the available destinations
	{
	  printf ("|%d - %s|\n", i + 1, TRAINS[i].destination);
	}
	  printf ("Enter Destination Code : ");
	  int destination_code; //get destination code corresponding to the destination from the user
	  scanf ("%d", &destination_code);
	  if (destination_code > no_of_trains)  //if user enters a larger destination code
	{
	  printf ("Invalid Destination Code\n");
	  printf ("Transaction Failed\n");
	  passengerEnquiry (no_of_trains, TRAINS);  //repeats until a user enters a valid destination code
	}
	  else
	{
	  printf ("Chosen route is delhi to *%s* and seats remaining are *%d*\n", TRAINS[destination_code - 1].destination, TRAINS[destination_code - 1].seats_left);   //displays the chosen route and seats available
	  printf ("Press 1 to return to Main Menu. Enter any other key to exit\n"); //return to main menu or exit
	  int a;
	  scanf ("%d", &a);
	  if (a == 1)
		{
            main();	
		}
	  else
		{
		  printf ("Exiting........");
		}
	}
	}
  else
	{
	  printf ("No trains depart from this station\n");  //if user enters a source station apart from delhi
	  passengerEnquiry (no_of_trains, TRAINS);
	}
}

int searchtrainNo (int tempTrainNo, int no_of_trains, struct trains TRAINS[])   //searches train no corresponding to the key for PNR enquiry
{
  int trainKey;
  for (int i = 0; i < no_of_trains; i++)    //linear search for train no
	{
	  if (TRAINS[i].trainNo == tempTrainNo)
	{
	  trainKey = i;
	}
	}
  return trainKey;      //returns key corresponding to the train no
}

void ticketBooking (int currPNR, int no_of_trains, int no_of_trainsdup, struct trains TRAINS[])  //function to book a ticket 
{
  printf ("Enter Source Station : ");   //get source station from the user
  char ch[10] = "delhi";
  char ch1[10];
  scanf ("%s", ch1);
  int b = no_of_trains;
  int destination_key;
  int x = 0;
  if (strcmp (ch, ch1) == 0)    //checks if entered source station is delhi or not
	{
	  printf ("Proceeding towards Booking.....\n");
	  printf("************************************************************\n");
	  printf ("Available destinations : \n");
	  for (int i = 0; i < no_of_trains; i++)    //this for loop prints all the Available destinations
	  printf ("%s\n", TRAINS[i].destination);
	  printf("************************************************************\n");
	  printf ("Enter destination : ");
	  char ch[20];
	  scanf ("%s", ch);    // gets the destination user wants to travel to
	  printf ("Entered destination is %s\n", ch);
	  for (int j = 0; j < no_of_trains; j++)
	{
	  if (strcmp (ch, TRAINS[j].destination) == 0)  //checks if entered destination exists or not
		{
		  destination_key = j;
		  x++;
		}
	}
	  if (x == 1)
	{
	  int destination_code = destination_key + 1;
	  if (TRAINS[destination_code - 1].seats_left == 0) //checks if there are any remaining seats left in the train
		{
		  printf ("No seats remaining to this destination\n");
		  printf ("Transaction Ended");
		}
	  else
		{
		  printf ("***Chosen destination is %s and seats remaining are %d***\n", TRAINS[destination_code - 1].destination, TRAINS[destination_code - 1].seats_left);    //displays chosen destination and seats remaining
		  int abc = TRAINS[destination_code - 1].trainNo;
		  struct tickets booking[100];  //create a temporary struct for ticket booking
		  FILE *file1 = fopen ("booked_tickets.txt", "a");
		  printf ("Enter passenger Name(First name only) : ");
		  scanf ("%s", booking[0].name);   //reads passenger name for booking
		  printf ("Do you want to confirm the booking of Rs %d?\nEnter 1 to confirm : \n", TRAINS[destination_code - 1].price); //gets user confirmationfor ticket booking
		  int confirmation;
		  scanf ("%d", &confirmation);
		  if (confirmation == 1)    //if user confirms the booking
		{
		  fprintf (file1, "%d\t%s\t%d\n", ++currPNR, booking[0].name, abc); //write the booking details to the booked_tickets.txt file
		  fclose (file1);
		  changeSeatNo (1, destination_code, no_of_trains, TRAINS); //decreases a seat in list_of_trains.txt
		  printf ("Please wait while we confirm payment receipt\n");
		  printf ("Payment of Rs %d recieved Succesfully...\n", TRAINS[destination_code - 1].price);    //displaysthe cost of the ticket
		  printf ("************************************************************\n");
		  printf("****************Ticket Succesfully Booked*******************\n");
		  printf("************************************************************\n");
		  printf ("Ticket Details are as follows:\n");  //displays the details of the ticket
		  printf ("Passenger Name : %s\n", booking[0].name);
		  printf ("Source Staion : Delhi\n");
		  printf ("Destination Station : %s\n",TRAINS[destination_code - 1].destination);
		  printf ("Ticket PNR No :  %d\n", currPNR);
		  printf("************************************************************\n");
		  printf("Thank You for Travelling with us. Have a safe journey!!!!\n");
		  IncrementPNR ();  //increases the PNR for next booking
		  int x;
		  printf("Enter 1 to return to main menu.\nEnter any other key to exit.\n");
		  scanf ("%d", &x);
		  if (x == 1)
			{
			  main ();  //returns to main menu
			}
		  else
			{
			  printf ("Exiting...............");
			}
		}
		  else      //if user does not confirm ticket booking
		{
		  printf("Confirmation Not Recieved. Transaction Cancelled. Returning to Main Menu\n");
		  main ();
		}
		}
	}
	  else          //if user enters an invalid destination
	{
	  printf ("No trains exist between Delhi and %s\n", ch);
	  printf ("Press 1 to search again. Press any other key to exit.\n");
	  int x;
	  scanf ("%d", &x);
	  if (x == 1)
		ticketBooking (currPNR, no_of_trains, no_of_trains, TRAINS);    //return to ticket booking
	  else
		printf ("Exiting..........\n");
	}
	}
  else
	{
	  printf ("No trains depart from %s station\n", ch1);   // if user enters a source station apart from delhi
	  ticketBooking (currPNR, no_of_trains, no_of_trains, TRAINS);  //return to ticket booking
	}
}

int readPNR ()          //reads the current PNR for ticket booking
{
  FILE *file;
  file = fopen ("last_PNR.txt", "r");
  int currPNR;
  fscanf (file, "%d", &currPNR);
  fclose (file);
  return currPNR;       //returns the current PNR value
}

int searchPNR (int no_of_tickets, struct tickets TICKET[], int no_of_trains, struct trains TRAINS[], int cancelledPNR[], int no_cancelledTickets)   //search for PNR for user enquiry/ticket cancellation
{
  printf ("Enter PNR No to Search Ticket : ");  //get PNR value from user
  int key;
  int c = 0;
  int d = 0;
  int temp1;
  scanf ("%d", &temp1);     //get PNR value from user
  for (int i = 0; i < no_of_tickets; i++)
	{
	  if (TICKET[i].PNR == temp1)   //check if entered PNR matches with any active ticket PNR
	{
	  printf("************************************************************\n");
	  printf ("Ticket Details : \n");
	  printf ("Ticket PNR : %d\n", temp1);
	  printf ("Passenger Name : %s\n", TICKET[i].name);
	  key = i;
	  c++;
	  int trainNo = TICKET[key].trainNo;
	  int trainKey = searchtrainNo (trainNo, no_of_trains, TRAINS);
	  printf ("Train NO : %d\n", TRAINS[trainKey].trainNo);
	  printf ("Source : Delhi\n");
	  printf ("Destination : %s\n", TRAINS[trainKey].destination);
	  printf("************************************************************\n");
	  

	}
	}
  if (c == 0)
	{
	  for (int j = 0; j < no_cancelledTickets; j++) //check if entered PNR is cancelled previously
	{
	  if (cancelledPNR[j] == temp1) //if given PNR is already cancelled
		{
		  printf ("Ticket with given PNR is already cancelled\n");
		  d++;
		  int x;
		  printf
		("Enter 1 to return to main menu. Enter any other key to exit.\n");
		  scanf ("%d", &x);
		  if (x == 1)
		{
		  main ();
		}
		  else
		{
		  printf ("Exiting...............");
		  return 100000;//100000 is the exit key
		}

		}
	}
	  if (d == 0)       //if PNR does not match with any existing PNR
	{
	  printf ("Invalid PNR\n");
	  int x;
	  printf ("Enter 1 to search again . Enter any other key to exit.\n");
	  scanf ("%d", &x);
	  if (x == 1)
		{
		  searchPNR (no_of_tickets, TICKET, no_of_trains, TRAINS, cancelledPNR, no_cancelledTickets);   //search again
		  return 100000;//100000 is the exit key
		}
	  else
		{
		  printf ("Exiting...............");
		  return 100000;//100000 is the exit key
		}
	}
	}
  else
	return key;         //returns key value of PNR from list_of_trains.txt
}

void writeCancelledPNR (int PNR) //write cancelled PNR value to cancelled_PNRs.txt
{
  FILE *file;
  file = fopen ("cancelled_PNRs.txt", "a");
  fprintf (file, "%d\n", PNR);
  fclose (file);
}

void deletePNR (int key, int no_of_tickets, struct tickets TICKET[], struct trains TRAINS[], int trainKey)   //delete cancelled ticket from booked_tickets.txt
{
  FILE *file2;
  file2 = fopen ("temp.txt", "w+");
  printf ("Do you want to cancel the ticket?\n");
  printf ("Cancellation of a ticket will incurr a 50%% cancellation fee.\n");
  printf ("Press 1 for cancelling the ticket\n");
  int response;
  scanf ("%d", &response);
  if (response == 1)        //if user agrees to cancel the ticket
	{
	  printf ("Deleting Reservation.....\n");
	  printf("****************Ticket Cancelled Succesfully****************\n");
	  printf("*******Amount refunded(after 50%% deduction) : Rs %d********\n",TRAINS[trainKey].price / 2);
	  printf("************************************************************\n");
	  printf ("Exiting......\n");
	  writeCancelledPNR (TICKET[key].PNR);  //write cancelled PNR to cancelled_PNRs.txt
	  for (int i = 0; i < no_of_tickets; i++)
	{
	  if (i != key)     //prints tickets other than cancelled tickets
		{
		  fprintf (file2, "%d\t%s\t%d\n", TICKET[i].PNR, TICKET[i].name, TICKET[i].trainNo);    //prints all tickets other than cancelled ticket to the temp file
		}
	}
	  fclose (file2);
	  remove ("booked_tickets.txt");    //deletes original ticket file
	  rename ("temp.txt", "booked_tickets.txt");    //new tickets file

	}
  else
	{
	  printf ("Invalid Input : Transaction Failed\n");  //if user does not agree to cancel ticket
	  int x;
	  printf ("Enter 1 to return to main menu. . Enter any other key to exit.\n");
	  scanf ("%d", &x);
	  if (x == 1)
	  {
	      main();
	  }
	  else
	  {
	      printf("Exiting..............");
	  }
	  
	}
}

int readTicketNo ()         //get number of currently active booked tickets
{
  FILE *fp;
  int count = 0;
  char c;
  fp = fopen ("booked_tickets.txt", "r");
  for (c = getc (fp); c != EOF; c = getc (fp))
	if (c == '\n')
	  count = count + 1;
  fclose (fp);
  return count;         //return the number of tickets
}

int readCancelledPNR ()     //get number of cancelled tickets
{
  FILE *fp;
  int count = 0;
  char c;
  fp = fopen ("cancelled_PNRs.txt", "r");
  for (c = getc (fp); c != EOF; c = getc (fp))
	if (c == '\n')
	  count = count + 1;
  fclose (fp);
  return count;         //return number of cancelled tickets
}

int readTrainNo ()          // get number of trains from list_of_trains.txt
{
  FILE *fp;
  int count = 0;
  char c;
  fp = fopen ("list_of_trains.txt", "r");
  for (c = getc (fp); c != EOF; c = getc (fp))
	if (c == '\n')
	  count = count + 1;
  fclose (fp);
  return count;         //return number of trains running
}

int main ()
{
  int no_of_tickets = readTicketNo ();  //reads number of tickets in the booked_tickets.txt
  int no_of_trains = readTrainNo ();    //reads number of trains in list_of_trains.txt
  int no_cancelledTickets = readCancelledPNR ();    //reads number of cancelled tickets from cancelled_PNRs.txt
  int cancelledPNR[no_cancelledTickets];    //array for cancelled PNRs
  int a = no_of_trains;
  struct trains TRAINS[no_of_trains];   //struct declaration for train 
  FILE *file = fopen ("list_of_trains.txt", "r");    //opening list_of_trains.txt 
  int i = 0;
  while (a)         //this while loop reads list_of_trains.txt into the struct TRAIN
	{
	  fscanf (file, "%d\t%s\t%s\t%d\t%d\n", &TRAINS[i].trainNo,TRAINS[i].source, TRAINS[i].destination,&TRAINS[i].seats_left, &TRAINS[i].price);
	  a--;
	  i++;
	}
  fclose (file);
  FILE *file1;
  file1 = fopen ("booked_tickets.txt", "r");    //opening booked_tickets.txt
  struct tickets TICKET[no_of_tickets]; //struct declaration for tickets
  for (int i = 0; i < no_of_tickets; i++)   //this for loop reads booked_tickets.txt into struct TICKETS
	{
	  fscanf (file1, "%d\t%s\t%d", &TICKET[i].PNR, TICKET[i].name,&TICKET[i].trainNo);
	}
  fclose (file);
  printf ("************************************************************\n");
  printf ("welcome to IRCTC Train booking portal\n");
  printf ("Choose one of the following\n");
  printf ("1 : User enquiry\n");
  printf ("2 : New ticket booking\n");
  printf ("3 : Booked ticket cancellation\n");
  printf ("4 : Exit\n");
  printf ("************************************************************\n");
  printf ("User Option : ");
  FILE *file2;
  file2 = fopen ("cancelled_PNRs.txt", "r"); //opening cancelled_PNRs.txt
  for (int i = 0; i < no_cancelledTickets; i++) //this for loop reads cancelled PNRs into the array
	{
	  fscanf (file2, "%d", &cancelledPNR[i]);
	}
  fclose (file2);
  int input;
  scanf ("%d", &input);     //gets user input for initial menu
  switch (input)        //switch case based on input
	{
	case 1:
	  {
	printf("************************************************************\n");
	printf ("Choose type of Enquiry\n");
	printf ("1: Seat availability enquiry\n");
	printf ("2: Get booked ticket details\n");
	printf("************************************************************\n");
	int response;
	scanf ("%d", &response);    //getting user response
	if (response == 1)
	  {
		passengerEnquiry (no_of_trains, TRAINS);    //goes to passengerEnquiry function
	  }
	else if (response == 2)
	  {
		searchPNR (no_of_tickets, TICKET, no_of_trains, TRAINS, cancelledPNR, no_cancelledTickets); //searches for the ticket details of the PNR entered by the user
	  }
	else
	  {
		printf ("Invalid Input\nReturning to Main Menu\n");
		main ();
	  }
	break;
	  }
	case 2:
	  {
	int currPNR = readPNR ();   //gets the details of the last unbooked PNR
	ticketBooking (currPNR, no_of_trains, no_of_trains, TRAINS);    //function call to book tickets
	break;
	  }
	case 3:
	  {
	int key = searchPNR (no_of_tickets, TICKET, no_of_trains, TRAINS, cancelledPNR, no_cancelledTickets);   //searches for PNR in booked_tickets.txt and returns key of the PNR from the list
	if (key != 100000)// 100000 is the exit key
	  {
		int tempTrainNo = TICKET[key].trainNo;  //gets train number of the booked ticket
		int trainKey = searchtrainNo (tempTrainNo, no_of_trains, TRAINS);   //gets key of train of the PNR number
		deletePNR (key, no_of_tickets, TICKET, TRAINS, trainKey);   //deletes the PNR from booked_tickets.txt
		changeSeatNo (2, trainKey, no_of_trains, TRAINS);   //increases the number of seats in the corresponding train in list_of_trains.txt
	  }
	break;
	  }
	case 4:
	  {
	printf ("Exiting........");
	break;
	  }
	default:
	  printf ("**************Invalid Input**************\n");
	  main ();
	  break;
	}
  return 0;
}
