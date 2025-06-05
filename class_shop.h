#ifndef CLASS_SHOP_H_INCLUDED
#define CLASS_SHOP_H_INCLUDED

using namespace std;

class ShoppingCart {
private:
    vector<Reservation> _reservations;
public:
    Transaction confirm();


void addReservation(const Reservation& reservation) {
    _reservations.push_back(reservation);
}

void removeReservation(int ID) {
    _reservations.erase(
        remove_if(_reservations.begin(), _reservations.end(),
                  [ID](const Reservation& res) { return res.get_reservation_id() == ID; }),
        _reservations.end());
}

void viewShoppingCartItems() const {
    for (const auto& res : _reservations) {
        cout << "Reservation ID: " << res.get_reservation_id()  << endl;
    }
}

void clear() {
    _reservations.clear();
}

vector<Reservation> getReservations() const {
    return _reservations;
}

};
#endif // CLASS_SHOP_H_INCLUDED
