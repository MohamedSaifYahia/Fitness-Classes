#include "A2functions.h"

int SESSION = 1;
string currentadmin;
string currentmember;
DoublyLinkedList<Admin> Admins;
DoublyLinkedList<Member> Members;
DoublyLinkedList<FitnessClass> Classes;

void adminCommands()
{
    cout<<"The list of available operations for Admins:"<<endl
        <<"1) Register a new Admin"<<endl
        <<"2) Register a new member"<<endl
        <<"3) View the list of members "
        <<"4) Add a fitness class"<<endl
        <<"5) Delete a fitness class"<<endl
        <<"6) Update the details of a fitness class"<<endl
        <<"7) Update the capacity of a fitness class"<<endl
        <<"8) Split a fitness class into two classes"<<endl
        <<"9) View the classes with vacancies"<<endl
        <<"10)Logout"<<endl
        <<"11) Quit the program"<<endl
        <<"Enter the number of the required action: [1-11]"<<endl;

}

// list of member commands

void memberCommands()
{
    cout<<"The list of available operations for Members:"<<endl
        <<"1) Book a class"<<endl
        <<"2) View the classes with vacancies"<<endl
        <<"3) View booking list"<<endl
        <<"4) Cancel a booking"<<endl
        <<"5) Logout"
        <<"6) Quit the program"<<endl
        <<"Enter the number of the required action: [1-6]"<<endl;
}

//registering a member in the system

void registerMember(string first, string last, DoublyLinkedList<Member> &Members)
{
    Member newmember;
    newmember.MemberID = memberuniqueID(Members);
    newmember.First = first;
    newmember.Last = last;
    transform(last.begin(), last.end(), last.begin(), ::tolower);
    transform(first.begin(), first.end(), first.begin(), ::tolower); //transform changes a string into lowercase
    newmember.Username = first + newmember.MemberID;
    srand(0);
    newmember.Password = last + to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10);
    Members.addFront(newmember);
    cout<<"Success!"<<endl;
    cout<<"Your details are: "<<endl;
    cout<<"First name: " + newmember.First<<endl;
    cout<<"Last name: " + newmember.Last<<endl;
    cout<<"MemberID: " + newmember.MemberID<<endl;
    cout<<"Username: " + newmember.Username<<endl;
    cout<<"Password: " + newmember.Password<<endl;
}


//registering an admin in the system

void registerAdmin(string first, string last, DoublyLinkedList<Admin> &Admins)
{
    Admin newadmin;
    newadmin.AdminID = adminuniqueID(Admins);
    newadmin.First = first;
    newadmin.Last = last;
    transform(last.begin(), last.end(), last.begin(), ::tolower);
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    newadmin.Username = first + newadmin.AdminID;
    srand(2);
    newadmin.Password = last + to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10);
    Admins.addFront(newadmin);
    cout<<"Success!"<<endl;
    cout<<"Your details are: "<<endl;
    cout<<"First name: " + newadmin.First<<endl;
    cout<<"Last name: " + newadmin.Last<<endl;
    cout<<"AdminID: " + newadmin.AdminID<<endl;
    cout<<"Username: " + newadmin.Username<<endl;
    cout<<"Password: " + newadmin.Password<<endl;
}

// generating a unique ID for admins

string adminuniqueID (DoublyLinkedList<Admin> &Admins)
{
    string auid;
    srand(3);
    auid = to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10);
    DNode<Admin>* start = Admins.head->next;
    while (start != Admins.tail)
    {
        if (start->elem.AdminID == auid)
        {
            srand(4);
            auid = to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10);
        }
        start = start -> next;
    }
    return auid;
}

//generating a unique ID for the members

string memberuniqueID (DoublyLinkedList<Member> &Members)
{
    string muid;
    srand(3);
    muid = to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10);
    DNode<Member>* start = Members.head->next;
    while (start != Members.tail)
    {
        if (start->elem.MemberID == muid)
        {
            srand(4);
            muid = to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10);
        }
        start = start -> next;
    }
    return muid;
}

//adding a fitness class to the system

void addFitnessClass(string ClassID, string ClassName, string ClassDate, string ClassTime, string MaximumCapacity, string RoomNumber, DoublyLinkedList<FitnessClass> &Classes)
{
    FitnessClass newclass;
    newclass.ClassID = ClassID;
    newclass.ClassName = ClassName;
    newclass.ClassDate = ClassDate;
    newclass.ClassTime = ClassTime;
    newclass.MaximumCapacity = MaximumCapacity;
    newclass.RoomNumber = RoomNumber;
    LinkedStack<string> LoM;
    newclass.ListofMembers = LoM;
    Classes.addFront(newclass);
    cout<<"Success!"<<endl;
}

//deleting a fitness class from the system

