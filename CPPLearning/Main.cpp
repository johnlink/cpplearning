#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int getNumHumans();
int getNumSkeletons();
void printResults(int humansCurrent, int humansStart, int skeletonsCurrent, int skeletonsStart);
void simulatBattle(int &humansCurrent, int &skeletonsCurrent);

int main() {

	int humansStart;
	int skeletonsStart;
	int humansCurrent;
	int skeletonsCurrent;

	cout << "*** Skeletons vs Humans ***\n\n";

	humansStart = getNumHumans();
	humansCurrent = humansStart;

	skeletonsStart = getNumSkeletons();
	skeletonsCurrent = skeletonsStart;

	cout << "\nBeginning combat!\n";
	cout << "\n(Combat Noises)\n\n";
	
	simulatBattle(humansCurrent, skeletonsCurrent);

	printResults(humansCurrent, humansStart, skeletonsCurrent, skeletonsStart);

	system("pause");

	return 0;
}

int getNumHumans()
{
	int humans;
	cout << "Input the number of humans: ";
	cin >> humans;

	return humans;
}

int getNumSkeletons()
{
	int skeletons;
	cout << "Input the number of skeletons: ";
	cin >> skeletons;

	return skeletons;
}

void printResults(int humansCurrent, int humansStart, int skeletonsCurrent, int skeletonsStart)
{
	cout << "Combat ended! \n\n";

	if (humansCurrent > 0)
	{
		cout << "Humans win!\nThere are " << humansCurrent << " humans left.\n";
	}
	else {
		cout << "Skeletons win!\nThere are " << skeletonsCurrent << " skeletons left.\n";
	}

	cout << humansStart - humansCurrent << " humans and " << skeletonsStart - skeletonsCurrent << " skeletons lost their lives.\n\n";
}

void simulatBattle(int &humansCurrent, int &skeletonsCurrent)
{
	// Initialize random engine
	static default_random_engine randomGenerator(time(0));
	uniform_real_distribution<float> randomDist(0.0f, 1.0f);

	while (humansCurrent > 0 && skeletonsCurrent > 0)
	{
		if (randomDist(randomGenerator) <= 0.185f)
		{
			humansCurrent--;
		}
		else
		{
			skeletonsCurrent--;
		}
	}
}