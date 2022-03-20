#include <bits/stdc++.h>
using namespace std;

class ExpressDelivery;
class Customer;
class Reviews;
class Order;
class DeliveryInfo;
class Employee;
class Vehicles;
class Centres;

class ExpressDelivery
{
private:
	string system_inform;

protected:
	int no_customers, no_employees, no_vehicles, no_centres;

public:
	ExpressDelivery() // constructor for initializaton
	{
		no_centres = 0;
		no_customers = 0;
		no_employees = 0;
		no_vehicles = 0;
		system_inform = "The Express Delivery System is a parcel delivery system that automates the process of delivering various products such as heavyweight and lightweight parcels, as well as letters, from person to person throughout numerous cities across the country.";
	}
	void display_info()
	{
		cout << "\t\t\tExpress Delivery\n"
			 << system_inform << "\n";
	}
};

class Customer : public ExpressDelivery
{
private:
	string Name, Address, City, Password;
	long long int Contact;

protected:
	int Customer_ID;

public:
	void setInfo()
	{
		cout << "Enter Customer's Name :\n\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, Name);
		cout << "Enter Customer's Address :\n";
		getline(cin, Address);
		cout << "Enter Customer's Contact Number :\n";
		cin >> Contact;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter Customer's City :\n";
		getline(cin, City);
		cout << "Enter Customer Id :\n";
		cin >> Customer_ID;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter Password :\n";
		getline(cin, Password);
	}

	void display_info()
	{
		cout << "Customer Name :- " << Name << "\n";
		cout << "Customer Address :-\n"
			 << Address << "\n";
		cout << "Contact Number :- " << Contact << "\n";
		cout << "City :- " << City << "\n";
		cout << "Enter Customer Id :- " << Customer_ID << "\n";
		cout << "Password :- " << Password << "\n";
	}

	friend void customerMenu(Customer &ptr, vector<Reviews> &rev, vector<Order> &ord, vector<DeliveryInfo> &di);
	friend void loginCustomer(vector<Customer> &cust, vector<Reviews> &rev, vector<Order> &ord, vector<DeliveryInfo> &di);
	friend void registerCustomer(vector<Customer> &cust);
};

class Reviews : public Customer
{
private:
	string Review, Name;
	int Ratings;

public:
	void setReviews(string ptr)
	{
		Name = ptr;
		string dfd;
		dfd = "\n";
		dfd = dfd + "Customer's Name-- " + Name + "\n";
		cout << "Give rating out of five (1-5) to our services :-\n";
		cin >> Ratings;
		dfd = dfd + "Rating Given by customer (out of 5) -- " + to_string(Ratings) + "\n";

		cout << "Give some description :-\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, Review);
		dfd = dfd + "Description given by customer-- " + Review + "\n";
		cout << "Thank you for submitting your review. \n";
		ofstream fout;
		fout.open("oops.txt", ios::app);
		fout << dfd << "\n";
		fout.close();
	}
	friend void showReviews();
};

class Order : public Customer
{
private:
	string Name, Address;
	long long int PhoneNo;
	int weight;
	float cost;
	static int count;
	void calculateCost()
	{
		cost = weight * 10.0;
	}
	static int generateOrderID()
	{
		count++;
		return count;
	}

protected:
	int Order_Id;
	int Cust_ID;

public:
	void setInfo(int x)
	{
		Cust_ID = x;
		cout << "\nEnter Reciever's Name :\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, Name);
		cout << "Enter Address of Reciever :\n";
		getline(cin, Address);
		cout << "Enter the Phone Number of Reciever :\n";
		cin >> PhoneNo;
		cout << "Enter the weight of parcel :\n";
		cin >> weight;
		calculateCost();
		Order_Id = generateOrderID();
		cout << "\nOrder Placed successfully.\n";
	}

	void display_info()
	{
		cout << "Order Id :- " << Order_Id << "\n";
		cout << "Reciever's Name is :- " << Name << "\n";
		cout << "Address of Reciever :-\n"
			 << Address << "\n";
		cout << "Phone Number of Reciever :- " << PhoneNo << "\n";
		cout << "Weight of the parcel :- " << weight << "\n";
		cout << "Cost of the Parcel is :- " << cost << " Rs.\n";
	}

	friend void customerMenu(Customer &ptr, vector<Reviews> &rev, vector<Order> &ord, vector<DeliveryInfo> &di);
	friend class DeliveryInfo;
};
int Order::count = 0;

class DeliveryInfo 
{
private:
	int Order_Id;
	int Sender_Id;
	int Cost;
	bool Delivered;

public:
	// DeliveryInfo(){}

	DeliveryInfo(Order ord) // copy constructor
	{
		Order_Id = ord.Order_Id;
		Sender_Id = ord.Cust_ID;
		Cost = ord.cost;
		Delivered = false;
	}

