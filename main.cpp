#include <iostream>
#include <fstream>
using namespace std;


      //Declaring structure
struct Parking{
   int slot;
   int entry_gate;
   string owner_name;
   string vehicle_type;
   string vehicle_number;
   string valet_name;
   string cashier_name;
   string payment_type;
   time_t entry_time;
   int payment_amount;
   int year,month,day;

};

//defining maximum parking and making an array for parking slots
const int MAX_PARKING=100;
Parking parking[MAX_PARKING];
int slot_filled[MAX_PARKING]={0};
int slot_count=0;


//-------------------------------------------------------------------------------------Function to update filled slots.
void update_filled_slots()
{
    ifstream infile("parking.txt");
    int slot;
    string extra;
    while(infile>>slot)
    {
        slot_filled[slot]=1;
        getline(infile,extra);
    }
    infile.close();
}
//-------------------------------------------------------------------------------------Function to show available and occupied slots.
void slot_details()
{
    update_filled_slots();
    cout<<"Following Slots are filled: ";
    for (int i=0;i<=MAX_PARKING;i++)
    {
        if (slot_filled[i+1]==1)
        {
            cout<<i+1<<" , ";
        }
    }
}


//-----------------------------------------------------------------------------------------function to enter car into parking
void car_entry()
{
        update_filled_slots();
        if(slot_count>=MAX_PARKING)
        {
            cout<<"No empty parking slot..!"<<endl;
            return;
        }
    Parking p;
        while(true)
        {
        cout<<"Enter gate number for entry(1/2/3)..........: ";
        cin>>p.entry_gate;
        cin.ignore();
        if(p.entry_gate==1||p.entry_gate==2||p.entry_gate==3)
        {
            break;
        }
        else
        {
          cout << " Invalid input! Please try again."<<endl;
        }
        }
    cout<<"Enter owner's name..........................:";
    getline(cin,p.owner_name);
         while(true)
         {
         cout<<"Enter type of vehicle (car/bike/truck/bus)..:  ";
         cin>>p.vehicle_type;
         cin.ignore();
         for (int i=0;i<p.vehicle_type.length();i++)
         {
         p.vehicle_type[i]=tolower(p.vehicle_type[i]);
         }
         if (p.vehicle_type=="car"||p.vehicle_type=="truck" ||
            p.vehicle_type=="bus"||p.vehicle_type=="bike")
         {
             if(p.vehicle_type=="bike")
        {
            p.payment_amount=20;
        }
       else if (p.vehicle_type=="car")
        {
            p.payment_amount=30;
        }
       else if (p.vehicle_type=="bus"||p.vehicle_type=="truck")
        {
            p.payment_amount=50;
        }
            break;
         }
         else {
            cout << " Invalid input! Please try again.\n";
         }
         }
    cout<<"Enter Vehicle's number......................:  ";
    getline(cin,p.vehicle_number);
    for (int i=0;i<p.vehicle_number.length();i++)
         {
         p.vehicle_number[i]=tolower(p.vehicle_number[i]);
         }
    cout<<"Enter valet name............................:  ";
    getline(cin,p.valet_name);
    cout<<"Enter Cashier's name........................:  ";
    getline(cin,p.cashier_name);
    while(true)
    {
    cout<<"Enter payment type (card/cash)..............:  ";
    cin>>p.payment_type;
    cin.ignore();

        for (int i=0;i<p.payment_type.length();i++)
        {
    p.payment_type[i]=tolower(p.payment_type[i]);
        }
        if(p.payment_type=="card"||p.payment_type=="cash")
        {
            break;
        }
        else
        {
          cout << " Invalid input! Please try again."<<endl;
        }
    }
    while (true)
        {
        cout<<"Enter date (1-31)...........................: ";
    cin>>p.day;
    if(p.day<=0||p.day>31)
        {
          cout<<"Invalid day! try again..";
          continue;
        }
         break;
        }
    while(true)
    {
        cout<<"Enter month (1-12)..........................: ";
    cin>>p.month;
    if(p.month<=0||p.month>12)
        {
          cout<<"Invalid month! try again..";
          continue;
        }
         break;
        }
    while(true)
    {
        cout<<"Enter year..................................: ";
    cin>>p.year;
    if(p.year<=999||p.year>9999)
        {
          cout<<"Invalid year! try again..";
          continue;
        }
         break;
        }
    cout<<"Entry Date is...............................:"<<p.day<<"-"<<p.month<<"-"<<p.year<<endl;
    cout<<"Payment amount is...........................:Rs."<<p.payment_amount<<endl;

   while(true)
    {
    cout<<"Enter slot you want to park at (1 to " << MAX_PARKING<<")...:";
    cin>>p.slot;
    if (p.slot<=0||p.slot>MAX_PARKING)
    {
        cout<<"Invalid slot number. Try again.\n";
        continue;
    }
    if (slot_filled[p.slot]==1)
    {
        cout<<"Sorry! Slot already filled.\n";
        continue;
    }
    slot_filled[p.slot] = 1;
    cout<<"Slot "<< p.slot <<" allocated!"<<endl;
    break;
    }

    parking[slot_count++]=p;
}
//--------------------------------------------------------------------------Function to save record to file.
void save_to_file()
{
    ofstream outfile("parking.txt",ios::app);
    if (!outfile)
    {
        cout<<"Error in opening file..!"<<endl;
        return;
    }
    for(int i=0;i<slot_count;i++)
    {
        Parking p=parking[i];
        outfile<<p.slot<<" "<<p.entry_gate<<" "<<p.owner_name<<" "<<p.vehicle_type<<" "<<p.vehicle_number<<" "<<p.valet_name<<
        " "<<p.cashier_name<<" "<<p.payment_type<<" "<<p.payment_amount<<" "<<p.day<<" "<<p.month<<" "<<p.year<<endl;
    }
    outfile.close();
    cout<<"Car entered.."<<endl;
}
//--------------------------------------------------------------------------Function to calculate earnings.
void calculate_earning_by_date()
{
    ifstream infile("parking.txt");
    {
        if(!infile)
        {
            cout<<"Error! No file.";
        }
    }

    int input_day,input_month,input_year;
    cout<<"Enter day of month (0 if you want to check for month): ";
    cin>>input_day;
    cout<<"Enter month (0 if you want to check for year)........: ";
    cin>>input_month;
    cout<<"Enter day of year....................................: ";
    cin>>input_year;
    int total=0;
    while(true)
    {
        int slot,entry_gate,payment_amount,year,month,day;
        string owner_name,vehicle_type,vehicle_number,valet_name,cashier_name,payment_type;
        infile>>slot>>entry_gate>>owner_name>>vehicle_type>>vehicle_number>>valet_name>>cashier_name>>payment_type>>payment_amount>>day>>month>>year;
        if (infile.fail())
        {
            break;
        }
        if (year==input_year)
        {
            if(input_day<=0&&input_month<=0)
            {
                total+=payment_amount;
            }
            else if(input_day<=0&&input_month>0&&month==input_month)
            {
                total+=payment_amount;
            }
            else if(input_day>0&&input_month>0&&day==input_day)
            {
                total+=payment_amount;
            }
        }
    }
    infile.close();
    cout<<"Total earnings are Rs."<<total<<endl;
}
//----------------------------------------------------------------------Function to check parking details by date.
void parking_deatils_by_date()
{
    ifstream infile("parking.txt");
    {
        if(!infile)
        {
            cout<<"Error! No file.";
        }
    }

    int input_day,input_month,input_year;
    cout<<"Enter day of month.: ";
    cin>>input_day;
    cout<<"Enter month........: ";
    cin>>input_month;
    cout<<"Enter day of year..: ";
    cin>>input_year;
    bool found=false;
    cout<<"Slot NO.|Entry Gate|Owner Name|Vehicle type|Valet Name|Cashier Name|Payment Type|Payment Amount|Date|"<<endl;
     while(true)
    {
        int slot,entry_gate,payment_amount,year,month,day;
        string owner_name,vehicle_type,vehicle_number,valet_name,cashier_name,payment_type;
        infile>>slot>>entry_gate>>owner_name>>vehicle_type>>vehicle_number>>valet_name>>cashier_name>>payment_type>>payment_amount>>day>>month>>year;
        if (infile.fail())
        {
            break;
        }
        if (year==input_year)
        {
            if(input_day<=0&&input_month<=0)
            {
                 found = true;
                cout << slot << " | " << entry_gate << " | " << owner_name << " | " << vehicle_type << " | "
                     << vehicle_number << " | " << valet_name << " | " << cashier_name << " | "
                     << payment_type << " | Rs." << payment_amount << " | "
                     << day << "-" << month << "-" << year << endl;
            }
            else if(input_day<=0&&input_month>0&&month==input_month)
            {
                 found = true;
                cout << slot << " | " << entry_gate << " | " << owner_name << " | " << vehicle_type << " | "
                     << vehicle_number << " | " << valet_name << " | " << cashier_name << " | "
                     << payment_type << " | Rs." << payment_amount << " | "
                     << day << "-" << month << "-" << year << endl;
            }
            else if(input_day>0&&input_month>0&&day==input_day)
            {
                 found = true;
                cout << slot << " | " << entry_gate << " | " << owner_name << " | " << vehicle_type << " | "
                     << vehicle_number << " | " << valet_name << " | " << cashier_name << " | "
                     << payment_type << " | Rs." << payment_amount << " | "
                     << day << "-" << month << "-" << year << endl;
            }
            }
        }
    infile.close();
}
//--------------------------------------------------------------------------Function to check car details by number.
void car_details_by_number()
{
    ifstream infile("parking.txt");
    {
        if(!infile)
        {
            cout<<"Error! No file.";
        }
    }
    string input_vehicle_number;
    cout<<"Enter Vehicle's Number : ";
    cin>>input_vehicle_number;
    bool found=false;
     while(true)
    {
        int slot,entry_gate,payment_amount,year,month,day;
        string owner_name,vehicle_type,vehicle_number,valet_name,cashier_name,payment_type;
        infile>>slot>>entry_gate>>owner_name>>vehicle_type>>vehicle_number>>valet_name>>cashier_name>>payment_type>>payment_amount>>day>>month>>year;
        if (infile.fail())
        {
            break;
        }
        if (vehicle_number==input_vehicle_number)
        {
                 found = true;
                cout<<"-----Car Details----- "<<slot<<endl;
                cout<<"Slot : "<<slot<<endl;
                cout<<"Entrance Gate : "<<entry_gate<<endl;
                cout<<"Owner's Name : "<<owner_name<<endl;
                cout<<"Vehicle Type : "<<vehicle_type<<endl;
                cout<<"Vehicle Number : "<<vehicle_number<<endl;
                cout<<"Valet Name : "<<valet_name<<endl;
                cout<<"Cashier's Name : "<<cashier_name<<endl;
                cout<<"Payment Type : "<<payment_type<<endl;
                cout<<"Payment Amount : Rs."<<payment_amount<<endl;
                cout<< "Date : "<<day << "-" << month << "-" << year << endl;
        }
    }
        if (!found)
        {
            cout<<"No vehicle of this number in parking..!"<<endl;
        }

    infile.close();
}
//--------------------------------------------------------------------Function to exit a vehicle and make a slot empty.
void exit_vehicle()
{
     ifstream infile("parking.txt");
    {
        if(!infile)
        {
            cout<<"Error! No file.";
        }
    }
    string input_vehicle_number;
    cout<<"Enter Vehicle's Number to exit : ";
    cin>>input_vehicle_number;
    bool found=false;
    while(true)
    {
        int slot,entry_gate,payment_amount,year,month,day;
        string owner_name,vehicle_type,vehicle_number,valet_name,cashier_name,payment_type;
        infile>>slot>>entry_gate>>owner_name>>vehicle_type>>vehicle_number>>valet_name>>cashier_name>>payment_type>>payment_amount>>day>>month>>year;
        if (infile.fail())
        {
            break;
        }
        if (vehicle_number==input_vehicle_number)
        {
            found=true;
            if (slot_filled[slot]==1)
            {
                slot_filled[slot]=0;
                cout<<"Vehicle '"<<vehicle_number<<"' has exited. Slot "<<slot<<" is now empty.\n";
            }
            else
            {
                cout<<"Slot was already empty.\n";
            }
            break;
        }
    }
        if (!found)
        {
            cout<<"No vehicle of this number in parking.."<<endl;
        }

    infile.close();
}

