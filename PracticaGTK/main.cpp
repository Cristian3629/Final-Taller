#include <iostream>
#include <gtkmm/main.h>
#include <gtkmm/comboboxtext.h>
#include "Ventana.h"

void on_clicked_button(){
  Gtk::Main::quit();
}

//Ventana con boton pero sin clase
int maina(int argc, char * argv[]) {
  Gtk::Main kit(argc,argv);
  Gtk::Button myButton;
  myButton.set_label("Cerrar");
  myButton.signal_clicked().connect(sigc::ptr_fun(&on_clicked_button));
  Gtk::Window window;
  window.add(myButton);
  window.show_all();
  Gtk::Main::run(window);
  return 0;
}