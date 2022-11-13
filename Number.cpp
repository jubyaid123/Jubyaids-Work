#include <iostream>
#include <vector>

using namespace std;


int main(){
    
    char user_selection {};
    vector <int> number;
    int new_number;
    
    do {
        
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;    
    cout << "S - Display the smallest number" << endl;    
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> user_selection;
    
    switch ( user_selection){
        
        case 'a':
        case 'A':
        cout << "Enter an integer to add to the list: ";
        cin >> new_number;
        cout << new_number << " added" << endl; 
        cout << endl;
        number.push_back(new_number);
        break;
        
        case 'p':
        case 'P':
        cout << "[ ";
            if (number.size() > 0){
                for ( int i=0 ; i < number.size(); i++)
               cout << number.at(i) << " " ;
               cout << "]";
               cout << endl;
               cout << endl;
            }else
                cout << "] - the list is empty" << endl;
            
        break;
        
        case 'm' :
        case 'M' :
        {
        double sum {};
    
            for ( int i = 0 ; i < number.size(); i++){
                sum = sum + number.at(i);
    }
    
        double mean {};
        mean = sum / number.size();
        cout << "The mean is: " << mean << endl;
        cout << endl;
        
        } 
        break;
        
        case 's' :
        case 'S' :
        {
        int smallest_number {number.at(0)};
        for ( int i = 0 ; i < number.size(); i++){
            if ( number.at(i) < number.at(0) ) {
                smallest_number = number.at(i);
            } 
        }
        cout << "The smallest number is: " << smallest_number << endl;
        cout << endl;
        }
        break;
        
        case 'l' :
        case 'L' :
        {
        int largest_number {number.at(0)};
        for ( int i = 0 ; i < number.size(); i++){
            if (number.at(i) > number.at(0) ) {
                largest_number = number.at(i);
            }
        }
        cout << "The largest number is: " << largest_number << endl;
        cout << endl;
        }
        break;
        
        case 'q' :
        case 'Q' :
        cout << "goodbye..." << endl;
        break;
        
        
        
        default: 
        cout << "Unknown selection, please try again" << endl;
        cout << endl;
        
        
    }
       
            
    
    }while ( user_selection != 'q' && user_selection != 'Q');
    
    
    
    return 0;

    }
