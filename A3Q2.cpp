// -----------------------------------------------------
// Assignment: 3
// Question: 2
// File name: A3Q2.cpp
// Written by: Ajwad Hossain
// For Comp 218 Section EC/Fall 2019
// -----------------------------------------------------

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

//Made class shapes
class Shape                                                                                             
{
public:                                                                                               
//HEADER
	void displayHeader()                                                                               
	{
		cout << "-------****-------****-------****-------****-------****-------****-------\n"
			 << "	Welcome to the Circumference and Surface Area Calculator! \n"
			 << "-------****-------****-------****-------****-------****-------****-------\n\n";
	}
//OPTIONS
	void displayMenu()                                                                                   
	{
		cout << "Here are some shapes you could choose to calculate the circumference and surface area\n";
		cout << "	1 - Circle\n";
		cout << "	2 - Triangle\n";
		cout << "	3 - Square\n";
		cout << "	4 - Rectangle\n";
		cout << "	5 - Quit\n\n";
	}
//CHECKING IF VALID OPTION IS CHOSEN
	int getChoice()                                                                                       
	{                                                                                                   
		int pick = 0;
		char num;
		cout << "Please enter the digit corresponding to your option: ";
		cin >> num;

		while (num < 47 || num > 58)
		{                                                                                              
			fflush(stdin);
			cout << "Invalid choice!!! Try again: ";                   
			cin >> num;

		}

		pick = (int)(num - '0');

		while (pick < 1 || pick > 4)                                                                                                           
		{
			fflush(stdin);                                                                               
			cout << "Invalid choice!!! Try again: ";               
			cin >> num;


			while (num < 47 || num > 58)
			{
				fflush(stdin);
				cout << "Invalid choice!!! Try again: ";
				cin >> num;
			}

			pick = (int)(num - '0');


		}

		return pick;                                                                                   
	}
	//BASED ON CHOICE CHOOSE WHICH CASE TO EXECUTE
	void processMenuChoice(int pick, double& circumference, double& surfaceArea, string& shapee)       
	{                                                                                                   
		switch (pick)                                                                                   
		{
		case 1:
			shapee = "circle";                                                                      
			calculateCircle(circumference, surfaceArea);
			break;

		case 2:
			shapee = "triangle";                                                                      
			calculateTriangle(circumference, surfaceArea);                                          
			break;

		case 3:
			shapee = "square";
			calculateSquare(circumference, surfaceArea);
			break;

		case 4:
			shapee = "rectangle";
			calculateRectangle(circumference, surfaceArea);
			break;

		default:
			break;
		}
	}
//INPUT VALUES FOR CHOSEN SHAPE EITHER SQUARE CIRCLE RECTANGLE OR TRIANGLE
	void calculateCircle(double& circumference, double& surfaceArea)                              
	{
		double radius;

		cout <<"Please input the value of radius: ";                                      
		cin >> radius;

		while (radius <= 0)                                                                         
		{
			cout <<"Invalid choice!!! Try again: ";
			cin >> radius;
		}

		circumference = 2 * 3.14 * radius;                                                               
		surfaceArea = 3.14 * radius * radius;

	}

	void calculateTriangle(double& circumference, double& surfaceArea)                              
	{
		double height, side1, side2, side3;

		cout <<"Please input the height of the triangle:";                                       
		cin >> height;

		while (height <= 0)                                                                                 
		{
			cout <<"Invalid choice!!! Try again:";
			cin >> height;
		}

		cout <<"Please input the length of side 1:";
		cin >> side1;

		while (side1 <= 0)
		{
			cout <<"Invalid choice!!! Try again: ";
			cin >> side1;
		}

		cout <<"Please input the length of side 2:";
		cin >> side2;

		while (side2 <= 0)
		{
			cout <<"Invalid choice!!! Try again: ";
			cin >> side2;
		}

		cout <<"Please input the length of side 3:";
		cin >> side3;

		while (side3 < 0)
		{
			cout <<"Invalid choice!!! Try again: ";
			cin >> side3;
		}

		circumference = side1 + side2 + side3;                                                                                  
		surfaceArea = height * side1 / 2;
	}

	void calculateSquare(double& circumference, double& surfaceArea)                                         
	{
		double s;

		cout <<"Please input the length of side:";                                                         
		cin >> s;

		while (s <= 0)                                                                                             
		{
			cout <<"Invalid choice!!! Try again: ";
			cin >> s;
		}

		circumference = 4 * s;                                                                                       
		surfaceArea = s * s;
	}

	void calculateRectangle(double& circumference, double& surfaceArea)                                           
	{
		double w, l;                                                                                              

		cout <<"Please input the width of the rectangle:";
		cin >> w;

		while (w <= 0)                                                                                               
		{
			cout <<"Invalid choice!!! Try again:";
			cin >> w;
		}
		cout <<"Please input the length of the rectangle:";
		cin >> l;

		while (l <= 0)                                                                                               
		{
			cout <<"Invalid choice!!! Try again:";
			cin >> l;
		}

		circumference = 2 * (w + l);                                                                                   
		surfaceArea = w * l;
	}
//DISPLAY RESULTS
	void displayResult(double& circumference, double& surfaceArea, string& shapee)                               
	{
		cout <<"\nThe circumference of " << shapee << " is: " << circumference;                             
		cout <<"\nThe surfaceArea of " << shapee << " is: " << surfaceArea;
		cout << "\n\n Thank you for using the Shape Calculator!";
	}


};

int main()                                                                                                       
{
	Shape s;                                                                                                     
	string shapee;                                                                                               
	double circumference, surfaceArea;
	int pick;

	s.displayHeader();                                                                                           
	s.displayMenu();
	pick = s.getChoice();
	s.processMenuChoice(pick, circumference, surfaceArea, shapee);
	s.displayResult(circumference, surfaceArea, shapee);

	return 0;
}