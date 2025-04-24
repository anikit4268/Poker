#include <iostream>
/*Workspace
 *
 */
class Play
{
public:
	// Constructor
	Play()
	{
		bool gameGo = true;
		//Get Starting chips for each player
		float startChips;
		std::cout<<"Enter starting chips: ";
		std::cin>>startChips;

		//Get amount of players
		int playerAmt;
		std::cout << "Enter number of players:";
		std::cin >> playerAmt;

		//Declare arrays for names and chips
		std::string names[playerAmt];
		double chips[playerAmt];
		bool out[playerAmt];

		//Fill all arrays
		for (int i = 0; i < playerAmt; i++)
		{
			std::cout<<"Enter name for player " << i+1<<": ";
			std::cin>>names[i];
			chips[i] = startChips;
			out[i] = false;
		}
		displayBoard(names,chips,playerAmt,out);
		startGame(gameGo,playerAmt, out, names);
	}

private:
	void displayBoard(std::string names[], double chips[], int playerAmt, bool out[])
	{
		std::cout << "Players\tChips\tOut\n";
		for (int i = 0; i < playerAmt; i++)
		{
			std::cout << names[i] << "\t$" << chips[i] << "\t" << out[i] << std::endl;
		}
	}
	int askUser(std::string names[], int turn)
	{
		int choice;
		std::cout << "Player: " << names[turn] << std::endl;
		std::cout << "1.Bet/Raise\n2.Call/Check\n3.Fold\n9.End\nChoose an option:\n";
		std::cin >> choice;
		return choice;
	}
	void startGame(bool gameGo,int playerAmt, bool out[], std::string names[])
	{
		while (gameGo)
		{
			for (int turn = 0; turn < playerAmt; turn++)
			{
				if (out[turn] == true)
				{
					continue;
				}
				//Ask user for choice
				int choice;
				do
				{
					choice = askUser(names, turn);
				}while (choice != 1 && choice != 2 && choice != 3 && choice != 9);
				//Determine players' action
				if (choice==1)//Bet
				{
					std::cout << "Bet\n";

				}else if (choice==2)//Call
				{
					std::cout << "Call\n";

				}else if (choice==3)//Fold
				{
					std::cout << "Fold\n";
					out[turn] = true;

				}else if (choice==9)//END
				{
					std::cout << "END\n";
					gameGo = false;
					break;
				}
			}
		}
	}




};

int main()
{
	//Make object
	Play game();

}