//----------------------------------------------------------------Function to change password.
void change_admin_password() {
    string old_pass,entered_old_pass,new_pass,confirm_pass;

    ifstream infile("admin_pass.txt");
    if (!infile) {
        cout<< "Error: Could not open password file." << endl;
        return;
    }
    getline(infile, old_pass);
    infile.close();
    cout<<"Enter current admin password: ";
    cin>>entered_old_pass;
    if (entered_old_pass!=old_pass)
    {
        cout<< "Incorrect password. Access denied."<<endl;
        return;
    }
    cout << "Enter new password: ";
    cin >> new_pass;
    cout << "Confirm new password: ";
    cin >> confirm_pass;
    if (new_pass != confirm_pass) {
        cout << "Passwords do not match. Password not changed." << endl;
        return;
    }
    ofstream outfile("admin_pass.txt");
    if (!outfile) {
        cout << "Error: Could not write to password file." << endl;
        return;
    }
    outfile << new_pass;
    outfile.close();
    cout << "Password changed successfully!" << endl;
}

//----------------------------------------------------------------------------------------Function to show menu for entry.
void showMenu2()
{   cout<<"\n\n\n";
    cout << "======================================\n";
    cout << ""            "Gate Login\n";
    cout << "======================================\n";
    cout << "1. New car entry.\n";
    cout << "2. Car Details by Number. \n";
    cout << "3. Exit a Vehicle from Parking.\n";
    cout << "4. Filled Slots.\n";
    cout << "0. Exit\n";
    cout << "--------------------------------\n";
    cout << "Enter your choice: ";
    int choice;
    do {
        cin >> choice;

        switch(choice) {
            case 1:
                car_entry();
                save_to_file();
             break;
            case 2:
                car_details_by_number();
             break;
            case 3:
                exit_vehicle();
             break;
             case 4:
                slot_details();
             break;
            case 0:
                cout << "Exiting... Thank you!\n";
            break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}
//-------------------------------------------------------------------Function to show admin menu.
void show_admin_menu()
{
    cout<<"\n\n\n";
    cout << "======================================\n";
    cout << ""            "Admin Login       \n";
    cout << "======================================\n";
    cout << "1. Calculate Earning (by date/monthly/yearly/)\n";
    cout << "2. Parking Details   (by date/monthly/yearly/)\n";
    cout << "3. Car Details by Number. \n";
    cout << "4. Change Admin Password. \n";
    cout << "0. Exit\n";
    cout << "--------------------------------\n";
    cout << "Enter your choice: ";
     int choice;
    do {
        cin >> choice;

        switch(choice) {
            case 1:
                calculate_earning_by_date();
             break;
            case 2:
                parking_deatils_by_date();
             break;
            case 3:
                car_details_by_number();
             break;
             case 4:
                change_admin_password();
             break;
            case 0:
                cout << "Exiting... Thank you!\n";
            break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);


}
//-----------------------------------------------------------------------------Function for Admin Login.
void admin_login()
{
    ifstream infile("admin_pass.txt");
    if (!infile)
    {
        ofstream outfile("admin_pass.txt");
        outfile << "13579";
        outfile.close();
    }
    infile.close();
    string stored_pass;
    ifstream readfile("admin_pass.txt");
    getline(readfile, stored_pass);
    readfile.close();
    while (true)
    {
        string entered_pass;
        cout << "Enter Password to continue: ";
        cin >> entered_pass;

        if (entered_pass == stored_pass)
        {
            show_admin_menu();
            break;
        }
        else
        {
            cout << "Password incorrect! Try again.." << endl;
        }
    }
}

//-----------------------------------------------------------------------------------Function to show menu 1.
void show_menu1()
{
    cout << "======================================\n";
    cout << ""    "Parking Management System\n";
    cout << "======================================\n";
    cout << "1. Gate Login.\n";
    cout << "2. Admin Login\n";
    cout << "0. Exit\n";
    cout << "--------------------------------\n";
    cout << "Enter your choice: ";
    int choice;
    do {
        cin >> choice;
        switch(choice) {
            case 1:
                showMenu2();
             break;
            case 2:
                admin_login();
             break;
            case 0:
                cout << "Exiting... Thank you!\n";
            break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

int main()
{
    show_menu1();
    return 0;
}
