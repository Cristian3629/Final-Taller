
#include <gtkmm/drawingarea.h>
#include <gtkmm/application.h>
#include <gtkmm/window.h>

#include <cmath>
#include <gtkmm/main.h>
#include <gtkmm/comboboxtext.h>
#include "Ventana.h"
#define ANCHO_LINEA 0.05

class Ovalo : public Gtk::DrawingArea {

 protected:
  bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    Gtk::Allocation alloc = get_allocation();

    int ancho = alloc.get_width();
    int largo = alloc.get_height();
    cr->translate(ancho/2,largo/2);
    cr->rotate(M_PI/4);
    cr->scale(ancho/2, largo/3);
    cr->arc(0,0,1,0,2*M_PI);

    cr->restore();
    cr->stroke();

//    cr->line_to(1,0);
//    cr->line_to(0,1);
//    cr->line_to(0,0);
//    cr->close_path();
//    cr->set_source_rgb(1,0,0);
//    cr->fill();
//    cr->restore();
//    cr->stroke();

//    int ancho = alloc.get_width();
//    int alto = alloc.get_height();
//    int x = ancho / 2;
//    int y = alto / 2;
//
//    int w = ancho/2;
//    int h = alto/3;
//    //cr->save();
//    cr->translate(x,y);
//    cr->scale(w, h);
//    cr->arc(0, 0, 1, 0, 2 * M_PI);
//    cr->set_source_rgba(0, 0, 1.0, 0);
//    cr->restore();  // back to opaque black
//    cr->stroke();
    return true;
  }
};

///Para que ande todo esto hay que tener configurado el gtkmm como en el tp

//ejemplo de ventana con boton usando clase
int mains(int argc, char * argv[]){
  Gtk::Main kit(argc, argv);
  Ventana ventana;
  Gtk::Main::run(ventana.get_window());
}

//main para dibujo
int zmain(int argc, char* argv[]) {
  Gtk::Main kit(argc,argv);
  Gtk::Window win;
  win.set_title("DrawingArea");
  Ovalo area;
  win.add(area);
  win.show_all();
  Gtk::Main::run(win);
  return 0;
}

//Ejemplo de combobox
int mainx(int argc, char * argv[]){
  Gtk::Main kit(argc, argv);
  Gtk::Window window;
  Gtk::ComboBoxText cb;
  for (int i = 0; i < 20; i++){
    cb.append("Linea " + std::to_string(i));
  }
  window.add(cb);
  window.show_all();
  Gtk::Main::run(window);
}