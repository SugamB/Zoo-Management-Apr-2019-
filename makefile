#makefile
CXXFLAGS= -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

executable: sxb2420_main.o sxb2420_Animal.o sxb2420_Zoo.o sxb2420_Aquatic.o sxb2420_Avian.o sxb2420_Terrestrial.o sxb2420_Amphibious.o sxb2420_View.o sxb2420_Controller.o sxb2420_Mainwin.o
	$(CXX) $(CXXFLAGS) sxb2420_main.o sxb2420_Animal.o sxb2420_Zoo.o sxb2420_Aquatic.o sxb2420_Avian.o sxb2420_Terrestrial.o sxb2420_Amphibious.o sxb2420_View.o sxb2420_Controller.o sxb2420_Mainwin.o $(GTKFLAGS)
	./a.out
sxb2420_main.o: sxb2420_main.cpp *.h
	$(CXX) $(CXXFLAGS) -c sxb2420_main.cpp $(GTKFLAGS)
sxb2420_View.o: sxb2420_View.cpp *.h
	$(CXX) $(CXXFLAGS) -c sxb2420_View.cpp $(GTKFLAGS)
sxb2420_Controller.o: sxb2420_Controller.cpp *.h
	$(CXX) $(CXXFLAGS) -c sxb2420_Controller.cpp $(GTKFLAGS)
sxb2420_Mainwin.o: sxb2420_Mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c sxb2420_Mainwin.cpp $(GTKFLAGS)
sxb2420_Animal.o: sxb2420_Animal.cpp *.h
	$(CXX) $(CXXFLAGS) -c sxb2420_Animal.cpp $(GTKFLAGS)
sxb2420_Zoo.o: sxb2420_Zoo.cpp *.h
	$(CXX) $(CXXFLAGS) -c sxb2420_Zoo.cpp $(GTKFLAGS)
sxb2420_Aquatic.o: sxb2420_Aquatic.cpp *.h 
	$(CXX) $(CXXFLAGS) -c sxb2420_Aquatic.cpp $(GTKFLAGS)
sxb2420_Avian.o: sxb2420_Avian.cpp *.h 
	$(CXX) $(CXXFLAGS) -c sxb2420_Avian.cpp $(GTKFLAGS)
sxb2420_Terrestrial.o: sxb2420_Terrestrial.cpp *.h 
	$(CXX) $(CXXFLAGS) -c sxb2420_Terrestrial.cpp $(GTKFLAGS)
sxb2420_Amphibious.o: sxb2420_Amphibious.cpp *.h 
	$(CXX) $(CXXFLAGS) -c sxb2420_Amphibious.cpp $(GTKFLAGS)
	
clean:
	rm -f *.o a.out