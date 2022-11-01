#include<iostream>
#include<cassert>
using namespace std;
#include"Computer.h"
#include"ComputerStore.h"

int main()
{
	Computer* c1 = new Computer("Dell", "Silver", 2019, "Core I5 8", 8, 256);
	Computer* c2 = new Computer("Asus", "Silver", 2018, "Core I7 7", 8, 256);
	Computer* c3 = new Computer("Asus", "Black", 2021, "Ryzen 7 6800", 16, 1024);
	Computer** computers = new Computer*[3] { c1,c2,c3 };
	ComputerStore* computerStore = new ComputerStore("compstore",computers,3);
	computerStore->getComputersByColor("Silver")[1]->print();
}