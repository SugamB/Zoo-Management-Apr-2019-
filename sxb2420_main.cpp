#include "sxb2420_Mainwin.h"
#include <gtkmm.h>

int main(int argc, char** argv)
{

	auto app = Gtk::Application::create(argc, argv);
	
	Zoo z;
	View v{z};
	Controller controller(z,v);

	Mainwin win(controller);

	return app->run(win);

}
