
#include <iostream>


using namespace std;

void guess_number(int, int);

int main(int argc, const char * argv[]) {
    
    guess_number(1, 100);
    
}

void guess_number(int low, int high)
{
    int mid_left = (low+high)/2; // left-most center number
    int mid_right = mid_left + 1; // right-most center number
    char choice = 'X';
    int question_count = 0;
    
    for (question_count = 1; abs(high - low) >= 2; question_count++) // loop while range of numbers is at least 2
    {
        cout << "Question #" << question_count << endl;
        cout << "Is your number between " << low << " and " << mid_left << "? (enter Y or N): " << endl; // determine in number exist in left half of range
        cin >> choice;
     
        while (choice != 'Y' && choice != 'N') // check for bad input
        {
            cout << "Bad input, try again: " << endl;
            cin >> choice;
        }
        
        if (choice == 'Y') // if number exist in left half of range, assign leftmost center number as the highest/maximum range number
            high = mid_left;
        else
            low = mid_right; // else, number will exist in right half of range, and assign rightmost center number as the lowest/minimum range number
        
        mid_left = abs( (low+high)/2 ); // re-establish center numbers based on new range
        mid_right = mid_left + 1;
        
        
    } // exit loop when remaining option is between 2 numbers
    
    cout << "Question #" << question_count << endl;
    cout << "Is your number " << low << "? (enter Y or N): " << endl; // determine if the number is the first out of the 2
    cin >> choice;
    while (choice != 'Y' && choice != 'N') // check for bad input
    {
        cout << "Bad input, try again: " << endl;
        cin >> choice;
    }
    
    if (choice == 'Y')
        cout << "Your number is " << low << endl; // the number is the first out of the 2
    else
        cout << "Your number is " << high << endl; // if not, by default, the number will the second out of the 2
  
    
}
