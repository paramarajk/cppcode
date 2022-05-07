#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//Chain of Responsibility

class Command
{
public:
	static vector<Command*> commands;
protected:
	Command(/* this */)
	{
		commands.push_back(this);
	}
public:
	virtual bool Execute(string command, string values, double &value) = 0;
};
vector<Command*> Command::commands;

void main()
{
	double value = 0;
	string command, values;
	while (true)
	{
		cout << value << endl;
		cin >> command >> values;

		for (int i = 0; i < Command::commands.size(); i++)
		{
			if (Command::commands[i]->Execute(command, values, value))
			{
				break;
			}
		}
	}
}


class AddCommand : public Command
{
	bool Execute(string command, string values, double &value)
	{
		if (command == "add")
		{
			value += atof(values.c_str());
			return true;
		}
		else
			return false;
	}
};
AddCommand ac;

class SubtractCommand : public Command
{De
	bool Execute(string command, string values, double &value)
	{
		if (command == "subtract")
		{
			value -= atof(values.c_str());
		}
		else
			return false;
	}
};
SubtractCommand sc;
