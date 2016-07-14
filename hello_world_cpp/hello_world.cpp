#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	cout << "Hey Y'all \nWould any of Y'all like some sweat ice tea? (Y/n)" << endl;
	char input;
	cin >> input;
	if (input == 'y' || input == 'Y')
	{
		cout << "Provieds sweat ice tea" << endl;
	}
	else
	{
		cout << "Does not provide sweat ice tea" << endl;
	}
	
	return 0;
}
