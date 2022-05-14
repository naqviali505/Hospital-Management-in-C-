#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
void date(int day, int month, int year)
{
    cout << "---Today's Date---\n";
    while (1)
    {
        cout << "Day [1-30] ------ ";
        cin >> day;
        if ((day >= 1) && (day <= 30))
        {
            break;
        }
        else
        {
            cin.ignore();
            cout << "Invalid Date.\nPlease enter Date again\n";
        }
    }
    while (1)
    {
        cout << "Month [1-12] ---- ";
        cin >> month;
        if ((month >= 1) && (month <= 12))
        {
            break;
        }
        else
        {
            cin.ignore();
            cout << "Invalid Month.\nPlease enter Month again\n";
        }
    }
    while (1)
    {
        cout << "Year  ----------- ";
        cin >> year;
        if ((year >= 2000) && (year <= 2030))
        {
            break;
        }
        else
        {
            cin.ignore();
            cout << "Invalid Year.\nPlease enter Year again\n";
        }
    }
}
int reading(string header[], ifstream &readfile, int itr, int ID[], char name[][100], char gender[], int age[], char disease[][100], char type[])
{

    while (!readfile.eof())
    {
        readfile >> type[itr];
        cout << type[itr] <<"\t";
        readfile >> ID[itr];
        cout << ID[itr]<<"\t";
        readfile.getline(name[itr],100, ';');
        cout << name[itr]<<'\t';
        readfile >> gender[itr];
        cout << gender[itr] <<'\t';
        readfile >> age[itr];
        cout << age[itr] << "\t";
        readfile.getline(disease[itr], 100,'\n');
        cout << disease[itr] << "\n";
        itr++;
    }
    cout << endl;
    cout << "itr" << itr << "\n";
    return itr;
}
int adding(string header[], ifstream &readfile, ofstream &writefile, char type[], int &itr, int ID[], char names[][100], char gender[], int age[], char disease[][100])
{

    cout << "*Adding a new Patient*\n";
    cout << "---Patient's Type---\n";
    cout << "O-> O.P.D\n";
    cout << "E-> Emergency\n";
    while (1)
    {
        cout << "Choose Patient's Type[O/E]: ";
        cin >> type[itr];
        if (type[itr] == 'E')
        {
            writefile<< "\n" << type[itr] << setw(12);
            break;
        }
        else if (type[itr] == 'O')
        {
            writefile << "\n"<< type[itr] << setw(12);
            break;
        }
        else
        {
            cin.ignore();
            cout << "Invalid Type.\nPlease enter Type again\n";
        }
    }
    if (type[itr] == 'O')
    {
        cout << "*Adding a new OPD Patient*\n";
    }
    else
    {
        cout << "*Adding a new Emergency Patient*\n";
    }
    ID[itr] = itr + 1;
    writefile << ID[itr]<< setw(14);
    cout << "Patient's ID --------------------------------- " << ID[itr] << endl;
    cout << "Enter Patient's Name (Only First And Last Name) ";
    cin.ignore();
    cin >> names[itr];
    writefile << names[itr] <<';'<< setw(14);
    while (1)
    {
        cout << "Enter Patient's gender[M/F] ------------------ ";
        cin >> gender[itr];
        if (gender[itr] == 'm' || gender[itr] == 'M' || gender[itr] == 'f' || gender[itr] == 'F')
        {
            writefile << gender[itr] << setw(010);
            break;
        }
        else
        {
            cin.ignore();
            cout << "Invalid gender.\nPlease enter gender again\n";
        }
    }
    while (1)
    {
        cout << "Enter Patient's Age -------------------------- ";
        cin >> age[itr];
        if (age[itr] > 0)
        {
            writefile << age[itr] << setw(15);
            break;
        }
        else
        {
            cin.ignore();
            cout << "Invalid age. Please input Age again.\n";
        }
    }
    cout << "Enter Disease's (Seperate by Commas or Spaces): ";
    cin.ignore();
	cin.getline(disease[itr],100);
    writefile << disease[itr];
    cout << "**Congratulations!The patient has been added\n";
    itr++;
	return itr;
}
void searching(int choose, int searchID, int itr, int id[], char type[], char names[][100], int age[], char gender[], char disease[][100])
{
    cout << "*Searching for a Patient*\n";
    cout << "Enter Patient's ID:";
    cin >> searchID;
    bool foundCheck = false;
    for (int search = 0; search < itr; search++)
    {
        if (searchID == id[search])
        {
            cout << "ID founded" << endl;
            foundCheck = true;
            if (type[search] == 1)
            {
                cout << "\n---O.P.D Patient---.\n";
            }
            else if (type[search] == 2)
            {
                cout << "\n---Emergency Patient---.\n";
            }
            cout << "ID ------------------------------ " << id[search] << endl;
            cout << "Patient's Name ------------------ " << names[search] << endl;
            cout << "Age ----------------------------- " << age[search] << endl;
            cout << "Gender -------------------------- " << gender[search] << endl;
            cout << "Disease(s) ---------------------- " << disease[search] << endl;
        }
    }
}
int Adminlogin(int code, int ans, int choce)
{
    while (1)
    {
        cout << "1.Administrator" << endl;
        cout << "2.Patient" << endl;
        cin >> choce;
        if (choce == 1)
        {
            cout << "Enter the security code" << endl;
            cin >> ans;

            if (ans != code)
            {
                cin.ignore();
                cout << "Inavalid code." << endl;
            }
            else
            {
                cout << "Congratulation on logging into Admin Console" << endl;
                break;
            }
        }
        else if (choce == 2)
        {
            cout << "You are entering in the console as a patient user\n";
            break;
        }
        else
            cin.ignore();
    }
    return choce;
}
void editing(int search, int id[], char type[], int edit, int age[], char gender[], char diseases[][100], int searchID, int itr)
{
    bool repeatED = false;
    while (!repeatED)
    {
        cout << "*Editing Patient's Record*\n";
        cout << "0. Patient Type\n";
        cout << "1. Age\n";
        cout << "2. Gender\n";
        cout << "3. Disease(s)\n";
        cout << "What would you like to edit for Patient ID[0-3]: " << id[search] << " ?";
        cin >> edit;
        if (edit == 0)
        {
            cout << "*Editing Type*\n";
            while (1)
            {
                cout << "1. OPD\n2. Emergency\n";
                cout << "Edit Patient's Type[1/2]: ";
                cin >> type[itr];
                if (type[itr] == 2 || type[itr] == 1)
                {
                    cout << "Thank You for editing" << endl;
                    break;
                }
                else
                {
                    cin.ignore();
                    cout << "Invalid Type.\nPlease enter Type again\n";
                }
            }
        }
        if (edit == 1)
        {
            cout << "*Editing Age*\n";
            while (1)
            {

                cout << "Enter Patient's Age ------------------------ ";
                cin >> age[itr];
                if (age[itr] > 0 && age[itr] < 120)
                {
                    cout << "Thank You for editing" << endl;
                    break;
                }
                else
                {
                    cin.ignore();
                    cout << "Invalid age. Please input Age again.\n";
                    cin >> age[itr];
                }
            }
        }
        else if (edit == 2)
        {
            cout << "*Editing gender*\n";
            while (1)
            {
                cout << "Edit Patient's gender[M/F] ------------------ ";
                cin >> gender[itr];
                if (gender[itr] == 'm' || gender[itr] == 'M' || gender[itr] == 'f' || gender[itr] == 'F')
                {
                    cout << "Thank You for editing" << endl;
                    break;
                }
                else
                {
                    cin.ignore();
                    cout << "Invalid gender.\nPlease enter gender again\n";
                }
            }
            gender[search] = gender[itr];
        }
        else if (edit == 3)
        {
            cout << "*Editing  Disease-ID*\n";
            cout << "Enter Disease's (Seperate by Commas/Spcaes): ";
            for (int n = 0; n < 2; n++)
            {
                cin >> diseases[n];
            }
            cout << "Thank You for editing" << endl;
        }
    }
}
void menu()
{
    cout << "1. Add a new Patient.\n";
    cout << "2. Search or Edit Patient.\n";
    cout << "3. Billing\n";
    cout << "4. Delete Patient Record.\n";
    cout << "5. Show Patients Record.\n";
    cout << "0. EXIT\n";
    cout << "Choose an option[0-4]: ";
}
void billings(float charge, float deposit, float totalCharge, bool foundCheck, int month, int day, int year)
{
    foundCheck = false;
    cout << "*Billing*\n";
    cout << day << "/" << month << "/" << year << "\n\n\n";
    cout << "Total Charge -------------------- ";
    cin >> charge;
    cout << "Enter Money Deposited ----------- ";
    cin >> deposit;
    totalCharge = deposit - charge;
    if (deposit > charge)
    {
        cout << "Hospital needs to return " << totalCharge << " PKR to Patient.\n";
        cout << "Press any key to Proceed";
    }
    else if (deposit < charge)
    {
        totalCharge = totalCharge * -1;
        cout << "Charged amount has exceeded deposited amount.\n";
        cout << "Patient needs to deposit " << totalCharge << " PKR to complete their Bill.\n";
        cout << "Press any key to Proceed";
        system("cls");
    }
    else
    {
        cout << "The Bill has been Paid\n";
        cout << "Thank You for billing\n";
    }
    if (!foundCheck)
    {
        cout << "No Records Found.\n";
    }
}
void deleting(int searchID, int itr, int deletingPatient, int id[], char names[][100], int age[], char gender[], char diseases[][100], char delChoice)
{
    cout << "*Deleting Patient*\n";
    cout << "Enter Patient's ID to Delete: ";
    cin >> searchID;
    system("cls");

    bool foundCheckDel = false;
    for (int del = 0; del < itr; del++)
    {
        if (id[del] == searchID)
        {
            foundCheckDel = true;
            cout << "ID ------------------------------ " << id[del] << endl;
            cout << "Patient's Name ------------------ " << names[del] << endl;
            cout << "Age ----------------------------- " << age[del] << endl;
            cout << "gender[itr]der -------------------------- " << gender[del] << endl;
            cout << "Disease(s) ---------------------- " << diseases[del] << endl;
            cout << "Press 'D' to delete Patient: " << id[del] << endl;
            cin >> delChoice;
            if (delChoice == 'd' || delChoice == 'D')
            {
                id[del] = deletingPatient;
                age[del] = deletingPatient;
                gender[del] = deletingPatient;
                cout << "*Patient's record has been deleted*\n";
            }
        }
    }
    if (!foundCheckDel)
    {
        cout << "No Records Found.\n";
    }
}
void listing(int sort, int itr, int deletingPatient, char type[], int id[], char names[][100], int age[], char gender[], char diseases[][100])
{
    cout << "*Listing Patients*\n";
    cout << "Show patient's list according to: \n";
    cout << "1. ID\n";
    cout << "2. OPD Patients\n";
    cout << "3. Emergency Patients\n";
    cout << "How would you like the patient list to be shown? ";
    cin >> sort;
    system("cls");
    if (sort == 1)
    {
        cout << "*Listing by IDs*\n";

        bool foundCheckID = false;
        for (int out = 0; out < itr; out++)
        {
            if (id[out] != deletingPatient)
            {
                foundCheckID = true;
                if (type[out] == 1)
                {
                    cout << "\n---O.P.D Patient---.\n";
                }
                else if (type[out] == 2)
                {
                    cout << "\n---Emergency Patient---.\n";
                }
                cout << "ID ------------------------------ " << id[out] << endl;
                cout << "Patient's Name ------------------ " << names[out] << endl;
                cout << "Age ----------------------------- " << age[out] << endl;
                cout << "Gender -------------------------- " << gender[out] << endl;
                cout << "Disease(s) ---------------------- " << diseases[out] << endl;
                cout << "*****\n";
            }
        }
        if (!foundCheckID)
        {
            cout << "No Records Found.\n";
        }
    }
    else if (sort == 2)
    {
        cout << "*Listing by OPD Type*\n";

        bool foundCheckOPD = false;
        for (int opd = 0; opd < itr; opd++)
        {
            if (id[opd] != deletingPatient)
            {

                if (type[opd] == 1)
                {
                    foundCheckOPD = true;
                    cout << "\n---O.P.D Patient---.\n";
                    cout << "ID ------------------------------ " << id[opd] << endl;
                    cout << "Patient's Name ------------------ " << names[opd] << endl;
                    cout << "Age ----------------------------- " << age[opd] << endl;
                    cout << "Gender -------------------------- " << gender[opd] << endl;
                    cout << "Disease(s) ---------------------- " << diseases[opd] << endl;
                    cout << "*****\n";
                }
            }
        }
        if (!foundCheckOPD)
        {
            cout << "No OPD Records Found.\n";
        }
    }
    else if (sort == 3)
    {
        cout << "*Listing by Emergender[itr]cy Type*\n";

        bool foundCheckEM = false;
        for (int em = 0; em < itr; em++)
        {
            if (id[em] != deletingPatient)
            {
                if (type[em] == 2)
                {
                    foundCheckEM = true;
                    cout << "\n---Emergency Patient---.\n";
                    cout << "ID ------------------------------ " << id[em] << endl;
                    cout << "Patient's Name ------------------ " << names[em] << endl;
                    cout << "Age ----------------------------- " << age[em] << endl;
                    cout << "Gender -------------------------- " << gender[em] << endl;
                    cout << "Disease(s) ---------------------- " << diseases[em] << endl;
                    cout << "*****\n";
                }
            }
        }
        if (!foundCheckEM)
        {
            cout << "No Emergency Records Found.\n";
        }
    }
}
int main()
{
    cout << "*Patient Record Management System*\n";
    ifstream readfile;
    ofstream writefile;
    string header[10];
    const int SIZE = 1000;
    const int code = 6878;
    int allow = 0;
    char type[SIZE]; //Storing Patient Type
    int ID[SIZE], age[SIZE], sort = 0;
    char gender[SIZE], names[SIZE][100], disease[SIZE][100];
    float totalCharge = 0, charge = 0, deposit = 0;
    int searchID = 0, search = 0, edit = 0, day = 0, month = 0, year = 0, choose = 0;
    int deletingPatient = -1;
    bool repeat = false;
    int itr = 0, chose = 0, ans = 0, choce = 0; // patient counter
    char billChoice = 0, delChoice = 0;         //for giving billing option
    bool foundCheck = false, correctDate = false, correctBill = false, correctMonth = false, correctYear = false;
    readfile.open("HospitalRecord.txt");
    writefile.open("HospitalRecord.txt", ios::app);
    if ((!readfile.is_open()))
    {
        cout << "An error occured while opening the file\n";
    }
    else
    {
        readfile >> header[0] >> setw(10);
        readfile >> header[1] >> setw(10);
        readfile >> header[2] >> setw(20);
        readfile >> header[3] >> setw(10);
        readfile >> header[4] >> setw(10);
        readfile >> header[5];
        if ((!writefile.is_open()))
        {
            cout << "An error occured while opening the file\n";
        }
        else
        {
            date(day, month, year);
            int c = Adminlogin(code, ans, choce);
            while (!repeat)
            {
                if (c == 2)
                {
                    menu();
                    cin >> choose;
                    if (choose == 1)
                    {
                        allow = 0;
                        if (allow == 0)
                        {
                            cout << "Only admin are authorized to do that" << endl;
                        }
                        else
                        {
                            adding(header, readfile, writefile, type, itr, ID, names, gender, age, disease);
                            itr++;
                        }
                    }
                    else if (choose == 2)
                    {
                        cout << "1.Searching for a Patient\n";
                        cout << "2.Editing a Patient Record \n";
                        cin >> chose;
                        if (chose != 1 && chose != 2)
                        {
                            cin.ignore();
                            cin >> chose;
                        }
                        allow = 1;
                        if (chose == 1)
                        {
                            if (allow == 0)
                            {
                                cout << "Only admin are authorized to do that" << endl;
                            }
                            else
                            {
                                searching(choose, searchID, itr, ID, type, names, age, gender, disease);
                            }
                        }
                        else if (chose == 2)
                        {
                            allow = 0;
                            if (allow == 0)
                            {
                                cout << "Only admin are authorized to do that" << endl;
                            }
                            else
                            {
                                searching(choose, searchID, itr, ID, type, names, age, gender, disease);
                                editing(search, ID, type, edit, age, gender, disease, searchID, itr);
                            }
                        }
                    }
                    else if (choose == 3)
                    {
                        allow = 1;
                        if (allow == 0)
                        {
                            cout << "Only admin are authorized to do that" << endl;
                        }
                        else
                        {
                            billings(charge, deposit, totalCharge, foundCheck, month, day, year);
                        }
                    }
                    else if (choose == 4)
                    {
                        allow = 0;
                        if (allow == 0)
                        {
                            cout << "Only admin are authorized to do that" << endl;
                        }
                        else
                        {
                            deleting(searchID, itr, deletingPatient, ID, names, age, gender, disease, delChoice);
                        }
                    }
                    else if (choose == 5)
                    {
                        allow = 1;
                        if (allow == 0)
                        {
                            cout << "Only admin are authorized to do that" << endl;
                        }
                        else
                        {

                            listing(sort, itr, deletingPatient, type, ID, names, age, gender, disease);
                        }
                    }

                    else if (choose == 0)
                    {
                        repeat = true;
                    }
                }
                else if (c == 1)
                {
                    menu();
                    cin >> choose;
                    if (choose == 1)
                    {
                        itr = reading(header, readfile, itr, ID, names, gender, age, disease, type);
                        adding(header, readfile, writefile, type, itr, ID, names, gender, age, disease);
                    }
                    else if (choose == 2)
                    {
                        cout << "1.Searching for a Patient\n";
                        cout << "2.Editing a Patient Record \n";
                        cin >> chose;
                        if (chose != 1 && chose != 2)
                        {
                            cin.ignore();
                            cin >> chose;
                        }
                        if (chose == 1)
                        {

                            searching(choose, searchID, itr, ID, type, names, age, gender, disease);
                        }
                        else if (chose == 2)
                        {
                            searching(choose, searchID, itr, ID, type, names, age, gender, disease);
                            editing(search, ID, type, edit, age, gender, disease, searchID, itr);
                        }
                    }
                    else if (choose == 3)
                    {
                        billings(charge, deposit, totalCharge, foundCheck, month, day, year);
                    }
                    else if (choose == 4)
                    {

                        deleting(searchID, itr, deletingPatient, ID, names, age, gender, disease, delChoice);
                    }
                    else if (choose == 5)
                    {
                        listing(sort, itr, deletingPatient, type, ID, names, age, gender, disease);
                    }

                    else if (choose == 0)
                    {
                        repeat = true;
                    }
                }
            }
        }
    }
    readfile.close();
    writefile.close();
    return 0;
}