void deleteFitnessClass(string ClassID, DoublyLinkedList<FitnessClass> &Classes)
{
    DNode<FitnessClass>* start = Classes.head->next;
    while (start != Classes.tail)
    {
        if (start->elem.ClassID == ClassID)
        {
            Classes.remove(start);
        }
        start = start -> next;
    }
}

// updating a class 

void updateClassDetails(string ClassID, int updatechoice, string updatedvalue, DoublyLinkedList<FitnessClass> &Classes)
{
    DNode<FitnessClass>* start = Classes.head->next;
    while (start != Classes.tail)
    {
        if (start->elem.ClassID == ClassID)
        {
            if (updatechoice == 1)
            {
                start->elem.ClassDate = updatedvalue;
                cout<<"Success!"<<endl;
            }
            else if (updatechoice == 2)
            {
                start->elem.ClassTime = updatedvalue;
                cout<<"Success!"<<endl;
            }
            else if (updatechoice == 3)
            {
                start->elem.RoomNumber = updatedvalue;
                cout<<"Success!"<<endl;
            }
            else
            {
                cout<<"Invalid choice."<<endl;
            }
            
        }
        else
        {
            cout<<"Incorrect Class ID"<<endl;
        }
        start = start -> next;
    }
}

// booking a class as a member

void bookAClass(string ClassID, DoublyLinkedList<FitnessClass> &Classes, DoublyLinkedList<Member> &Members)
{
    DNode<FitnessClass>* start = Classes.head->next;
    while (start != Classes.tail)
    {
        if (start->elem.ClassID == ClassID)
        {
            start->elem.ListofMembers.push(currentmember);
            return;
        }
        start = start->next;
    }
    cout<<"Invalid ID."<<endl;
}

// views all classes with vacancies

void viewClassesWithVacancies(DoublyLinkedList<FitnessClass> &Classes)
{
    DNode<FitnessClass>* start = Classes.head->next;
    while (start != Classes.tail)
    {
        if (stoi(start->elem.MaximumCapacity) > start->elem.ListofMembers.size())
        {
            cout<<start->elem.ClassID<<", "<<start->elem.ClassName<<", "<<start->elem.ClassDate<<", "<<start->elem.ClassTime<<", "<<start->elem.RoomNumber<<endl;
        }
        start = start->next;
    }
}

// cancel a booking as a member