	void setInfo()
	{
		char x;
		cout << "If the Parcel is delivered Press Y \n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> x;
		if (x == 'y' || x == 'Y')
		{
			Delivered = true;
			cout << "Delivery of parcel is successfully completed\n";
		}
		else
			cout << "Parcel is not delivered yet. will deliver soon.\n";
	}
	void display_info()
	{
		cout << "\nThe Sender_Id is : " << Sender_Id << "\n";
		cout << "The Order Id is : " << Order_Id << "\n";
		cout << "The Cost is : " << Cost << "\n";
		cout << "The Parcel is ";
		if (Delivered == false)
			cout << "Not Delivered yet.\n";
		else
			cout << "Delivered\n";
	}

	friend void deliveryPerson(vector<DeliveryInfo> &di);
};

//CLASS CENTRES

class Centres : public ExpressDelivery
{
private:
	int Centre_id;

private:
	string Name;
	string City;
	string Address;
	long long int Contact;

public:
	void setInfo();
	void display_info()
	{
		cout << "\nCentre ID :-" << Centre_id << "\n";
		cout << "Centre Name :-" << Name << "\n";
		cout << "City where Centre is located :-" << City << "\n";
		cout << "Address of Centre :-" << Address << "\n";
		cout << "Contact Number :- " << Contact << "\n";
	}

	void setNoOfCentres(int Num)
	{
		no_centres = Num;
	}
	int getNoOfCentres()
	{
		return no_centres;
	}

	friend void managerMenu(vector<Employee> &emp, vector<Centres> &cent, vector<Vehicles> &vec, string Name);
};

void Centres::setInfo()
{
	cout << "\nEnter the details of the new Centre :-"
		 << "\n";
	cout << "Enter Centre ID :-"
		 << "\n";
	cin >> Centre_id;
	cout << "Enter Name of the Centre :-"
		 << "\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, Name);
	cout << "Enter Contact Number :- ";
	cin >> Contact;
	cout << "Enter Address of the Centre :-"
		 << "\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, Address);
	cout << "Enter City where Centre will be located :-"
		 << "\n";
	getline(cin, City);
}

//CLASS VEHICLES

class Vehicles : public ExpressDelivery
{
private:
	int Vehicle_Id;
	string Vehicle_Type;

public:
	void setInfo()
	{
		cout << "Enter the details of the new Vehicle :-\n";
		cout << "Enter Vehicle ID :- ";
		cin >> Vehicle_Id;
		cout << "Enter Vehicle Type :- ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, Vehicle_Type);
	}

	void display_info()
	{
		cout << "Vehicle ID is " << Vehicle_Id << "\n";
		cout << "Vehicle Type is " << Vehicle_Type << "\n";
	}

	friend void managerMenu(vector<Employee> &emp, vector<Centres> &cent, vector<Vehicles> &vec, string Name);
};

//CLASS EMPLOYEE

class Employee : public ExpressDelivery
{
private:
	string Name, Password, Address, Designation;
	long long int Contact;
	int Salary;
	int Emp_Id;

public:
	Employee()
	{
		Name = "Adil Prag";
		Contact = 9785640207;
		Address = "AB-500 , Hyderabad";
		Designation = "Manager";
		Emp_Id = 1;
		Salary = 100000;
		Password = "oops";
	}

	void setInfo();
	void display_info()
	{
		cout << "\nName :-" << Name << endl;
		cout << "Contact Number :-" << Contact << endl;
		cout << "Address :-" << Address << endl;
		cout << "Designation :-" << Designation << endl;
		cout << "Employee ID :-" << Emp_Id << endl;
		cout << "Salary :-" << Salary << endl;
	}

	friend void employee(vector<Employee> &emp, vector<DeliveryInfo> &di, vector<Centres> &cent, vector<Vehicles> &vec);
	friend void managerMenu(vector<Employee> &emp, vector<Centres> &cent, vector<Vehicles> &vec, string Name);
};

void Employee::setInfo()
{
	cout << "\nEnter the details of Employee :- " << endl
		 << endl;
	cout << "Enter Name of the Employee :- " << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, Name);
	cout << "Enter Contact Number :- " << endl;
	cin >> Contact;
	cout << "Enter Address of the Employee :- " << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, Address);
	cout << "Enter Designation of the Employee :- " << endl;
	getline(cin, Designation);
	cout << "Enter Employee ID : " << endl;
	cin >> Emp_Id;
	cout << "Enter of Salary of the Employee :- " << endl;
	cin >> Salary;
	cout << "Enter Password :- " << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, Password);
}

void listAllEmployee(vector<Customer> &cust)
{
	for (int i = 0; i < cust.size(); i++)
	{
		cust[i].display_info();
		cout << "\n";
	}
}

