#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
fstream fileCustomer, CarFile, AvailableFile, temp;
class Customer {
protected:
    string name;
    string cnic;
    string phone;
    string address;
    string make;
    string model;
    string year;
    string TransT;
    string Mile;
    string GPS;
    string ABS;
    string dailyRate;
    string AC;
    double Customer_ID = 0;
    string Car_ID;

public:
    virtual void addCustomer() = 0;
    virtual void saveToFile() = 0;
    virtual void addCar() = 0;
    virtual void enterCarInfo() = 0;
    virtual void showCustomers() = 0;
    virtual void SelectCar() = 0;
    bool checkname(string name) {
        for (int i = 0; i < name.length(); i++) {        
            if (!((name[i] >= 'a' && name[i]<= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' ')) {
                return false;
            }
        }
        return true;
    }
    bool checkcnic(string cnic) {
        if (!(cnic.length() == 13)) {
            return false;
        }
        for (int k = 0; k < cnic.length(); k++) {       
            if (cnic[k] < '0' || cnic[k] > '9') {
                return false;
            }
        }
        return true;
    }
    bool checkaddress(string address) {
        for (int i = 0; i < address.length(); i++) { 
            if (!((address[i] >= 'a' && address[i] <= 'z') || (address[i] >= 'A' && address[i] <= 'Z') || address[i] == ' ' || (address[i] >= '0' && address[i] <= '9') || address[i]=='-' || address[i]=='/')) {
                return false;
            }
        }
        return true;
    }
    bool checkphoneNo(string phone) {
        if (phone.size() != 11) {
            return false;
        }
        for (int i = 0; i < 11; i++) {
            if (phone[i] < '0' || phone[i] > '9')
            {
                return false;
            }
        }
        return true;
    }
    bool checknumeric(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] < '0' || str[i] > '9')
            {
                return false;
            }
        }
        return true;
    }
    bool checkdate(string d) {
        for (int i = 0; i < d.length(); i++) {
            if (!( (d[i] >= '0' && d[i] <= '9') || d[i] == '/')) {
                return false;
            }
        }
        return true;
    }
};
class Car : public Customer {
public:
    string get_ID() {
        string line;
        int ID = 0;
        string customer_ID;
        ifstream fileCustomer("Customers.txt", ios::in);
        if (!fileCustomer.is_open()) {
            cout << "Cannot open file" << endl;
            return "1";
        }
        while (getline(fileCustomer, customer_ID, '.') && getline(fileCustomer, line)) {
            ID = stoi(customer_ID);
        }
        fileCustomer.close();
        ID = ID + 1;
        string newID = to_string(ID);
        return newID;
    }
    virtual void addCar() {}
    virtual void enterCarInfo() {}
    virtual void SelectCar() {}
    void addCustomer() override {
        system("Color 0B");
        bool valid = false;
        Customer_ID = Customer_ID + 1;
        bool flag = true;
        cin.ignore();
        do {
            cout << "Enter your name(alphabets only):" << endl;
            getline(cin, name);
        } while (!checkname(name));
        do {
            cout << "Enter CNIC(13 digits only): " << endl;
            getline(cin, cnic);
        } while (!checkcnic(cnic));
        do {
            cout << "Enter your phone number(11 digits only):" << endl;
            getline(cin, phone);
        } while (!checkphoneNo(phone));
        do {
            cout << "Enter address(alphabets,digits,/,-) :" << endl;
            getline(cin, address);
        } while (!checkaddress(address));
        saveToFile();
    }
    void saveToFile() override {
        system("Color 06");
        string newID = get_ID();
        ofstream fileCustomer("Customers.txt", ios::app);
        if (!fileCustomer.is_open()) {
            cout << "Cannot open file" << endl;
            return;
        }
        fileCustomer << newID << "." << name << "," << cnic << "," << phone << "," << address
            << endl;
        cout << "Customer added successfully" << endl;
        fileCustomer.close();
    }
    void showCustomers() {
        system("Color 05");
        string Customer_ID;
        cout << "\nCUSTOMER HISTORY:" << endl;
        ifstream myfile("Customers.txt", ios::in);
        if (!myfile.is_open()) {
            cout << "Cannot open file." << endl;
        }
        while (getline(myfile, Customer_ID, '.') && getline(myfile, name, ',') && getline(myfile, cnic, ',') && getline(myfile, phone, ',') && getline(myfile, address)) {

            cout << name << " " << cnic << " " << phone << " " << address << " "
                << endl;
        }
        myfile.close();
    }
};
class ZAW_Motors : public Customer {
public:
    string getLCar_ID() {
        string line;
        int ID = 0;
        string customer_ID;
        ifstream fileCustomer("LuxuryCar.txt", ios::in);
        if (!fileCustomer.is_open()) {
            cout << "Cannot open LuxuryCar file" << endl;
            return "1";
        }
        while (getline(fileCustomer, customer_ID, '.') && getline(fileCustomer, line)) {
            ID = stoi(customer_ID);
        }
        fileCustomer.close();
        ID = ID + 1;
        string newID = to_string(ID);
        return newID;
    }
    string getECar_ID() {
        string line;
        int ID = 0;
        string customer_ID;
        ifstream fileCustomer("EconomyCar.txt", ios::in);
        if (!fileCustomer.is_open()) {
            cout << "Cannot open file" << endl;
            return "1";
        }
        while (getline(fileCustomer, customer_ID, '.') && getline(fileCustomer, line)) {
            ID = stoi(customer_ID);
        }
        fileCustomer.close();
        ID = ID + 1;
        string newID = to_string(ID);
        return newID;
    }
    void addCustomer() override {}
    void saveToFile() override {}
    void showCustomers() override {}
    void SelectCar() {}
    void enterCarInfo() {
        system("Color 0B");
        cin.ignore();
        do {
            cout << "Enter Car Make:" << endl;
            getline(cin, make);
        } while (!checkname(make));
        do {
            cout << "Enter Model:" << endl;
            getline(cin, model);
        } while (!checkaddress(model));
        do {
            cout << "Enter Year:" << endl;
            getline(cin, year);
        } while (!checknumeric(year));
        do {
            cout << "Enter Transmission Type(Manual or Auto):" << endl;
            getline(cin, TransT);
        } while (!(TransT == "manual" || TransT == "Manual" || TransT == "auto" || TransT == "Auto"));
        do {
            cout << "Enter Mileage:" << endl;
            getline(cin, Mile);
        } while (!checknumeric(Mile));
        do {
            cout << "Enter GPS availabity(yes or no):" << endl;
            getline(cin, GPS);
        } while (!(GPS == "yes" || GPS == "Yes" || GPS == "No" || GPS == "no"));
        do {
            cout << "Enter ABS availabity(yes or no):" << endl;
            getline(cin, ABS);
        } while (!(ABS == "yes" || ABS == "Yes" || ABS == "No" || ABS == "no"));
        do {
            cout << "Enter AC availabity(yes or no):" << endl;
            getline(cin, AC);
        } while (!(AC == "yes" || AC == "Yes" || AC == "No" || AC == "no"));
        do {
            cout << "Enter Daily Rate:" << endl;
            getline(cin, dailyRate);
        } while (!checknumeric(dailyRate));
    }
    void addCar() override {
        system("Color 0A");
        string Car_ID;
        char type;
        cout << "What type of Car (Luxury(L or l) or Economy(E or e))?" << endl;
        cin >> type;
        while (type != 'L' && type != 'l' && type != 'E' && type != 'e') {
            cout << "Enter correct choice:" << endl;
            cin >> type;
        }
        if (type == 'L' || type == 'l') {
            enterCarInfo();
            Car_ID = getLCar_ID();
            ofstream fileCustomer("LuxuryCar.txt", ios::app);
            if (!fileCustomer.is_open()) {
                cout << "Cannot open file" << endl;
            }
            fileCustomer << Car_ID << "." << make << "," << model << "," << year << "," << TransT
                << "," << Mile << "," << GPS << "," << ABS << "," << AC
                << "," << dailyRate << endl;
            cout << "Car Details added successfully" << endl;
            fileCustomer.close();
        }
        else if (type == 'E' || type == 'e') {
            enterCarInfo();
            Car_ID = getECar_ID();
            ofstream fileCustomer("EconomyCar.txt", ios::app);
            if (!fileCustomer.is_open()) {
                cout << "Cannot open file" << endl;
            }
            fileCustomer << Car_ID << "." << make << "," << model << "," << year << "," << TransT
                << "," << Mile << "," << GPS << "," << ABS << "," << AC
                << "," << dailyRate << endl;
            cout << "Car Details added successfully" << endl;
            fileCustomer.close();
        }
    }
};
class LuxuryCar {
public:
    virtual void LxCarHistory() = 0;
    virtual void ReturnCar() = 0;
};
class EconomyCar {
public:
    virtual void EnCarHistory() = 0;
    virtual int Transmission_Cost(string TransT) = 0;
    virtual int Mile_Cost(string Mile) = 0;
    virtual int GPS_Cost(string GPS) = 0;
    virtual int ABS_Cost(string ABS) = 0;
    virtual int AC_Cost(string AC) = 0;
};
class RentalTransaction : public Customer, public LuxuryCar, public EconomyCar {
private:
    int yy;
    int dd;
    int mm;
    int cost = 0;
public:
    virtual void addCustomer() {}
    virtual void addCar() {}
    virtual void enterCarInfo() {}
    virtual void showCustomers() {}
    virtual void saveToFile() {}
    void EnmakeUnAvailable(string ID) {
        string id, line;
        ifstream AvailableFile("EnAvailStatus.txt", ios::in);
        ofstream CarFile("temp.txt", ios::out);
        if (!AvailableFile.is_open()) {
            cout << "Cannot open Economy Availability file" << endl;
        }
        else {
            while (getline(AvailableFile, id, '.') && getline(AvailableFile, line)) {
                if (id == ID && line == "Available ") {
                    CarFile << id << "." << "Rented" << endl;
                }
                else {
                    CarFile << id << "." << line << endl;
                }
            }
        }
        AvailableFile.close();
        CarFile.close();
        remove("EnAvailStatus.txt");
        rename("Temp.txt", "EnAvailStatus.txt");
    }
    void LxmakeUnAvailable(string ID) {
        string id, line;
        ifstream AvailableFile("LxAvailStatus.txt", ios::in);
        ofstream CarFile("temp.txt", ios::out);
        if (!AvailableFile.is_open()) {
            cout << "Cannot open Luxury availability file" << endl;
        }
        else {
            while (getline(AvailableFile, id, '.') && getline(AvailableFile, line)) {
                if (id == ID && line == "Available ") {
                    CarFile << id << "." << "Rented" << endl;
                }
                else {
                    CarFile << id << "." << line << endl;
                }
            }
        }
        AvailableFile.close();
        CarFile.close();
        remove("LxAvailStatus.txt");
        rename("Temp.txt", "LxAvailStatus.txt");
    }
    bool LxisAvailable(string ID) {
        string line, id;
        ifstream AvailableFile("LxAvailStatus.txt", ios::in);
        if (!AvailableFile.is_open()) {
            cout << "Cannot open availability status File" << endl;
        }
        else {
            while (getline(AvailableFile, id, '.') && getline(AvailableFile, line)) {
                if (id == ID && line == "Available ") {
                    return true;
                }
            }
        }
        return false;
    }
    bool EcisAvailable(string ID) {
        string line, id;
        ifstream AvailableFile("EnAvailStatus.txt", ios::in);
        if (!AvailableFile.is_open()) {
            cout << "Cannot open availability status File." << endl;
        }
        else {
            while (getline(AvailableFile, id, '.') && getline(AvailableFile, line)) {
                if (id == ID && line == "Available ") {
                    return true;
                }
            }
        }
        return false;
    }
    virtual int Transmission_Cost(string TransT) {

        if (TransT == "Manual") {
            cost = 15;
        }
        else {
            cost = 50;
        }
        return cost;
    }
    virtual int Mile_Cost(string Mile) {
        int Miles = stoi(Mile);
        if (Miles >= 0 && Miles <= 100) {
            cost = 25;
        }
        else {
            cost = -25;
        }
        return cost;
    }
    virtual int ABS_Cost(string ABS) {
        if (ABS == "yes") {
            cost = 10;
        }
        return cost;
    }
    virtual int GPS_Cost(string GPS) {
        if (GPS == "yes") {
            cost = 10;
        }
        return cost;
    }
    virtual int AC_Cost(string AC) {
        if (AC == "yes") {
            cost = 15;
        }
        return cost;
    }
    string startDate() {
        system("Color 03");
        string Sdate;
        cin.ignore();
        do {
            cout << "Please input the start date of the rental period using the format:dd/mm/yyyy: ";
            getline(cin, Sdate);
        } while (!checkdate(Sdate));
        return Sdate;
    }
    string EndDate() {
        string Edate;
        cin.ignore();
        do {
            cout << "Please input the end date of the rental period using the format:dd/mm/yyyy: ";
            getline(cin, Edate);
        } while (!checkdate(Edate));
        return Edate;
    }
    int TotalDays(string Sdate, string Edate) {
        int dd1, mm1, yy1, dd2, mm2, yy2;
        stringstream ss(Sdate);
        getline(ss, Sdate, '/');
        dd1 = stoi(Sdate);
        getline(ss, Sdate, '/');
        mm1 = stoi(Sdate);
        getline(ss, Sdate);
        yy1 = stoi(Sdate);
        stringstream s2(Edate);
        getline(s2, Sdate, '/');
        dd2 = stoi(Sdate);
        getline(s2, Sdate, '/');
        mm2 = stoi(Sdate);
        getline(s2, Sdate);
        yy2 = stoi(Sdate);
        int startdays = yy1 * 360 + mm1 * 30 + dd1;
        int enddays = yy2 * 360 + mm2 * 30 + dd2;
        return (enddays - startdays);
    }
    virtual void saveToFile(char type, string ID, string make, string model, string year, string Sdate, string Edate) {
        ofstream AvailableFile("TransactionHistory", ios::app);
        if (!AvailableFile.is_open()) {
            cout << "Cannot open transactions file" << endl;
        }
        else {
            if (type == 'e' || type == 'E') {
                AvailableFile << "Economy: " << ID << "." << make << " " << model << " " << year << " rented from" << " " << Sdate << " to " << Edate << endl;
            }
            else if (type == 'l' || type == 'L') {
                AvailableFile << "Luxury: " << ID << "." << make << " " << model << " " << year << " rented from" << " " << Sdate << " to " << Edate << endl;
            }
        }
    }
    void TotalBill(char type, string ID, string make, string model, string year, string TransT, string Mile, string GPS, string ABS, string AC, string dailyRate) {
        system("Color 0D");
        int totalCost = 0;
        int choice;
        cout << "Are you sure you want to continue with this? (Press 0 to confirm , anything else to reject)" << endl;
        cin >> choice;
        if (choice == 0 && (type == 'l' || type == 'L')) {
            string Sdate = startDate();
            string Edate = EndDate();
            int totalDays = TotalDays(Sdate, Edate);
            totalCost = Transmission_Cost(TransT) + Mile_Cost(Mile) + GPS_Cost(GPS) + ABS_Cost(ABS) + AC_Cost(AC) + (stoi(dailyRate) * totalDays);
            cout << "Total Cost of " << make << " " << model << ": " << endl;
            cout << totalCost << endl;
            LxmakeUnAvailable(ID);
            saveToFile(type, ID, make, model, year, Sdate, Edate);
        }
        else if (choice == 0 && (type == 'e' || type == 'E')) {
            string Sdate = startDate();
            string Edate = EndDate();
            int totalDays = TotalDays(Sdate, Edate);
            totalCost = Transmission_Cost(TransT) + Mile_Cost(Mile) + GPS_Cost(GPS) + ABS_Cost(ABS) + AC_Cost(AC) + (stoi(dailyRate) * totalDays);
            cout << "Total Cost of " << make << " " << model << ": " << endl;
            cout << "$" << totalCost << endl;
            EnmakeUnAvailable(ID);
            saveToFile(type, ID, make, model, year, Sdate, Edate);
        }
    }
    virtual void LxCarHistory() override {
        system("Color 09");
        cout << "\nLUXURY CAR HISTORY:" << endl;
        ifstream myfile("LuxuryCar.txt", ios::in);
        if (!myfile.is_open()) {
            cout << "Cannot open file:(" << endl;
        }
        while (!myfile.eof()) {
            getline(myfile, make, ',');
            getline(myfile, model, ',');
            getline(myfile, year, ',');
            getline(myfile, TransT, ',');
            getline(myfile, Mile, ',');
            getline(myfile, GPS, ',');
            getline(myfile, ABS, ',');
            getline(myfile, AC, ',');
            getline(myfile, dailyRate);
            cout << make << " " << model << " " << year << " " << TransT << " "
                << Mile << " " << GPS << " " << ABS << " " << AC << " " << dailyRate
                << endl;
        }
        myfile.close();
    }
    virtual  void EnCarHistory() {
        system("Color 09");
        cout << "\nECONOMY CAR HISTORY:" << endl;
        ifstream myfile("EconomyCar.txt", ios::in);
        if (!myfile.is_open()) {
            cout << "Cannot open file:(" << endl;
        }
        while (!myfile.eof()) {
            getline(myfile, make, ',');
            getline(myfile, model, ',');
            getline(myfile, year, ',');
            getline(myfile, TransT, ',');
            getline(myfile, Mile, ',');
            getline(myfile, GPS, ',');
            getline(myfile, ABS, ',');
            getline(myfile, AC, ',');
            getline(myfile, dailyRate);
            cout << make << " " << model << " " << year << " " << TransT << " "
                << Mile << " " << GPS << " " << ABS << " " << AC << " " << dailyRate
                << endl;
        }
        myfile.close();
    }
    virtual void SelectCar() {
        bool found = false;
        string ID, Cname, Cmodel;
        char type;
        cout << "Enter the Type of Car you want to rent (Luxury (L or l) or Economy (E or e))" << endl;
        cin >> type;
        while (type != 'L' && type != 'l' && type != 'E' && type != 'e') {
            cout << "Enter correct choice:" << endl;
            cin >> type;
        }
        if (type == 'l' || type == 'L') {
            LxCarHistory();
            do {
                cout << "Enter the Exact Name of Car you want to rent:" << endl;
                cin >> Cname;
            } while (!checkname(Cname));
            do {
                cout << "Enter Exact Model of the Car you want to rent:" << endl;
                cin >> Cmodel;
            } while (!checkaddress(Cmodel));
            ifstream CarFile("LuxuryCar.txt");
            while (getline(CarFile, ID, '.') && getline(CarFile, make, ',') && getline(CarFile, model, ',') && getline(CarFile, year, ',') && getline(CarFile, TransT, ',')
                && getline(CarFile, Mile, ',')
                && getline(CarFile, GPS, ',')
                && getline(CarFile, ABS, ',')
                && getline(CarFile, AC, ',')
                && getline(CarFile, dailyRate)) {
                if (Cname == make && Cmodel == model) {
                    cout << ID << "." << make << " " << model << endl;
                    cout << "Year of manufacture: " << year << endl;
                    cout << "Transmission Type: " << TransT << endl;
                    cout << "Mileage: " << Mile << endl;
                    cout << "GPS avaialbity: " << GPS << endl;
                    cout << "ABS availabity: " << ABS << endl;
                    cout << "AC availabity: " << AC << endl;
                    cout << "Daily Rate: " << dailyRate << endl;
                    if (LxisAvailable(ID)) {
                        found = true;
                        TotalBill(type, ID, make, model, year, TransT, Mile, GPS, ABS, AC, dailyRate);
                    }
                }
            }
            CarFile.close();
            if (!found) {
                cout << "Car not available currently" << endl;
            }
        }
        else if (type == 'e' || type == 'E') {
            EnCarHistory();
            do {
                cout << "Enter the Name of Car you want to rent:" << endl;
                cin >> Cname;
            } while (!checkname(Cname));
            do {
                cout << "Enter Model of the Car you want to rent:" << endl;
                cin >> Cmodel;
            } while (!checkname(Cmodel));
            ifstream CarFile("EconomyCar.txt");
            while (getline(CarFile, ID, '.') && getline(CarFile, make, ',') && getline(CarFile, model, ',') && getline(CarFile, year, ',') && getline(CarFile, TransT, ',')
                && getline(CarFile, Mile, ',')
                && getline(CarFile, GPS, ',')
                && getline(CarFile, ABS, ',')
                && getline(CarFile, AC, ',')
                && getline(CarFile, dailyRate)) {
                if (Cname == make && Cmodel == model) {
                    cout << ID << "." << name << " " << model << endl;
                    cout << "Year of manufacture: " << year << endl;
                    cout << "Transmission Type: " << TransT << endl;
                    cout << "Mileage: " << Mile << endl;
                    cout << "GPS avaialbity: " << GPS << endl;
                    cout << "ABS availabity: " << ABS << endl;
                    cout << "AC availabity: " << AC << endl;
                    cout << "Daily Rate: " << dailyRate << endl;
                    if (EcisAvailable(ID)) {
                        found = true;
                        TotalBill(type, ID, make, model, year, TransT, Mile, GPS, ABS, AC, dailyRate);
                    }
                }
            }
            if (!found) {
                cout << "Car not available currently!" << endl;
            }
        }
        else
            cout << "Enter valid option." << endl;
        CarFile.close();
    }
    void lxmakeAvailable(string ID) {
        string status;
        ofstream temp("temp.txt", ios::app);
        ifstream CarFile("LxAvailStatus.txt", ios::in);

        while (getline(CarFile, Car_ID, '.') && getline(CarFile, status)) {
            if (Car_ID == ID && status == "Rented") {
                status = "Available";
            }
            temp << Car_ID << "." << status << endl;
        }
        temp.close();
        CarFile.close();
        remove("LxAvailStatus.txt");
        rename("temp.txt", "LxAvailStatus.txt");
    }
    void EnmakeAvailable(string ID) {
        string status;
        ofstream temp("temp.txt", ios::app);
        ifstream CarFile("EnAvailStatus.txt", ios::in);
        while (getline(CarFile, Car_ID, '.') && getline(CarFile, status)) {
            if (Car_ID == ID && status == "Rented") {
                status = "Available";
            }
            temp << Car_ID << "." << status << endl;
        }
        temp.close();
        CarFile.close();
        remove("EnAvailStatus.txt");
        rename("temp.txt", "EnAvailStatus.txt");
    }
    void ReturnCar() {
        system("Color 0E");
        char choice;
        string ID;
        cout << "Enter type of Car , Luxury(L or l) or Economy(E or e)" << endl;
        cin >> choice;
        while (choice != 'L' && choice != 'l' && choice != 'E' && choice != 'e') {
            cout << "Enter correct choice:" << endl;
            cin >> choice;
        }
        do {
            cout << "Enter ID: " << endl;
            cin >> ID;
        } while (!checknumeric(ID));
        if (choice == 'l' || choice == 'L') {
            ifstream CarFile("LuxuryCar.txt", ios::in);
            while (getline(CarFile, Car_ID, '.') && getline(CarFile, make, ',') && getline(CarFile, model, ',') && getline(CarFile, year, ',') && getline(CarFile, TransT, ',') && getline(CarFile, Mile, ',') && getline(CarFile, GPS, ',') && getline(CarFile, ABS, ',') && getline(CarFile, AC, ',') && getline(CarFile, dailyRate)) {
                if (Car_ID == ID) {
                    cout << "Car ID found" << endl;
                    lxmakeAvailable(ID);
                    cout << make << " with ID " << ID << " has been returned " << endl;
                }
            }
            CarFile.close();
        }
        else if (choice == 'e' || choice == 'E') {
            ifstream CarFile("EconomyCar.txt", ios::in);
            while (getline(CarFile, Car_ID, '.') && getline(CarFile, make, ',') && getline(CarFile, model, ',') && getline(CarFile, year, ',') && getline(CarFile, TransT, ',') && getline(CarFile, Mile, ',') && getline(CarFile, GPS, ',') && getline(CarFile, ABS, ',') && getline(CarFile, AC, ',') && getline(CarFile, dailyRate)) {
                if (Car_ID == ID) {
                    cout << "Car ID found" << endl;
                    EnmakeAvailable(ID);
                    cout << make << " with ID " << ID << " has been returned " << endl;
                }
            }
        }
    }
};
void displayMainMenu() {
    char choice,chr;
    EconomyCar* En = nullptr;
    LuxuryCar* Lx = nullptr;
    Customer* Select = nullptr;
    Customer* p1 = new Car;
    Customer* p2 = nullptr;
    LuxuryCar* p4 = new RentalTransaction;
    system("Color 70");
    cout << "\n\n\n\t\t.........:::ZAW MOTORS:::........";
    cout << "\n\t\t:: press 1 to add a customer   :: ";
    cout << "\n\t\t:: press 2 to add a car        ::";
    cout << "\n\t\t:: press 3 to rent a car       ::";
    cout << "\n\t\t:: press 4 to return a car     ::";
    cout << "\n\t\t:: press 5 for customer info   ::";
    cout << "\n\t\t:: press 6 for car information ::";
    cout << "\n\t\t:: press 7 to exit             ::";
    cout << "\n\t\t::.............................::\n\t\t\t\t";
    cin >> choice;
    switch (choice) {
    case '1':
        system("CLS");
        p1->addCustomer(); 
        cout << "\nPress Enter key to continue....." << endl;
        cin.get(chr);
        do {
            if (chr == '\n') {
               // cin.ignore();
                system("CLS");
                displayMainMenu();
            }
        } while (chr != '\n');
        displayMainMenu();
        break;
    case '2':
        system("CLS");
        p2 = new ZAW_Motors;
        p2->addCar();  
        cout << "\nPress Enter key to continue....." << endl;
        cin.get(chr);
        do {
            if (chr == '\n') {
               // cin.ignore();
                system("CLS");
                displayMainMenu();
            }
        } while (chr != '\n');
        displayMainMenu();
        break;
    case '3':
        system("CLS");
        Select = new RentalTransaction;
        Select->SelectCar(); 
        cout << "\nPress Enter key to continue....." << endl;
        cin.get(chr);
        do {
            if (chr == '\n') {
                //cin.ignore();
                system("CLS");
                displayMainMenu();
            }
        } while (chr != '\n');
        displayMainMenu();
        break;
    case '4':
        system("CLS");
        p4->ReturnCar(); 
        cout << "\nPress Enter key to continue....." << endl;
        cin.get(chr);
        do {
            if (chr == '\n') {
                cin.ignore();
                system("CLS");
                displayMainMenu();
            }
        } while (chr != '\n');
        displayMainMenu();
        break;
    case '5':
        system("CLS");
        p1->showCustomers();
        cout << "\nPress Enter key to continue....." << endl;
        cin.get(chr);
        do {
            if (chr == '\n') {
                cin.ignore();
                system("CLS");
                displayMainMenu();
            }
        } while (chr != '\n');
        displayMainMenu();
        break;
    case '6':
        system("CLS");
        cout << "Press 1 for Luxury Cars,2 for EconomyCars" << endl;
        cin >> choice;
        switch (choice) {
        case '1':
            Lx = new RentalTransaction;
            Lx->LxCarHistory();
            cout << "\nPress Enter key to continue....." << endl;
            cin.get(chr);
            do {
                if (chr == '\n') {
                    cin.ignore();
                    system("CLS");
                    displayMainMenu();
                }
            } while (chr != '\n');
            displayMainMenu();
            break;
        case '2':
            En = new RentalTransaction;
            En->EnCarHistory();
            cout << "\nPress Enter key to continue....." << endl;
            cin.get(chr);
            do {
                if (chr == '\n') {
                    cin.ignore();
                    system("CLS");
                    displayMainMenu();
                }
            } while (chr != '\n');
            displayMainMenu();
            break;
        }      
        break;
    case '7':
        system("Color 02");
        cout << " *******  ****** ****** *****   ******  *       * ******** \n"
            << " *        *    * *    * *     * *    *   *     *  *        \n"
            << " *   ***  *    * *    * *     * *****     *   *   ******  \n"
            << " *     *  *    * *    * *     * *    *      *     *         \n"
            << " *******  ****** ****** *****   ******      *     ********  \n"
            ;
            exit(0);
        break;
    default:
        cout << "Invalid choice" << endl;
    }
}
int main() {
    displayMainMenu();
}