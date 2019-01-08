// Assignment 2.
// Student Name: Sampath Lakkaraju.
// Student ID: 011818781.
// Student email: sampath.lakkaraju@sjsu.edu.
/* Program compares two methodes of watering plants according to the total steps per units.
	The program is a modification of assignment 1 while including functions */
	
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int UNITS_PER_CAN = 3;
const string INPUT_FILE_NAME = "counts.txt";
	
int Plan_Near( int, int,int);
int Plan_Far( int, int, int);
void Output_header(int, int);
void Output_details(int, int, int, int, int);
void Output_footer(int, int, int);
void Output_Plan_comparision(int, int, int);

int main()
{
	int plant_count;		//Plant_count declaration.
	
    ifstream input; 				//Inputstream declaration.
    input.open(INPUT_FILE_NAME);
	
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
	do
    {
		input >> plant_count; 	//Plant_count input from file.
   		
		if (plant_count== 0)	//No plant condition.
			{
				return 0;
			}
		// Variable declartions.
		int Cumi_Step_units_near=0;
		int Cumi_Step_units_far=0;
		int Plan_no;
		
		// Near plan.
		Plan_no=1;
		Output_header(Plan_no, plant_count );	// Header output function call.
		Cumi_Step_units_near=Plan_Near(UNITS_PER_CAN, plant_count, Plan_no); //Plan Near exceution function call.

		// Far plan.
		
		Plan_no=2;
		Output_header(Plan_no, plant_count); // Header output function call.
		Cumi_Step_units_far=Plan_Far(UNITS_PER_CAN, plant_count, Plan_no); //Plan Far exceution function call.
		
		Output_Plan_comparision(plant_count,Cumi_Step_units_near,Cumi_Step_units_far); // Comparision of plan output function call.
		
	} while (plant_count > 0);
    
    return 0;
}

int Plan_Near( int UNITS_PER_CAN, int plant_count , int Plan_no)
{
	int Plant_no=0;
	int Steps_can_takes=0;
	int Water_amt_can=UNITS_PER_CAN;
	int Can_posit=0;
	int Cumi_Steps=0;
	int Cumi_Step_units=0;
	while (Plant_no < plant_count)		// Loop for Trip
	{
		if (Water_amt_can>0)					// Can water check.
			{
				Steps_can_takes=1;
				Can_posit=Can_posit+1;						//Can position incriment
				Cumi_Steps=Cumi_Steps+Steps_can_takes;		//Cumulative steps computation.
				Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);	//Cumulative step unit computation.
				Plant_no=Plant_no+1;			//Number of plant filled.
				
				Output_details(Can_posit, Plant_no, Cumi_Steps, Cumi_Step_units, Water_amt_can);
			
				Water_amt_can=Water_amt_can-1;	// Can water level decrement.
			}
		else if ( Water_amt_can==0)				// Can water refill loop.
			{
				Steps_can_takes=Can_posit;		// Steps the can is away from faucet.
				Can_posit=0;					//Faucet considerd as 0 step.
				Cumi_Steps=Cumi_Steps+Steps_can_takes;
				Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);
				
				Output_details(Can_posit, Plant_no, Cumi_Steps, Cumi_Step_units, Water_amt_can);
					
				Water_amt_can=UNITS_PER_CAN;		//Can refill assignment.
				Steps_can_takes=Plant_no;
				Cumi_Steps=Cumi_Steps+Steps_can_takes;
				Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);
				Can_posit=Plant_no;
			}
	}
	
	if (Plant_no==plant_count)					// Can return to start position.
		{
			Steps_can_takes=Plant_no;
			Cumi_Steps=Cumi_Steps+Steps_can_takes;
			Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);
			Can_posit=0;
			Plant_no=0;
			
			Output_details(Can_posit, Plant_no, Cumi_Steps, Cumi_Step_units, Water_amt_can);
		}
	
	//Cumi_Step_units_near=Cumi_Step_units;			//Cumulative step per units assign for plan near.
	Output_footer(Plan_no, Cumi_Steps, Cumi_Step_units);
	
	return (Cumi_Step_units);
}