void registerCustomer(vector<Customer> &cust)
{
	Customer ptr;
	ptr.setInfo();
	int flag = 0;
	for (int i = 0; i < cust.size(); i++)
	{
		if (cust[i].Customer_ID == ptr.Customer_ID)
			flag = 1;
	}
	if (flag == 0)
	{
		cust.push_back(ptr);
		cout << "\nSign Up successfully completed ";
	}
	else
		cout << "\nCustomer Id already exists\n";
}

void customerMenu(Customer &ptr, vector<Reviews> &rev, vector<Order> &ord, vector<DeliveryInfo> &di)
{
	while (5)
	{
		cout << "\n\t\tHELLO! " << ptr.Name << "\n";
		cout << "1. Your Orders\n"
			 << "2. New Order\n"
			 << "3. Review our services\n"
			 << "4. Logout\n"
			 << "Enter Your Choice :- ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			for (int i = 0; i < ord.size(); i++)
			{
				if (ptr.Customer_ID == ord[i].Cust_ID)
				{
					ord[i].display_info();
					cout << "\n";
				}
			}
			break;

		case 2:
		{
			Order o;
			o.setInfo(ptr.Customer_ID);
			ord.push_back(o);
			DeliveryInfo d(o);
			di.push_back(d);
		}
		break;

		case 3:
		{
			Reviews r;
			r.setReviews(ptr.Name);
			rev.push_back(r);
		}
		break;
		case 4:
			return;
			break;
		}
	}
}

void loginCustomer(vector<Customer> &cust, vector<Reviews> &rev, vector<Order> &ord, vector<DeliveryInfo> &di)
{
	int cust_ID;
	string Password;
	cout << "\nEnter Customer ID :- ";
	cin >> cust_ID;
	cout << "\nEnter Password :- ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, Password);
	for (int i = 0; i < cust.size(); i++)
	{
		if (cust_ID == cust[i].Customer_ID)
		{
			if (Password == cust[i].Password)
			{
				cout << "\n Login Successful \n";
				customerMenu(cust[i], rev, ord, di);
				return;
			}
			else
			{
				cout << "Invalid customer Id or Password\n";
				return;
			}
		}
	}
	cout << "\nNo such user exists\n";
}

void customer(vector<Customer> &cust, vector<Reviews> &rev, vector<Order> &ord, vector<DeliveryInfo> &di)
{
	while (5)
	{
		cout << "\n\n\t\tHELLO CUSTOMER, EXPRESS DELIVERY WELCOMES YOU!!\n\n";
		cout << "Enter your choice (1-3)\n";
		cout << "1. Existing Customer? Login\n"
			 << "2. Sign Up\n"
			 << "3. Back to main menu\n"
			 << "Enter Your Choice : ";
		int choice;
		cin >> choice;
		ExpressDelivery ED;
		switch (choice)
		{
		case 1:
			loginCustomer(cust, rev, ord, di);
			break;
		case 2:
			registerCustomer(cust);
			break;
		case 3: return;
			break;
		}
	}
}

void managerMenu(vector<Employee> &emp, vector<Centres> &cent, vector<Vehicles> &vec, string Name)
{
	while (5)
	{
		cout << "\n\n\t\tHello Mr. " << Name << endl
			 << endl;
		cout << "\t1. Hire new Employee.\n"
			 << "\t2. Fire an Employee.\n"
			 << "\t3. Manage Centres.\n"
			 << "\t4. Manage Vehicles.\n"
			 << "\t5. Show Vehicles.\n"
			 << "\t6. List all Employees.\n"
			 << "\t7. Logout.\n"
			 << "\tEnter Your Choice : ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Employee ptr;
			ptr.setInfo();
			int flag = 0;
			for (int i = 0; i < emp.size(); i++)
			{
				if (emp[i].Emp_Id == ptr.Emp_Id)
					flag = 1;
			}
			if (flag == 0)
			{
				emp.push_back(ptr);
				cout << "\nEmployee created successfully.\n";
			}
			else
				cout << "\nEmployee Id already exists\n";
		}
		break;

		case 2:
		{
			int E_Id;
			cout << "\nEnter Employee ID to Fire.\n";
			cin >> E_Id;
			int flag = 0;
			for (int i = 0; i < emp.size(); i++)
			{
				if (E_Id == emp[i].Emp_Id)
				{
					emp.erase(emp.begin() + i);
					cout << "Employee is Fired.";
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				cout << "\nNo such Employee exists.";
		}
		break;

		case 3:
		{
			Centres ptr;
			ptr.setInfo();
			int flag = 0;
			for (int i = 0; i < cent.size(); i++)
			{
				if (cent[i].Centre_id == ptr.Centre_id)
					flag = 1;
			}
			if (flag == 0)
			{
				cent.push_back(ptr);
				cout << "\nCentre Details updated.\n";
			}
			else
				cout << "\nCentre Id already exists\n";
		}
		break;

		case 4:
		{
			Vehicles ptr;
			ptr.setInfo();
			int flag = 0;
			for (int i = 0; i < vec.size(); i++)
			{
				if (vec[i].Vehicle_Id == ptr.Vehicle_Id)
					flag = 1;
			}
			if (flag == 0)
			{
				vec.push_back(ptr);
				cout << "\nVehicle details added successfully.\n";
			}
			else
				cout << "\nVehicle Id already exists\n";
		}
		break;

		case 5:
			for (int i = 0; i < vec.size(); i++)
			{
				vec[i].display_info();
				cout << endl;
			}
			break;

		case 6:
			cout << "\nFollowing are the details of our Employees\n\n";
			for (int i = 0; i < emp.size(); i++)
				emp[i].display_info();
			break;

		case 7:
			return;
			break;
		}
	}
}

