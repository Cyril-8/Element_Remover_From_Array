//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

vector<int> getIndex(vector<int> &array, int &chosen_number);
int getChoice(vector<int> &index, vector<int> &array, int &chosen_number);
int getInput();

int main(){
	vector<int> array, og_array;
	
	int size, chosen_number, choice;
	bool first = true;
	
	do {
			
		if(first){ //lets the user to edit on their existed array instead of making a new one (until they choose option 2)
			cout << "Please enter how many numbers do you want to input:\n" ;
			size = getInput();
	
			array.resize(size); og_array.resize(size);
	
			cout << "\nPlease enter the values of your array:\n";
	
			for(int i=0; i<size; ++i){
				array[i] = getInput();
			}
	
		copy(array.begin(), array.end(), og_array.begin());	
		
		first = !first;	
		}

		cout << "\nPlease enter the element you want to remove:\n";
		chosen_number = getInput();
	
		vector<int> index = getIndex(array, chosen_number);
	
		getChoice(index, array, chosen_number);
	
		cout << "\n\nYour array before changes:\n";
	
		for(int i=0; i < og_array.size(); ++i){
    		if(i < og_array.size()-1)
        		printf("%d, ", og_array[i]);
    		else
        		printf("%d", og_array[i]); 
		}

		cout << "\n\nYour array after changes:\n";
	
		for(int i=0; i < array.size(); ++i){
    		if(i < array.size()-1)
        		printf("%d, ", array[i]);
    		else
        		printf("%d", array[i]); 
		}	
		cout << "\n\nWhat would you like to do?\n\t1. Choose another element to remove\n\t2. Do another array\n\t(ANY Number). Exit the program";
		cout << "\n\nEnter your choice: ";
		choice = getInput();
		
		if(choice == 2) first = !first;
		if (choice != 1 && choice != 2 ){
		cout <<"\n\t\t\tDon't be a stranger. Bye :)";
		}
	}	
	while(choice == 1 || choice == 2);
	
	return 0;
}

vector<int> getIndex(vector<int> &array, int &chosen_number){	//Gets all the indexes that have the chosen element in it (in the switch case of 1)
	vector<int> index; 
	
	for(int i=0; i<array.size(); ++i){
		if (array[i] == chosen_number)
			index.push_back(i);
	}
	
	return index;
} 

int getChoice(vector<int> &index, vector<int> &array, int &chosen_number){
	int choice, amount;	
	
    if (index.size() > 1){
        printf("\nYour element '%d' occurs %d times\n" , chosen_number, index.size());
        for (int i = 0; i < array.size(); ++i) {
            if (i < array.size() - 1) {
                array[i] == chosen_number ? cout << "\033[31m" << array[i] << "\033[0m, " : cout << array[i] << ", "; //this part only make the array look good and make the chosen element stand out in red
            } else {
                array[i] == chosen_number ? cout << "\033[31m" << array[i] << "\033[0m" : cout << array[i];
            }
        }
		cout << "\n\nWould you like to\n\t1. Remove all of them\n\t2. Remove only some of them\n";
		choice = getInput();
		switch(choice){
			case 1: {
				array.erase(remove(array.begin(), array.end(), chosen_number), array.end());
				break;
			} 
			case 2:{
				
				printf("\nHow many %d's would you like to remove\n", chosen_number); //Gets the wanted indexes in an array
				amount = getInput();
				
				printf("\n\nIndexes : ");
				for(int i = 0; i < array.size(); ++i)
					printf("%d\t",i);
				cout << '\n';
								
				printf("\nElements: ");
				for(int i = 0; i < array.size(); ++i)
    				printf("%d\t",array[i]);	
	
				
				printf("\n\nEnter the indexes you want to delete %d from: ", chosen_number); 
				
				int i=0, entered_index;
				vector<int> chosen_indexes(amount);
				
				while(i < amount){ //Makes sure the user doesn't enter more values than the amount they chose
					
					entered_index = getInput();
					
					if(array[entered_index] == chosen_number){ //Makes sure it only count the input as a valid index if it has the element
						chosen_indexes[i] = entered_index;
						
						++i;
					}
					
					else {
						cout << "This index doesn't have " << chosen_number << ". Try again\n";
					}
				}
				
				for(int i = chosen_indexes.size()-1; i >= 0; --i){
					array.erase(array.begin() + chosen_indexes[i]);	
				}
				break;
			}
			default: cout << "Invalid choice"; 
		}
	}

	else if (index.size() == 1 ){	//The size of index is one, which means the number exsits only once, so it just removes it
	array.erase(remove(array.begin(), array.end(), chosen_number), array.end());
	}
	
	else {
		printf("\n'%d' doesn't exist in your array\nTry another value\n", chosen_number);
		
		chosen_number = getInput();
		
		getIndex(array, chosen_number);
		getChoice(index, array, chosen_number);
	}	
	return 0;
}

int getInput() {	//Makes sure that the input is an integer so the program doesn't crash
    while (true) {
    	int choice;
        double value;
        
        cin >> value;

        if (cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\nYou entered character(s). Please enter a whole number.\n";
            
        } else if (value != floor(value)){
            cout << "\nYou entered " << value << " so we rounded it to" << floor(value) << "for you.\n";
            value = floor(value);
            
        } else {
            return static_cast<int>(value);
        }
    }
}