int Plan_Far( int UNITS_PER_CAN, int plant_count, int Plan_no)
{
	int Plant_no=plant_count; 
	int Steps_can_takes=0;
	int Water_amt_can=UNITS_PER_CAN;
	int Can_posit=0;
	int Cumi_Steps=0;
	int Cumi_Step_units=0;
	
	while (Plant_no>0)				// Loop for Plant counter.
	{
		if (Water_amt_can>0)				// Faucet water check.
			{
				if(Can_posit==0)				
					{
						Steps_can_takes=Plant_no;	// Steps to be taken for reaching last plant.
						Cumi_Steps=Cumi_Steps+Steps_can_takes;
						Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);
						Can_posit=Plant_no;
						
						Output_details(Can_posit, Plant_no, Cumi_Steps, Cumi_Step_units, Water_amt_can);
						
						Water_amt_can=Water_amt_can-1;
					}
				
				// Steps taken from far when faucet is filled.
				
				Steps_can_takes=1;		
				Cumi_Steps=Cumi_Steps+Steps_can_takes;
				Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);
				Can_posit=Can_posit-1;
				Plant_no=Plant_no-1;
				
				Output_details(Can_posit, Plant_no, Cumi_Steps, Cumi_Step_units, Water_amt_can);
					
				Water_amt_can=Water_amt_can-1;
			}
		else if ( Water_amt_can==0)
			{
				Steps_can_takes=Plant_no;
				Can_posit=0;
				Cumi_Steps=Cumi_Steps+Steps_can_takes;
				Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);
				
				Output_details(Can_posit, Plant_no, Cumi_Steps, Cumi_Step_units, Water_amt_can);
					
				Water_amt_can=UNITS_PER_CAN;				//Can refill.
				Plant_no = Plant_no-1;
			}
	}
	
	Output_footer(Plan_no, Cumi_Steps, Cumi_Step_units);
       
	return (Cumi_Step_units);
	
}

void Output_header(int Plan_no, int plant_count)
{
	if (Plan_no==1)			// Header output for plan near.
		{
			cout << endl;
			cout << "==========================" << endl;
			cout << " Plan Near with " << plant_count << " plants" << endl;
			cout << "==========================" << endl;
			cout << endl;
		} 
	else if (Plan_no==2)	// Header output for plan far.
		{
			cout << endl;
			cout << "==========================" << endl;
			cout << " Plan Far with " << plant_count << " plants" << endl;
			cout << "==========================" << endl;
			cout << endl;
		}
					// Common header output.
	
	cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
	cout << "---------  ----------  ----------  ---------------" << endl;

}

void Output_details(int Can_posit, int Plant_no, int Cumi_Steps, int Cumi_Step_units, int Water_amt_can)
{	
			// Output of can position.
	if (Can_posit>0)								
		{
			cout <<"Plant  "<< Plant_no<< "      ";	// If the can position is at plant 
		}
	else if (Can_posit==0)
		{
			cout<< "FAUCET        ";				// If the can position is at faucet
		}
	
			// Output of Details
	
	if (Cumi_Steps<=9 && Cumi_Step_units<=9)	// if Cumulative Steps and Cumulative Step per units are single digit.
		{
			cout<<" "<< Cumi_Steps<<"\t   "<<Water_amt_can<<" \t\t "<<Cumi_Step_units<<"\n";;
		}
	else if (Cumi_Steps>9 && Cumi_Step_units<=9)	// if Cumulative Steps is double digit.
		{
			cout<< Cumi_Steps<<"\t   "<<Water_amt_can<<" \t\t "<<Cumi_Step_units<<"\n";
		}
	else if (Cumi_Steps<=9 && Cumi_Step_units>9)	// if Cumulative Step per units is double digit.
		{
			cout<<" " << Cumi_Steps<<"\t   "<<Water_amt_can<<"\t\t"<<Cumi_Step_units<<"\n";
		}
	else if (Cumi_Steps>9 && Cumi_Step_units>9)	// if Cumulative Steps and Cumulative Step per units are double digit.
		{
			cout<< Cumi_Steps<<"\t   "<<Water_amt_can<<"\t\t"<<Cumi_Step_units<<"\n";
		}
	
}

void Output_footer(int Plan_no, int Cumi_Steps, int Cumi_Step_units)
{
	if (Plan_no==1)				// Header output for plan near.
		{
			cout << endl<< "Plan Near: Total steps = "<< Cumi_Steps << ", total step-units = "<< Cumi_Step_units<<" \n";
		} 
	else if (Plan_no==2)		// Footer output for plan far.
		{
			cout << endl<<"Plan Far: Total steps = "<< Cumi_Steps << ", total step-units = "<< Cumi_Step_units<<" \n";
		}
	
}


void Output_Plan_comparision(int plant_count, int Cumi_Step_units_near, int Cumi_Step_units_far)

{
	cout << endl;
	cout << "*** With " << plant_count << " plants, ";		//Plan comparision result output.
	
	if (Cumi_Step_units_far>Cumi_Step_units_near)				
		{
			cout<< "Plan Near is better with "<< (Cumi_Step_units_far - Cumi_Step_units_near)<< " fewer step-units.\n"; 
		}
    else if (Cumi_Step_units_far < Cumi_Step_units_near)
		{
			cout<< "Plan Far is better with "<< (Cumi_Step_units_near - Cumi_Step_units_far)<< " fewer step-units.\n";
		}
}