#ifndef _A2FUNCTIONS_H
#define _A2FUNCTIONS_H
#include<string>
#include<fstream>
#include<exception>
#include<sstream>
#include<stdlib.h>
#include <iostream>

using namespace std;
// variable, class and function declarations
extern string currentadmin;
extern string currentmember;
extern int SESSION;


template <typename Elem>
class DNode
{
	public:
		Elem elem; //data element 
		DNode<Elem>* next; //Link (pointer) to the next Node
		DNode<Elem>* prev; //Link (pointer) to the previous Node
		DNode(): next(NULL), prev(NULL)
		{}
		DNode(Elem elem) : elem(elem), next(NULL), prev(NULL)
		{}
};
//==============================================================
template <typename Elem>
class DoublyLinkedList
{
	public:
		DNode<Elem>* head; 	// pointer to the head of List
		DNode<Elem>* tail; 	// pointer to the tail of List
	
		DoublyLinkedList ();
		~DoublyLinkedList (); 
		bool empty() const; 
		const Elem& front() const; 
		const Elem& back() const;  
		void addBefore(DNode<Elem> *ptr, const Elem& elem);	 
		void addFront(const Elem& elem); 
		void addBack(const Elem& elem); 
		void removeFront(); 
		void removeBack();  
        void add(DNode<Elem>* in, const Elem& e);
        void remove(DNode<Elem>* out);
};

template <typename Elem>
class Node 
{
public:
    Elem elem;
    Node<Elem>* next;
};

template <typename Elem> 
class SLinkedList //for linked stack
{
public:
    SLinkedList(): head(NULL) {};
    ~SLinkedList();
    bool empty() const;
    const Elem& front() const;
    void addFront(const Elem& e);
    void removeFront();
    Node<Elem>* head;
};

template <typename Elem>
class LinkedStack
{
public:
    LinkedStack(); // constructor
    int size() const;
    bool empty() const;
    const Elem& top() const;
    void push(const Elem& e);
    string pop();
    SLinkedList<Elem> S; // linked list
    int n;
};


class Admin
{
public:
    string AdminID;
    string First;
    string Last;
    string Username;
    string Password;
};

class Member
{
public:
    string MemberID;
    string First;
    string Last;
    string Username;
    string Password;
};

class FitnessClass
{
public:
    string ClassID;
    string ClassName;
    string ClassDate;
    string ClassTime;
    string MaximumCapacity;
    string RoomNumber;
    LinkedStack<string> ListofMembers;
};

void adminCommands();
bool adminlogin(DoublyLinkedList<Admin> &Admins);
bool memberlogin(DoublyLinkedList<Member> &Members);
void memberCommands();
void registerMember(string first, string last, DoublyLinkedList<Member> &Members);
string memberuniqueID (DoublyLinkedList<Member> &Members);
void registerAdmin(string first, string last, DoublyLinkedList<Admin> &Admins);
string adminuniqueID (DoublyLinkedList<Admin> &Admins);
void addFitnessClass(string ClassID, string ClassName, string ClassDate, string ClassTime, string MaximumCapacity, string RoomNumber, DoublyLinkedList<FitnessClass> &Classes);
void updateClassDetails(string ClassID, int updatechoice, string updatedvalue, DoublyLinkedList<FitnessClass> &Classes);
void deleteFitnessClass(string ClassID, DoublyLinkedList<FitnessClass> &Classes);
bool memberlogin(DoublyLinkedList<Member> &Members);
void logout();
void quitProgram(DoublyLinkedList<Admin> &Admins, DoublyLinkedList<Member> &Members, DoublyLinkedList<FitnessClass> &Classes);
void bookAClass(string ClassID, DoublyLinkedList<FitnessClass> &Classes, DoublyLinkedList<Member> &Members);
void viewClassesWithVacancies(DoublyLinkedList<FitnessClass> &Classes);
void cancelBooking(string ClassID, DoublyLinkedList<FitnessClass> &Classes);
void viewMemberList(DoublyLinkedList<Member> &Members);
void viewBookingList(DoublyLinkedList<FitnessClass> &Classes);
void changeClassCapacity(string ClassID, int newcap, DoublyLinkedList<FitnessClass> &Classes);
void splitClass(string oldCID, string newCID, int firstcap, int secondcap, string newCT, string newCD, DoublyLinkedList<FitnessClass> &Classes);
extern DoublyLinkedList<Admin> Admins;
extern DoublyLinkedList<Member> Members;
extern DoublyLinkedList<FitnessClass> Classes;
#endif