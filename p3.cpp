#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <ctime>
#include "class_meal.h"
#include "class_din_hall.h"
#include "class_user.h"
#include "class_student.h"
#include "class_reservation.h"
#include "class_transaction.h"
#include "class_shop.h"


using namespace std;









class Admin : public Student{
public:



    // مدیریت وضعیت فعال بودن
    void activateUser(User& user) {
        cout << "User: " << user.getName()<<endl;
        set_active();

    }


    // چاپ اطلاعات Admin
    void print() const {
        cout << "Admin ID: " << getUserID() << ", Name: " << getName() << " " << getLastName() << endl;
    }
};



class Panel : public Reservation,Student {
    int k;
public:
    // نمایش منو
    void showMenu() {
        cout << "1. display student information\n";
        cout << "2. show credit\n";
        cout << "3. view reservations\n";
        cout << "4. add reservation\n";
        cout << "5. add to cart\n";
        cout << "6. purchase confirmation\n";
        cout << "7. cancel the reservation\n";
        cout << "8. EXIT";
    }

    void Switch(){
        cin>>k;

    switch(k)
    {
    case 1:
        showStudentInfo();
        break;
    case 2:
        break;
    case 3:
        viewReservations();
        break;
    case 4:
        addReservation();
        break;
    case 5:
        addToShoppingCart();
        break;
    case 6:
        confirmShoppingCart();
        break;
    case 7:
        cancelReservation();
        break;
    case 8:
        exit();
        break;
    default:
        break;






    }}

    // توابع مربوط به تعاملات کاربری
    void showStudentInfo();
    void checkBalance();
    void viewReservations();
    void addReservation();
    void addToShoppingCart();
    void confirmShoppingCart();
    void removeShoppingCartItem();
    void increaseBalance();
    void cancelReservation(){cancel();};
    void exit();
};

int main(){



return 0;
}
