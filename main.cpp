#include <iostream>
#include <fstream>
using namespace std;

// Comment#1: Define a struct named Restaurant.
struct Restaurant 
{
    string name;
    string address;
    string cuisineType;
    int rating; // Comment#2: Rating from 1 to 5.
    bool dineOption;
};

Restaurant populateRestaurant();
void outputRestaurant(const Restaurant& restaurant);

int main()
{
    Restaurant restaurant = populateRestaurant();
    cout << endl << "Outputting single restaurant in single struct:" << endl;
    outputRestaurant(restaurant);
    cout << endl;

     // Comment#3: Create an array of 3 Restaurant structs.
    Restaurant restaurantCollection[3];

    for (int i = 0; i < 3; i++) 
    {
        Restaurant temp = populateRestaurant();

        // Comment#4: Store each populated struct into the array.
        restaurantCollection[i] = temp;
    }

    // Comment#5: Output all restaurants in the array.
    cout << endl;
    cout << "Outputting array of restaurants:" << endl;
    for (int i = 0; i < 3; i++) 
    {
        cout << endl;
        cout << "Restaurant #" << i + 1 << ":" << endl;
        outputRestaurant(restaurantCollection[i]);
    }    

    cout << endl << endl;

    return 0;
}

Restaurant populateRestaurant() 
{
    // Comment#6: Populate a Restaurant struct with user input.
    Restaurant restaurant;
    
    cout << endl;
    
    cout << "Enter restaurant name: ";
    getline(cin, restaurant.name);

    cout << "Enter restaurant address: ";
    getline(cin, restaurant.address);

    cout << "Enter cuisine type: ";
    getline(cin, restaurant.cuisineType);

    cout << "Enter restaurant rating (1-5): ";
    cin >> restaurant.rating;
    // Comment#7: Validate rating input.
    while (restaurant.rating < 1 || restaurant.rating > 5) 
    {
        cout << "\t> ERROR: Rating must be between 1 and 5: ";
        cin >> restaurant.rating;
    }

    cin.ignore(); // Comment#8: To ignore the newline character after integer input.

    cout << "Does the restaurant offer dine-in option? (Y for Yes, N for No): ";
    char dineInput;
    cin >> dineInput;
    // Comment#9: Validate dine-in option input.
    while (!(dineInput == 'Y' || dineInput == 'y' || dineInput == 'N' || dineInput == 'n')) 
    {
        cout << "\t> ERROR: y/Y/n/N only: ";
        cin >> dineInput;
    }

    restaurant.dineOption = (dineInput == 'Y' || dineInput == 'y');
    
    cin.ignore(); 

    return restaurant;
}

void outputRestaurant(const Restaurant& restaurant)
{
    // Comment#10: Output the details of a Restaurant struct.
    cout << endl << "Restaurant Details:" << endl;
    cout << "Name: " << restaurant.name << endl;
    cout << "Address: " << restaurant.address << endl;
    cout << "Cuisine Type: " << restaurant.cuisineType << endl;
    cout << "Rating: " << restaurant.rating << endl;
    cout << "Dine-in Option: " << (restaurant.dineOption ? "Yes" : "No") << endl;
}