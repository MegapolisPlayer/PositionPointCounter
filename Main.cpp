#include <iostream>
#include <string>
#include <vector>

static std::vector<std::vector<uint64_t>> EntriesPositions;

static uint64_t AmountOfEntries;
static uint64_t AmountOfPositions;
static bool LastPointIgnored;

int main(int argc, char **argv) {
	std::cout << "Position Pointer Counter by MegapolisPlayer\nPlease enter amount of items:\n";
	std::cin >> AmountOfEntries;
	std::cout << "Please enter the amount of positions per item:\n";
	std::cin >> AmountOfPositions;
	std::cout << "Please enter whether entry should get a point for last place (Y/n):";
	char Buffer;
	std::cin >> Buffer;
	if(Buffer == 'y' || Buffer == 'Y' || Buffer == '1') {
		LastPointIgnored = true;
	}
	else { LastPointIgnored = false; }
	
	uint64_t PointsMax = (AmountOfEntries - !LastPointIgnored) * AmountOfPositions;
	
	std::cout << "Maximum points: " << PointsMax << "\n";
	
	EntriesPositions.reserve(AmountOfEntries);
	
	uint64_t Temp = 0;
	std::vector<uint64_t> TempVector;
	
	for(uint64_t Id1 = 0; Id1 < AmountOfEntries; Id1++) {
	
		std::cout << "Entry no. " << Id1 << "\n";
		EntriesPositions.push_back(TempVector);
		
		for(uint64_t Id2 = 0; Id2 < AmountOfPositions; Id2++) {
			std::cout << Id1 << " / " << Id2 << ":";
			std::cin >> Temp;
			if(Temp > AmountOfEntries) {
				std::cout << "Position larger than amount of them.\n";
				std::cout << "Press any key and enter to exit!\n";
				std::cin >> Buffer;
				return 1;
			}
			EntriesPositions[Id1].push_back(Temp);
		}
		TempVector.clear();
		std::cout << '\n';
	}
	
	std::cout << "ENTRIES SUMMARY:\n";
	
	for(uint64_t Id1 = 0; Id1 < EntriesPositions.size(); Id1++) {
		for(uint64_t Id2 = 0; Id2 < EntriesPositions[Id1].size(); Id2++) {
			std::cout << EntriesPositions[Id1][Id2] << ", ";
		}
		std::cout << '\n';
	}
	
	std::cout << "----\nCalculating...";
	
	//Make calculation itself
	
	std::vector<uint64_t> FullPoints;
	uint64_t Points = 0;
	
	for(uint64_t Id1 = 0; Id1 < EntriesPositions.size(); Id1++) {
		for(uint64_t Id2 = 0; Id2 < EntriesPositions[Id1].size(); Id2++) {
			Points += (AmountOfPositions - EntriesPositions[Id1][Id2]);
			//std::cout << AmountOfPositions << " - " << EntriesPositions[Id1][Id2] << " = " << AmountOfPositions - EntriesPositions[Id1][Id2] << "\n"; //DEBUG messages
			//std::cout << "PTs: " << Points << "\n";
			if(!LastPointIgnored) { Points++; }
		}
		FullPoints.push_back(Points);
		Points = 0;
	}
	
	std::cout << "Done!\n";
	
	for(uint64_t Id1 = 0; Id1 < FullPoints.size(); Id1++) {
		std::cout << "Entry " << Id1 << ": " << FullPoints[Id1] << '/' << PointsMax << " points.\n";
	}
	
	std::cout << "Press any key and enter to exit!\n";
	std::cin >> Buffer;
	
	return 0;
}
