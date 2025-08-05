Parking Management System
A C++ Based Terminal Parking Slot & Vehicle Tracking Software.
Developed by: Muhammad Zayeem
Language: C++ (Console-Based)
File I/O | Menu-Driven | Password-Protected Admin Panel

✅ Overview
•	 This is a Parking Management System developed using C++ with file handling, modular design, and a terminal-based UI.
•	 It offers a real-time solution for managing vehicle entries/exits, calculating revenue, and tracking parked vehicle details.

🧠 Key Features
🔢 Slot Management..
•	Tracks total of 100 parking slots.
•	Displays available and occupied slots dynamically.
•	Prevents double-booking of slots.

👨‍✈️ Gate Entry Module..
•	Supports multiple entry gates (Gate 1, 2, 3).
•	Validates inputs like gate number, vehicle type, and payment type.
•	Vehicle types supported: Car, Bike, Bus, Truck.

💳 Flexible Payment System..
•	Accepts Cash and Card payments.
•	Charges dynamically based on vehicle type.
•	Amounts:
             
o	Bike: Rs.20
o	Car: Rs.30
o	Bus/Truck: Rs.50

🗃️ Persistent File Handling...
•	Saves all data in a text file (parking.txt).
•	Reads data back for reports, exits, and verifications.

🔒 Admin Panel (Password Protected)..

•	Password-protected login.
•	Check earnings for:
                 🔹 Specific Date
                 🔹 Month
                 🔹 Whole Year
•	View detailed parking history.
•	Update/change admin password.

🧾 Vehicle Detail Tracking..
•	Tracks owner's name, valet, cashier, vehicle number.
•	Date of entry included in logs.
•	View individual vehicle info by entering number.

📆 Date-Based Reporting..
•	Calculate daily, monthly, and yearly earnings.
•	List all parking records filtered by date/month/year.

🚘 Vehicle Exit..
•	Mark slot as empty when vehicle exits.
•	Prevents repeated entries for exited vehicles.

📆 Record Queries
•	Search parking data by:
                  Specific Day
                  Whole Month
                  Whole Year
•	Retrieve vehicle details using vehicle number.
🔒 Security & Validation
•	Admin login is password-protected.
•	On first run, password is set to default: 13579
•	Allows password change.
•	Input validations for:
o	Vehicle type
o	Entry date
o	Slot number
o	Payment method