void cancelBooking(string ClassID, DoublyLinkedList<FitnessClass> &Classes)
{
    DNode<FitnessClass>* start = Classes.head->next;
    while (start != Classes.tail)
    {
        if (start->elem.ClassID == ClassID)
        {
            //store popped stack members into a dynamic array
            int count = 0;
            string* listofmembers = new string[count];
            for (int i = 0; i < start->elem.ListofMembers.size(); i++)
            {
                if (start->elem.ListofMembers.top() == currentmember)
                {
                    start->elem.ListofMembers.pop();
                    for (int i = 0; i < count + 1; i++)
                    {
                        //restore popped stack members from dynamic array
                        start->elem.ListofMembers.push(listofmembers[i]);
                    }
                }
                else 
                {
                    string check = start->elem.ListofMembers.pop();
                    listofmembers[count] = check;
                    count++;
                }
            }
            delete[] listofmembers;
        }
        start = start -> next;
    }
}
// view member list as admin
void viewMemberList(DoublyLinkedList<Member> &Members)
{
    DNode<Member>* start = Members.head->next;
    while (start != Members.tail)
    {
        cout<<start->elem.MemberID<<", "<<start->elem.First<<", "<<start->elem.Last<<endl;
        start = start -> next;
    }
}
// view booking list as member
void viewBookingList(DoublyLinkedList<FitnessClass> &Classes)
{
    DNode<FitnessClass>* start = Classes.head->next;
    while (start != Classes.tail)
    {
        int count = 0;
        string* listofmembers = new string[count];
        for (int i = 0; i < start->elem.ListofMembers.size(); i++)
        {
            if (start->elem.ListofMembers.top() == currentmember)
            {
                cout<<start->elem.ClassName<<", "<<start->elem.ClassDate<<", "<<start->elem.ClassTime<<", "<<start->elem.RoomNumber<<endl;
                start->elem.ListofMembers.pop();
                for (int i = 0; i < count + 1; i++)
                {
                    start->elem.ListofMembers.push(listofmembers[i]);
                }
            }
            else 
            {
                string check = start->elem.ListofMembers.pop();
                listofmembers[count] = check;
                count++;
            }
        }
        delete[] listofmembers;
        start = start->next;
    }
}
// change the class capacity as an admin
void changeClassCapacity(string ClassID, int newcap, DoublyLinkedList<FitnessClass> &Classes)
{
    DNode<FitnessClass>* start = Classes.head->next;
    while (start != Classes.tail)
    {
        if (start->elem.ClassID == ClassID)
        {
            if (stoi(start->elem.MaximumCapacity) == start->elem.ListofMembers.size() && newcap < stoi(start->elem.MaximumCapacity))
            {
                int n = stoi(start->elem.MaximumCapacity) - newcap;
                for (int i = 0; i < n; i++)
                {
                    start->elem.ListofMembers.pop();
                }
                start->elem.MaximumCapacity = to_string(newcap);
            }
            else
            {
                start->elem.MaximumCapacity = to_string(newcap);
            }
        }
        start = start->next;
    }
}
// split the class into 2
void splitClass(string oldCID, string newCID, int firstcap, int secondcap, string newCT, string newCD, DoublyLinkedList<FitnessClass> &Classes)
{
    DNode<FitnessClass>* start = Classes.head->next;
    while (start != Classes.tail)
    {
        if (start->elem.ClassID == oldCID)
        {
            if (newCD == "0")
            {
                newCD = start->elem.ClassDate;
            }
            if (newCT == "0")
            {
                newCT = start->elem.ClassTime;
            }
            FitnessClass split;
            LinkedStack<string> LoM;
            start->elem.MaximumCapacity = to_string(firstcap);
            split.ClassName = start->elem.ClassName;
            split.ClassDate = newCD;
            split.ClassID = newCID;
            split.ListofMembers = LoM;
            split.RoomNumber = start->elem.RoomNumber;
            split.ClassTime = newCT;
            split.MaximumCapacity = to_string(secondcap);
            if (start->elem.ListofMembers.size() > 0 && firstcap < start->elem.ListofMembers.size())
            {
                int n = start->elem.ListofMembers.size() - firstcap;
                for (int i = 0; i < n; i++)
                {
                    string transfer;
                    transfer = start->elem.ListofMembers.pop();
                    split.ListofMembers.push(transfer);
                }
            }
        }
        else
        {
            cout<<"Class ID is not preexisting."<<endl;
            return;
        }
        start = start -> next;
    }
}
// quit program and save 3 files
void quitProgram(DoublyLinkedList<Admin> &Admins, DoublyLinkedList<Member> &Members, DoublyLinkedList<FitnessClass> &Classes)
{
    ofstream aoutdata;
    aoutdata.open("Admins.txt");
    DNode<Admin>* astart = Admins.head->next;
    while (astart != Admins.tail)
    {
        aoutdata << astart->elem.AdminID << ","<<astart->elem.First << ","<<astart->elem.Last << ","<<astart->elem.Username << ","<<astart->elem.Password <<endl;
        astart = astart->next;
    }
    aoutdata.close();

    ofstream moutdata;
    moutdata.open("Members.txt");
    DNode<Member>* mstart = Members.head->next;
    while(mstart != Members.tail)
    {
        moutdata << mstart->elem.MemberID << ","<<mstart->elem.First << ","<<mstart->elem.Last << ","<<mstart->elem.Username << ","<<mstart->elem.Password <<endl;
        mstart = mstart->next;
    }
    moutdata.close();

    ofstream coutdata;
    coutdata.open("FitnessClasses.txt");
    DNode<FitnessClass>* cstart = Classes.head->next;
    while(cstart != Classes.tail)
    {
        coutdata << cstart->elem.ClassID << ","<<cstart->elem.ClassDate << ","<<cstart->elem.ClassName << ","<<cstart->elem.ClassTime << ","<<cstart->elem.MaximumCapacity<<", "<<cstart->elem.RoomNumber<<endl;
        cstart = cstart->next;
    }
    coutdata.close();
}

void logout()
{
    SESSION++;
}
// check for valid admin login credentials
bool adminlogin(DoublyLinkedList<Admin> &Admins)
{
    cout<<"Please enter your username: "<<endl;
    string user;
    cin >> user;
    cout<<"Please enter your password: "<<endl;
    string pw;
    cin >> pw;

    DNode<Admin>* start = Admins.head->next;
    while (start != Admins.tail)
    {
        if (start->elem.Username == user && start->elem.Password == pw)
        {
            cout<<"You have logged in successfully."<<endl;
            currentadmin = start->elem.AdminID;
            return true;
        }
        if (start->next == Admins.tail)
        {
            break;
        }
        start = start -> next;
    }
    return false;
}

// checking for valid member login credentials

bool memberlogin(DoublyLinkedList<Member> &Members)
{
    cout<<"Please enter your username: "<<endl;
    string user;
    cin >> user;
    cout<<"Please enter your password: "<<endl;
    string pw;
    cin >> pw;

    DNode<Member>* start = Members.head->next;
    while (start != Members.tail)
    {
        if (start->elem.Username == user && start->elem.Password == pw)
        {
            cout<<"You have logged in successfully."<<endl;
            currentmember = start->elem.MemberID;
            return true;
        }
        if (start->next == Members.tail)
        {
            break;
        }
        start = start -> next;
    }
    return false;
}
  
