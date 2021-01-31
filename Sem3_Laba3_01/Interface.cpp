#include <iostream>
#include "Graph.h"
using namespace std;

int interface() {
	int choice =0;
	cout << "/////////GRAPH/////////\n";
	bool exit = false ;
	bool exit1 = false ;

	while (!exit1){
		int size=0;
		cout << "Write the quantity and the vertexes of a graph: \n" 
			<< " Quantity of elements: ";
		cin >> size;

		int* vertex = new int[size];
		cout << "The vertexes: ";
		for (int i = 0; i < size; i++) {
			cout << "\nVertex" << i <<" : ";
			cin >> vertex[i];
		}

		Graph<int> graph(size, vertex);
		ArraySequence<int> paths;

		cout << "Write the paths for every vertexes: \n";
		for (int i=0; i < size; i++){
			int quant = 0;
			int a = 0;

			cout << vertex[i] << ": \n" "    quantity: ";
			cin >> quant;
			cout << "\n    " << "Paths: ";

			for (int k=0; k < quant; k++){
				cin >> a;
				cout << " ";
				graph.AddPath(vertex[i], a);
			}
		}

		//вывод списка смежности
		cout << "The adjacency list of a graph: \n";
		graph.Print();

		while (!exit)
		{
			int a=0;
			int b=0;
			cout << " Write the vertexes to finding the shortest path: \n"
				<< "From: ";
			cin >> a;
			cout <<"    To: ";
			cin >> b;

			ArraySequence<int>* path = graph.BFS(a, b);
			for (int i=0; i < path->GetLength(); i++){
				if (i != path->GetLength() - 1)
					cout << path->Get(i) + 1 << " -> ";
				else
					cout << path->Get(i) + 1 << "\n";
			}

			cout << "Choose the option: \n"
				<< "1. Find another path \n" 
				<< "2. Change the graph \n" 
				<< "3. Exit \n";

			std::cin >> choice;
			if (choice == 1)
				exit = false;
			if (choice == 2)
				exit = true;
			if (choice == 3){
				exit = true;
				exit1 = true;
			}
		}
	}

	return 0;
}

/*
void Print() {
	/*for (int i(0); i < this->list->GetLength(); ++i)
	{
		if (i % 10 == 0 && i != 0)
			std::cout << this->list->Get(i) << " " << std::endl;
		else
			std::cout << this->list->Get(i) << " ";
	}

	std::cout << " |" << list->Get(0) << "|";
	for (int i(1); i < list->GetLength(); i++)
		std::cout << " --> " << list->Get(i);
	std::cout << " " << std::endl;

} */



int main() {

	interface();

	return 0;
}
