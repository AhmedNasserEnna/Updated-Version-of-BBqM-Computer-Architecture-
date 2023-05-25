#include <iostream>
#include <string>
using namespace std;
bool Empty = 0, Full = 0, Alarm = 0;
int Pcount = 0, Tcount = 0;
string Error = "There is No Errors in the System to show";
void Flags()
{
	if (Pcount == 0)
	{
		Empty = 1;
		Full = 0;
	}
	else if (Pcount == 7)
	{
		Empty = 0;
		Full = 1;
	}
	else
	{
		Empty = 0;
		Full = 0;
	}
	Alarm = 0;
	Error = "There is No Errors in the System to show";
}
void Up_Down_Counter(bool Reset, bool UpDown)
{
	if (Reset)
	{
		Pcount = 0;
		Tcount = 0;
		Flags();
	}
	else if (Tcount == 0)
	{
		Pcount = 0;
		Flags();
		Alarm = 1;
		if (UpDown)
		{
			Error = "Pushing Up when there is no Tellers Avaliable ";
		}
		else if (!UpDown)
		{
			Error = "Pushing Down when there is no Tellers Avaliable ";
		}
	}
	else if (UpDown)
	{

		if (Pcount != 7)
		{
			Pcount++;
			Flags();
		}
		else //(Pcount == 7)
		{
			Flags();
			Alarm = 1;
			Error = "(Overflow Error) Pushing Up when the Queue is already Full of 7";
		}
	}
	else if (!UpDown)
	{
		if (Pcount != 0)
		{
			Pcount--;
			Flags();
		}
		else  //(Pcount == 0)
		{
			Flags();
			Alarm = 1;
			Error = "(Underflow Error) Pushing Down when the Queue is already Empty";
		}
	}
}
void setting_Tcount()
{
	cout << "Setting Tcount " << endl
		<< "Enter the Number of Available Tellers between 0 - 3 : ";
	cin >> Tcount;
	while (Tcount < 0 || Tcount > 3)
	{
		cout << "Wrong Number of Available Tellers " << endl
			<< "Enter a number between  0 - 3 : ";
		cin >> Tcount;
	}
}
void setting_Pcount()
{
	if (Tcount == 0)
	{
		Pcount = 0;
		Flags();
		Alarm = 1;
		Error = "Setting Pcount when there is no Tellers Avaliable ";
	}
	else
	{
		cout << "Setting a manual value for Pcount " << endl
			<< "Enter the Number of People in the Queue between 0 - 7 : ";
		cin >> Pcount;
		while (Pcount < 0 || Pcount > 7)
		{
			cout << "Wrong Number of People in the Queue" << endl
				<< "Enter a number between  0 - 7 : ";
			cin >> Pcount;
		}
		Flags();
	}
}
/*
int Wtime_Calculations(int P, int T)
{
	int Wtime = 0;
	if (P == 0 || T == 0)
	{
		Wtime = 0;
	}
	else
	{
		Wtime = 3 * (P + T - 1) / T;total/t
	}
	return Wtime;
}*/
//wtime
int Wtime_Calculations(int P, int T)
{
	int Wtime = 0;
	int total = 0;
	int Multicounts = 3;
	if (P == 0)
	{
		Wtime = 0;
	}
	else
	{
		while (Multicounts != 0)
		{
			total = total + (P + T - 1);
			Multicounts--;
		}
		while (total > 0)
		{
			total = total - T;
			Wtime++;
		}
		if (total < 0)
		{
			Wtime--;
		}
	}
	return Wtime;
}
void display()
{
	cout << "Tcount (Number of Avalible Tellers) = " << Tcount << endl
		<< "Pcount (Number of People in the Queue) = " << Pcount << endl
		<< "Wtime (Waiting Time) = " << Wtime_Calculations(Pcount, Tcount) << " Sec. " << endl
		<< "Empty Flag = " << Empty << endl
		<< "Full Flag = " << Full << endl
		<< "Alarm Flag = " << Alarm << endl;
	if (Empty)
	{
		cout << "The Queue is Empty " << endl;
	}
	else if (Full)
	{
		cout << "The Queue is Full " << endl;
	}
	cout << "Error Happened during Operation : " << Error << endl;
}
void Menu()
{
	int Operation;
	cout << "--------------------------------------------------------------" << endl
		<< "Choose Operation number That you want to be executed " << endl
		<< "1 - Reset the System " << endl
		<< "2 - Push Up the Queue " << endl
		<< "3 - Push Down the Queue " << endl
		<< "4 - Set a Manual value for Pcount " << endl
		<< "5 - Set Tcount " << endl
		<< "6 - Get the Data Saved in System " << endl
		<< "Operation no. : ";
	cin >> Operation;
	do
	{
		switch (Operation)
		{
		case 1:
			cout << "Resetting the System " << endl;
			Up_Down_Counter(true, true);// or (tru , X )
			Operation = -1;
			break;
		case 2:
			cout << "Pushing Up the Queue " << endl;
			Up_Down_Counter(false, true);
			Operation = -1;
			break;
		case 3:
			cout << "Pushing Down the Queue " << endl;
			Up_Down_Counter(false, false);
			Operation = -1;
			break;
		case 4:
			setting_Pcount();
			Operation = -1;
			break;
		case 5:
			setting_Tcount();
			Operation = -1;
			break;
		case 6:
			cout << "Getting the Data Saved in System " << endl;
			display();
			Operation = -1;
			break;
		default:
			do
			{
				cout << "Wrong Operation number Please Enter a Correct Operation number" << endl
					<< "Operation no. : ";
				cin >> Operation;
			} while (Operation < 1 || Operation > 6);
			break;
		}
	} while (Operation >= 1 && Operation <= 6);
}
int main()
{
	char Again = 'x';
	setting_Tcount();
	cout << "Number of People in the Queue = " << Pcount << endl;
	do
	{
		Menu();
		cout << "--------------------------------------------------------------" << endl
			<< "Current Data after Execution of Operation " << endl;
		display();
		cout << "--------------------------------------------------------------" << endl
			<< "If you want to make another Operation Press \'Y\' or \'y\'" << endl
			<< "OR " << endl
			<< "Press another key to Exit " << endl;
		cin >> Again;
	} while (Again == 'y' || Again == 'Y');
	cout << "End of Operations " << endl;
	system("pause");
	return 0;
}