template <typename Elem> SLinkedList<Elem>::~SLinkedList()
{
	//todo
    while (!empty())
    {
        removeFront();
    }
}
//====================================
// Check if the list is empty or not
template <typename Elem> bool SLinkedList<Elem>::empty() const 
{
	//todo
    return head == NULL;
}
//====================================
// add a node at the front of the list
template <typename Elem> void SLinkedList<Elem>::addFront(const Elem& e)
{
	//todo
    Node<Elem>* x = new Node<Elem>;
    x->elem = e;
    x->next = head;
    head = x;
}
//====================================
// remove the first node from the list
template <typename Elem> void SLinkedList<Elem>::removeFront()
{
	//todo
    Node<Elem>* y = head;
    head = y->next;
    delete y;
}

template <typename Elem> const Elem& SLinkedList<Elem>::front() const
{
    return head->elem;
}

template <typename Elem> LinkedStack<Elem>::LinkedStack(): S(), n(0) { }

template <typename Elem> int LinkedStack<Elem>::size() const 
{// returns the number of elements
    return n;
}
template <typename Elem> bool LinkedStack<Elem>::empty() const 
{ // returns true if stack is empty
    return n == 0;
}
template <typename Elem> const Elem& LinkedStack<Elem>::top() const
{ // return top of stack
    return S.front(); // “front()” is already implemented in the linked list S
}

template <typename Elem> void LinkedStack<Elem>::push(const Elem& e) // push “e” onto stack
{
    ++n;
    S.addFront(e);
}
template <typename Elem> string LinkedStack<Elem>::pop() // pop the stack
{
    string s;
    s = S.front();
    n--;
    S.removeFront();
    return s;
}

template <typename Elem> DoublyLinkedList<Elem>::DoublyLinkedList ()
{
    head = new DNode<Elem>;
    tail = new DNode<Elem>;
    head -> next = tail;
    tail -> prev = head;
}
//============================================================
template <typename Elem> DoublyLinkedList<Elem>::~DoublyLinkedList () // destructor to clean up all nodes
{
    while (!empty()) 
    {
        removeFront();
    }
    delete head;
    delete tail;
}
//============================================================
template <typename Elem> bool DoublyLinkedList<Elem>::empty() const // checks if list is empty
{
	if (head->next == tail && tail->prev == head)
    {
        return true;
	}
	else 
    {
        return false;
    }
}
//============================================================
template <typename Elem> const Elem& DoublyLinkedList<Elem>::front() const // get front element
{
    return head->next->elem;
}
//============================================================
template <typename Elem> const Elem& DoublyLinkedList<Elem>::back() const // get back element
{
	//todo
    return tail->prev->elem;
}
//============================================================
template <typename Elem> void DoublyLinkedList<Elem>::addBefore(DNode<Elem> *ptr, const Elem& elem)
{
    // add element before a node in list
	DNode<Elem>* x = new DNode<Elem>;
    x->next = ptr;
	x->elem = elem;
	x->prev = ptr->prev;
	ptr->prev->next = x;
	ptr->prev = x;
}
//============================================================
template <typename Elem> void DoublyLinkedList<Elem>::addFront(const Elem& elem) // add to front of list
{
	DNode<Elem> * x = new DNode<Elem>;
	x->prev = head;
    x->elem = elem;
	x->next = head->next;
	head->next->prev = x;
	head->next = x;
}
//============================================================
template <typename Elem> void DoublyLinkedList<Elem>::addBack(const Elem& elem) // add to Back of the list
{
	//todo
    DNode<Elem> * x = new DNode<Elem>;
    x->next = tail;
	x->elem = elem;
	x->prev = tail->prev;
	tail->prev->next = x;
	tail->prev = x;
}
//============================================================
template <typename Elem> void DoublyLinkedList<Elem>::removeFront() // remove front item from list
{
   DNode<Elem> * old = head->next;
   head->next = old->next;
   old->next->prev = head;
   delete old;
}
//============================================================
template <typename Elem> void DoublyLinkedList<Elem>::removeBack() // remove last item from list
{
    DNode<Elem> * old = tail->prev;
    tail->prev = old->prev;
    old->prev->next = tail;
    delete old;
}

template <typename Elem> void DoublyLinkedList<Elem>::remove(DNode<Elem> *out)
{
    //remove node out
    DNode<Elem>* u = out->prev;
    DNode<Elem>* w = out->next;
    u->next = w;
    w->prev = u;
    delete out;
}

template <typename Elem> void DoublyLinkedList<Elem>::add(DNode<Elem> *in, const Elem& e)
{
    // insert node in
    DNode<Elem>* u = new DNode<Elem>;
    u->elem = e;
    u->next= in;
    u->prev = in->prev;
    in->prev->next = u;
    in->prev = u;
}