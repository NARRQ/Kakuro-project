#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include "WindowNana.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>

void WindowNana::ShowWindow() {
	nana::form form;
	nana::label label(form, nana::rectangle(0, 0, 100, 20));
	label.caption("Kakuro Game");
	form.show();
	nana::exec();
}