void deliveryPerson(vector<DeliveryInfo> &di)
{
	while (5)
	{
		cout << "\t\t\n\nHELLO DELIVERY PERSON , LETS GET TO WORK."
			 << "\n1. List all Incomplete Delivery"
			 << "\n2. Change Delivery Status."
			 << "\n3. Logout\n"
			 << "Enter Your Choice :- ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			for (int i = 0; i < di.size(); i++)
			{
				if (di[i].Delivered == false)
					di[i].display_info();
			}
			break;

		case 2:
		{
			int order;
			cout << "\nEnter Order Id : ";
			cin >> order;
			int flag = -1;
			for (int i = 0; i < di.size(); i++)
			{
				if (di[i].Order_Id == order)
					flag = i;
			}
			if (flag >= 0)
				di[flag].setInfo();

			else
				cout << "\nNo such Order exists.\n\n";
		}
		break;

		case 3:
			return;
			break;
		}
	}
}
void employee(vector<Employee> &emp, vector<DeliveryInfo> &di, vector<Centres> &cent, vector<Vehicles> &vec)
{
	while (5)
	{
		cout << "\n\t\tHELLO EMPLOYEE, EXPRESS DELIVERY SYSTEM WELCOMES YOU!!\n\n";
		cout << "Enter your choice (1-2)\n";
		cout << "1. Login\n"
			 << "2. Back to main menu\n"
			 << "Enter Your Choice :- ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int E_Id, flag = 0;
			string Password;
			cout << "\nEnter Employee Id: ";
			cin >> E_Id;
			cout << "\nEnter Password : ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, Password);
			for (int i = 0; i < emp.size(); i++)
			{
				if (E_Id == emp[i].Emp_Id)
				{
					if (Password == emp[i].Password)
					{
						if (emp[i].Designation == "Manager")
						{
							managerMenu(emp, cent, vec, emp[i].Name);
							flag = 1;
						}
						else if (emp[i].Designation == "Delivery Person")
						{
							deliveryPerson(di);
							flag = 1;
						}
					}
					else
					{
						cout << "Incorrect Password\n";
						flag = 1;
					}
				}
			}
			if (flag == 0)
				cout << "No such Employee Id exists\n";
		}
		break;

		case 2:
			return;
			break;
		}
	}
}

void showReviews() // File handling
{
	ifstream fin;
	string a;
	fin.open("oops.txt");
	while (getline(fin, a))
		cout << a << "\n";
	fin.close();
	return;
}

int main()
{
	ExpressDelivery ED;
	vector<Customer> cust;
	vector<Reviews> rev;
	vector<Order> ord;
	vector<DeliveryInfo> di;
	vector<Employee> emp;
	vector<Centres> cent;
	vector<Vehicles> vec;
	Employee E;
	emp.push_back(E);
	while (5)
	{
		cout << "\n\n\t\tWELCOME TO EXPRESS DELIVERY SYSTEM\n\n";
		cout << "1. About\n2. Customer Login\n3. Employee Login\n4. Reviews\n5. Exit\n";
		cout << "\nNow, Enter your choice:- ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			ED.display_info();
			if (cent.size() != 0)
				cout << "Our Centres are : \n\n";
			for (int i = 0; i < cent.size(); i++)
				cent[i].display_info();
			cout << "\nNumber of Centres :- " << cent.size() << "\nNumber of Customer :- " << cust.size() << "\nNumber of Employee :- " << emp.size() << "\nNumber of Vehicles :- " << vec.size();
			break;

		case 2:
			customer(cust, rev, ord, di);
			break;

		case 3:
			employee(emp, di, cent, vec);
			break;

		case 4:
			showReviews();
			break;

		case 5:
			return 0;
			break;
		}
	}
	return 0;
}
