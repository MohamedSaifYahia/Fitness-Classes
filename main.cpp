#include"A2functions.h"

int main()
{
    // inputting data from files into the program
    string AID, AFN, ALN, AUN, APW, Aline;
    ifstream Afile("Admins.txt");
    while(getline(Afile, Aline))
    {
        Admin dadmin;
        stringstream ss(Aline);
        getline(ss, AID, ',');
        getline(ss, AFN, ',');
        getline(ss, ALN, ',');
        getline(ss, AUN, ',');
        getline(ss, APW, ',');
        dadmin.AdminID = AID;
        dadmin.First = AFN;
        dadmin.Last = ALN;
        dadmin.Username = AUN;
        dadmin.Password = APW;
        Admins.addFront(dadmin);
    }

    string MID, MFN, MLN, MUN, MPW, Mline;
    ifstream Mfile("Members.txt");
    while(getline(Mfile, Mline))
    {
        Member dmember;;
        stringstream ss(Mline);
        getline(ss, MID, ',');
        getline(ss, MFN, ',');
        getline(ss, MLN, ',');
        getline(ss, MUN, ',');
        getline(ss, MPW, ',');
        dmember.MemberID = MID;
        dmember.First = MFN;
        dmember.Last = MLN;
        dmember.Username = MUN;
        dmember.Password = MPW;
        Members.addFront(dmember);
    }

    string CID, CN, CD, CT, RN, MC, Cline, dummy, dummy1;
    
    ifstream Cfile("FitnessClasses.txt");
    while(getline(Cfile, Cline))
    {
        FitnessClass dclass;
        LinkedStack<string> LoM;
        stringstream ss(Cline);
        getline(ss, CID, ',');
        getline(ss, CN, ',');
        getline(ss, CD, ',');
        getline(ss, CT, ',');
        getline(ss, MC, ',');
        getline(ss, RN, ',');
        getline(ss, dummy, '\n');
        //inputting the data of the list of members into a linked stack
        for (int i = 0; i < dummy.size(); i++)
        {
            if (dummy[i] == '[')
            {
                dummy1 = "";
            }
            else if (dummy[i] == ',' || dummy[i] == ']')
            {
                dclass.ListofMembers = LoM;
                dclass.ListofMembers.push(dummy1);
                dummy1 = "";
            }
            else
            {
                dummy1 = dummy1 + dummy[i];
            }
        }
        dclass.ClassID = CID;
        dclass.ClassName = CN;
        dclass.ClassDate = CD;
        dclass.ClassTime = CT;
        dclass.MaximumCapacity = MC;
        dclass.RoomNumber = RN;
        Classes.addFront(dclass);
    }
    // SESSION is for logout function    
    for (int i = 0; i < SESSION; i++)
    {
        cout<<"Welcome to the fitness management system!"<<endl
            <<"Please enter the category of your account before logging in: [admin/member]"<<endl;
        string category;
        cin >> category;
        if (category == "admin")
        {
            int choices = 1;
            if (adminlogin(Admins) == true)
                {
                    for (int i = 0; i < choices; i++)
                    {
                        adminCommands();
                        string choice;
                        cin >> choice;
                        if (choice == "1")
                        {
                            choices++;
                            cout<<"Please enter new admin first name: "<< endl;
                            string nadminf;
                            cin >> nadminf;
                            cout<<"Please enter new admin last name: "<< endl;
                            string nadminl;
                            cin >> nadminl;
                            registerAdmin(nadminf, nadminl, Admins);
                        }
                        else if (choice == "2")
                        {
                            choices++;
                            cout<<"Please enter new member first name: "<< endl;
                            string nmemberf;
                            cin >> nmemberf;
                            cout<<"Please enter new member last name: "<< endl;
                            string nmemberl;
                            cin >> nmemberl;
                            registerMember(nmemberf, nmemberl, Members);
                        }
                        else if (choice == "3")
                        {
                            choices++;
                            viewMemberList(Members);
                        }
                        else if (choice == "4")
                        {
                            choices++;
                            cout<<"Please enter Class ID: "<<endl;
                            string CID;
                            cin >> CID;
                            cout<<"Please enter Class Name: "<<endl;
                            string CN;
                            cin >> CN;
                            cout<<"Please enter Class Date: "<<endl;
                            string CD;
                            cin >> CD;
                            cout<<"Please enter Class Time: "<<endl;
                            string CT;
                            cin >> CT;
                            cout<<"Please enter maximum capcity of class: "<<endl;
                            string MC;
                            cin >> MC;
                            // sets default maximum capacity
                            while (isdigit(stoi(MC)))
                            {
                                if (MC == "")
                                {
                                    MC = "10";
                                    cin >> MC;
                                    break;
                                }
                                cout<<"Please enter maximum capcity of class in integer form: "<<endl;
                                int MC;
                                cin >> MC;
                            }
                            cout<<"Please enter Class Room Number: "<<endl;
                            string CRN;
                            cin >> CRN;
                            addFitnessClass(CID, CN, CD, CT, MC, CRN, Classes);
                        }
                        else if (choice == "5")
                        {
                            choices++;
                            cout<<"Please enter Class ID: "<<endl;
                            string CID;
                            cin >> CID;
                            deleteFitnessClass(CID, Classes);
                        }
                        else if (choice == "6")
                        {
                            choices++;
                            cout<<"Please enter Class ID: "<<endl;
                            string CID;
                            cin >> CID;
                            cout<<"Please choose which section to update: "<<endl
                                <<"1) Class Date"<<endl
                                <<"2) Class Time"<<endl
                                <<"3) Class Room Number"<<endl;
                            int updatechoice;
                            cin >> updatechoice;
                            cout<<"Please enter updated value: "<<endl;
                            string updatevalue;
                            cin >> updatevalue;
                            updateClassDetails(CID, updatechoice, updatevalue, Classes);
                        }
                        else if (choice == "7")
                        {
                            choices++;
                            cout<<"Please enter Class ID: "<<endl;
                            string CID;
                            cin >> CID;
                            cout <<"Please enter the new capacity: "<<endl;
                            string temp;
                            cin >> temp;
                            // checks for valid input
                            while (stoi(temp) < 5 || stoi(temp) > 15 || !isdigit(stoi(temp)))
                            {
                                cout <<"Please enter a valid capacity between 5 and 15: "<<endl;
                                string temp;
                                cin >> temp;   
                            }
                            int newcap = stoi(temp); 
                            changeClassCapacity(CID, newcap, Classes);
                        }
                        else if (choice == "8")
                        {
                            choices++;
                            cout<<"Please enter existing Class ID: "<<endl;
                            string oldCID;
                            cin >> oldCID;
                            cout<<"Please enter the capacity for the first class: "<<endl;
                            int firstcap;
                            cin >> firstcap;
                            // sets default value 
                            while (firstcap > 15 || firstcap < 5 || !isdigit(firstcap) )
                            {
                                if (to_string(firstcap) == "")
                                {
                                    firstcap = 10;
                                    break;
                                }
                                cout<<"Please enter a valid capacity between 5 and 15 (or blank) for the first class: "<<endl;
                                int firstcap;
                                cin >> firstcap;
                            }
                            cout<<"Please enter the capacity for the second class: "<<endl;
                            int secondcap;
                            cin >> secondcap;
                            while (secondcap > 15 || secondcap < 5 || !isdigit(secondcap))
                            {
                                if (to_string(secondcap) == "")
                                {
                                    secondcap = 10;
                                    break;
                                }
                                cout<<"Please enter a valid capacity between 5 and 15 (or blank) for the second class: "<<endl;
                                int secondcap;
                                cin >> secondcap;
                            }
                            cout<<"Please enter new Class ID: "<<endl;
                            string newCID;
                            cin >> newCID;
                            cout<<"Please enter new Class Time (optional, enter 0 if unneeded): "<<endl;
                            string newCT;
                            cin >> newCT;
                            cout<<"Please enter new Class Date (optional, enter 0 if unneeded): "<<endl;
                            string newCD;
                            cin >> newCD;
                            splitClass(oldCID, newCID, firstcap, secondcap, newCT, newCD, Classes);
                            //split
                        }
                        else if (choice == "9")
                        {
                            choices++;
                            viewClassesWithVacancies(Classes);
                        }
                        else if (choice == "10")
                        {
                            logout();
                            break;
                        }
                        else if (choice == "11")
                        {
                            quitProgram(Admins, Members, Classes);
                            exit(1);
                        }
                        else
                        {
                            cout<<"Invalid choice."<<endl;
                        }
                    }
                    continue;
                }
        }
        else if (category == "member")
        {
            int choices = 1;
            if (memberlogin(Members) == true)
            {
                for (int i = 0; i < choices; i++)
                {
                    memberCommands();
                    int choice;
                    cin >> choice;
                    if (choice == 1)
                    {
                        choices++;
                        cout<<"Please provide the ID of the class you wish to book: "<<endl;
                        string CID;
                        cin >> CID;
                        bookAClass(CID, Classes, Members);
                    }
                    else if (choice == 2)
                    {
                        choices++;
                        viewClassesWithVacancies(Classes);
                    }
                    else if (choice == 3)
                    {
                        choices++;
                        viewBookingList(Classes);
                    }
                    else if (choice == 4)
                    {
                        choices++;
                        cout<<"Please enter the Class ID for the class you wish to cancel: "<<endl;
                        string CID;
                        cin >> CID;
                        cancelBooking(CID, Classes);
                    }
                    else if (choice == 5)
                    {
                        logout();
                        break;
                    }
                    else if (choice == 6)
                    {
                        quitProgram(Admins, Members, Classes);
                        exit(1);
                    }
                    else 
                    {
                        cout<<"Invalid choice."<<endl;
                    }
                    
                }
            }
        }
        else
        {
            cout<<"Invalid category"<<endl;
        }
    }
}