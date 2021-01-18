#include "Namecard.h"

Namecard::Namecard() {};			//Function declaration in public of class
Namecard::~Namecard() {};
void Namecard::SetName(char *name)		//Save name
{
	strcpy(m_Name, name);
}
void Namecard::SetPhonenumber(char *phonenumber)		//Save phonenumber
{
	strcpy(m_Phonenumber, phonenumber);
}
void Namecard::SetAddress(char* address)			//Save address
{
	strcpy(m_Address, address);
}
void Namecard::SetAge(int age)			//Save age
{
	m_Age = age;
}

int main()
{
	Namecard Student_A;			//Declare 5 class variables
	Namecard Student_B;
	Namecard Student_C;
	Namecard Student_D;
	Namecard Student_E;

	Student_A.SetName("Khan");
	Student_A.SetPhonenumber("010-1234-5678");
	Student_A.SetAddress("Khan@gmail.com");
	Student_A.SetAge(25);

	Student_B.SetName("Clid");
	Student_B.SetPhonenumber("010-1234-1234");
	Student_B.SetAddress("Clid@gmail.com");
	Student_B.SetAge(21);

	Student_C.SetName("Faker");
	Student_C.SetPhonenumber("010-5678-5678");
	Student_C.SetAddress("Faker@gmail.com");
	Student_C.SetAge(24);

	Student_D.SetName("Teddy");
	Student_D.SetPhonenumber("010-4287-2570");
	Student_D.SetAddress("Teddy@gmail.com");
	Student_D.SetAge(22);

	Student_E.SetName("Mata");
	Student_E.SetPhonenumber("010-9090-9090");
	Student_E.SetAddress("Mata@gmail.com");
	Student_E.SetAge(26);

	cout << Student_A.GetName() << endl << Student_A.GetPhonenumber() << endl << Student_A.GetAddress() << endl << Student_A.GetAge() << endl << endl;				// Output
	cout << Student_B.GetName() << endl << Student_B.GetPhonenumber() << endl << Student_B.GetAddress() << endl << Student_B.GetAge() << endl << endl;
	cout << Student_C.GetName() << endl << Student_C.GetPhonenumber() << endl << Student_C.GetAddress() << endl << Student_C.GetAge() << endl << endl;
	cout << Student_D.GetName() << endl << Student_D.GetPhonenumber() << endl << Student_D.GetAddress() << endl << Student_D.GetAge() << endl << endl;
	cout << Student_E.GetName() << endl << Student_E.GetPhonenumber() << endl << Student_E.GetAddress() << endl << Student_E.GetAge() << endl << endl;
	return 0;
}