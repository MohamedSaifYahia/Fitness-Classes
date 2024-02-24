fitnessclassv2.0: FinalAssignment2.o A2functions.o
	g++ FinalAssignment2.o A2functions.o -o fitnessclassv2.0

FinalAssignment2.o: FinalAssignment2.cpp
	g++ -c FinalAssignment2.cpp

A2functions.o: A2functions.cpp
	g++ -c A2functions.cpp

clean:
	rm *.o fitnessclassv2.0