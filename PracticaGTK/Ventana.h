//
// Created by darius on 08/07/17.
//

#ifndef PRACTICA_GTK_VENTANA_H
#define PRACTICA_GTK_VENTANA_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/main.h>
class Ventana {
 private:
  Gtk::Window window;
  Gtk::Button button;

 public:
  Ventana(){
    button.set_label("Cerrar");
    button.signal_clicked().connect(sigc::mem_fun(*this,&Ventana::close_window));
    window.add(button);
    window.show_all();
  }

  Gtk::Window& get_window(){
    return window;
  }

  void close_window(){
    window.close();
  }
};

#endif //PRACTICA_GTK_VENTANA_H
